#include<stdio.h>
#include<stdlib.h>
typedef struct Treenode
{
    int data;
    struct Treenode*left;
    struct Treenode*right;
}Treenode;
//Create Function
Treenode* create()
{
    int x;
    Treenode*newnode=(Treenode*)malloc(sizeof(Treenode));
    printf("\nEnter value for newnode:");
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    newnode->data=x;
    printf("\nEnter left child of %d",x);
    newnode->left=create();
    printf("\nEnter right child of %d",x);
    newnode->right=create();
    return newnode;
}
//Count total nodes in binary tree
int count(Treenode*root)
{
    if(!root)
    {
        return 0;
    }
    return 1+count(root->left)+count(root->right);
}
//Preorder traversal
void preorder(Treenode*root)
{
    if(root==NULL)return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
//Inorder Traversal
void inorder(Treenode*root)
{
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
//Postorder Traversal
void postorder(Treenode*root)
{
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
//Levelorder Traversal
void levelorder(Treenode*root)
{
    int n=count(root);
    int arr[n];
    int front=-1;
    int rear=-1;
    Treenode*temp=root;
    arr[++rear]=temp;
    arr[++rear]=NULL;
    front++;
    while(front<=rear)
    {
        Treenode*curr=arr[front];
        if(curr==NULL)
        {
            if(front>rear)
            {
                return;
            }
            arr[++rear]=NULL;
            front++;
            printf("\n");
            continue;
        }
        front++;
        printf("%d ",curr->data);
        if(curr->left)
        {
            arr[++rear]=curr->left;
        }
        if(curr->right)
        {
            arr[++rear]=curr->right;
        }
    }
}
/ Function to calculate the average of levels in a binary tree
void averageOfLevels(struct Treenode* root) {
    if (!root) {
        return;
    }

    int front = -1;
    int rear = -1;
    struct Treenode* arr[1000];  // Assuming a maximum of 1000 nodes

    arr[++rear] = root;
    arr[++rear] = NULL;

    while (front < rear) {
        struct Treenode* curr = arr[++front];
        int sum = 0;
        int count = 0;

        while (curr != NULL) {
            sum += curr->data;
            count++;

            if (curr->left) {
                arr[++rear] = curr->left;
            }

            if (curr->right) {
                arr[++rear] = curr->right;
            }

            curr = arr[++front];
        }

        // Print the average of nodes at the current level
        printf("Average of level: %lf\n", (double)sum / count);

        // Add a NULL marker for the next level
        if (front < rear) {
            arr[++rear] = NULL;
        }
    }
}
//Count nodes having only left child
int leftNode(Treenode*root)
{
    if(!root)
    {
        return 0;
    }
    int leftcount=leftNode(root->left);
    int rightcount=leftNode(root->right);
    if(root->left && !root->right)
    {
        return 1+leftcount+rightcount;
    }
    else
    {
        return leftcount+rightcount;
    }
}
//Count nodes having only right child
int rightNode(Treenode*root)
{
    if(!root)
    {
        return 0;
    }
    int leftcount=rightNode(root->left);
    int rightcount=rightNode(root->right);
    if(root->right && !root->left)
    {
        return 1+leftcount+rightcount;
    }
    else
    {
        return leftcount+rightcount;
    }
}
//Count nodes having only 1 child
int onechild(Treenode*root)
{
    if(!root)
    {
        return 0;
    }
    int left=onechild(root->left);
    int right=onechild(root->right);
    if((root->right && !root->left)||(root->left && !root->right))
    {
        return 1+left+right;
    }
    else
    {
        return left+right;
    }
}
//Count nodes having only 1 child
int twochild(Treenode*root)
{
    if(!root)
    {
        return 0;
    }
    int left=twochild(root->left);
    int right=twochild(root->right);
    if((root->right && root->left))
    {
        return 1+left+right;
    }
    else
    {
        return left+right;
    }
}
//Count leaf nodes
int leafNodes(Treenode*root)
{
    if(!root)
    {
        return 0;
    }
    if(!root->left && !root->right)
    {
        return 1;
    }
    return leafNodes(root->left)+leafNodes(root->right);
}
//Count nodes having at least one child
int notleafNodes(Treenode*root)
{
    if(!root)
    {
        return 0;
    }
    if(!root->left && !root->right)
    {
        return 0;
    }
    return 1+notleafNodes(root->left)+ notleafNodes(root->right);
}
//To check if value is prime or not?
int isprime(int val)
{
    if(val<=1)
    {
        return 0;
    }
    for(int i=2;i*i<=val;i++)
    {
        if(val%i==0)
        {
            return 0;
        }
    }
    return 1;
}
//Count only Prime nodes
int primeNodes(Treenode*root)
{
    if(!root)
    {
        return 0;
    }
    int count=isprime(root->data);
    count+=primeNodes(root->left);
    count+=primeNodes(root->right);
    return count;
}
//Depth of a node
int Depth(Treenode* root, int k) {
    if (!root) {
        return 0;
    }

    int dist=0;
    if((root->data==k)|| (dist=Depth(root->left,k)>0)||(dist=Depth(root->right,k)>0))
    {
        return dist+1;
    }
    return dist;
}
//Height of a node
int nodeHeight(Treenode*root,int k,int currH)
{
    if(!root)

    {
        return 0;
    }
    if(root->data==k)
    {
        return currH;
    }
    int left=nodeHeight(root->left,k,currH+1);
    int right=nodeHeight(root->right,k,currH+1);
    if(left>0)
    {
        return left;
    }
    if(right>0)
    {
        return right;
    }
    return 0;
}
// Max of two
int max(int i, int j) {
    return (i > j) ? i : j;
}

// Height of tree
int height(Treenode* root) {
    if (!root) {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

// Diameter of tree
int Diameter(Treenode* root) {
    if (!root) {
        return 0;
    }

    int leftH = height(root->left);
    int rightH = height(root->right);

    // Calculate the diameter passing through the current root
    int currD = leftH + rightH + 1;

    // Calculate the diameter in the left and right subtrees
    int leftD = Diameter(root->left);
    int rightD = Diameter(root->right);

    // Return the maximum of the three diameters
    return max(currD, max(leftD, rightD));
}
//Search
void search(Treenode*root,int val)
{
    if(root->data==val)
    {
        printf("Node found with value :%d",val);
        return;
    }
    if(root->data<val)
    {
        search(root->right,val);
    }
    if(root->data>val)
    {
        search(root->left,val);
    }
}
//Delete a node
Treenode* del(Treenode*root,int val)
{
    if(!root)
    {
        return root;
    }
    if(val < root->data)
    {
        root->left=del(root->left,val);
    }
    else if(val > root->data)
    {
        root->right=del(root->right,val);
    }
    else
    {
        if(!root->left && !root->right)
        {
            free(root);
            root=NULL;
            return root;
        }
        if(!root->left)
        {
            Treenode*temp=root->right;
            free(root);
            return temp;
        }
        else if(!root->right)
        {
            Treenode*temp=root->left;
            free(root);
            return temp;
        }
        else
        {
            Treenode*itr=root->right;
            while(itr->left)
            {
                itr=itr->left;
            }
            root->data=itr->data;
            root->right=del(root->right,itr->data);
        }
    }
    return root;
}
int main()
{
    Treenode*root=NULL;
    int k;
    printf("******Create Binary Tree*******");
    root=create();
    printf("Preorder traversal of tree:");
    preorder(root);
    printf("\nInorder traversal of tree:");
    inorder(root);
    printf("\nPostorder traversal of tree:");
    postorder(root);
    printf("\nTotal no. of nodes:%d",count(root));
    printf("\nNodes having only left child:%d",leftNode(root));
    printf("\nNodes having only right child:%d",rightNode(root));
    printf("\nLeafnodes:%d",leafNodes(root));
    printf("\nNot Leafnodes:%d",notleafNodes(root));
    printf("\nPrimenodes:%d",primeNodes(root));
    printf("\nNodes having only one child:%d",onechild(root));
    printf("\nNodes having only two child:%d",twochild(root));
    printf("\nEnter node to know it's Depth and Height:");
    scanf("%d",&k);
    printf("\nDepth of node:%d",Depth(root,k));
    printf("\nHeight of node:%d",nodeHeight(root,k,1));
    printf("\nLevel Order traversal of tree:\n");
    levelorder(root);
    printf("\nHeight of Binary Tree:%d",height(root));
    printf("\nDiameter of Binary Tree:%d",Diameter(root));
}

//*****ITERATIVE********



//Iterative insert
Treenode* insert(Treenode*root,int val)
{
    if(!root)
    {
        Treenode* node=(Treenode*)malloc(sizeof(Treenode));
        node->data=val;
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    Treenode* itr=root;
    while(1)
    {
        if(val<itr->data)
        {
            if(itr->left)
            {
                itr=itr->left;
            }
            else
            {
                Treenode*temp=(Treenode*)malloc(sizeof(Treenode));
                temp->data=val;
                temp->left=NULL;
                temp->right=NULL;
                itr->left=temp;
                break;
            }
        }
        else if(val>itr->data)
        {
            if(itr->right)
            {
                itr=itr->right;
            }
            else
            {
                Treenode*temp=(Treenode*)malloc(sizeof(Treenode));
                temp->data=val;
                temp->left=NULL;
                temp->right=NULL;
                itr->right=temp;
                break;
            }
        }
    }
    return root;
}
int count(Treenode*root)
{
    if(!root)
    {
        return 0;
    }
    return count(root->left)+count(root->right)+1;
}
//Iterative Preorder
void preorder(Treenode*root)
{
    int n=count(root);
    int *arr=(int*)malloc(n*sizeof(int));
    int top=-1;
    Treenode* temp=root;
    if(temp)
    {
        arr[++top]=temp;
    }
    while(top>=0)
    {
        temp=arr[top--];
        printf("%d ",temp->data);
        if(temp->right)
        {
            arr[++top]=temp->right;
        }
        if(temp->left)
        {
            arr[++top]=temp->left;
        }
    }
}
//Iterative Inorder Traversal
void inorder(Treenode*root)
{
    int n=count(root);
    int *arr=(int*)malloc(n*sizeof(int));
    int top=-1;
    Treenode* temp=root;
    while(1)
    {
        while(temp)
        {
            arr[++top]=temp;
            temp=temp->left;
        }
        if(top>=0)
        {
            temp=arr[top--];
            printf("%d ",temp->data);
            temp=temp->right;
        }
        else
        {
            break;
        }
    }
    free(arr);
}
//PostOrder iterative
void postorder(Treenode* root) {
    if (root == NULL) {
        return;
    }

    int n = count(root);
    int *arr1 = (int*)malloc(n * sizeof(int));
    int *arr2 = (int*)malloc(n * sizeof(int));
    int top1 = -1;
    int top2 = -1;

    Treenode* temp = root;
    arr1[++top1] = (int)temp;

    while (top1 >= 0) {
        temp = (Treenode*)arr1[top1--];
        if (temp) {
            arr2[++top2] = (int)temp;
            if (temp->left) {
                arr1[++top1] = (int)temp->left;
            }
            if (temp->right) {
                arr1[++top1] = (int)temp->right;
            }
        }
    }

    while (top2 >= 0) {
        temp = (Treenode*)arr2[top2--];
        printf("%d ", temp->data);
    }

    free(arr1);
    free(arr2);
}
