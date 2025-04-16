#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char firstName[20];
    char lastName[20];
    char gender;
    float midterm1;
    float midterm2;
    float finalExam;
} Student;

void calculate_average(Student* ptr, int i) {
    float average = 0.3f * (ptr->midterm1) + 0.3f * (ptr->midterm2) + 0.4f * (ptr->finalExam);
    printf("\nStudent %d\nName: %s\nSurname: %s\nGender: %c\nMidterm 1: %.2f\nMidterm 2: %.2f\nFinal Exam: %.2f\nAverage: %.2f\n\n",
        i + 1, ptr->firstName, ptr->lastName, ptr->gender, ptr->midterm1, ptr->midterm2, ptr->finalExam, average);
}

void get_student_info(Student* ptr, int i) {
    printf("Enter first name of student %d: ", i + 1);
    scanf_s("%s", ptr->firstName, 20);

    printf("Enter last name of student %d: ", i + 1);
    scanf_s("%s", ptr->lastName, 20);

    printf("Enter gender of student %d (M for male, F for female): ", i + 1);
    scanf_s(" %c", &ptr->gender, 1);

    printf("Enter midterm 1 score of student %d: ", i + 1);
    scanf_s("%f", &ptr->midterm1);

    printf("Enter midterm 2 score of student %d: ", i + 1);
    scanf_s("%f", &ptr->midterm2);

    printf("Enter final exam score of student %d: ", i + 1);
    scanf_s("%f", &ptr->finalExam);
}

int main() {
    int count;
    printf("How many students will be registered? ");
    scanf_s("%d", &count);

    Student* students = (Student*)calloc(count, sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        get_student_info(students + i, i);
    }

    for (int j = 0; j < count; j++) {
        calculate_average(students + j, j);
    }

    free(students);
    return 0;
}