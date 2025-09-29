struct Student {
    char name[20];
    int roll;
    float marks;
};
int main(){
     int n=3;
    struct Student *ar;
    ar = (struct Student*) malloc(5 * sizeof(struct Student));
    struct Student *arr;
    arr = (struct Student*) calloc(5, sizeof(struct Student));

    printf("After malloc()\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d -> roll: %d, marks: %.2f, name: \"%s\"\n",
               i, ar[i].roll, ar[i].marks, ar[i].name);
    }

     printf("\nAfter calloc()\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d -> roll: %d, marks: %.2f, name: \"%s\"\n",
               i, arr[i].roll, arr[i].marks, arr[i].name);
    }


    return 0;
}