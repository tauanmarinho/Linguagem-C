#include <allegro.h>

bool pause()
{
	int i = 1;
	BITMAP *pause;

	pause = load_bitmap("pause.bmp",NULL);

	while (!key[KEY_ENTER])
		{
    		draw_sprite(screen, pause,0,0);
		}
		
	if(i == 1){ return false;}
	else if (i == 0) {return true;}
		destroy_bitmap(pause);
}
