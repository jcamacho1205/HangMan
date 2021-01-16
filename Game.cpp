/*
	Hangman Game Class
Programmers:
	Kelvin Figueroa Figueroa
	Jonathan Camacho Ortega
	Sebastian Matthews
*/
#include<conio.h>
#include "Game.h"

using namespace std;

Game::Game()
{
	setRand("");
	setGuess(' ');
}

Game::Game(string newRandWord)
{
	setRand(newRandWord);
}

Game::~Game()
{
	//Destruction!!
}

void Game::setRand(string randWord)
{
	this->randWord = randWord;
}
void Game::setGuess(char guess)
{
	this->guess = guess;
}

string Game::getRand() const
{
	return this->randWord;
}
char Game::getGuess() const
{
	return this->guess;
}

void Game::createFile()
{
	//se crea el file de las palabras para el juego
	file.open("Words.txt", ios::out);

	//escribiendo las palabras al file (10 en total)
	//Las palabras por el momento van a ser de animales
	
	file << "owl\n";
	file << "dog\n";
	file << "cat\n";
	file << "fly\n";
	file << "fox\n";
	file << "pig\n";
	file << "ape\n";
	file << "ant\n";
	file << "bee\n";
	file << "bat\n";
	
	//se cierra el file 
	file.close();
}

void Game::generateRandWord()
{
	//abriendo el archivo para buscar la palabra random
	file.open("Words.txt", ios::in);

	int fileIndex; //lineas del file
	string wordList[12]; //lista de todas las palabras
	int listIndex = 0; //index de la lista
	int word = 1; //numero de palabras a copiar

	unsigned seed = static_cast<unsigned int>(time(0));

	//copiar todas las palabras a la variable wordList[listIndex]
	while (!file.eof())
	{
		getline(file, wordList[listIndex]);
		listIndex++;
	}

	for (int i = 0; i < word; i++)	//solo una palabra se pasara a la variable randWord ( privada )
	{
		srand(seed);
		fileIndex = rand() % 10;	//1 de 10 lineas se guardara en indexFile
		setRand(wordList[fileIndex]); //pasa la palabra a la variable randWord
	}
}

void Game::validateGuess()
{

	if (!isalpha(guess))
	{
		cout << "Error; you may only use letters to guess..." << endl;
	}
	else
	{
		tolower(guess);
	}
}

void Game::instructions()
{
	cout << "Welcome to HangMan!\n"
		<< "This game has only one rule:\n"
		<< "1. If you don't guess the word in 8 attempts,\n"
		<< "you lose.\n"
		<< "Hint: All the words to guess in this game are based on animals.\n"
		<< "Have fun!\n\n"
		<< "Press any key to continue...";
}


void Game::hangMan()
{
	instructions();
	_getch(); //entrar cualquier tecla para continuar el programa

	int lives = 8;
	string word = "---";
	for (int count = 0; count < SIZE; count++)
		guesses[count] = ' ';

	generateRandWord();

	while (lives > 0 && word != randWord)
	{
		system("cls");
		displayMan(lives);
		cout << "\t" << word << "\t\n";
		cout << "You have " << lives << " lives.\n";
		cout << "Attempts: ";
		displayAttempts(guesses, guess);
		cout << "\nEnter your guess with a letter: ";
		cin >> guess;

		validateGuess();

		cout << endl << endl;

		int found = randWord.find(guess);
		int length = randWord.length();

		if (found != string::npos)						//si la palabra no existe sigue escribiendo una letra
		{
			for (int i = 0; i < length; i++)	//loop para buscar las que se parecen
			{
				if (guess == randWord[i])
				{
					word[i] = guess;	//si la letra esta en la palabra, borra una linea y pone la letra
				}
			}
		}
		else
		{
			lives -= 1;
		}

	}

	if (word == randWord)
	{
		displayMan(lives);
		cout << "Congratulations!!\n";
		cout << "The word was: " << randWord << endl;
		setGuess(' ');  //para que no salga en los 'Incorrect attempts:' si el usuario juega de nuevo [again == y]
	}
	else
	{
		displayMan(lives);
		cout << "Your chances are up!\n"
			<< "The word was: " << randWord << endl;
		setGuess(' ');
	}
}

void Game::displayMan(int lives)
{
	if (lives == 8)
	{
		cout << "_______" << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (lives == 7)
	{
		cout << "_______" << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
		cout << "|     o" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (lives == 6)
	{
		cout << "_______" << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
		cout << "|     o" << endl;
		cout << "|    /" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (lives == 5)
	{
		cout << "_______" << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
		cout << "|     o" << endl;
		cout << "|    /|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (lives == 4)
	{
		cout << "_______" << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
		cout << "|     o" << endl;
		cout << "|    /|\\" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (lives == 3)
	{
		cout << "_______" << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
		cout << "|     o" << endl;
		cout << "|    /|\\" << endl;
		cout << "|    /" << endl;
		cout << "|" << endl;
	}
	else if (lives == 2)
	{
		cout << "_______" << endl;
		cout << "|      " << endl;
		cout << "|      " << endl;
		cout << "|     o" << endl;
		cout << "|    /|\\" << endl;
		cout << "|    / \\" << endl;
		cout << "|" << endl;
	}
	else if (lives == 1)
	{
		cout << "_______" << endl;
		cout << "|     |" << endl;
		cout << "|      " << endl;
		cout << "|     o" << endl;
		cout << "|    /|\\" << endl;
		cout << "|    / \\" << endl;
		cout << "|" << endl;
	}
	else if (lives == 0)
	{
		cout << "_______" << endl;
		cout << "|     |" << endl;
		cout << "|     |" << endl;
		cout << "|     x" << endl;
		cout << "|    /|\\" << endl;
		cout << "|    / \\" << endl;
		cout << "|" << endl;
	}
}

void Game::displayAttempts(char attempts[SIZE], char attempt)
{
	int count;
	//maximum errors are 7 and maximum correct guesses are 3; thus, SIZE = 11.
	for (count = 0; count < SIZE; count++)
	{
			if (!isalpha(attempts[count])) //asegurar que el espacio esté en blanco
			{
				attempts[count] = attempt;
				break; //parar el loop para que no siga asignando el mismo valor
			}
	}
	for (count = 0; count < SIZE; count++)
	{
		cout << attempts[count] << " "; //imprimir el contenido del arreglo
	}
}

void Game::startGame()
{
	hangMan();
}

char Game::playAgain() const
{
	char again;
	cout << "\nDo you wish to play again? (Y/N)\n";
	cin >> again;
	return again;
}