#ifndef DEF_PLAYER
#define DEF_PLAYER

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player
{
private:
	//attributes
	sf::RectangleShape p_shape;

	int p_hp;
	int p_hpMax;
	float p_movementSpeed;

	void p_initVariable();
	void p_initShape();

public:
	//constructor
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	//get
	const sf::RectangleShape& getShape() const;

	//methodes
	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

#endif // !DEF_PLAYER
