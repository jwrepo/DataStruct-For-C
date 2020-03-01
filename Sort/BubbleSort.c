#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *arr, int len)
{
    int temp;
    int flag = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (flag)
        {
            flag = 0;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int a[7] = {4, -2, 7, 3, 9, 32, 5};

    BubbleSort(a, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", a[i]);
    }

    getchar();
}