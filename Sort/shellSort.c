#include <stdio.h>

void InsertSort(int *arr,int len)
{   
    int temp;
    int j;
    for (int gap = len/2;gap>0;gap/=2)
    {
        for (int i = gap; i < len; i++)
        {
            
            for (j = i - gap; j >= 0; j-=gap)
            {
                if (arr[j+gap] < arr[j])
                {
                    temp = arr[j];
                    arr[j] = arr[j+gap];
                    arr[j + gap] = temp;
                }
               
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