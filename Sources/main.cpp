#include "Game.h"

int main()
{
	//Initialize random seed
	srand(static_cast<unsigned>(time(0)));

	//Game loop
	Game game;

	while (game.running())
	{
		game.update();
		game.render();
	}

	//End of application.
	system("pause");

	return 0;
}