#include <stdio.h>
void radixSort(int *arr, int len)
{
    int max = arr[0];
    for(int i = 1;i < len;i++)
    {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int maxLength;
     while(max!=0)
    {
     
        max/=10;
        maxLength++;
    }

    for (int m = 0, n = 1; m < maxLength; m++, n *= 10)
    {
        int bucket[10][len];
        int bucketElementCounts[10] = {0};
        int digitOfElement = 0;
        for (int i = 0; i < len; i++)
        {
            digitOfElement = arr[i] / n % 10;
            bucket[digitOfElement][bucketElementCounts[digitOfElement]] = arr[i];
            bucketElementCounts[digitOfElement]++;
        }

        int index = 0;

        for (int j = 0; j < 10; j++)
        {
            if (bucketElementCounts[j] != 0)
            {
                for (int k = 0; k < bucketElementCounts[j]; k++)
                {
                    arr[index++] = bucket[j][k];
                }
            }
        }
    }
}

int main()
{
    int a[7] = {4, 2, 7, 3, 9, 32, 5};

    radixSort(a, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", a[i]);
    }
    getchar();
    return 0;
}