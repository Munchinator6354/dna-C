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

// Reads a database file and dna file in from the user.
char* file_prompts(char* file1, char* file2) {
  printf("Databasefile: ");
  scanf("%s", file1);
  printf("DNA file: ");
  scanf("%s", file2);
}

// Reads a file.
FILE* read_file(char* file_name) {
  FILE* file = fopen(file_name, "r");
}

char** grab_header(FILE* file, int* num_of_str, char* line) {
  // Grabs the number of STR's.
  fscanf(file, "%d", num_of_str);
  // printf("DEBUG # of STR %d\n", num_of_str);

  // Grabs the whole next line
  fscanf(file, "%s", line);
  // printf("%s", line);

  // Puts the name category into it's own variable.
  char* next = strtok(line, ",");
  printf("%s ", next);
  // printf("DEBUG#ofSTRS?  %d", num_of_str);
  // Creates array of strings to store STR's
  char** str_arr = (char**) malloc(*num_of_str * sizeof(char*));

  // Grabs the STR's individually and puts them into an array.
  for(int i = 0; i < *num_of_str; i++) {
    char* str = strtok(NULL, ",");
    // printf("DEBUG STR: %s", str);
    str_arr[i] = (char*) malloc((strlen(str) + 1) * sizeof(char));
    str_arr[i] = str;

  }
  printf("\n");

  return str_arr;
}

int count_str_occurences(char* substring, char* string) {
  int count = 0;
  if (substring != NULL && string != NULL) {
    int len_string = strlen(string);
    int len_substring = strlen(substring);

    if(len_string > 0 && len_substring > 0) {
      for(int i = 0; i < len_string; i++) {
        if(0 == strncmp(substring, string + i, len_substring)) {
          count++;
        }
      }
    }
  }
  return count;
}



int main() {

  // Reads a db_file and dna_file from the user.
  char db_file[100];
  char dna_file[100];
  file_prompts(db_file, dna_file);

  // Reads the given db_file and header
  // USE TO TEST: dna/databases/small.csv
  // USE TO TEST: dna/databases/large.csv
  FILE* file = read_file(db_file);

  // Grabs the number of str sequences in that file and the header line
  // subsequent. Returns the number of str's and breaks apart the header with
  // spaces instead of commas.
  char line[400];
  int num_of_str = 0;
  char** str_arr = grab_header(file, &num_of_str, line);

  // TESTS TO SEE IF ARRAY IS RETURNED AND WILL PRINT
  print_array_string(str_arr, num_of_str);

  // Reads in data from the dna file given by the user.
  // USE TO TEST: dna/sequences/17.txt
  FILE* file2 = read_file(dna_file);

  // Grabs the dna sequence from it's file.
  char dna_line[6500];
  fscanf(file2, "%s", dna_line);
  printf("%s", dna_line);



  printf("DEBUG: %d", num_of_str);

  // Creates a space to store the occurences of str's in the dna sequence.
  int occurences[num_of_str];

  // Loops through a DNA sequence and returns the amount of times an str is in
  // the sequence.
  for(int i = 0; i < num_of_str; i++) {
    occurences[i] = count_str_occurences(str_arr[i], dna_line);
  }

  printf("\nDEBUG Occur1: %d\n", occurences[0]);
  printf("DEBUG Occur2: %d\n", occurences[1]);
  printf("DEBUG Occur3: %d\n", occurences[2]);


















  // Scans and prints every line until the End Of File.
  // while(fscanf(file, "%s", line) != EOF) {
  //   // Prints every line including commas
  //   // printf("%s\n", line);
  //
  //   next = strtok(line, ",");
  //
  //   while(next != NULL) {
  //     printf("%s ", next);
  //     next = strtok(NULL, ",");
  //   }
  //   printf("\n");
  //
  // }







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
