/*
 * Spencer Cornish
 * Lab 4, CSCI 112
 * 2/19/2017
 */
 
 #include <stdio.h> // Includes
 #include <math.h>
 #define PI 3.14159 // Constants
 #define LOOP_LIMIT 90
 typedef enum {
	 Sine,
	 Cosine,
	 Tangent,
	 QUIT
 } menu_t; // Menu enum
 void sine() { // Calculates Sine
	 double sine;
	 for(int i = 0; i <= LOOP_LIMIT; i += 15) {
		 sine = sin(PI * i/180);
		 printf("\tsin(%d) = %.4f\n", i, sine);
	 }
 }
 void cosine() { // Calulates Cosine
	 double cosine;
	 for(int i = 0; i <= LOOP_LIMIT; i += 15) {
		 cosine = cos(PI * i/180);
		 printf("\tcos(%d) = %.4f\n", i, cosine);
	 }
 }
  void tangent() { // Calculates Tangent
	 double tangent;
	 for(int i = 0; i <= LOOP_LIMIT; i += 15) {
		 if(i == 90) {
			 printf("\ttan(%d) is UNDEFINED\n", i);
		 }
		 else{
			 tangent = tan(PI * i/180);
			 printf("\ttan(%d) = %.4f\n", i, tangent);
		 }
	 }
 }
 
 
 int main(void) { 
	 while(1) { // Indefinite Loop
		 menu_t MENU; // Enum
		 printf("Please Choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\n");
		 printf("Enter your choice > ");
		 scanf("%u", &MENU);
		 switch(MENU) {
			 case Sine :
				sine();
				break;
			 case Cosine : 
				cosine();
				break;
			 case Tangent :
				tangent();
				break;
			 case QUIT :
				printf("You chose QUIT. Thank you, come again!\n");
				return 0; // Exits Cleanly
				break;
			 default:
				printf("%d is an invalid option. Please try again.\n", (int)MENU);
				break;
		 }
		 
		 
	 }
	 
	 
	 
	 
	 
	 
 }