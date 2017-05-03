  /*
   * Reverse Words on a Line
   * Author: Spencer Cornish
   * Date: 4/6/2017
   */
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <ctype.h>   
   
    #define SIZE 80 // Max String length
	void reverse(char in[]); // Reverse Method Declaration
	
	int main(int argc, char *argv[]) {
		if(argc == 2) { // Checks to make sure there are the proper number of args
			int num = (int)strtol( argv[1], NULL, 10); // Turns the input into an int
			if(num < 0) { // Check that the number of args is > 0
				printf("ERROR: Please provide an integer greater than or equal to 0\n\n");	
				return -1; // Exit on error
			}
			for(int i = 0; i < num; i++) { // Iterate number specified by args
				char cstr[SIZE];
				if ( fgets( cstr, SIZE, stdin ) ) { // Get the input string
					reverse(cstr); // Reverse the String
				}
			}
		}
		else { // Error on arguement
			printf("ERROR: Please provide an integer greater than or equal to 0\n\n");	
			return -1; // Exit on error
		}	
	}
	void reverse(char in[]) {
		char temp[SIZE] = ""; // Reversal String 
		int len = strlen(in)-2; //Total length of the character array
		int word_len = 0; // Set initial word length to 0
		int i; // Iterator
		for(i = len; i > -1; i--){
			if(in[i] == ' ' && word_len > 0) { 
				strncat(temp, &in[i+1], word_len); // Cats the string onto Temp
				strncat(temp, " ", 1); // Cats a space
				word_len = 0; // Resets word length
			}
			else if(isalnum(in[i])) {
				word_len++; // Adds to word length
			}
		}
		if(word_len > 0) {
				strncat(temp, &in[i+1], word_len); // Cats the word to Temp
				//strncat(temp, " ", 1);
				word_len = 0; // Resets word_len
			}
		printf("%s\n", temp); // Print the new string
		memset(temp, '\0', strlen(temp)); // Clear the temp string memory for the next run
	}