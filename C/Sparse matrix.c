#include<stdio.h>
#include<stdlib.h>

#define nRow 2
#define nCol 2

struct sparseMatrix
{
	int row,col,value;
	struct sparseMatrix *pc,*pl;
	
};typedef struct sparseMatrix MatEsp;

void vfPosition(MatEsp *vetRow[],int row,int col,MatEsp **aux)
{
	MatEsp *p;
	p = vetRow[row];
	while(p!= NULL && col>p->col)
		p = p->pl;
		
	if(p!= NULL && col==p->col)
		*aux = p;
	else
		*aux = NULL;
}

void insert(MatEsp *vetRow[],MatEsp *vetcol[],int row,int col,int value)
{
	MatEsp *prev,*aux,*newCel;
	if(row >= 0 && row<nRow && col>= 0 && col<nCol)
	{
		vfPosition(vetRow,row,col,&aux);
		if(aux != NULL)
			aux->value = value;
		else
		{
			///create celula
			newCel = (MatEsp*)malloc(sizeof(MatEsp));
			newCel->row = row;
			newCel->col = col;
			newCel->value = value;

			// link horizontal
			if(vetRow[row]== NULL) // first case
			{
				vetRow[row] = newCel;
				newCel->pl=NULL;
			}
			else
			{
				if(col < vetRow[row]->col)// second case
				{
					newCel->pl = vetRow[row];
					vetRow[row] = newCel;
				}
				else // third case
				{
					prev= vetRow[row];
					aux= prev->pl;
					while(aux != NULL && col > aux->col)
					{
						prev = aux;
						prev = prev->pl;
					}
					prev->pl = newCel;
					newCel->pl = aux;
				}
			}
			
			// link vertical
			if(vetcol[col] == NULL)
			{
				vetcol[col]= newCel;
				newCel->pc = NULL;
			}
			else
			{
				if(row < vetcol[col]->row)
				{
					newCel->pc = vetcol[col];
					vetcol[col] = newCel;
				}
				else
				{
					prev = vetcol[col];
					aux = prev->pc;
					while(aux != NULL && row > aux->row)
					{
						prev = aux;
						aux = aux->pc;
					}
					prev->pc = newCel;
					newCel->pc = aux;
				}
			}
			
		}
	}
	else
		printf("As coordenadas est�o fora da matriz" );
}

void init(MatEsp *vetRow[],MatEsp *vetcol[])
{
	int i;
	for(i =0; i<nRow ; i++)
		vetRow[i] = NULL;
	for(i =0; i<nCol ; i++)
		vetcol[i] = NULL;
}

void show(MatEsp *vetRow[])
{
	MatEsp *aux;
	int i,j;
	for(i = 0; i < nRow; i++)
	{
		for(j=0; j< nCol; j++)
		{
			vfPosition(vetRow,i,j,&aux);
			if(aux != NULL)
				printf("%d ",aux->value);
			else
				printf("0  ");
		}
		printf("\n");
	}
}

void sum(MatEsp *rowA[],MatEsp *rowB[],MatEsp *rowC[],MatEsp *colC[])
{
	MatEsp *auxA,*auxB;
	int i,j,soma;
	for(i = 0; i < nRow; i++)
	{
		for(j=0; j< nCol; j++)
		{
			vfPosition(rowA,i,j,&auxA);
			vfPosition(rowB,i,j,&auxB);
			soma = 0;
			if(auxA != NULL)
				soma = auxA->value;
			if(auxB != NULL)
				soma+= auxB->value;

			if(soma!= 0)
				insert(rowC,colC,i,j,soma);

		}
	}
}

void removeMat(MatEsp *vetRow[])
{
	MatEsp *aux,*prev;
	int i,j;
	
	for(i = 0; i < nRow; i++)
	{
		for(j=0; j< nCol; j++)
		{
			vfPosition(vetRow,i,j,&aux);
			if(aux != NULL)
				free(aux);
		}
	}
}

void multiply(MatEsp *rowA[], MatEsp *rowB[], MatEsp *rowC[], MatEsp *colC[])
{
	MatEsp *auxA,*auxB;
	int i,j,k,res;

	for(i = 0; i < nRow; i++)
	{
		for(j=0; j< nCol; j++)
		{
			res = 0;
			for(k = 0; k < nRow ; k++)
			{
				vfPosition(rowA,i,k,&auxA);
				vfPosition(rowB,k,j,&auxB);

				if(auxA == NULL)
					auxA->value = 0;
				if(auxB == NULL)
					auxB->value = 0;

				res += auxA->value * auxB->value;
			}
			insert(rowC,colC,i,j,res);
		}
	}
}

int main()
{
	MatEsp *rowA[nRow], *colA[nCol],*rowB[nRow], *colB[nCol], *rowC[nRow], *colC[nCol];

	init(rowA,colA);
	init(rowB,colB);
	init(rowC,colC);
	
	insert(rowA,colA,0,0,2);
	insert(rowA,colA,0,1,5);
	insert(rowA,colA,1,0,5);
	insert(rowA,colA,1,1,2);
	
	insert(rowB,colB,0,0,2);
	insert(rowB,colB,0,1,5);
	insert(rowB,colB,1,0,5);
	insert(rowB,colB,1,1,2);
	
	show(rowA);
	printf("----------------\n");
	show(rowB);
	printf("----------------\n");
	multiply(rowA,rowB,rowC,colC);
	
	show(rowC);
	removeMat(rowC);
	printf("----------------\n");
	show(rowC);
}
