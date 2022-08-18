#ifndef __TEST_GAME_H__
#define __TEST_GAME_H__

#include "../engine/AbstractGame.h"

struct GameKey {
	Point2 pos;
	bool isAlive;
};

struct Enemy {
	Point2 pos;
	bool isAlive;
};
	

class MyGame : public AbstractGame {
	private:
		Rect box;

		Vector2i velocity;

		std::vector<std::shared_ptr<GameKey>> gameKeys;

		std::vector<std::shared_ptr<Enemy>> enemy;

		/* GAMEPLAY */
		int score, numKeys, enemyObjects, lives;
		bool gameWon;
		bool gameLose;

		void handleKeyEvents();
		void update();
		void render();
		void renderUI();
	public:
        MyGame();
	~MyGame();
};

#endif
