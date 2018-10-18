#include <stdio.h>
#include <stdlib.h>
#include "linkedList.c"

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

  printf("- T E S T I N G  L I N K E D L I S T -\n");

  printf("=============================================\n");
  printf("TESTING insert_front:\n inserting %s by %s \n inserting %s by %s\n", song3, artist3, song4, artist4);
  
  main_pointer = insert_front(main_pointer, song3, artist3);
  main_pointer = insert_front(main_pointer, song4, artist4);

  printf("\n=============================================\n");
  printf("TESTING insert_inorder:\n");
  printf(" inserting %s by %s \n inserting %s by %s\n inserting %s by %s \n inserting %s by %s\n", song2, artist2, song1, artist1, song5, artist5, song6, artist6);

  main_pointer = insert_inorder(main_pointer, song2, artist2);
  main_pointer = insert_inorder(main_pointer, song1, artist1);
  main_pointer = insert_inorder(main_pointer, song5, artist5);
  main_pointer = insert_inorder(main_pointer, song6, artist6);

  printf("\n=============================================\n");
  printf("TESTING print_list:\n");
  print_list(main_pointer);

  //main_pointer = free_list(main_pointer);
  //print_list(main_pointer);

  printf("\n=============================================\n");
  printf("TESTING find_first:\n");
  printf("...finding first song by taylor swift\n");
  print_list(find_first(main_pointer , "taylor swift"));

  printf("\n=============================================\n");
  printf("TESTING find_node:\n");
  printf("...finding perfect by ed sheeran\n");
  print_node(find_node(main_pointer, "perfect", "ed sheeran"));

  printf("\n=============================================\n");
  printf("TESTING struct_length\nlength of the main_pointer: %d \n", struct_length(main_pointer));

  printf("\n=============================================\n");
  printf("TESTING rand_node & remove_node:\n");
  while(main_pointer){

    struct song_node * pointer = malloc(sizeof(struct song_node));
    pointer = rand_node(main_pointer);
    printf("rand_node: ");
    print_node(pointer);
    printf("...removing the rand_node using remove_node\n");
    main_pointer = remove_node(main_pointer, pointer -> name, pointer -> artist);
    }

  print_list(main_pointer);
  return 0;

}
