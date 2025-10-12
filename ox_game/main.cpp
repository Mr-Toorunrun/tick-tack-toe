#include <iostream>
#include <array>
#include <string>
#include "board.h"
#include "action.h"
using namespace std;

int main() {
	char board[3][3] = {
		{'-','-','-'},
		{'-','-','-'},
		{'-','-','-'}
	};

	for (int t = 0; t < 9; t++) {

		Board::showBoard(board);
		if (Board::winCheck(board)) {
			break;
		}
		if (t % 2 == 0) {
			string answer;
			while (!Board::getZero(board, answer)) {
			}
			Action::setAction(board, answer);
		}
		else {
			cout << endl << "AI's turn." << endl;
			Action::thinking(board, t);
		};
	}
	if (!Board::winCheck(board)) {
		cout << endl << "No winner.";
	}
	//showBoard(board);

	return 0;
}


