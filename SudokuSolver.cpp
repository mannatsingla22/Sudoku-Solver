#include <iostream>
using namespace std;

#define N 9  // grid size

// checks if num is valid at board[row][col]
bool isValid(int board[N][N], int row, int col, int num) {
    // check row
    for (int x = 0; x < N; x++)
        if (board[row][x] == num)
            
            return false;
    
    // check column
    for (int x = 0; x < N; x++)
        if (board[x][col] == num)
            return false;

    // check 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;
    return true;
}

// Backtracking for solving Sudoku
bool solveSudoku(int board[N][N], int row, int col) {
    // if we've reached last row and column, it's solved
    if (row == N - 1 && col == N)
        return true;

    // move to next row if col exceeds 9
    if (col == N) {
        row++;
        col = 0;
    }

    // skip if already filled
    if (board[row][col] != 0)
        return solveSudoku(board, row, col + 1);

    // try 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board, row, col + 1))
                return true;

            board[row][col] = 0;  // backtrack
        }
    }
    return false;
}

void printGrid(int board[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++)
            cout << board[r][d] << " ";
        cout << endl;
    }
}

int main() {
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board, 0, 0)) {
        printGrid(board);
    } else {
        cout << "No solution exists" << endl;
    }
    return 0;
}
