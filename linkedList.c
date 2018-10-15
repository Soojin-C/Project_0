#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void print_list (struct song_node * pointer){

  while (pointer){

    printf("%s by %s\n", pointer->name[100], pointer->artist[100]);
    pointer = (pointer -> next);
    
  }
  
}

struct song_node * insert_front (struct song_node * pointer, char name[100] new_name, char artist[100] new_artist){

  struct song_node * temp = malloc (sizeof(struct song_node));
  temp -> name[100] = new_name;
  temp -> artist[100] = new_artst;
  temp -> next = pointer;

  return temp;

}

struct song_node * insert_inorder (struct song_node * pointer, char name[100], char artist[100]){

}

struct song_node * find_node (struct song_node * pointer, char name[100], char artist[100]){

}

struct song_node * find_first (struct song_node *, char artist[100]){

}

struct song_node * ran_node (struct song_node * pointer){

}

struct song_node * remove_node (struct song_node * pointer, char artist[100], char name[100] ){

  struct song_node * prev = malloc(sizeof(struct song_node));
  prev = pointer;

  while (pointer){

    pointer = pointer -> next;
    
    
  }
  

}

struct song_node * free_list (struct song_node * pointer){

  struct song_node * prev = malloc(sizeof(struct song_node));
  prev = pointer;
  pointer = pointer -> next;

  while (pointer){

    free(prev);
    prev = pointer;
    pointer = pointer -> next;

  }

  free(prev);
  return pointer;

}
