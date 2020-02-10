#include "CharacterLuigi.h"

CharacterLuigi::CharacterLuigi(SDL_Renderer* renderer, std::string imagePath, Vector2D startPosition, LevelMap* map) : Character(renderer, imagePath, startPosition, map)
{
	mRenderer = renderer;
}

CharacterLuigi::~CharacterLuigi()
{
	delete  mRenderer;
	mRenderer = NULL;
}

void CharacterLuigi::Update(float deltaTime, SDL_Event e)
{
	Character::Update(deltaTime, e);
	//Player Input
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			mMovingLeft = true;
			break;
		case SDLK_d:
			mMovingRight = true;
			break;
		case SDLK_w:
			Jump();
			break;
		}

		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			mMovingLeft = false;
			break;
		case SDLK_d:
			mMovingRight = false;
			break;
		}
		break;
	}
}

void CharacterLuigi::Render()
{
	Character::Render();
}
