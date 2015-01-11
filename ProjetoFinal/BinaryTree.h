#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define LimpaTela "CLS"
#define TamanhoVetorPrincial 200
//Declaração do tipo de nó
struct avl_node
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
};


int find_height(struct avl_node *node)//Funcao criada para achar a diferença de altura
{
    int height=0;//a contagem da altura sempre começa por ZERO
    if (node !=NULL){//ele era fazer a contagem até final da arvore
        int left_height= find_height(node->left);//altura da esquerda
        int right_height= find_height(node->right);//altura da direita
        int max=(left_height > right_height) ? left_height : right_height;//se a altura da esquerda for maior que da direita
        height = 1+ max;//contagem da altura                              //entao max=altura da esquerda, caso contrario max=altura da direita
    }
    return height;
}
    int get_diff(struct avl_node *node)
{
    int left_height=find_height(node ->left);//pega a maior altura da esquerda
    int right_height=find_height(node ->right);//pega a maior altura da direita
    int b_factor= left_height - right_height;//faz a diferença das alturas
    return b_factor;
}

struct avl_node* right_right_rotation(struct avl_node *parent)
{
    struct avl_node *node1;//a folha principal da subarvore avl
    node1=parent->right;//a folha principal aponta para a sua filha a direita
    parent->right = node1->left;//a filha da direita aponta para a folha central
    node1->left= parent;//a folha central para a ficar no lado esquerdo e a antiga filha da direita para a ser a folha central
    return node1;
}
struct avl_node* left_left_rotation (struct avl_node *parent)//contrario de right right rotation
{
    struct avl_node *node1;
    node1 = parent->left;
    parent ->left = node1->right;
    node1 ->right = parent;
    return node1;
}
struct avl_node* right_left_rotation( struct avl_node *parent)//a ultima folha passa a ser a central
{
    struct avl_node *node1;//folha central
    node1=parent->right;//a folha central aponta para a filha a direita
    parent->right = left_left_rotation(node1);//a filha da direita passa apontar para sua filha a esquerda
    return right_right_rotation(parent);//a folha central passa a apontar para a ultima folha, e esta vira folha central
}
 struct avl_node* left_right_rotation(struct avl_node *parent)//a ultima folha passa a ser a central
{
    struct avl_node *node1;//folha central
    node1= parent->left;//a folha central aponta para a filha a esquerda
    parent->left = right_right_rotation(node1);//a filha a esquerda passa a apontar para a sua filha a direita
    return left_left_rotation(parent);//a folha central passa a apontar para a ultima folha, e esta vira folha central
}

struct avl_node* balancing(struct avl_node *node)//funcao que vai decidir qual rotacao vai ser feita
{//vai verificar uma subarvore avl com tres niveis
    int b_f= get_diff(node);//vai verificar para qual lado da arvore esta desequilibrada. Desequilibrio sempre ocorre quando a diferença de altura >1
    if (b_f >1) {//problema de balanceamento
        if (get_diff(node->left) >0)//se for positivo a rotacao sera esquerda, pois em get diff altura esq- dir
            node=left_left_rotation(node);
        else
            node=left_right_rotation(node);//se for negativo a rotacao sera esquerda direita
    }
    else if(b_f < -1) {//negativo problema na direita
        if(get_diff(node ->right) >0)//problema na esquerda
            node=right_left_rotation(node);
        else//problema na direita
            node=right_right_rotation(node);
    }
    return node;
    }

struct avl_node* insertAvlTree(struct avl_node *root,int val)
{
    if (root==NULL) {
        root = (struct avl_node*) malloc(sizeof(struct avl_node));
        root -> data = val;
        root -> left = NULL;
        root -> right = NULL;
        return root;
    }
    else if (val < root->data) {
        root->left = insertAvlTree(root->left, val);
        root=balancing(root);
    }
    else if (val > root->data) {
        root->right = insertAvlTree(root->right, val);
        root=balancing(root);
    }
    return root;
}


void gotoxy(int x, int y){
     COORD coord;
     HANDLE handle;
     handle = GetStdHandle(STD_OUTPUT_HANDLE);
     coord.X = x;
     coord.Y = y;
     SetConsoleCursorPosition(handle, coord);
}

void desenhaNivel(struct avl_node *p, int col, int lin, int desloc){

  if (p == NULL) return;
  gotoxy(col, lin);
  printf("(%d)\n", p->data);
  if (p->left != NULL)
     desenhaNivel(p->left, col - desloc, lin + 2, desloc / 2 + 1);
  if (p->left != NULL)
     desenhaNivel(p->right, col + desloc, lin + 2, desloc / 2 + 1);
}
void inorder(struct avl_node *tree)
{
    if(tree == NULL)
        return;
    else {
         inorder(tree -> left);
         printf("(%d)\t",tree ->data);
         inorder(tree ->right);
    }
}
void preorder(struct avl_node *tree)
{
    if(tree == NULL)
        return;
    else {
        printf("(%d)\t", tree ->data);
        preorder(tree ->left);
        preorder(tree ->right);
    }
}
void postorder(struct avl_node *tree)
{
    if(tree == NULL)
        return;
    else {
        postorder(tree ->left);
        postorder(tree ->right);
        printf("(%d)\t",tree ->data);
    }
}
int emptyAvlTree(struct avl_node *avlTreeTemp)//Verifica se a árvore está vazia
{
    return (avlTreeTemp == NULL);
}

int verifyValue(struct avl_node *avlTreeTemp, int wantedValueTemp)
{
    if(avlTreeTemp)
    {
        if(avlTreeTemp->data == wantedValueTemp) return 1;

        else
        {
            if(avlTreeTemp->data < wantedValueTemp)
                return verifyValue(avlTreeTemp->right,wantedValueTemp);
            else
                return verifyValue(avlTreeTemp->left,wantedValueTemp);
        }
    return 0;
    }

}
void ImprimirVetorPrincipalb(int *vetorTemp)//Imprime vetor;
{
    int i;

    system(LimpaTela);

    printf("Vetor:\n\n");

    for(i = 0; i < TamanhoVetorPrincial; i++)
    {
        printf("%d\t",vetorTemp[i]);
    }

    printf("\n\n\nImpress%co realizada com sucesso!!!\n\n\n",198);

    system("PAUSE");
}
//*******************************************************************************************************************************
void menuArvoreBinaria(int *vetorTemp)//Menu Principal
{
    system(LimpaTela);

    int i, opcaoSwitch;
    int wantedValue;//Valor a ser procurado no case 1
    int answerValue;
    struct avl_node *avlTree = NULL;

    double ti,tf,tempo; // ti = tempo inicial // tf = tempo final
    ti = tf = tempo = 0;
    struct timeval tempo_inicio,tempo_fim;

    gettimeofday(&tempo_inicio,NULL);
    for(i = 0; i < TamanhoVetorPrincial; i++)
    {
        avlTree = insertAvlTree(avlTree, vetorTemp[i]);

    }
    Sleep(1000);
    gettimeofday(&tempo_fim,NULL);

    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));
    tempo = ((tf - ti) / 1000) - 1000;

    printf("\n\n%crvore bin%cria inicializada com sucesso\n\n",181,160);
    printf("O tempo gasto para inicializar todos os elementos na %crvore foi de:\t\nTempo = %.9f",160,tempo);
    printf("\n\n\nAperte qualquer tecla para acessar o menu da %crvore bin%cria.\n\n\n",160,160);
    getch();

    do{

    system(LimpaTela);

    printf(">>>Menu %cvore Bin%caria<<<\n\n",181,160);
    printf("1 - Consultar um valor na %cvore bin%cria.\n",160,160);
    printf("2 - Imprimir por n%cvel.\n",161);
    printf("3 - Imprimir em pr%c-ordem.\n",130);
    printf("4 - Imprimir em ordem.\n");
    printf("5 - Imprimir em p%cs-ordem.\n",162);
    printf("6 - Vetor que geral inicialmente.\n");
    printf("0 - Voltar ao menu principal.\n");
    printf("\nInsira a op%c%co desejada: ",135,198); scanf("%d",&opcaoSwitch);


    switch(opcaoSwitch)
    {
        case 1://Consultar um valor na árvore binária
            system(LimpaTela);
            int wantedValue;//Valor procurado

                printf("Insira o elemento procurado: "); scanf("%d",&wantedValue);

                printf("\n\nProcessando...");

                gettimeofday(&tempo_inicio,NULL);

                answerValue = verifyValue(avlTree,wantedValue);

                Sleep(1000);
                gettimeofday(&tempo_fim,NULL);
                tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
                ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

                tempo = ((tf - ti) / 1000) - 1000;

                if(answerValue == 1) printf("\n\nValor encontrado!\n\n");

                else printf("\n\nValor n%co encontrado!\n\n",198);

                printf("O tempo necess%crio para encontrar o valor na %cvore bin%cria foi de:\nTempo = %.9f",160,160,160,tempo);
                getch();
        break;
        case 2://Imprimir por nível
            system(LimpaTela);
            desenhaNivel(avlTree, 1250, 2, 600);//col/linha/desl
            system("PAUSE");
        break;
        case 3://imprimir em pós-ordem
            system(LimpaTela);
            printf("%cvore Bin%cria em p%cs-ordem:\n\n",181,160,130);
            preorder(avlTree);
            getch();
        break;
        case 4://Imprimir em ordem
            system(LimpaTela);
            printf("%crvore Bin%cria em-ordem\n\n",181,160);
            inorder(avlTree);
            getch();
        break;
        case 5://Imprimir em pós-ordem
            system(LimpaTela);
            printf("%cvore Bin%cria em p%cs-order\n\n",181,160,162);
            postorder(avlTree);
            getch();
        break;
        case 0://Voltar para o menu principal
            system(LimpaTela);
            printf("\n\nVoc%c optou por sair do menu de %crvores bin%crias.\n\n\n",136,160,160);
            getch();
        break;
        case 6:
            system(LimpaTela);
            ImprimirVetorPrincipalb(vetorTemp);
            break;
        default:
            system(LimpaTela);
            printf("\n\nVoc%c digitou uma op%c%co inv%clida, tente novamente...\n",136,135,198,160);
        break;
    }
    }while(opcaoSwitch != 0);//
    system("PAUSE");
}
#endif // BINARYTREE_H_INCLUDED
