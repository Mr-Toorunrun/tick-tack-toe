#include <iostream>
#include <array>
#include <string>
#include "action.h"

#include "board.h"

using namespace std;

class Board {

	// check the winner
	static bool winCheck(char board[3][3]) {
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
	static void showBoard(char board[3][3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << board[i][j] << ' ';
			}
			cout << endl;

		}
	}
	static bool getZero(char board[3][3], string& answer) {
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

};