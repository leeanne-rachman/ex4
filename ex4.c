/******************
Name: Lee Anne Rachman
ID: 323917286
Assignment: 4
*******************/
#include <stdio.h>
#define PYRAMID_MAX_LEVEL 5

//this function sends a row and a column number to a function which calculates the unique paths of a grid
void task1RobotPaths();

//this function calculates the unique patterns of a grid, given the column and row number
int calculatePaths(int column, int row);

void task2HumanPyramid();

float callCalculateWeights(float weights[PYRAMID_MAX_LEVEL][PYRAMID_MAX_LEVEL], int weightsLength);

float calculateWeights(float weights[PYRAMID_MAX_LEVEL][PYRAMID_MAX_LEVEL], int level, int index);

void task3ParenthesisValidator();

int validateParentheses();

int findMatchingClosing(char open);

void task4QueensBattle();

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
    float weights[pyramidSize][pyramidSize];
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

//start 3

// Recursive function to find the matching closing parenthesis
int findMatchingClosing(char open) {
    char c;
    scanf("%c", &c); // Read one character, ignoring leading whitespace

    if (c == '\n') {
        // End of input; no matching closing parenthesis found
        return 0;
    }

    if (open == '(' && c == ')') return 1;
    if (open == '[' && c == ']') return 1;
    if (open == '{' && c == '}') return 1;
    if (open == '<' && c == '>') return 1;

    if (c == '(' || c == '[' || c == '{' || c == '<') {
        // Found a nested opening parenthesis, so we need to find its matching closing parenthesis first
        if (findMatchingClosing(c) == 0) {
            return 0; // Unbalanced parentheses inside
        }
        // Continue looking for the matching closing parenthesis for the original opening
        return findMatchingClosing(open);
    }

    if (c == ')' || c == ']' || c == '}' || c == '>') {
        return 0; // Unbalanced closing parenthesis
    }

    // Ignore non-parenthesis characters and continue looking for the matching closing parenthesis
    return findMatchingClosing(open);
}

// Recursive function to validate parentheses
int validateParentheses() {
    char c;
    scanf("%c", &c); // Read one character, ignoring leading whitespace
    if (c == '\n') {
        // End of input; all parentheses matched correctly
        return 1;
    }
    if (c == '(' || c == '[' || c == '{' || c == '<') {
        // Read the matching closing parenthesis
        if (findMatchingClosing(c) == 0) {
            return 0; // Unbalanced parentheses
        }
    } else if (c == ')' || c == ']' || c == '}' || c == '>') {
        return 0; // Unbalanced closing parenthesis found without matching opening
    }

    // Ignore non-parenthesis characters and continue checking
    return validateParentheses();
}

void task3ParenthesisValidator() {
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Please enter a term for validation:\n");
    // Call the recursive function to validate parentheses
    if (validateParentheses()) {
        printf("The parentheses are balanced correctly\n");
    } else {
        printf("The parentheses are not balanced correctly\n");
    }
}

void task4QueensBattle() {
    // Todo
}

void task5CrosswordGenerator() {
    // Todo
}
