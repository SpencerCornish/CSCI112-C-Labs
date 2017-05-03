/*
 * Spencer Cornish
 * Lab 3, CSCI 112
 * 2/04/2017
 */
 #include <stdio.h>
 #include <math.h>
double get_input(void) {
	printf("Enter a number: ");
        /* user input is taken here */
        double curIn;
	    scanf("%lf", &curIn);
		return curIn;
}
int get_N() {
	int numElements;
	// Get number of elements
	do {
		printf("Enter a value for N that is >= 0: ");
		scanf("%d", &numElements);
		// Check to see if N is negative or not
		if(numElements < 0) {
			printf("Invalid value for N \n");
		}
	} while(numElements < 0);
	return numElements;
}
void main(void) {
	int numElements = get_N();
	double highest = 0.0;
	double lowest = 0.0;
	double avg = 0.0;
	double range = 0.0;
	double stdDev = 0.0;
	
	for(int n = 0; n < numElements; n++) {
		// iterate for each number
		double curIn = get_input();
		// Set the lowest value to the first number for init
		if(n == 0) {
			lowest = curIn;
		}
		// Conditionals for lowest and highest values
		if(curIn < lowest) {
			lowest = curIn;
		}
		if(curIn > highest) {
			highest = curIn;
		}
		avg = avg + curIn; // Sum of all elements
		stdDev = stdDev + (curIn * curIn); // Sum of all elements squared
	}
	if(numElements > 0){
		// Calculate the range. "fabs" is for absoulute value of doubles
		range = fabs(highest - lowest);
		avg = avg / numElements;
		stdDev = sqrt((stdDev/numElements) - pow(avg, 2.0));
	}
	printf("The Highest is: %.3f \nThe Lowest is: %.3f \nThe average is: %.3f \nThe range is: %.3f \nThe standard deviation is: %.3f \n ", highest, lowest, avg, range, stdDev);
	}
