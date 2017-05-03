/*
* Element Structure Lab
* Author: Spencer Cornish
* Date: 4/13/2017
*/


  //Includes
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <limits.h> // Used for setting the placeholder for the largest and smallest ints

  
  #define MAX_ELEMENTS = 20; // Max elements allowed for input
  


  typedef struct { // Struct for elements
	  int atom_num;
	  char name[20];
	  char symbol[5];
	  char class[30];
	  float weight;
	  int shells[7];
  } element_t;

    //Prototypes
  void scan_element(element_t *ele);
  void print_element(element_t ele);

int main(int argc, char *argv[]) {
		if(argc == 2) { // Checks to make sure there are the proper number of args
			int num = (int)strtol( argv[1], NULL, 10); // Turns the input into an int
			if(num < 1 || num > 20) { // Check that the number of args is > 0 and < 20
				printf("ERROR: You must provide an integer greater than 0 and less than or equal to 20.\n");	
				return -1; // Exit on error
			}
			int small_anum = INT_MAX; // Placeholder values for calculating what element has the smallest and largest atomic numbers
			int large_anum = INT_MIN;
			char *small_ele; // Stores pointers to the names of the smallest and largest elements
			char *large_ele;
			element_t elements[num]; // Array of element structs of length num from args
			for(int i = 0; i < num; i++) { // Iterate number specified by args
				scan_element(&elements[i]); // Scan in all elements
				
				
				if(elements[i].atom_num > large_anum) { // New largest atomic number
					large_anum = elements[i].atom_num; // Update variables
					large_ele = elements[i].name;
				}
				if(elements[i].atom_num < small_anum) { // New smallest atomic number
					small_anum = elements[i].atom_num; 
					small_ele = elements[i].name;
				}
			}
			//Print general info
			printf("%d total elements.\n", num);
			printf("%s had the smallest atomic number.\n", small_ele);
			printf("%s had the largest atomic number.\n", large_ele);
			// Print the elements stored in the elements[] array
			for(int i = 0; i < num; i++) {
				print_element(elements[i]);
			}

		}
		else { // Error on arguement (None or too many)
			printf("ERROR: You must provide exactly one argument to this program.\n");	
			return -1; // Exit on error
		}	
}
// Scan element components from line, and pass them back into the struct in question
void scan_element(element_t *ele) {
	// Use fscanf to scan in the line and sort each piece to the proper variable in the struct passed in by reference
	fscanf(stdin, "%d %s %s %s %f %d %d %d %d %d %d %d", &ele->atom_num, ele->name, ele->symbol, ele->class,
				&ele->weight, &ele->shells[0], &ele->shells[1], &ele->shells[2], &ele->shells[3], &ele->shells[4], &ele->shells[5], &ele->shells[6]);
	
	
	
}
// Print the element
void print_element(element_t ele) {
	printf("---------------\n");
	printf("| %d    %.4f\n", ele.atom_num, ele.weight);
	printf("| %s    %s\n| ", ele.symbol, ele.name);
	for(int i = 0; i < 7; i++) { // Iterate trhrough shells
		if(ele.shells[i] != 0) { // Only print shells that do not equal 0
			printf("%d ", ele.shells[i]);
		}
	}
	printf("\n---------------\n");
}
