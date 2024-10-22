#include <stdio.h>

void callByValueFun(int x, int y){
  int temp=x;
  x=y;
  y=temp;
}

void callByRefFun(int *x, int *y){
  int temp=*x;
  *x=*y;
  *y=temp;
}

int main(){
  int a=1,b=2;

  callByValueFun(a,b);

  printf("After the call by value funtion the value of a and b is : %d %d\n",a,b);
  
  callByRefFun(&a, &b);

  printf("After the call by reference funtion the value of a and b is : %d %d\n",a,b);

  return 0;
}


