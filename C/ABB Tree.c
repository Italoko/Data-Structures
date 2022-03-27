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

Tree *createNo(int info)
{
	Tree *no = (Tree*)malloc(sizeof(Tree));
	no->info = info;
	no->left = no->right =NULL;

	return no;
}

void insert(Tree **root,int info) // iterative
{
	Tree *aux,*ant;
	if(*root == NULL)
		*root = createNo(info);
	else
	{
		aux = *root;
		while(aux != NULL)
		{
			ant = aux;
			if(info < aux->info)
				aux = aux->left;
			else
				aux = aux->right;
		}
		if(info < ant->info)
			ant->left = createNo(info);
		else
			ant->right = createNo(info);
	}
}

void insertRec(Tree **root,int info) // recursive
{
	if(*root == NULL)
		*root = createNo(info);
	else
	{
		if(info < (*root)->info)
			insertRec(&(*root)->left,info);
		else
			insertRec(&(*root)->right,info);
	}
}

void searchRec(Tree *root,int info,Tree **no) // search with ref recursive
{
	if(root != NULL && info != root->info)
	{
		if(info < root->info)
			searchRec(root->left,info,&*no);
		else
			searchRec(root->right,info,&*no);
	}
	else
		*no = root;
}

Tree *searchRec(Tree *root, int info) // search with return recursive
{
	if(root!=NULL)
	{
		if(info==root->info)
			return root;
		else if(info>root->info)
			return searchRec(root->right, info);
		else
			return searchRec(root->left, info);
	}
	return NULL;
}

void search(Tree *root,int info,Tree **no) // search with ref iterative
{
	while(root != NULL && info != root->info)
	{
		if(info < root->info)
			root = root->left;
		else
			root = root->right;
	}
	*no = root;
}

Tree *search(Tree *root,int info) // search with return iterative
{
	while(root != NULL && info != root->info)
	{
		if(info < root->info)
			root = root->left;
		else
			root = root->right;
	}
	return root;
}

void localize_NO(Tree *root,int infoParent,Tree **parentNode)
{
	if(root != NULL)
	{
		if(root->info == infoParent)
			*parentNode = root;
 		else
		{
			localize_NO(root->left,infoParent,&*parentNode);
			localize_NO(root->right,infoParent,&*parentNode);
		}
	}
}

void destroyer (Tree **root) // kill tree 
{
	if(*root != NULL)
	{
		destroyer(&(*root)->left);
		destroyer(&(*root)->right);
		free(*root);
		*root = NULL;
	}
}

int depth(Tree *root,int info) // return tree depth
{
	int level = 1;
	while(root != NULL && info != root->info)
	{
		if(info < root->info)
			root = root->left;
		else
			root = root->right;
		level++;
	}
	if(root != NULL && root->info == info)
		return level;
	else
		return 0;
		
}

Tree *parentNode(Tree *root,int info)
{
	Tree *ant;
	if(root->info == info)
		return root;

	while(root != NULL && info != root->info)
	{
		ant = root;
		if(info < root->info)
			root = root->left;
		else
			root = root->right;
	}
	if(root != NULL && root->info == info)
		return ant;
	return NULL;
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

//travessia recursive
void pre_ordem(Tree *root)
{
	if(root != NULL)
	{
		printf("%d\n",root->info);
		pre_ordem(root->left);
		pre_ordem(root->right);
	}
}

void in_ordem(Tree *root)
{
	if(root != NULL)
	{
		in_ordem(root->left);
		printf("%d\n",root->info);
		in_ordem(root->right);
	}
}

void pos_ordem(Tree *root)
{
	if(root != NULL)
	{
		pos_ordem(root->left);
		pos_ordem(root->right);
		printf("%d\n",root->info);
	}
}
// travessia

int main()
{
	Tree *root;
	init(&root);

	showTree(root,40,1,20);
}
