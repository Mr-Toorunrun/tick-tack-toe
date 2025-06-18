#include <iostream>
#include <array>
#include <string>
using namespace std;


void showBoard(char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;

	}
}
bool checkAction(char board[3][3], int answer) {
	if (board[(answer - 1) / 3][(answer - 1) % 3] == '-') {
		return true;
	}
	else if (answer > 0 && answer < 10) {
		return true;
	}
	return false;
}
char setAction(char board[3][3], int answer, int t) {
	if (t % 2 == 0) {
		board[(answer - 1) / 3][(answer - 1) % 3] = 'o';
	}
	else {
		board[(answer - 1) / 3][(answer - 1) % 3] = 'x';
	}
	return board[3][3];
}
int getO(char board[3][3], int& answer) {
	cout << endl;
	cin >> answer;
	while (checkAction(board, answer) == false) {
		cout << endl << "Give me the valid action." << endl;
		cin >> answer;
	}
	return answer;
}
int main() {
	char board[3][3] = {
		{'-','-','-'},
		{'-','-','-'},
		{'-','-','-'}
	};
	for (int t = 0; t < 9; t++) {
		showBoard(board);
		if (t % 2 == 0) {
			cout << endl << "what do you pick ? (o)" << endl;
		}
		else {
			cout << endl << "what do you pick ? (x)" << endl;
		}
		int answer = 0;
		getO(board, answer);
		setAction(board, answer, t);
	}
	showBoard(board);
}



