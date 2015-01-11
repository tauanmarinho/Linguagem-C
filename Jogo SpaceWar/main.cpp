#include <allegro.h>
#include "abertura.h"
#include "musica.h"
#include "movimentos.h"
#include "higherscore.h"
#include "pause.h"


 // Variável Global 
int Pause = 0;
int count = 0; 

// Função para o timer
void Conta()
{
   count++;
}
END_OF_FUNCTION(Conta);
LOCK_FUNCTION(Conta);
LOCK_VARIABLE(count);

int main() {
	allegro_init ();
    install_keyboard ();
    install_mouse();
    install_sound (DIGI_AUTODETECT,MIDI_AUTODETECT, NULL);
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
    set_window_title("Space War");
    
     
	int x2,i;
	int x3, x4;
	int y = 0;
	int b = 0;
	int s = 0;
	int vida=0;
	int vida1=0;
	int vida2 = 0;
	int a1=0;
	int a2=0;
	int a3=0;
	int x5,x6;
	int y5=0;
	int y6=0;
	int vidas=10;
    int vid=10;
            int x1=320;
          int y1=480;
          BITMAP *imagem[8];
          BITMAP *buffer=NULL;
                   
          buffer = create_bitmap(640,480);
        
         music();//chamando musica   
         menu();//chamando a funcao de abertura

        //asteroide1
        imagem[0] = load_bitmap("asteroide3.bmp", NULL);
        x3=rand()%(SCREEN_W);

        //asteroide2
        imagem[1] = load_bitmap("asteroide4.bmp", NULL);
        x2=10+rand()%(SCREEN_W);
        
        //asteroide3/4/5
        imagem[4] = load_bitmap("asteroide0.bmp", NULL);
        x4=20+rand()%(SCREEN_W);
        
        //mapa
        imagem[2] = load_bitmap("mapa1.bmp", NULL);
        
        //Nave
        imagem[3] = load_bitmap("naves.bmp", NULL);
        
        //Nave destroida
        imagem[5] = load_bitmap("navestiro.bmp", NULL);
        
        //Explosão do asteroide
        imagem[6] = load_bitmap("explosao.bmp",NULL);
        
        //coração
        imagem[7] = load_bitmap("coracao.bmp",NULL);
        
        //tiro
        imagem[8] = load_bitmap("tiro.bmp",NULL);
         bool verd=true;//novo

	    while (!key[KEY_ESC]) {
          
          int x=0;
          int j=10;
          int r=0;
          int t=0;
          
          if(verd==false)//novo
          {
               verd=true;
                         }
          if(key[KEY_SPACE])
          {
          //pause  
            remove_int(Conta);       
        pause();
        install_int(Conta, 1000);
      
        }                 
        //mapa  
        draw_sprite(buffer, imagem[2], 0,0);
          
        //asteroide1
        draw_sprite(buffer, imagem[0], x3,y++);
        if (y==500){
        y = 0;
        x3=20+rand()%(SCREEN_W);
        } 
         
        //astereiode2
        draw_sprite(buffer, imagem[1], x2,b++);
        if (b==550){
        b = 0;
        x2=10+rand()%(SCREEN_W);
        } 
        
        //asteroide3
        draw_sprite(buffer, imagem[4], x4,s++);
        if (s==520){
        s = 0;
        x4=40+rand()%(SCREEN_W);
        }
        
        //asteroide4
        draw_sprite(buffer, imagem[4], x5,y5++);
         if (y5==590){
        y5 = 0;
        x5=140+rand()%(SCREEN_W);
        }
        
        //asteroide5
        draw_sprite(buffer, imagem[4], x6,y6++);
         if (y6==580){
        y6 = 0;
        x6=90+rand()%(SCREEN_W);
        }
 
        //Nave
        draw_sprite(buffer, imagem[3], x1,y1);  
      
        //limites/movimento
        movimento(&x1,&y1);
        
         if ( key[KEY_W] )//tipo 1
         {     
         line(buffer ,x1+22 ,y1, x1+22,0 ,makecol(255,0,0) ); //tiro laser
         if(((x1+22)>x2)&&((x1+22)<(x2+27)))             //baseado em centro de massa do tiro
         {
         draw_sprite(buffer, imagem[6], x2,b);
         b=0;
         x2=200+rand()%(SCREEN_W);
                   a1+=1;   //acertos  asteroide 2
                               }
         if(((x1+22)>x3)&&((x1+22)<(x3+36)))
         {
         draw_sprite(buffer, imagem[6], x3,y);
         y=0; 
         x3=20+rand()%(SCREEN_W);
                   a2+=1;  //acertos asteroide 1
                     } 
         if(((x1+22)>x4)&&((x1+22)<(x4+32)))
         {
         draw_sprite(buffer, imagem[6], x4,s);
         s = 0;
         x4=100+rand()%(SCREEN_W);
                   a3+=1;//acertos asteroide 3
         }
         if(((x1+22)>x5)&&((x1+22)<(x5+32)))
         {
         draw_sprite(buffer, imagem[6], x5,y5);
         y5 = 0;
         x5=130+rand()%(SCREEN_W);
                   a3+=1;//acertos asteroide 4
         }
         if(((x1+22)>x6)&&((x1+22)<(x6+32)))
         {
         draw_sprite(buffer, imagem[6], x6,y6);
         y6 = 0;
         x6=130+rand()%(SCREEN_W);
                   a3+=1;//acertos asteroide 5
         }
         }
         //colisao
         if(((x2>=x1)&&(x2<=(x1+45))&&(b<=(y1+59))&&(b>=y1))||(((x2+27)>=x1)&&((x2+27)<=(x1+45))&&((b+25)<=(y1+59))&&((b+25)>=y1)))//asteroide2
         {
         draw_sprite(buffer, imagem[5], x1,y1);                                                                                                                             
         vida+=1;          
         }
         if(((x3>=x1)&&(x3<=(x1+45))&&(y<=(y1+59))&&(y>=y1))||(((x3+36)>=x1)&&((x3+36)<=(x1+45))&&((y+36)<=(y1+59))&&((y+36)>=y1)))//asteroide1
         {
         draw_sprite(buffer, imagem[5], x1,y1);
         vida1+=1;           
         }
         if(((x4>=x1)&&(x4<=(x1+45))&&(s<=(y1+59))&&(s>=y1))||(((x4+32)>=x1)&&((x4+32)<=(x1+45))&&((s+31)<=(y1+59))&&((s+31)>=y1)))//asteroide3
         {
         draw_sprite(buffer, imagem[5], x1,y1);                                                                                                                           
         vida2+=1;           
         }
         if(((x5>=x1)&&(x5<=(x1+45))&&(y5<=(y1+59))&&(y5>=y1))||(((x5+32)>=x1)&&((x5+32)<=(x1+45))&&((y5+25)<=(y1+59))&&((y5+31)>=y1)))//asteroide4
         {
         draw_sprite(buffer, imagem[5], x1,y1);                                                                                                                             
         vida2+=1;          
         }
         if(((x6>=x1)&&(x6<=(x1+45))&&(y6<=(y1+59))&&(y6>=y1))||(((x6+32)>=x1)&&((x6+32)<=(x1+45))&&((y6+25)<=(y1+59))&&((y6+31)>=y1)))//asteroide4
         {
         draw_sprite(buffer, imagem[5], x1,y1);                                                                                                                             
         vida2+=1;          
         }
         vid= vidas-((vida/59)+(vida1/59)+(vida2/59));       
         //game over
         if(vid==0 && verd==true)//novo
         {    
              for(t=0;t<10;t++)
         {
              draw_sprite(buffer, imagem[5], x1,y1);
              }                           
	     high(count);//reinicia
                verd=false;
                vida=0;
    	        vida1=0;
	            vida2 = 0;
	            b=0;
	            y=0;
	            s=0;
	            y5=0;
	            y6=0;
	            count = 0; 
	            a1=0;
	            a2=0;
	            a3=0;
	            x1=320;
	            y1=480;
              }
          //posição
          draw_sprite(buffer, imagem[7], 0,460);
          textprintf_ex( buffer, font, 12, 460, makecol(255,255,255), -1, "Vida: %d", vid);
          // Imprimindo o timer
          textprintf (buffer, font, 0, 0, makecol(255,255,255), "Tempo %ds", count);
          //imprimindo tiro
          draw_sprite(buffer, imagem[8], 0,450);
          textprintf_ex (buffer, font, 10, 450, makecol(255,255,255), -1, "Acertos: %d", (a1)+(a2)+(a3)); 
          blit (buffer,screen,0,0,0,0,SCREEN_W, SCREEN_W);
          install_int(Conta, 1000); // TIMER

          clear(buffer);
	}
	  destroy_bitmap(imagem[0]);
	  destroy_bitmap(imagem[1]);
	  destroy_bitmap(imagem[2]);
	  destroy_bitmap(imagem[3]);
      destroy_bitmap(imagem[4]);
      destroy_bitmap(imagem[5]);
      destroy_bitmap(imagem[6]);
      destroy_bitmap(imagem[7]);
      destroy_bitmap(imagem[8]);
	
	
	return 0;
}

END_OF_MAIN()
