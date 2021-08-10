///Júlia de Miranda Gomes     RA:20052387
#include <stdio.h>
#include <stdlib.h>
#define TAM 50

struct PEDIDOS
{
    int npedido;
    int nproduto;
    int qtdd;
};

struct PRECOS
{
    int num;
    float preco;
};

void leitura_pedidos(int*tamanho, struct PEDIDOS pedidos[])
{
    int i,j=0,n,ped=0;
    *tamanho=0;
    while(ped!=-1)
    {
        printf("Numero do pedido: "); scanf("%d",&ped);
        if(ped==-1)
            break;
        else
        {
            printf("Quantos produtos serao neste pedido? "); scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                pedidos[j].npedido=ped;
                printf("     Numero do Produto: "); scanf("%d",&pedidos[j].nproduto);
                printf("     Quantidade: "); scanf("%d",&pedidos[j].qtdd);
                (*tamanho)++;
                j++;
            }
        }
    }
}

void imprime_relatorio(struct PRECOS precos[], struct PEDIDOS pedidos[],int tamanho)
{
    int i,j;
    float valor[TAM],preco_unitario[10];
    for(i=0;i<tamanho;i++)
        for(j=0;j<10;j++)
        {
           if(pedidos[i].nproduto==precos[j].num)
            {
                preco_unitario[i]=precos[j].preco;
                valor[i]=pedidos[i].qtdd*precos[j].preco;
            }
        }

    printf("\nNo. Pedido    No. Produto    Quantidade    Preco Unitario    Valor");
    printf("\n===================================================================");
    for(i=0;i<tamanho;i++)
    {
        if(pedidos[i].npedido==pedidos[i-1].npedido)
            printf("\n                  %3d            %2d            %.2f         %.2f",pedidos[i].nproduto, pedidos[i].qtdd, preco_unitario[i], valor[i]);
        else
            printf("\n   %4d           %3d            %2d            %.2f         %.2f",pedidos[i].npedido, pedidos[i].nproduto, pedidos[i].qtdd, preco_unitario[i], valor[i]);
    }
}

int main()
{
    struct PEDIDOS pedidos[TAM];
    struct PRECOS precos[]= {{120,25.50},{121,14.45},{122,30.58},{123,48.35},{124,75.55},
                             {125,25.00},{126,43.40},{127,30.00},{128,30.75},{129,15.55}};
    int tamanho;
    leitura_pedidos(&tamanho,pedidos);
    imprime_relatorio(precos,pedidos,tamanho);
    printf("\n\n");
    return 0;
}
