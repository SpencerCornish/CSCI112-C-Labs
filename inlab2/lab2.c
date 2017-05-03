/*
 * Spencer Cornish
 * Lab 2, CSCI 112
 * 1/30/2017
 */
 #include <stdio.h>
double get_input(void)
{
	/* Prompt for User Input */
    printf("Enter a value > ");
    /* user input is taken here */
    double in;
	scanf("%lf", &in);
	return(in);
}
double get_next(double firstNum, double secNum)
{
	/* Does tha math for the next number in the sequence */
	double xNext = (firstNum/2)+(3*secNum);
	return(xNext);
}
void print_result(double num)
{
	printf("the result is %.2f \n", num);
}
void main(void)
 { 
	/* Read in the first two numbers in the sequence */
	double x1 = get_input();
	double x2 = get_input();
	/* Run the function three times */
	double x3 = get_next(x1, x2);
	double x4 = get_next(x2, x3);
	double x5 = get_next(x3, x4);
	/* Prints the result of the math */
	print_result(x5);
	
 
 }
 
