#include<stdio.h>

struct Student{
    char name[100];
    int roll_number;
    float marks;
};
int main(){
    int n, i, max_index=0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n]; 
     for(i=0;i<n;i++){
         printf("\nEnter details of student %d\n", i + 1);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Roll Number: ");
        scanf("%d", &s[i].roll_number);

        printf("Marks: ");
        scanf("%f", &s[i].marks);

        if(s[i].marks>s[max_index].marks){
            max_index=i;
        }
     }

    printf("\n--- STUDENTS COMPARISON ---\n");
    printf("Highest Marks among them: %.2f\n", s[max_index].marks);

    return 0;
}