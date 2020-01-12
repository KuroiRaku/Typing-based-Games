#include "game.h"


int main()
{

	srand(time(NULL));

	game game;
	game.InitGame();

	Inventory inv;
	inv.AddItem(item());

	inv.DebugPrint();

	Character char_default;
	while (game.GetPlaying())
	{
		game.MainMenu();
	}
	return 0;
}