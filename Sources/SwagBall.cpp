#include "SwagBall.h"

//private methodes
void SwagBall::p_initShape(const sf::RenderWindow& window)
{
	this->p_shape.setRadius(static_cast<float>(rand() % 10 + 10));

	sf::Color randColor(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);

	this->p_shape.setFillColor(randColor);

	this->p_shape.setPosition(sf::Vector2f
	(
		static_cast<float>(rand()% window.getSize().x - this->p_shape.getGlobalBounds().width), 
		static_cast<float>(rand() % window.getSize().y - this->p_shape.getGlobalBounds().height)
	));
}


//constructors
SwagBall::SwagBall(const sf::RenderWindow& window)
{
	this->p_initShape(window);
}

SwagBall::~SwagBall()
{
}


//get
const sf::CircleShape & SwagBall::getShape() const
{
	return this->p_shape;
}


//methodes
void SwagBall::update()
{

}

void SwagBall::render(sf::RenderTarget& target)
{
	target.draw(this->p_shape);
}
