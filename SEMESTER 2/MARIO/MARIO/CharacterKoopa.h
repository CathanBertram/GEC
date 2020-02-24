#pragma once
#include "Character.h"
class CharacterKoopa : public Character
{
public:
	CharacterKoopa(SDL_Renderer* renderer, std::string imagePath, Vector2D startPosition, LevelMap* map, FACING startFace, float movementSpeed);
	~CharacterKoopa();

	void TakeDamage();
	void Jump();

	void Update(float deltaTime, SDL_Event e);
	void Render();

	bool GetAlive();
	void SetAlive(bool alive);

private:
	bool mInjured;
	float mInjuredTime;

	void FlipRightWayUp();
	void Flip();

	const int cKoopaFrameTime = 2;
};

