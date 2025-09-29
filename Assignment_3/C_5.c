#include<stdio.h>

struct Employee{
    char name[100];
    int emp_id;
    float salary;
    char dept[100];
};

int main(){
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    
    struct Employee emp[n];

     for (int i = 0; i < n; i++) {
        printf("\nEnter details of employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
        printf("Department: ");
        scanf("%s", emp[i].department);
    }

for (int i = 0; i < n; i++) {
        if (strcmp(emp[i].department, "IT") == 0) {
            emp[i].salary *= 1.10; // increase by 10%
        }
    }

printf("\nUpdated Employee Details:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f, Department: %s\n",
               emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }

    return 0;
}