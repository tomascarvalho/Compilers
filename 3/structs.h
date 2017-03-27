#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED


typedef enum {rt_node, vardec_node, funcdec_node, stat_node, op_node, term_node, id_node, unknown_node} node_type;
typedef struct node{
	node_type type;
	char *anote_type;
	char *table_type;
	char *str_type;
	char *value;
	int n_sons;
	int is_expression;
	int aux_ref; /* 0 - Normal 1 - Declaration 2 - ArrayDeclaration 3 - FunctionCall 4 - Null expression if*/
	struct node *father;
	struct node **children;
	struct node *son;
	struct node *brother;
}node;



void getType(node *root, char* table_name, char* symbol_name);
node *createNode(node_type, char *a_type, char *a_value, int is_expression);
void addChild(node *father, node *new_born);
void addBrother(node *old, node *new);
void assign_value(node* first, char *dec_type);
void print_tree(node *root, int level, int anoted, char* f_name, char* l_value);
void clearTree(node* current);
node *deleteComma(node *root);
int nBrothers(node *root, int unknown);
void assign_node(node *root);
void check_type(node *root);
void freeTree(node* root);
void verify(node *to_verify, node* aux, char* table_name);
void addType(node* root, char* table_name, char*);
int get_nPointers(char* func_name, char* symbol_name);
char* trim_and_addPointer(char* string);
int count_length_str(char *str);

#define OP (char*)calloc(1,sizeof(char))

node* root;

#endif // STRUCTS_H_INCLUDED