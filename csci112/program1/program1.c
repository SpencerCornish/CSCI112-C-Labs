/*
 * Spencer Cornish
 * Program 1, CSCI 112
 * 2/20/2017
 */
 
 #include <stdio.h>
  /* Function to determine validity
	 of the user's input */
 int is_valid(int uinput) {
	 if(uinput < 1) { // Checks for less than 0 input
		 printf("You have entered a number less than 1. Please try again.\n\n");
		 return 0;
	 }
	 else if(uinput > 10) { // Checks for greater than 0 input
		 printf("You have entered a number greater than 9. Please try again.\n\n");
		 return 0;
	 }
	 else if(uinput % 2 == 0){ // Uses a modulus function to check for even-ness
		 printf("You have entered an even number. Please try again.\n\n");
		 return 0;
	 }
	 else return 1; // If everything checks out, return 1
	 
 }
 /* Function to get user input
	continues to ask if the user
	inputs invalid information */
 int get_input() {
	 int input; // Input variable
	 int valid; // Validity variable
	 do {
		 printf("Enter an odd number less than or equal to 9 and greater than 0 > ");
		 scanf("%d", &input);
		 valid = is_valid(input);
	 } while(valid == 0); // runs while input is invalid
	 return input;
 }

  /* Function to print pattern */
 void print_pattern(int count) {
	 	 printf("\n"); // Padding
	 for(int i = 1; i <= count; i += 2) { // Line Iteration - Top of shape
		 printf("%*s", count-i, ""); // Prints spaces
		 int printed = 1; // Tacks number of chars printed in the while loop
		 while(printed <= i) {
			 printf("%d ",printed);
			 printed++;
		 }
		 printf("\n"); // Carrage return after each line
		 
	 }
	 for(int i = count-2; i > 0; i -= 2) { // Line Iteration - Bottom of shape
		 printf("%*s", i-count, "");
		 int printed = 1;
		 while(printed <= i) {
			 printf("%d ",printed);
			 printed++;
		 }
		 printf("\n");
		 
	 }
	 printf("\n"); // Padding
 }
 

 int main(void) {
	 int input; // Input variable
	 input = get_input(); // Get input
	 print_pattern(input); // Send input to pattern printer
 }