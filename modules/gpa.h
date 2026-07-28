#ifndef GPA_H
#define GPA_H

#include "courseResult.h"

char getLetterGrade(double marks);
double getGradePoint(double marks);
double calculateCGPA(CourseResult results[], int count);

#endif