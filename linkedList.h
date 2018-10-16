#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct song_node{char name[100];
                 char artist[100];
		 struct song_node * next;};

void print_list (struct song_node * pointer);

struct song_node * insert_front (struct song_node * pointer, char * song_name, char * artist_name);

struct song_node * insert_inorder (struct song_node * pointer, char * song_name, char * artist_name);

struct song_node * find_node (struct song_node * pointer, char song_name, char * artist_name);

struct song_node * find_first (struct song_node *, char * artist_name);

struct song_node * ran_node (struct song_node * pointer);

struct song_node * remove_node (struct song_node * pointer, char *song_name, char * artist_name );

struct song_node * free_list (struct song_node * pointer);

#endif
