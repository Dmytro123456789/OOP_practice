#include <iostream>
#include "PassengerTrain.h"
#include "Plain.h"

using namespace std;

int main() {
    PassengerTrain object1, object2, object3;
    Plain plane;

    cout << "Введіть дані для першого поїзда:" << endl;
    cin >> object1;

    cout << "\nВведіть дані для другого поїзда:" << endl;
    cin >> object2;

    cout << "\nВведіть дані для третього поїзда:" << endl;
    cin >> object3;

    cout << "\nІнформація про поїзди:" << endl;
    cout << object1 << endl << object2 << endl << object3;

    if (object1 == object2) {
        cout << "\nПерший та другий поїзди рівні за всіма параметрами." << endl;
    } else {
        cout << "\nПерший та другий поїзди відрізняються." << endl;
    }

    if (object1 == object3) {
        cout << "Перший та третій поїзди рівні за всіма параметрами." << endl;
    } else {
        cout << "Перший та третій поїзди відрізняються." << endl;
    }

    cout << "\nВведіть дані для літака:" << endl;
    cin >> plane;

    cout << "\nІнформація про літак:" << endl;
    cout << plane << endl;

    return 0;
}
