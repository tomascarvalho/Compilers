#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "structs.h"
#include "tables.h"

int semLine = INT_MAX;
int semColumn = INT_MAX;
char* semError = 0;


table* createGlobalTable(node* root)
{
    table* global = NULL;
    global = createTable("Global", NULL);
    addSymbolToTable(global, createSymbol("atoi", "int(char*)", NULL, 0, 0, NULL, 0));
    addSymbolToTable(global, createSymbol("itoa", "char*(int,char*)", NULL, 0, 0, NULL,0));
    addSymbolToTable(global, createSymbol("puts", "int(char*)", NULL, 0, 0, NULL,0));


    return global;

}

void createAllTables(node *root)
{
    if (root->str_type != NULL)
    {
        if(strcmp(root->str_type,"FuncDeclaration") == 0)
        {
            funcdeclaration(root);
        }
        else if(strcmp(root->str_type,"FuncDefinition") == 0)
        {
            funcdefinition(root);
        }
         else
        {
            declaration(root,"Global");
        } 

    }
    
   
    if(root->brother)
        createAllTables(root->brother);
}

void funcdeclaration(node *root)
{

    char *type = NULL;
    node *aux = root->son;
    node *other_aux = NULL;
    int n_pointers = 0;
    char *function_name = NULL;
    char *function_params = NULL;
    int n_params = 0;
    int i = 0;
    char *aux_string = NULL; 

    if (root== NULL)
        return;

    if (strlen(aux->str_type) <1)
        aux->str_type = NULL;
    if (aux->str_type != NULL)
    {
        type = (char*)malloc(sizeof(char)*strlen(aux->str_type)+1);
        strcpy(type,aux->str_type);
    }
    else
        type = NULL;


    for(aux = aux->brother; strcmp(aux->str_type,"Pointer") == 0; aux=aux->brother)
    {
        type = (char*)realloc(type,sizeof(char)*strlen(aux->str_type)+1);
        strcat(type,"*");
    }

    function_name = aux->value;
    aux = aux->brother;

    for(other_aux = aux->son; other_aux != NULL; other_aux = other_aux->brother)
    {
        n_params++;
    }

    aux->n_sons = n_params;
    function_params = (char*)calloc(n_params+1, sizeof(char));
    strcat(function_params, "(");

    for(aux=aux->son, i=0; i<n_params; aux=aux->brother,i++)
    {

        aux_string =  stringToLower(aux->son->str_type);

        if (strlen(function_params )> 1)
        {
            function_params = (char*)realloc(function_params, sizeof(char)*strlen(function_params)+2);
            strcat(function_params, ",");
        }


        function_params = (char*)realloc(function_params,(sizeof(char)*strlen(aux_string)) +(sizeof(char)*strlen(function_params)+1));
        strcat(function_params, aux_string);
        if (aux->son->brother != NULL)
        {
            for(other_aux=aux->son->brother; strcmp(other_aux->str_type,"Pointer") == 0 && other_aux->brother != NULL; other_aux = other_aux->brother)
            {
                function_params = (char*)realloc(function_params, sizeof(char)+strlen(function_params)+1);
                strcat(function_params,"*");
            }
            if ((strcmp(other_aux ->str_type,"Pointer")==0 )&& (other_aux->brother == NULL))
            {
                
                function_params = (char*)realloc(function_params, sizeof(char)+strlen(function_params)+1);
                strcat(function_params,"*");
            }
        }
        
    }
    function_params = (char*) realloc(function_params, sizeof(char)*strlen(function_params)+2);
    strcat(function_params, ")");
    type = (char*)realloc(type,sizeof(char)*(strlen(type)+strlen(function_params)+1));
    strcat(type,function_params);
    free(function_params);
    insert_element("Global",type, n_pointers, function_name, NULL, n_params, NULL, 0);

   

}


void funcdefinition(node *root)
{
    table* aux_table = NULL;
    table* other_aux_table = NULL;
    node *aux = root->son;
    node *other_aux = NULL, *param_aux = NULL;
    char *function_type = NULL;
    char *function_name = NULL;
    int num_params = 0;
    int n_pointers = 0;
    int i = 0;

    funcdeclaration(root);


    if (aux->str_type != NULL)
    {
        function_type = stringToLower(aux->str_type);
    }
    else
        function_type = NULL;

    for(aux = aux->brother; strcmp(aux->str_type,"Pointer")==0; aux=aux->brother)
    {
        function_type = (char*)realloc(function_type, sizeof(char)*strlen(function_type)+2);
        strcat(function_type, "*");
    }

    if (aux->value != NULL)
    {
        function_name = (char*)malloc(sizeof(char)*strlen(aux->value)+1);
        strcpy(function_name,aux->value); 
    }
    else
        function_name = NULL;
    

    
    aux_table = createTable(function_name, function_type);
    for(other_aux_table = first; other_aux_table->next != NULL; other_aux_table = other_aux_table->next);
    other_aux_table ->next = aux_table;

    aux = aux->brother;
    num_params = aux->n_sons;
    for(i = 0, other_aux = aux->son; i<num_params; i++, other_aux = other_aux->brother)
    {
        n_pointers = 0;
        param_aux = other_aux->son;

        function_type = stringToLower(param_aux->str_type);
        param_aux = param_aux->brother;

        if (param_aux != NULL)
        {

            for(; param_aux!=NULL && strcmp(param_aux->str_type,"Pointer") == 0; param_aux = param_aux->brother)
            {
                n_pointers++;
            }
            if(param_aux != NULL)
            {
                insert_element(function_name, function_type, n_pointers, param_aux->value, NULL, 0, NULL, 1);
            }
        }
        
        else
        {
            insert_element(function_name, function_type, n_pointers, NULL, NULL, 0, NULL, 1);
        }


    }

    aux = aux->brother;
    funcbody(aux, function_name);

}

void declaration(node *root, char *table_name)
{

    char *type = NULL;
    node *aux = root->son;
    int n_pointers = 0;


    if (aux->str_type != NULL)
    {
        type = (char*)malloc(sizeof(char)*strlen(aux->str_type)+1);
        strcpy(type,aux->str_type);
    }
    else
        type = NULL;
    

    for(aux = aux->brother; strcmp(aux->str_type,"Pointer") == 0; aux=aux->brother)
    {
        n_pointers++;
    }

    if(strcmp(root->str_type,"ArrayDeclaration") == 0)
    {

        insert_element(table_name,type,n_pointers,aux->value, aux->brother->value,0,NULL,0);
    }


    else/*declaration*/
      insert_element(table_name, type ,n_pointers ,aux->value, NULL, 0 ,NULL, 0);
}




void funcbody(node *root, char *table_name)
{

    node *aux = root->son;
    for(; aux!=NULL; aux=aux->brother)
    {
        if(aux->type != vardec_node)
            break;
        declaration(aux,table_name);
    }
    check_statement(aux, table_name);

}

void check_statement(node *root,char *t_name)
{

    node *aux = root;
    char *symbol_type = NULL;
    char *aux_str = NULL;

    if(root == NULL)
        return;

    if(aux->type == stat_node || aux->type == unknown_node)
    {
        check_statement(aux->son,t_name);
        check_statement(aux->brother,t_name);
    }

    if(aux->type == op_node)
    {
        check_statement(aux->son,t_name);
        //atualizar o type do aux
        check_statement(aux->brother,t_name);

    }

    if(aux->type == id_node)
    {

        symbol_type = search_in_tables(aux->value, t_name);

        if(symbol_type == NULL)
        {
            if(strcmp(aux->str_type,"IntLit") == 0)
            {
                symbol_type = (char*)malloc(sizeof(char)*strlen("int")+1);
                strcpy(symbol_type,"int");
            }
            if(strcmp(aux->str_type,"CharLit") == 0)
            {
                symbol_type = (char*)malloc(sizeof(char)*strlen("char")+1);
                strcpy(symbol_type,"char");
            }
            if(strcmp(aux->str_type,"StrLit") == 0)
            {
                symbol_type = (char*)malloc(sizeof(char)*strlen("char[]")+strlen(aux->value)+1);
                strcpy(symbol_type,"char[");
                aux_str = (char*) malloc(sizeof(char)*strlen(aux->value));
                sprintf(aux_str,"%lu",strlen(aux->value)-1);
                strcat(symbol_type,aux_str);
                strcat(symbol_type,"]");
            }
        }

        aux->table_type = symbol_type;
        check_statement(aux->brother,t_name);
    }
}



void insert_element(char *table_name,char *symbol_type,int n_pointers,char *symbol_name,char *symbol_value,int num_params,char* symbol_params,int p_is_param)
{
    int i = 0;
    table* aux_table = NULL;


    aux_table = table_exists(table_name);

    if (aux_table == NULL)
    {
    
        aux_table = createTable(table_name, stringToLower(symbol_type));

        
        table* result;
        for(result = first; result->next != NULL; result= result->next);
        result->next = aux_table;

    }
    
    else if (table_name != NULL && symbol_name != NULL)
    {
        aux_table = search_table(table_name, symbol_name);
 
    }


    if (aux_table != NULL)
    {

        for(i = 0; i < n_pointers; i++)
        {
            symbol_type = (char*)realloc(symbol_type, sizeof(char)*strlen(symbol_type)+2);
            strcat(symbol_type,"*");
        }

        if(symbol_value != NULL)
        {
            symbol_type = (char*)realloc(symbol_type, strlen(symbol_type)*sizeof(char) + strlen(symbol_value)*sizeof(char) +4);
            strcat(symbol_type,"[");
            symbol_value = octal_to_decimal(symbol_value);
            strcat(symbol_type, symbol_value);
            strcat(symbol_type,"]");
        }
        if(symbol_type == NULL || strlen(symbol_type) < 1)
            symbol_type = NULL;
        if(symbol_name == NULL || strlen(symbol_name) < 1)
            symbol_name = NULL;
        if(symbol_value == NULL || strlen(symbol_value) < 1)
            symbol_value = NULL;
        if(symbol_params == NULL || strlen(symbol_params) < 1)
            symbol_params = NULL;

        addSymbolToTable(aux_table, createSymbol(symbol_name, stringToLower(symbol_type), stringToLower(symbol_value), p_is_param, num_params, symbol_params, n_pointers));
        

    }

    

}

table* createTable(char* name, char* type)
{


    table* result = NULL;
  
    for(result = first; result != NULL; result= result->next);
    result = (table*)calloc(sizeof(table), sizeof(table));
    result->symbols = 0;
    result->nSymbols = 0;

    if (name != NULL)
    {
        result->name = (char*)malloc(sizeof(char)*(strlen(name))+1);
        strcpy(result->name, name);
    }
    else
        result->name = NULL;

    if (type != NULL)
    {
        addSymbolToTable(result, createSymbol("return", type, NULL, 0, 0, NULL, 0));

    }
    else
        result->type = NULL;
    result->next = NULL;


    return result;
}

symbol* createSymbol(char* name, char* type, char* value, int p_is_param, int num_params, char* symbol_params, int n_pointers)
{

    symbol* result = (symbol*)malloc(sizeof(symbol));


    if (strlen(type) <1)
        type = NULL;

    result->name = NULL;
    if (name != NULL)
    {
        result->name = (char*)calloc(strlen(name)+1, sizeof(char));
        strcpy(result->name, name);
    }
    
    result->type = NULL;
    if (type != NULL)
    {
        result->type = (char*)calloc(strlen(type)+1, sizeof(char));

        strcpy(result->type, type);
    }
    
    result->value = NULL;
    if (value != NULL)
    {
        result->value = (char*)malloc(strlen(value)*sizeof(char)+1);
        strcpy(result->value, value);
        
    }
    
    result->is_param = p_is_param;
    result->n_pointers = n_pointers; 


    if(num_params != 0 && symbol_params != NULL)
    {
        result ->n_params = num_params;
        result ->parameters = (char*)malloc(1+strlen(symbol_params)*sizeof(char));
        strcpy(result->parameters, symbol_params);
    }
    else
    {
        result->n_params = 0;
        result->parameters = NULL;
    }
    return result;
}

void addSymbolToTable(table* targetTable, symbol* targetSymbol)
{

    targetTable->nSymbols++;
    targetTable->symbols = (symbol**)realloc(targetTable->symbols, targetTable->nSymbols*sizeof(symbol*));
    targetTable->symbols[targetTable->nSymbols-1] = targetSymbol;
}

table *search_table(char *targetTable,char *targetSymbol)
{

    table *aux = NULL;
    table *aux_table = NULL;
    int i = 0;

    if (targetTable != NULL && targetSymbol != NULL)
    {

        for(aux_table=first; aux_table!=NULL; aux_table=aux_table->next)
        {
            if(strcmp(targetTable, "Global") == 0)
            {
                aux = first;
                for (i = 0; i< aux ->nSymbols; i++)
                {
                    if (strcmp((((aux->symbols[i]))-> name), targetSymbol) == 0) /* O simbolo existe na global */
                        return NULL;
                }
            }
            else if (strcmp(aux_table->name,targetTable) == 0)
            {
                for (i = 0; i< aux_table->nSymbols; i++)
                {
                    if (aux_table->symbols[i]->name != NULL)
                        if (strcmp(((aux_table->symbols[i])-> name), targetSymbol) == 0) /* O simbolo existe na tabela onde o queremos inserir */
                            return NULL;
                }
                return aux_table;
            }
        }

        return first;
    }
    return NULL;
}


table *table_exists(char* targetTable)
{
    table *aux_table = NULL;
    for(aux_table=first; aux_table!=NULL; aux_table=aux_table->next)
    {

        if (strcmp(aux_table->name,targetTable) == 0)
        {
            return aux_table;
        }
    }
    return NULL;
}

char *search_in_tables(char *var_name,char *t_name)
{

    symbol **aux_symbol = first->symbols;
    table *aux = NULL;

    char *return_str = NULL;
    int i = 0;

    /*global*/
    for(i = 0; i< first->nSymbols; i++)
    {
        if(strcmp(var_name,aux_symbol[i]->name)==0)
        {

            if(aux_symbol[i] -> parameters != NULL)
            {

                return_str = (char*)calloc((strlen(aux_symbol[i]->type))+2, sizeof(char));
                strcpy(return_str,aux_symbol[i]->type);
                strcat(return_str,"(");

                return_str = (char*) realloc(return_str,sizeof(char)*sizeof(return_str)+sizeof(char)*(strlen(aux_symbol[i]->parameters))+2);
                strcat(return_str, (aux_symbol[i]->parameters));
                strcat(return_str,")");
                return return_str;
            }     

            else
                return aux_symbol[i]->type;
        }

    }

    for(aux = first->next; aux!=NULL; aux=aux->next)
    {
        if(strcmp(aux->name,t_name)==0)
        {
            
            for(i = 0; i< first->nSymbols; i++)
            {
                if(strcmp(var_name,first->symbols[i]->name)==0)
                    return aux_symbol[i]->type;
            }
        }
    }

    return NULL;
}


void printTables(table* current)
{
    int i = 0;
    to_print_in_order();
    while(current!=0)
    {
        if (strcmp(current->name, "Global")==0)
            printf("===== Global Symbol Table =====\n");
        else
            printf("===== Function %s Symbol Table =====\n", current->name);
        for(i=0; i<current->nSymbols; i++)
        {
            printSymbol(current->symbols[i]);
        }
        current = current->next;
        if(current!=0)
        {
            printf("\n");
        }

    }
}


void printSymbol(symbol* currentSymbol)
{

    if(currentSymbol==0)
    {
        return;
    }
    if (currentSymbol-> name == NULL || currentSymbol->type == NULL)
        return;
    if (currentSymbol->parameters == NULL)
    {
        if (currentSymbol->is_param)
            printf("%s\t%s\tparam", currentSymbol->name, currentSymbol-> type);
        else
            printf("%s\t%s", currentSymbol->name, currentSymbol->type);
    }
    else
    {
        if (currentSymbol->parameters)
        {
            printf("%s\t%s", currentSymbol->name, currentSymbol-> type);
            printf("%s", currentSymbol->parameters);
        }
    }
    
    printf("\n");
}

char* stringToLower(char* string)
{
    char* result = NULL;
    int i = 0;
    if (string == NULL)
        return NULL;
    result= (char*)calloc(strlen(string)+1, sizeof(char));
    strcat(result, "" );

    
    for(i=0; i<strlen(string); i++)
    {
        result[i] = tolower(string[i]);
    }
    return result;
}

char *octal_to_decimal(char *value)
{

    int aux_value = 0;
    char *return_value = NULL;


    if(value[0]=='0')
    {
        sscanf(value,"%o",&aux_value);
        return_value = (char*)malloc(10*sizeof(char));
        sprintf(return_value,"%d",aux_value);
        return return_value;
    }

    else
    {
        return value;
    }
}


   

void to_print_in_order()
{
    table* global = NULL;
    table* prev = NULL;
    table* aux = NULL;
    table* final = NULL;
    table* current_table= NULL;
    
    int i = 0;
    for(global = first; i < global->nSymbols; i++)
    {
        for (current_table = first-> next, prev = first; current_table != NULL; prev = current_table, current_table = current_table->next)
        {
            if (strcmp(current_table->name, global->symbols[i]->name) == 0)
                break;
        }

        if(current_table != NULL)
        {
            prev->next = current_table->next;
            current_table->next = NULL;

            if(final != NULL)
            {
                for(aux = final; aux->next != NULL; aux = aux->next);
                aux->next = current_table;
            }
            else
                final = current_table;
        }
    }

    if(final!=NULL)
        first->next = final;
}

void clearTables(table* current)
{
    if(current == NULL)
    {
        return;
    }
    clearTables(current->next);
    int i;
    for(i=0; i<current->nSymbols; i++)
    {
        if (current->symbols[i]->name != NULL)
        {
            free(current->symbols[i]->name);
            current->symbols[i]->name = NULL;
        }
        
        if (current->symbols[i]->type != NULL)
        {
            free(current->symbols[i]->type);
            current->symbols[i]->type = NULL;
        }
        if (current->symbols[i]->parameters != NULL)
        {
            free(current->symbols[i]->parameters);
            current->symbols[i]->parameters = NULL;
        }
        if (current->symbols[i]->value != NULL)
        {
            free(current->symbols[i]->value);
            current->symbols[i]->value = NULL;
        }
        if (current->symbols[i] != NULL)
        {
            free(current->symbols[i]);
            current->symbols[i] = NULL;
        }
    }
    if (current->name != NULL)
    {
        free(current->name);
        current->name = NULL;
    }
    
    if (current->type != NULL)
    {
        free(current->type);
        current->type = NULL;
    }
    if (current->symbols != NULL)
    {
        free(current->symbols);
        current->symbols = NULL;
    }
    if (current != NULL)
    {
        free(current);
        current = NULL;
    }
    return;
}
