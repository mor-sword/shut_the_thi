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
double calculateRequiredGPA(
    double current_cgpa,
    double completed_credits,
    double target_cgpa,
    double remaining_credits);

#endif