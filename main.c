#include <stdio.h>
#include "course.h"
#include "courseResult.h"

int main(void)
{
    Course courses[3];
    CourseResult results[3];

    courses[0] = createCourse(
        "CSE 4107",
        "Structured Programming I",
        3.0);

    courses[1] = createCourse(
        "CSE 4108",
        "Structured Programming I Lab",
        1.5);

    courses[2] = createCourse(
        "CSE 4203",
        "Discrete Mathematics",
        3.0);

    results[0] = createCourseResult(&courses[0], 85.5);
    results[1] = createCourseResult(&courses[1], 90.0);
    results[2] = createCourseResult(&courses[2], 78.5);

    for (int i = 0; i < 3; i++)
    {
        viewCourseResult(results[i]);
        printf("\n");
    }

    return 0;
}