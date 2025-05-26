//Добрий день!
//Арсеньєв Ілля 3-21 

//завдання за березень:
//Создать вектор 
//Заполнить вектор елеменами значение елементов = его индекс в кубе по модулю 10 
//Создать мапу которая считатает все елементы и повторяющиеся тоже

//код:
#include <iostream>
#include <vector>
#include <map>

void fillVect(std::vector<int> a, std::vector<int> result) {
    for (int i = 0; i < 20; i++) {
        int number = (i * i * i) % 10;
        result.push_back(number);
    }

    std::cout << "Елементи вектора: ";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    std::map<int, int> count;
    for (int i = 0; i < result.size(); i++) {
        int el = result[i];
        count[el] = count[el] + 1;
    }

    std::cout << "Кількість кожного елемента:" << std::endl;
    std::map<int, int>::iterator it = count.begin();
    while (it != count.end()) {
        std::cout << it->first << ": " << it->second << std::endl;
        it++;
    }
}

void run() {
    std::vector<int> temp;
    std::vector<int> res;
    fillVect(temp, res);
}

int main() {
    run();
    return 0;
}