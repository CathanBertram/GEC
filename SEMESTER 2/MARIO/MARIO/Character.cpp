#include "Character.h"
#include "Texture2D.h"

Character::Character(SDL_Renderer* renderer, std::string imagePath, Vector2D startPosition)
{
	mRenderer = renderer;
	mTexture = new Texture2D(mRenderer);
	mTexture->LoadFromFile(imagePath);
	mPosition = startPosition;
	mFacingDirection = FACING_RIGHT;
	mMovingLeft = false;
	mMovingRight = false;
	speed = 100;
}

Character::~Character()
{
	mRenderer = NULL;
}

void Character::Render()
{
	if (mFacingDirection==FACING_RIGHT)
	{
		mTexture->Render(mPosition, SDL_FLIP_NONE);
	}
	if (mFacingDirection == FACING_LEFT)
	{
		mTexture->Render(mPosition, SDL_FLIP_HORIZONTAL);
	}
}

void Character::Update(float deltaTime, SDL_Event e)
{
	//Adds Gravity Force
	AddGravity(deltaTime);
	
	//Jump Force Change
	if (mJumping)
	{
		//Adjust Position
		mPosition.y -= mJumpForce * deltaTime;

		//Reduce Jump Force
		mJumpForce -= JUMP_FORCE_DECREMENT * deltaTime;

		//Check If Jump Force = 0
		if (mJumpForce <= 0.0f)
		{
			mJumping = false;
		}
	}

	//Changes Character Direction
	if (mMovingLeft)
	{
		MoveLeft(deltaTime);
	}
	else if (mMovingRight)
	{
		MoveRight(deltaTime);
	}

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
void Character::SetPosition(Vector2D newPosition)
{
	mPosition = newPosition;
}

Vector2D Character::GetPosition()
{
	return mPosition;
}

void Character::Jump()
{
	if (!mJumping)
	{
		mJumpForce = INITIAL_JUMP_FORCE;
		mJumping = true;
		mCanJump = false;
	}
}

void Character::AddGravity(float deltaTime)
{
	if (mPosition.y < SCREEN_HEIGHT - 42)
	{
	mPosition.y += gravity*deltaTime;
	}
	else
	{
		mCanJump = true;
	}
}

void Character::MoveLeft(float deltaTime)
{
	mFacingDirection = FACING_LEFT;
	mPosition.x -= speed* deltaTime;
}

void Character::MoveRight(float deltaTime)
{
	mFacingDirection = FACING_RIGHT;
	mPosition.x += speed* deltaTime;
}
