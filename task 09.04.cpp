#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>

using namespace std;

map<int, int> graph;
int rangeMin, rangeMax;
ofstream file;

void drawGraph(string title) {
    file << title << endl;

    int maxCount = 0;
    for (int i = rangeMin; i <= rangeMax; i++) {
        if (graph[i] > maxCount) {
            maxCount = graph[i];
        }
    }

    for (int height = 20; height >= 1; height--) {
        for (int i = rangeMin; i <= rangeMax; i++) {
            double relativeHeight = (double)graph[i] / maxCount * 20;
            if (relativeHeight >= height) {
                file << "# ";
            } else {
                file << "  ";
            }
        }
        file << endl;
    }

    for (int i = rangeMin; i <= rangeMax; i++) {
        file << i << " ";
    }

    file << endl << endl;
}

int main() {
    int min;
    int max;
    int number;

    cout << "Введіть мінімальне число діапазону: ";
    cin >> min;

    cout << "Введіть максимальне число діапазону: ";
    cin >> max;

    cout << "Введіть кількість генерацій: ";
    cin >> number;

    srand(time(0));

    map<int, int> countRand;
    map<int, int> countUni;
    map<int, int> countNormal;

    for (int i = min; i <= max; i++) {
        countRand[i] = 0;
        countUni[i] = 0;
        countNormal[i] = 0;
    }

    for (int i = 0; i < number; i++) {
        int number = rand() % (max - min + 1) + min;
        countRand[number] = countRand[number] + 1;
    }

    default_random_engine generatorUniform(time(0) + 100);
    uniform_int_distribution<int> uniform(min, max);

    for (int i = 0; i < number; i++) {
        int number = uniform(generatorUniform);
        countUni[number] = countUni[number] + 1;
    }

    default_random_engine generatorNormal(time(0) + 200);
    double medium = (min + max) / 2.0;
    double difference = (max - min) / 6.0;

    normal_distribution<double> normal(medium, difference);

    for (int i = 0; i < number; i++) {
        int number = round(normal(generatorNormal));
        if (number >= min && number <= max) {
            countNormal[number] = countNormal[number] + 1;
        }
    }

    ofstream file;
    file.open("graphs.txt");

    if (!file.is_open()) {
        cout << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    rangeMin = min;
    rangeMax = max;

    graph = countRand;
    drawGraph("Графік: std::rand");

    graph = countUni;
    drawGraph("Графік: std::uniform_int_distribution");

    graph = countNormal;
    drawGraph("Графік: std::normal_distribution");

    file.close();
    cout << "Графіки збережено у файл graphs.txt" << endl;

    return 0;
}