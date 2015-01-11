#include <allegro.h>

void music(){
     //som
          MIDI *musica;
          musica=load_midi ("highwaytohell.mid");
           play_midi(musica,TRUE);
          }
