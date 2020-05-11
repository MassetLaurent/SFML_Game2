#include "Game.h"

//private methodes
void Game::initVariable()
{
	this->p_endGame = false;
	this->p_spawnTimerMax = 10.f;
	this->p_spawnTimer = this->p_spawnTimerMax;
	this->p_maxSwagBalls = 10;
	this->p_points = 0;
}

void Game::initWindow()
{
	this->p_videoMode = sf::VideoMode(800, 600);
	this->p_window = new sf::RenderWindow(p_videoMode, "SFML Game 2", sf::Style::Close | sf::Style::Titlebar);
	this->p_window->setFramerateLimit(60);
}

void Game::initFonts()
{
	if (!this->p_font.loadFromFile("Fonts/PixellettersFull.ttf"))
	{
		std::cout << " ! ERROR FROM LOADING FONT IN GAME.CPP (PixellettersFull)\n";
	}
}

void Game::initText()
{
	//gui text
	this->p_guiText.setFont(p_font);
	this->p_guiText.setFillColor(sf::Color::Red);
	this->p_guiText.setCharacterSize(32);
}


//constructors
Game::Game()
{
	this->initVariable();
	this->initWindow();
	this->initFonts();
	this->initText();
}

Game::~Game()
{
	delete this->p_window;
}


//get
bool const Game::running() const
{
	return this->p_window->isOpen();
}


//methodes
void Game::pollEvent()
{
	while (this->p_window->pollEvent(this->p_sfmlEvent))
	{
		switch (this->p_sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->p_window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->p_sfmlEvent.key.code == sf::Keyboard::Escape)
				this->p_window->close();
			break;
		default:
			break;
		}
	}
}

void Game::spawnSwagBall()
{
	if (this->p_spawnTimer < this->p_spawnTimerMax)
		this->p_spawnTimer += 1.f;
	else if (this->p_swagBalls.size() < this->p_maxSwagBalls)
	{
		this->p_swagBalls.push_back(SwagBall(*this->p_window));
		this->p_spawnTimer = 0.f;
	}
}

void Game::updateCollision()
{
	//check collision
	for (size_t i = 0; i < p_swagBalls.size(); i++)
	{
		if (this->p_player.getShape().getGlobalBounds().intersects(this->p_swagBalls[i].getShape().getGlobalBounds()))
		{
			//collided
			this->p_swagBalls.erase(this->p_swagBalls.begin() + i);
			this->p_points++;
		}
	}
}

void Game::updateGui()
{
	std::stringstream ss;

	ss	<< " Points : " << this->p_points << "\n"
		//<< " Health : " << this->p_player.getHealth << "\n"
		;

	this->p_guiText.setString(ss.str());
}

void Game::update()
{
	this->pollEvent();

	this->spawnSwagBall();

	this->updateCollision();

	this->updateGui();

	p_player.update(this->p_window);
}

void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->p_guiText);
}

void Game::render()
{
	this->p_window->clear();

	//render image.
	this->p_player.render(this->p_window);
	
	for (auto i : this->p_swagBalls)
	{
		i.render(*this->p_window);
	}
	
	this->renderGui(this->p_window);

	this->p_window->display();
}

