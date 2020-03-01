#include <stdio.h>
void QuickSort(int *arr,int l,int r)
{
    int i=l,j=r;
    int x=arr[i];
    if(i<j)
    {
        while(i<j)
        {
           while(i<j && arr[j]>=x)
           {
               j--;
           }
            if(i<j)
            {
                arr[i++] = arr[j];

            }
            while(i<j && arr[i]<=x)
            {
                i++;
            }
            if(i<j)
            {
                arr[j--] = arr[i];
            }
            
        }
        arr[i] = x;
        QuickSort(arr,l,i-1);
        QuickSort(arr,i+1,r);

    }
    
}

int main()
{
    int a[7] = {4, -2, 7, 3, 5, 32, 5};

    QuickSort(a,0,6);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", a[i]);
    }
    getchar();
    return 0;
}