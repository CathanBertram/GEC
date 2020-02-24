#include "Character.h"
#include "Texture2D.h"

Character::Character(SDL_Renderer* renderer, std::string imagePath, Vector2D startPosition, LevelMap* map)
{
	mRenderer = renderer;
	mTexture = new Texture2D(mRenderer);
	mTexture->LoadFromFile(imagePath);
	mPosition = startPosition;
	mFacingDirection = FACING_RIGHT;
	mMovingLeft = false;
	mMovingRight = false;
	speed = 250;
	mCollisionRadius = 15.0f;
	mCurrentLevelMap = map;

	mSingleSpriteWidth = mTexture->GetWidth() / 12;
	mSingleSpriteHeight = mTexture->GetHeight();

	frame = 1;
}

Character::~Character()
{
	delete mRenderer;
	mRenderer = NULL;
}

void Character::Render()
{
	int left = mSingleSpriteWidth * slice;
	SDL_Rect portionOfSpritesheet = { left, 0, mSingleSpriteWidth, mSingleSpriteHeight };
	SDL_Rect destRect = { (int)(mPosition.x),(int)(mPosition.y), mSingleSpriteWidth, mSingleSpriteHeight };
	
	if (mFacingDirection==FACING_RIGHT)
	{
		mTexture->Render(portionOfSpritesheet, destRect, SDL_FLIP_HORIZONTAL);
	}
	if (mFacingDirection == FACING_LEFT)
	{
		mTexture->Render(portionOfSpritesheet, destRect, SDL_FLIP_NONE);
	}
}

void Character::Update(float deltaTime, SDL_Event e)
{
	int centralXPosition = (int)(mPosition.x + ((mTexture->GetWidth()/12) * 0.5f)) / TILE_WIDTH;
	int footPosition = (int)(mPosition.y + mTexture->GetHeight()) / TILE_HEIGHT;
	if (mCurrentLevelMap->GetTileAt(footPosition, centralXPosition)==0)
	{
	//Adds Gravity Force
	AddGravity(deltaTime);
	}
	else
	{
		mCanJump = true;
	}
	
	//Jump Force Change
	if (mJumping)
	{
		//Adjust Position
		mPosition.y -= mJumpForce * deltaTime;

		//Reduce Jump Force
		mJumpForce -= JUMP_FORCE_DECREMENT * deltaTime;

		if (gravity > mJumpForce)
		{
			mFalling = true;
		}
		//Check If Jump Force = 0
		if (mJumpForce <= 0.0f)
		{
			mJumping = false;
		}
	}
	else
	{
		mFalling = false;
	}

	//Changes Character Direction
	if (mMovingLeft)
	{
		moving = true;
		MoveLeft(deltaTime);
	}
	else if (mMovingRight)
	{
		moving = true;
		MoveRight(deltaTime);
	}
	else
	{
		moving = false;
	}

	if (mJumping && !mFalling)
	{
		slice = 5;
	}
	else if (mFalling)
	{
		slice = 6;
	}
	else if (moving == true)
	{
		frame += deltaTime * 10;
		if (frame > cFrameTime)
		{
			slice++;
			frame = 0;
		}
		if (slice >= 5)
		{
			slice = 1;
		}
	}
	else
	{
		frame = 0;
		slice = 0;
	}
	
}
float Character::GetCollisionRadius()
{
	return mCollisionRadius;
}

void Character::SetPosition(Vector2D newPosition)
{
	mPosition = newPosition;
}

Vector2D Character::GetPosition()
{
	return mPosition;
}

void Character::CancelJump()
{
	mJumpForce = 0.0f;
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
