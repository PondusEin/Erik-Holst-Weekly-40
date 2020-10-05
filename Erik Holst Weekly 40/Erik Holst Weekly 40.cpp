#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <limits>
#include <ctime>
#include <Windows.h>
#include <algorithm>

#define KEY_ESC 27

// task 1 global
/* The char data type has a variable named lc (short for lowercase to see it easily). 
The string length is to make the for loop work*/
char lc[80];

// task 2 global
const char WIDTH = 10, HEIGHT = 10;
unsigned char player = { 64 };
int posX = 0, posY = 0;
char input;

void playerAction();

// task 3 global
struct information
{
	std::string names;
	long long phonenumber{ 0 };
};

int amount;
int person;

// task 4 global
bool finishedDice;

// Global general
void cya() {
	char goodbye = _getch();
	system("cls");
}

void task_1() {

	system("cls");


	std::cout << "Welcome to task 1. Please write anything you would like"
		" and see it turn to capital letters." << std::endl;

	std::cout << "Write anything less than 80 characters.\n\nInput: ";

	//Ali thaught me this trick. As results do the same as : (std::numeric_limits<std::streamsize>::max(), '\n')
		//bugged when i did not ignore the buffer size
	std::cin.ignore(UINT16_MAX, '\n'); 

	// getline so that you can write a whole sentence, and not a single word.
	std::cin.getline(lc, 80);

	// for each time i is smaller than the lowercase, the following if statement will happen.
	for (int i = 0; i < strlen(lc); i++)
	{
		
		// i finds out if the lc is bigger than ascii 97 or smaller than ascii 129, which is lowercase latin
		if (lc[i] >= 97 && lc[i] <= 129) {

			//when it finds that it's between these ascii numbers, they will convert them to uppercases latin, which is -32 exactly.
			//found out you can't write this in norwegian. Don't write in norwegian to make it work.
			lc[i] = lc[i] - 32;
		}
	}
	std::cout << lc << std::endl;
	std::cout << '\n' << "Press any button to return to main menu!";
	cya();
	return;
}

unsigned char board[WIDTH][HEIGHT] = {
		{'-','-','-','-','-','-','-','-','-','/' },
		{'-','-','\\','-','-','-','-','-','-','-' },
		{'-','\\','-','/','-','-','-','-','-','\\' },
		{'-','-','/','-','-','-','-','-','-','-' },
		{'-','\\','-','\\','-','-','-','-','-','-' },
		{'-','-','\\','G','\\','-','-','-','-','/' },
		{'-','/','-','/','-','-','-','-','-','-' },
		{'-','-','/','-','-','G','-','-','-','-' },
		{'-','\\','-','/','-','-','-','-','\\','-' },
		{'-','-','-','-','-','-','-','-','-','-' },
};

void playerAction() {

	long long prevPosX = posX;
	long long prevPosY = posY;
	unsigned char space = { 32 };
	input = _getch();
		switch (input)
		{
		case 'W': case 'w':
				posX--;
			system("cls");
			break;
		case 'A': case 'a':
				posY--;
			system("cls");
			break;
		case 'D': case 'd':
				posY++;
			system("cls");
			break;
		case 'S': case 's':
				posX++;
			system("cls");
			break;
		default:
			std::cout << "Incorrect move!" << std::endl;
			break;
		}
	board[prevPosX][prevPosY] = '-';
}

void task_2() {
	system("cls");

	while (input != KEY_ESC) {
		std::cout << "Move your player using WASD." << std::endl;
		std::cout << std::endl;

		board[posX][posY] = player;

		for (int y=0; y < HEIGHT; y++)
		{
			std::cout << std::endl;
			for (int x = 0; x < WIDTH; x++) {

				std::cout << board[y][x];
			}
		}

		playerAction();
		if (board[posX][posY] != '-')
		{
			if (board[posX][posY] == '/')
			{
				posX++;
			}
			else if (board[posX][posY] == '\\')
			{
				posX--;
			}
			else if (board[posX][posY] == 'G')
			{
				std::cout << "You win! Well done! ";
				break;
			}
		}
		if (posY < 0)
		{
			posY = 9;
		}
		if (posY > 9)
		{
			posY = 0;
		}
		if (posX < 0)
		{
			posX = 9;
		}
		if (posX > 9)
		{
			posX = 0;
		}
	} 
	std::cout << "Press any button to return to main menu!" << '\n';

	cya();
	return;
}

void error() {
	std::cout << "Error, no info found. Try again with [1-" << amount << "]";
	cya();
}

void task_3() {
	system("cls");

	information info[10];

	std::cout << "How many people would like to store? \nInput: ";
	std::cin >> amount;
//	std::cin.ignore();

	for (int i = 1; i < amount+1; i++)
	{
	system("cls");
	std::cout << "Enter person " << i << " name: ";
	std::cin.ignore(32676, '\n');
	std::getline(std::cin, info[i-1].names);

	std::cout << "Enter person " << i << " number: ";

	std::cin >> info[i-1].phonenumber;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cin >> info[i - 1].phonenumber;
		};
	}
	system("cls");

		for (int i = 1; i <= amount; i++)
		{
			while (true)
			{
				std::cout << "Displaying info\n**************************" << std::endl;

				std::cout << std::endl;
				std::cout << "Which person would you like to see information about?"
					"\tPress [0] to return to main menu!\n\nInput: ";
				std::cin >> person;
				switch (person)
				{
				case 1:
					std::cout << "Person " << i << " : " << info[i - 1].names << std::endl;
					std::cout << "Person " << i << " : " << info[i - 1].phonenumber << std::endl;
					cya();
					break;
				case 2:
					if (amount >= 2)
					{
						std::cout << "Person " << i + 1 << " : " << info[i].names << std::endl;
						std::cout << "Person " << i + 1 << " : " << info[i].phonenumber << std::endl;
						cya();
					}
					else
					{
						error();
					}
					break;

				case 3:
					if (amount >= 3)
					{
						std::cout << "Person " << i + 2 << " : " << info[i + 1].names << std::endl;
						std::cout << "Person " << i + 2 << " : " << info[i + 1].phonenumber << std::endl;
						cya();
					}
					else
					{
						error();
					}
					break;
				case 4:
					if (amount >= 4)
					{
						std::cout << "Person " << i + 3 << " : " << info[i + 2].names << std::endl;
						std::cout << "Person " << i + 3 << " : " << info[i + 2].phonenumber << std::endl;
						cya();
					}
					else
					{
						error();
					}
					break;
				case 5:
					if (amount >=5)
					{
						std::cout << "Person " << i + 4 << " : " << info[i + 3].names << std::endl;
						std::cout << "Person " << i + 4 << " : " << info[i + 3].phonenumber << std::endl;
						cya();
					}
					else
					{
						error();
					}
					break;
				case 6:
					if (amount >= 6)
					{
						std::cout << "Person " << i + 5 << " : " << info[i + 4].names << std::endl;
						std::cout << "Person " << i + 5 << " : " << info[i + 4].phonenumber << std::endl;
						cya();
					}
					else
					{
						error();
					}
					break;
				case 7:
					if (amount >= 7)
					{
						std::cout << "Person " << i + 6 << " : " << info[i + 5].names << std::endl;
						std::cout << "Person " << i + 6 << " : " << info[i + 5].phonenumber << std::endl;
						cya();
					}
					else
					{
						error();
					}
					break;
				case 8:
					if (amount >= 8)
					{

						std::cout << "Person " << i + 7 << " : " << info[i + 6].names << std::endl;
						std::cout << "Person " << i + 7 << " : " << info[i + 6].phonenumber << std::endl;
						cya();
					}
					else
					{
						error();
					}
					break;
				case 9:
					if (amount >= 9)
					{
						std::cout << "Person " << i + 8 << " : " << info[i + 7].names << std::endl;
						std::cout << "Person " << i + 8 << " : " << info[i + 7].phonenumber << std::endl;
						cya();
					}
					else
					{
						error();
					}
					break;
				case 10:
					if (amount >= 10)
					{
						std::cout << "Person " << i + 9 << " : " << info[i + 8].names << std::endl;
						std::cout << "Person " << i + 9 << " : " << info[i + 8].phonenumber << std::endl;
						cya();
					}
					else
					{
						error();
					}
					break;
				case 0:
					system("cls");
					return;
				default:
					error();
					break;
				}	
			}
		}
}

int diceSixes(std::vector<int> array)
{
	int sixes{ 0 };
	for (int i = 0; i < array.size(); i++)
	{
		if (array.at(i) == 6)
		{
			sixes++;
		}
	}
	return sixes;
}

int dicePairs(std::vector<int> array) 
{
	int pairs{ 0 };
	sort(array.begin(), array.end());
	for (int i = 0; i < array.size(); i++)
	{	
		if (i > 0 && array.at(i) == array.at(i-1)) 
		{
			pairs++;
			i++;
		}
	}
	return pairs;
}

void diceRoll(std::vector<int> &array) {
	for (int i = 0; i < array.size(); i++)
	{
		array.at(i) = rand() % 6 + 1;
		std::cout << array.at(i) << ' ';
	}
}

void task_4() {
	system("cls");
	srand(static_cast <unsigned int>(std::time(nullptr)));
	finishedDice = false;
	std::vector<int> Playing(5);
	std::vector<int> keptDice{};
	std::cout << "Dice roll game. Press 'R' to roll. Press [0] to exit." << std::endl;
	input=_getch();
	while (true)
	{
		while (input != 'h' && input != 'H')		//press h to break the while loop and go to hold
		{
			system("cls");
			if (input == 'r' || input == 'R')		//press r and the dice will be rolled
			{
				diceRoll(Playing);
				input = ' ';
			}
			std::cout << "\nPress 'H' to keep dice \nPress 'R' to reroll dice";
			input = _getch();
		}
		while (true)
		{
			system("cls");
			input = ' ';
			for (int i = 0; i < Playing.size(); i++)	//print rolled dice
			{
				std::cout << "Dice[" << i+1 << "] : " << Playing.at(i) << '\n';
			}

			std::cout << "Dice kept: ";
			for (int i = 0; i < keptDice.size(); i++)
			{
				std::cout << keptDice.at(i) << " ";
			}

			std::cout << "\nPress number [1-" << Playing.size() << "] to hold the dice. Press 'R' to reroll. Press 'H' to see result and exit. \n";
			input = _getch();

			if (input == 'r' || input == 'R'){
				break;
			}
			if (input == 'h' || input == 'H')
			{
				system("cls");
				std::cout << "Numbers you got: ";
				for	(int i = 0; i < keptDice.size(); i++)
				{
					std::cout << keptDice.at(i) << " ";
				}
				std::cout << "\nNumber of 6's:   " << diceSixes(keptDice) << std::endl;
				std::cout << "Amount of pairs: " << dicePairs(keptDice) << std::endl;

				system("pause");
				finishedDice = true;
				break;
			}
			switch (input)
			{
				case '1':
					if (true)
					{
						keptDice.push_back(Playing.at(0)); 
						Playing.erase(Playing.begin());
					}
					break;
				case '2':
					if (true)
					{
						keptDice.push_back(Playing.at(1));
						Playing.erase(Playing.begin() + 1);
					}
					break;
				case '3':
					if (true)
					{
						keptDice.push_back(Playing.at(2));
						Playing.erase(Playing.begin() + 2);
					}
					break;
				case '4':
					if (true)
					{
						keptDice.push_back(Playing.at(3));
						Playing.erase(Playing.begin() + 3);
					}
					break;
				case '5':
					if (true)
					{
						keptDice.push_back(Playing.at(4));
						Playing.erase(Playing.begin() + 4);
					}
					break;
				default:
					std::cout << "Please select a value between [1-" << Playing.size() << ']';
					system("pause");
					break;
			}
		}
		if (finishedDice == true){
			finishedDice = false;
			break;
		}
	}
	std::cout << '\n' << "Press any button to return to main menu!";

	cya();
	return;
}

int main()
{
	// bool task to finish the "showthrough" of the weekly task
	bool completed_task_1 = false;
	bool completed_task_2 = false;
	bool completed_task_3 = false;
	bool completed_task_4 = false;

	system("cls");
	int x;
	
	std::cout << "Hello! Welcome to weekly 40 assignments, by Erik Holst!" << std::endl;
	
	do
	{
		if (completed_task_1 && completed_task_2 && completed_task_3 && completed_task_4)
		{
			system("cls");
			std::cout << "Well done, you completed all the tasks!";
			return (EXIT_SUCCESS);
		}
		else
		{

			std::cout << "Please select task [1-4]" << std::endl;
			std::cout << "\nTask [1]: Converts lower case to UPPER CASE using functions and data type char."
				" \nTask [2]: Board game that let's you move around."
				" \nTask [3]: Program that takes names and info of max 10 persons."
				" \nTask [4]: Dice game.\n\nPress [0] to exit" << std::endl;

			std::cin >> x;

			switch (x)
			{
			case 1:
				task_1();
				completed_task_1=true;
				break;
			case 2:
				task_2();
				completed_task_2 = true;
				break;
			case 3:
				task_3();
				completed_task_3 = true;
				break;
			case 4:
				task_4();
				completed_task_4 = true;
				break;
			case 0:
				exit(true);
				break;
			default:
				system("cls");
				break;
			}
		}
		//std::cin.clear();
		//std::cin.ignore(UINT16_MAX, '\n');
	} while (true);
}