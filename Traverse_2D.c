#include <stdio.h>
#include <stdbool.h>

void Traverse(int mat[3][4], int row, int col) {
    int sum=0;
    for(int i =0;i<row;i++){
        for(int j=0;j<col;j++){
            sum+=mat[i][j];
        }
    }
    printf("Sum of all matrix element is : %d",sum);
}

int main() {
    int mat[3][4] = {
        {1, 0, 3, 4},
        {5, 0, 0, 0},
        {0, 10, 0, 0}
    };
    
    Traverse(mat, 3, 4);

    return 0;
}
