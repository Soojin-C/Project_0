#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

void print_list (struct song_node * pointer){

  while (pointer){

    printf("%s by %s\n", pointer -> name, pointer -> artist);
    pointer = (pointer -> next);
    
  }
  
}

struct song_node * insert_front (struct song_node * pointer, char * song_name, char * artist_name){

  struct song_node * temp = malloc (sizeof(struct song_node));
  strcpy(song_name, temp -> name);
  //strcpy(artist_name, temp -> artist);
  temp -> next = pointer;

  return temp;

}
/*
struct song_node * insert_inorder (struct song_node * pointer, char * song_name, char * artist_name){

  struct song_node * temp = malloc (sizeof(struct song_node));

  while (pointer){

  

  }

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

*/

int main(){

  char * song1 = "abc";
  char * song2 = calloc(3, sizeof(char));
  song2 = "b";
  char * artist1 = "be";
  char * artist2 = "ba";

  struct song_node * main_pointer = malloc(sizeof(struct song_node));
  main_pointer = insert_front(main_pointer, song2, artist1);
  print_list(main_pointer);
  
  return 0;

}
