#include<iostream>
#include "chessnecessities.h"


class check {
public:
	int dangerlvl = NULL;
	int value = NULL;
	int points = NULL;
	

};

int chsnm2val(std::string chessname) {
	if (chessname == "pawn") { return 1; }
	if (chessname == "tower") { return 2; }
	if (chessname == "bischop") { return 3; }
	if (chessname == "knight") { return 4; }
	if (chessname == "queen") { return 5; }
	if (chessname == "king") { return 6; }
	return 0;
}
void mov_tower(check val[][8], int posX, int posY) {
	int choices[2];
	for (int i = 0; i <= sizeof(val) / sizeof(val[0]) - posY;  i++) {
		if (posX > 8 || posY > 8) break;
		if (val[posX][posY + i].value > 0) {
			choices[1] = val[posX][posY + i].value;
			std::cout << choices[1];

			break;
		}
	}
}
void standardsetup_blk(check val[][8]) {
	// position generating: 
	val[0][0].value = chsnm2val("tower");
	val[0][7].value = chsnm2val("tower");
	val[0][1].value = chsnm2val("bischop");
	val[0][6].value = chsnm2val("bischop");
	val[0][2].value = chsnm2val("knight");
	val[0][5].value = chsnm2val("knight");
	val[0][3].value = chsnm2val("queen");
	val[0][4].value = chsnm2val("king");
	for (int i = 0; i < 8; i++)
		val[1][i].value = chsnm2val("pawn");
}

void standardsetup_wit(check val[][8]) {
	// position generating: 
	val[7][0].value = chsnm2val("tower");
	val[7][7].value = chsnm2val("tower");
	val[7][1].value = chsnm2val("bischop");
	val[7][6].value = chsnm2val("bischop");
	val[7][2].value = chsnm2val("knight");
	val[7][5].value = chsnm2val("knight");
	val[7][3].value = chsnm2val("queen");
	val[7][4].value = chsnm2val("king");
	for (int i = 0; i < 8; i++)
		val[6][i].value = chsnm2val("pawn");
}

int main() {
	check chess[8][8];
	
	for (int i = 2; i <= 6; i++) {
		for (int f = 0; f <= 8; f++) {
			chess[i][f].value = 0;
		}
	}
	standardsetup_blk(chess);
	standardsetup_wit(chess);
	for (int i = 0; i < 8; i++) {
		for (int f = 0; f < 8; f++) {
			std::cout << " " << chess[i][f].value;
		}
		std::cout << "\n";
	}
	for (int i = 0; i < 8; i++) {
		for (int f = 0; f < 8; f++) {
			if (i >= 6 && chess[i][f].value == chsnm2val("tower")) {
				mov_tower(chess, f, i);
			}
		}
		std::cout << "\n";
	}
	return 0;
	
}
