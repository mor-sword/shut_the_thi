#ifndef GPA_H
#define GPA_H

#include "courseResult.h"

char getLetterGrade(double marks);
double getGradePoint(double marks);

double calculateCGPA(CourseResult results[], int count);
double calculateSemesterGPA(CourseResult results[], int count, int semester);

void viewSemesterResults(
    CourseResult results[],
    int count,
    int semester);

#endif