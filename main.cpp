#include <iostream>
#include "modem.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");


    cout << "=== Тестирование класса Modem ===" << endl;
    

    Modem myModem("Cisco", "DPC3008", ModemType::Cable, 
                 ConnectionStandard::DOCSIS, 340.0);


    myModem.displayInfo();
    

    cout << "\n=== Тестирование методов ===" << endl;
    myModem.powerOn();
    myModem.connect();
    myModem.disconnect();
    myModem.powerOff();
    

    cout << "\n=== Тестирование конструктора копирования ===" << endl;
    Modem copiedModem = myModem;
    copiedModem.displayInfo();
    

    cout << "\n=== Тестирование оператора присваивания ===" << endl;
    Modem assignedModem;
    assignedModem = myModem;
    assignedModem.displayInfo();

    
    cout << "\n=== Тестирование перегрузки оператора вывода ===" << endl;
    cout << "Модем: " << myModem << endl;
    
    return 0;
}