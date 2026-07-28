#include <stdio.h>
#include <string.h>
#include "course.h"

Course createCourse(
    const char code[],
    const char name[],
    double credit,
    int semester)
{
    Course course;

    strcpy(course.code, code);
    strcpy(course.name, name);
    course.credit = credit;
    course.semester = semester;

    return course;
}

void viewCourse(Course course)
{
    printf("%s - %s | Credit: %.1f | Semester: %d\n",
           course.code,
           course.name,
           course.credit,
           course.semester);
}