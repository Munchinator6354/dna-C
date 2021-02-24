// Ryan Isaacson, CS&131, Winter 2021
// Programming Assignment #6, dna 02/25/2021
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Helper function for debugging
void print_array(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%-15d", arr[i]);
    }
    puts("");
}

// Helper function for debugging
void print_array_char(char arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%c ", arr[i]);
    }
    puts("");
}

// Helper function for debugging
void print_array_string(char* arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%-15s", arr[i]);
    }
    puts("");
}
//______________________________________________________________________________

// Reads a database file in from the user.
char* file_prompts(char* file1, char* file2) {
  printf("Databasefile: ");
  scanf("%s", file1);
  printf("DNA file: ");
  scanf("%s", file2);
}

FILE* read_file(char* file_name) {
  FILE* file = fopen(file_name, "r");
}

int grab_header(FILE* file, int num_of_str, char* line, char* next, char* str) {
  // Grabs the number of STR's.
  fscanf(file, "%d", &num_of_str);
  printf("%d\n", num_of_str);

  // Grabs the whole next line
  fscanf(file, "%s", line);
  // Puts the name category into it's own variable.
  next = strtok(line, ",");
  printf("%s ", next);

  char* str_arr = (char*) calloc(num_of_str * sizeof(char[10]))

  // Grabs the STR's individually.
  str = strtok(NULL, ",");
  while(str != NULL) {
    printf("%s ", str);
    str = strtok(NULL, ",");
  }
  printf("\n");

  return num_of_str;
}


  // dna/databases/small.csv
int main() {

  // Reads a db_file and dna_file from the user.
  char db_file[100];
  char dna_file[100];
  file_prompts(db_file, dna_file);

  // Reads the given db_file and header
  FILE* file = read_file(db_file);

  // Grabs the number of str sequences in that file and the header line
  // subsequent. Returns the number of str's and breaks apart the header with
  // spaces instead of commas.
  char line[400];
  char* next;
  char str[10];
  int num_of_str = grab_header(file, num_of_str, line, next, str);

  // char* arr_of_strs[20];

  // put_strs_in_array();






  // Scans and prints every line until the End Of File.
  while(fscanf(file, "%s", line) != EOF) {
    // Prints every line including commas
    // printf("%s\n", line);

    next = strtok(line, ",");

    while(next != NULL) {
      printf("%s ", next);
      next = strtok(NULL, ",");
    }
    printf("\n");

  }







  // FILE* file = fopen("dna/databases/small.csv", "r");
  // int num_of_str;
  // char line[100];
  //
  // fscanf(file, "%d", &num_of_str);
  // printf("%d\n", num_of_str);
  //
  // while(fscanf(file, "%s", line) != EOF) {
  //   printf("%s\n", line);
  //   char* name = strtok(line, ",");
  //   char* dna_seq = strtok(NULL, ",");
  //   printf("%s %s\n\n", name, dna_seq);
  //



  // if (file != NULL) {
  //   int num_of_str;
  //   fscanf(file, "%d", &num_of_str);
  //   printf("%d", num_of_str);
  // }


}
