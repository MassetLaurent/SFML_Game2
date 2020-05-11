#ifndef DEF_SWAGBALL
#define DEF_SWAGBALL

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class SwagBall
{
private:
	//attributes
	sf::CircleShape p_shape;

	void p_initShape(const sf::RenderWindow& window);

public:
	//constructor
	SwagBall(const sf::RenderWindow& window);
	virtual ~SwagBall();

	//get
	const sf::CircleShape& getShape() const;

	//methodes
	void update();
	void render(sf::RenderTarget& target);
};

#endif // !DEF_SWAGBALL
