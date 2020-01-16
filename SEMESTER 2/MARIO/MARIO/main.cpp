#include "Main.h"

void CloseSDL();
bool InitSDL();
void Draw();
void Update();

SDL_Window* gWindow = NULL;

bool quit = false;

int main(int argc, char* agrs[])
{
	frame = 0;
	fpsTimer.start();
	//Game Loop
	if (InitSDL())
	{
		while (!quit)
		{
			capTimer.start();
			Update();
		}
	}
	
	CloseSDL();
	return 0;
}

void CloseSDL()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	IMG_Quit();
	SDL_Quit();
}

void Draw() 
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, NULL);
	SDL_FillRect(SDL_GetWindowSurface(gWindow), NULL, SDL_MapRGB(SDL_GetWindowSurface(gWindow)->format, 0, 0, 0));
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}

bool InitSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL Did Not Initialise. Error: " << SDL_GetError();
		return false;
	}
	else
	{
		gWindow = SDL_CreateWindow("GAEM",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Window Was Not Created. Error: " << SDL_GetError();
			return false;
		}
	}

	renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	return true;
}

void Update()
{
	//Event Handler
	SDL_Event e;
	SDL_PollEvent(&e);
	switch (e.type)
	{
	case SDL_QUIT:
		quit = true;
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			quit = true;
			return;
		case SDLK_w:
			rect.y = rect.y - speed;
			break;
		case SDLK_s:
			rect.y = rect.y + speed;
			break;
		case SDLK_d:
			rect.x = rect.x + speed;
			break;
		case SDLK_a:
			rect.x = rect.x - speed;
			break;
		}
	}
	float avgFPS = frame / (fpsTimer.getTicks() / 1000.f);
	if (avgFPS > 2000000)
	{
		avgFPS = 0;
	}
	int frameTicks = capTimer.getTicks();
	if (frameTicks < SCREEN_TICKS_PER_FRAME)
	{
		SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
	}
	Draw();
	return;
}