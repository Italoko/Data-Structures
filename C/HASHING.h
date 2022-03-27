#include<stdio.h>
#define TF 100
#define N 13

struct no
{
	int key,pos;
	struct no *prox;
};typedef struct no No;

struct tpreg
{
	int codigo,idade;
	char nome[30],status;
};typedef struct tpreg TpReg;

int hash(int key)
{
	return key % N;
}

void CreateFileHash(char arqName[])
{
	FILE *arq=fopen(arqName,"rb");
	TpReg reg;
	if(arq == NULL)
	{
		arq = fopen(nomeArq,"ab");
		reg.numero = 0;
		strcpy(reg.nome,"");
		reg.salario = 0.0;
		reg.status=0;
		reg.elo = 0;
		for(i = 0;i<N;i++)
			fwrite(&reg,sizeof(TpReg),1,arq);
	}
	fclose(arq);
}

int filesize(FILE *arq)
{
	fseek(arq,0,2);
	return ftell(arq) / sizeof(TpReg);
}

void searchHash(FILE *arq,int numero,int ender,char *achou)
{
	TpReg reg;
	fseek(arq,ender*sizeof(TpReg),0);
	fread(&reg,sizeof(TpReg),1,arq);
	
	while(numero != reg.numero && reg.elo != 0)
	{
		fseek(arq,reg.elo*sizeof(TpReg),0);
		fread(&reg,sizeof(TpReg),1,arq);
	}
	
	if(reg.numero == numero)
		*achou = 1;
	else
		*achou = 0;
}

void insereHash(char arqName[],TpReg reg)
{
	char achou;
	int ender;
	TpReg regDad;
	FILE *arq = fopen(arqName,"rb+");
	ender = hash(reg.numero);
	fseek(arq,ender*sizeof(TpReg),0);
	fread(&regDad,sizeof(TpReg),1,arq);
	
	if(regDad.numero == 0)
	{
		fseek(arq,ender*sizeof(TpReg),0);
		fwrite(&reg,sizeof(TpReg),1,arq);
	}
	else 
	{
		searchHash(arq,reg.numero,ender,&achou);
		if(!achou)
		{
			reg.elo= regDad.elo;
			regDad.elo = filesize(arq);
			fseek(arq,ender*sizeof(TpReg),0);
			fwrite(&regDad,sizeof(TpReg),1,arq);
			fseek(arq,0,2);
			fwrite(&reg,sizeof(TpReg),1,arq);
		}
	}
	
	fclose(arq);
}

void searchList(No *start,int key,No **no)
{
	while(start != NULL && key > start->key)
		start = start->prox;
	if(start != NULL && key == start->key)	
		*no = start;
	else
		*no = NULL;	
}

void insert(No T[], TpReg TabDados[TF],int *TL, TpReg reg)
{
	int ender;
	No *aux;
	
	ender = hash(reg.codigo);
	searchList(T[ender],reg.codigo,&aux);
	
	if(aux == NULL) 
	{
		TabDados[*TL] = reg;
		insere_lista(&T[ender],reg.codigo,*TL)	
		(*TL)++;
	}
	else
		printf("Chave existente");
}

void removeLogic(No T[N],TpReg TabDados[TF],int codigo)
{
	int ender;
	No *aux;
	searchList(T[ender],reg.codigo,&aux);
	
	if(aux != NULL)
	{
		if(TabDados[aux->pos].status)
			TabDados[aux->pos].status = 0;
		else
			printf("Chave ja excluido");
	}
	else
		printf("N�o encontrado");
}

