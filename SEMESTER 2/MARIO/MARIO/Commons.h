#pragma once

enum FACING
{
	FACING_LEFT = 0,
	FACING_RIGHT
};

enum SCREENS
{
	SCREEN_INTRO = 0,
	SCREEN_MENU,
	SCREEN_LEVEL1,
	SCREEN_LEVEL2,
	SCREEN__GAMEOVER,
	SCREEN_HIGHSCORES
};

struct Vector2D
{
	float x;
	float y;

	Vector2D()
	{
		x = 0.0f;
		y = 0.0f;
	} 	
	
	Vector2D(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
};

