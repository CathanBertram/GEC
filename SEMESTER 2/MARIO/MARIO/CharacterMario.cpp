#include "CharacterMario.h"

CharacterMario::CharacterMario(SDL_Renderer* renderer, std::string imagePath, Vector2D startPosition, LevelMap* map) : Character(renderer, imagePath, startPosition, map)
{
	mRenderer = renderer;
}

CharacterMario::~CharacterMario()
{
	delete  mRenderer;
	mRenderer = NULL;
}

void CharacterMario::Update(float deltaTime, SDL_Event e) 
{
	Character::Update(deltaTime, e);
	//Player Input
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			mMovingLeft = true;
			break;
		case SDLK_RIGHT:
			mMovingRight = true;
			break;
		case SDLK_UP:
			Jump();
			break;
		}

		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			mMovingLeft = false;
			break;
		case SDLK_RIGHT:
			mMovingRight = false;
			break;
		}
		break;
	}
}

void CharacterMario::Render()
{
	Character::Render();
}
