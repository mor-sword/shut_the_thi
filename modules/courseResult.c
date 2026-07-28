#include <stdio.h>
#include "courseResult.h"

CourseResult createCourseResult(Course *course, double marks)
{
    CourseResult result;

    result.course = course;
    result.marks = marks;
    result.completed = 1;

    return result;
}

CourseResult createIncompleteCourseResult(Course *course)
{
    CourseResult result;

    result.course = course;
    result.marks = 0.0;
    result.completed = 0;

    return result;
}

void viewCourseResult(CourseResult result)
{
    printf("Course: %s\n", result.course->code);
    printf("Name: %s\n", result.course->name);

    if (result.completed)
        printf("Marks: %.2f\n", result.marks);
    else
        printf("Status: Incomplete\n");
}