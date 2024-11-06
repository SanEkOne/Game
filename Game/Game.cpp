#include <iostream> 
#include <ctime> 
using namespace std;

void printArr(char** myArr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << myArr[i][j] << " ";
		}
		cout << endl;
	}
}



// a=0, b=1, c=2

void printWin(int a, int b, int c, char** arr, char symbol2) {
	if (arr[a][a] == arr[a][b] && arr[a][a] == arr[a][c] && arr[a][a] != '+') {
		cout << "Winner is: " << symbol2 << endl;
	}
	else if (arr[b][a] == arr[b][b] && arr[b][a] == arr[b][c] && arr[b][a] != '+') {
		cout << "Winner is: " << symbol2 << endl;
	}
	else if (arr[c][a] == arr[c][b] && arr[c][a] == arr[c][c] && arr[c][a] != '+') {
		cout << "Winner is: " << symbol2 << endl;
	}

	else if (arr[a][a] == arr[b][b] && arr[a][a] == arr[c][c] && arr[a][a] != '+') {
		cout << "Winner is: " << symbol2 << endl;
	}
	else if (arr[a][c] == arr[b][b] && arr[a][c] == arr[c][a] && arr[a][c] != '+') {
		cout << "Winner is: " << symbol2 << endl;
	}

	else if (arr[a][a] == arr[b][a] && arr[a][a] == arr[c][a] && arr[a][a] != '+') {
		cout << "Winner is: " << symbol2 << endl;
	}
	else if (arr[a][b] == arr[b][b] && arr[a][b] == arr[b][c] && arr[a][b] != '+') {
		cout << "Winner is: " << symbol2 << endl;
	}
	else if (arr[a][c] == arr[b][c] && arr[a][c] == arr[c][c] && arr[a][c] != '+') {
		cout << "Winner is: " << symbol2 << endl;
	}
}

void printDraw(int amount) {
	if (amount > 0) {
		cout << "continue" << endl;
	}
	else {
		cout << "Draw" << endl;
	}
}



void main()
{
	char** field = new char* [3];

	for (int i = 0; i < 3; i++) {
		field[i] = new char[3];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = '+';
		}
	}

	bool isGameOver = false;
	char symbol = 'X';
	int countOfSteps = 1;
	int amountOfFreePlaces = 9;

	while (!isGameOver) {
		if (countOfSteps % 2 == 0) {
			symbol = '0';
		}
		else {
			symbol = 'X';
		}
		countOfSteps++;

		printArr(field, 3);


		int x, y;
		cout << "Enter a row of place: ";
		cin >> x;
		cout << endl << "Enter a column of place: ";
		cin >> y;

		while (field[x][y] != '+') {
			cout << "Enter a row of place: ";
			cin >> x;
			cout << endl << "Enter a column of place: ";
			cin >> y;
		}

		field[x][y] = symbol;
		amountOfFreePlaces--;

		printWin(0, 1, 2, field, symbol);



		printDraw(amountOfFreePlaces);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		delete[] field[i];
	}

	delete[] field;
	field = nullptr;
}