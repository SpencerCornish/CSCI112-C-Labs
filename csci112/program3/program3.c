/*
* Student Data Program
* Author: Spencer Cornish
* Date: 4/21/2017
*/

// Includes
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>     /* calloc, exit, free */
	
// Definitions
	#define NAME_SIZE 25 // Name Max Size Definition

typedef struct { // Stuct for student Data
	int sid; // Student ID
	char last[NAME_SIZE]; // Last name
	char first[NAME_SIZE]; // First name
	float *grade_list; // Pointer to list of grades
	float gpa; // Calculated student GPA
} student;

// Function Prototypes
student scan_student(int grades);
float calc_gpa(student stu, int grades);
void print_recs(student *stu, int num_students, int num_grades);
void free_mem(student *stu_point, int num_students);

int main(void) {
	int num_students, num_grades;	
	scanf("%d", &num_students); // Scan in the number of students and grades for each
	scanf("%d", &num_grades);
	printf("Number of Students: %d\n", num_students); // Print values back to the user
	printf("Number of Grades(Each): %d\n", num_grades);
	student *stud_arr; // Pointer to the student array
	stud_arr = (student *)calloc(num_students, sizeof(student)); // Clear memory for the student array
	for(int i = 0; i < num_students; i ++) {
		stud_arr[i] = scan_student(num_grades); // Scan in students to the array
	}
	print_recs(stud_arr, num_students, num_grades); // Print records
	free_mem(stud_arr, num_students); // Clear the memory
	
	
}
student scan_student(int grades) {
	student stu; // Temporary student we are scannin in
	stu.grade_list = (float *)calloc(grades, sizeof(float)); // Clear memory for the list of grades for the student
	scanf("%d", &stu.sid); // Scan in everything
	scanf("%s", stu.last);
	scanf("%s", stu.first);
	for(int i = 0; i < grades; i++) {
		scanf("%f", &stu.grade_list[i]); 
	}
	stu.gpa = calc_gpa(stu, grades); // call GPA helper function
	return stu; // Return the student
}
// Prints the records
void print_recs(student * stu_point, int num_students, int num_grades) {
	for(int i = 0; i < num_students; i++) { // Iterate through each student
		
		printf("ID: %d, Name: %s %s, GPA: %.2f\n", stu_point[i].sid, stu_point[i].first, stu_point[i].last, stu_point[i].gpa);
		printf("Grades: "); 
		// Print each grade
		for(int j = 0; j < num_grades; j++) {
			printf("%.1f", stu_point[i].grade_list[j]);
			if(j < num_grades-1) { // Only place commas if appropriate
				printf(",");
			}
			else {
				printf("\n"); // Newline at the end
			}
		}
	}
}
float calc_gpa(student stu, int grades) {
	float gpa;
	for(int i = 0; i < grades; i++){// Add all the grades
		gpa = gpa + stu.grade_list[i];
	}
	return gpa / grades; // Return sum of grades devided by number of grades
	
}

// Free up memory
void free_mem(student *stu_point, int num_students) {
	for(int i = 0; i < num_students; i++) {
		free(stu_point[i].grade_list); // Free the grade lists
		stu_point[i].grade_list = NULL;
	}
	free(stu_point); // Free the student pointer data
	stu_point = NULL;
}
