%option yylineno

%x COMMENT
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	int flag=0, coluna = 1, linha = 1, colunaTemp = 1, linhaTemp = 1;
%}

escape                \\n|\\t|\\\\|\\\'|\\\"|\\([0-7]{1,3})
invalidEscape         (\\([8-9][0-9]{0,2}))
num									  [0-9]+
id									  ([a-z]|[A-Z]|\_)+[a-zA-Z0-9\_]*

strlit 								\"([^\n\"\\]|{escape})*\"
invalidString         \"(\\.|[^\n\"\\])*\"
unterminatedStr       \"([^\n\"]|{escape})*|(\"\\\")

charlit               \'({escape}|[^\'\n\\])\'
invalidChar           \'(\\.|[^\n\'\\])*\'
unterminatedChar      \'([^\\\'\n]|{escape})*\\*[^\'\n]*
iniciocom							"/*"
fimcom								"*/"
illegalChar           .

%%
"&&"								  {if(flag==1) printf("AND\n");coluna+=yyleng;}
"&"									  {if(flag==1) printf("AMP\n");coluna+=yyleng;}
"=="								  {if(flag==1) printf("EQ\n");coluna+=yyleng;}
"="									  {if(flag==1) printf("ASSIGN\n");coluna+=yyleng;}
"char"							  {if(flag==1) printf("CHAR\n");coluna+=yyleng;}
"if"								  {if(flag==1) printf("IF\n");coluna+=yyleng;}
"int"								  {if(flag==1) printf("INT\n");coluna+=yyleng;}
"else"						  	{if(flag==1) printf("ELSE\n");coluna+=yyleng;}
"for"							  	{if(flag==1) printf("FOR\n");coluna+=yyleng;}
"return"							{if(flag==1) printf("RETURN\n");coluna+=yyleng;}
"void"								{if(flag==1) printf("VOID\n");coluna+=yyleng;}
">="							 	  {if(flag==1) printf("GE\n");coluna+=yyleng;}
"<="							   	{if(flag==1) printf("LE\n");coluna+=yyleng;}
">"									  {if(flag==1) printf("GT\n");coluna+=yyleng;}
"<"									  {if(flag==1) printf("LT\n");coluna+=yyleng;}
"*"									  {if(flag==1) printf("AST\n");coluna+=yyleng;}
","									  {if(flag==1) printf("COMMA\n");coluna+=yyleng;}
"/"									  {if(flag==1) printf("DIV\n");coluna+=yyleng;}
"{"									  {if(flag==1) printf("LBRACE\n");coluna+=yyleng;}
"}"									  {if(flag==1) printf("RBRACE\n");coluna+=yyleng;}
"("									  {if(flag==1) printf("LPAR\n");coluna+=yyleng;}
"["									  {if(flag==1) printf("LSQ\n");coluna+=yyleng;}
")"									  {if(flag==1) printf("RPAR\n");coluna+=yyleng;}
"]"									  {if(flag==1) printf("RSQ\n");coluna+=yyleng;}
"-"									  {if(flag==1) printf("MINUS\n");coluna+=yyleng;}
"%"									  {if(flag==1) printf("MOD\n");coluna+=yyleng;}
"!="								  {if(flag==1) printf("NE\n");coluna+=yyleng;}
"!"									  {if(flag==1) printf("NOT\n");coluna+=yyleng;}
"||"								  {if(flag==1) printf("OR\n");coluna+=yyleng;}
"+"									  {if(flag==1) printf("PLUS\n");coluna+=yyleng;}
";"									  {if(flag==1) printf("SEMI\n");coluna+=yyleng;}
" " 									{coluna+=1;}
\n								    {coluna = 1;linha++;}
\t					     		  {coluna+=1;}

"++"|"--"|"auto"|"_Bool"|"break"|"case"|"_Complex"|"const"|"continue"|"default"|"do"|"double"|"enum"|"extern"|"float"|"goto"|"_Imaginary"|"inline"|"long"|"register"|"restrict"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"while"  {if(flag==1) printf("RESERVED(%s)\n",yytext);coluna+=yyleng;}


{iniciocom}            {BEGIN COMMENT; colunaTemp = coluna; linhaTemp = yylineno; coluna+=yyleng;}
<COMMENT>{fimcom}    	 {coluna+=yyleng; BEGIN 0;}
<COMMENT>.          	 {coluna+=yyleng;}
<COMMENT>\n         	 {linha++; coluna=1;}
<COMMENT><<EOF>>    	 {printf("Line %d, col %d: unterminated comment\n", linhaTemp, colunaTemp);yyterminate();}																			



{id}                    {if(flag==1) printf("ID(%s)\n",yytext);coluna+=yyleng;}
{num}								    {if(flag==1) printf("INTLIT(%s)\n",yytext);coluna+=yyleng;}

{charlit}               {if(flag==1) printf("CHRLIT(%s)\n",yytext);coluna+=yyleng;}
{invalidChar}						{printf("Line %d, col %d: invalid char constant (%s)\n",linha, coluna, yytext);coluna+=yyleng;}
{unterminatedChar}      {printf("Line %d, col %d: unterminated char constant\n",linha, coluna);coluna+=yyleng;}

{strlit}                {if(flag==1) printf("STRLIT(%s)\n",yytext);coluna+=yyleng;}
{unterminatedStr}       {printf("Line %d, col %d: unterminated string constant\n",linha, coluna);coluna+=yyleng;}
{invalidString}         {printf("Line %d, col %d: invalid string constant (%s)\n", linha, coluna, yytext);coluna+=yyleng;}

{illegalChar}						{printf("Line %d, col %d: illegal character (%s)\n",linha, coluna, yytext);coluna+=yyleng;}


%%
int main(int argc, char **argv){
  if(argc>1){
    if(strcmp(argv[1],"-l")==0){
      flag = 1;
    }
  }
  yylex();
  return 0;
}

int yywrap(){
	return 1;
}