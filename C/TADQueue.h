struct queue
{
	int info;
	struct queue *prox;
};
typedef struct queue Queue;

void init(Queue **q)
{
	*q = NULL;
}

char isEmpty(Queue *q)
{
	return q == NULL;
}

void enqueue(Queue **q,int info)
{
	Queue *aux;
	Queue *newNo = (Queue*)malloc(sizeof(Queue));
	newNo->prox = NULL;
	newNo->info = info;
	
	if(isEmpty(*q))
		*q = newNo;	
	else
	{
		aux = *q;
		while(aux->prox != NULL )
			aux = aux->prox;
		
		aux->prox = newNo;	
	}	 
}

void dequeue(Queue **q,int *info)
{
	queue *aux;
	if(!isEmpty(*q))
	{
		aux = *q;
		*info = (*q)->info;
		*q = (*q)->prox;
		free(aux);
	}
	else
		*info = -1;
}