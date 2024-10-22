#include <stdio.h>


int findStrLength(string str){
  int length=0;
  while(str[length]!="/0"){
    length++;
  }
  return length;
}

int main(){
  String str= "ramu the don";

  int result = findStrLength(str);
  printf("The length of the string is : %d",result);
}