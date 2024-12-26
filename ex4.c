/******************
Name: Lee Anne Rachman
ID: 323917286
Assignment: 4
*******************/
#include <stdio.h>
#define PYRAMID_MAX_LEVEL 5
#define MAX_BOARD_SIZE 20
#define ASCII_TOTAL 128

//this function sends a row and a column number to a function which calculates the unique paths of a grid
void task1RobotPaths();

//this function calculates the unique patterns of a grid, given the column and row number
int calculatePaths(int column, int row);

void task2HumanPyramid();

float callCalculateWeights(float weights[PYRAMID_MAX_LEVEL][PYRAMID_MAX_LEVEL], int weightsLength);

float calculateWeights(float weights[PYRAMID_MAX_LEVEL][PYRAMID_MAX_LEVEL], int level, int index);

//this function scans character by character and checks if the given term is parenthesis-valid
void task3ParenthesisValidator();

//this function validates the parentheses recursively
int validateParentheses();

//this function finds the matching closing parenthesis, given a parenthesis
int findMatchingClosing(char open);

void task4QueensBattle();

//function checks if diagonal already contains queen. Returns 1 if is free to place a queen
int isDiagonalValid(int result[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int columnIndex, int rowIndex, int size);

//this function manages all the checks in order to solve nqueens problem
int manageNQueens(int result[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size, int rowIndex, int columnIndex, int colorZones[],
                  char grid[][MAX_BOARD_SIZE], int occupiedColumns[MAX_BOARD_SIZE]);

//this function checks if it's possible to place a queen in certain index and returns 1 if it's ok to place
int canPlaceQueen(int result[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int columnIndex, int rowIndex, int size,
                  char grid[][MAX_BOARD_SIZE], int colorZones[ASCII_TOTAL], int occupiedColumns[MAX_BOARD_SIZE]);

int isColorValid(int colorZones[ASCII_TOTAL], char grid[][MAX_BOARD_SIZE], int rowIndex, int columnIndex);

//this function prints the result board
void printResultBoard(int result[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size);

void task5CrosswordGenerator();

int main() {
    int task = -1;
    do {
        printf("Choose an option:\n"
            "1. Robot Paths\n"
            "2. The Human Pyramid\n"
            "3. Parenthesis Validation\n"
            "4. Queens Battle\n"
            "5. Crossword Generator\n"
            "6. Exit\n");

        if (scanf("%d", &task)) {
            switch (task) {
                case 6:
                    printf("Goodbye!\n");
                    break;
                case 1:
                    task1RobotPaths();
                    break;
                case 2:
                    task2HumanPyramid();
                    break;
                case 3:
                    task3ParenthesisValidator();
                    break;
                case 4:
                    task4QueensBattle();
                    break;
                case 5:
                    task5CrosswordGenerator();
                    break;
                default:
                    printf("Please choose a task number from the list.\n");
                    break;
            }
        } else {
            scanf("%*s");
        }
    } while (task != 6);
}

void task1RobotPaths() {
    int sumPaths = 0;
    int column = 0;
    int row = 0;
    printf("Please enter the coordinates of the robot (column, row):\n");
    scanf(" %d %d", &column, &row);

    sumPaths = calculatePaths(column, row);
    printf("The total number of paths the robot can take to reach home is: %d\n", sumPaths);
}

int calculatePaths(int column, int row) {
    if (column < 0 || row < 0) {
        return 0;
    }

    if (column == 0 && row == 0) {
        return 1;
    }

    return calculatePaths(column - 1, row) + calculatePaths(column, row - 1);
}

void task2HumanPyramid() {
    int pyramidSize = PYRAMID_MAX_LEVEL;
    float weights[PYRAMID_MAX_LEVEL][PYRAMID_MAX_LEVEL];
    printf("Please enter the weights of the cheerleaders:\n");
    //loop to scan all the inputs
    for (int i = 0; i < pyramidSize; i++) {
        for (int j = 0; j < i + 1; j++) {
            float weight = 0;
            scanf("%f", &weight);
            if (weight < 0) {
                printf("Negative weights are not supported.\n");

                break;
            }
            weights[i][j] = weight;
        }
    }

    callCalculateWeights(weights, pyramidSize);
}

float callCalculateWeights(float weights[][PYRAMID_MAX_LEVEL], int weightsLength) {
    for (int i = 0; i < weightsLength; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%.2f ", calculateWeights(weights, i, j));
        }

        printf("\n");
    }
}

float calculateWeights(float weights[][PYRAMID_MAX_LEVEL], int level, int index) {
    double half = 0.5;
    if (level == 0) {
        return weights[level][index];
    }

    if (index == 0) {
        return half * calculateWeights(weights, level - 1, index) + weights[level][index];
    }

    if (index == level) {
        return half * calculateWeights(weights, level - 1, index - 1) + weights[level][index];
    }

    return half * calculateWeights(weights, level - 1, index) + half * calculateWeights(weights, level - 1, index - 1)
           + weights[level][index];
}

void task3ParenthesisValidator() {
    scanf("%*[^ \n]");
    scanf("%*c");
    printf("Please enter a term for validation:\n");
    if (validateParentheses()) {
        printf("The parentheses are balanced correctly\n");
    } else {
        printf("The parentheses are not balanced correctly\n");
    }
}

//changeNames of funcs in 3
int validateParentheses() {
    char character;
    scanf("%c", &character);
    if (character == '\n') {
        return 1;
    }
    if (character == '(' || character == '[' || character == '{' || character == '<') {
        if (findMatchingClosing(character) == 0) {
            return 0;
        }
    } else if (character == ')' || character == ']' || character == '}' || character == '>') {
        scanf("%*[^\n]");
        return 0;
    }

    // Ignore non-parenthesis character and continue to next character
    return validateParentheses();
}

int findMatchingClosing(char open) {
    char nextChar;
    scanf("%c", &nextChar);
    if (nextChar == '\n') {
        return 0;
    }

    if (open == '(' && nextChar == ')') return 1;
    if (open == '[' && nextChar == ']') return 1;
    if (open == '{' && nextChar == '}') return 1;
    if (open == '<' && nextChar == '>') return 1;

    //move to func
    if (nextChar == '(' || nextChar == '[' || nextChar == '{' || nextChar == '<') {
        if (findMatchingClosing(nextChar) == 0) {
            return 0;
        }
        return findMatchingClosing(open);
    }

    //move to func
    if (nextChar == ')' || nextChar == ']' || nextChar == '}' || nextChar == '>') {
        scanf("%*[^\n]");
        return 0;
    }

    return findMatchingClosing(open);
}

//change 128
void task4QueensBattle() {
    int boardSize = 0;
    char grid[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    int resultGrid[MAX_BOARD_SIZE][MAX_BOARD_SIZE] = {0};
    //magic number
    int colorZones[ASCII_TOTAL] = {0};
    int notSafeColumns[MAX_BOARD_SIZE] = {0};

    // Get the size of the board
    printf("Please enter the board dimensions:\n");
    scanf("%d", &boardSize);

    // Get the grid layout from the user
    printf("Please enter the %d*%d puzzle board\n", boardSize, boardSize);
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }

    if (manageNQueens(resultGrid, boardSize, 0, 0, colorZones, grid, notSafeColumns)) {
        printResultBoard(resultGrid, boardSize);
        return;
    }

    printf("This puzzle cannot be solved.\n");
}

int manageNQueens(int result[][MAX_BOARD_SIZE], int size, int rowIndex, int columnIndex, int colorZones[ASCII_TOTAL],
                  char grid[][MAX_BOARD_SIZE], int occupiedColumns[]) {
    if (rowIndex == size) {
        return 1; // All queens have been placed successfully
    }

    if (columnIndex == size) {
        return 0;  // No more columns to try for this row, backtrack
    }

    // Try placing a queen in the current column if valid
    if (rowIndex < size) {
        if (canPlaceQueen(result, columnIndex, rowIndex, size, grid, colorZones, occupiedColumns)) {
            result[rowIndex][columnIndex] = 1; // Place queen
            colorZones[(int) grid[rowIndex][columnIndex]]++;
            occupiedColumns[columnIndex]++;

            // Recursively place queens in the next row, starting from the first column
            if (manageNQueens(result, size, rowIndex + 1, 0, colorZones, grid, occupiedColumns)) {
                return 1; // If placing the queen leads to a solution, return true
            }

            // Backtrack: undo the queen placement
            result[rowIndex][columnIndex] = 0;
            colorZones[(int) grid[rowIndex][columnIndex]]--;
            occupiedColumns[columnIndex]--;
        }
        // Try the next column for the current row (using recursion)
        return manageNQueens(result, size, rowIndex, columnIndex + 1, colorZones, grid, occupiedColumns);
    }
    return 0;
}

int canPlaceQueen(int result[][MAX_BOARD_SIZE], int columnIndex, int rowIndex, int size, char grid[][MAX_BOARD_SIZE],
                  int colorZones[ASCII_TOTAL], int occupiedColumns[MAX_BOARD_SIZE]) {
    if (occupiedColumns[columnIndex] == 0) {
        if (isDiagonalValid(result, columnIndex, rowIndex, size)) {
            if (isColorValid(colorZones, grid, rowIndex, columnIndex))
                return 1;
        }
    }

    return 0;
}

int isColorValid(int colorZones[ASCII_TOTAL], char grid[][MAX_BOARD_SIZE], int rowIndex, int columnIndex) {
    if (colorZones[(int) grid[rowIndex][columnIndex]] > 0) {
        return 0;
    }

    return 1;
}

int isDiagonalValid(int result[][MAX_BOARD_SIZE], int columnIndex, int rowIndex, int size) {
    if (columnIndex >= size && rowIndex >= size) {
        return 0;
    }

    if (columnIndex == 0 && rowIndex == 0) {
        if (result[rowIndex + 1][columnIndex + 1] == 0) {
            return 1;
        }
    }

    if (columnIndex == 0) {
        if (result[rowIndex - 1][columnIndex + 1] == 0 && result[rowIndex + 1][columnIndex + 1] == 0) {
            return 1;
        }
    }

    if (rowIndex == 0) {
        if (result[rowIndex + 1][columnIndex - 1] == 0 && result[rowIndex + 1][columnIndex + 1] == 0) {
            return 1;
        }
    }

    if (result[rowIndex - 1][columnIndex + 1] == 0 && result[rowIndex - 1][columnIndex - 1] == 0 &&
        result[rowIndex + 1][columnIndex - 1] == 0 && result[rowIndex + 1][columnIndex + 1] == 0) {
        return 1;
    }

    return 0;
}

void printResultBoard(int result[][MAX_BOARD_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (result[i][j] == 1) {
                printf("X "); // Queen placed
            } else {
                printf("* "); // Empty space
            }
        }
        printf("\n");
    }
}

void task5CrosswordGenerator() {
    // Todo
}
