/*
	Hangman Game Class
Programmers:
	Kelvin Figueroa Figueroa 
	Jonathan Camacho Ortega		
	Sebastian Matthews

Instructions:
You will design a program that plays hangman.
The program must at least include one class and client code.
It does not require graphical representation but to keep track of the player misses.
The host is the computer.
The list of words is 10 and all of them will be three-letters (file?).
*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
#include<ctime>

using namespace std;
const int SIZE = 11;

class Game
{
private:
	fstream file;
	string randWord; //randomly generated word from the file 
	char guess; // user-inputted guess
	char guesses[SIZE]; // so the attempts(misses) get recorded after each call of the function
public:
	Game();
	Game(string newRandWord); //constructor to manually input the word to be guessed by the user
	~Game();

	void setRand(string randWord); // mutator function to use in generateRandWord()
	void setGuess(char guess); // mutator function to store user's guess

	string getRand() const; // accessor function for the string value in the randWord variable
	char getGuess() const; // accessor function for the char value in the guess variable

	void createFile();
	void generateRandWord(); // to generate the random word, from the file, to be guessed by the user
	void validateGuess(); // valida la letra del usuario
	void instructions();
	void hangMan(); // compara la letra con las palabras y llama las otras funciones(excepto createFile)
	void displayMan(int lives); // imprime los diagramas del hangman con respecto al cantidad de errores
	void displayAttempts(char attempts[SIZE], char attempt);
	void startGame();
	char playAgain() const;
};