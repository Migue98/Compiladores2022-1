%{
	#include <stdio.h>
%}
%option noyywrap

P_Reservada	"cadena"|"caracter"|"else"|"entero"|"for"|"if"|"real"|"return"|"void"|"while"

OPERADOR	"+"|"-"|"*"|"/"|"$"
OP_ASIGNA	"~"|"+~"|"-~"|"*~"|"/~"|"$~"
SIMBOLOS_E	"("|")"|"{"|"}"|"["|"]"|"&"|","|":"
OP_RELACION	"^^"|"^*"|"=="|"^^="|"^\"="|"<>"
ID 			[A-Za-z0-9]{0,5}_ 
C_NUM_E		" "?("+"|"-")?([0-9]){1,6}$
C_NUM_R		([0-9]*"."([0-9]?)*)|(([0-9]?)*"."[0-9]*)
C_CADENAS	\"[A-Za-z^0-9]{0,38}\"
C_CARACTER 	"'"[0-9A-Za-z]"'"
C_IGNORAR	" "|"\t"|"\n"

%%
{P_Reservada}		{ printf("reconocido P_Reservada %s\n", yytext); }
{OPERADOR}      	{ printf("reconocido OPERADOR %s\n", yytext); }
{OP_ASIGNA}   		{ printf("reconocido OP_ASIGNA %s\n", yytext); }
{SIMBOLOS_E}   		{ printf("reconocido SIMBOLOS_E %s\n", yytext); }
{OP_RELACION}   	{ printf("reconocido OP_RELACION %s\n", yytext); }
{ID}				{ printf("reconocido ID %s\n", yytext); }
{C_NUM_E}			{ printf("reconocido C_NUM_E %s\n", yytext); }
{C_NUM_R}		 	{ printf("reconocido C_NUM_R %s\n", yytext); }
{C_CADENAS}			{ printf("reconocido C_CADENAS %s\n", yytext); }
{C_CARACTER}		{ printf("reconocido C_CARACTER %s\n", yytext); }


%%
int main(argc,argv)
int argc;
char **argv;
{
	++argv,--argc; /* se saltael nombre del programa*/
	if ( argc> 0 ){
		printf("Leyedo el archivo %s...\n\n", argv[0]);
		yyin = fopen(argv[0],"r" );
	}else{
		printf("Leyendo la termial.\nEn espera de entrada...\n");
		yyin= stdin;
	}
	yylex();

	return 0;
}
