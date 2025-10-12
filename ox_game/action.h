#pragma once
#include <iostream>
using namespace std;


class Action {

public:

	Action();
	static bool checkAction(char board[3][3], string answer);

	static void setAction(char board[3][3], string answer);

	static void thinking(char board[3][3], int t);



};