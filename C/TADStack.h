struct stack
{
	int info;
	struct stack *prox;
};
typedef struct stack Stack;

void init(Stack **s)
{
	*s = NULL;
}

char isEmpty(Stack *s)
{
	return s == NULL;
}

int top(Stack *s)
{
	if(!isEmpty(s))
		return s->info;
	return -1;	
}

void push(Stack **s,int info)
{
	Stack *newNo = (stack*)malloc(sizeof(Stack));
	newNo->info = info; 
	newNo->prox = *s;
	*s = newNo;	
}

void pop(Stack **s,int *info)
{
	stack *aux;
	if(!isEmpty(*s))
	{
		aux = *s;
		*info = (*s)->info;
		*s = (*s)->prox;
		free(aux);
	}
	else
		*info = -1;
}