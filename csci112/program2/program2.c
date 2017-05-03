/*
 * Spencer Cornish
 * Program 2, CSCI 112
 * 3/21/2017
 */
 #define MAX_ARRAY_SIZE 50
 #include <stdio.h>
 
 int     populate_array( int array[] );                  // Fill array with values from user.
 void    print_array( int array[], int n );              // Print out the array values
 void    swap( int array[], int index1, int index2 );    // Swap two array elements. 
 void    quicksort( int array[], int low, int high );    // Sorting algorithm
 int     partition( int array[], int low, int high );    // Find the partition point (pivot)
 
 int main(void) {
	 int items[MAX_ARRAY_SIZE];  // Define the Array Size
	 int n = populate_array(items); // Populate the array with user input, return length of inputted data
	 printf("The initial array contains:\n");
	 print_array(items, n); // Print the initial array, before sorting
	 quicksort(items, 0, n-1); // Run the quicksort algorithm
	 printf("The array is now sorted:\n");
	 print_array(items, n); // Print the Sorted Array
	 return 0; // Exit Cleanly
	 
 }
 int populate_array(int array[]) {
	 int n; // Holds number of elements to request from the user
	 do { 
		printf("Enter the value of n > "); 
		scanf("%d", &n); // Scan the value of N
		if(n < 0) { // If n is less than zero
			printf("%d is less than zero. Please try again.\n\n", n);
			continue; // Return to the beginning of the loop
		}
		else if (n > MAX_ARRAY_SIZE) { // If n is greater than the max constant
			printf("%d exceeds the maximum array size. Please try again.\n\n", n);
			continue; // Return to the beginning of the loop
		}
	 } while((n < 0) | (n > MAX_ARRAY_SIZE));
	 printf("Enter %d integers (Positive, negative, or zero) >\n", n);
	 for(int i = 0; i < n; i++) {
		 scanf("%d", &array[i]); // Scan and store integers
	 }
	 return n; // Return the length of the data
 }
 void print_array( int array[], int n ) {
	 for(int i = 0; i < n; i++) {
		 printf("%+5d\n", array[i]); // Print each used element of the array
	 }
 }
 void swap( int array[],int index1, int index2) {
	 int temp = array[index1]; // Store first number in a temp variable
	 array[index1] = array[index2]; // Overwrite index1 with index2
	 array[index2] = temp; // Overwrite index2 with temp (Which holds index1's value)
 }
 void quicksort( int array[], int low, int high ){    // Sorting algorithm
	 if(low < high) { // If the lower bound is lower than the higher one
		 int pivot = partition( array, low, high); // Calculate the pivot
		 quicksort( array, low, pivot - 1); // Recursively sort the lower partition
		 quicksort( array, pivot + 1, high); // Recursively sort the upper partition
	 } 
 }
 int partition( int array[], int low, int high ) {
	 int pivot = array[high]; // Start the pivot on the higher bound
	 int i = low; // set the i index to the lower bound
	 for( int j = low; j < high; j++) {
		 if(array[j] <= pivot) { // if the value at array j is less than or equal to the pivot
			 swap(array, i, j); // Swap the lower bounded array[i] with array[j]
			 i++; // Iterate i
		 }
	 }
	 swap(array, i, high); // Swap array[i] with the high bound index, array[high]
	 return i; // Return i, which is the found partition
 }
 
