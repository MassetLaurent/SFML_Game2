#ifndef DEF_GAME
#define DEF_GAME

#include <iostream>
#include <ctime>
#include <sstream>

#include "Player.h"
#include "SwagBall.h"

class Game
{
private:
	//attributes
	Player p_player;
	sf::RenderWindow* p_window;
	sf::VideoMode p_videoMode;
	sf::Event p_sfmlEvent;
	std::vector<SwagBall> p_swagBalls;
	sf::Font p_font;
	sf::Text p_guiText;

	float p_spawnTimer;
	float p_spawnTimerMax;
	int p_maxSwagBalls;
	bool p_endGame;
	int p_points;

	void initWindow();
	void initVariable();
	void initFonts();
	void initText();

public:
	//constructors
	Game();
	virtual ~Game();

	//get
	bool const running() const;

	//methodes
	void pollEvent();
	void spawnSwagBall();
	void updateCollision();
	void updateGui();
	void update();
	void renderGui(sf::RenderTarget* target);
	void render();
};

#endif // !DEF_GAME