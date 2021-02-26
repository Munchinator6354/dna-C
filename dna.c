// Ryan Isaacson, CS&131, Winter 2021
// Programming Assignment #6, dna 02/25/2021
//
// This program will search through a database and find a specified CSV file
// with patient data on their DNA and compare that to a DNA sequence in another
// specified file. After comparing the two it will return whether or not there
// was a match in the DNA sequence to a patient in the file based on structures
// in the DNA known as STRs or Short Tandem Repeats.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

// Grabs the header of a specified CSV file and returns an array of STR's.
char** grab_header(FILE* file, int* num_of_str, char* line) {
  // Grabs the number of STR's.
  fscanf(file, "%d", num_of_str);

  // Grabs the whole next line
  fscanf(file, "%s", line);

  // Puts the name category into it's own variable.
  char* next = strtok(line, ",");
  // printf("%s ", next);

  // Creates array of strings to store STR's
  char** str_arr = (char**) malloc(*num_of_str * sizeof(char*));

  // Grabs the STR's individually and puts them into an array.
  for(int i = 0; i < *num_of_str; i++) {
    char* str = strtok(NULL, ",");
    str_arr[i] = (char*) malloc((strlen(str) + 1) * sizeof(char));
    str_arr[i] = str;

  }
  return str_arr;
}

// Counts the number of occurences of a given STR in a sequence of DNA and
// returns the count.
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

// Checks if there is a match to the DNA sequence for a person in the database.
int determine_match(int match_checker, FILE* file, char* line, int num_of_str,
                                                            int* occurences) {
  while(fscanf(file, "%s", line) != EOF) {
    // Grabs the individuals name.
    char* name = strtok(line, ",");

    // Creates an array to store the individuals str_counts
    int str_count[num_of_str];

    // This will loop through the individuals str_counts and put them into
    // an index.
    for(int i = 0; i < num_of_str; i++) {
      str_count[i] = atoi(strtok(NULL, ","));
    }

    // Checks if the 3 counts in the DNA sequence match the 3 counts for an
    // individual.
    int match_count = 0;
    for(int i = 0; i < num_of_str; i++) {
      if(str_count[i] == occurences[i]) {
        match_count++;
      }
    }

    // If there is a full STR count match, this prints out the match name.
    if(match_count == num_of_str) {
      char* print_name = name;
      printf("Match: %s", name);
      match_checker++;
    }
  }
  return match_checker;
}

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
  int num_of_str = 0;
  char** str_arr = grab_header(file, &num_of_str, line);

  // Reads in data from the dna file given by the user.
  FILE* file2 = read_file(dna_file);

  // Grabs the dna sequence from it's file.
  char dna_line[6500];
  fscanf(file2, "%s", dna_line);

  // Creates a space to store the occurences of str's in the dna sequence.
  int occurences[num_of_str];

  // Loops through a DNA sequence and returns the amount of times an str is in
  // the sequence.
  for(int i = 0; i < num_of_str; i++) {
    occurences[i] = count_str_occurences(str_arr[i], dna_line);
  }
  printf("Counts: [%d", occurences[0]);
  for(int i = 1; i < num_of_str; i++) {
    printf(", %d", occurences[i]);
  }
  printf("]\n");

  // Scans every line until the End Of File and returns if there is a DNA match
  // in the database.
  int match_checker = 0;
  match_checker = determine_match(match_checker, file, line, num_of_str,
                                                                  occurences);
  // If there is no match, prints that no matches were found.
  if(match_checker == 0) {
    printf("No matches found.");
  }
}
