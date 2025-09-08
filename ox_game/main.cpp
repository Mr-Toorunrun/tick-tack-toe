#include <iostream>
#include <array>
#include <string>
using namespace std;

// Ai's turn
void thinking(char board[3][3], int t) {
	if (t < 2) {
		if (board[1][1] == '-') {
			board[1][1] = 'x';
			return;
		}

	}
	// check the rows
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == 'o' && board[i][1] == 'o' && board[i][2] == '-') {
			board[i][2] = 'x'; return;
		}
		if (board[i][0] == 'o' && board[i][2] == 'o' && board[i][1] == '-') {
			board[i][1] = 'x'; return;
		}
		if (board[i][1] == 'o' && board[i][2] == 'o' && board[i][0] == '-') {
			board[i][0] = 'x'; return;
		}
	}
	// check the cols
	for (int i = 0; i < 3; i++) {
		if (board[0][i] == 'o' && board[1][i] == 'o' && board[2][i] == '-') {
			board[2][i] = 'x'; return;
		}
		if (board[0][i] == 'o' && board[2][i] == 'o' && board[1][i] == '-') {
			board[1][i] = 'x'; return;
		}
		if (board[1][i] == 'o' && board[2][i] == 'o' && board[0][i] == '-') {
			board[0][i] = 'x'; return;
		}
	}
	// check the upper right diagonal
	if (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == '-') {
		board[2][2] = 'x'; return;
	}
	if (board[0][0] == 'o' && board[2][2] == 'o' && board[1][1] == '-') {
		board[1][1] = 'x'; return;
	}
	if (board[1][1] == 'o' && board[2][2] == 'o' && board[0][0] == '-') {
		board[0][0] = 'x'; return;
	}
	// check the upper left diagonal
	if (board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == '-') {
		board[2][0] = 'x'; return;
	}
	if (board[0][2] == 'o' && board[2][0] == 'o' && board[1][1] == '-') {
		board[1][1] = 'x'; return;
	}
	if (board[1][1] == 'o' && board[2][0] == 'o' && board[0][2] == '-') {
		board[0][2] = 'x'; return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == '-') {
				board[i][j] = 'x';
				return;
			}
		}
	}
}
// check the winner
bool winCheck(char board[3][3]) {
	// board's data change to number
	char number[3][3] = {
		{board[0][0],board[0][1],board[0][2] },
		{board[1][0],board[1][1],board[1][2] },
		{board[2][0],board[2][1],board[2][2] }
	};
	for (int i = 1; i < 10; i++) {
		if (number[(i - 1) / 3][(i - 1) % 3] == 'o') {
			number[(i - 1) / 3][(i - 1) % 3] = 1;
		}
		else if (number[(i - 1) / 3][(i - 1) % 3] == 'x') {
			number[(i - 1) / 3][(i - 1) % 3] = -1;
		}
		else {
			number[(i - 1) / 3][(i - 1) % 3] = 0;
		}
		//check the row
		for (int i = 0; i < 3; i++) {
			if (number[i][0] + number[i][1] + number[i][2] == 3) {
				cout << "winner is the o!" << endl;
				return true;
			}
			else if (number[i][0] + number[i][1] + number[i][2] == -3) {
				cout << "winner is the x!" << endl;
				return true;
			}
		}
		//check the col
		for (int i = 0; i < 3; i++) {
			if (number[0][i] + number[1][i] + number[2][i] == 3) {
				cout << "winner is the o!" << endl;
				return true;
			}
			else if (number[0][i] + number[1][i] + number[2][i] == -3) {
				cout << "winner is the x!" << endl;
				return true;
			}
		}
		//check the upper right diagonal
		if (number[0][2] + number[1][1] + number[2][0] == 3) {
			cout << "winner is the o!" << endl;
			return  true;
		}
		else if (number[0][2] + number[1][1] + number[2][0] == -3) {
			cout << "winner is the x!" << endl;
			return true;
		}
		//check the upper left diagonal
		if (number[0][0] + number[1][1] + number[2][2] == 3) {
			cout << "winner is the o!" << endl;
			return true;
		}
		else if (number[0][0] + number[1][1] + number[2][2] == -3) {
			cout << "winner is the x!" << endl;
			return true;
		}
	}
	return false;
}

void showBoard(char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;

	}
}

bool checkAction(char board[3][3], string answer) {
	if (answer.length() == 1 && isdigit(answer[0])&&
		board[(stoi(answer) - 1) / 3][(stoi(answer) - 1) % 3 ] == '-' &&
		stoi(answer) >= 1 && stoi(answer) <= 9) {

		return true;
	}
	else {
		return false;
	}
}

void setAction(char board[3][3], string answer) {
	board[(stoi(answer) - 1) / 3][(stoi(answer) - 1) % 3] = 'o';
}

bool getO(char board[3][3], string& answer) {
	cout << "What do you pick? (1-9): ";
	cin >> answer;
	if (!checkAction(board, answer)) {
		cout << "Give me a valid action." << endl;
		return false;
	}
	else {
		return true;
	}
}

int main() {
	char board[3][3] = {
		{'-','-','-'},
		{'-','-','-'},
		{'-','-','-'}
	};

	for (int t = 0; t < 9; t++) {

		showBoard(board);
		if (winCheck(board)) {
			break;
		}
		if (t % 2 == 0) {
			string answer;
			while (!getO(board, answer)) {
			}
			setAction(board, answer);
		}
		else {
			cout << endl << "AI's turn." << endl;
			thinking(board, t);
		}
	}

	//showBoard(board);

	return 0;
}


