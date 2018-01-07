#include<iostream>
#include<vector>

using namespace std;

#define MAX_SIZ 256

class Board {
	private:
		int pR, pC;
		char board[MAX_SIZ][MAX_SIZ];
		vector<int> rolls;
		void winStub(vector<int> rolls){}
	public:
		void (*onWin)(vector<int>);
		Board(int r, int c){
			pR = pC = 0;
			//assigning stubs
			//onWin = winStub;

		}
		void setCell(int r, int c, char val){
			board[r][c] = val;
		}
		void roll(int rollVal){
			//update rolls
			rolls.push_back(rollVal);
			//calculate pR and pC using rollVal, pR and pC
			if(pR == pC == 0){
				onWin(rolls);
			}
		}
};

void win(vector<int> rolls){
	for(int i = 0; i < rolls.size(); i++){
		cout << rolls[i] << " ";
	}
	cout << endl;
}


int main(int argc, char *argv[]){
	int r, c, i, j;
//get r and c
	cin >> r >> c;

//board creation
	Board b(r, c);

//get vals for board
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			int val = 0;
			cin >> val;
			b.setCell(r, c, val);
		}
	}

//get vals for dice rolling
	int rolls[] = { 4, 5, 2, 1, 1, 6 };
	int rollLen = sizeof(rolls)/sizeof(int);
//print dice roll sequence required
	for(i = 0; i < rollLen; i++){
		b.roll(rolls[i]);
	}
	b.onWin = win;
}
