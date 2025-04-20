#ifndef MODEM_H
#define MODEM_H

#include <iostream>
#include <string>


enum class ModemType {
    DialUp,
    DSL,
    Cable,
    Fiber,
    Wireless
};

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
    std::string manufacturer;   
    std::string model;           
    ModemType type;              
    ConnectionStandard standard; 
    double maxSpeed;              
    bool isConnected;           
    bool isPoweredOn;          

public:

    Modem();
    Modem(const std::string& manuf, const std::string& mdl, ModemType tp, 
          ConnectionStandard std, double speed);
    Modem(const Modem& other); 
    ~Modem(); 


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


    void powerOn();
    void powerOff();
    void connect();
    void disconnect();
    

    Modem& operator=(const Modem& other);
    

    void displayInfo() const;
    

    friend std::ostream& operator<<(std::ostream& os, const Modem& modem);
};

#endif 