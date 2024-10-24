#include <iostream>
#include "PassengerTrain.h"
#include "Plain.h"
#include "Base.h"

using namespace std;

void displayMenu() {
    cout << "Оберіть тип об'єкта для створення:" << endl;
    cout << "1. Пасажирський поїзд" << endl;
    cout << "2. Літак" << endl;
    cout << "3. Вихід" << endl;
}

int main() {
    system("chcp 65001");
    const int SIZE = 5;
    Base* objects[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        displayMenu();
        int choice;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            PassengerTrain* train = new PassengerTrain();
            cin >> *train;
            objects[i] = train;
            break;
        }
        case 2: {
            Plain* plane = new Plain();
            cin >> *plane;
            objects[i] = plane;
            break;
        }
        case 3:
            cout << "Вихід з програми." << endl;
            return 0;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз." << endl;
            --i;
            break;
        }
    }

    cout << "\nІнформація про створені об'єкти:\n" << endl;
    for (int i = 0; i < SIZE; ++i) {
        objects[i]->displayBaseInfo();  // Виклик displayBaseInfo замість displayInfo
        cout << endl;
    }

    cout << "Виклик чисто віртуального методу:\n" << endl;
    for (int i = 0; i < SIZE; ++i) {
        objects[i]->somePureVirtualMethod();
    }

    for (int i = 0; i < SIZE; ++i) {
        delete objects[i];
    }

    return 0;
}
