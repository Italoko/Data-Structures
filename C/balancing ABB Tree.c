void search(Tree *root,int info,Tree **e,Tree **parentNode)
{
	*e = *parentNode = root;
	while(e != NULL && info != e->info)
	{
		*parentNode = *e;
		if(info < (*e)->info)
			*e = (*e)->left;
		else
			*e = (*e)->right;
	}
}

void remove(Tree **root, Tree *e, Tree *parentNode,char side)
{
	Tree *paiSub,*sub;
	int aux;

	if(e->left == NULL && e->right == NULL ) // 1) leaf
	{
		if(e!= parentNode)
			if(e->info > parentNode->info)
				parentNode->right = NULL;
			else
				parentNode->left = NULL;
		else
			*root = NULL;
		free(e);
	}
	else
	{
		if(e->left != NULL  && e->right == NULL || e->right != NULL && e->left == NULL) // one child
		{
			if(e != parentNode)
			{
				if(e->info > parentNode->info)
				{
 	 				if(e->left != NULL)
						parentNode->right = e->left;
					else
						parentNode->right = e->right;
				}
				else
				{
					if(e->left != NULL)
						parentNode->left = e->left;
					else
						parentNode->left = e->right;
				}
				free(e);
			}
			else
				if(e == parentNode)
				{
					if(e->left !=NULL)
						*root = e->left;
					else
						*root = e->right;
					free(e);
				}
		}
		else
		{
			// sub right
			if(side == 'r')
			{
				paiSub = e;
				sub = e->right;
				while(sub->left != NULL)
				{
					paiSub = sub;
					sub = sub->left;
				}
				aux = sub->info;
				remove(&*root,sub,paiSub,side);
				e->info = aux;
			}
			else // sub left
			{
				paiSub = e;
				sub = e->left;
				while(sub->right != NULL)
				{
					paiSub = sub;
					sub = sub->right;
				}
				aux = sub->info;
				remove(&*root,sub,paiSub,side);
				e->info = aux;
			}
			free(sub);
		}
	}
}

void quantNO(Tree *p, int *qtd)
{
	if(p != NULL)
	{
		*qtd = *qtd+1;
		quantNO(p->left,&qtd);
		quantNO(p->right,&qtd);
	}
}

void insert(Tree **root,int info)
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

void balancing(Tree **root)
{
	Tree *p,*e,*parentNode;
	int aux,qDir,qEsq,FB;
	Queue *Q;
	
	init(&Q);
	enqueue(&Q,*root);
	while(!isEmpty(Q))
	{
		dequeue(&Q,&p);
		do
		{
			qDir = qEsq = 0;
			quantNo(p->left,&qEsq);
			quantNo(p->right,&qDir);
			FB = qDir - qEsq;
			if(FB<-1 || FB >1)
			{
				aux = p->info;
				busca(*root,p->info,&e,&parentNode);
				if(p->left == NULL)
					p = p->right;
				else
					if(p->right == NULL)
						p = p->left;
				if(FB > 0)
					remove(&*root,e,parentNode,'r');
				else
					remove(&*root,e,parentNode,'l');
				insert(&*root,aux);
			}
		}while(FB<-1 || FB>1);
		
		if(p->left != NULL)
			enqueue(&Q,p->left);
		if(p->right != NULL)
			enqueue(&Q,p->right);
	}
}
