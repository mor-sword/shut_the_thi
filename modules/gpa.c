for (int i = 0; i < count; i++)
{
    if (!results[i].completed)
        continue;

    totalPoints += getGradePoint(results[i].marks) * results[i].course->credit;

    totalCredits += results[i].course->credit;
}