#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <windows.h>
#include "BinaryTree.h"
#include "QuickSort.h"
#define RandomicoMaximo 100
#define LimpaTela "CLS"
#define TamanhoVetorPrincial 200
#define InicioVetorPrincipal 0
#define AmplitudeValoresAleatorios 1001//Tamanho da amplitude que se quer + 1

//Alunos:
//Carlos Roberto Remenche Junior
//Tauan Marinho
//Trabalho de projeto FINAL

//Opção III – Busca / Ordenação
//Fazer um programa em C para realizar a busca de um número em uma sequência de 200
//números aleatórios (que deve ser diferente a cada execução do programa). Esta busca deve ser
//feita de duas maneiras:
//
//1 – a função busca1()  deve simplesmente  procurar  o número  no vetor  de números
//aleatórios;
//
//2 – na funçao busca2(), deve-se criar uma árvore binária a partir do vetor de números
//aleatórios; este vetor deve ser ordenado previamente com o algoritmo quicksort. A cada inserção
//de elementos na árvore,  o balanceamento desta deve ser mantido (caso necessário, através de
//rotações). A busca do número deve ser realizada na árvore binária.
//
//Registre o tempo necessário para a operação de busca (e somente esta operação!) em
//cada execução das funções descritas  acima.  Compare  o melhor caso (um vetor ordenado de
//forma crescente), o pior caso (um vetor ordenado de forma decrescente) e o caso médio e tire
//suas conclusões.

void GeraVetorAleatorio(int *VetorPrincipalTemp);//Gera vetor principal aleatoriamente
void ImprimirVetorPrincipal(int *VetorTemp);
void busca1(int *VetorTemp);//Busca um valor no vetor principal de forma linear;
void busca2();
void ResetaVetorPrincipal(int *VetorPrincipalTemp);

int main()//Função main()principal
{
    int Option;//Opção do menu switch
    int *vetorPrincipal = NULL;
    int orderMode = 0;// 0 = desordenado 1 = ordenado

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD consoleSize;

    consoleSize.X = 2500; consoleSize.Y = 420;//tamanho da tela

    SetConsoleScreenBufferSize(console, consoleSize);

    do{
        system(LimpaTela);
        printf("PROJETO FINAL DE ESTRUTURA DE DADOS - IF63C\n\n");
        printf("Alunos: Carlos Roberto\n");
        printf("        Tauan Marinho\n");
        printf("\n\n");
        printf("1 - Gerar vetor de 200 espa%cos com n%cmeros aleat%crios no vetor.\n",135,163,162);
        printf("2 - Imprimir a lista gerada pela op%c%co anterior.\n",135,198);
        printf("3 - Procurar valor espec%cfico no vetor gerado aleat%criamente.(Usando busca1())\n",161,162);
        printf("4 - Procurar valor na %cvore bin%cria.(Usando busca2())\n",160,160);
        printf("5 - Ordena vetor principal atrav%cs do m%ctodo QuickSort.\n",130,130);
        printf("6 - Resetar vetor principal.\n");
        printf("0 - Sair\n\n\n");

        printf("Insira a op%c%co desejada: ",135,198); scanf("%d",&Option);

    switch(Option)
    {
      case 1://Gera vetor com valores aleatório
        system(LimpaTela);
        vetorPrincipal = malloc(TamanhoVetorPrincial * sizeof(int));
        GeraVetorAleatorio(vetorPrincipal);
        orderMode = 0;
        break;

    case 2://Imprime vetor;
        system(LimpaTela);
        if(vetorPrincipal == NULL)
        {
            printf("\n\nO vetor principal ainda n%co foi criado...\n\n\n",198);
            getch();
            break;
        }
        ImprimirVetorPrincipal(vetorPrincipal);
        break;

    case 3://realiza busca1();
        system(LimpaTela);
        if(vetorPrincipal == NULL)
        {
            printf("\n\nO vetor principal ainda n%co foi criado...\n\n\n",198);
            getch();
            break;
        }
        busca1(vetorPrincipal);
        break;

    case 4://Realiza busca2();

        if((vetorPrincipal == NULL)||(orderMode == 0))
        {
            system(LimpaTela);
            printf("\n\nO vetor principal ainda n%co foi criado ou n%co est%c ordenado.\n\n\n",198,198,160);
            getch();
            break;
        }
        busca2(vetorPrincipal);
        break;

    case 5://Ordena vetor principal pelo QuickSort
        system(LimpaTela);
        if(vetorPrincipal == NULL)
        {
            printf("\n\nO vetor principal ainda n%co foi criado...\n\n\n",198);
            getch();
            break;
        }
        OrdenaQuickSort(vetorPrincipal,InicioVetorPrincipal, TamanhoVetorPrincial - 1);
        printf("\n\nAlgoritmo Ordenado com sucesso!!!\n\n\n");
        orderMode = 1;
        system("PAUSE");
        break;

    case 6://Zera vetor principal
        system(LimpaTela);
        if(vetorPrincipal == NULL)
        {
            printf("\n\nO vetor principal ainda n%co foi criado...\n\n\n",198);
            getch();
            break;
        }
        ResetaVetorPrincipal(vetorPrincipal);
        break;


    case 0:
        system(LimpaTela);
        printf("\n\nFIM\n\n\n\n");
        system("PAUSE");
        exit(0);

    default:
        system(LimpaTela);
        printf("\n\nVoc%c escolheu uma op%c%co inv%clida, tente novamente...",136,135,198,160);
        printf("\n\n");
        getch();
        break;
    }

    }while(Option != 0);

    system("PAUSE");
    return 0;
}

void GeraVetorAleatorio(int *vetorTemp)//Função do case 1, serve para gerar o vetor aleatório recebendo o ponteiro.
{
    srand(time(NULL));//Gera semente para melhorar a aleatoridade da função rand();
    double ti,tf,tempo; // ti = tempo inicial // tf = tempo final
    ti = tf = tempo = 0;
    struct timeval tempo_inicio,tempo_fim;
    int i;

    gettimeofday(&tempo_inicio,NULL);
    for(i = 0; i < TamanhoVetorPrincial ; i++)
    {
        vetorTemp[i] = rand() % AmplitudeValoresAleatorios;
    }
    Sleep(1000);
    gettimeofday(&tempo_fim,NULL);

    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = ((tf - ti) / 1000) - 1000;

    printf("Tempo necess%crio para gerar os valores aleat%crios: %.9f",160,162,tempo);
    printf("\nVetor gerado com sucesso!!!\n\n");

    system("PAUSE");
}

void ImprimirVetorPrincipal(int *vetorTemp)//Imprime vetor;
{
    int i;

    system(LimpaTela);

    printf(">>>>>>>>>>   Vetor:   <<<<<<<<<<\n\n");

    for(i = 0; i < TamanhoVetorPrincial; i++)
    {
        printf("%d\t",vetorTemp[i]);
    }

    printf("\n\n\nImpress%co realizada com sucesso!!!\n\n\n",198);

    system("PAUSE");
}
void busca1(int *vetorTemp)//Busca linear no vetor para satisfazer o critério do enunciado
{
    int i, NumeroProcurado, Contador = 0;
    double ti,tf,tempo; // ti = tempo inicial // tf = tempo final
    ti = tf = tempo = 0;
    struct timeval tempo_inicio,tempo_fim;


    printf("Insira o valor que voc%c deseja procurar no vetor principal: ",136); scanf("%d", &NumeroProcurado);

    gettimeofday(&tempo_inicio,NULL);
    for(i = 0; i < TamanhoVetorPrincial; i++)
    {
        if(NumeroProcurado == vetorTemp[i])
            Contador++;
    }
    Sleep(1000);
    gettimeofday(&tempo_fim,NULL);

    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = ((tf - ti) / 1000) - 1000;

    printf("\n\nO n%cmero procurado aparece %d vezes.\n\n\n",163,Contador);
    printf("O tempo necess%crio para buscar o valor foi de %.9f\n\n\n",160,tempo);

    system("PAUSE");
}
void busca2(int *vetorTemp) //Busca que ocorrerá no menu da busca binária
{
    menuArvoreBinaria(vetorTemp);
}
void ResetaVetorPrincipal(int *VetorPrincipalTemp)
{
    int i;

    if(VetorPrincipalTemp == NULL)
    {
        printf("O vetor que voc%c est%c tentando imprimir est%c vazio.",136,160,160);
    }
    else
    {
        for(i = 0 ; i < TamanhoVetorPrincial ; i++)
        {
            VetorPrincipalTemp[i] = 0;
        }

    printf("\nVetor zerado com sucesso!!!\n\n\n");
    }


    system("PAUSE");
}

