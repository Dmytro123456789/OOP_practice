#include <iostream>
#include "PassengerTrain.h"

using namespace std;

int main() {
    system("chcp 65001");

    PassengerTrain object1, object2, object3;

    cout << "Введіть дані для першого поїзда:" << endl;
    cin >> object1;

    cout << "\nВведіть дані для другого поїзда:" << endl;
    cin >> object2;

    cout << "\nВведіть дані для третього поїзда:" << endl;
    cin >> object3;

    return 0;
}
