#include <iostream>
#include "PassengerTrain.h"

using namespace std;

int main() {
    PassengerTrain object1, object2, object3;

    cout << "Введіть дані для першого поїзда:" << endl;
    cin >> object1;

    cout << "\nВведіть дані для другого поїзда:" << endl;
    cin >> object2;

    cout << "\nВведіть дані для третього поїзда:" << endl;
    cin >> object3;

    cout << "\nІнформація про поїзди:" << endl;
    cout << object1 << endl << object2 << endl << object3;

    return 0;
}
