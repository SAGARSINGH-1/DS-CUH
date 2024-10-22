#include <stdio.h>
#include <limits.h>

int maxOfArray(int row, int col, int arr[row][col]){
  int max =INT_MIN;
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        if(arr[i][j]<max){
            max=arr[i][j];
        }  
    }
  }
  return max;
}


int main(){
    
  int row,col;
  printf("Enter the number of rows & col: ");
  scanf("%d%d", &row,&col);
  int arr[row][col];
  
  for(int i=0;i<row;i++){ //i is for row
    for(int j=0;j<col;j++){
        scanf("%d",&arr[i][j]);
    }
  }
  
  int result = maxOfArray(row, col, arr);
  printf("The result is : %d",result);
  return 0;
}