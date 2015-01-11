#include <allegro.h>
//#include "tela_higher.h"
#include <stdio.h>
#include <stdlib.h>
 
#define TAMANHO_TEXTO 20            // Tamanho do texto de entrada

int menu()
{
BITMAP *buffer=NULL;
BITMAP *buffer2=NULL;
BITMAP *inicio=NULL;
BITMAP *comandos=NULL;
BITMAP *rank=NULL;
BITMAP *sair=NULL;
BITMAP *cursor=NULL;
BITMAP *primeira=NULL;
BITMAP *highscore=NULL; // Novo ponteiro <----------------

BITMAP *highscore2=NULL; // Novo ponteiro <----------------

BITMAP *comandostela=NULL;
BITMAP *comandostela2=NULL;
int x= 300;
int y=405;
//arquivo
FILE *fp;
int m;
char texto[TAMANHO_TEXTO];

          
buffer2= create_bitmap( 640,480);
buffer= create_bitmap( 640,480);
primeira= load_bitmap ("primeira.bmp",NULL);
inicio= load_bitmap ("iniciar.bmp",NULL);  // x = 395  573  y= 314  335
comandos= load_bitmap ("comandos.bmp",NULL); // x = 490 571  y= 358 379
rank= load_bitmap ("rank.bmp",NULL);
sair= load_bitmap ("sair.bmp",NULL);
cursor= load_bitmap ("cursor1.bmp",NULL);

comandostela= load_bitmap ("comandostela.bmp",NULL);
comandostela2= load_bitmap ("comandostela2.bmp",NULL);

// Novos loads de imagem <----------------
highscore=load_bitmap ("highscore.bmp",NULL);
//gameover=load_bitmap ("gameover.bmp",NULL);
highscore2=load_bitmap ("highscore2.bmp",NULL);
          
bool saida = false;
bool coman = false;
bool higher = false; // Nova variável Booleana <----------------

while (saida==false && !key[KEY_ESC])
{    
      if (mouse_x > 498 && mouse_x < 596 && // Mudança "Inicio"
          mouse_y > 328 && mouse_y < 341)
      {  
       draw_sprite (buffer, inicio, 0,0);
       
       if (mouse_b & 1)
       {
                   saida = true;
                   }
       }else if(mouse_x > 386 && mouse_x < 601 && // Mudança "Comandos"
                mouse_y > 364 && mouse_y < 377)
                {                       
                draw_sprite (buffer, comandos, 0,0);
                if (mouse_b & 1)
                {
                 saida=true;
                 coman=true;
                 }              
                }else if(mouse_x > 511 && mouse_x < 598 && // Mudança "Rank"
                mouse_y > 400 && mouse_y < 414)
                {
                        
                draw_sprite (buffer, rank, 0,0);
                if (mouse_b & 1)
                {                        
                            higher=true;
                            saida=true;
                            }                  
                }else if(mouse_x > 511 && mouse_x < 595 && // Mudança "Sair"
                mouse_y > 432 && mouse_y < 445)
                {                      
                draw_sprite (buffer, sair, 0,0);
                if (mouse_b & 1)
                {
                         exit (1);
                            }                  
                }else  draw_sprite (buffer, primeira, 0,0);  // Página incial principal
                draw_sprite (buffer, cursor,mouse_x,mouse_y  );
                blit (buffer,screen,0,0,0,0,SCREEN_W, SCREEN_W);               
               }
if (coman==true )
{               
while (coman==true && !key[KEY_ESC] )
{
      blit (buffer,screen,0,0,0,0,SCREEN_W, SCREEN_W);
      draw_sprite (buffer, comandostela, 0,0);
      draw_sprite (buffer, cursor,mouse_x,mouse_y  );
      if (mouse_x > 173 && mouse_x < 617 && // Mudança "Comandos"
          mouse_y > 453 && mouse_y < 467)
      {  
       draw_sprite (buffer, comandostela2, 0,0);
       draw_sprite (buffer, cursor,mouse_x,mouse_y);
       if (mouse_b & 1)
       {
                   coman = false;
                   }
                   }
                   }
                   }
if (higher==true ) // Comandos para execução do Highscore <----------------
{           
while (higher==true && !key[KEY_ESC] )
{
      blit (buffer,screen,0,0,0,0,SCREEN_W, SCREEN_W); 
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
                   higher = false;
                   }
                   }
                   }
                   }            
      clear (buffer);
      blit (buffer,screen,0,0,0,0,SCREEN_W, SCREEN_W);
      destroy_bitmap(primeira);
	  destroy_bitmap(inicio);
	  destroy_bitmap(cursor);
	  destroy_bitmap(sair);
      destroy_bitmap(rank);
      destroy_bitmap(comandos);
      destroy_bitmap(comandostela);
      destroy_bitmap(comandostela2);
      destroy_bitmap(highscore2);
      destroy_bitmap(highscore);
   
  return 0;
     }


