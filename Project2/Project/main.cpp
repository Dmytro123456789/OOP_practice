#include "PassengerTrain.h"
#include "Plain.h"
#include "Vector.h"
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int showMenu() {
    int choice;
    cout << "Виберіть тип об'єкта для створення:\n";
    cout << "1. Пасажирський поїзд\n";
    cout << "2. Літак\n";
    cout << "3. Вихід\n";
    cin >> choice;
    return choice;
}

int main() {
    srand(0);
    system("chcp 65001");

    vector<int> vector1;
    for (int i = 0; i < 10; i++) {
        vector1.push_back(2 * (i * 3 + 1) + 1);
    }

    vector<int> vector2(10);
    vector<int>::iterator it = vector2.begin();
    while (it != vector2.end()) {
        *it = rand() % 100;
        *it = *it % 2 == 0 ? *it : *it + 1;
        ++it;
    }

    sort(vector1.begin(), vector1.end());
    sort(vector2.begin(), vector2.end());
    vector<int> vector3;
    merge(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), back_inserter(vector3));

    cout << "Vector 1: " << endl;
    for (auto n : vector1) {
        cout << n << " ";
    }
    cout << endl;

    cout << "Vector 2: " << endl;
    for (auto n : vector2) {
        cout << n << " ";
    }
    cout << endl;

    cout << "Vector 3: " << endl;
    for (auto n : vector3) {
        cout << n << " ";
    }
    cout << endl;

    vector<Base*> baseVector;
    int choice = 0;
    while (choice != 3) {
        choice = showMenu();
        switch (choice) {
            case 1: {
                PassengerTrain* train = new PassengerTrain();
                cin >> *train;
                baseVector.push_back(train);
                break;
            }
            case 2: {
                Plain* plane = new Plain();
                cin >> *plane;
                baseVector.push_back(plane);
                break;
            }
            case 3:
                break;
            default:
                cout << "Невірний вибір" << endl;
        }
    }

    vector<Base*> baseVector2(baseVector);
    vector<Base*>::iterator baseIterator1 = baseVector.begin();
    vector<Base*>::iterator baseIterator2 = baseVector2.begin();

    while (baseIterator1 != baseVector.end()) {
        if (dynamic_cast<PassengerTrain*>(*baseIterator1)) {
            baseIterator1 = baseVector.erase(baseIterator1);
        } else {
            ++baseIterator1;
        }
    }

    while (baseIterator2 != baseVector2.end()) {
        if (dynamic_cast<Plain*>(*baseIterator2)) {
            baseIterator2 = baseVector2.erase(baseIterator2);
        } else {
            ++baseIterator2;
        }
    }

    cout << "Base vector 1:" << endl;
    for (auto base : baseVector) {
        if (auto* train = dynamic_cast<PassengerTrain*>(base)) {
            cout << *train << endl;
            train->showInfo();
        } else if (auto* plane = dynamic_cast<Plain*>(base)) {
            cout << *plane << endl;
            plane->showInfo();
        }
    }

    cout << endl;
    cout << "Base vector 2: " << endl;
    for (auto base : baseVector2) {
        if (auto* train = dynamic_cast<PassengerTrain*>(base)) {
            cout << *train << endl;
            train->showInfo();
        } else if (auto* plane = dynamic_cast<Plain*>(base)) {
            cout << *plane << endl;
            plane->showInfo();
        }
    }

    return 0;
}
