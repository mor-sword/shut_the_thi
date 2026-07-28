#include <stdio.h>
#include "courseResult.h"

CourseResult createCourseResult(Course *course, double marks)
{
    CourseResult result;

    result.course = course;
    result.marks = marks;

    return result;
}

void viewCourseResult(CourseResult result)
{
    printf("Course: %s\n", result.course->code);
    printf("Name: %s\n", result.course->name);
    printf("Marks: %.2f\n", result.marks);
}