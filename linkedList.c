#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

void print_list (struct song_node * pointer){

  while (pointer){

    printf("%s by %s\n", pointer -> name, pointer -> artist);
    pointer = pointer -> next;
    
  }
  
}

struct song_node * insert_front (struct song_node * pointer, char * song_name, char * artist_name){

  struct song_node * temp = malloc (sizeof(struct song_node));
  strcpy(temp -> name, song_name);
  strcpy(temp -> artist, artist_name);
  temp -> next = pointer;

  return temp;

}

struct song_node * insert_inorder (struct song_node * pointer, char * song_name, char * artist_name){

  struct song_node * prev = malloc (sizeof(struct song_node));
  struct song_node * orig = malloc (sizeof(struct song_node));
  prev = NULL;
  orig = pointer;
  
  int cmp_name;
  int cmp_artist;

  while (pointer){
    
    cmp_name = strcmp(pointer->name, song_name);
    cmp_artist= strcmp(pointer->artist, artist_name);

    if ((cmp_artist > 0) || (cmp_artist == 0 && cmp_name > 0)){

      pointer = insert_front(pointer, song_name, artist_name);
      if (prev){
	prev -> next = pointer;
	return orig;
      }
      return pointer;   
    }

    prev = pointer;
    pointer = pointer -> next;

  }

  pointer = insert_front(pointer, song_name, artist_name);
  prev -> next = pointer;
  return orig;

}

/*

struct song_node * find_node (struct song_node * pointer, char * song_name, char * artist_name){



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
*/

struct song_node * free_list (struct song_node * pointer){

  struct song_node * prev = malloc(sizeof(struct song_node));
  prev = NULL;

  while (pointer){

    prev = pointer;
    pointer = pointer -> next;
    free(prev);

  }
  return pointer;

}



int main(){

  char * song1 = "perfect";
  char * song2 = "delicate";
  char * song3 = "sad song";
  char * song4 = "look what you made me do";
  char * song5 = "take me to church";
  char * song6 = "fireflies";
  
  char * artist1 = "ed sheeran";
  char * artist2 = "taylor swift";
  char * artist3 = "we the kings";
  char * artist4 = "taylor swift";
  char * artist5 = "hozier";
  char * artist6 = "owl city";

  struct song_node * main_pointer = malloc(sizeof(struct song_node));
  main_pointer = NULL;

  //main_pointer = insert_front(main_pointer, song3, artist3);
  main_pointer = insert_front(main_pointer, song4, artist4);
  
  printf("adding 3, 4:\n\n");
  print_list(main_pointer);

  main_pointer = insert_inorder(main_pointer, song2, artist2);
  main_pointer = insert_inorder(main_pointer, song1, artist1);
  main_pointer = insert_inorder(main_pointer, song5, artist5);
  main_pointer = insert_inorder(main_pointer, song3, artist3);
  
  printf("adding 2, 1:\n\n");
  print_list(main_pointer);

  main_pointer = free_list(main_pointer);
  print_list(main_pointer);
  
  return 0;

}
