#include <stdio.h>

void InsertSort(int *arr,int len)
{   
    int temp;
    int j;
    for (int i = 1; i < len; i++)
    {
        
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j+1] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = temp;
            }
            
        }
    
    }
}

int main()
{
    
    int a[10] = {4,-2,7,99,9,32,5,45,24,18};

    InsertSort(a,10);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    getchar();
    return 0;
}