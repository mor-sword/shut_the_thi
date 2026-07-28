#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

#define MAX_COURSES 1000
#define MAX_RESULTS 1000

void showMenu(void)
{
    printf("\n1. Add Course\n");
    printf("2. Edit Course\n");
    printf("3. Delete Course\n");
    printf("4. View Courses\n");
    printf("5. Add Course Result\n");
    printf("6. Edit Course Result\n");
    printf("7. Delete Course Result\n");
    printf("8. View Marksheet\n");
    printf("9. Exit\n");
    printf("Enter Choice: ");
}

void addCourse(Course courses[], int *n_courses)
{
    if (*n_courses >= MAX_COURSES)
    {
        printf("Course limit reached.\n");
        return;
    }

    char code[20];
    char name[100];
    double credit;
    int semester;

    printf("Course Code: ");
    scanf("%19s", code);

    printf("Course Name: ");
    scanf(" %99[^\n]", name);

    printf("Credit: ");
    scanf("%lf", &credit);

    printf("Semester: ");
    scanf("%d", &semester);

    courses[*n_courses] =
        createCourse(code, name, credit, semester);

    (*n_courses)++;
    printf("Course added successfully.\n");
}

void viewCourses(Course courses[], int n_courses)
{
    if (n_courses == 0)
    {
        printf("No courses available.\n");
        return;
    }

    printf("\nCourse List\n");

    for (int i = 0; i < n_courses; i++)
    {
        printf("%d. ", i + 1);
        viewCourse(courses[i]);
    }
}

void editCourse(Course courses[], int n_courses)
{
    int course_no;

    viewCourses(courses, n_courses);

    if (n_courses == 0)
        return;

    printf("Course Number: ");
    scanf("%d", &course_no);

    if (course_no < 1 || course_no > n_courses)
    {
        printf("Invalid course number.\n");
        return;
    }

    char code[20];
    char name[100];
    double credit;
    int semester;

    printf("New Course Code: ");
    scanf("%19s", code);

    printf("New Course Name: ");
    scanf(" %99[^\n]", name);

    printf("New Credit: ");
    scanf("%lf", &credit);

    printf("New Semester: ");
    scanf("%d", &semester);

    courses[course_no - 1] =
        createCourse(code, name, credit, semester);

    printf("Course updated successfully.\n");
}

void deleteCourse(
    Course courses[],
    int *n_courses,
    CourseResult results[],
    int *n_results)
{
    int course_no;

    viewCourses(courses, *n_courses);

    if (*n_courses == 0)
        return;

    printf("Course Number: ");
    scanf("%d", &course_no);

    if (course_no < 1 || course_no > *n_courses)
    {
        printf("Invalid course number.\n");
        return;
    }

    Course *deleted_course = &courses[course_no - 1];
    int kept_results = 0;

    for (int i = 0; i < *n_results; i++)
    {
        if (results[i].course == deleted_course)
            continue;

        if (results[i].course > deleted_course)
            results[i].course--;

        results[kept_results] = results[i];
        kept_results++;
    }

    *n_results = kept_results;

    for (int i = course_no - 1; i < *n_courses - 1; i++)
    {
        courses[i] = courses[i + 1];
    }

    (*n_courses)--;

    printf("Course and linked result deleted successfully.\n");
}

void addCourseResult(
    Course courses[],
    int n_courses,
    CourseResult results[],
    int *n_results)
{
    if (n_courses == 0)
    {
        printf("Add a course first.\n");
        return;
    }

    if (*n_results >= MAX_RESULTS)
    {
        printf("Result limit reached.\n");
        return;
    }

    int course_no;
    int completed;
    double marks;

    viewCourses(courses, n_courses);

    printf("Course Number: ");
    scanf("%d", &course_no);

    if (course_no < 1 || course_no > n_courses)
    {
        printf("Invalid course number.\n");
        return;
    }

    Course *course = &courses[course_no - 1];

    printf("%s: %s Completed?\n",
           course->code,
           course->name);

    printf("1. YES\n");
    printf("2. NO\n");
    printf("Enter Choice: ");
    scanf("%d", &completed);

    if (completed == 1)
    {
        printf("Marks for %s: ", course->name);
        scanf("%lf", &marks);

        results[*n_results] =
            createCourseResult(course, marks);
    }
    else
    {
        results[*n_results] =
            createIncompleteCourseResult(course);
    }

    (*n_results)++;
    printf("Course result added successfully.\n");
}

void editCourseResult(
    CourseResult results[],
    int n_results)
{
    if (n_results == 0)
    {
        printf("No course results available.\n");
        return;
    }

    int result_no;
    int completed;
    double marks;

    printf("\nCourse Results\n");

    for (int i = 0; i < n_results; i++)
    {
        printf("%d. ", i + 1);
        viewCourseResult(results[i]);
    }

    printf("Course Result Number: ");
    scanf("%d", &result_no);

    if (result_no < 1 || result_no > n_results)
    {
        printf("Invalid result number.\n");
        return;
    }

    Course *course = results[result_no - 1].course;

    printf("%s: %s Completed?\n",
           course->code,
           course->name);

    printf("1. YES\n");
    printf("2. NO\n");
    printf("Enter Choice: ");
    scanf("%d", &completed);

    if (completed == 1)
    {
        printf("Marks for %s: ", course->name);
        scanf("%lf", &marks);

        results[result_no - 1] =
            createCourseResult(course, marks);
    }
    else
    {
        results[result_no - 1] =
            createIncompleteCourseResult(course);
    }

    printf("Course result updated successfully.\n");
}

void deleteCourseResult(
    CourseResult results[],
    int *n_results)
{
    if (*n_results == 0)
    {
        printf("No course results available.\n");
        return;
    }

    int result_no;

    printf("\nCourse Results\n");

    for (int i = 0; i < *n_results; i++)
    {
        printf("%d. ", i + 1);
        viewCourseResult(results[i]);
    }

    printf("Course Result Number: ");
    scanf("%d", &result_no);

    if (result_no < 1 || result_no > *n_results)
    {
        printf("Invalid result number.\n");
        return;
    }

    for (int i = result_no - 1; i < *n_results - 1; i++)
    {
        results[i] = results[i + 1];
    }

    (*n_results)--;

    printf("Course result deleted successfully.\n");
}

void viewMarksheet(
    CourseResult results[],
    int n_results)
{
    if (n_results == 0)
    {
        printf("No course results available.\n");
        return;
    }

    printf("\nMarksheet\n");

    for (int i = 0; i < n_results; i++)
    {
        printf("%d. ", i + 1);
        viewCourseResult(results[i]);
    }

    printf("\n");

    for (int semester = 1; semester <= 8; semester++)
    {
        int found = 0;

        for (int i = 0; i < n_results; i++)
        {
            if (results[i].course->semester == semester)
            {
                found = 1;
                break;
            }
        }

        if (found)
        {
            viewSemesterResults(
                results,
                n_results,
                semester);

            printf("\n");
        }
    }

    printf("Overall CGPA: %.2f\n",
           calculateCGPA(results, n_results));
}

int main(void)
{
    Course courses[MAX_COURSES];
    CourseResult results[MAX_RESULTS];

    int n_courses = 0;
    int n_results = 0;
    int choice = 0;

    while (choice != 9)
    {
        showMenu();
        scanf("%d", &choice);

        if (choice == 1)
        {
            addCourse(courses, &n_courses);
        }
        else if (choice == 2)
        {
            editCourse(courses, n_courses);
        }
        else if (choice == 3)
        {
            deleteCourse(
                courses,
                &n_courses,
                results,
                &n_results);
        }
        else if (choice == 4)
        {
            viewCourses(courses, n_courses);
        }
        else if (choice == 5)
        {
            addCourseResult(
                courses,
                n_courses,
                results,
                &n_results);
        }
        else if (choice == 6)
        {
            editCourseResult(results, n_results);
        }
        else if (choice == 7)
        {
            deleteCourseResult(results, &n_results);
        }
        else if (choice == 8)
        {
            viewMarksheet(results, n_results);
        }
        else if (choice != 9)
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}