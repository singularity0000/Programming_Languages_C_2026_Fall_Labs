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

int save_student_binary(const Student *s, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) return -1;
    if (fwrite(s, sizeof(Student), 1, fp) != 1) {
        fclose(fp);
        return -1;
    }
    fclose(fp);
    return 0;
}

int load_student_binary(const char *filename, Student *s) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) return -1;
    if (fread(s, sizeof(Student), 1, fp) != 1) {
        fclose(fp);
        return -1;
    }
    fclose(fp);
    return 0;
}

long file_size(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) return -1;
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    return size;
}

int main() {
    Student original = {"Alice", 21, 3.75f};
    Student loaded;
    const char *bin_filename = "student.bin";
    const char *txt_filename = "student.txt";

    printf("Saving student in binary format...\n");
    save_student_binary(&original, bin_filename);

    printf("Loading student from binary file...\n");
    load_student_binary(bin_filename, &loaded);

    printf("Loaded student: %s, %d, GPA %.2f\n", loaded.name, loaded.age, loaded.gpa);

    FILE *fp = fopen(txt_filename, "w");
    if (fp != NULL) {
        fprintf(fp, "%s %d %.2f\n", original.name, original.age, original.gpa);
        fclose(fp);
    }

    printf("Text file size: %ld bytes\n", file_size(txt_filename));
    printf("Binary file size: %ld bytes\n", file_size(bin_filename));

    return 0;
}