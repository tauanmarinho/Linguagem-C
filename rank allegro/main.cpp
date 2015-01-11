#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>


// Constantes


#define TELA_X 640                  // Largura da tela em pixels
#define TELA_Y 480                  // Altura da tela em pixels
#define CORES 32                    // Profundidade de cores
#define TAMANHO_TEXTO 20            // Tamanho do texto de entrada
#define BRANCO makecol(255,255,255) // Branco (255,255,255)


// Globais


BITMAP *buffer;                 // Necessario para Double Buffering
char texto[TAMANHO_TEXTO];      // Armazena texto digitado
int indice;                     // Indice para o texto digitado
int caracter;                   // Armazena um caracter lido
//arquivo
FILE *fp;
FILE *fpn;
int count=10;
char n[15];
int x;


int main() 
{
    // Inicializa o Allegro
    if (allegro_init())
        return 1;


    // Configura a profundidade de cores
    set_color_depth(CORES);

        
    // Configura o modo grafico
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, TELA_X, TELA_Y, 0, 0);


    // Instala o handler do teclado
    install_keyboard();


    // Cria o buffer para realizar Double Buffering
    buffer = create_bitmap(TELA_X, TELA_Y);


    // Loop principal

fp=fopen("numero.txt","r+");
fscanf(fp,"%i",&x);
fclose(fp);
    while(!key[KEY_ENTER])
    {
        // Limpa o buffer
        clear(buffer);


if(count>x)
{

        while (keypressed())
        {
            //ler do buffer do teclado o valor da tecla
            caracter = readkey();


            // A tecla BACKSPACE foi pressionada
            if ((caracter >> 8) == KEY_BACKSPACE) // Scancode
            {
                if (indice > 0) // O indice deve ser maior que 0!
                    texto[--indice] = '\0'; // Apaga o caracter
            }
            else // Outra tecla foi pressionada
            {
                if (indice < TAMANHO_TEXTO)
                {
                    if ((caracter & 0xff) >= 32 && (caracter & 0xff) <= 126) // Eh uma tecla valida?
                        texto[indice++] = (caracter & 0xff); // ASCII
                }
            }
        }

        
        //nome no arquivo
        textprintf_ex(buffer,font,0,0,BRANCO,-1,"Seu nome: %s",texto);
        fpn=fopen("rank.txt","w+");
        fprintf(fpn,"%s",texto);
        fclose(fpn);
        
        //pontos no arquivo
        textprintf_ex(buffer,font,0,10,BRANCO,-1,"Seu score: %i",count);
        fpn=fopen("numero.txt","w+");
        fprintf(fpn,"%i",count);
        fclose(fpn);
        }
else
{
    textprintf_ex(buffer,font,0,0,BRANCO,-1,"GAME OVER");
}
blit(buffer,screen,0,0,0,0,TELA_X,TELA_Y);
    }

    // Destroi buffer e termina o programa
    destroy_bitmap(buffer);
    allegro_exit();
    return 0;
}
END_OF_MAIN();
