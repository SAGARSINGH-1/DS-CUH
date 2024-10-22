#include <stdio.h>
#include <stdbool.h>

void LinearSearch(int mat[3][4], int row, int col, int target) {
    bool found=false; 
    for(int i =0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]==target){
                printf("Element found in the index: arr[%d][%d]",row,col);
                found=true;
                break;
            }
        }
    }
    if(!found){
        printf("Element not found.");
    }
}

int main() {
    int mat[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target); 
    
    LinearSearch(mat, 3, 4, target);

    return 0;
}
