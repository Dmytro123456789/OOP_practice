#include <iostream>
#include "PassengerTrain.h"

using namespace std;

int main() {
    system("chcp 65001");

    PassengerTrain train1;

    PassengerTrain train2(1, 12345, "ІнтерСіті", "10:30", "Київ", "Львів", "Київ - Львів", 5.5, 100, 20, 30, 10);

    cout << "ID поїзда: " << train2.getId() << endl;
    cout << "Номер поїзда: " << train2.getTrainNumber() << endl;
    cout << "Назва поїзда: " << train2.getName() << endl;
    cout << "Час відправки: " << train2.getDepartureTime() << endl;
    cout << "Станція відправлення: " << train2.getDepartureStation() << endl;
    cout << "Станція призначення: " << train2.getDestinationStation() << endl;
    cout << "Маршрут: " << train2.getRoute() << endl;
    cout << "Тривалість подорожі: " << train2.getTravelDuration() << " годин" << endl;
    cout << "Загальні місця: " << train2.getGeneralSeats() << endl;
    cout << "Купе місця: " << train2.getCoupeSeats() << endl;
    cout << "Плацкарт місця: " << train2.getReservedSeats() << endl;
    cout << "Люкс місця: " << train2.getLuxurySeats() << endl;

    train2.setName("ІнтерСіті+");
    train2.setGeneralSeats(120);

    cout << "\nОновлена назва поїзда: " << train2.getName() << endl;
    cout << "Оновлені загальні місця: " << train2.getGeneralSeats() << endl;

    return 0;
}
