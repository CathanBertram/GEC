#include <iostream>
#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include "PowBlock.h"

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
	mLevelMap = NULL;
}

GameScreenLevel1::~GameScreenLevel1()
{
	mBackgroundTexture = NULL;
	delete mario;
	mario = NULL;
	delete luigi;
	luigi = NULL;
	delete mPowBlock;
	mPowBlock = NULL;
}

void GameScreenLevel1::Render()
{
	mBackgroundTexture->Render(Vector2D(0, mBackgroundYPos), SDL_FLIP_NONE, mBackgroundYPos);
	mario->Render();
	luigi->Render();
	mPowBlock->Render();
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	if (mScreenshake)
	{
		ShakeScreen(deltaTime);
	}
	mPos = mario->GetPosition();
	lPos = luigi->GetPosition();
	mario->Update(deltaTime, e);
	luigi->Update(deltaTime, e);
	/*if (Collisions::Instance()->Circle(Circle2D(mario->GetCollisionRadius(), mario->GetPosition()), Circle2D(luigi->GetCollisionRadius(), luigi->GetPosition())))
	{
		mario->SetPosition(mPos);
		luigi->SetPosition(lPos);
	}*/
	if (Collisions::Instance()->Box(mario->GetCollisionBox(), luigi->GetCollisionBox()))
	{
		mario->SetPosition(mPos);
		luigi->SetPosition(lPos);
	}
	UpdatePowBlock();
}

void GameScreenLevel1::UpdatePowBlock()
{
	if (Collisions::Instance()->Box(mario->GetCollisionBox(), mPowBlock->GetCollisionBox()))
	{
		if (mPowBlock->IsAvailable())
		{
			if (mario->IsJumping())
			{
				DoScreenshake();
				mPowBlock->TakeAHit();
				mario->CancelJump();
			}
		}
	}
	if (Collisions::Instance()->Box(luigi->GetCollisionBox(), mPowBlock->GetCollisionBox()))
	{
		if (mPowBlock->IsAvailable())
		{
			if (luigi->IsJumping())
			{
				DoScreenshake();
				mPowBlock->TakeAHit();
				luigi->CancelJump();
			}
		}
	}
}

bool GameScreenLevel1::SetUpLevel()
{
	mBackgroundTexture = new Texture2D(mRenderer);
	if (!mBackgroundTexture->LoadFromFile("Images/BackgroundMB.png"))
	{
		std::cout << "Failed to load background texture!";
		return false;
	}
	SetLevelMap();
	mario = new CharacterMario(mRenderer, "Images/MarioSheet.png", Vector2D(64, 330), mLevelMap);
	luigi = new CharacterLuigi(mRenderer, "Images/LuigiSheet.png", Vector2D(448, 330), mLevelMap);
	mPowBlock = new PowBlock(mRenderer, mLevelMap);
	mScreenshake = false;
	mBackgroundYPos = 0.0f;
	return false;
}

void GameScreenLevel1::SetLevelMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									{ 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
									{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									{ 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0 },
									{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
									{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									{ 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
									{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
	if (mLevelMap != NULL)
	{
		delete mLevelMap;
	}
	mLevelMap = new LevelMap(map);
}
