# include <stdio.h>
# include <malloc.h>

struct BTNode
{
    int num;
    char *name;
    struct BTNode * left; 
    struct BTNode * right;
};

struct BTNode * creatNode(int num,char *name)
{
    struct BTNode * temp = (struct BTNode *)malloc(sizeof(struct BTNode));;
    temp->num = num;
    temp->name = name;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct BTNode * CreateBTree(void)
{
    struct BTNode * root = creatNode(1,"宋江");
    struct BTNode * node2 = creatNode(2,"吴用");
    struct BTNode * node3 = creatNode(3,"卢俊义");
    struct BTNode * node4 = creatNode(4,"林冲");
    struct BTNode * node5 = creatNode(5,"关胜");

    root->left = node2;
    root->right = node3;
    node3->right = node4;
    node3->left = node5;
    

    return root;
}

void preOrder(struct BTNode *node)
{
    if(node)
    {
        printf("%d %s\n",node->num,node->name);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void infixOrder(struct BTNode *node)
{
    if(node)
    {
        
        preOrder(node->left);
        printf("%d %s\n",node->num,node->name);
        preOrder(node->right);
    }
}

void postOrder(struct BTNode *node)
{
    
    if(node)
    {
        
        preOrder(node->left);
        preOrder(node->right);
        printf("%d %s\n",node->num,node->name);
    }
    
}

struct BTNode * preOrderSerach (struct BTNode * node,int num)
{
    struct BTNode * resNode = NULL;
    if (node)
    {
        printf("进入前序遍历\n");
        if (node->num == num)
        {
            return node;
        }
        resNode = preOrderSerach(node->left,num);
        if (resNode !=NULL)
        {
            return resNode;
        }

        resNode = preOrderSerach(node->right,num);
        
    }

    return resNode;
}

struct BTNode * infixOrderSerach (struct BTNode * node,int num)
{
    
    
    struct BTNode * resNode = NULL;
    if (node)
    {
        
        resNode = preOrderSerach(node->left,num);
        if (resNode !=NULL)
        {
            return resNode;
        }

        printf("进入中序遍历\n");
        if (node->num == num)
        {
            return node;
        }

        resNode = preOrderSerach(node->right,num);
        
    }

    return resNode;
}

struct BTNode * postOrderSerach (struct BTNode * node,int num)
{
    
    
    struct BTNode * resNode = NULL;
    if (node)
    {
        
        resNode = postOrderSerach(node->left,num);
        if (resNode !=NULL)
        {
            return resNode;
        }

        resNode = postOrderSerach(node->right,num);
        if (resNode !=NULL)
        {
            return resNode;
        }
        printf("进入后序遍历\n");
        if (node->num == num)
        {
            return node;
        }
    }

    return resNode;
}



int main(void)
{
    struct BTNode * pT = CreateBTree();
    pT = postOrderSerach(pT,5);
    printf("%d %s ",pT->num,pT->name);

    getchar();
    return 0;
}