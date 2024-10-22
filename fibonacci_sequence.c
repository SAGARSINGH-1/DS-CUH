#include <stdio.h>

void fibona(int len)
{
    int num1 = 0;
    int num2 = 1;
    int sum;
    for (int i = 0; i <= len; i++)
    {
        if (i == 0)
        {
            printf("%d ", num1);
        }
        else if (i == 1)
        {
            printf("%d ", num2);
        }
        else
        {
            sum = num1 + num2;
            num1 = num2;
            num2 = sum;
            printf("%d ", sum);
        }
    }
}

int main()
{
    int len;
    printf("Enter the size where to find fibbonacci series: ");
    scanf("%d", &len);

    fibona(len);
}