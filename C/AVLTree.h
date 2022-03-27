#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>

struct tree
{
	int info;
	struct tree *left,*right;
};
typedef struct tree Tree;

void init(Tree **root)
{
	*root = NULL;
}

Tree *CreateNo(int info)
{
	Tree *no = (Tree*)malloc(sizeof(Tree));
	no->info = info;
	no->left = no->right =NULL;

	return no;
}

void rotationLeft(Tree **p)
{
	Tree *q,*temp;
	q = (*p)->right;
	temp = q->left;
	q->left = *p;
	(*p)->right = temp;
	*p = q;
}

void rotationRight(Tree **p)
{
	Tree *q,*temp;
	q = (*p)->left;
	temp = q->right;
	q->right = *p;
	(*p)->left = temp;
	*p = q;
}

void height(Tree *p, int count,int *max)
{
	if(p!=NULL)
	{
		if(count > *max)
			*max = count;
			
		height(p->left,count+1,&*max);
		height(p->right,count+1,&*max);
	}
}

int heightAVL(Tree *p)
{
	int max = 0;
	height(p,1,&max);
	return max;
}

void showTree(Tree *root,int x,int y,int dist)
{
	if(root != NULL)
	{
		gotoxy(x,y); printf("%d\n",root->info);
		if(root->left != NULL);
		{
			gotoxy(x-dist/2,y+1); printf("/");

		}
		if(root->right != NULL);
		{
			gotoxy(x+dist/2,y+1); printf("\\");
		}
		showTree(root->left,x-dist,y+2,dist/2);
		showTree(root->right,x+dist,y+2,dist/2);
	}
}

void insertAVL(Tree **root, int info ,char *rotated)
{
	if(*root == NULL)
	{
		*rotated =1;
		*root = CreateNo(info);
	}
	else
		if(info<(*root)->info)
			insereAVL(&(*root)->left,info,&*rotated);
		else
			insereAVL(&(*root)->right,info,&*rotated);

	// then rotation
	if(!*rotated)
	{
		FB = heightAVL((*root)->right) -heightAVL((*root)->left) ;
		if(FB == -2 || FB == 2)
		{
			*rotated = 1;
			if(FB == 2)
			{
				FB_Child = heightAVL((*root)->right->right) - heightAVL((*root)->right->left); ;
				if(FB_Child == 1) // (2)(1)
					rotationLeft(&*root);
				else //(2)(-1)
				{
					rotationRight(&(*root)->right);
					rotationLeft(&*root);
				}

			}
			else // FB == -2
			{
				FB_Child = heightAVL((*root)->left->right) - heightAVL((*root)->left->left);
				if(FB_Child == -1) // (-2)(-1)
					rotationRight(&*root);
				else// (-2)(1)
				{
					rotationLeft(&(*root)->left);
					rotationRight(&*root);
				}
				
			}
		}
	}

}