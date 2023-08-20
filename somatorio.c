#include<stdio.h>
#include<stdlib.h>

struct somatorio
{
    int soma,item;
};

struct somatorio* somatorio_pa_rec(int n,int b,int r)
{
    if (n==1)
    {
        struct somatorio *q=NULL;
        q=(struct somatorio *) malloc(sizeof(struct somatorio));

        q->item=b;
        q->soma=b;
        printf("%d",b);

        return q;
    }
    else
    {
        struct somatorio *k=NULL;
        k=somatorio_pa_rec(n-1,b,r);
        
        k->item=k->item+r;
        k->soma=k->soma+k->item;
        printf(" + %d",k->item);

        return k;
    }
    
}

struct somatorio* somatorio_pg_rec(int n,int b,int r)
{
    if (n==1)
    {
        struct somatorio *q=NULL;
        q=(struct somatorio *) malloc(sizeof(struct somatorio));

        q->item=b;
        q->soma=b;
        printf("%d",b);

        return q;
    }
    else
    {
        struct somatorio *k=NULL;
        k=somatorio_pg_rec(n-1,b,r);
        
        k->item=k->item*r;
        k->soma=k->soma+k->item;
        printf(" + %d",k->item);

        return k;
    }
    
}

int main(){
    int decisao=0;
    int i=0;
    int b=0;
    int r=0;

    printf("é PA ou PG?(1 para PA, 2 para PG)\n");
    scanf("%d",&decisao);
    printf("Escreva até onde você quer fazer a soma\n");
    scanf("%d",&i);
    printf("Escreva o caso base\n");
    scanf("%d",&b);
    printf("Escreva a razão\n");
    scanf("%d",&r);

    if (decisao==1)
    {
        struct somatorio *aux=NULL;
        aux=somatorio_pa_rec(i,b,r);

        printf("\nO resultado da soma é %d",aux->soma);
    }
    
    else if (decisao==2)
    {
        struct somatorio *aux=NULL;
        aux=somatorio_pg_rec(i,b,r);

        printf("\nO resultado da soma é %d",aux->soma);
    }
    
}
