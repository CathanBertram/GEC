#pragma once
#include <SDL.h>
#include <iostream>
#include "Commons.h"

class Texture2D;

class Character
{
public:
	Character(SDL_Renderer* renderer, std::string imagePath, Vector2D startPosition);
	~Character();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

	void SetPosition(Vector2D newPosition);
	Vector2D GetPosition();
private:
	FACING mFacingDirection;
	bool mMovingLeft;
	bool mMovingRight;
	float speed;
	bool mJumping;
	bool mCanJump;
	float mJumpForce;
	const int JUMP_FORCE_DECREMENT = 1.0f;
	const int INITIAL_JUMP_FORCE = 400.0f;

	void Jump();
	void AddGravity(float deltaTime);
protected:
	SDL_Renderer* mRenderer;
	Vector2D mPosition;
	Texture2D* mTexture;
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
};

