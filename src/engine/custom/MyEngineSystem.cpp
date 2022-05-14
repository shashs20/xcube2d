#include "MyEngineSystem.h"
#include <SDL_mixer.h>
#include <SDL.h>

int MyEngineSystem::sound(int argc, char **argv) {

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	Mix_Music* bgm = Mix_LoadMUS("bgm.mp3");
	Mix_Chunk* Soundeffect = Mix_LoadWAV("applaud.mp3");

	Mix_PlayMusic(bgm, -1);

	Mix_CloseAudio();
	Mix_FreeMusic(bgm);
	Mix_FreeChunk(Soundeffect);
	SDL_Quit;

	return 0;
}
