/*
	Hangman Game Class
Programmers:
	Kelvin Figueroa Figueroa
	Jonathan Camacho Ortega
	Sebastian Matthews
*/
#include "Game.h"

int main()
{
	char again;
	Game hangMan;
	do
	{
		hangMan.createFile();
		hangMan.startGame();
		again = hangMan.playAgain();
		system("cls");
	} while (again == 'y' || again == 'Y');
	cout << "\nThanks for playing!\n";
	system("pause");
	return 0;
}