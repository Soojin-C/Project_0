#include <stdio.h>
#include <stdlib.h>
#include "linkedList.c"
#include "library.h"

void print_library(){
  
  int length = 0;
  while(length - 27){

    if (table[length]){

      char temp = (char)(length + (int)'a');
      char * pointer = &temp;
      print_letter(pointer);

    }
    length++;
    
  }

}

void print_artist(char * artist_name){

  print_artist_songs(find_artist(artist_name));

}

void print_letter(char * letter){

  printf("%c ----------------------\n", *letter);
  print_list(table[letter_position(letter)]); 

}

int letter_position(char * string){

  char * letter = malloc(sizeof(char));
  strncpy(letter, string, 1);

  int position = (int)(*letter) - (int)'a';

  //printf("%d\n", (int)'Z' - (int)'a');
  //printf("letter: %s\nposition: %d\n", letter , position);

  if (position < 0 || position > 26){

    position = 26;

  }
  return position;
  
}

void add_song(char * song_name, char * artist_name){

  int position = letter_position(artist_name);
  table[position] = insert_inorder(table[position],song_name, artist_name);
  //print_list(table[position]);

}

struct song_node * find_song(char * song_name, char * artist_name){

  return find_node(find_artist(artist_name), song_name, artist_name);

}

struct song_node * find_artist(char * artist_name){

  return find_first(table[letter_position(artist_name)], artist_name);

}

void remove_song(char * song_name, char * artist_name){

  int position = letter_position(artist_name);
  table[position] = remove_node(table[position], song_name, artist_name);

}

void clear_library(){

  printf("..clearing library\n");
  int index = 0;
  while (index < 27){

    if (table[index]){

      table[index] = free_list(table[index]);

    }
    index++;

  }

}

void shuffle(){

  int rand_songs = 4;
  int index = 0;
  struct song_node * all_songs = malloc(sizeof(struct song_node));
  struct song_node * curr_list = malloc(sizeof(struct song_node));
  all_songs = NULL;

  while (index < 27){

    curr_list = table[index];
    if (curr_list){

	while (curr_list){

	  all_songs = insert_inorder(all_songs, curr_list -> name, curr_list -> artist);
	  curr_list = curr_list -> next;
	  
	}

    }
    index ++;

  }

  while (rand_songs){

    print_node(rand_node(all_songs));
    rand_songs --;

  }

}
