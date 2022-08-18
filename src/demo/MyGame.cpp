#include "MyGame.h"

MyGame::MyGame() : AbstractGame(), score(0), lives(3), numKeys(5), enemyObjects(10), gameWon(false), gameLose(false),  box(5, 5, 30, 30) {
	TTF_Font * font = ResourceManager::loadFont("res/fonts/arial.ttf", 72);
	gfx->useFont(font);
	gfx->setVerticalSync(true);

    for (int i = 0; i < numKeys; i++) {
        std::shared_ptr<GameKey> k = std::make_shared<GameKey>();
        k->isAlive = true;
        k->pos = Point2(getRandom(0, 750), getRandom(0, 550));
        gameKeys.push_back(k);
    }

	for (int i = 0; i < enemyObjects; i++) {
		std::shared_ptr<Enemy> k = std::make_shared<Enemy>();
		k->isAlive = true;
		k->pos = Point2(getRandom(0, 750), getRandom(0, 550));
		enemy.push_back(k);
	}
}

MyGame::~MyGame() {

}

void MyGame::handleKeyEvents() {
	int speed = 3;

	if (eventSystem->isPressed(Key::W)) {
		velocity.y = -speed;
	}

	if (eventSystem->isPressed(Key::S)) {
		velocity.y = speed;
	}

	if (eventSystem->isPressed(Key::A)) {
		velocity.x = -speed;
	}

	if (eventSystem->isPressed(Key::D)) {
		velocity.x = speed;
	}
}

void MyGame::update() {
	box.x += velocity.x;
	box.y += velocity.y;

	for (auto key : gameKeys) {
		if (key->isAlive && box.contains(key->pos)) {
			score += 200;
			key->isAlive = false;
			numKeys--;
		}
	}

	velocity.x = 0;
	velocity.y = 0;

	if (numKeys == 0) {
		gameWon = true;
	}
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																									
	for (auto key : enemy) {
		if (key->isAlive && box.contains(key->pos)) {
			score -= 100;
			key->isAlive = false;
			enemyObjects--;
		}
	}

	if (enemyObjects == 9) {
		gameLose = true;
	}
}

void MyGame::render() {
	gfx->setDrawColor(SDL_COLOR_GREEN);
	gfx->drawRect(box);

	gfx->setDrawColor(SDL_COLOR_RED);
	for (auto key : enemy)
		if (key->isAlive)
			gfx->drawCircle(key->pos, 5);

	gfx->setDrawColor(SDL_COLOR_YELLOW);
	for (auto key : gameKeys)
		if (key->isAlive)
			gfx->drawCircle(key->pos, 5);
}

void MyGame::renderUI() {
	gfx->setDrawColor(SDL_COLOR_AQUA);
	std::string scoreStr = std::to_string(score);
	gfx->drawText(scoreStr, 780 - scoreStr.length() * 50, 25);

	if (gameWon)
		gfx->drawText("YOU WON", 200, 500);

	if (gameLose)
		gfx->drawText("GAME OVER", 190, 500);
}
