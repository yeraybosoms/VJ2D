#ifndef _BOARD_INCLUDE
#define _BOARD_INCLUDE

#include "Sprite.h"
#include "Texture.h"
#include "ShaderProgram.h"

#include <queue>
#include <list>
#include <iostream>
#include <fstream>
#include <ctime>

class Board {

public:
	typedef std::vector<int> boardRow;
	typedef std::vector<boardRow> boardMatrix;

	//Constructors
	Board();
	~Board();

	//Draw functions
	void init(int width, int height, ShaderProgram &program);
	void update(int deltaTime);
	void load(int level);
	void render();


	void setPositionFirstY(float newFirstY);

private:

	float positionFirstY;
	unsigned int boardWidth;
	unsigned int boardHeight;
	boardMatrix matrixBubbles;

	Sprite* bubSprite;
	Texture bubTexture;

};
#endif
