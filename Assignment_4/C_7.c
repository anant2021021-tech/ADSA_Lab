#include<stdio.h>

struct Student{
    char name[100];
    int run;
    int wickets;
};
int main(){
    int n=11, i, max_index=0;


    struct Student s[n]; 
     for(i=0;i<n;i++){
         printf("\nEnter details of player: %d\n", i + 1);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Runs: ");
        scanf("%d", &s[i].run);

        printf("Wickets: ");
        scanf("%d", &s[i].wickets);

        if(s[i].run>s[max_index].run){
            max_index=i;
        }
     }

     printf("\n--- Player with Highest Runs ---\n");
    printf("Name: %s\n", s[max_index].name);
    printf("Runs: %d\n", s[max_index].run);
    printf("Wickest: %d\n", s[max_index].wickets);

    return 0;
}