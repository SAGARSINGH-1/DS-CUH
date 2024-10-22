#include <stdio.h>


int delElement(int arr[],int *size,int target){
    for(int k=0;k<*size;k++){
        if(target==arr[k]){
            int a=k;
            while(a<*size-1){
                arr[a]=arr[a+1];
                a++;
            }
            *(size)--;
        }
    }
    
        for(int i =0;i<*size;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}

int main() {
    
    int size;
    printf("Enter the size of an array..: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the array elements..: ");
    for(int i =0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    
    int target;
    printf("Enter the element to delete : ");
    scanf("%d",&target);
    
    // deletion from an array
    delElement(arr,&size,target);
}