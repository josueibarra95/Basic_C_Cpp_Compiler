D           [0-9]
L           [a-zA-Z_]
H           [a-fA-F0-9]
E           [Ee][+-]?{D}+
FS          (f|F|l|L)
IS          (u|U|l|L)*

%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "traductor.tab.h"
#include "symtable.h"

int yylineno;
void comentario(void);
void comentariolinea(void);
void count();

%}

%%
"/*"			{ comentario(); }
"//"			{ comentariolinea(); }
"#include ""<"((_|{L}*)"."{L}*)">"	{ /* vacio */ }
"const"         { return(CONST); }

"char"          { yylval.tipo = CHAR; return(CHAR); }
"double"        { yylval.tipo = DOUBLE; return(DOUBLE); }
"float"         { yylval.tipo = FLOAT; return(FLOAT); }
"int"           { yylval.tipo = INT; return(INT); }
"void"          { yylval.tipo = VOID; return(VOID); }

"continue"		{ return CONTINUE; }
"default"		{ return DEFAULT; }
"do"			{ return DO; }
"if"			{ return IF; }
"else"			{ return ELSE; }
"switch"		{ return SWITCH; }
"case"			{ return CASE; }
"for"			{ return FOR; }
"while"			{ return WHILE; }
"return"		{ return RETURN; }
"break"			{ return BREAK; }

{L}({L}|{D})*	{ yylval.nombre = strdup(yytext); return(IDENTIFIER); }
0[xX]{H}+{IS}?		{ yylval.nombre = strdup(yytext); return(CONSTANT); }
0{D}+{IS}?		{ yylval.nombre = strdup(yytext); return(CONSTANT); }
{D}+{IS}?		{ yylval.nombre = strdup(yytext); return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ yylval.nombre = strdup(yytext); return(CONSTANT); }

(-)?{D}+{E}{FS}?		{ yylval.nombre = strdup(yytext); return(CONSTANT); }
(-)?{D}*"."{D}+({E})?{FS}?	{ yylval.nombre = strdup(yytext); return(CONSTANT); }
(-)?{D}+"."{D}*({E})?{FS}?	{ yylval.nombre = strdup(yytext); return(CONSTANT); }

">>="			{ return(RIGHT_ASSIGN); }
"<<="			{ return(LEFT_ASSIGN); }
"+="			{ return(ADD_ASSIGN); }
"-="			{ return(SUB_ASSIGN); }
"*="			{ return(MUL_ASSIGN); }
"/="			{ return(DIV_ASSIGN); }
"%="			{ return(MOD_ASSIGN); }
"&="			{ return(AND_ASSIGN); }
"^="			{ return(XOR_ASSIGN); }
"|="			{ return(OR_ASSIGN); }
">>"			{ return(RIGHT_OP); }
"<<"			{ return(LEFT_OP); }
"++"			{ return(INC_OP); }
"--"			{ return(DEC_OP); }
"&&"			{ return(AND_OP); }
"||"			{ return(OR_OP); }
"<="			{ return(LE_OP); }
">="			{ return(GE_OP); }
"=="			{ return(EQ_OP); }
"!="			{ return(NE_OP); }
";"				{ return(';'); }
","				{ return(','); }
("{"|"<%")		{ return('{'); }
("}"|"%>")		{ return('}'); }
":"				{ return(':'); }
"="				{ return('='); }
"("				{ return('('); }
")"				{ return(')'); }
("["|"<:")		{ return('['); }
("]"|":>")		{ return(']'); }
"."				{ return('.'); }
"&"				{ return('&'); }
"!"				{ return('!'); }
"~"				{ return('~'); }
"-"				{ return('-'); }
"+"				{ return('+'); }
"*"				{ return('*'); }
"/"				{ return('/'); }
"%"				{ return('%'); }
"<"				{ return('<'); }
">"				{ return('>'); }
"^"				{ return('^'); }
"|"				{ return('|'); }
"?"				{ return('?'); }

[ \t\v\f]		{ count(); }
\n				{ ++yylineno; }
.				{ /* Se ignoran caracteres no reconocidos */ }

%%

yywrap()
{
	return(1);
}


int column = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;
}

/* Para comentarios de mas de una linea */
void comentario(void)
{
    int c1, c2; //se declaran las variables c1, c2
    c1 = 0; //input(); //se guarda en c1 un caracter
    c2 = input(); //se guarda en c2 el siguiente caracter
    while (c2 != EOF && !(c1 == '*' && c2 == '/')) 
    {
            if (c1 == '\n')
                ++yylineno; //contador de lineas + 1
            c1 = c2; //va avanzando el lookahead
            c2 = input(); //c2 toma valor de un nuevo caracter
    }
    if( c2 == EOF ){
        printf("Error. Comentario no cerrado.\n");
    }
}


/* Borrar los comentarios de linea */
void comentariolinea()
{
    int cursor; //lookahead

    cursor = input(); //se recibe un caracter

    while (cursor != '\n' && cursor != EOF){
        //en caso de no ser un salto de linea o EOF se toma otro caracter
        cursor = input();
    }

    //en caso de ser salto de linea, se aumenta en 1 el contador de lineas
    if(cursor == '\n'){
        ++yylineno;
    }
}
