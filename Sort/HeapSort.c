#include <stdio.h>


void buildMaxHeap(int *arr,int len,int index)
{
    int left = index*2+1;
    int right = index*2+2;
    int maxIndex = index;
    int temp= 0;
    if(arr == NULL || len == 1) return;
    if(left < len && arr[left] > arr[index]){
        maxIndex = left;
    }
    if(right < len && arr[right] > arr[index]){
        maxIndex = right;
    }

    if(maxIndex != index){
        temp = arr[maxIndex];
        arr[maxIndex] = arr[index];
        arr[index] = temp;

        buildMaxHeap(arr,len,maxIndex);
    }
}


void heapSort(int *arr,int len)
{
    int temp;
    if(arr == NULL || len == 1) return;

    for(int i = len/2;i >= 0;i--)
    {
        buildMaxHeap(arr,len,i);
    }

    for(int i = len-1;i >=1;i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        buildMaxHeap(arr,i,0);
    }
    
    
}


int main()
{
    int a[7] = {4, -2, 7, 3, 9, 32, 5};

    heapSort(a, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", a[i]);
    }
    getchar();
    return 0;
}