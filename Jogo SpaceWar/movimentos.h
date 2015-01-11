#include <allegro.h>

void movimento(int *x1, int *y1)
{
     //movimentos da nave
     if ( key[KEY_UP] )
      {
         *y1-=1;  
      }
      if ( key[KEY_DOWN] )
      {
         *y1+=1; 
      }
      if ( key[KEY_LEFT] )
      {
         *x1-=1;
      }
      if ( key[KEY_RIGHT] )
      {
         *x1+=1;
      }
     //limites da nave na tela
     if(*x1<0)
          {
                  *x1=0;
                  }  
          if(*y1<0)
          {
                  *y1=0;
                  }
          if(*x1>595)
          {
                    *x1=595;
                    }
          if(*y1>421)
          {
                    *y1=421;
                    }
     }
