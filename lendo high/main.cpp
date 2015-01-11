#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>


// Constantes


#define TELA_X 640                  // Largura da tela em pixels
#define TELA_Y 480                  // Altura da tela em pixels
#define CORES 32                    // Profundidade de cores
#define TAMANHO_TEXTO 20            // Tamanho do texto de entrada




// Globais


BITMAP *buffer=NULL;                 // Necessario para Double Buffering
char texto[TAMANHO_TEXTO];      // Armazena texto digitado
BITMAP *highscore=NULL;
//arquivo
FILE *fp;
int m;




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


    while(!key[KEY_ESC])
    {
        clear(buffer);

        fp=fopen("numero.txt","r+");
        fscanf(fp,"%i",&m);  
        fclose(fp);
 
        fp=fopen("rank.txt","r+");
        fscanf(fp,"%s",texto);
        fclose(fp);
                   
                   highscore= load_bitmap ("highscore.bmp",NULL);
            draw_sprite(buffer, highscore, 0,0);
            textprintf_ex (buffer, font, 145, 240, makecol(155,255,255), -1, " %s                             %i", texto, m); 
               
               blit(buffer,screen,0,0,0,0,TELA_X,TELA_Y);  
               
}
    destroy_bitmap(buffer);
    destroy_bitmap(highscore);
    allegro_exit();
    return 0;
}
END_OF_MAIN();
