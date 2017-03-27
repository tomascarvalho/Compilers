#ifndef TABLES_H_INCLUDED
#define TABLES_H_INCLUDED

typedef enum {constantFlag, returnFlag, paramFlag, varParamFlag, noFlag} flag_type_t;
typedef struct symbol
{
    char* name;
    char* type;
    char* value;
    char *parameters;
    int n_pointers;
    int n_params;
    int is_param;
    int table_flag; /*0 - Hidden 1 - Show*/
} symbol;

typedef struct table
{
    char* name;
    char* type;
    struct table* next;
    int nSymbols;
    symbol** symbols; 
} table;

symbol* createSymbol(char* , char* , char* , int , int , char* , int);
table* createTable(char* , char*);
void createAllTables(node *root);
void insert_element(char *, char *, int ,char *, char *,int ,char* ,int);
table *search_table(char *,char *);
char *search_in_tables(char *, char *);
char *octal_to_decimal(char *);
void funcdeclaration(node *);
void funcdefinition(node *);
void declaration(node *, char *);
void funcbody(node *, char *);
void check_statement(node *, char *); 
table *table_exists(char*);
void to_print_in_order();

void addSymbolToTable(table*, symbol*);
table* createGlobalTable();
void clearTables(table*);

void printTables(table*);
void printSymbol(symbol*);
char* stringToLower(char*);

table* first;

void addError(char*, int, int);
int semanticCheck(node*, char*);

#endif // TABLES_H_INCLUDED