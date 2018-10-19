#include <stdio.h>
#include <stdlib.h>
#include "library.c"

int main(){

  srand( time( NULL ) );

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
  printf("TESTING insert_front:\n");
  
  main_pointer = insert_front(main_pointer, song3, artist3);
  main_pointer = insert_front(main_pointer, song4, artist4);

  printf("\n=============================================\n");
  printf("TESTING free_list():\n");
  main_pointer = free_list (main_pointer);

  printf("\n=============================================\n");
  printf("TESTING insert_inorder:\n");

  main_pointer = insert_inorder(main_pointer, song3, artist3);
  main_pointer = insert_inorder(main_pointer, song4, artist4);
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
  printf("TESTING find_first & print_artist_songs:\n");
  print_artist_songs(find_first(main_pointer , "taylor swift"));

  printf("\n=============================================\n");
  printf("TESTING find_node & print_node:\n");
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
  

  printf("current list: ");
  print_list(main_pointer);

  printf("\n- T E S T I N G  L I B R A R Y - \n");

  //print_library();

  char * song7 = "shout out to my ex";
  char * song8 = "black magic";
  char * artist7 = ".little mix";

  printf("=============================================\n");
  printf("TESTING add_song:");
  add_song(song8, artist7);
  add_song(song7, artist7);
  add_song(song1, artist1);
  add_song(song2, artist2);
  add_song(song3, artist3);
  add_song(song4, artist4);
  add_song(song5, artist5);
  add_song(song6, artist6);


  printf("=============================================\n");
  printf("TESTING shuffle:\n");
  shuffle();

  printf("=============================================\n");
  printf("TESTING find_song:\n");
  find_song(song3, artist3);

  printf("=============================================\n");
  printf("TESTING find_arist:\n");
  find_artist(artist3);
  
  //print_library();
  printf("=============================================\n");
  printf("TESTING print_letter:\n");
  char * letter = "t";
  char * letter2 = "e";
  print_letter(letter);
  print_letter(letter2);

  printf("=============================================\n");
  printf("TESTING print_artist:\n");
  print_artist(artist7);

  printf("=============================================\n");
  printf("TESTING print_library:\n");
  print_library();

  printf("=============================================\n");
  printf("TESTING remove_song:\n");

  remove_song(song7, artist7);
  remove_song(song7, artist7);
  remove_song(song7, artist7);

  printf("=============================================\n");
  printf("TESTING clear_library:\n");
  clear_library();

  printf("current lib:\n");
  print_library();

  return 0;
  

}
