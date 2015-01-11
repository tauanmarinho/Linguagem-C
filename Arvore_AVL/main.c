#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

 struct tipono_avl  {
                        int dado;
                        short int bal;
                        struct tipono_avl *esq, *dir;
                        };

void mostra_operacoes()
{ printf("\nOperacoes disponiveis: \n");
  printf("    1 - Imprimir percurso em pre-ordem\n");
  printf("    2 - Imprimir percurso em em-ordem\n");
  printf("    3 - Imprimir percurso em pos-ordem\n");
  printf("    4 - Buscar um elemento na arvore\n");
  printf("    5 - Retirar um elemento da arvore\n");
  printf("    6 - Imprimir arvore por nivel \n");
  printf("    7 - Calcular altura da arvore \n");
}

void pre_ordem(struct  tipono_avl *p)
{ if (p != NULL){
      printf(" %d ", p->dado);
      pre_ordem(p->esq);
      pre_ordem(p->dir);
      }
}

void em_ordem(struct  tipono_avl *p)
{ if (p != NULL){
      em_ordem(p->esq);
      printf(" %d ", p->dado);
      em_ordem(p->dir);
      }
}

void pos_ordem(struct  tipono_avl *p)
{ if (p != NULL){
      pos_ordem(p->esq);
      pos_ordem(p->dir);
      printf(" %d ", p->dado);
      }
}



void rot_dir(struct tipono_avl **pp, char *psit)
{
struct tipono_avl *aux;
if ( (*pp)->esq->bal == 1) //rotacao direita simples
   {
    aux = *pp;
    *pp = (*pp)->esq;
    aux->esq = (*pp)->dir;
    (*pp)->dir = aux;
     aux->bal = 0;
   }
else // rota��o direita dupla
   {
   struct tipono_avl *auxa; //mais um auxiliar
   aux =*pp;
   auxa= (*pp)->esq;
   *pp = auxa->dir;
   auxa->dir = (*pp)->esq;  // adota filho esquerdo do novo raiz
   aux->esq = (*pp)->dir;   // adota filho direito  do novo raiz
   (*pp)->esq = auxa;
   (*pp)->dir = aux;

   if ((*pp)->bal == 1)
       { auxa->bal = 0;
         aux->bal = -1;
       };
   if  ((*pp)->bal == -1)
             { auxa->bal = 1;
              aux->bal = 0;
              } ;
   }
   (*pp)->bal = 0; //em ambos os casos
   *psit = 'F';
}


void rot_esq(struct tipono_avl **pp, char *psit)
{
struct tipono_avl *aux;
if ( (*pp)->dir->bal == -1) //rotacao esquerda simples
   {
    aux = *pp;
    *pp = (*pp)->dir;
    aux->dir = (*pp)->esq;
    (*pp)->esq = aux;
    aux->bal = 0;
   }
else // rota��o esquerda dupla
   {
   struct tipono_avl *auxa; //mais um auxiliar
   aux =*pp;
   auxa= (*pp)->dir;
   *pp = auxa->esq;
   auxa->dir = (*pp)->esq;
   aux->dir = (*pp)->dir;
   (*pp)->esq = aux;
   (*pp)->dir = auxa;

   if ((*pp)->bal == 1)
       { auxa->bal = 0;
         aux->bal = -1;
       }
   else if   ((*pp)->bal == -1)
             { auxa->bal = 1;
              aux->bal = 0;
              };
    };
   (*pp)->bal = 0;
   *psit = 'F';
}


void insere_dado(int x, struct tipono_avl **pp, char *psit)
{
if (*pp == NULL)  // posi��o vazia, fazer a insercao
   { *pp = (struct tipono_avl *) malloc(sizeof(struct tipono_avl));
     (*pp)->dado = x;
     (*pp)->bal = 0; //balanceamento zero
     (*pp)->esq = NULL;
     (*pp)->dir = NULL;
     *psit = 'V';
   }
else if (x < (*pp)->dado) //insere a esquerda
        {
             insere_dado(x, &((*pp)->esq), psit);
             if (*psit == 'V')  //depois que inserir acertar balanceamentos:
                 switch((*pp)->bal) { //ver balanceamento do pai:
                                    case -1: (*pp)->bal = 0; *psit = 'F'; break;
                                    case 0:  (*pp)->bal = 1;  break;
                                    case 1:  rot_dir(pp, psit); break;
                                    };
        }
        else if  (x > (*pp)->dado)
                 {
                 insere_dado(x, &((*pp)->dir), psit);
                 if (*psit == 'V')  //depois que inserir acertar balanceamentos:
                     switch((*pp)->bal) { //ver balanceamento do pai:
                                    case 1: (*pp)->bal = 0; *psit = 'F'; break;
                                    case 0:  (*pp)->bal = -1; break;
                                    case -1:  rot_esq(pp, psit); break;
                                    };
                 }
                 else printf("        erro -> elemento existente \n");
}



void cria_arvore_avl(struct tipono_avl **pp)
{
char cont = 's', sit;
int dado;
printf(" \n\n Criacao da arvore AVL: \n\n");
*pp = NULL; // inicializando o no raiz
while (cont == 's') // le dados e insere
      { printf("  Digite um dado: ");
        scanf("%d", &dado);
        sit = 'F';  // dado ainda n�o inserido
        insere_dado(dado, pp, &sit);
        printf(" Deseja inserir mais dados (s/n) ? ");
        fflush(stdin);
        cont = getche();
      }
printf(" \n        Arvore AVL foi criada !!! \n");
}

struct tipono_avl* busca(struct tipono_avl *p, int x){
if (x==NULL)
    {
        return NULL;
    }
        else {
            if (p->dado>x)
    {
        return busca(p->esq,x);
    }
    else{
        if(p->dado<x){
            return busca(p->dir,x);
        }
        else
        {
            return x;
        }
        }
        }
}

void desenhaArvore(struct  tipono_avl *p) {
    printf("\n");
     desenhaNivel(p, 1);
      }

void desenhaNivel(struct tipono_avl *p, int nivel) {
     int i;
     if(p != NULL){
     desenhaNivel(p->dir, nivel+1);
     for(i=0;i<nivel;i++)
     printf("      ");
     printf("%6d\n\n",p->dado);
     desenhaNivel(p->esq,nivel+1);
     }
}

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}



int altura(struct tipono_avl *pRaiz){
   if((pRaiz == NULL) || (pRaiz->esq == NULL && pRaiz->dir == NULL))
       return 0;
   else
       return 1 + maior(altura(pRaiz->esq), altura(pRaiz->dir));
}

int main(int argc, char *argv[])
{
  struct  tipono_avl *raiz;
  int operacao;
  int x;
  char resp = 's';
  cria_arvore_avl(&raiz);
  mostra_operacoes();
  while (resp == 's')
        { printf("  Digite operacao: ");
        scanf("%d", &operacao);
        switch (operacao) {
            case 1: printf("\nPre-ordem: "); pre_ordem(raiz); break;
            case 2: printf("\nEm-ordem:  "); em_ordem(raiz); break;
            case 3: printf("\nPos-ordem: "); pos_ordem(raiz); break;
            case 4: printf("\nDigite elemento a ser procurado: "); scanf("%d", &x);
            printf("Valor procurado: %i",busca(raiz,x)); break;
            case 5: printf("\nDigite elemento a ser retirado: ");
            scanf("%d", &x);  retira(x,&raiz); break;
            case 6: printf("\n Imprimir arvore por nivel: "); desenhaArvore(raiz);
            case 7: printf("\n Altura da arvore: %d \n",  altura(raiz));
            }
         printf("\n Deseja outra operacao ? (s/n) ");
         fflush(stdin);
         resp = getche();
         };
  printf("\n\n");
  system("PAUSE");
  return 0;
}
