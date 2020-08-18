/**
 * Tic-Tac-Toe Program
 *
 * By Liam Halpin
 */


#include <iostream>

using namespace std;

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int mark_board(int c, char m);
int check_win();
void create_board();

/**
 * Main function of Tic Tac Toe
 */
int main() {
	char repeat, mark;
	int i, choice;
	int player = 1;

	do {
		cout << "====  Tic Tac Toe ====" << endl << endl;

		cout << "Player 1 (X) vs. Player 2 (0)" << endl << endl;
		do {
			create_board();
			player = (player % 2) ? 1:2;

			// get player choice
			cout << "Player " << player << ", please enter a number (1-9): ";
			cin >> choice;

			mark = (player == 1) ? 'X' : 'O';

			if (mark_board(choice, mark) == 1) {
				i = check_win();
				player++;
			} else {
				player--;
				cin.ignore();
				cin.get();
			}
		} while (i == -1);

		if (i == 1) cout << "[!] Player " << --player << " wins!" << endl;
		else cout << "Game is a draw!\n\n" << endl;

		cin.ignore();

		cout << "Do you want to play again? (Y/N)";
		cin >> repeat;
	} while (repeat == 'Y' || repeat == 'y');
	return 0;
}

/**
 * Checks if the chosen square has been marked:
 *
 * returns 0 if square is occupied (invalid)
 * returns 1 if sqaure is not occupied (valid)
 */
int mark_board(int c, char m) {
	if (c == 1 && board[0] == '1') board[0] = m;
	else if (c == 2 && board[1] == '2') board[1] = m;
	else if (c == 3 && board[2] == '3') board[2] = m;
	else if (c == 4 && board[3] == '4') board[3] = m;
	else if (c == 5 && board[4] == '5') board[4] = m;
	else if (c == 6 && board[5] == '6') board[5] = m;
	else if (c == 7 && board[6] == '7') board[6] = m;
	else if (c == 8 && board[7] == '8') board[7] = m;
	else if (c == 9 && board[8] == '9') board[8] = m;
	else {
		cout << "Invalid move!";
		return 0;
	}
	// move valid
	return 1;
}

/**
 * Checks if a win state has been reached i.e. 3 'X' or 'O' in a row
 *
 * '-1' - no win, game continues
 * '0' - draw, game stops
 * '1' - win, game stops
 */
int check_win() {
	// Check horizontal
	if (board[0] == board[1] && board[1] == board[2]) return 1;
	if (board[3] == board[4] && board[4] == board[5]) return 1;
	if (board[6] == board[7] && board[7] == board[8]) return 1;

	// Check vertical
	if (board[0] == board[3] && board[3] == board[6]) return 1;
	if (board[1] == board[4] && board[4] == board[7]) return 1;
	if (board[2] == board[5] && board[5] == board[8]) return 1;

	// Check diagonal
	if (board[0] == board[4] && board[4] == board[8]) return 1;
	if (board[2] == board[4] && board[4] == board[6]) return 1;

	// check draw
	if (board[0] != '1' && board[1] != '2' && board[2] != '3'
		&& board[3] != '4' && board[4] != '5' && board[5] != '6'
		&& board[6] != '7' && board[7] != '8' && board[8] != '9') return 0;

	// no win condition yet
	return -1;
}

/**
 * Creates the starting 3x3 board for Tic Tac Toe
 */
void create_board() {
	system("cls");

	cout << "___________________" << endl;
	cout << "|     |     |     |" << endl;
	cout << "|  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  |" << endl;
	cout << "|_____|_____|_____|" << endl;
	cout << "|     |     |     |" << endl;
	cout << "|  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  |"  << endl;
	cout << "|_____|_____|_____|" << endl;
	cout << "|     |     |     |" << endl;
	cout << "|  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  |" << endl;
	cout << "|_____|_____|_____|" << endl;

}


/**
 *
 * Sample win output:
 * ___________________
 * |     |     |     |
 * |  X  |  O  |  X  |
 * |_____|_____|_____|
 * |     |     |     |
 * |  O  |  X  |  O  |
 * |_____|_____|_____|
 * |     |     |     |
 * |  X  |     |     |
 * |_____|_____|_____|
 *
 * Player 1 Wins!
 */
