// Ryan Isaacson, CS&131, Winter 2021
// Programming Assignment #6, dna 02/25/2021
//
//

#include <stdio.h>

int main() {
  // Reads a database file in from the user.
  printf("Databasefile: ");
  char db_file[100];
  scanf("%s", db_file);
  // printf("%s", db_file);

  // Reads a DNA file in from the user.
  printf("DNA file: ");
  char dna_file[100];
  scanf("%s", dna_file);
  // printf("%s", dna_file);

  FILE* file = fopen(db_file, "r");
  int num_of_str;
  char line[400];

  fscanf(file, "%d", &num_of_str);
  printf("%d\n", num_of_str);

  fscanf(file, "%s", line);
  printf("%s\n", line);

  while(fscanf(file, "%s", line) != EOF) {
    printf("%s\n", line);
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
