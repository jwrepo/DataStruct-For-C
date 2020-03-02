#include <stdio.h>
#include <stdlib.h>
typedef struct BTNode
{
    int num;
    struct BTNode *left;
    struct BTNode *right;
}BTNode;

BTNode * creatNode(int num)
{
    BTNode * temp = (BTNode *)malloc(sizeof(BTNode));;
    temp->num = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void infixOrder(struct BTNode *node)
{
    if(node)
    {
        
        infixOrder(node->left);
        printf("%d\n",node->num);
        infixOrder(node->right);
    }
}

int Height(BTNode *node)
{
    int max,l,r;
    static int len;
    if(node){
        l=Height(node->left);
        r=Height(node->right);
        max = l > r ? l:r;
        return max +1;
    }
    return 0;
}

BTNode * leftRotate (BTNode *node)
{
    BTNode *temp;
    temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
}


BTNode * rightRotate (BTNode *node)
{
    BTNode *temp;
    temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
}
BTNode * doubleRotate (BTNode *node)
{

    if(Height(node->left)-Height(node->right)>1){
            if (node->left != NULL && (Height(node->left->right) > Height(node->left->left)))
            {
                node->left = leftRotate(node->left);
                node = rightRotate(node);
            }
            else
            {
                node = rightRotate(node);
            }
    }

    if(Height(node->right)-Height(node->left)>1){
            if (node->right != NULL && (Height(node->right->left) > Height(node->right->right)))
            {
                node->left = rightRotate(node->left);
                node = leftRotate(node);
            }
            else
            {
                node = leftRotate(node);
            }
    }

    return node;
}

BTNode * BinarySortTree (BTNode *node,int num)
{
    if(node)
    {
        if(num < node->num){
            if(node->left == NULL){
                node->left = creatNode(num);
            }else
            {
                BinarySortTree(node->left,num);
            }
            
        }else
        {
            if(node->right == NULL){
                node->right = creatNode(num);
            }else
            {
                BinarySortTree(node->right,num);
            }
        }
    }
}


int main()
{
    //int a[6]={4,3,6,5,7,8};  //左旋测试
    //int a[6]={10,12,8,9,7,6};   //右旋测试
    int a[6] = {10,11,7,6,8,9};  //双旋测试
    int l,r;
    BTNode *root  = creatNode(a[0]),*node;

     for(int i = 1;i < 6 ;i++)
     {
         BinarySortTree(root,a[i]);
     }

    infixOrder(root);

    root = doubleRotate(root);
    l=Height(root->left);
    r=Height(root->right);

    printf("%d %d",l,r);
     //infixOrder(root);
    getchar();
    return 0;
}