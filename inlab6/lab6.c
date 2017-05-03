/*
 * Spencer Cornish
 * Lab 6, CSCI 112
 * 3/09/2017
 */
 
 #include <stdio.h> // Includes
 #include <math.h>
 // List of all function prototypes

    // displays user menu, reads input, and validates input
    int user_menu();

    // Equation functions that are pass by reference
    void equation1(float *);            // calculate motion equation 1
    void equation2(float *);            // calculate motion equation 2
    void equation3(float *);            // calculate motion equation 3
    void equation4(float *);            // calculate motion equation 4

    // User input functions return a value from user
    float get_position_initial(void);   // Prompts user for x0
    float get_position_final(void);     // Prompts user for xf
    float get_velocity_initial(void);   // Prompts user for v0
    float get_velocity_final(void);     // Prompts user for vf
    float get_acceleration(void);       // Prompts user for a
    float get_time(void);               // Prompts user for t
 
 int main (void)
    {
        // Print welcome message
        printf("Welcome to the MOTION EQUATION CALCULATOR\n\n");

        // Variable for the user choice menu.
        int user_choice;

        do
        {
            user_choice = user_menu();  // print menu, validate choice is between 1 and 5

            // You will pass the address of this variable to your equation functions. 
            float result;               // Variable to hold calculated result

            // Handle menu choice selected by user
            switch( user_choice )
            {
                case 1:
					equation1(&result);
					break;
				case 2:
					equation2(&result);
					break;
				case 3:
					equation3(&result);
					break;
				case 4:
					equation4(&result);
					break;
                case 5:
                    // exit program if user selected QUIT
                    printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");
                    return 0;
                    break;
            }

            // Print out the calculated result with four digits after the decimal place
            printf("Your result is %.4f.\n\n", result);


        } while ( user_choice != 5 );

        return 0; // exit with no error
    } 

 int user_menu(void) {
	 int choice;
	 do {
	 printf("Choose a motion equation 1-4 or choose 5 to QUIT > ");
	 scanf("%d", &choice);
	 if(choice < 1 || choice > 5) { // Print error if input is invalid, otherwise return the input
		 printf("Invalid Option. Please try again.\n\n");
	 }
	 else {
		 return choice;
	 }
	 } while(choice > 5 || choice < 1); // Keep looping if error was thrown earlier
	 return choice;
 }
 
 /* Equations */
 void equation1(float *result) {
	 float v0 = get_velocity_initial();
	 float a = get_acceleration();
	 float t = get_time();
	 *result = v0 + (a * t); // edit the float at the location to the equation value
 }
 void equation2(float *result) {
	 float x0 = get_position_initial();
	 float v0 = get_velocity_initial();
	 float t = get_time();
	 float a = get_acceleration();
	 *result = x0 + (v0 * t) + (0.5 * a * pow(t, 2));
 }
 void equation3(float *result) {
	 float v0 = get_velocity_initial();
	 float a = get_acceleration();
	 float xf = get_position_final();
	 float x0 = get_position_initial();
	 *result = sqrt(pow(v0, 2) + 2 * a * (xf - x0));
 }
 void equation4(float *result) {
	 float x0 = get_position_initial();
	 float vf = get_velocity_final();
	 float v0 = get_velocity_initial();
	 float t = get_time();
	 *result = x0 + 0.5 * (vf + v0) * t;
 } 
 /* End Equations */
 
 /* Get Functions */
 float get_position_initial(void) {
	 float pos;
	 printf("\tEnter initial position > ");
	 scanf("%f", &pos);
	 return pos; // Return the initial position
 }
 float get_position_final(void) {
	 float pos;
	 printf("\tEnter final position > ");
	 scanf("%f", &pos);
	 return pos; // Return the final position
 }
 float get_velocity_initial(void) {
	 float vel;
	 printf("\tEnter initial velocity > ");
	 scanf("%f", &vel);
	 return vel; // return the initial velocity
 }
 float get_velocity_final(void) {
	 float vel;
	 printf("\tEnter final velocity > ");
	 scanf("%f", &vel);
	 return vel; // Return the final velocity
	 
 }
 float get_acceleration(void) {
	 float acc;
	 printf("\tEnter acceleration > ");
	 scanf("%f", &acc);
	 return acc; // Return the acceleration
 }
 float get_time(void) {
	 float time;
	 printf("\tEnter time > ");
	 scanf("%f", &time);
	 return time; // Return the time
 }
 
 /* End Get Functions */