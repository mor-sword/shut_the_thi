double calculateSemesterGPA(
    CourseResult results[],
    int count,
    int semester)
{
    double totalPoints = 0.0;
    double totalCredits = 0.0;

    for (int i = 0; i < count; i++)
    {
        if (!results[i].completed)
            continue;

        if (results[i].course->semester != semester)
            continue;

        totalPoints += getGradePoint(results[i].marks) * results[i].course->credit;

        totalCredits += results[i].course->credit;
    }

    if (totalCredits == 0.0)
        return 0.0;

    return totalPoints / totalCredits;
}

void viewSemesterResults(
    CourseResult results[],
    int count,
    int semester)
{
    printf("Semester %d Results\n", semester);

    for (int i = 0; i < count; i++)
    {
        if (!results[i].completed)
            continue;

        if (results[i].course->semester != semester)
            continue;

        printf("Course: %s\n", results[i].course->code);
        printf("Name: %s\n", results[i].course->name);
        printf("Marks: %.2f\n", results[i].marks);
        printf("Grade: %c\n", getLetterGrade(results[i].marks));
        printf("Grade Point: %.2f\n\n",
               getGradePoint(results[i].marks));
    }

    printf("Semester GPA: %.2f\n",
           calculateSemesterGPA(results, count, semester));
}