%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

void yyerror(char *s);
int yylex();

extern char *yytext;
extern int linha, coluna, flag_l, lex;

int aux_ref = 0;
int flag_error = 0;
int print_t = 0;


node* root;
node* aux;

%}
%union
{
    char* var;
    struct node* no;
}


%token AMP AND ASSIGN AST CHAR COMMMA DIV ELSE EQ FOR GE GT IF INT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RETURN RPAR RSQ SEMI VOID

%token <var> RESERVED ID INTLIT CHRLIT STRLIT

%type <no> Start Repetition FunctionDefinition FunctionBody FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration TypeSpec Declarator Statement Expression DeclarationAux StatementAux StatementE StatementAux1 AstAux ParameterAux DeclaratorAux ExprStat ExpressionAux

%left COMMA
%right ASSIGN
%left OR
%left AND
%left EQ NE
%left GE GT LE LT
%left PLUS MINUS
%left AST DIV MOD
%right AMP NOT 
%right PRECEDENCE
%left LBRACE LPAR LSQ RPAR RSQ
%nonassoc ELSE

%%

Start: FunctionDefinition Repetition 							{$$ = createNode(rt_node,"Program",""); root = $$; addChild($$,$1); addBrother($1,$2);}
	| FunctionDeclaration Repetition							{$$ = createNode(rt_node,"Program",""); root = $$; addChild($$,$1); addBrother($1,$2);}
	| Declaration Repetition									{$$ = createNode(rt_node,"Program",""); root = $$; addChild($$,$1); addBrother($1,$2);}
;

Repetition: 													{$$ = NULL;}	
	| FunctionDefinition Repetition								{$$ = $1; addBrother($$,$2);}
	| FunctionDeclaration Repetition							{$$ = $1; addBrother($$,$2);}
	| Declaration Repetition									{$$ = $1; addBrother($$,$2);}
;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody 	{$$ = createNode(funcdec_node,"FuncDefinition",""); addChild($$, $1); addBrother($1,$2); addBrother($1,$3);}
;

FunctionBody: LBRACE DeclarationAux StatementAux RBRACE			{	$$ = createNode(funcdec_node,"FuncBody",""); 
																	if ($2 != NULL)
																	{
																		addChild($$,$2);
																		addBrother($2,$3);
																	}
																	else
																	{
																		addChild($$, $3);
																	}
																 }
			| LBRACE error RBRACE	 							{$$ = NULL; flag_error = 1;}
;

DeclarationAux: 												{$$ = NULL;}	 							
			| Declaration DeclarationAux 						{$$ = $1; addBrother($1,$2);}							 						
;

StatementAux: Statement StatementAux1							{$$ = $1; addBrother($1,$2);}
			| 													{$$ = NULL;}
;

StatementAux1: StatementE StatementAux1 						{$$ = $1; addBrother($1, $2);}
 			| 													{$$ = NULL;}
;


FunctionDeclaration: TypeSpec FunctionDeclarator SEMI			{$$ = createNode(funcdec_node,"FuncDeclaration",""); addChild($$, $1); addBrother($1,$2);}
;

FunctionDeclarator: AstAux ID LPAR ParameterList RPAR			{ 	aux = createNode(id_node,"Id",$2);
                                                                	if($1 != NULL ){
                                                                  		$$ = $1;
                                                                  		addBrother($1, aux);
                                                                	}
                                                                	else{
                                                             	 		$$ = aux;
                                                            		}
                                                                	addBrother($$,$4);
                                                              	}
;

AstAux: AST AstAux												{$$ = createNode(term_node,"Pointer",""); addBrother($$,$2);}
	| 	 														{$$ = NULL;}
;

ParameterList: ParameterDeclaration ParameterAux				{$$ = createNode(funcdec_node,"ParamList",""); addChild($$,$1); addBrother($1,$2);}
;

ParameterAux: 													{$$ = NULL;}
			| COMMA ParameterDeclaration ParameterAux 			{$$ = $2; addBrother($2, $3);}
;

ParameterDeclaration: TypeSpec AstAux ID						{$$ = createNode(funcdec_node,"ParamDeclaration",""); addChild($$,$1); addBrother($1,$2); addBrother($1,createNode(id_node,"Id",$3)); }
					| TypeSpec AstAux   						{$$ = createNode(funcdec_node,"ParamDeclaration",""); addChild($$,$1); addBrother($1,$2); }
;

Declaration: TypeSpec Declarator DeclaratorAux SEMI 			{
                                                                    if($2->aux_ref == 2) $$ = createNode(vardec_node,"ArrayDeclaration","");
                                                                    else if($2->aux_ref == 1) $$ = createNode(vardec_node,"Declaration","");
                                                                    addChild($$,$1); addBrother($1,$2); addBrother($$,$3);
                                                                    assign_value($$,$1->str_type);
                                                              	}
		| error SEMI 											{$$ = NULL; flag_error = 1; }
;

DeclaratorAux: 													{$$ = NULL;}
			| COMMA Declarator DeclaratorAux					{ 	if($2->aux_ref == 2) $$ = createNode(vardec_node,"ArrayDeclaration","");
                                                                	else if($2->aux_ref == 1) $$ = createNode(vardec_node,"Declaration","");
                                                                	addChild($$,createNode(term_node,"",""));
                                                                	addBrother($$->son,$2); addBrother($$,$3);
                                                              	}
;	

TypeSpec: CHAR 													{$$ = createNode(term_node,"Char","");}
		| INT 													{$$ = createNode(term_node,"Int","");}
		| VOID 													{$$ = createNode(term_node,"Void","");}
;

Declarator: AstAux ID LSQ INTLIT RSQ							{ 
																	aux = createNode(id_node,"Id",$2);
                                                                    if($1 != NULL)
                                                                    {
            	                                                		$$ = $1;
                                            		                    addBrother($1,aux);
                                                        			}
                                                                    else
                                                                    {
                                                                    	$$ = aux;
                                                                    }
                                                                    $$->aux_ref = 2;
                                                                    addBrother($$, createNode(id_node,"IntLit",$4));
                                                              	}
		| AstAux ID 											{ 	aux = createNode(id_node,"Id",$2);
                                                                	if($1 != NULL)
                                                                	{
                                                                        $$ = $1;
                                                                    	addBrother($1,aux);
                                            	                    }
                                                                    else{
                                                                    	$$ = aux;

                                                                    }
                                                                    $$->aux_ref = 1;
	                                                            }
;

Statement: ExprStat SEMI										{	
																	if ($1 == NULL)
																	{
																		$$ = createNode(unknown_node, "Null",""); 
																	}
																	else
																	{
																		$$ = $1;
																	}
																}
		| LBRACE StatementAux RBRACE							{ 	
																	if (nBrothers($2,0) >= 2)
																	{
																		$$ = createNode(stat_node, "StatList", "");
																		addChild($$, $2);
																	}
																	else
																	{
																		$$ = $2;
																	}
																	
																}
		| IF LPAR ExpressionAux RPAR StatementE 	 			{	$$ = createNode(stat_node,"If",""); addChild($$,$3); 
																	if (nBrothers($5,0) >= 2)
																	{
																		aux = createNode(stat_node, "StatList", "");
																		addChild(aux, $5);
																		assign_node($5);
																		addBrother($3, aux);
																	}
																	else
																	{
                                                                      	if($5 == NULL)
                                                                      	{

                                                                            addBrother($3,createNode(unknown_node,"Null",""));
                                                                            addBrother($3,createNode(unknown_node,"Null",""));
                                                                      	}
                                                                      	else if(nBrothers($5,1) == 1)
                                                                      	{
                                                                            addBrother($3,$5);
                                                                            addBrother($3,createNode(unknown_node,"Null",""));
                                                                      	}
                                                                      	else if(nBrothers($5,1) == 2)
                                                                      	{
                                                                            addBrother($3,$5);
                                                                    		assign_node($5);
                                                                      	}
                                                                	}
                                                              	}

		| IF LPAR ExpressionAux RPAR StatementE ELSE StatementE { 	$$ = createNode(stat_node,"If",""); addChild($$,$3);
                                                                	if(nBrothers($5,0)>=2)
                                                                	{
                                                                      	aux= createNode(stat_node,"StatList","");
                                                                      	addChild(aux,$5);
                                                                      	assign_node($5);
                                                                      	addBrother($3,aux);
                                                                    }
                                                                    else
                                                                    {
                                                                      	if($5 == NULL)
                                                                      	{
                                                                            addBrother($3,createNode(unknown_node,"Null",""));
                                                                      	}
                                                              			else if(nBrothers($5,1) == 1)
                                                              			{
                                                                            addBrother($3,$5);
                                                                      	}
                                                                      	else if(nBrothers($5,1) == 2)
                                                                      	{
                                                    						addBrother($3,$5);
                                                                      	}
                                                                    }
                                                                    if(nBrothers($7,0)>=2)
                                                                    {
                                                                      	aux = createNode(stat_node,"StatList","");
                                                                      	addChild(aux,$7);
                                                                      	assign_node($7);
                                                                        addBrother($3,aux);
                                                                    }
                                                                	else
                                                                	{
                                                                      	if($7 == NULL)
                                                                      	{
                                                                            addBrother($3,createNode(unknown_node,"Null",""));
                                                                      	}
                                                                      	if(nBrothers($7,0) == 1)
                                                                      	{
                                                                            addBrother($3,$7);
                                                                      	}
                                                                      	else if(nBrothers($3,1) == 2)
                                                                      	{
                                                                        	addBrother($3,createNode(unknown_node,"Null",""));
                                                                      	}
                                                                    }
                                                              	}
		| FOR LPAR ExprStat SEMI ExprStat SEMI ExprStat RPAR StatementE 	{ 	$$ = createNode(stat_node,"For","");
                                                                            	if($3 == NULL)
                                                                            	{
                                                                                    addChild($$,createNode(unknown_node,"Null",""));
                                                                                }
                                                                            	else
                                                                            	{
                                                                                    addChild($$,$3);
                                                                                }
                                                                            	if($5 == NULL)
                                                                            	{
																					addBrother($$->son,createNode(unknown_node,"Null",""));
																				}
                                                                                else
                                                                                {
                                                                                	addBrother($$->son,$5);
                                                                                } 
                                                                                if($7 == NULL)
                                                                                {
                                                                                	addBrother($$->son,createNode(unknown_node,"Null",""));
                                                                                } 
                                                                                else 
                                                                                {
                                                                                	addBrother($$->son,$7);
                                                                            	}
                                                                                if(nBrothers($9,0)>=2)
                                                                                {
                                                                                  	aux = createNode(stat_node,"StatList","");
                                                                                   	addChild(aux,$9);
                                                                                   	assign_node($9);
                                                                                    addBrother($$->son,aux);
                                                                                }
                                                                                else if ($9 == NULL)
                                                                                {
                                                                                	addBrother($$->son, createNode(unknown_node, "Null",""));
                                                                                }
                                                                                else
                                                                                {
                                                                                  	addBrother($$->son,$9);
                                                                                } 
                                                                            }
		| RETURN ExprStat SEMI 									{ $$ = createNode(stat_node,"Return",""); if($2 == NULL) addChild($$,createNode(unknown_node,"Null","")); else addChild($$,$2); }
;	


StatementE: ExprStat SEMI										{	
																	if ($1 == NULL)
																	{
																		$$ = createNode(unknown_node, "Null",""); 
																	}
																	else
																	{
																		$$ = $1;
																	}
																}
		| LBRACE StatementAux1 RBRACE							{ 	if (nBrothers($2,0) >= 2)
																	{
																		$$ = createNode(stat_node, "StatList", "");
																		addChild($$, $2);
																	}
																	else
																	{
																		$$ = $2;
																	}
																	
																}
		| IF LPAR ExpressionAux RPAR StatementE 	 			{ 	$$ = createNode(stat_node,"If",""); addChild($$,$3);
                                                                    if(nBrothers($5,0)>=2)
                                                                    {
                                                                      	aux = createNode(stat_node,"StatList","");
                                                                      	addChild(aux,$5);
                                                                      	assign_node($5);
                                                                      	addBrother($3,aux);
                                                                    }
                                                                    else
                                                                    {
                                                                      	if($5 == NULL)
                                                                      	{
                                                                    		addBrother($3,createNode(unknown_node,"Null",""));
                                                                    		addBrother($3,createNode(unknown_node,"Null",""));
                                                                  		}
                                                                      	else if(nBrothers($5,1) == 1)
                                                                      	{
                                                                            addChild($3,$5);
                                                                            addChild($3,createNode(unknown_node,"Null",""));
                                                                      	}
                                                                      	else if(nBrothers($5,1) == 2)
                                                                      	{
                                                                            addChild($3,$5);
                                                                            assign_node($5);
                                                                      	}
                                                                    }
                                                          		}
		| IF LPAR ExpressionAux RPAR StatementE ELSE StatementE {	$$ = createNode(stat_node,"If",""); addChild($$,$3);
                                                                	if(nBrothers($5,0)>=2)
                                                                	{
                                                                      	aux = createNode(stat_node,"StatList","");
                                                                      	addChild(aux,$5);
                                                                     	assign_node($5);
                                                                      	addBrother($3,aux);
                                                                    }
                                                                	else
                                                                	{
                                                                      	if($5 == NULL)
                                                                      	{
                                                                            addBrother($3,createNode(unknown_node,"Null",""));
                                                                        }
                                                                     	else if(nBrothers($5,1) == 1)
                                                                     	{
                                                                            addBrother($3,$5);
                                                                      	}
                                                                      	else if(nBrothers($5,1) == 2)
                                                                      	{
                                                                            addBrother($3,$5);
                                                                      	}
                                                                    }
                                                                    if(nBrothers($7,0)>=2)
                                                                    {
                                                                 	 	aux = createNode(stat_node,"StatList","");
                                                                  		addChild(aux,$7);
                                                                  		assign_node($7);
                                                                      	addBrother($3,aux);
                                                                	}
                                                                    else
                                                                    {
                                                                      	if($7 == NULL)
                                                                      	{
                                                                        	addBrother($3,createNode(unknown_node,"Null",""));
                                                                      	}
                                                              			if(nBrothers($7,0) == 1)
                                                              			{
                                                                            addBrother($3,$7);
                                                                      	}
                                                                      	else if(nBrothers($3,1) == 2)
                                                                      	{
                                                                        	addBrother($3,createNode(unknown_node,"Null",""));
                                                                      	}
                                                                    }
                                                              	}
		| FOR LPAR ExprStat SEMI ExprStat SEMI ExprStat RPAR StatementE 	{ 	$$ = createNode(stat_node,"For","");
                                                                            	if($3 == NULL)
                                                                            	{
                                                                                  	addChild($$,createNode(unknown_node,"Null",""));
                                                                                }
                                                                                else
                                                                                {
                                                                                  	addChild($$,$3);
                                                                                }
                                                                                if($5 == NULL)
                                                                            	{
                                                                            		addBrother($$->son,createNode(unknown_node,"Null",""));
                                                                             	}
                                                                                else
                                                                                {
                                                                                	addBrother($$->son,$5);	
                                                                                } 
                                                                            	if($7 == NULL)
                                                                        		{
                                                                        			addBrother($$->son,createNode(unknown_node,"Null",""));
                                                                        		}
                                                                                else 
                                                                            	{
                                                                            		addBrother($$->son,$7);
                                                                            	}
                                                                                if(nBrothers($9,0)>=2)
                                                                                {
                                                                                  	aux = createNode(stat_node,"StatList","");
                                                                                  	addChild(aux,$9);
                                                                                  	assign_node($9);
                                                                                  	addBrother($$->son,aux);
                                                                            	}
                                                                                else if($9 == NULL)
                                                                                {
                                                                                  	addBrother($$->son,createNode(unknown_node,"Null",""));
                                                                                }
                                                                                else
                                                                                {
                                                                                	addBrother($$->son,$9);
                                                                        		}
                                                                          	}
		| RETURN ExprStat SEMI 									{ 	$$ = createNode(stat_node,"Return",""); 
																	if($2 == NULL)
																	{
																		addChild($$,createNode(unknown_node,"Null",""));
																	}
																	else
																	{
																		addChild($$,$2); 
																	} 
																}
		| error SEMI											{$$ = NULL; flag_error = 1;} /*Aqui  $$ = NULL; flag_error = 1*/
		| LBRACE error RBRACE									{$$ = NULL; flag_error = 1;} /*aqui*/
;



ExprStat: 														{$$ = NULL;}
		| ExpressionAux 										{$$ = $1;}
;

ExpressionAux: ExpressionAux COMMA Expression 					{$$ = createNode(op_node,"Comma",""); $$->aux_ref = 3; addChild($$,$1); addBrother($1,$3);}
		| Expression 											{$$ =$1;}
;

Expression: Expression ASSIGN Expression   						{$$ = createNode(op_node,"Store",""); addChild($$,$1); addBrother($1,$3);}
		| Expression AND Expression 							{$$ = createNode(op_node,"And",""); addChild($$,$1); addBrother($1,$3); }
		| Expression OR Expression 								{$$ = createNode(op_node,"Or",""); addChild($$,$1); addBrother($1,$3);}
		| Expression EQ Expression 								{$$ = createNode(op_node,"Eq",""); addChild($$,$1); addBrother($1,$3);}
		| Expression NE Expression 								{$$ = createNode(op_node,"Ne",""); addChild($$,$1); addBrother($1,$3);}
		| Expression LT Expression 								{$$ = createNode(op_node,"Lt",""); addChild($$,$1); addBrother($1,$3);}
		| Expression GT Expression 								{$$ = createNode(op_node,"Gt",""); addChild($$,$1); addBrother($1,$3);}
		| Expression LE Expression 								{$$ = createNode(op_node,"Le",""); addChild($$,$1); addBrother($1,$3);}
		| Expression GE Expression 								{$$ = createNode(op_node,"Ge",""); addChild($$,$1); addBrother($1,$3);}
		| Expression PLUS Expression 							{$$ = createNode(op_node,"Add",""); addChild($$,$1); addBrother($1,$3);}
		| Expression MINUS Expression 							{$$ = createNode(op_node,"Sub",""); addChild($$,$1); addBrother($1,$3);}
		| Expression AST Expression 							{$$ = createNode(op_node,"Mul",""); addChild($$,$1); addBrother($1,$3);}
		| Expression DIV Expression 							{$$ = createNode(op_node,"Div",""); addChild($$,$1); addBrother($1,$3);}
		| Expression MOD Expression 							{$$ = createNode(op_node,"Mod",""); addChild($$,$1); addBrother($1,$3);}
		| AMP Expression %prec PRECEDENCE 						{$$ = createNode(op_node,"Addr", ""); addChild($$,$2);}
		| AST Expression %prec PRECEDENCE						{$$ = createNode(op_node, "Deref", ""); addChild($$, $2);}
		| PLUS Expression %prec PRECEDENCE						{$$ = createNode(op_node, "Plus", ""); addChild($$, $2);}
		| MINUS Expression %prec PRECEDENCE						{$$ = createNode(op_node, "Minus", ""); addChild($$, $2);}
		| NOT Expression %prec PRECEDENCE						{$$ = createNode(op_node, "Not", ""); addChild($$, $2);}
		| Expression LSQ ExpressionAux RSQ						{$$ = createNode(op_node,"Deref",""); addChild($$,createNode(op_node,"Add","")); addChild($$->son,$1); addBrother($1,$3);}
		| ID LPAR ExpressionAux RPAR							{ 	$$ = createNode(op_node,"Call",""); addChild($$,createNode(id_node,"Id",$1));
                                                                    if($3->aux_ref == 3)
                                                                    {
                                                                  		addBrother($$->son,deleteComma($3));
                                                                    }
                                                                    else
                                                                    {
                                                                      	addBrother($$->son,$3);
                                                                    }
                                                              	}
		| ID LPAR RPAR											{$$ = createNode(op_node,"Call",""); $$->aux_ref=3; addChild($$,createNode(id_node,"Id",$1));}
		| ID 													{$$ = createNode(id_node,"Id",$1);}
		| INTLIT 												{$$ = createNode(id_node,"IntLit",$1);}
		| CHRLIT 												{$$ = createNode(id_node,"ChrLit",$1);}
		| STRLIT 												{$$ = createNode(id_node,"StrLit",$1);}
		| LPAR ExpressionAux RPAR								{$$ = $2; $$->aux_ref = 0;}
		| LPAR error RPAR 										{$$ = createNode(unknown_node,"Null",""); flag_error = 1;}
		| ID LPAR error RPAR 									{$$ = createNode(unknown_node,"Null",""); flag_error = 1;}
;


%%
void yyerror(char *s){
  printf("Line %d, col %lu: %s: %s\n", linha, (unsigned long)(coluna-strlen(yytext)), s, yytext);
}

int main(int argc, char *argv[]){
	 if(argv[1]!=NULL){
        if(strcmp(argv[1],"-t")==0){
        	lex=0;
        	flag_l=0;
            print_t = 1;
        }
        else if(strcmp(argv[1],"-1")==0){

        	lex=1;
        	flag_l=0;
        	yylex();
        }
        else if(strcmp(argv[1],"-l")==0){

        	lex=1;
        	flag_l=1;
        	yylex();
        }
    }
  	if(!lex){
    	yyparse();
    	if(print_t && !flag_error)
      		print_tree(root,0);
  	}

    return 0;
}
 					
