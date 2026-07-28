#include <stdio.h>
#include "gpa.h"

int main(void)
{
    Course courses[3];

    courses[0] = createCourse(
        "CSE 4107",
        "Structured Programming I",
        3.0,
        1);

    courses[1] = createCourse(
        "CSE 4108",
        "Structured Programming I Lab",
        1.5,
        1);

    courses[2] = createCourse(
        "CSE 4203",
        "Discrete Mathematics",
        3.0,
        2);

    CourseResult results[3];

    results[0] = createCourseResult(&courses[0], 85.0);
    results[1] = createCourseResult(&courses[1], 75.0);
    results[2] = createCourseResult(&courses[2], 90.0);

    double semesterOneGPA =
        calculateSemesterGPA(results, 3, 1);

    double semesterTwoGPA =
        calculateSemesterGPA(results, 3, 2);

    printf("Semester GPA tests\n");
    printf("Semester 1 GPA: %.2f\n", semesterOneGPA);
    printf("Semester 2 GPA: %.2f\n", semesterTwoGPA);

    if (semesterOneGPA == 3.9166666667 &&
        semesterTwoGPA == 4.0)
    {
        printf("Passed semester GPA tests\n");
        return 0;
    }

    printf("Semester GPA tests failed\n");
    return 1;
}