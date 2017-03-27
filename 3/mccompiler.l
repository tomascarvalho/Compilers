%option yylineno

%x COMMENT
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
  	#include "y.tab.h"
	int coluna = 1, linha = 1, colunaTemp = 1, linhaTemp = 1, flag_l=0, lex=0, flag_t=0;
%}

escape                				\\n|\\t|\\\\|\\\'|\\\"|\\([0-7]{1,3})
invalidEscape         				(\\([8-9][0-9]{0,2}))
num									[0-9]+
id									([a-z]|[A-Z]|\_)+[a-zA-Z0-9\_]*

strlit 								\"([^\n\"\\]|{escape})*\"
invalidString         				\"(\\.|[^\n\"\\])*\"
unterminatedStr       				\"([^\n\"]|{escape}(\"\\\"))*


charlit               				\'({escape}|[^\'\n\\])\'
invalidChar           				\'(\\.|[^\n\'\\])*\'
unterminatedChar      				\'([^\\\'\n]|{escape})*\\*[^\'\n]*
iniciocom							"/*"
fimcom								"*/"
illegalChar           				.

%%
"&&"								{coluna+=yyleng; if(flag_l) printf("AND\n"); else return AND;}
"&"									{coluna+=yyleng; if(flag_l) printf("AMP\n"); else return AMP;}
"=="								{coluna+=yyleng; if(flag_l) printf("EQ\n"); else return EQ;}
"="									{coluna+=yyleng; if(flag_l) printf("ASSIGN\n"); else return ASSIGN;}
"char"								{coluna+=yyleng; if(flag_l) printf("CHAR\n"); else return CHAR;}
"if"								{coluna+=yyleng; if(flag_l) printf("IF\n"); else return IF;}
"int"								{coluna+=yyleng; if(flag_l) printf("INT\n"); else return INT;}
"else"								{coluna+=yyleng; if(flag_l) printf("ELSE\n"); else return ELSE;}
"for"							  	{coluna+=yyleng; if(flag_l) printf("FOR\n"); else return FOR;}
"return"							{coluna+=yyleng; if(flag_l) printf("RETURN\n"); else return RETURN;}
"void"								{coluna+=yyleng; if(flag_l) printf("VOID\n"); else return VOID;}
">="								{coluna+=yyleng; if(flag_l) printf("GE\n"); else return GE;}
"<="							   	{coluna+=yyleng; if(flag_l) printf("LE\n"); else return LE;}
">"									{coluna+=yyleng; if(flag_l) printf("GT\n"); else return GT;}
"<"									{coluna+=yyleng; if(flag_l) printf("LT\n"); else return LT;}
"*"									{coluna+=yyleng; if(flag_l) printf("AST\n"); else return AST;}
","									{coluna+=yyleng; if(flag_l) printf("COMMA\n"); else return COMMA;}
"/"									{coluna+=yyleng; if(flag_l) printf("DIV\n"); else return DIV;}
"{"								 	{coluna+=yyleng; if(flag_l) printf("LBRACE\n"); else return LBRACE;}
"}"									{coluna+=yyleng; if(flag_l) printf("RBRACE\n"); else return RBRACE;}
"("									{coluna+=yyleng; if(flag_l) printf("LPAR\n"); else return LPAR;}
"["									{coluna+=yyleng; if(flag_l) printf("LSQ\n"); else return LSQ;}
")"									{coluna+=yyleng; if(flag_l) printf("RPAR\n"); else return RPAR;}
"]"									{coluna+=yyleng; if(flag_l) printf("RSQ\n"); else return RSQ;}
"-"									{coluna+=yyleng; if(flag_l) printf("MINUS\n"); else return MINUS;}
"%"									{coluna+=yyleng; if(flag_l) printf("MOD\n"); else return MOD;}
"!="								{coluna+=yyleng; if(flag_l) printf("NE\n"); else return NE;}
"!"									{coluna+=yyleng; if(flag_l) printf("NOT\n"); else return NOT;}
"||"								{coluna+=yyleng; if(flag_l) printf("OR\n"); else return OR;}
"+"									{coluna+=yyleng; if(flag_l) printf("PLUS\n"); else return PLUS;}
";"									{coluna+=yyleng; if(flag_l) printf("SEMI\n"); else return SEMI;}
" " 								{coluna+=1;}
\n								    {coluna = 1;linha++;}
\t					     		  	{coluna+=1;}

"++"|"--"|"auto"|"_Bool"|"break"|"case"|"_Complex"|"const"|"continue"|"default"|"do"|"double"|"enum"|"extern"|"float"|"goto"|"_Imaginary"|"inline"|"long"|"register"|"restrict"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"while"  {coluna += yyleng;  if(flag_l) printf("RESERVED(%s)\n",yytext); else{ yylval.var = yytext; return RESERVED;}}


{iniciocom}            				{BEGIN COMMENT; colunaTemp = coluna; linhaTemp = yylineno; coluna+=yyleng;}
<COMMENT>{fimcom}    	 			{coluna+=yyleng; BEGIN 0;}
<COMMENT>.          	 			{coluna+=yyleng;}
<COMMENT>\n         	 			{linha++; coluna=1;}
<COMMENT><<EOF>>    	 			{printf("Line %d, col %d: unterminated comment\n", linhaTemp, colunaTemp);yyterminate();}																			


{id}                    			{coluna += yyleng; if(flag_l) printf("ID(%s)\n",yytext); else{ yylval.var = (char*)calloc(255+yyleng,sizeof(char));strncpy(yylval.var,yytext,yyleng); return ID;}}
{num}								{coluna += yyleng; if(flag_l) printf("INTLIT(%s)\n",yytext); else{ yylval.var = (char*)calloc(255+yyleng,sizeof(char));strncpy(yylval.var, yytext, yyleng); return INTLIT;}}

{charlit}               			{coluna += yyleng; if(flag_l) printf("CHRLIT(%s)\n",yytext); else{ yylval.var= (char*)calloc(255+yyleng,sizeof(char));strncpy(yylval.var, yytext, yyleng); return CHRLIT;}}
{invalidChar}						{coluna += yyleng; if(lex) printf("Line %d, col %d: invalid char constant (%s)\n",linha, coluna, yytext);}
{unterminatedChar}      			{coluna += yyleng; if(lex) printf("Line %d, col %d: unterminated char constant\n",linha, coluna);}

{strlit}                			{coluna += yyleng; if(flag_l) printf("STRLIT(%s)\n",yytext); else{ yylval.var = (char*)calloc(255+yyleng,sizeof(char));strncpy(yylval.var, yytext, yyleng); return STRLIT;}}
{unterminatedStr}       			{coluna += yyleng; if(lex) printf("Line %d, col %d: unterminated string constant\n", linha, coluna);}
{invalidString}         			{coluna += yyleng; if(lex) printf("Line %d, col %d: invalid string constant (%s)\n", linha, coluna, yytext);}

{illegalChar}						{coluna += yyleng; if(lex) printf("Line %d, col %d: illegal character (%s)\n",linha, coluna, yytext);}
 
%%

int yywrap(){
	return 1;
}