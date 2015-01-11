#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

#define MAX_X 640
#define MAX_Y 480
#define V_MAX_X 0
#define V_MAX_Y 0
#define COLOR_BITS 32
#define VIDEO_CARD GFX_AUTODETECT_WINDOWED
#define DIGI_CARD DIGI_AUTODETECT
#define MIDI_CARD MIDI_AUTODETECT

//-------------------------------------------------------------------------
// FUNÇÕES PRINCIPAIS
int begin(void); 
void closing(void); 
void gameloop(void); 
volatile long int counter = 0;
void game_timer(void);
BITMAP *buffer;

int main(int argc, char **argv)
{
	if (!begin())
	{
		closing();
		return -1;
	}

	gameloop();

	closing();
	return 0;

}
END_OF_MAIN();

int begin(void)
{

	allegro_init();

	install_keyboard();
	install_mouse();

	install_timer();

	srand((unsigned)time(NULL));

	set_color_depth(COLOR_BITS);
	if (set_gfx_mode(VIDEO_CARD, MAX_X, MAX_Y, V_MAX_X, V_MAX_Y) < 0)
	{
		if (set_gfx_mode(GFX_AUTODETECT, MAX_X, MAX_Y, V_MAX_X, V_MAX_Y) < 0)
		{
			allegro_message("Erro ao inicializar o modo grafico");
			return (FALSE);
		}
	}

	if (COLOR_BITS == 32)	set_alpha_blender(); // instala o canal alpha (funciona apenas em 32 bits)

	if (install_sound(DIGI_CARD, MIDI_CARD, NULL) < 0)
	{
		if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) < 0)
		{
			allegro_message("Erro ao inicializar o som");
			return (FALSE);
		}
	}

	return (TRUE);
}

void game_timer(void)
{
    counter++;
}
END_OF_FUNCTION(game_timer);

void gameloop(void)
{
	LOCK_VARIABLE(counter);
	LOCK_FUNCTION(game_timer);
	install_int(game_timer, 1);
	buffer = create_bitmap(MAX_X,MAX_Y);
	clear(buffer);
	
	// Looping do Jogo-------------------------------
	do
	{
		
		textprintf_centre_ex(buffer,font, MAX_X/2, MAX_Y/2, makecol(counter%256,255 - (counter%256),0), -1,"tempo: %2.d : %2.d : %2.d ",counter/57600, (counter/960)%60, (counter/16)%60 );
		
		// Desenhando na tela (com Double Buffer)-------------------------
		blit(buffer, screen, 0, 0, 0, 0,MAX_X,MAX_Y);
		clear(buffer);
		
		if (key[KEY_ESC])    break;
	}while(1);
}


void closing(void)
{
	remove_timer();
	remove_mouse();
	remove_sound();
	remove_keyboard();
	allegro_exit();
}
