#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedList.h"


void print_list (struct song_node * pointer){

  int counter = 0;
  while (pointer){

    printf("[%d] ", counter);
    print_node (pointer);
    pointer = pointer -> next;
    counter += 1;
    
  }
  print_node(pointer);
  
}

void print_node(struct song_node * pointer){

  if (pointer){
    printf("%s by %s\n", pointer -> name, pointer -> artist);
  }

  else{
    printf("NULL\n");
  }

}

void print_artist_songs(struct song_node * pointer){

  char * orig_artist;
  int counter = 0;

  while (pointer){

    orig_artist = pointer -> artist;
    if (pointer -> artist == orig_artist){

      printf("[%d] ", counter);
      print_node(pointer);
      counter ++;

    }
    pointer = pointer -> next;
    
  }

}

struct song_node * insert_front (struct song_node * pointer, char * song_name, char * artist_name){

  printf("...inserting %s by %s\n", song_name, artist_name);
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
  if (prev){

    prev -> next = pointer;
    
  }

  else{

    orig = pointer;

  }
  return orig;

}


struct song_node * find_node (struct song_node * pointer, char * song_name, char * artist_name){

  printf("...finding %s by %s\n", song_name, artist_name);

  struct song_node * temp = malloc(sizeof(struct song_node));
  temp = pointer;
  while (temp){

    if (strcmp (artist_name, temp->artist) == 0){

      if (strcmp (song_name, temp->name) == 0){

	return temp;

      }
      
    }
    temp = temp -> next;

  }
  return temp;

}


struct song_node * find_first (struct song_node * pointer , char * artist_name){

  printf("...finding by %s\n", artist_name);
  while(pointer){

    if (strcmp(artist_name, pointer -> artist) == 0){

      return pointer;
      
    }

    pointer = pointer -> next;
  }
  return pointer;

}

int struct_length(struct song_node * pointer){

  int len = 0;
  while (pointer){

    len += 1;
    pointer = pointer -> next;

  }
  return len;

}

struct song_node * rand_node (struct song_node * pointer){

  int counter = rand() % 20;
  int random;
  while (counter){

    random = rand();
    counter --;

  }
  random = random % (struct_length(pointer));

  while (random){

    pointer = pointer -> next;
    random -= 1;

  }
  return pointer;

}


struct song_node * remove_node (struct song_node * pointer, char * song_name, char * artist_name ){

  printf("...removing %s by %s\n", song_name, artist_name);

  struct song_node * prev = malloc(sizeof(struct song_node));
  struct song_node * orig = malloc(sizeof(struct song_node));

  orig = pointer;
  prev = NULL;
  int cmp_name;
  int cmp_artist;

  while (pointer){
  
    cmp_name = (strcmp(song_name, pointer -> name));
    cmp_artist = (strcmp(artist_name, pointer -> artist));

    if (cmp_name == 0  && cmp_artist == 0){
      if(prev){
	prev -> next = pointer-> next;
      }
      else{
	prev = pointer -> next;
	orig = prev;
      }

      free(pointer);
      return orig;

    }
    prev = pointer;
    pointer = pointer -> next;
  }
  printf("song not found\n");
  return orig;
  
}

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

