#ifndef _STUDENT_H_
#define _STUDENT_H_

typedef struct {
    int id;
    char *lastName;
    char *firstName;
    char *promotion;
    double marks[20];
    double average;
    int markCount;
}Student;

void addStudent(Student**, int, int);
void printStudents(Student**, int);
void deleteStudent(Student**, int, int);
void addMark(Student **, int);
void detailsStudent(Student **, int, int);
void updateStudent(Student **, int, int);
#endif
