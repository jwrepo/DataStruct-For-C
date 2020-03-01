#include <stdio.h>

void SelectSort(int *arr, int len)
{
    int min = 0;
    int minIndex = 0;
    for (int i = 0; i < len - 1; i++)
    {
        min = arr[i];
        minIndex = i;
        for (int j = 1 + i; j < len; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            arr[minIndex] = arr[i];
            arr[i] = min;
        }
    }
}

int main()
{
    int a[7] = {4, -2, 7, 3, 9, 32, 5};

    SelectSort(a, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", a[i]);
    }
    getchar();
}