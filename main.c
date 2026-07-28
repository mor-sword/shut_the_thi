#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

int main(void)
{
    Course courses[4];

    courses[0] = createCourse("CSE 4107", "Structured Programming I", 3.0);
    courses[1] = createCourse("CSE 4108", "Structured Programming I Lab", 1.5);
    courses[2] = createCourse("CSE 4203", "Discrete Mathematics", 3.0);
    courses[3] = createCourse("CSE 4204", "Discrete Mathematics Lab", 1.5);

    CourseResult results[4];

    results[0] = createCourseResult(&courses[0], 85.5);
    results[1] = createCourseResult(&courses[1], 90.0);
    results[2] = createCourseResult(&courses[2], 78.5);
    results[3] = createIncompleteCourseResult(&courses[3]);

    for (int i = 0; i < 4; i++)
    {
        viewCourseResult(results[i]);

        if (results[i].completed)
        {
            printf("Grade: %c\n", getLetterGrade(results[i].marks));
            printf("Grade Point: %.2f\n", getGradePoint(results[i].marks));
        }

        printf("\n");
    }

    printf("CGPA: %.2f\n", calculateCGPA(results, 4));

    return 0;
}