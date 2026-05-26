#include <stdio.h>

#define MAX 20

int board[MAX][MAX];
int N;

// Function to check whether a queen can be placed safely
int isSafe(int row, int col) {

    int i, j;

    // Check column
    for (i = 0; i < row; i++) {
        if (board[i][col])
            return 0;
    }

    // Check upper left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return 0;
    }

    // Check upper right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j])
            return 0;
    }

    return 1;
}

// Backtracking function
int solveNQueens(int row) {

    int col;

    // All queens are placed
    if (row == N)
        return 1;

    // Try placing queen in each column
    for (col = 0; col < N; col++) {

        if (isSafe(row, col)) {

            // Place queen
            board[row][col] = 1;

            // Recur for next row
            if (solveNQueens(row + 1))
                return 1;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return 0;
}

// Function to print board
void printBoard() {

    int i, j;

    printf("\nSolution:\n\n");

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {

            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int main() {

    printf("Enter value of N: ");
    scanf("%d", &N);

    if (solveNQueens(0))
        printBoard();
    else
        printf("No solution exists.\n");

    return 0;
}
