#include <iostream>

using namespace std;

int main() {
    int arr[] = {5, 7, 12, 4, 9};
    int size = 5;
    int value;

    cout << "Введіть значення для пошуку: ";
    cin >> value;

    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            cout << "Знайдено за індексом: " << i << endl;
            return 0;
        }
    }

    cout << "Значення не знайдено" << endl;
    return 0;
}
