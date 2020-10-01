#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <limits>

// task 1 global
char lc[80];
// task 2 global
char ch;
// task 3 global
struct information
{
	std::string names;
	long long phonenumber{ 0 };
};

int amount;
// task 4 global



void task_1() {

	system("cls");
	// The char data type has a variable named lc (short for lowercase to see it easily). the string length is to make the for loop work


	std::cout << "Welcome to task 1. Please write anything you would like"
		" and see it turn to capital letters." << std::endl;

	std::cout << "Write anything less than 80 characters.\n\nInput: ";

	//Ali thaught me this trick. As results do the same as : (std::numeric_limits<std::streamsize>::max(), '\n')
		//bugged when i did not ignore the buffer size
	std::cin.ignore(UINT16_MAX, '\n'); 

	// getline so that you can write a whole sentence, and not a single word.
	std::cin.getline(lc, 80);
	 

	//std::cout << "running after getline" << std::endl;

	// for each time x is smaller than the lowercase, the following if statement will happen.
	for (int i = 0; i < strlen(lc); i++)
	{
		
		// x finds out if the lc is bigger than ascii 97 or smaller than ascii 129, which is lowercase latin
		if (lc[i] >= 97 && lc[i] <= 129) {

			//when it finds that it's between these ascii numbers, they will convert them to uppercases latin, which is -32 exactly.
			//found out you can't write this in norwegian. Don't write in norwegian to make it work.
			lc[i] = lc[i] - 32;
		}

	}
	
	std::cout << lc << std::endl;
	std::cout << '\n' << "Press any button to return to main menu!";

	char hello=_getch();
	system("cls");
	return;
}

void task_2() {
	system("cls");


	std::vector <std::vector<int>> board{ {1,2,3,4,5,6,7,8,9,10},
							  {11,12,13,14,15,16,17,18,19,20},
							  {21,22,23,24,25,26,27,28,29,30},
							  {31,32,33,34,35,36,37,38,39,40},
							  {41,42,43,44,45,46,47,48,49,50},
							  {51,52,53,54,55,56,57,58,59,60},
							  {61,62,63,64,65,66,67,68,69,70},
							  {71,72,73,74,75,76,77,78,79,80},
							  {81,82,83,84,85,86,87,88,89,90},
							  {91,92,93,94,95,96,97,98,99,100} };

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
			std::cout << "|=|";
		std::cout << std::endl;
	}

	if (_kbhit)
	{
		do
		{
			std::cin.get(ch);
			switch (_getch() == '\033')
			{
			case 'a':
				break;
			case 's':
				break;
			case 'd':
				break;
			case 'w':
				break;
			default:
				break;
			}
		} while (true);

	}

	std::cout << '\n' << "Press any button to return to main menu!";

	char hello = _getch();
	return;
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

		std::cout << "Displaying info\n**************************" << std::endl;

		std::cout << std::endl;
		for (int i = 1; i <= amount; i++)
		{
			std::cout << "Person " << i << " : " << info[i-1].names << std::endl;
			std::cout << "Person " << i << " : " << info[i-1].phonenumber << std::endl;
			std::cout << "**************************" << std::endl;
		}


	
	std::cout << '\n' << "Press any button to return to main menu! \n";

	char hello = _getch();
	system("cls");
}

void task_4() {
	system("cls");




	std::cout << '\n' << "Press any button to return to main menu!";

	char hello = _getch();
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
