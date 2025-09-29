#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    int n, m, i;
    struct Student *students;

    printf("Enter initial number of students: ");
    scanf("%d", &n);
    students = (struct Student*) malloc(n * sizeof(struct Student));
    printf("\nEnter details of %d students:\n", n);
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll: ");
        scanf("%d", &students[i].roll);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
    printf("\nEnter number of additional students: ");
    scanf("%d", &m);
    students = (struct Student*) realloc(students, (n + m) * sizeof(struct Student));
    printf("\nEnter details of %d new students:\n", m);
    for (i = n; i < n + m; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll: ");
        scanf("%d", &students[i].roll);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
    printf("\nAll Student Details:\n");
    for (i = 0; i < n + m; i++) {
        printf("Student %d -> Name: %s, Roll: %d, Marks: %.2f\n",
               i + 1, students[i].name, students[i].roll, students[i].marks);
    }
    return 0;
}
