#include"ChessBoard.h"

#include<iostream>

using std::cout;

int main() {

	cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";

	ChessBoard cb;
	cout << '\n';

	cb.submitMove("D7", "D6");
	cout << '\n';

	cb.submitMove("D4", "H6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cout << '\n';

	cb.submitMove("F8", "B4");
	cout << '\n';

	cout << "=========================\n";
	cout << "Alekhine vs. Vasic (1931)\n";
	cout << "=========================\n\n";

	cb.resetBoard();
	cout << '\n';

	cb.submitMove("E2", "E4");
	cb.submitMove("E7", "E6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cb.submitMove("D7", "D5");
	cout << '\n';

	cb.submitMove("B1", "C3");
	cb.submitMove("F8", "B4");
	cout << '\n';

	cb.submitMove("F1", "D3");
	cb.submitMove("B4", "C3");
	cout << '\n';

	cb.submitMove("B2", "C3");
	cb.submitMove("H7", "H6");
	cout << '\n';

	cb.submitMove("C1", "A3");
	cb.submitMove("B8", "D7");
	cout << '\n';

	cb.submitMove("D1", "E2");
	cb.submitMove("D5", "E4");
	cout << '\n';

	cb.submitMove("D3", "E4");
	cb.submitMove("G8", "F6");
	cout << '\n';

	cb.submitMove("E4", "D3");
	cb.submitMove("B7", "B6");
	cout << '\n';

	cb.submitMove("E2", "E6");
	cb.submitMove("F7", "E6");
	cout << '\n';

	cb.submitMove("D3", "G6");
	cout << '\n';

	return 0;
}

// int main() {

// 	ChessBoard cb;

// 	cout << "=========================\n";
// 	cout << "Duke of Brunswick and Count Isouard\n";
// 	cout << "=========================\n\n";

// 	cb.resetBoard();
// 	cout << '\n';

// 	cb.submitMove("E2", "E4");
// 	cb.submitMove("E7", "E5");
// 	cout << '\n';

// 	cb.submitMove("G1", "F3");
// 	cb.submitMove("D7", "D6");
// 	cout << '\n';

// 	cb.submitMove("D2", "D4");
// 	cb.submitMove("C8", "G4");
// 	cout << '\n';

// 	cb.submitMove("D4", "E5");
// 	cb.submitMove("G4", "F3");
// 	cout << '\n';

// 	cb.submitMove("D1", "F3");
// 	cb.submitMove("D6", "E5");
// 	cout << '\n';

// 	cb.submitMove("F1", "C4");
// 	cb.submitMove("G8", "F6");
// 	cout << '\n';

// 	cb.submitMove("F3", "B3");
// 	cb.submitMove("D8", "E7");
// 	cout << '\n';

// 	cb.submitMove("B1", "C3");
// 	cb.submitMove("C7", "C6");
// 	cout << '\n';

// 	cb.submitMove("C1", "G5");
// 	cb.submitMove("B7", "B5");
// 	cout << '\n';

// 	cb.submitMove("C3", "B5");
// 	cb.submitMove("C6", "B5");
// 	cout << '\n';

// 	cb.submitMove("C4", "B5");
// 	cb.submitMove("B8", "D7");
// 	cout << '\n';

// 	cb.submitMove("E1", "C1");
// 	cb.submitMove("A8", "D8");
// 	cout << '\n';

// 	cb.submitMove("D1", "D7");
// 	cb.submitMove("D8", "D7");
// 	cout << '\n';

// 	cb.submitMove("H1", "D1");
// 	cb.submitMove("E7", "E6");
// 	cout << '\n';
	
// 	cb.submitMove("B5", "D7");
// 	cb.submitMove("F6", "D7");
// 	cout << '\n';

// 	cb.submitMove("B3", "B8");
// 	cb.submitMove("D7", "B8");
// 	cout << '\n';

// 	cb.submitMove("D1", "D8");
	
// 	return 0;
// }