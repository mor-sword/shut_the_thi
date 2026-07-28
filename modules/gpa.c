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
        totalPoints += getGradePoint(results[i].marks) * results[i].course->credit;
        totalCredits += results[i].course->credit;
    }

    if (totalCredits == 0.0)
        return 0.0;

    return totalPoints / totalCredits;
}