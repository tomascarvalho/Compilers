#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "tables.h"

node *createNode(node_type n_type, char *a_type, char *a_value, int is_expression){

    node *new_node = malloc(sizeof(node));

    new_node->type = n_type;
    if (a_type != NULL)
    {
        new_node->str_type = (char*)malloc(strlen(a_type)*sizeof(char)+255);
        strcpy(new_node->str_type, a_type);
    }
    else
        new_node->str_type = NULL;

    if (a_value != NULL)
    {
        new_node->value = (char*)malloc(strlen(a_value)*sizeof(char)+255);
        strcpy(new_node->value, a_value);
    }
    else
        new_node-> value = NULL;
    
    new_node->anote_type = NULL;
    new_node ->table_type = NULL;
    new_node->is_expression = is_expression;
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

    if(old->father != NULL)
    {
        new->father = old->father;
        new->father->n_sons++;
    }

}

void assign_value(node* first, char *dec_type)
{

    node *aux;
    for(aux=first->brother; aux != NULL; aux=aux->brother)
    {
        strcpy(aux->son->str_type,dec_type);
    }

}

void print_tree(node *root,int level, int anoted, char* f_name, char* l_value)
{
    int i = 0;
    char* func_name = f_name;
    char* last_value = l_value;


    node *aux = NULL;
    node *other_aux = NULL;


    if(root==NULL)
        return;

    if (strcmp(root-> str_type, "FuncDefinition") == 0)
    {
        other_aux = root->son;
        while (other_aux != NULL)
        {
            if (other_aux->type == id_node)
            {
                func_name = (char*)calloc(1+strlen(other_aux->value), sizeof(char));
                strcpy(func_name, other_aux->value);
                
                break;
                
            }
            other_aux = other_aux-> brother;
        }
        if (func_name == NULL)
        {
            func_name = (char*)calloc(strlen("Global")+1, sizeof(char));
            strcpy(func_name, "Global");
        }
    }

    if(root->type == id_node)
    {
        for(i=0;i<level;i++)
        {
            printf("..");
        }
        if (!anoted)
            printf("%s(%s)\n",root->str_type, root->value);
        else
            if (root->is_expression)
            {
                
                getType(root, func_name, root->value);
                last_value = (char*) calloc(strlen(root->value)+1, sizeof(char));
                if (root->value != NULL)
                    strcpy(last_value, root->value);
                printf("%s(%s) - %s\n",root->str_type, root->value, root->anote_type);
            }
            else
                printf("%s(%s)\n",root->str_type, root->value);
            
    }


    else if(root->type!=unknown_node)
    {
        for(i=0;i<level;i++)
        {
            printf("..");
        }
        if(!anoted)
            printf("%s\n",root->str_type);
        else
            if (root->is_expression)
            {
                getType(root, func_name, root->value);
                printf("%s - %s\n",root->str_type, root->anote_type);
            }
            else
                printf("%s\n",root->str_type);

    }

    else if(root->type == unknown_node && root->father != NULL && root->father->type == stat_node)
    {
        for(i=0;i<level;i++)
        {
            printf("..");
        } 
        if (!anoted)
            printf("%s\n",root->str_type);
        else
            if (root->is_expression)
            {
                printf("%s - %s\n",root->str_type, root->table_type);
            }
            else
                printf("%s\n",root->str_type);
    }

    for(aux=root->son; aux != NULL; aux=aux->brother)
    {
        print_tree(aux,level+1, anoted, func_name, last_value);
    }
 
}

void addType(node* root, char* table_name, char* my_opp)
{
    char* type_son_one = NULL;
    int n_pointers_one = 0;
    int n_pointers_two = 0;
    char* type_son_two = NULL;
    char* aux_str = NULL;
    node* sons = NULL;
    int str_length;

    if (root == NULL || table_name == NULL)
        return;

    if (root->son != NULL)
    {
        sons = root->son;
        if(strcmp(sons->str_type,"IntLit") == 0)
        {
            sons->anote_type = (char*)malloc(sizeof(char)*strlen("int")+1);
            strcpy(sons->anote_type,"int");
        }
        else if(strcmp(sons->str_type,"ChrLit") == 0)
        {
            sons->anote_type = (char*)malloc(sizeof(char)*strlen("int")+1);
            strcpy(sons->anote_type,"int");
        }
        else if(strcmp(sons->str_type,"StrLit") == 0)
        {
            sons->anote_type = (char*)malloc(sizeof(char)*strlen("char[]")+strlen(sons->value)+1);
            strcpy(sons->anote_type,"char[");
            str_length = count_length_str(sons->value);
            str_length--;
            sprintf(aux_str,"%d",str_length);
            strcat(sons->anote_type,aux_str);
            strcat(sons->anote_type,"]");
        }
    

        else
            getType(sons, table_name, sons->value);
        if (sons->anote_type == NULL)
            return;

        type_son_one = (char*) calloc(strlen((sons-> anote_type))+1, sizeof(char));
        strcpy(type_son_one, sons->anote_type);
        n_pointers_one = get_nPointers(table_name,sons->value);
        char *p = strchr(type_son_one, '[');
            
        if (!p);
        else
        {
            *p = 0;
            type_son_one = (char*)realloc(type_son_one, 2+strlen(type_son_one) *sizeof(char));
            strcat(type_son_one, "*");
            n_pointers_one++;
        }
        
        
        //printf("N Pointers do %s e %d\n", type_son_one, get_nPointers(table_name,sons->value));

        if (sons->brother != NULL)
        {
            sons = sons->brother;

            if(strcmp(sons->str_type,"IntLit") == 0)
            {
                sons->anote_type = (char*)malloc(sizeof(char)*strlen("int")+1);
                strcpy(sons->anote_type,"int");
            }
            else if(strcmp(sons->str_type,"ChrLit") == 0)
            {
                sons->anote_type = (char*)malloc(sizeof(char)*strlen("int")+1);
                strcpy(sons->anote_type,"int");
            }
            else if(strcmp(sons->str_type,"StrLit") == 0)
            {
                sons->anote_type = (char*)malloc(sizeof(char)*strlen("char[]")+strlen(sons->value)+1);
                strcpy(sons->anote_type,"char[");
                aux_str = (char*) malloc(sizeof(char)*strlen(sons->value));
                sprintf(aux_str,"%lu",strlen(sons->value)-1);
                strcat(sons->anote_type,aux_str);
                strcat(sons->anote_type,"]");
            }

            else
                getType(sons, table_name, sons->value);

            
            type_son_two = (char*) calloc(strlen((sons-> anote_type))+1, sizeof(char));
            strcpy(type_son_two, sons->anote_type);
            n_pointers_two = get_nPointers(table_name,sons->value);
            char *p = strchr(type_son_two, '[');
                
            if (!p);
            else
            {
                *p = 0;
                type_son_two = (char*)realloc(type_son_two, 2+strlen(type_son_two) *sizeof(char));
                strcat(type_son_two, "*");
                n_pointers_two++;
            }

        }
        else
        {

        }
    }
    else
        return;

    /** I dont trust pointer counter **/
    char *count_pointers = NULL;
    count_pointers = calloc(strlen(type_son_one)+1, sizeof(char));
    strcpy(count_pointers, type_son_one);
    char *asterisc;
    n_pointers_one = 0;
    while ((asterisc = strchr(count_pointers, '*')))
    {
        n_pointers_one ++;
        *asterisc = '#';
    }
    if (type_son_two != NULL)
    {
        count_pointers = calloc(strlen(type_son_two)+1, sizeof(char));
        strcpy(count_pointers, type_son_two);
        n_pointers_two = 0;
        while ((asterisc = strchr(count_pointers, '*')))
        {
            n_pointers_two ++;
            *asterisc = '#';
        }
    }
    
    



    if (strcmp(my_opp, "Add") == 0)
    {
        //printf("\nEntrou em add para somar: %s com %s, npoiters1: %d, npointers2: %d\n", type_son_one, type_son_two, n_pointers_one, n_pointers_two);

        if (n_pointers_one > n_pointers_two)
        {
            root->anote_type = (char*) calloc(strlen(type_son_one)+1, sizeof(char));
            strcpy(root-> anote_type, type_son_one);
            //printf("Resultado: %s\n", root->anote_type);
            return;
        }

        else if (n_pointers_two > n_pointers_one)
        {
            root->anote_type = (char*) calloc(strlen(type_son_two)+1, sizeof(char));
            strcpy(root-> anote_type, type_son_two);
            //printf("Resultado: %s\n", root->anote_type);
            return;
        }

        else if ((strcmp(type_son_one, type_son_two) == 0))
        {
            root->anote_type = (char*) calloc(strlen("int")+1, sizeof(char));
            strcpy(root-> anote_type, "int");
            //printf("Resultado: %s\n", root->anote_type);
            return;
        }

        else if ((n_pointers_one > 0 ) && (n_pointers_one == n_pointers_two) && (strcmp(type_son_one, type_son_two) != 0))
        {
            root->anote_type = (char*) calloc(strlen("undef")+1, sizeof(char));
            strcpy(root-> anote_type, "undef");
            //printf("Resultado: %s\n", root->anote_type);
            return;
        }

        else if ((n_pointers_one == 0) && (n_pointers_two == 0) && strcmp(type_son_one, type_son_two) != 0)
        {
            root->anote_type = (char*) calloc(strlen("int")+1, sizeof(char));
            strcpy(root-> anote_type, "int");
            //printf("Resultado: %s\n", root->anote_type);
            return;
        }

        else if (strcmp(type_son_one, "char") == 0 && strcmp(type_son_one, "int") == 0 )
        {
            root->anote_type = (char*) calloc(strlen("int")+1, sizeof(char));
            strcpy(root-> anote_type, "int");
            //printf("Resultado: %s\n", root->anote_type);
            return;
        }
        else if (strcmp(type_son_two, "char") == 0 && strcmp(type_son_two, "int") == 0 )
        {
            root->anote_type = (char*) calloc(strlen("int")+1, sizeof(char));
            strcpy(root-> anote_type, "int");
            //printf("Resultado: %s\n", root->anote_type);
            return;
        }
        else
        {
            root->anote_type = (char*) calloc(strlen("undef")+1, sizeof(char));
            strcpy(root-> anote_type, "undef");
            //printf("Resultado: %s\n", root->anote_type);
            return;
        }

    }

    else if (strcmp(my_opp, "Sub") == 0)
    {
        if (n_pointers_one > n_pointers_two)
        {
            root->anote_type = (char*) calloc(strlen(type_son_one)+1, sizeof(char));
            strcpy(root-> anote_type, type_son_one);
            return;
        }
        else if (strcmp(type_son_one, "int") == 0 && strcmp(type_son_two, "char") == 0)
        {
            root->anote_type = (char*) calloc(strlen("int")+1, sizeof(char));
            strcpy(root-> anote_type, "int");
            return;
        }
        else if (strcmp(type_son_one, "char") == 0 && strcmp(type_son_two, "int") == 0)
        {
            root->anote_type = (char*) calloc(strlen("int")+1, sizeof(char));
            strcpy(root-> anote_type, "int");
            return;
        }
        else if (strcmp(type_son_one, type_son_two) == 0)
        {
            root->anote_type = (char*) calloc(strlen("int")+1, sizeof(char));
            strcpy(root-> anote_type, "int");
            return;
        }
        else
        {
            root->anote_type = (char*) calloc(strlen("undef")+1, sizeof(char));
            strcpy(root-> anote_type, "undef");
            return;
        }

    }

    else if ((strcmp(my_opp, "Plus") == 0) || (strcmp(my_opp, "Minus") == 0))
    {

        root->anote_type = (char*) calloc(strlen("int") +1, sizeof(char));
        strcpy(root->anote_type, "int");
        return;

        /*if ((n_pointers_one == 0) && (n_pointers_two == 0))
        {
            root->anote_type = (char*) calloc(strlen("int")+1, sizeof(char));
            strcpy(root-> anote_type, "int");
            return;
        }
        else
        {
            root->anote_type = (char*) calloc(strlen("undef")+1, sizeof(char));
            strcpy(root-> anote_type, "undef");
            return;
        }
        */
    }
    else
    {

        if ((n_pointers_one == 0) && (n_pointers_two == 0))
        {
            root->anote_type = (char*) calloc(strlen("int")+1, sizeof(char));
            strcpy(root-> anote_type, "int");
            return;
        }
        else
        {
            root->anote_type = (char*) calloc(strlen("undef")+1, sizeof(char));
            strcpy(root-> anote_type, "undef");
            return;
        }

    }

    

}

char* trim_and_addPointer(char* string)
{
    if (string == NULL)
        return NULL;
    int size = (int)strlen(string),i, to_alloc_size = 1;
    char *str = (char*)malloc(sizeof(char)*to_alloc_size), *aux;
    strcpy(str,"");
    for(i=0;i<size;i++)
    {
        if(string[i]=='[')
        {
            str = (char*)realloc(string, sizeof(char*)*strlen(string)+1);
            strcat(str, "*");
            return str;
        }
        else
        {
            to_alloc_size++;
            str = (char*)realloc(str,sizeof(char)*to_alloc_size);
            aux = (char*)malloc(sizeof(char)*2);
            sprintf(aux,"%c",string[i]);
            strcat(str,aux);
            free(aux);
        }
    }
    return str;
}

int get_nPointers(char* func_name, char* symbol_name)
{
    if (func_name == NULL || symbol_name == NULL)
        return 0;
    table* aux;
    int i = 0;
    for (aux = first; aux != NULL; aux= aux->next)
    {
        if (strcmp(func_name, aux->name) == 0)
        {
            for (i = 0; i<aux->nSymbols; i++)
            {
                if (aux->symbols[i]->name != NULL)
                {
                    if (strcmp(symbol_name, aux->symbols[i]->name) == 0)
                        return aux->symbols[i]->n_pointers;
                }
                
            }
        }
    }
    aux = first;
    for (i = 0; i< first->nSymbols; i++)
    {
        if (strcmp(aux->symbols[i]->name, symbol_name) == 0)
            return aux->symbols[i]->n_pointers;
    }

    return 0;
}

void verify(node *to_verify, node *aux, char* table_name)
{
    if (to_verify == NULL)
        return;
    
    if (strcmp(to_verify->str_type, "Comma") == 0)
    {
        while(to_verify->brother != NULL)
            to_verify = to_verify->brother;
        verify(to_verify->son, aux, table_name);
    }
    else if (strcmp(to_verify->str_type, "Store") == 0)
    {
        if (to_verify->son != NULL)
        {
            to_verify = to_verify->son;
            verify(to_verify, aux, table_name);
        }
        
    }

    getType(aux, table_name, to_verify->value);

}


void getType(node *root, char* table_name, char* symbol_name)
{

    table* aux= NULL;
    node* and_this = NULL;
    node* node_aux = NULL;
    node_aux = root;
    int i = 0, flag_found = 0, str_length = 0;
    char* aux_str = NULL;
    char* last_value = NULL;
    char* other_aux_str = NULL;

    if(strcmp(root->str_type,"IntLit") == 0)
    {
        root->anote_type = (char*)malloc(sizeof(char)*strlen("int")+1);
        strcpy(root->anote_type,"int");
        return;
    }
    else if(strcmp(root->str_type,"ChrLit") == 0)
    {
        root->anote_type = (char*)malloc(sizeof(char)*strlen("int")+1);
        strcpy(root->anote_type,"int");
        return;
    }
    else if(strcmp(root->str_type,"StrLit") == 0)
    {
        root->anote_type = (char*)malloc(sizeof(char)*strlen("char[]")+strlen(root->value)+1);
        strcpy(root->anote_type,"char[");
        str_length = count_length_str(root->value);
        str_length--;
        aux_str = (char*)calloc(strlen("999999"), sizeof(char));
        sprintf(aux_str,"%d",str_length);
        strcat(root->anote_type,aux_str);
        strcat(root->anote_type,"]");
        return;



    }
    else if ((strcmp(root->str_type, "Eq") == 0 || strcmp(root->str_type, "Ge") == 0 || strcmp(root->str_type, "Gt") == 0 || strcmp(root->str_type, "Le") == 0 || strcmp(root->str_type, "Lt") == 0 || strcmp(root->str_type, "Ne") == 0 || strcmp(root->str_type, "And") == 0 ||strcmp(root->str_type, "Not") == 0 ||strcmp(root->str_type, "Or") == 0))
    {
      
        root->anote_type = (char*)calloc(strlen("int")+1, sizeof(char));
        strcpy(root->anote_type,"int");
        return;
    }

    else if (strcmp(root->str_type, "Call") == 0)
    {
        for (and_this = root-> son; and_this != NULL ; and_this = and_this->brother)
        {
            if (and_this->type == id_node)
            {
                if (and_this->value != NULL)
                {
                    last_value = (char*)calloc(strlen(and_this->value)+1, sizeof(char));
                    strcpy(last_value, and_this->value);
                    break;
                }
            }
        }

        for (aux = first; aux!= NULL; aux = aux->next)
        {
            if (strcmp(aux->name, table_name) == 0)
            {
                for (i = 0; i< aux->nSymbols; i++)
                {
                    if (aux->symbols[i]->name != NULL)
                    {
                        if (strcmp(aux->symbols[i]->name, last_value) == 0)
                        {
                            root->anote_type = (char*)calloc(strlen(aux->symbols[i]->type)+1, sizeof(char));
                            strcpy(root -> anote_type, aux->symbols[i]->type);
                            flag_found = 1;
                            break;
                        }
                    }
                }
            }
        }
        if (!flag_found)
        {
            //printf("veio aqui\n");
            aux = first;
            for (i = 0; i< first->nSymbols; i++)
            {
                //printf("Comparo: %s com : %s\n", aux->symbols[i]->name, symbol_name);
                if (strcmp(aux->symbols[i]->name, last_value)== 0)
                {
                    //printf("Encontrei\n");
                    root->anote_type = (char*)calloc(strlen(aux->symbols[i]->type)+1, sizeof(char));
                    strcpy(root->anote_type, aux->symbols[i]-> type);
                    break;
                }
            }
        }

        
        if (root->anote_type != NULL)
        {
            char *p = strchr(root->anote_type, '(');
            if (!p);
            else
                *p = 0;
        }
        return;
    }

    if (strcmp(root->str_type, "Store") == 0)
    {
        if (root->son != NULL)
        {
            and_this = root->son;

            if (and_this->anote_type == NULL)
            {
                getType(and_this, table_name, and_this->value);
                if (and_this ->anote_type != NULL)
                {
                    root->anote_type =(char*)calloc(strlen(and_this->anote_type)+1, sizeof(char));
                    strcpy(root->anote_type, and_this->anote_type);
                    
                }

            }
            
            
            root->anote_type =(char*)calloc(strlen(and_this->anote_type)+1, sizeof(char));
            strcpy(root->anote_type, and_this->anote_type);
            
        
        
            char *p = strchr(root->anote_type, '[');
            if (!p);
            else
            {
                *p = 0;
                root->anote_type = (char*)realloc(root->anote_type, 2+strlen(root->anote_type) *sizeof(char));
                strcat(root->anote_type, "*");
            }
            return;

        }
    }

    else if (strcmp(root->str_type, "Deref") == 0)
    {
        if (root->son != NULL)
        {
            if (strcmp(root->son->str_type, "Add") == 0 || (strcmp(root->son->str_type, "Sub") == 0) || (strcmp(root->son->str_type, "Mul") == 0) || (strcmp(root->son->str_type, "Div") == 0) || (strcmp(root->son->str_type, "Mod") == 0))
            {
                
                addType(root->son, table_name, root->son->str_type);
                if (root->son->anote_type != NULL)
                {
                    
                    char *find_pointer = strchr(root->son->anote_type, '*');
                    if (!find_pointer)
                    {
                        other_aux_str = (char*)calloc(strlen(root->son->anote_type), sizeof(char)+1);
                        strncpy(other_aux_str, root->son->anote_type, strlen(root->son->anote_type));
                    }
                    else
                    {
                        other_aux_str = (char*)calloc(strlen(root->son->anote_type), sizeof(char));
                        strncpy(other_aux_str, root->son->anote_type, strlen(root->son->anote_type)-1);
                    }

                    root->anote_type = (char*)calloc(strlen(other_aux_str)+1, sizeof(char));
                    strcpy(root->anote_type, other_aux_str);
                }
            }

            else
            {
                
                getType(root->son, table_name, root->son->value);
                if(root->son->anote_type != NULL)
                {
                    root->anote_type = (char*)calloc(strlen(root->son->anote_type)+3, sizeof(char));
                    strcpy(root->anote_type, root->son->anote_type);
                    char *p = strchr(root->anote_type, '[');
                    if (!p)
                    {
                        root->anote_type = (char*)calloc(strlen(root->son->anote_type), sizeof(char));
                        strncpy(root->anote_type, root->son->anote_type, strlen(root->son->anote_type)-1);

                    }
                    else
                    {
                        *p = 0;
                    }
                }
            }
            return;
        }
    }
    else if (strcmp(root->str_type, "Minus") == 0 || strcmp(root->str_type, "Plus") == 0 || strcmp(root->str_type, "Add") == 0 || (strcmp(root->str_type, "Sub") == 0) || (strcmp(root->str_type, "Mul") == 0) || (strcmp(root->str_type, "Div") == 0) || (strcmp(root->str_type, "Mod") == 0))
    {
        addType(root, table_name, root->str_type);
        return;
    }

    else if (strcmp(root->str_type, "Addr") == 0)
    {
        if (strcmp(root->son->str_type, "Add") == 0 || (strcmp(root->son->str_type, "Sub") == 0) || (strcmp(root->son->str_type, "Mul") == 0) || (strcmp(root->son->str_type, "Div") == 0) || (strcmp(root->son->str_type, "Mod") == 0))
        {
            
            addType(root->son, table_name, root->son->str_type);
            other_aux_str = (char*)calloc(strlen(root->son->anote_type)+2, sizeof(char));
            strcpy(other_aux_str, root->son->anote_type);
            strcat(other_aux_str, "*");


        }
        else
        {
            //printf("Eu sou %s e o filho vai ser: %s\n", root->str_type, root->son->str_type);
            getType(root->son, table_name, root->son->value);
            if(root->son->anote_type != NULL)
            {
                root->anote_type = (char*)calloc(strlen(root->son->anote_type)+1, sizeof(char));
                strcpy(root->anote_type, root->son->anote_type);
                char *p = strchr(root->anote_type, '[');
                if (!p)
                {
                    root->anote_type = (char*)calloc(strlen(root->son->anote_type)+2, sizeof(char));
                    strcpy(root->anote_type, root->son->anote_type);
                    strcat(root->anote_type, "*");

                }
                else
                {
                    *p = 0;
                    root->anote_type = (char*)realloc(root->anote_type, strlen(root->anote_type)*sizeof(char)+3);
                    strcat(root->anote_type, "**");
                }
            }
        }
        return;
        
    }
    else if (strcmp(root->str_type, "Comma") == 0)
    {
        if (root->son != NULL)
        {
            and_this = root->son;
            while(and_this->brother != NULL)
                and_this = and_this -> brother;
            
            
            if (and_this->value != NULL)
            {
                last_value = (char*)calloc(strlen(and_this->value)+1, sizeof(char));
                strcpy(last_value, and_this->value);
            }
            if (root->anote_type == NULL)
            {
                getType(and_this, table_name, and_this->value);
                if (and_this->anote_type != NULL)
                {
                    root->anote_type = (char*)calloc(strlen(and_this->anote_type)+1, sizeof(char));
                    strcpy(root->anote_type, and_this->anote_type);
                }

                
            }
            if (root->anote_type != NULL)
            {
                char *p = strchr(root->anote_type, '[');
                if (!p);
                else
                {
                    *p = '*';
                    *(p+1) = 0;
                }

            }

        }
    }
        
        

    if (table_name == NULL || symbol_name == NULL)
        return;
    //printf("passou\n");
    for (aux = first; aux!= NULL; aux = aux->next)
    {
        if (strcmp(aux->name, table_name) == 0)
        {
            for (i = 0; i< aux->nSymbols; i++)
            {
                if (aux->symbols[i]->name != NULL)
                {
                    if (strcmp(aux->symbols[i]->name, symbol_name) == 0)
                    {
                        node_aux->anote_type = (char*)calloc(strlen(aux->symbols[i]->type)+1, sizeof(char));
                        strcpy(node_aux -> anote_type, aux->symbols[i]->type);
                        return;
                    }
                }
            }
        }
    }
    if (!flag_found)
    {
        //printf("veio aqui\n");
        aux = first;
        for (i = 0; i< first->nSymbols; i++)
        {
            //printf("Comparo: %s com : %s\n", aux->symbols[i]->name, symbol_name);
            if (strcmp(aux->symbols[i]->name, symbol_name)== 0)
            {
                //printf("Encontrei\n");
                node_aux->anote_type = (char*)calloc(strlen(aux->symbols[i]->type)+1, sizeof(char));
                strcpy(node_aux->anote_type, aux->symbols[i]-> type);
                return;
            }
        }
    }
}

int count_length_str(char *str)
{

    int length = 0;
    int i;

    for(i=0; i<strlen(str);)
    {

        if(str[i]=='\\')
        {
            i++;
            if (i < strlen(str) && (str[i] == 'n' || str[i] ==  't' || str[i] ==  '\\' || str[i] ==  '\'' || str[i] ==  '\"' || str[i] ==  '0' || str[i] == '1' || str[i] ==  '2' || str[i] ==  '3' || str[i] == '4' || str[i] ==  '5' || str[i] ==  '6' || str[i] ==  '7') )
            {
                i++;
                if (i < strlen(str) && (str[i] ==  '0' || str[i] == '1' || str[i] ==  '2' || str[i] ==  '3' || str[i] == '4' || str[i] ==  '5' || str[i] ==  '6' || str[i] ==  '7'))
                {
                    i++;
                    if (i  < strlen(str) && (str[i] ==  '0' || str[i] == '1' || str[i] ==  '2' || str[i] ==  '3' || str[i] == '4' || str[i] ==  '5' || str[i] ==  '6' || str[i] ==  '7'))
                    {

                    }
                    else
                    {
                        length++;
                    }
                }
                else
                {
                    length++;
                }
            }
            else
            {
                length++;
            }
        }
        else
        {
            i++;
            length++;
        }
    }
    return length;
}


node *deleteComma(node *root){

    node *aux;

    if(strcmp(root->son->str_type,"Comma") != 0)
    {
        addBrother(root->son,root->brother);
        return root->son;
    }
    aux = deleteComma(root->son);

    if(root->brother != NULL)
    {
        addBrother(aux,root->brother);
        free(root);
        return aux;
    }
    else
    {
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

    for(aux=root->brother; aux!=NULL; aux=aux->brother)
    {
        aux->father=root->father;
    }
}

void freeTree(node* root)
{
    node* actual = NULL;
    node* proximo = NULL;


    if (root == NULL)
        return;

    for (actual = root, proximo = root->brother; proximo != NULL; actual = proximo, proximo = proximo->brother)
    {
        
        free(actual->anote_type);
        free(actual->table_type);
        free(actual->str_type);
        free(actual->value);
        if (actual->son != NULL)
        {
            freeTree(actual->son);
        }
        free(actual->father);
        free(actual->children);
        free(actual->son);
        
    }
    free(actual);
    free(proximo);
}

