#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int rows;
    int cols;
    int **data;  // pointer to 2D array
};

int main() {
    struct Matrix mat;
    int i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &mat.rows, &mat.cols);


    mat.data = (int **)malloc(mat.rows * sizeof(int *));
    for (i = 0; i < mat.rows; i++) {
        mat.data[i] = (int *)malloc(mat.cols * sizeof(int));
    }
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < mat.rows; i++) {
        for (j = 0; j < mat.cols; j++) {
            scanf("%d", &mat.data[i][j]);
        }
    }

    printf("\nMatrix:\n");
    for (i = 0; i < mat.rows; i++) {
        for (j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i][j]);
        }
        printf("\n");
    }
    return 0;
}
