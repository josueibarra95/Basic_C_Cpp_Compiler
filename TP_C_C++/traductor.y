// Definiciones
%{
#include <stdio.h>
#include <string.h>
#include "symtable.h"

// defino las funciones EXTERN, ya que usamos Bison, esto deveria de hacerse
// de forma automatica, pero param evitar problema al traducir, declaro

extern int yylex(void);													    // devuelve un valor entero que representa un tipo de token
extern FILE *yyin;														    // lugar de donde flex/lexx lee los caracteres
extern char *yytext; 														//reconoce tokens del input y es retornado al parser
extern int yylineno; 														//numero de linea del codigo fuente

FILE *yyoutput; 															//archivo que sera traducido
symrec *sym_table = (symrec * )0;
symrec *s;
symrec *symtable_set_type;

int tam_vector = 0;          												 // ignorar tamano del vector
int cant_corchetes = 0;       												 // cuando el vector es multidimensional imprimir una sola vez '=array()'
int imprimir_corchete = 0;   												 // cuando se reconoce ']' imprimir el ')' despues de cargar los valores al vector
int comprueba_funcion = 0;    												 // 1 cuando se define una funcion e imprimir 'function'
int sin_error = 1;               												 // si existe un error, se convierte en 0
int variable_global = 0;     												 // define si una variable es global

%}

%union {
int tipo;
double val;
char *nombre;
struct symrec *tptr;

}

%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP		// definicion de parentesis, corchete ... , aparte, contadores de incremento y decremen.
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN         	// definiciones de operaciones
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN   					// definiciones de asignaciones
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME                                   	// definiciones de operaciones especiales  
%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR CONTINUE BREAK RETURN  		// definiciones de funciones

%token <nombre> IDENTIFIER CONSTANT											// definiciones de constantes
%token <tipo> CHAR INT FLOAT DOUBLE CONST VOID   // definiciones de tipo de datos

%type <tipo> type_specifier declaration_specifiers type_qualifier			
%type <nombre> direct_declarator declarator init_declarator init_declarator_list function_definition  // tipos de declaraciones de funciones
%type <tptr> declaration    												// definiciones para estructuras


%left INC_OP DEC_OP  														// precedencia de tokens

// definimos la NO asociacion entre  if and else
%nonassoc IFX
%nonassoc ELSE

%start translation_unit														// definimos el simbolo no terminal inicial



//     														REGLAS

%%

primary_expression															
// a) En caso de ser un identificador, ya guarda el mismo identificador en el archivo
// b) En caso de ser constante, pregunta si se ignora el tamaño de archivo, si es asi se escribe en el archivo el yytext, en caso contrario, no se hace nada y se cera tam_vector. 
// c) En caso de ser funcion, imprime () 
			// a)
					: IDENTIFIER	{ if (comprueba_funcion){ fprintf(yyoutput, "%s", yytext); comprueba_funcion=0; } else if(variable_global){ fprintf(yyoutput, "%s", yytext); }else{ fprintf(yyoutput, "%s", yytext);} } 
			// b)
					| CONSTANT { if (!tam_vector) {fprintf(yyoutput, "%s", yytext); } else {fprintf(yyoutput, "%s", yytext); tam_vector=0;} }
			// c)
					| '(' { fprintf(yyoutput, "( "); } expression ')' { fprintf(yyoutput, " )"); }
					;
// Tokens que guarda ya en el archivo 
postfix_expression
					: primary_expression
					| postfix_expression '[' { fprintf(yyoutput, "[ "); } expression ']' { fprintf(yyoutput, " ]"); }
					| postfix_expression '(' { fprintf(yyoutput, "( "); } ')' { fprintf(yyoutput, " )"); } 
					| postfix_expression '(' { fprintf(yyoutput, "( "); } argument_expression_list ')' { fprintf(yyoutput, " )"); }
					| postfix_expression INC_OP { fprintf(yyoutput, "++"); }
					| postfix_expression DEC_OP { fprintf(yyoutput, "--"); }
					;

argument_expression_list
					: assignment_expression
					| argument_expression_list ',' { fprintf(yyoutput, ", "); } assignment_expression
					;
	
unary_expression
					: postfix_expression
			// operacion de incremento/decremento que guarda en el archivo yyoutput 
					| INC_OP { fprintf(yyoutput, "++"); } unary_expression
					| DEC_OP { fprintf(yyoutput, "--"); } unary_expression
					| unary_operator cast_expression
					;
// Sale los siguientes tokens y se guarda en archivo como esta 
unary_operator
					: '&' { fprintf(yyoutput, " & "); }
					| '*' { fprintf(yyoutput, " * "); }
					| '+' { fprintf(yyoutput, " + "); }
					| '-' { fprintf(yyoutput, " - "); }
					| '~' { fprintf(yyoutput, " ~ "); }
					| '!' { fprintf(yyoutput, " ! "); }
					;
cast_expression
					: unary_expression
					;

// Operadores de multiplicacion, division, mod 	
multiplicative_expression
					: cast_expression
					| multiplicative_expression '*' { fprintf(yyoutput, " * "); } cast_expression
					| multiplicative_expression '/' { fprintf(yyoutput, " / "); } cast_expression
					| multiplicative_expression '%' { fprintf(yyoutput, " %% "); } cast_expression
					;
// Operadores de suma, resta 
additive_expression
					: multiplicative_expression
					| additive_expression '+' { fprintf(yyoutput, " + "); } multiplicative_expression
					| additive_expression '-' { fprintf(yyoutput, " - "); } multiplicative_expression
					;

// Operadores de desplazamiento a la izquierda y a la derecha 	
shift_expression
					: additive_expression
					| shift_expression LEFT_OP { fprintf(yyoutput, " << "); } additive_expression
					| shift_expression RIGHT_OP { fprintf(yyoutput, " >> "); } additive_expression
					;

// Operadores relacionales menor, mayor, menor igual, mayor igual 
relational_expression
					: shift_expression
					| relational_expression '<' { fprintf(yyoutput, " < "); } shift_expression
					| relational_expression '>' { fprintf(yyoutput, " > "); } shift_expression
					| relational_expression LE_OP { fprintf(yyoutput, " <= "); } shift_expression
					| relational_expression GE_OP { fprintf(yyoutput, " >= "); } shift_expression
					;

// Operadores de igualdad, igual y distinto 
equality_expression
					: relational_expression
					| equality_expression EQ_OP { fprintf(yyoutput, " == "); } relational_expression
					| equality_expression NE_OP { fprintf(yyoutput, " != "); } relational_expression
					;	

// Operador AND 
and_expression
					: equality_expression
					| and_expression '&' { fprintf(yyoutput, " & "); } equality_expression
					;
					
// Operador OR exclusivo 
exclusive_or_expression
					: and_expression
					| exclusive_or_expression '^' { fprintf(yyoutput, " ^ "); } and_expression
					;

// Operador OR inclusivo 
inclusive_or_expression
					: exclusive_or_expression
					| inclusive_or_expression '|' { fprintf(yyoutput, " | "); } exclusive_or_expression
					;

// Operador AND logico 
logical_and_expression
					: inclusive_or_expression
					| logical_and_expression AND_OP { fprintf(yyoutput, " && "); } inclusive_or_expression
					;

// Operador OR logico 
logical_or_expression
					: logical_and_expression
					| logical_or_expression OR_OP { fprintf(yyoutput, " || "); } logical_and_expression
					;

// Expresion condicional 
conditional_expression
					: logical_or_expression
					| logical_or_expression '?' { fprintf(yyoutput, " ? "); } expression ':' { fprintf(yyoutput, " : "); } conditional_expression 
					;
	
assignment_expression
					: conditional_expression
					| unary_expression assignment_operator assignment_expression
					;
assignment_operator
					: '=' { fprintf(yyoutput, " = "); }
					| MUL_ASSIGN { fprintf(yyoutput, " *= "); }
					| DIV_ASSIGN { fprintf(yyoutput, " /= "); }
					| MOD_ASSIGN { fprintf(yyoutput, " %%= "); }
					| ADD_ASSIGN { fprintf(yyoutput, " += "); }
					| SUB_ASSIGN { fprintf(yyoutput, " -= "); }
					| LEFT_ASSIGN { fprintf(yyoutput, " <<= "); }
					| RIGHT_ASSIGN { fprintf(yyoutput, " >>= "); }
					| AND_ASSIGN { fprintf(yyoutput, " &= "); }
					| XOR_ASSIGN { fprintf(yyoutput, " ^= "); }
					| OR_ASSIGN { fprintf(yyoutput, " |= "); }
					;
expression
					: assignment_expression
					| expression ',' { fprintf(yyoutput, ", "); } assignment_expression
					;
					
constant_expression
					: conditional_expression
					;

declaration
					: declaration_specifiers init_declarator_list ';'
						{
							for(symtable_set_type=sym_table; symtable_set_type!=(symrec *)0; symtable_set_type=(symrec *)symtable_set_type->next){
								if(symtable_set_type->type==-1){
									symtable_set_type->type=$1;
								}
							}
							if (cant_corchetes==1 && imprimir_corchete==1)
							{
								fprintf(yyoutput, "];\n");
								cant_corchetes=0;
								imprimir_corchete=0;
							}else
								fprintf(yyoutput, ";\n");
											
						}
		//			| declaration_specifiers init_declarator_list error { yyerror("Falta \";\". "); yyerrok; }
					;

declaration_specifiers
					: type_specifier {if($1 == INT) fprintf(yyoutput, "int ");
										if($1 == CHAR) fprintf(yyoutput, "char ");
										if($1 == VOID) fprintf(yyoutput, "void ");
										if($1 == FLOAT) fprintf(yyoutput, "float ");
										if($1 == DOUBLE) fprintf(yyoutput, "double ");}
					| type_specifier declaration_specifiers 
					| type_qualifier type_qualifier  
					| type_qualifier declaration_specifiers
					;

init_declarator_list
					: init_declarator
					| init_declarator_list ',' { fprintf(yyoutput, ";\n"); } init_declarator
					;
init_declarator
					: declarator
					 	{
							s = getsym($1);
							if (s==(symrec *)0)
							{
								s = putsym($1, -1, 0);
							}
							else
							{
								printf("Variable ya declarada!\n");
								yyerrok;	
							}
						}
					| declarator	
						{
							s=getsym($1);
							if(s==(symrec *)0)
							{
								s=putsym($1, -1, 0);
							}
							else
							{
								printf("Variable ya declarada!\n");
								yyerrok;
							}
						}
					'=' { if (imprimir_corchete==0) fprintf(yyoutput, "="); } initializer 
					;
type_specifier
					: CHAR 
					| INT
					| FLOAT
					| DOUBLE
					| VOID
					;

declarator
					: direct_declarator {$$=$1;}
					;
direct_declarator
	// Si es la declaracion de una funcion, pone FUNCTION YYTEXT, sino $YYTEXT 
					: IDENTIFIER { if (comprueba_funcion){ fprintf(yyoutput, "%s", yytext); comprueba_funcion=0; } else fprintf(yyoutput, "%s", yytext); $$=$1; } 
					| direct_declarator '[' { tam_vector=1; if (!cant_corchetes) fprintf(yyoutput, "[ "); cant_corchetes=1; }
					 constant_expression ']' { fprintf(yyoutput, "] ");}
					| direct_declarator '['  { if (!cant_corchetes) fprintf(yyoutput, "[ "); cant_corchetes=1; }
					  ']' { fprintf(yyoutput, "] "); }
					| direct_declarator '(' { fprintf(yyoutput, "( "); } ')' { fprintf(yyoutput, " )"); }
					| direct_declarator '(' { fprintf(yyoutput, "( "); } parameter_type_list ')' { fprintf(yyoutput, " )"); }
					;

parameter_type_list
					: parameter_list
					;

parameter_list
					: parameter_declaration
					| parameter_list ',' { fprintf(yyoutput, ", "); } parameter_declaration
					;

parameter_declaration
					: declaration_specifiers declarator
						{
							s=getsym($2);
						    if(s==(symrec *) 0)
						    {
						        s=putsym($2, $1, 0);
						    }
						    else
						    {
						        printf("Variable ya declarada!\n");
						        yyerrok;
						    }
						}
					| declaration_specifiers
					;

initializer_list
					: initializer
					| initializer_list ',' { fprintf(yyoutput, " ,"); } initializer
					;

initializer
					:  assignment_expression /*primary_expression*/ 
					| '{' {fprintf(yyoutput, "{ ");} initializer_list '}' {fprintf(yyoutput, "} ");}
					;

type_qualifier
					: CONST { fprintf(yyoutput, "const "); }
					;

statement
					: labeled_statement
					| compound_statement
					| expression_statement
					| selection_statement
					| iteration_statement
					| jump_statement
					;
					
labeled_statement
					: CASE { fprintf(yyoutput, "case "); } constant_expression ':' { fprintf(yyoutput, ": "); } statement
					| DEFAULT { fprintf(yyoutput, "default "); } ':' { fprintf(yyoutput, ": "); } statement
					;
	
compound_statement
					: '{' { fprintf(yyoutput, "{ "); } '}' { fprintf(yyoutput, " }\n"); }
					| '{' { fprintf(yyoutput, "{\n"); } statement_list '}' { fprintf(yyoutput, "}\n"); }
/*| '{' { fprintf(yyoutput, "{\n"); } declaration_list '}' { fprintf(yyoutput, "}\n"); }*/
					| '{' { fprintf(yyoutput, "{\n"); } declaration_list statement_list '}' { fprintf(yyoutput, "}\n"); }
		//			| '{' error { yyerror("Falta \"}\"."); yyerrok; }
					;

declaration_list
					: declaration
					| declaration_list declaration
					; 

statement_list
					: statement
					| statement_list statement
					|
					;

expression_statement
					: ';' { fprintf(yyoutput, ";\n"); }
					| expression ';' { fprintf(yyoutput, ";\n"); }
					;
	
else_statement
					: ELSE  { fprintf(yyoutput, "else"); } statement
					| %prec IFX
					;	

selection_statement
					: IF { fprintf(yyoutput, "if"); } '(' { fprintf(yyoutput, "( "); } expression ')' { fprintf(yyoutput, " )"); } statement else_statement
					| SWITCH { fprintf(yyoutput, "switch"); } '(' { fprintf(yyoutput, "( "); } expression ')' { fprintf(yyoutput, " )"); } statement
					;
	
iteration_statement
					: WHILE { fprintf(yyoutput, "while"); } '(' { fprintf(yyoutput, "( "); } expression ')' { fprintf(yyoutput, " )"); } statement
					| DO { fprintf(yyoutput, "do"); } statement WHILE { fprintf(yyoutput, "while"); } '(' { fprintf(yyoutput, "( "); } expression ')' { fprintf(yyoutput, " )"); } ';' { fprintf(yyoutput, ";\n"); }
					| FOR { fprintf(yyoutput, "for"); } '(' { fprintf(yyoutput, "( "); } expression_statement expression_statement expression ')' { fprintf(yyoutput, " )"); } statement
					;
	
jump_statement
					: CONTINUE { fprintf(yyoutput, "continue"); } ';' { fprintf(yyoutput, ";\n"); }
					| BREAK { fprintf(yyoutput, "break"); } ';' { fprintf(yyoutput, ";\n"); }
					| RETURN { fprintf(yyoutput, "return"); } ';' { fprintf(yyoutput, ";\n"); }
					| RETURN { fprintf(yyoutput, "return "); } expression ';' { fprintf(yyoutput, ";\n"); }
	//				| CONTINUE error { yyerror("Falta \";\" despues de continue en la sentencia."); yyerrok; }
	//				| BREAK error { yyerror ("Falta \";\" despues de break en la sentencia."); yyerrok;}
	// 				| RETURN error { yyerror ("Falta \";\" despues de return en la sentencia."); yyerrok;}
	// 				| RETURN expression error { yyerror("Falta \";\" despues de return en la sentencia."); yyerrok;}
					;
external_declaration
					: function_definition { comprueba_funcion=1; }
					| declaration 
					;

function_definition
					: declaration_specifiers declarator compound_statement	
						{
							s=getsym($2);
							if(s==(symrec *)0)
							{
								s=putsym($2,$1,1);
							}
							else
							{
								printf("Funcion ya declarada!");
								yyerrok;
							}
						}
					| declarator declaration_list compound_statement
					| declarator compound_statement
					;

translation_unit
					: external_declaration
					| translation_unit external_declaration
					;
%%
//						FUNCIONES


#include <stdio.h>
#include <string.h>
#define X 300
#define Y 300
int indice =0;
char matriz[300][300],matriz_aux[300][300];
char funcion_name[20],funcion_name_aux[20];
char matriz_aux1[300][300];
int encontro_funcion=0,fil=0,col=0,columna=0;
void leer_archivo();
void clonacion();
char entrada[20];

yyerror(s)
char *s;
{
	sin_error=0;
	printf("%s: ERROR en la Linea %d cerca de:  %s\n", s, yylineno, yylval.nombre);
}

symrec * putsym(sym_name,sym_type, b_function)
	char *sym_name;
	int sym_type;
	int b_function;
{
	symrec *ptr;
	ptr = (symrec *) malloc(sizeof(symrec));
	ptr->name = (char *) malloc(strlen(sym_name) + 1);
	strcpy(ptr->name, sym_name);
	ptr->type = sym_type;
	ptr->value = 0; //set value to 0
	ptr->function = b_function;
	ptr->next =(struct symrec *) sym_table;
	sym_table = ptr;
	return ptr;
}
symrec * getsym(sym_name)
	char *sym_name;
{
	symrec *ptr;
	for(ptr = sym_table; ptr != (symrec*)0; ptr = (symrec *)ptr->next)
		if(strcmp(ptr->name, sym_name) == 0)
		{
			printf("simbolo: %s\n", ptr->name);
			return ptr;
		}
	return 0;
}

const char *tipo_id(int tipo){
	switch(tipo){
		case(282):
			return "CHAR";
		case(284):
			return "INT";
		case(288):
			return "FLOAT";
		case(289):
			return "DOUBLE";
		case(290):
			return "CONST";
		case(291):
			return "VOID";
		default:
			return "NO";
	}
}

const char *tipo_var(int tipo){
	switch(tipo){
		case(1):
			return "Funcion";
		case(0):
			return "Variable";
		default:
			return "NO";
	}
}

void leer_archivo()
{
    
    int i=0,j=0;
    char c;
	if ((yyoutput=fopen(entrada, "r")) == NULL)
	{
		printf("No se pudo abrir el archivo para escritura\n");
            return;
	}
    while(1)
    {
        c = fgetc(yyoutput);
        if(c=='\n')
        {
            i++;
            j=0;
        }else{

            j++;
        }
        matriz[i][j]=c;
        if( feof(yyoutput) )
        {
            break ;
        }
    }
    fclose(yyoutput);
    indice = i;
}

void clonacion(){

	int q,w,z;
	z=0;
	for(q=0;q<X;q++)
	{

			if(q == (indice-2))
				{
					strcat(matriz_aux1[z], "\n}");

				}
			else{
				strcat(matriz_aux1[z], matriz_aux[q]);
			}
		z++;

	}
}

//									MAIN - DEF
int main(int argc,char **argv)
{
	strcpy(entrada,argv[2]);
	/* Debe tener 3 parametros, ejecutable.exe /path/to/fuente.c /path/to/objeto.php */
	if (argc<3)
	{
		printf("Modo incorrecto de uso\n Forma correcta %s archivo.c archivo.php\n", argv[0]);
		return 0;
	}
	if ((yyin = fopen(argv[1],"rt")) == NULL) /*  */
	{
		printf("No se pudo abrir el archivo de lectura\n");
                return 0;
	}
	if ((yyoutput=fopen(argv[2], "w")) == NULL)
	{
		printf("No se pudo abrir el archivo para escritura\n");
                return 0;
	}

	fprintf(yyoutput, "\n");
	yyparse();
	fprintf(yyoutput, "\n");
	fclose(yyin);
	fclose(yyoutput);
	leer_archivo();
	clonacion();
	remove(entrada);
    yyoutput = fopen(entrada,"w+");
    fprintf(yyoutput, "#include <iostream>\nusing namespace std;\n");
    for(fil=0;fil<indice;fil++)
     {
        fprintf(yyoutput, "%s", matriz[fil]);
    }
    fclose(yyoutput);

	if(sin_error)
		printf("***********_ Traducción COMPLETA _***********\n");
	else
		printf("\nNo se pudo finalizar la traducción.\n");

	FILE *simbolos;
	strcat(argv[1], ".txt");
	simbolos=fopen(argv[1], "w+");
	symrec * ptr_table;
	fprintf(simbolos, "NOMBRE, TIPO, VARIABLE O FUNCION.\n");
	for(ptr_table = sym_table; ptr_table!=(symrec *)0; ptr_table=(symrec *)ptr_table->next)
	{
		fprintf(simbolos, "\t%s, %s, %s\n", ptr_table->name,
			tipo_id(ptr_table->type), 
			tipo_var(ptr_table->function));
	}

	fclose(simbolos);
	return 0;
}
