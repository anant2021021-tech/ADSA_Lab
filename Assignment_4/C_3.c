struct dob{
    int month;
    int date;
    int year;
};

struct student{
    int r_n;
    char name[80];
    struct dob db;
};

int main(){

    struct student s1;
    printf("Enter detials of student:\n Name:");
    scanf("%s",s1.name);
    printf("Roll Number:");
    scanf("%d",&s1.r_n);
    printf("Date of birth: Day Month Year\n");
    scanf("%d %d %d",&s1.db.date,&s1.db.month,&s1.db.year);

    printf("\n--- Student Details ---\n");
    printf("Name: %s\n", s1.name);
    printf("Roll Number: %d\n", s1.r_n);
    printf("DOB: %d/%d/%d",s1.db.date,s1.db.month,s1.db.year);
    return 0;
}