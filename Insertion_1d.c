#include <stdio.h>


int insertElement(int arr[],int target,int pos){
            int a=4;
            while(a>pos){
                arr[a]=arr[a-1];
                a--;
            }
            arr[pos]=target;
    
        for(int i =0;i<4;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}

int main() {
    
    int arr[4]={1,2,4};
    
    int target,pos;
    printf("Enter the element to insert : ");
    scanf("%d",&target);
    
    printf("Enter the position to insert in : ");
    scanf("%d",&pos);
    
    // deletion from an array
    insertElement(arr,target,pos);
}