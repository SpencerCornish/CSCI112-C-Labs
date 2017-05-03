  /*
   * Homegrown strncpy test program
   * Author: Spencer Cornish
   * Date: 3/30/2017
   */
  #include <stdio.h>
  #include <string.h>

  // Function prototypes
  char *my_strncpy(char *dest, char *source, int n);
  char *my_strncat(char *dest, char *source, int n);

  // ********* Insert your my_strncpy implementation here! *************

  char *my_strncpy(char *dest, char *source, int n) {
	 for ( int i = 0; i < n; i++ ) { // For loop iterates from beginning of dest to n
		  dest[i] = source[i]; // Copy from 0 to n-1 characters to dest from source 
	  }
	  dest[n] = '\0'; // Append null character at n, which clears the rest of what was in dest
	  return dest; // Return the destination pointer
  }
  // ********* Insert your my_strncat implementation here! *************
  char *my_strncat(char *dest, char *source, int n) {
	  int dest_len = strlen(dest); // Length of the current destination string
	  for ( int i = 0; i < n; i++ ) { // iterate from the beginning of src to n
		  dest[i + dest_len] = source[i]; // place source chars(0 to n) at the end of the current dest string
	  }	  
	  return dest; // Return the destination pointer
  }
  int main() {
    // Test your function with various source strings and values of n

    char testSrc[] = "Hello";
    char testDest[40] = "World"; // Must be large enough to hold the length of src + dest (for strcat)
    int n = 5; // Number of src chars to copy to dest

    my_strncat(testDest, testSrc, n);
    printf("CAT: %s \n", testDest);

    my_strncpy(testDest, testSrc, n);
    printf("CPY: %s \n", testDest);

    printf("%s \n", testDest);
    return 0; // Exit cleanly
  }
