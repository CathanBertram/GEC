#pragma once
#include <SDL.h>
#include "Commons.h"
#include "GameScreen.h"
#include "GameScreenLevel1.h"
#include "Character.h"
#include "CharacterLuigi.h"
#include "CharacterMario.h"
#include "Collisions.h"
#include "LevelMap.h"

class Character;
class Texture2D;
class PowBlock;

class GameScreenLevel1 : GameScreen
{
public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	void UpdatePowBlock();
private:
	Texture2D* mBackgroundTexture;
	CharacterMario* mario;	
	CharacterLuigi* luigi;

	Vector2D mPos;
	Vector2D lPos;
	bool SetUpLevel();
	void SetLevelMap();
	LevelMap* mLevelMap;
	PowBlock* mPowBlock;
};

