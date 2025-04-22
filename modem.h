#ifndef MODEM_H
#define MODEM_H

#include <iostream>
#include <string>

// Перечисление типов модемов
enum class ModemType {
    DialUp,
    DSL,
    Cable,
    Fiber,
    Wireless
};

// Перечисление стандартов связи
enum class ConnectionStandard {
    V32,
    V34,
    V90,
    ADSL,
    VDSL,
    DOCSIS,
    LTE,
    WiFi
};

class Modem {
private:
    std::string manufacturer;    // Производитель
    std::string model;           // Модель
    ModemType type;              // Тип модема
    ConnectionStandard standard; // Стандарт связи
    double maxSpeed;             // Максимальная скорость (Мбит/с)
    bool isConnected;            // Состояние подключения
    bool isPoweredOn;            // Состояние питания

public:
    // Конструкторы
    Modem();
    Modem(const std::string& manuf, const std::string& mdl, ModemType tp, 
          ConnectionStandard std, double speed);
    Modem(const Modem& other); // Конструктор копирования
    ~Modem(); // Деструктор

    // Методы доступа к свойствам
    void setManufacturer(const std::string& manuf);
    std::string getManufacturer() const;
    
    void setModel(const std::string& mdl);
    std::string getModel() const;
    
    void setType(ModemType tp);
    ModemType getType() const;
    std::string getTypeString() const;
    
    void setStandard(ConnectionStandard std);
    ConnectionStandard getStandard() const;
    std::string getStandardString() const;
    
    void setMaxSpeed(double speed);
    double getMaxSpeed() const;
    
    bool getConnectionStatus() const;
    bool getPowerStatus() const;

    // Методы работы модема
    void powerOn();
    void powerOff();
    void connect();
    void disconnect();
    
    // Перегрузка оператора присваивания
    Modem& operator=(const Modem& other);
    
    // Метод вывода информации
    void displayInfo() const;
    
    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Modem& modem);
};

#endif // MODEM_H