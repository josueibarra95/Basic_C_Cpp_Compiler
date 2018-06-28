/*The multi-function calculator requieres a symbol table to keep track of the names and meanings
of variables and functions - This doesn't affect the grammar rules*/

/*The symbol table itselft consists of a linked list of records

/*Data type for links in the chain of symbols*/
struct symrec
{
	char *name;			/* name of symbol */
	int type;			/* type of symbol */
	double value;				/* value of a VAR */
	int function;
	struct symrec *next;		/* link field */
};

typedef struct symrec symrec;

/*The symbol table: a chain of 'struct symrec'*/
extern symrec *sym_table;

symrec *putsym ();
symrec *getsym ();
