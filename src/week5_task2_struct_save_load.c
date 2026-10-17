/*
 * Name: Naim
 * Surname: Khuduzade
 * Student ID: 251ADB072
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

int save_student(const Student *s, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) return -1;
    fprintf(fp, "%s %d %.2f\n", s->name, s->age, s->gpa);
    fclose(fp);
    return 0;
}

int load_student(const char *filename, Student *s) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) return -1;
    int fields_read = fscanf(fp, "%49s %d %f", s->name, &s->age, &s->gpa);
    fclose(fp);
    if (fields_read != 3) return -1;
    return 0;
}

int main() {
    Student original_student = {"Alice", 21, 3.75f};
    Student loaded_student;
    const char *filename = "student.txt";

    printf("Saving student to file...\n");
    if (save_student(&original_student, filename) != 0) {
        printf("Error saving student.\n");
        return 1;
    }

    printf("Loading student from file...\n");
    if (load_student(filename, &loaded_student) != 0) {
        printf("Error loading student.\n");
        return 1;
    }

    printf("Loaded student: %s, %d, GPA %.2f\n", loaded_student.name, loaded_student.age, loaded_student.gpa);
    return 0;
}