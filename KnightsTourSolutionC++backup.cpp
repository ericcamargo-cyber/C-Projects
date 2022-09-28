#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define NUM 4

int MoveCheck (int x, int y, int grid[NUM][NUM]){

	return (x >= 0 && x < NUM && y >= 0 && y < NUM
			&& grid[x][y] == 0);//changed from -1
}

void PrintSolution (int grid[NUM][NUM]) {
	for (int x = 0 ; x < NUM; x++) {
		for (int y = 0 ; y < NUM; y++) {
			cout << " " << setw(4) << grid[x][y] << " ";
		
		}
		cout << endl;
	}
}
int KnightTourSolver (int x , int y , int grid[NUM][NUM] , int RowMove[NUM] , int ColMove[NUM] , int moveidx ) {
	int xNext;
	int yNext;
	if (moveidx == (NUM * NUM)){
		return 1;
	}
	for (int i = 0; i < NUM; i++) {
		xNext = x + RowMove [i];
		yNext = y + ColMove [i];
		if (MoveCheck(xNext , yNext , grid) == 1) {
			grid[xNext][yNext] = moveidx + 1;
			if (KnightTourSolver (xNext , yNext , grid , RowMove, ColMove, moveidx + 1 ) == 1) {
				return 1;
			}
			else {
				grid [xNext][yNext] = 0;
			}
		}
	}
	return 0;
}

int KnightTourSolution () {
	int grid[NUM][NUM];
	int RowMove[8] = {2 , 2 , 1 , 1 , -2 , -1 , -1, -2};
	int ColMove[8] = {1 , -1 , -2 , 2 , -1, -2 , 2 , 1};
	for (int x = 0; x < NUM; x++) {
		for (int y = 0; y < NUM; y++ ){
			grid[x][y] = 0;
		}
	
	}
	grid[0][0] = 1;
	
	//run KnightTourInit and if the move # equals 64, then print the soltuion, if not
	//then print "no solution
	if (KnightTourSolver(0 , 0 , grid , RowMove, ColMove, 1) == 1) { 
		PrintSolution(grid)	;
	}
	else {
		cout << "Solution Not Found";
	} 
	
};




int main() {
	KnightTourSolution();
	return 0;
}
