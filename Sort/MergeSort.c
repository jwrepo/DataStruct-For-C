#include <stdio.h>

void mergeArry(int *arr, int left, int mid, int right, int *temp)
{
    int i = left, j = mid + 1;
    int m = mid, n = right;
    int k = 0;

    while (i <= m && j <= n)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m)
    {
        temp[k++] = arr[i++];
    }
    while (j <= n)
    {
        temp[k++] = arr[j++];
    }

    for (int i = 0; i < k; i++)
    {
        arr[left + i] = temp[i];
    }
}
void mergeSort(int *arr, int left, int right, int *temp)
{
    int mid = 0;
    mid = (left + right) / 2;

    if (left < right)
    {
        mergeSort(arr, left, mid, temp);
        mergeSort(arr, mid + 1, right, temp);
        mergeArry(arr, left, mid, right, temp);
    }
}
int main()
{
    int a[10] = {4, -2, 7, 99, 9, 32, 5, 45, 24, 18};
    int temp[10] = {0};

    mergeSort(a, 0, 9, temp);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    getchar();
    return 0;
}