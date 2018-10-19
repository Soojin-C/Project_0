struct song_node * table[27];

void print_library();

void print_artist(char * artist_name);

void print_letter(char * letter);

int letter_position(char * string);

void add_song(char * song_name, char * artist_name);

struct song_node * find_song(char * song_name, char * artist_name);

struct song_node * find_artist(char * artist_name);

void remove_song(char * song_name, char * artist_name);

void clear_library();

void shuffle();
