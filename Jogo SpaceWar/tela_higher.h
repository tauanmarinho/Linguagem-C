#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_TEXTO 20            // Tamanho do texto de entrada

 
void rank(bool *high)
{
BITMAP *buffer=NULL;
BITMAP *highscore=NULL; 
BITMAP *highscore2=NULL;
BITMAP *cursor=NULL;
int m;
char texto[TAMANHO_TEXTO];


        highscore= load_bitmap ("highscore.bmp",NULL);
        highscore2= load_bitmap ("highscore2.bmp",NULL);
        cursor= load_bitmap ("cursor1.bmp",NULL);
        
        buffer= create_bitmap( 640,480);
        FILE *fp;
        blit (buffer,screen,0,0,0,0,SCREEN_W, SCREEN_W); 

        draw_sprite (buffer, cursor,mouse_x,mouse_y  );
     
        fp=fopen("numero.txt","r+");
        fscanf(fp,"%i",&m);  
        fclose(fp);
 
        fp=fopen("rank.txt","r+");
        fscanf(fp,"%s",texto);
        fclose(fp);
        
      draw_sprite (buffer, highscore, 0,0);
      draw_sprite (buffer, cursor,mouse_x,mouse_y  );
      textprintf_ex (buffer, font, 145, 240, makecol(155,255,255), -1, " %s                             %i", texto, m);
      
      if (mouse_x > 179 && mouse_x < 451 && // Mudança HighScore"
          mouse_y > 407 && mouse_y < 430)
      {  
       draw_sprite (buffer, highscore2, 0,0);
       draw_sprite (buffer, cursor, mouse_x,mouse_y);
       textprintf_ex (buffer, font, 145, 240, makecol(155,255,255), -1, " %s                             %i", texto, m);
       
       if (mouse_b & 1)
       {
                   high = false;
                   }
                   }
                   }
                   


