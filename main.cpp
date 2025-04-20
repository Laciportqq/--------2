#include <iostream>
#include "modem.h"

using namespace std;

int main() {
    // Установка локализации для поддержки кириллицы
    setlocale(LC_ALL, "Russian");

    // Создание и тестирование модема
    cout << "=== Тестирование класса Modem с наследованием ===" << endl;
    
    // Создание модема с помощью конструктора с параметрами
    Modem myModem("Cisco", "DPC3008", ModemType::Cable, 
                 ConnectionStandard::DOCSIS, 340.0);
    
    // Вывод информации о модеме
    myModem.displayInfo();
    
    // Тестирование методов работы модема
    cout << "\n=== Тестирование методов ===" << endl;
    myModem.powerOn();
    myModem.connect();
    myModem.disconnect();
    myModem.powerOff();
    
    // Демонстрация полиморфизма
    cout << "\n=== Демонстрация полиморфизма ===" << endl;
    NetworkDevice* device = new Modem("TP-Link", "Archer VR600", 
                                    ModemType::DSL, ConnectionStandard::VDSL, 100.0);
    device->powerOn();
    device->displayInfo();
    device->powerOff();
    delete device;
    
    return 0;
}