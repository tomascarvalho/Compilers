#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

node *createNode(node_type n_type, char *a_type, char *a_value){

    node *new_node = malloc(sizeof(node));

    new_node->type = n_type;
    new_node->str_type = (char*)malloc(255+strlen(a_type)*sizeof(char));
    strcpy(new_node->str_type, a_type);
    new_node->value = (char*)malloc(255+strlen(a_value)*sizeof(char));
    strcpy(new_node->value, a_value);
    new_node->n_sons = 0;
    new_node->aux_ref = 0;
    new_node->father = NULL;
    new_node->brother = NULL;
    new_node->son = NULL;

    return new_node;
}

void addChild(node *father, node *new_born){

    if(new_born == NULL)
        return;

    father->son = new_born;
    father->n_sons++;
    new_born->father = father;

}

void addBrother(node *old, node *new){

    if(old==NULL || new==NULL)
        return;

    node *aux;
  

    for(aux=old; aux != NULL && aux->brother != NULL; aux=aux->brother);

    aux->brother = new;

    if(old->father != NULL){
        new->father = old->father;
        new->father->n_sons++;
    }

}

void assign_value(node* first, char *dec_type){

    node *aux;
    for(aux=first->brother; aux != NULL; aux=aux->brother){
        strcpy(aux->son->str_type,dec_type);
    }

}

void print_tree(node *root,int level){

    int i;
    node *aux;

    if(root==NULL)
        return;

    if(root->type == id_node)
    {
        for(i=0;i<level;i++)
        {
            printf("..");
        }
        printf("%s(%s)\n",root->str_type, root->value);
    }
    else if(root->type!=unknown_node)
    {
        for(i=0;i<level;i++)
        {
            printf("..");
        }
        printf("%s\n",root->str_type);
    }
    else if(root->type == unknown_node && root->father != NULL && root->father->type == stat_node)
    {
        for(i=0;i<level;i++)
        {
            printf("..");
        } 
        printf("%s\n",root->str_type);
    }

    for(aux=root->son; aux != NULL; aux=aux->brother)
    {
        print_tree(aux,level+1);
    }
}


node *deleteComma(node *root){

  node *aux;

  if(strcmp(root->son->str_type,"Comma") != 0){
    addBrother(root->son,root->brother);
    return root->son;
  }
  aux = deleteComma(root->son);

  if(root->brother != NULL){
    addBrother(aux,root->brother);
    free(root);
    return aux;
  }
  else{
    free(root);
    return aux;
  }

  return NULL;
}

int nBrothers(node *root, int unknown){

    int n = 0;
    node *aux;
    for (aux = root; aux!= NULL; aux=aux->brother)
    {
        if (unknown)
        {
            n++;
        }
        else
        {
            if (aux->type!=unknown_node)
                n++;
        }
    }
    return n;
}




void assign_node(node *root){

  node *aux;

  for(aux=root->brother; aux!=NULL; aux=aux->brother){
    aux->father=root->father;
  }
}


