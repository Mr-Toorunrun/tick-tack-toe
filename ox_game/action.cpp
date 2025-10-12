#include <iostream>
#include <array>
#include <string>

#include "action.h"

using namespace std;

class Action
{
	Action();
	
	static void thinking(char board[3][3], int t) {
		if (t < 2) {
			if (board[1][1] == '-') {
				board[1][1] = 'x';
				return;
			}

		}
		//win
		// check the rows
		for (int i = 0; i < 3; i++) {
			if (board[i][0] == 'x' && board[i][1] == 'x' && board[i][2] == '-') {
				board[i][2] = 'x'; return;
			}
			if (board[i][0] == 'x' && board[i][2] == 'x' && board[i][1] == '-') {
				board[i][1] = 'x'; return;
			}
			if (board[i][1] == 'x' && board[i][2] == 'x' && board[i][0] == '-') {
				board[i][0] = 'x'; return;
			}
		}
		// check the cols
		for (int i = 0; i < 3; i++) {
			if (board[0][i] == 'x' && board[1][i] == 'x' && board[2][i] == '-') {
				board[2][i] = 'x'; return;
			}
			if (board[0][i] == 'x' && board[2][i] == 'x' && board[1][i] == '-') {
				board[1][i] = 'x'; return;
			}
			if (board[1][i] == 'x' && board[2][i] == 'x' && board[0][i] == '-') {
				board[0][i] = 'x'; return;
			}
		}
		// check the upper right diagonal
		if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == '-') {
			board[2][2] = 'x'; return;
		}
		if (board[0][0] == 'x' && board[2][2] == 'x' && board[1][1] == '-') {
			board[1][1] = 'x'; return;
		}
		if (board[1][1] == 'x' && board[2][2] == 'x' && board[0][0] == '-') {
			board[0][0] = 'x'; return;
		}
		// check the upper left diagonal
		if (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == '-') {
			board[2][0] = 'x'; return;
		}
		if (board[0][2] == 'x' && board[2][0] == 'x' && board[1][1] == '-') {
			board[1][1] = 'x'; return;
		}
		if (board[1][1] == 'x' && board[2][0] == 'x' && board[0][2] == '-') {
			board[0][2] = 'x'; return;
		}
		//lose
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


		if (board[0][0] == '-') {
			board[0][0] = 'x';
			return;
		}
		if (board[0][2] == '-') {
			board[0][2] = 'x';
			return;
		}
		if (board[2][0] == '-') {
			board[2][0] = 'x';
			return;
		}
		if (board[2][2] == '-') {
			board[2][2] = 'x';
			return;
		}


	}

	static bool checkAction(char board[3][3], string answer) {
		if (answer.length() == 1 && isdigit(answer[0]) &&
			board[(stoi(answer) - 1) / 3][(stoi(answer) - 1) % 3] == '-' &&
			stoi(answer) >= 1 && stoi(answer) <= 9) {

			return true;
		}
		else {
			return false;
		}
	}


	static void setAction(char board[3][3], string answer) {
		board[(stoi(answer) - 1) / 3][(stoi(answer) - 1) % 3] = 'o';
	}




};



