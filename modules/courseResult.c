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