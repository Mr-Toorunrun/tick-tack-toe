#pragma once
#include <iostream>
using namespace std;





class Board {

public:

	Board();
	static bool winCheck(char board[3][3]);

	static bool getZero(char board[3][3], string& answer);

	static void showBoard(char board[3][3]);





};

