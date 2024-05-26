#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left;
    node *right;
};

node *root=NULL;

struct node *insert(node *temp,node *ptr){
    if(ptr->data>temp->data){
        if(temp->right==NULL){
            temp->right=ptr;
        }
        else{
            temp=temp->right;
            insert(temp,ptr);
        }

    }


        else if(ptr->data<temp->data){
        if(temp->left==NULL){
            temp->left=ptr;
        }
        else{
            temp=temp->left;
            insert(temp,ptr);
        }
        }

};

void inorder(node *temp){
    if(temp!=NULL){
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
    }
}

void preorder(node *temp){
    if(temp!=NULL){
        printf("%d ",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(node *temp){
    if(temp!=NULL){
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->data);
    }
}

int search(node *temp,int x){
    int flag=0;
    if(temp->data==x){
        return 1;
    }

    else{
        if(temp->data>x){
            temp=temp->left;
            search(temp,x);
        }

        if(temp->data<x){
            temp=temp->right;
            search(temp,x);
        }
    }
}



int main()
{
    int n,x=15;
    node *ptr=new node;
    ptr->data=x;
    ptr->left=NULL;
    ptr->right=NULL;
    root=ptr;

    while(1){
    printf("\n1.insert\n2.Display\n3.Search\n0.Exit");
    scanf("%d",&n);
    if(n==1){
        printf("Enter value:\n");
        int val;
        scanf("%d",&val);
        node *temp=root;
        ptr=new node;
        ptr->data=val;
        ptr->left=NULL;
        ptr->right=NULL;

        insert(temp,ptr);
    }

    else if(n==2) {
        printf("\n1.inorder\n 2.preorder\n 3.postorder\n");
        int box;
        scanf("%d",&box);
        node *temp=root;
        if(box==1)inorder(temp);
        if(box==2)preorder(temp);
        if(box==3)postorder(temp);
    }

    else if(n==3){
        int i,pot;
        printf("Enter the value to search:");
        scanf("%d",&i);
        node *temp=root;
        pot=search(temp,i);
        if(pot==1){
            printf("DATA Found\n");
        }

    }

     else if(n==0){
        exit(1);
    }

    }


    return 0;
}
