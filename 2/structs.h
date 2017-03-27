#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED


typedef enum {rt_node, vardec_node, funcdec_node, stat_node, op_node, term_node, id_node, unknown_node} node_type;
typedef struct node{
  node_type type;
  char *str_type;
  char *value;
  int n_sons;
  int aux_ref;
  struct node *father;
  struct node *son;
  struct node *brother;
}node;


node *createNode(node_type, char *a_type, char *a_value);
void addChild(node *father, node *new_born);
void addBrother(node *old, node *new);
void assign_value(node* first, char *dec_type);
void print_tree(node *root, int level);
void clearTree(node* current);
node *deleteComma(node *root);
int nBrothers(node *root, int unknown);
void assign_node(node *root);

#define OP (char*)calloc(1,sizeof(char))

#endif // STRUCTS_H_INCLUDED