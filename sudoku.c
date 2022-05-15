#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int* vacio()
{
  int* creador=(int*)malloc(sizeof(int)*11);
  for(int i=0;i<10;i++)
    {
      creador[i]=0;
    }
  return creador;
}

int is_valid(Node* n)
{
  int* flag;
  for(int i=0;i<9;i++)
  {
    flag=vacio();
    for(int j=0;j<9;j++)
    {
      int sudo=n->sudo[i][j];
      if(sudo!=0)
      {
        if(flag[sudo]!=0)
        {
          return 0;
        }
        flag[sudo]=1;
      }
    }
    free(flag);
    flag=vacio();
    for(int j=0;j<9;j++)
      {
        int sudo=n->sudo[j][i];
        if(sudo!=0)
        {
          if(flag[sudo]!=0)
          {
            return 0;
          }
          flag[sudo]=1;
        }
      }
    free(flag);
  }
  for(int l=0;l<9;l++)
    {
      flag=vacio();
      for(int a=0;a<9;a++){
        int i = 3 * (l / 3) + (a / 3);
        int j = 3 * (l % 3) + (a % 3);

        int sudo=n->sudo[i][j];
        if(sudo==0)continue;
        if(flag[sudo]==0)
        {
          flag[sudo]=1;
        }
        else
        {
          free(flag);
          return 0;
        }
      }
    }

    return 1;
}

int posicionActual(Node*n,int linea)
{
  for(int i=0;i<9;i++)
    {
      if(n->sudo[linea][i]==0)
      {
        return i;
      }
    }
  return 0;
}
List* get_adj_nodes(Node* n)
{
  List* list=createList(); 
  for(int i=0;i<9;i++)
  {
    if(posicionActual(n,i)!=0)
    {
      for(int j=1;j<10;j++)
      {
        Node* Adj=copy(n);
        int detecotr=posicionActual(n,i);
        Adj->sudo[i][detecotr]=j;
        if(is_valid(Adj)==1)
        {
          pushBack(list,Adj);
        }
      }
    }
    break;
  }
  return list;
}


int is_final(Node* n)
{
  for(int i=0;i<9;i++)
    {
      for(int j=0;j<9;j++)
        {
          if(n->sudo[i][j]==0)
          {
            return 0;
          }
        }
    }
    return 1;
}

Node* DFS(Node* initial, int* cont){
  Stack* S=createStack();
  push(S,initial);
  while (size(S) != 0){
     node* n = pop(S);
     if n.visited==true continue;
    
     //visitar nodo
     n.visited=true
     List* adj=get_adj_nodes(n);
     node* aux= first(adj);
     while(aux){
        push(S,aux);
        aux=next(adj);
     }
}

}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/