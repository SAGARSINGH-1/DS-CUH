#include <stdio.h>

void binarySearch(int mat[][4], int row, int col, int target) {
    int low = 0;
    int high = col - 1;
    
    while (low <= high) {
        int mid1D = (low + high) / 2;
        if (mat[row][mid1D] > target) {
            high = mid1D - 1;
        } else if (mat[row][mid1D] < target) {
            low = mid1D + 1;
        } else {
            printf("Element found at index: mat[%d][%d]\n", row, mid1D);
            return;
        }
    }
    printf("Element not found in this row.\n");
}


void matrix1DConvo(int mat[][4], int rows, int cols, int target) {
    int low = 0, high = rows - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (target >= mat[mid][0] && target <= mat[mid][cols - 1]) {

            binarySearch(mat, mid, cols, target);
            return;
        } else if (target < mat[mid][0]) {
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }
    
    printf("Element not found in the matrix.\n");
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
    
    matrix1DConvo(mat, 3, 4, target);

    return 0;
}
