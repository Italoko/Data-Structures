struct priorityQueue
{
	int priority;
	char info;
	priorityQueue *prox;
};
typedef priorityQueue PQueue;

void init(PQueue **pq)
{
	*pq = NULL;
}

char isEmpty(PQueue *pq)
{
	return pq == NULL;
}

void enqueue(PQueue **pq,char info, int priority)
{
	PQueue *aux;
	PQueue *newNo = (PQueue*)malloc(sizeof(PQueue));
	
	newNo->info = info ;
	newNo->priority = priority ;
	newNo->prox = NULL;
	
	if(isEmpty(*pq))
		*pq = newNo;
	else
	{
		if(priority < (*pq)->priority)
		{
			newNo->prox = *pq;
			(*pq) = newNo;
		}	
		else
		{
			aux = *pq;
			while(aux->prox != NULL && aux->prox->priority <= priority)
				aux = aux->prox;	
			newNo->prox = aux->prox;
			aux->prox = newNo;
		}	
	}		
}

void dequeue(PQueue **pq,char *info,int *priority)
{
	PQueue *aux = *pq;
	if(!isEmpty(*pq))
	{
		*info = (*pq)->info;
		*priority = (*pq)->priority;
		*pq =(*pq)->prox;
		free(aux);
	}
}
