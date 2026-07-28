#include <stdio.h>
#include <string.h>
#include "courseResult.h"

int testCourseResultCourse()
{
    Course course = createCourse(
        "CSE 4202",
        "Structured Programming II Lab",
        1.5);

    CourseResult result = createCourseResult(&course, 85.5);

    return result.course == &course;
}

int testCourseResultMarks()
{
    Course course = createCourse(
        "CSE 4202",
        "Structured Programming II Lab",
        1.5);

    CourseResult result = createCourseResult(&course, 85.5);

    return result.marks == 85.5;
}

int main()
{
    printf("Course result module tests\n");

    int passed = 0;
    int total = 0;

    total++;
    if (testCourseResultCourse())
        passed++;

    total++;
    if (testCourseResultMarks())
        passed++;

    printf("Passed %d/%d tests\n", passed, total);

    return passed == total ? 0 : 1;
}