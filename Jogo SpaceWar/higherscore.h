#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>


// Constantes


#define TELA_X 640                  // Largura da tela em pixels
#define TELA_Y 480                  // Altura da tela em pixels
#define CORES 32                    // Profundidade de cores
#define TAMANHO_TEXTO 20            // Tamanho do texto de entrada
#define BRANCO makecol(255,255,255) // Branco (255,255,255)


int high(int count) 
{
   
BITMAP *buffer=NULL;                 // Necessario para Double Buffering
char texto[TAMANHO_TEXTO];      // Armazena texto digitado
int indice = 0;                     // Indice para o texto digitado
int caracter;                   // Armazena um caracter lido

BITMAP *gameover=NULL;                    //game over
//arquivo
FILE *fp;
FILE *fpn;
char n[15];
int x;
BITMAP *highscore1=NULL; 

    // Cria o buffer para realizar Double Buffering
    buffer = create_bitmap(TELA_X, TELA_Y);

    fp=fopen("numero.txt","r+");
    fscanf(fp,"%i",&x);
    fclose(fp);
    while(!key[KEY_ENTER])
    {
        // Limpa o buffer
        clear(buffer);

if(count>x)
{
 // Imagem na Tela
    highscore1=load_bitmap ("bateurecord2.bmp",NULL);
        draw_sprite(buffer, highscore1, 0,0);
        
        while (keypressed())
        {
            //ler do buffer do teclado o valor da tecla  
            caracter = readkey();

            // A tecla BACKSPACE foi pressionada
            if ((caracter >> 8) == KEY_BACKSPACE) // Scancode
            {
                if (indice > 0) // O indice deve ser maior que 0
                    texto[--indice] = '\0'; // Apaga o caracter
            }
            else // se outra tecla foi pressionada
            {
                if (indice < TAMANHO_TEXTO)
                {
                    if ((caracter & 0xff) >= 32 && (caracter & 0xff) <= 126) // verificando se a tecla é valida
                        texto[indice++] = (caracter & 0xff); // ASCII
                }
            }
            }
        //nome no arquivo
        fpn=fopen("rank.txt","w+");
        fprintf(fpn,"%s",texto);
        fclose(fpn);
        fflush(stdin);
        textprintf_ex(buffer,font,150,286,BRANCO,-1," %s",texto);
        //pontos no arquivo 
        fpn=fopen("numero.txt","w+");
        fprintf(fpn,"%i",count);
        fclose(fpn);
        textprintf_ex(buffer,font,425,286,BRANCO,-1," %i",count);
        }
else
{
    gameover = load_bitmap("gameover.bmp", NULL);
    draw_sprite(buffer, gameover, 0,0);
    
}
 blit(buffer,screen,0,0,0,0,TELA_X,TELA_Y);
    }
destroy_bitmap(gameover);
destroy_bitmap(highscore1);
destroy_bitmap(buffer);
menu(); 
return 0;
}

