#include "game.h"


int main()
{

	srand(time(NULL));

	game game;
	game.initGame();

	Inventory inv;
	inv.addItem(item());

	inv.debugPrint();

	Character char_default;
	while (game.getPlaying())
	{
		game.mainmenu();
	}
	return 0;
}