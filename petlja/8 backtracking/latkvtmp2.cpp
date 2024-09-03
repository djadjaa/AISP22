#include <iostream>
#include <vector>

using namespace std;
const int N=5;
bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
    // Check if the number is already present in the same row or column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    return true;
}

// Backtracking function to solve the Latin Square problem
void solveLatinSquare(vector<vector<int>>& grid, int row, int col, int& solutionCount) {
    // Base case: if we have filled all positions, print the solution
    if (row == N - 1 && col == N) {
        cout << "Solution " << solutionCount << ":\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        solutionCount++;
        return;
    }

    // If we have reached the end of a row, move to the next row
    if (col == N) {
        row++;
        col = 0;
    }

    // Try to place numbers from 1 to N in the current position
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively check the next position
            solveLatinSquare(grid, row, col + 1, solutionCount);

            // Backtrack by undoing the current placement
            grid[row][col] = 0;
        }
    }
}

int main() {
    vector<vector<int>> grid(N, vector<int>(N, 0));
    int solutionCount = 1;

    solveLatinSquare(grid, 0, 0, solutionCount);

    if (solutionCount == 1) {
        cout << "No solution exists for the given Latin Square.\n";
    } else {
        cout << "Total solutions found: " << (solutionCount - 1) << endl;
    }

    return 0;
}
