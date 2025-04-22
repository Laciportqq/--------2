#include <iostream>
#include "modem.h"
#include <windows.h> 
#include <locale.h>  

using namespace std;

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Создание и тестирование модема
    cout << "=== Тестирование класса Modem ===" << endl;
    
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
    
    // Тестирование конструктора копирования
    cout << "\n=== Тестирование конструктора копирования ===" << endl;
    Modem copiedModem = myModem;
    copiedModem.displayInfo();
    
    // Тестирование оператора присваивания
    cout << "\n=== Тестирование оператора присваивания ===" << endl;
    Modem assignedModem;
    assignedModem = myModem;
    assignedModem.displayInfo();
    
    // Тестирование перегрузки оператора вывода
    cout << "\n=== Тестирование перегрузки оператора вывода ===" << endl;
    cout << "Модем: " << myModem << endl;
    
    system("pause");
    return 0;
}