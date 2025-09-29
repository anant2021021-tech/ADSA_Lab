#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    int n, i;
    float limit;

    printf("Enter number of books: ");
    scanf("%d", &n);

    struct Book b[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter details of book %d:\n", i + 1);
        printf("Title: ");
        scanf(" %[^\n]", b[i].title);  
        printf("Author: ");
        scanf(" %[^\n]", b[i].author);
        printf("Price: ");
        scanf("%f", &b[i].price);
    }

    printf("\nEnter price limit: ");
    scanf("%f", &limit);

    printf("\nBooks with price above %.2f:\n", limit);
    for (i = 0; i
