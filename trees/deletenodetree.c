#include<stdio.h>
nodeptr deletenode(nodeptr root, int data)
{

    if(root==NULL)
        return root;
    else if(data < root->data)
        root->left=deletenode(root->left, data);
    else if(data > root->data)
        root->right=deletenode(root->right, data);
    else{
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
            return root;
        }
        else if(root->left == NULL){
            nodeptr temp=root;
            ro
        }
    }
}
