#include <iostream>
#include <vector>
using namespace std;

// Рекурзивна функција за генерисање бројева
void generateNumbers(int n, int num, vector<int>& result) {
    if (n == 0) {
        result.push_back(num);  // Додајемо генерисани број у резултат
        return;
    }

    // За сваку цифру од 0 до 3
    for (int i = 0; i < 4; i++) {
        // Проверавамо да ли је генерисани број погодан
        if ((num % 10) % 2 != i % 2) {
            int newNum = num * 10 + i;
            generateNumbers(n - 1, newNum, result);  // Рекурзивни позив за генерисање следеће цифре
        }
    }
}

int main() {
    int n;
    cout << "Unesite broj cifara (n): ";
    cin >> n;

    vector<int> result;
    generateNumbers(n, 0, result);  // Позивамо функцију за генерисање бројева

    // Исписујемо генерисане бројеве у лексикографском поретку
    cout << "Brojevi sa " << n << " cifara u sistemu sa osnovom 4 koji nemaju dve susjedne neparne cifre:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
