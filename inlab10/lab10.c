/*
* Periodic Table Lab (lab 10)
* Author: Spencer Cornish
* Date: 4/27/2017
*/


// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definitions
#define ELEMENT_FILENAME "element_db.csv"

// Structure for elements
typedef struct {
    int atomic_number;
    char symbol[4];
    char name[25];
    float atomic_weight;
    char state[25];
    char bonding_type[25];
    char discovered[25];
} element_t;


// Function Prototypes
element_t * find_element( element_t * list, char * symbol );

int main( int argc, char * argv[] )
{
    if ( argc < 2 ) // If there are not enough arguments
    {
        printf("ERROR: Please provide at least one program argument.\n");
        return -1; // Exit on error
    }

    element_t * elements = (element_t *)calloc( 118 , sizeof( element_t ) ); // Allocate memory for the periodic table
    
    FILE * element_file = fopen( ELEMENT_FILENAME, "r" ); // Open the element file
    if ( element_file != NULL ) // If the CSV is not empty
    {
        char line[100];
        while( fgets(line, 100, element_file ) != NULL ) // Place the item in the table, and remove the comma, etc.
        {
            // remove newline character from line
            char * nl = strchr( line, '\n' );
            if ( nl )
            {
                *nl = '\0';
            }
			
            //printf("line = %s\n", line );
            element_t e; // Our new element
            char * str = strtok( line, "," );
            int col = 0; // What column we are working in
            while ( str != NULL ) // While there is still data in the column
            {
                switch( col )
                {
                    case 0:
                        e.atomic_number = atoi( str ); // Copy the Atomic Number
                        break;
                    case 1:
                        strcpy( e.symbol, str ); // Copy the Atomic Symbol
                        break;
					case 2: // Name
						strcpy( e.name, str );
						break;
					case 3: // Atomic Weight
						e.atomic_weight = atof( str );
						break;
					case 4: // State
						strcpy( e.state, str );
						break;
					case 5: // Bonding Type
						strcpy( e.bonding_type, str );
						break;
					case 6: // Discovery Year
						strcpy( e.discovered, str );
						break;
						
                }
                str = strtok( NULL, "," );
                col++;
            }
            elements[ e.atomic_number - 1 ] = e; // Insert the element into the array

            
            //printf(" %s\n", elements[ e.atomic_number - 1].symbol );
        }
        fclose( element_file ); // Close the file
    }

    // process program arguments.
    FILE * output_f = NULL; // Output File
    int i; // Iterator
    for( i = 1; i < argc; i++ )
    {
        if ( i == 1 ) // check for filename in the first arg
        {
            char * dot = strchr( argv[i], '.' ); // Scan for a dot (like .txt)
            if ( dot )
            {
                // this is a filename
				//DEBUG: printf("%s", argv[i]);
                output_f = fopen( argv[i], "w" ); // Open the output file
                continue;
            }
        }

        // Look up this element
        element_t * ele = find_element( elements, argv[i] ); // Lookup the current arg element
		if(output_f != NULL) { // If we should output to a file
			if ( ele )  // If the element exists
			{
				fprintf(output_f, "---------------\n");
				fprintf(output_f, "| %d \t %f\n", ele->atomic_number, ele->atomic_weight);
				fprintf(output_f, "| %s \t %s\n", ele->symbol, ele->name);
				fprintf(output_f, "| %s\n", ele->state);
				fprintf(output_f, "| %s\n", ele->bonding_type);
				fprintf(output_f, "| Found: %s\n", ele->discovered);
				fprintf(output_f, "---------------\n");
				
			}
			else { // Element doesn't exist
				fprintf(output_f, "WARNING: No such element: %s\n", argv[i]);
			}
		}
		else { // If we should print to stdout
			if ( ele )  // If element exists
			{
				printf("---------------\n");
				printf("| %d \t %f\n", ele->atomic_number, ele->atomic_weight);
				printf("| %s \t %s\n", ele->symbol, ele->name);
				printf("| %s\n", ele->state);
				printf("| %s\n", ele->bonding_type);
				printf("| Found: %s\n", ele->discovered);
				printf("---------------\n");
				
			}
			else { // Element doesn't exist
				printf("WARNING: No such element: %s\n", argv[i]);
			}
		}
    }
    return 0; // Program is done, exiting cleanly
}

element_t * find_element( element_t * list, char * symbol ) // Find the element in the array
{
    int i;
    for( i = 0; i < 118; i++ ) // Scan through all 118
    {
        if ( strcmp( list[i].symbol, symbol ) == 0 ) // If there are zero differences
        {
            element_t * result = &list[i];
            return result; /// Return a pointer to the result
        }
    }
    return NULL; // If there was not a match, return NULL
}
