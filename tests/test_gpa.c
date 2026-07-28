#include <stdio.h>
#include "gpa.h"

int main(void)
{
    int passed = 0;
    int total = 0;

    total++;
    if (getLetterGrade(85.0) == 'A')
        passed++;

    total++;
    if (getLetterGrade(72.0) == 'C')
        passed++;

    total++;
    if (getGradePoint(85.0) == 4.00)
        passed++;

    Course courses[2];

    courses[0] = createCourse("CSE 4107", "Programming", 3.0);
    courses[1] = createCourse("CSE 4108", "Programming Lab", 1.5);

    CourseResult results[2];

    results[0] = createCourseResult(&courses[0], 85.0);
    results[1] = createCourseResult(&courses[1], 75.0);

    total++;
    if (calculateCGPA(results, 2) == 3.9166666667)
        passed++;

    printf("GPA module tests\n");
    printf("Passed %d/%d tests\n", passed, total);

    return passed == total ? 0 : 1;
}