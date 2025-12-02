#include <iostream>
using namespace std;

bool isSafe(int grid[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

int main() {
    int grid[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    int row, col, num;

    while (true) {
        cout << "\nCurrent Sudoku:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }

        cout << "\nEnter row (0-8), col (0-8), number (1-9). Enter -1 to exit: ";
        cin >> row;
        if (row == -1) break;

        cin >> col >> num;

        if (grid[row][col] != 0) {
            cout << "Cell already filled!\n";
        } else if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            cout << "Move accepted!\n";
        } else {
            cout << "Invalid move!\n";
        }
    }
}
