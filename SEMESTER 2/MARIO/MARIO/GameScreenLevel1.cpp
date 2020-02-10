#include <iostream>
#include "GameScreenLevel1.h"
#include "Texture2D.h"

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
}

void GameScreenLevel1::Render()
{
	mBackgroundTexture->Render(Vector2D(), SDL_FLIP_NONE);
	mario->Render();
	luigi->Render();
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
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
	mario = new CharacterMario(mRenderer, "Images/Mario.png", Vector2D(64, 330), mLevelMap);
	luigi = new CharacterLuigi(mRenderer, "Images/Luigi.png", Vector2D(448, 330), mLevelMap);
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
