#include "PassengerTrain.h"
#include "Plain.h"
#include "Base.h"
#include "Vector.h"
#include <iostream>

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
    system("chcp 65001");

    // Перевірка роботи з простими типами
    Vector<int> intVector;
    intVector.push_back(4);
    intVector.push_back(1);
    for (int i = 0; i < intVector.getSize(); i++) {
        cout << intVector[i] << " ";
    }
    cout << endl;

    // Перевірка роботи з класами PassengerTrain та Plain
    Vector<Base*> mediaVector;

    while (true) {
        int choice = showMenu();
        if (choice == 3) {
            break;
        }

        switch (choice) {
            case 1: {
                PassengerTrain* train = new PassengerTrain();
                cin >> *train;
                mediaVector.push_back(train);
                break;
            }
            case 2: {
                Plain* plane = new Plain();
                cin >> *plane;
                mediaVector.push_back(plane);
                break;
            }
            default:
                cout << "Неправильний вибір, спробуйте ще раз.\n";
            continue;
        }
    }

    cout << "\nІнформація про об'єкти:\n";
    for (int i = 0; i < mediaVector.getSize(); i++) {
        mediaVector[i]->displayBaseInfo();
    }

    cout << "\nВиклик чисто віртуального методу:\n";
    for (int i = 0; i < mediaVector.getSize(); i++) {
        mediaVector[i]->somePureVirtualMethod();
    }

    for (int i = 0; i < mediaVector.getSize(); i++) {
        delete mediaVector[i];
    }

    return 0;
}
