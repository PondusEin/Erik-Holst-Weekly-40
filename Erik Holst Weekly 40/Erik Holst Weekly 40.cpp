#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <limits>




void task_1() {

	system("cls");
	// The char data type has a variable named lc (short for lowercase to see it easily). the string length is to make the for loop work
	char lc[80];

	//using an integer to understand the value of ascii program
	int i;

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
	

	std::cout << lc;


	char hello=_getch();
	system("cls");
	return;

}

void task_2() {

}

void task_3() {

}

void task_4() {

}

int main()
{
	system("cls");
	int x;
	std::cout << "Hello! Welcome to weekly 40 assignments, by Erik Holst!" << std::endl;


	

	do
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
			break;
		case 2:
			task_2();
			break;
		case 3:
			task_3();
			break;
		case 4:
			task_4();
			break;
		case 0:
			exit(true);
			break;
		default:
			break;
		}
	} while (true);

}
