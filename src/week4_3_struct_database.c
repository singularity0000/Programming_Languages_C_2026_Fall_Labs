/*
 * Name: Naim
 * Surname: Khuduzade
 * Student ID: 251ADB072
 */

#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int id;
    float grade;
};

int main() {
    int n;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // Dynamically allocate memory for an array of Student records
    struct Student *students = (struct Student*)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter data for student %d: ", i + 1);
        // %49s ensures the name does not overflow the 50-char array
        if (scanf("%49s %d %f", students[i].name, &students[i].id, &students[i].grade) != 3) {
            printf("Invalid input.\n");
            free(students);
            return 1;
        }
    }

    printf("\n"); // Required empty line
    printf("%-6s %-11s %s\n", "ID", "Name", "Grade");
    
    for (int i = 0; i < n; i++) {
        printf("%-6d %-11s %.1f\n", students[i].id, students[i].name, students[i].grade);
    }

    // Optional Bonus: Calculate and print the average grade
    float total_grade = 0;
    for (int i = 0; i < n; i++) {
        total_grade += students[i].grade;
    }
    printf("\nAverage grade = %.2f\n", total_grade / n);

    // Free the allocated memory before exiting
    free(students);
    return 0;
}