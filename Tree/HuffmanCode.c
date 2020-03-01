#include <stdio.h>
#include <stdlib.h>

typedef struct HuffmanTree
{
    char ch;
    int num;
    struct HuffmanTree *left;
    struct HuffmanTree *right;
} HuffmanTree;

typedef struct String
{
   char ch;
   int num;
   struct String *next;
}String;

void QuickSort(HuffmanTree **arr,int l,int r)
{
    int i=l,j=r;
    HuffmanTree *x=arr[i];
    if(i<j)
    {
        while(i<j)
        {
           while(i<j && (arr[j]->num)>=x->num)
           {
               j--;
           }
            if(i<j)
            {
                arr[i++]= arr[j];

            }
            while(i<j && (arr[i]->num)<=x->num)
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

int binarySearch(int* arr, int left, int right, int findVal) {
		

		// 当 left > right 时，说明递归整个数组，但是没有找到
		if (left > right) {
			return -1;
		}
		int mid = (left + right) / 2;
		int midVal = arr[mid];

		if (findVal > midVal) { // 向 右递归
			return binarySearch(arr, mid + 1, right, findVal);
		} else if (findVal < midVal) { // 向左递归
			return binarySearch(arr, left, mid - 1, findVal);
		} else {
			
			return mid;
		}

	}

void BubbleSort(HuffmanTree **arr, int n,int len)
{
    HuffmanTree *temp;
    int flag = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j]->num > arr[j + 1]->num)
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

void InsertSort(HuffmanTree **arr, int n, int len)
{
    HuffmanTree *temp;
    int j;
    if (n == (len - 1))
        return;

    for (int i = n; i < len; i++)
    {

        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j + 1]->num < arr[j]->num)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void preOrder(HuffmanTree *node)
{
    if (node)
    {
        printf("%c %d %d\n", node->ch,node->ch,node->num);
        preOrder(node->left);
        preOrder(node->right);
    }
}

HuffmanTree *creatNode(char ch,int num)
{
    HuffmanTree *temp = (HuffmanTree *)malloc(sizeof(HuffmanTree));
    temp->ch =ch;
    temp->num = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

HuffmanTree *createHuffmanTree(String *h, int len)
{
    HuffmanTree **t, *node;
    int l, r;
    
    t = (HuffmanTree**)malloc(len * sizeof(HuffmanTree));

    for (int i = 0; i < len; i++)
    {
        t[i] = creatNode((h->ch),(h->num));
        h=h->next;
    }

    QuickSort(t, 0, len-1);

    for(int i = 0;i < len;i++)
    {
        printf("%c %d %d\n",t[i]->ch,t[i]->ch,t[i]->num);
    }
    

    for (int i = 1; i < len; i++)
    {
        l = t[i - 1]->num;
        r = t[i]->num;
        node = creatNode('\0',l + r);
        node->left = t[i - 1];
        node->right = t[i];
        t[i] = node;
        QuickSort(t, i, len-1);
    }

    return t[len - 1];
}

String * creatString(char ch,int num)
{
    String *temp = (String *)malloc(sizeof(String));
    temp->ch=ch;
    temp->num=num;
    temp->next=NULL;
    return temp;
}
int serach(String *h,char ch)
{
    while(h!=NULL){
            if(h->ch == ch){
                
                return ++(h->num);
            }
            h=h->next;
        }
        return -1;
}
void HuffManCoding(HuffmanTree *node,int len)
{
    static int arr[10] = {0};

    if(node){
        
        if(node->left ==NULL && node->right == NULL && node->ch !='\0'){
            for(int i = 0;i < len;i++)
            {
                printf("%d",arr[i]);
            }
            printf("   %c",node->ch);
            printf("\n");
        }else
        {
            arr[len] = 0;
            HuffManCoding(node->left,len+1);
            arr[len] = 1;
            HuffManCoding(node->right,len+1);
        }
        
        
        
    }
}

String * huffmanCode(char *arr,int len)
{
    String *h,*t;
    int chLen=0;
    HuffmanTree *res;


    h=creatString(arr[0],1);
    t=h;
    for(int i = 1;i < len;i++)
    {
        if(serach(h,arr[i]) >= 1){

        }else{
            t->next=creatString(arr[i],1);
            t=t->next;
        }
    }
    t=h;
    while(t!=NULL){
            printf("%c %d  %d\n",t->ch,t->ch,t->num);
            chLen++;
            t=t->next;
        }
        printf("总数 %d\n\n",chLen);

    
    res = createHuffmanTree(h, chLen);
    //preOrder(res);
    printf("\n");
    HuffManCoding(res,0);

    
}


int main()
{
    int a[7] = {13, 7, 8, 3, 29, 6, 1};
    char *s = "i like like like java do you like a java";

    
    huffmanCode(s,40);
    
    
    getchar();
    return 0;
}