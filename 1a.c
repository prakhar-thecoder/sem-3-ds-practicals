#include <stdio.h>
#include <string.h>

struct student {
    int rollno;
    char name[100];
    int marks;
    char grade;
};

int main () {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student students[n];

    printf("Enter students data\n");
    for (int i = 0; i < n; i++) {
        struct student temp;
        temp.rollno = i + 1;
        printf("\nEnter the name of student %d: ", i+1);
        scanf("%s", &temp.name);
        printf("Enter the marks of student %d: ", i+1);
        scanf("%d", &temp.marks);
        printf("Enter the grade of student %d: ", i+1);
        fflush(stdin);
        scanf("%c", &temp.grade);

        students[i] = temp;
    }

    char name[100];
    printf("\nEnter the name of student to fetch marks: ");
    scanf("%s", &name);

    int found = 0;
    int marks;
    for (int i = 0; i < n; i++) {
        struct student temp = students[i];
        if (strcmp(temp.name, name) == 0) {
            found = 1;
            marks = temp.marks;
            break;
        }
    }

    if (found == 1) {
        printf("The marks of %s: %d", name, marks);
    } else {
        printf("Student not found in records");
    }

    return 0;
}
