/*
 * Board.cpp
 *
 *  Created on: Oct 7, 2019
 *      Author: gustt
 */

#include "Board.h"

Board::Board() {
	ships[0] = new AircraftCarrier(0, 0, HORIZONTAL);
	ships[1] = new Battleship(2, 0, HORIZONTAL);
	ships[2] = new Cruiser(4, 0, HORIZONTAL);
	ships[3] = new Destroyer(6, 0, HORIZONTAL);
	ships[4] = new Submarine(8, 0, HORIZONTAL);

	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			board[row][col] = EMPTY;
		}
	}
	for (int shipN = 0; shipN < 5; shipN++) {
		int row = ships[shipN]->getRow();
		int col = ships[shipN]->getCol();
		for (int length = ships[shipN]->getLength(); length > 0; length--) {
			board[row][col] = shipN;
			if (ships[shipN]->getDirection() == HORIZONTAL)
				col++;
			else if (ships[shipN]->getDirection() == VERTICAL)
				row++;
		}
	}
}

Board::Board(bool isPlayer) {
	srand(time(NULL));
	ships[0] = new AircraftCarrier(0, 0, HORIZONTAL);
	ships[1] = new Battleship(0, 0, HORIZONTAL);
	ships[2] = new Cruiser(0, 0, HORIZONTAL);
	ships[3] = new Destroyer(0, 0, HORIZONTAL);
	ships[4] = new Submarine(0, 0, HORIZONTAL);
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			board[row][col] = EMPTY;
		}
	}
	int numSet = 0;
	while (numSet < 5) {
		int row;
		int col;
		if (!isPlayer) {
			row = rand() % (ROWS - ships[numSet]->getLength());
			col = rand() % (COLS - ships[numSet]->getLength());
			ships[numSet]->setDirection(rand() % 2);
		} else {
			fflush(stdout);
			printf("Please enter the row, column, and direction of the ");
			switch (numSet) {
			case 0:
				printf("Airplane Carrier of length 5");
				break;
			case 1:
				printf("Battleship of length 4");
				break;
			case 2:
				printf("Cruiser of length 3");
				break;
			case 3:
				printf("Destroyer of length 2");
				break;
			case 4:
				printf("Submarine Carrier of length 3");
				break;
			}
			printf("\nRow: \t");
			fflush(stdout);
			scanf("%d", &row);
			fflush(stdin);
			printf("Col: \t");
			fflush(stdout);
			scanf("%d", &col);
			fflush(stdin);
			printf("Direcion (Horizontal/Vertical: \t");
			fflush(stdout);
			char c;
			scanf("%c", &c);
			fflush(stdin);
			ships[numSet]->setDirection((c == 'h' || c == 'H') ? HORIZONTAL:VERTICAL);
			printf("Row %d, Col %d, Direction %c \n", row, col, (c == 'h' || c == 'H') ? 'H':'V');
		}

		ships[numSet]->setLocation(row, col);
		if (ships[numSet]->setLocation(row, col)) {
			bool isEmpty = true;
			for (int length = ships[numSet]->getLength(); length > 0; length--) {
				isEmpty &= (board[row][col] == EMPTY);
				if (ships[numSet]->getDirection() == HORIZONTAL)
					col++;
				else if (ships[numSet]->getDirection() == VERTICAL)
					row++;
			}
			if (isEmpty) {
				for (int length = ships[numSet]->getLength(); length > 0; length--) {
					if (ships[numSet]->getDirection() == HORIZONTAL)
						col--;
					else if (ships[numSet]->getDirection() == VERTICAL)
						row--;
					board[row][col] = numSet;
				}
				numSet++;
			}
		}
	}
}

bool Board::hasLost(){
	bool lost = false;
	for(Ship *ship: ships)
		lost |= ship->hasSunk();
	return lost;
}

bool Board::shot(int row, int col) {
	if (isShip(row, col)) {
		return ships[board[row][col]]->hit(row, col);
	} else if (isValid(row, col)) {
		board[row][col] = MISS;
	}
	return false;
}

bool Board::isHit(int row, int col) {
	return isShip(row, col) && ships[board[row][col]]->isHit(row, col);
}

bool Board::isShip(int row, int col) {
	return isValid(row, col) && board[row][col] < EMPTY;
}

bool Board::isValid(int row, int col) {
	return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

void Board::printBoard(bool canView) {
	for (int col = 0; col < COLS + 2; col++)
		printf("-");
	printf("\n");
	for (int row = 0; row < ROWS; row++) {
		printf("|");
		for (int col = 0; col < COLS; col++) {
			if ((isShip(row, col) && canView) || isHit(row, col))
				printf("%c", ships[board[row][col]]->toChar(row, col));
			else if (board[row][col] == MISS)
				printf("%c", '*');
			else
				printf("%c", '~');

		}
		printf("|\n");
	}
	for (int col = 0; col < COLS + 2; col++)
		printf("-");
	printf("\n\n");
}

void Board::filePrintBoard(bool canView) {
	FILE *outputP = fopen("output.txt", "r+");
	fseek(outputP, 0L, SEEK_END);
	fprintf(outputP, "\n\n\n\n");
	for (int col = 0; col < COLS + 2; col++)
		fprintf(outputP, "-");
	fprintf(outputP, "\n");
	for (int row = 0; row < ROWS; row++) {
		fprintf(outputP, "|");
		for (int col = 0; col < COLS; col++) {
			if ((isShip(row, col) && canView) || isHit(row, col))
				fprintf(outputP, "%c", ships[board[row][col]]->toChar(row, col));
			else if (board[row][col] == MISS)
				fprintf(outputP, "%c", '*');
			else
				fprintf(outputP, "%c", '~');
		}
		fprintf(outputP, "|\n");
	}
	for (int col = 0; col < COLS + 2; col++)
		fprintf(outputP, "-");
	fprintf(outputP, "\n\n");
	fclose(outputP);
}



