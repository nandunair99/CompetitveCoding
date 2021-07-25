#include <stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	struct node *left;
	struct node *right;
};
struct node * insertNode(struct node *root)
{
	struct node *newnode = NULL, *p = NULL, *parent = NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter value of node to be added:");
	scanf("%d",&newnode->val);
	newnode->left = NULL;
	newnode->right = NULL;
	if(root == NULL)
	{
		root = newnode;
		printf("Node inserted");
		return root;
	}
	else
	{
		p=root;
		while(p != NULL)
		{
			parent = p;
			if(newnode->val > p->val)
			{
				p=p->right;
			}
			else
			{
				p=p->left;
			}
		}
		if(newnode->val < parent->val)
		{
			parent->left = newnode;
			printf("Node inserted Left");
		}
		else
		{
			parent->right = newnode;
			printf("Node inserted right");
		}
		return root;
	}
}
void inorder(struct node *p)//left right right
{
	if(p != NULL)
	{
		inorder(p->left);
		printf("%d ",p->val);
		inorder(p->right);
	}
}

struct node * deleteNode(struct node *root)
{
    printf("root %d\n",root->val);
	int key;//user input
	struct node *p = NULL, *parent = NULL, *succ = NULL,*par_succ=NULL;
	if(root == NULL)
	{
		printf("Tree is empty!");
		return root;
	}
	else
	{
	   printf("Enter value to be deleted : ");
	scanf("%d",&key);
	p=root;
	while(p != NULL && p->val != key)//either reached the leaf and no value found or value found
	{
	    printf("k v %d %d\n",key,p->val);

		if(p->val < key)//34 28
		{
		    parent=p;
			p=p->right;
		}
		else
		{
		    parent=p;
			p=p->left;
		}
		//printf("\n%d",p->val);
		//printf("\n%d",parent->val);
	}
	if(p == NULL)//reached leaf and value not found
	{
		printf("Value not found!");
		return root;
	}
	else//value found and p points to value
	{
		if(p->left == NULL && p->right == NULL) //to delete leaf node
		{
			if(parent->left == p)//to check whether p is left node or right node of parent
			{
				parent->left = NULL;//if left then free left side
				free(p);
			}
			else
			{
				parent->right = NULL;//if right then free right side
				free(p);
			}
			return root;
		}
		else if(p->left != NULL && p->right == NULL) //to delete node having single left child
		{
			if(parent->left == p)//if p is on left side of parent then  p->left will be also on left side after deletion
			{
				parent->left = p->left;
			}
			else//if p is on right side of parent then child of p->left will be also on right side after deletion
			{
				parent->right = p->left;
			}
			free(p);
			return root;
		}
		else if(p->left == NULL && p->right != NULL) //to delete node having single right child
		{
			if(parent->left == p)//if p is on left side of parent then  p->right will be also on left side after deletion
			{
				parent->left = p->right;
			}
			else//if p is on right side of parent then child of p->right will be also on right side after deletion
			{
				parent->right = p->right;
			}
			free(p);
			return root;
		}
		else if(p->left != NULL && p->right != NULL) // to delete node having two child
		{
			succ = p->right;
			par_succ = p;
			while(succ->left != NULL)//moving to left child to get successor
            {
				 par_succ = succ;
				 succ=succ->left;
            }
            if(p == par_succ)//successor is to right of p and has no left child nodes
            {
                p->val=succ->val;
                p->right=succ->right;

            }
            else
            {
                p->val=succ->val;
                par_succ->left=succ->right;

            }



			free(succ);
			return root;
		}
	}
	}

}
void main()
{
	struct node *root = NULL;
	int choice;
	do{
		printf("\n\n--------------------------");
		printf("\n1.Insert data");
		printf("\n2.Inorder Traversal");
		printf("\n3.Delete data");
		printf("\n4.Exit");
		printf("\n--------------------------");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				root = insertNode(root);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				root = deleteNode(root);
				break;
			case 4:
				break;
			default:
				printf("Invalid choice!");
				break;
		}
	}while(choice!=6);
}
