struct No 
{
	int info;
	struct No *prev,*prox;
};
typedef struct No no;

struct Descritor
{
	struct No *start,*end;
};
typedef struct Descritor descritor;

void init(descritor *LD)
{
	(*LD).start = (*LD).end = NULL;
}

char isEmpty(descritor *LD)
{
	return (*LD).start == NULL && (*LD).end == NULL;
}

void insertStart(descritor *LD,int info)
{
	no *newNo = (no*)malloc(sizeof(no));
	newNo->info = info;
	newNo->prev = newNo->prox = NULL;
	
	if(isEmpty(LD))
		(*LD).start = (*LD).end = newNo;
	else
	{
		newNo->prox = (*LD).start;
		(*LD).start = (*LD).start->prev = newNo;
	}
}

void insertEnd(descritor *LD,int info)
{
	no *newNo = (no*)malloc(sizeof(no));
	newNo->info = info;
	newNo->prev = newNo->prox = NULL;
	
	if(isEmpty(LD))
		(*LD).start = (*LD).end = newNo;
	else
	{
		newNo->prev = (*LD).end;
		(*LD).end = (*LD).end->prox = newNo;
	}
}

no *search(descritor *LD,int info)
{
	no *aux = (*LD).start;
	while(aux != NULL && aux->info != info)
		aux = aux->prox;
	return aux;	
}

int exclui(descritor *LD,int info)
{
	no *aux = search(LD,info);
	if(aux != NULL)
	{
		if((*LD).start == (*LD).end) //only one
		{
			init(LD);
			free(aux);	
		}
		else
		{
			if((*LD).start==aux) // first
			{
				(*LD).start = (*LD).start->prox;
				(*LD).start->prev = NULL;
				free(aux);	
			}
			else 
			{
				if((*LD).end == aux) // end 
				{
					(*LD).end = (*LD).end->prev;
					(*LD).end->prox = NULL;
					free(aux);	
				}
				else //middle
				{
					aux->prev->prox = aux->prox;
					aux->prox->prev = aux->prev;
					free(aux);
				}	
			}	
		}
		return 1;  
	}
	return 0;
}
