/*
 * Spencer Cornish
 * Lab 5, CSCI 112
 * 3/02/2017
 */
 
 #include <stdio.h> // Includes
 #define CODE_SIZE 12 // Defines the length of the barcode we will be looking at
 
 void get_input(int *arr) {
	 printf("Enter a bar array to check. Separate digits with a space > \n");
	 int i = 0;
	 while (i < CODE_SIZE && scanf("%d", &arr[i++]) == 1); // Take in the input, sans white space
	 printf("You entered the code:"); // Print the code
	 for(int i = 0; i < CODE_SIZE; ++i) {
		 printf(" %d", arr[i]);
	 }
	 printf("\n"); // Carridge return
}
 int step_one(int *arr) {
	 int sum  = 0;
	 for(int i = 0; i < CODE_SIZE; i += 2) { // Sum odds, then multiply by three
		 sum += arr[i];
	 }
	 return sum*3;
 
}
int step_two(int *arr) {
	 int sum  = 0;
	 for(int i = 1; i < CODE_SIZE-1; i += 2) { // Sum evens then return
		 sum += arr[i];
	 }
	 return sum;
 }
 int step_four(int sum) {
	 int check = sum % 10; // Remainder after division by 10
	 if(check == 0) {
		 return 0;
	 }
	 else {
		 return 10 - check;
	 }
 } 
 int main(void) {
	 int array[CODE_SIZE]; // Define the array
	 get_input(array); // Get input for the array (send pointer to get_input)
	 int stepOne = step_one(array); // Get the sum for step 1 (send pointer)
	 int stepTwo = step_two(array); // Get the sum for step 2 (send pointer)
	 int stepThree = stepOne + stepTwo; // Add stepOne and stepTwo together
	 int stepFour = step_four(stepThree); // Extract the last digit of the sum (send pointer)
	 //////////////////////////////
	 // Printing section //////////
	 //////////////////////////////
	 printf("STEP 1: Sum of odds times 3 is %d\n", stepOne);
 	 printf("STEP 2: Sum of the even digits is %d\n", stepTwo);
	 printf("STEP 3: Total sum is %d\n", stepThree);
	 printf("STEP 4: Calculated check digit is %d\n", stepFour);
	 if(stepFour == array[CODE_SIZE-1]) { // Compare the check digit to the 12th digit of the array, and print the result of the conditional
		 printf("STEP 5: Check digit and last digit match\n");
		 printf("Barcode is VALID.\n\n");
	 }
	 else {
		 printf("STEP 5: Check digit and last digit do not match\n");
		 printf("Barcode is INVALID.\n\n");
	 }

 
 } 