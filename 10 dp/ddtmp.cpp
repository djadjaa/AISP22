#include <iostream>
#include <vector>
#include <set>

using namespace std;

void findSumPaths(vector<vector<int>>& matrix, int n, int i, int j, int sum, set<int>& sums) {
    sum += matrix[i][j]; // Dodajemo trenutni broj u zbir

    // Ako smo stigli do donjeg-desnog ugla, dodajemo zbir u set
    if (i == n - 1 && j == n - 1) {
        sums.insert(sum);
        return;
    }

    // Prolazimo moguće korake - desno i dolje
    if (j + 1 < n) {
        findSumPaths(matrix, n, i, j + 1, sum, sums); // Korak desno
    }
    if (i + 1 < n) {
        findSumPaths(matrix, n, i + 1, j, sum, sums); // Korak dolje
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    set<int> sums;
    findSumPaths(matrix, n, 0, 0, 0, sums); // Poziv funkcije za pretragu zbira

    // Ispisivanje svih mogućih zbirova
    for (int sum : sums) {
        cout << sum << endl;
    }

    return 0;
}
