#include <iostream>
#include <array>
#include <string>
#include "board.cpp"
#include "action.cpp"
using namespace std;




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
			while (!getZero(board, answer)) {
			}
			setAction(board, answer);
		}
		else {
			cout << endl << "AI's turn." << endl;
			thinking(board, t);
		};
	}
	
	//showBoard(board);

	return 0;
}


