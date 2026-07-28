#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

int main(void)
{
    Course courses[4];

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

    courses[3] = createCourse(
        "CSE 4204",
        "Discrete Mathematics Lab",
        1.5,
        2);

    CourseResult results[4];

    results[0] = createCourseResult(&courses[0], 85.5);
    results[1] = createCourseResult(&courses[1], 90.0);
    results[2] = createCourseResult(&courses[2], 78.5);
    results[3] = createIncompleteCourseResult(&courses[3]);

    viewSemesterResults(results, 4, 1);
    printf("\n");

    viewSemesterResults(results, 4, 2);
    printf("\n");

    printf("Overall CGPA: %.2f\n",
           calculateCGPA(results, 4));

    return 0;
}