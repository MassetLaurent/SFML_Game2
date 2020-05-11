#include "Player.h"
//private methodes
void Player::p_initVariable()
{
	this->p_movementSpeed = 5.f;
	this->p_hpMax = 10;
	this->p_hp = p_hpMax;
}

void Player::p_initShape()
{
	this->p_shape.setFillColor(sf::Color::Green);
	this->p_shape.setSize(sf::Vector2f(50.f, 50.f));
}


//constructeurs
Player::Player(float x, float y)
{
	this->p_shape.setPosition(x, y);

	this->p_initVariable();
	this->p_initShape();
}

Player::~Player()
{

}


//get
const sf::RectangleShape& Player::getShape() const
{
	return this->p_shape;
}


//methodes
void Player::updateInput()
{
	//Keyboard input
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->p_shape.move(-this->p_movementSpeed, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->p_shape.move(this->p_movementSpeed, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->p_shape.move(0.f, -this->p_movementSpeed);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->p_shape.move(0.f,this->p_movementSpeed);
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	//Left
	if (this->p_shape.getGlobalBounds().left <= 0.f)
		this->p_shape.setPosition(0.f, this->p_shape.getGlobalBounds().top);

	//Right
	if (this->p_shape.getGlobalBounds().left + this->p_shape.getGlobalBounds().width >= target->getSize().x)
		this->p_shape.setPosition(target->getSize().x - this->p_shape.getGlobalBounds().width, this->p_shape.getGlobalBounds().top);

	//Top
	if (this->p_shape.getGlobalBounds().top <= 0.f)
		this->p_shape.setPosition(this->p_shape.getGlobalBounds().left, 0.f);
	//Down
	if (this->p_shape.getGlobalBounds().top + this->p_shape.getGlobalBounds().height >= target->getSize().y)
		this->p_shape.setPosition(this->p_shape.getGlobalBounds().left, target->getSize().y - this->p_shape.getGlobalBounds().height);
}

void Player::update(const sf::RenderTarget* target)
{
	this->updateInput();

	//window bounce colision
	this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget * target)
{
	target->draw(this->p_shape);
}
