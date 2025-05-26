#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream file("names.txt");

    if (!file.is_open()) {
        cout << "Помилка при відп=критті файла" << endl;
        return 1;
    }

    vector<string> namesVector;
    string lastName, firstName;

    while (file >> lastName >> firstName) {
        string fullName = lastName + " " + firstName;
        namesVector.push_back(fullName);
    }

    cout << "Імена в std::vector:" << endl;
    for (int i = 0; i < namesVector.size(); i++) {
        cout << namesVector[i] << endl;
    }

    int size = namesVector.size();
    string* namesArray = new string[size];

    for (int i = 0; i < size; i++) {
        namesArray[i] = namesVector[i];
    }

    cout << endl << "Імена в динамічному масиві:" << endl;
    for (int i = 0; i < size; i++) {
        cout << namesArray[i] << endl;
    }

    delete[] namesArray;
    file.close();
    return 0;
}
