%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
IGUALDADE ==|!=
RELACIONAL >|<|>=|<=
LOGICO (\|\||&&)
NEGACAO ~

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
GLOBAL {LETRA}
ID {LETRA}({LETRA}|{NUM})*

STRING \"([^\"]*)\"

COMENTARIO "//"[^\n]*
COMENTARIOS "/*"([^/\*])*\w*"*/"

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{return TK_TIPO_INT;}

"float"     {return TK_TIPO_FLOAT;}

"char"      {return TK_TIPO_CHAR;}

"bool"      {return TK_TIPO_BOOL;}

"string"    {return TK_TIPO_STRING;}

"true"      {return TK_BOOL_TRUE;}

"false"     {return TK_BOOL_FALSE; }

"if"        {return TK_IF;}

"else"      {return TK_ELSE;}

"while"     {return TK_WHILE;}

"loop"      {return TK_LOOP;}

"for"       {return TK_FOR;}

"write"     {return TK_WRITE;}

"read"      {return TK_READ;}

"switch"    {return TK_SWITCH;}

"case"      {return TK_CASE;}

"default"   {return TK_DEFAULT;}

"break"     {return TK_BREAK;}

"continue"  {return TK_CONTINUE;}

"len"       {return TK_LEN;}

"global"       {return TK_GLOBAL;}

"return"       {return TK_RETURN;}


[(){}[\];,:]	{ return *yytext; }

[+\-*/=!]		{ return *yytext; }


{NUM}		{ yylval.traducao = yytext;return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }
{CHAR}      { yylval.traducao = yytext; return TK_CHAR;}
{REAL}      { yylval.traducao = yytext; return TK_REAL;}
{IGUALDADE} { yylval.operacao = yytext; return TK_IGUALDADE;}
{RELACIONAL} {yylval.operacao = yytext; return TK_RELACIONAL;}
{LOGICO}    {yylval.operacao = yytext; return TK_LOGICO;}
{NEGACAO}   {yylval.operacao = yytext; return TK_NEGACAO;}
{STRING}    {yylval.valor = yytext; return TK_STRING;}
{COMENTARIO}    {yylval.valor = yytext; return TK_COMENTARIO;}
{COMENTARIOS}    {yylval.valor = yytext; return TK_COMENTARIOS;}
.			{ *yytext; }

%%