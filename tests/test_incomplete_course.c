#include <stdio.h>
#include "courseResult.h"

int main(void)
{
    Course course = createCourse(
        "CSE 4204",
        "Discrete Mathematics Lab",
        1.5);

    CourseResult result = createIncompleteCourseResult(&course);

    if (result.course == &course && result.completed == 0)
    {
        printf("Incomplete course test passed\n");
        return 0;
    }

    printf("Incomplete course test failed\n");
    return 1;
}