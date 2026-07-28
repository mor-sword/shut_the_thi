#include <stdio.h>
#include "gpa.h"

char getLetterGrade(double marks)
{
    if (marks >= 80)
        return 'A';
    if (marks >= 75)
        return 'B';
    if (marks >= 70)
        return 'C';
    if (marks >= 65)
        return 'D';
    if (marks >= 60)
        return 'E';
    return 'F';
}

double getGradePoint(double marks)
{
    if (marks >= 80)
        return 4.00;
    if (marks >= 75)
        return 3.75;
    if (marks >= 70)
        return 3.50;
    if (marks >= 65)
        return 3.25;
    if (marks >= 60)
        return 3.00;
    return 0.00;
}

double calculateCGPA(CourseResult results[], int count)
{
    double totalPoints = 0.0;
    double totalCredits = 0.0;

    for (int i = 0; i < count; i++)
    {
        if (!results[i].completed)
            continue;

        totalPoints += getGradePoint(results[i].marks) * results[i].course->credit;

        totalCredits += results[i].course->credit;
    }

    if (totalCredits == 0.0)
        return 0.0;

    return totalPoints / totalCredits;
}

double calculateSemesterGPA(
    CourseResult results[],
    int count,
    int semester)
{
    double totalPoints = 0.0;
    double totalCredits = 0.0;

    for (int i = 0; i < count; i++)
    {
        if (!results[i].completed)
            continue;

        if (results[i].course->semester != semester)
            continue;

        totalPoints += getGradePoint(results[i].marks) * results[i].course->credit;

        totalCredits += results[i].course->credit;
    }

    if (totalCredits == 0.0)
        return 0.0;

    return totalPoints / totalCredits;
}

void viewSemesterResults(
    CourseResult results[],
    int count,
    int semester)
{
    printf("Semester %d Results\n", semester);

    for (int i = 0; i < count; i++)
    {
        if (!results[i].completed)
            continue;

        if (results[i].course->semester != semester)
            continue;

        printf("Course: %s\n", results[i].course->code);
        printf("Name: %s\n", results[i].course->name);
        printf("Marks: %.2f\n", results[i].marks);
        printf("Grade: %c\n", getLetterGrade(results[i].marks));
        printf("Grade Point: %.2f\n\n",
               getGradePoint(results[i].marks));
    }

    printf("Semester GPA: %.2f\n",
           calculateSemesterGPA(results, count, semester));
}