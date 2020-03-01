#include <stdio.h>
#include <stdlib.h>

typedef struct HuffmanTree
{
    int num;
    struct HuffmanTree *left;
    struct HuffmanTree *right;
} HuffmanTree;

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
        printf("%d\n", node->num);
        preOrder(node->left);
        preOrder(node->right);
    }
}

HuffmanTree *creatNode(int num)
{
    HuffmanTree *temp = (HuffmanTree *)malloc(sizeof(HuffmanTree));
    temp->num = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

HuffmanTree *createHuffmanTree(int *arr, int len)
{
    HuffmanTree **t, *node;
    int l, r;
    
    t = (HuffmanTree**)malloc(len * sizeof(HuffmanTree));

    for (int i = 0; i < len; i++)
    {
        t[i] = creatNode(arr[i]);
    }

    InsertSort(t, 0, len);

    for (int i = 1; i < len; i++)
    {
        l = t[i - 1]->num;
        r = t[i]->num;
        node = creatNode(l + r);
        node->left = t[i - 1];
        node->right = t[i];
        t[i] = node;
        InsertSort(t, i, len);
    }

    return t[len - 1];
}

int main()
{
    int a[7] = {13, 7, 8, 3, 29, 6, 1};
    HuffmanTree *res;

    res = createHuffmanTree(a, 7);
    preOrder(res);
    getchar();
    return 0;
}