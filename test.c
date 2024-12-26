#include <stdio.h>

#define N 20 // You can change this value to any positive integer

int isSafe(int board[N][N], int row, int col);
int solveNQUtil(int board[N][N], int col);
void printCol(int board[N][N], int row, int col);
void printRow(int board[N][N], int row);
void printSolution(int board[N][N]);
int solveNQ();

int isSafe(int board[N][N], int row, int col) {
    // Check this row on the left side
    if (col > 0) {
        int c = col - 1;
        if (board[row][c]) return 0;
    }

    // Check upper diagonal on the left side
    if (row > 0 && col > 0) {
        int r = row - 1;
        int c = col - 1;
        while (r >= 0 && c >= 0) {
            if (board[r][c]) return 0;
            r--; c--;
        }
    }

    // Check lower diagonal on the left side
    if (col > 0) {
        int r = row + 1;
        int c = col - 1;
        while (r < N && c >= 0) {
            if (board[r][c]) return 0;
            r++; c--;
        }
    }

    return 1;
}

int placeQueens(int board[N][N], int col, int row) {
    if (row >= N)
        return 0;

    if (isSafe(board, row, col)) {
        board[row][col] = 1;

        if (solveNQUtil(board, col + 1))
            return 1;

        board[row][col] = 0; // BACKTRACK
    }

    return placeQueens(board, col, row + 1); // Move to the next row
}

int solveNQUtil(int board[N][N], int col) {
    if (col >= N)
        return 1;

    return placeQueens(board, col, 0); // Start from the first row
}

void printCol(int board[N][N], int row, int col) {
    if (col >= N) {
        printf("\n");
        printRow(board, row + 1);
        return;
    }

    printf(board[row][col] ? "X " : "* ");
    printCol(board, row, col + 1);
}

void printRow(int board[N][N], int row) {
    if (row >= N) {
        printf("\n");
        return;
    }

    printCol(board, row, 0); // Start from the first column
}

void printSolution(int board[N][N]) {

    printRow(board, 0); // Start from the first row
}

int solveNQ() {
    int boardSize = 0;
    char board[N][N];

    // Get the size of the board
    printf("Please enter the board dimensions:\n");
    scanf("%d", &boardSize);

    if (boardSize > N) {
        printf("Size exceeds the maximum limit of 20.\n");
        return;
    }

    // Get the grid layout from the user
    printf("Please enter the %d*%d puzzle board\n", boardSize, boardSize);
    for (int i = 0; i < boardSize*boardSize; i++) {
        scanf(" %c", &board[i]);
        scanf("%*[^\n]");
        scanf("%*c");
    }

    if (!solveNQUtil(board, 0)) {
        printf("Solution does not exist\n");
        return 0;
    }

    printSolution(board);
    return 1;
}

int main() {
    solveNQ();
    return 0;
}
