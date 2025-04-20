#include "modem.h"
#include <iostream>


Modem::Modem() : manufacturer("Unknown"), model("Unknown"), 
                type(ModemType::DialUp), standard(ConnectionStandard::V32),
                maxSpeed(0.056), isConnected(false), isPoweredOn(false) {}

Modem::Modem(const std::string& manuf, const std::string& mdl, ModemType tp, 
             ConnectionStandard std, double speed) : 
    manufacturer(manuf), model(mdl), type(tp), standard(std), 
    maxSpeed(speed), isConnected(false), isPoweredOn(false) {}

Modem::Modem(const Modem& other) : 
    manufacturer(other.manufacturer), model(other.model), type(other.type),
    standard(other.standard), maxSpeed(other.maxSpeed), 
    isConnected(other.isConnected), isPoweredOn(other.isPoweredOn) {}

Modem::~Modem() {
    std::cout << "Модем " << manufacturer << " " << model << " выключен и уничтожен." << std::endl;
}


void Modem::setManufacturer(const std::string& manuf) {
    manufacturer = manuf;
}

std::string Modem::getManufacturer() const {
    return manufacturer;
}

void Modem::setModel(const std::string& mdl) {
    model = mdl;
}

std::string Modem::getModel() const {
    return model;
}

void Modem::setType(ModemType tp) {
    type = tp;
}

ModemType Modem::getType() const {
    return type;
}

std::string Modem::getTypeString() const {
    switch(type) {
        case ModemType::DialUp: return "Dial-Up";
        case ModemType::DSL: return "DSL";
        case ModemType::Cable: return "Cable";
        case ModemType::Fiber: return "Fiber";
        case ModemType::Wireless: return "Wireless";
        default: return "Unknown";
    }
}

void Modem::setStandard(ConnectionStandard std) {
    standard = std;
}

ConnectionStandard Modem::getStandard() const {
    return standard;
}

std::string Modem::getStandardString() const {
    switch(standard) {
        case ConnectionStandard::V32: return "V.32";
        case ConnectionStandard::V34: return "V.34";
        case ConnectionStandard::V90: return "V.90";
        case ConnectionStandard::ADSL: return "ADSL";
        case ConnectionStandard::VDSL: return "VDSL";
        case ConnectionStandard::DOCSIS: return "DOCSIS";
        case ConnectionStandard::LTE: return "LTE";
        case ConnectionStandard::WiFi: return "WiFi";
        default: return "Unknown";
    }
}

void Modem::setMaxSpeed(double speed) {
    maxSpeed = speed;
}

double Modem::getMaxSpeed() const {
    return maxSpeed;
}

bool Modem::getConnectionStatus() const {
    return isConnected;
}

bool Modem::getPowerStatus() const {
    return isPoweredOn;
}

void Modem::powerOn() {
    isPoweredOn = true;
    std::cout << "Модем включен." << std::endl;
}

void Modem::powerOff() {
    isPoweredOn = false;
    isConnected = false;
    std::cout << "Модем выключен." << std::endl;
}

void Modem::connect() {
    if (isPoweredOn) {
        isConnected = true;
        std::cout << "Установлено соединение. Скорость: " << maxSpeed << " Мбит/с" << std::endl;
    } else {
        std::cout << "Ошибка: модем выключен!" << std::endl;
    }
}

void Modem::disconnect() {
    isConnected = false;
    std::cout << "Соединение разорвано." << std::endl;
}

Modem& Modem::operator=(const Modem& other) {
    if (this != &other) {
        manufacturer = other.manufacturer;
        model = other.model;
        type = other.type;
        standard = other.standard;
        maxSpeed = other.maxSpeed;
        isConnected = other.isConnected;
        isPoweredOn = other.isPoweredOn;
    }
    return *this;
}


void Modem::displayInfo() const {
    std::cout << "=== Информация о модеме ===" << std::endl;
    std::cout << "Производитель: " << manufacturer << std::endl;
    std::cout << "Модель: " << model << std::endl;
    std::cout << "Тип: " << getTypeString() << std::endl;
    std::cout << "Стандарт: " << getStandardString() << std::endl;
    std::cout << "Макс. скорость: " << maxSpeed << " Мбит/с" << std::endl;
    std::cout << "Состояние питания: " << (isPoweredOn ? "Включен" : "Выключен") << std::endl;
    std::cout << "Состояние соединения: " << (isConnected ? "Установлено" : "Отсутствует") << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Modem& modem) {
    os << modem.manufacturer << " " << modem.model << " (" << modem.getTypeString() 
       << "), " << modem.getStandardString() << ", " << modem.maxSpeed << " Мбит/с";
    return os;
}