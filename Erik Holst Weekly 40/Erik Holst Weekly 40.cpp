#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <limits>
#include <ctime>
#include <Windows.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_W 0x57
#define KEY_A 0x41
#define KEY_S 0x53
#define KEY_D 0x44
#define VK_CAPITAL 0x14
#define KEYEVENTF_EXTENDEDKEY 0x0001
// task 1 global
	// The char data type has a variable named lc (short for lowercase to see it easily). the string length is to make the for loop work
char lc[80];

// task 2 global

int input = 0;
int posX = 0, posY = 0;
char player = { 1 };


// task 3 global
struct information
{
	std::string names;
	long long phonenumber{ 0 };
};

int amount;
int person;

// task 4 global
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
	 

	//std::cout << "running after getline" << std::endl; debug test

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

	char goodbye=_getch();
	system("cls");
	return;
}

void task_2() {
	system("cls");
	
	std::vector <std::vector<int>> board{ 10 };




	while (input != KEY_ESC) {

		board[posX][posY] = player;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board.size(); j++) {

				std::cout << '-';
			}
			std::cout << std::endl;
		}

		input = _getch();
		keybd_event(VK_CAPITAL, 0, KEYEVENTF_EXTENDEDKEY | 0,0);
		int prevPosX = posX;
		int prevPosY = posY;
		unsigned char space = { '-' };

		switch (input)
		{
		case KEY_W:
			posY--;
			board[prevPosX][prevPosY] = space;
			break;
		case KEY_A:
			posX--;
			board[prevPosX][prevPosY] = space;
			break;
		case KEY_D:
			posX++;
			board[prevPosX][prevPosY] = space;
			break;
		case KEY_S:
			posY++;
			board[prevPosX][prevPosY] = space;
			break;
		default:
			break;
		}
	} 
	
	
	
	std::cout << "Press any button to return to main menu!" << '\n';

	char goodbye = _getch();
	system("cls");
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
				}
;
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

void task_4() {
	system("cls");
	srand(time(nullptr));



	std::cout << '\n' << "Press any button to return to main menu!";

	char goodbye = _getch();
	system("cls");
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
