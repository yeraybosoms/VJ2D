#include "Board.h"

#define BUBBLE_SIZE 34.0f

#define BUBBLE_TYPES 10
#define START_BUBLES_X 212.0f



Board::Board() {
	positionFirstY = 55.0f;
}

Board::~Board() {
	matrixBubbles.clear();
}

void Board::init(int width, int height,  ShaderProgram &program) {

	boardWidth = width;
	boardHeight = height;

	matrixBubbles = boardMatrix(boardHeight, boardRow(width, 1));

	bubTexture.loadFromFile("images/bubbles.png", TEXTURE_PIXEL_FORMAT_RGBA);


	bubSprite = Sprite::createSprite(
		glm::ivec2(BUBBLE_SIZE, BUBBLE_SIZE),
		glm::vec2(1.0f/3.0f, 1.0f/3.0f),
		&bubTexture,
		&program);
	


	bubSprite->setNumberAnimations(BUBBLE_TYPES);
	int cont = 1;
	for (int i = 0; i < ((BUBBLE_TYPES-1)/3); ++i) {
		for (int j = 0; j < ((BUBBLE_TYPES-1)/3); ++j) {
			bubSprite->setAnimationSpeed(cont, 0);
			bubSprite->addKeyframe(cont, glm::vec2(1.0f / 3.0f * i, 1.0f / 3.0f * j));
			float x = 1.0f / 3.0f * i;
			float y = 1.0f / 3.0f * j;
			++cont;
		}
	}

	

}

void Board::update(int deltaTime)
{
}

void Board::render() {
	glm::vec2 position;
	for (int i = 0 ; i < boardHeight; ++i) {
		for (int j = 0; j <  boardWidth; ++j) {
			if (matrixBubbles[i][j] != 0) {
				if (i % 2 == 0)
					position = glm::vec2(START_BUBLES_X + j * BUBBLE_SIZE, positionFirstY + i * BUBBLE_SIZE - i * (BUBBLE_SIZE / 8.0f + 1.5f));
				else
					position = glm::vec2(START_BUBLES_X + j * BUBBLE_SIZE + BUBBLE_SIZE / 2.0f, positionFirstY + i * BUBBLE_SIZE - i * (BUBBLE_SIZE / 8.0f + 1.5f));

				if (i % 2 == 0 || j < boardWidth - 1) {
					bubSprite->setPosition(position);
					bubSprite->changeAnimation(matrixBubbles[i][j]);
					bubSprite->render();
				}
			}
		}
	}
}

void Board::load(int level) {
	//For now it's random
	srand(time(NULL));
	for (int i = 0; i < boardHeight; ++i) {
		for (int j = 0; j < boardWidth; ++j) {
			matrixBubbles[i][j] = (rand() % (BUBBLE_TYPES));
		}
	}
}

void Board::setPositionFirstY(float newFirstY) {
	positionFirstY = newFirstY;
}