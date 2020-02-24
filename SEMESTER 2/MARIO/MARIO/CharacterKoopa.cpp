#include "CharacterKoopa.h"

CharacterKoopa::CharacterKoopa(SDL_Renderer* renderer, std::string imagePath, Vector2D startPosition, LevelMap* map, FACING startFace, float movementSpeed) : Character(renderer, imagePath, startPosition, map)
{
	mFacingDirection = startFace;
	speed = movementSpeed;
	mPosition = startPosition;

	mInjured = false;

	mSingleSpriteWidth = mTexture->GetWidth() / 15;
	mSingleSpriteHeight = mTexture->GetHeight();
	slice = 1;
}

CharacterKoopa::~CharacterKoopa()
{
}

void CharacterKoopa::TakeDamage()
{
	mInjured = true;
	mInjuredTime = INJURED_TIME;
	Jump();
}

void CharacterKoopa::Jump()
{
	if (!mJumping)
	{
		mJumpForce = INITIAL_JUMP_FORCE_SMALL;
		mJumping = true;
		mCanJump = false;
		Flip();
	}
}

void CharacterKoopa::Update(float deltaTime, SDL_Event e)
{
	Character::Update(deltaTime, e);
	if (!mInjured)
	{
		if (mFacingDirection == FACING_LEFT)
		{
			mMovingLeft = true;
			mMovingRight = false;
		}
		else if (mFacingDirection == FACING_RIGHT)
		{
			mMovingLeft = false;
			mMovingRight = true;
		}
	}
	else
	{
		mMovingLeft = false;
		mMovingRight = false;

		mInjuredTime -= deltaTime;
		if (mInjuredTime <= 0)
		{
			FlipRightWayUp();
		}
	}
	if (mMovingLeft || mMovingRight)
	{
		frame += deltaTime * 10;
		if (frame > cKoopaFrameTime)
		{
			slice++;
			frame = 0;
		}
		if (slice >= 5)
		{
			slice = 1;
		}
	}

}

void CharacterKoopa::Render()
{
	int left = mSingleSpriteWidth * slice;
	SDL_Rect portionOfSpritesheet = { left, 0, mSingleSpriteWidth, mSingleSpriteHeight };
	SDL_Rect destRect = { (int)(mPosition.x),(int)(mPosition.y), mSingleSpriteWidth, mSingleSpriteHeight };

	if (mFacingDirection == FACING_RIGHT)
	{
		mTexture->Render(portionOfSpritesheet, destRect, SDL_FLIP_NONE);
	}
	if (mFacingDirection == FACING_LEFT)
	{
		mTexture->Render(portionOfSpritesheet, destRect, SDL_FLIP_HORIZONTAL);
	}
}

bool CharacterKoopa::GetAlive()
{
	return false;
}

void CharacterKoopa::SetAlive(bool alive)
{
}

void CharacterKoopa::FlipRightWayUp()
{
	mInjured = false;
	Jump();
}

void CharacterKoopa::Flip()
{
	if (mFacingDirection == FACING_LEFT)
	{
		mFacingDirection == FACING_RIGHT;
	}
	else if (mFacingDirection == FACING_RIGHT)
	{
		mFacingDirection == FACING_LEFT;
	}
}
