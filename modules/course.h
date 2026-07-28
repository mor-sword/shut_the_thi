#ifndef COURSE_H
#define COURSE_H

typedef struct Course
{
    char code[20];
    char name[100];
    double credit;
    int semester;
} Course;

Course createCourse(
    const char code[],
    const char name[],
    double credit,
    int semester);

void viewCourse(Course course);

#endif