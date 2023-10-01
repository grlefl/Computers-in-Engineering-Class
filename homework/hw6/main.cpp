/* Name: Grace Flores
 * Date: November 5th, 2022
 * Program Description: Using two classes to experiment with class inheritance.
*/

//
// Note: Code was modified from Challenge Activity 11.3.1: Overriding member function.
// in the CIE ZyBook class textbook.

#include <iostream>
using namespace std;

class Computer {
public:
    ////////////////////////////////////////////////////////////////////////
    // description: Computer object constructor; takes 3 inputs, all with
    //              predetermined default values
    // inputs:
    //          string "default" for private member cpuUsage
    //          string "default" for private member internetStatus
    //          float 0 as a default for private member *memorySize
    // outputs: none
    ///////////////////////////////////////////////////////////////////////
    explicit Computer(string x = "default", string y = "default", float z = 0) {
        // using copy assignment operator
        setCpuUsage(x);
        setInternetStatus(y);
        setMemorySize(z);
    }


    ////////////////////////////////////////////////////////////////////////
    // getters
    string getCpuUsage() const { return cpuUsage; }
    string getInternetStatus() const { return internetStatus; }

    // setters
    void setCpuUsage(const string x) { cpuUsage = x; }
    void setInternetStatus(const string x) { internetStatus = x; }

    // memorySize getter and setter
    float getMemorySize() const {
        if (memorySize != nullptr or memorySize != 0) {
            return *memorySize;
        }
    }
    void setMemorySize(const float i) {
        if (memorySize == nullptr) {
            memorySize = new float;
            if (memorySize == nullptr) {
                return;
            }
        }
        *memorySize = i;
    }
    ////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////
    // description: setComputerStatus() method; updates member variables
    //              of Computer object
    // inputs:
    //          string for private member cpuUsage
    //          string for private member internetStatus
    // outputs: none
    ///////////////////////////////////////////////////////////////////////
    void setComputerStatus(const string &usage, const string &status) {
        setCpuUsage(usage);
        setInternetStatus(status);
    };


    ////////////////////////////////////////////////////////////////////////
    // description: print() method; prints values of all member variables
    // inputs: none
    // outputs: none
    ///////////////////////////////////////////////////////////////////////
    void print() {
        cout << "CPU usage: " << getCpuUsage() << endl;
        cout << "Internet status: " << getInternetStatus() << endl;
        cout << "Memory size: " << getMemorySize() << endl;
    };


    // copy constructor
    Computer(const Computer &objToCopyFrom) {
        setCpuUsage(objToCopyFrom.getCpuUsage());
        setInternetStatus(objToCopyFrom.getInternetStatus());
        setMemorySize(objToCopyFrom.getMemorySize());
    }

    // copy assignment operator
    Computer& operator=(const Computer& objToCopy){
        if (this != &objToCopy) { // to avoid self-assignment
            setCpuUsage(objToCopy.getCpuUsage());
            setInternetStatus(objToCopy.getInternetStatus());
            delete memorySize;
            memorySize = new float;
            setMemorySize(objToCopy.getMemorySize());
        }
        return *this;
    }

    // destructor
    ~Computer() {
        cout << "\nYou are in the computer destructor. The object with the following"
                " information will be destroyed:" << endl;
        print();
        delete memorySize;
    }

private:
    string cpuUsage; // percentage out of 100
    string internetStatus; // "connected" or "disconnected"
    float *memorySize = nullptr; // in Gbytes
};

class Laptop : public Computer {
public:
    ////////////////////////////////////////////////////////////////////////
    // description: Laptop object constructor; takes 3 inputs, all with
    //              predetermined default values; uses Computer constructor
    //              to construct object; sets private member
    //              wifiQuality to "default" string
    // inputs:
    //          string "default" for private member cpuUsage
    //          string "default" for private member internetStatus
    //          float 0 as a default for private member *memorySize
    // outputs: none
    ///////////////////////////////////////////////////////////////////////
    explicit Laptop(string x = "default", string y = "default", float z = 0) : Computer(x,y,z) {
        setWifiQuality("default");
    }

    // wifiQuality getter and setter
    string getWifiQuality() const { return wifiQuality; }
    void setWifiQuality(const string x) { wifiQuality = x; }

    ////////////////////////////////////////////////////////////////////////
    // description: setComputerStatus() method; updates member variables
    //              of Laptop object using overloading
    // inputs:
    //          string for private member cpuUsage
    //          string for private member internetStatus
    //          string for private member wifiQuality
    // outputs: none
    ///////////////////////////////////////////////////////////////////////
    void setComputerStatus(const string &usage, const string &status, const string &quality) {
        Computer::setComputerStatus(usage, status);
        wifiQuality = quality;
    };


    ////////////////////////////////////////////////////////////////////////
    // description: print() method; prints values of all member variables
    // inputs: none
    // outputs: none
    ///////////////////////////////////////////////////////////////////////
    void print() {
        Computer::print();
        cout << "WiFi quality: " << getWifiQuality() << endl;
    };

    // destructor
    ~Laptop() {
        cout << "\nYou are in the laptop destructor. The object with the following"
                " information will be destroyed:" << endl;
        print();
    }

private:
    string wifiQuality; // "good" or "bad"
};

int main() {

    cout << "\nCOMPUTER CLASS TESTS" << endl;

    cout << "\nCONSTRUCTOR TEST\n" << endl;
    Computer computerOriginal;
    cout << "EXPECTED OUTPUT:\n"
            "CPU usage: default\n"
            "Internet status: default\n"
            "Memory size: 0\n" << endl;
    cout << "ACTUAL OUTPUT:" << endl;
    computerOriginal.print();


    cout << "\nSETTER TEST\n" << endl;
    computerOriginal.setCpuUsage("45%");
    computerOriginal.setInternetStatus("disconnected");
    computerOriginal.setMemorySize(8);
    cout << "EXPECTED OUTPUT:\n"
            "CPU usage: 45%\n"
            "Internet status: disconnected\n"
            "Memory size: 8\n" << endl;
    cout << "ACTUAL OUTPUT:" << endl;
    computerOriginal.print();


    cout << "\nGETTER TEST\n" << endl;
    cout << "EXPECTED OUTPUT:\n"
            "45%\n"
            "disconnected\n"
            "8\n" << endl;
    cout << "ACTUAL OUTPUT:" << endl;
    cout << computerOriginal.getCpuUsage() << endl;
    cout << computerOriginal.getInternetStatus() << endl;
    cout << computerOriginal.getMemorySize() << endl;


    cout << "\nsetComputerStatus() TEST\n" << endl;
    computerOriginal.setComputerStatus("23%","connected");
    cout << "EXPECTED OUTPUT:\n"
            "CPU usage: 23%\n"
            "Internet status: connected\n"
            "Memory size: 8\n" << endl;
    cout << "ACTUAL OUTPUT:" << endl;
    computerOriginal.print();


    cout << "\nprint() has been tested throughout other tests" << endl;


    cout << "\nCOPY CONSTRUCTOR TEST\n" << endl;
    Computer copyConstructor(computerOriginal);
    cout << "EXPECTED OUTPUT:\n"
            "CPU usage: 23%\n"
            "Internet status: connected\n"
            "Memory size: 8\n" << endl;
    cout << "ACTUAL OUTPUT:" << endl;
    copyConstructor.print();


    cout << "\nCOPY ASSIGNMENT OPERATOR TEST\n" << endl;
    Computer copyAssignmentOperator = computerOriginal;
    cout << "EXPECTED OUTPUT:\n"
            "CPU usage: 23%\n"
            "Internet status: connected\n"
            "Memory size: 8\n" << endl;
    cout << "ACTUAL OUTPUT:" << endl;
    copyAssignmentOperator.print();


    cout << "\nLAPTOP TESTS" << endl;


    cout << "\nCONSTRUCTOR TEST\n" << endl;
    Laptop laptopOriginal;
    cout << "EXPECTED OUTPUT:\n"
            "CPU usage: default\n"
            "Internet status: default\n"
            "Memory size: 0\n"
            "Wifi quality: default\n" << endl;
    cout << "ACTUAL OUTPUT:" << endl;
    laptopOriginal.print();


    cout << "\nsetComputerStatus() TEST\n" << endl;
    laptopOriginal.setComputerStatus("78%","disconnected","good");
    cout << "EXPECTED OUTPUT:\n"
            "CPU usage: 78%\n"
            "Internet status: disconnected\n"
            "Memory size: 0\n"
            "Wifi quality: good\n" << endl;
    cout << "ACTUAL OUTPUT:" << endl;
    laptopOriginal.print();


    cout << "\nprint() has been tested throughout other tests" << endl;


    cout << "\nCOMBINED COMPUTER AND LAPTOP DESTRUCTOR TEST\n" << endl;
    cout << "EXPECTED OUTPUT:\n\n"
            "You are in the laptop destructor. The object with the following information will be destroyed:\n"
            "CPU usage: 78%\n"
            "Internet status: disconnected\n"
            "Memory size: 0\n"
            "WiFi quality: good\n"
            "\n"
            "You are in the computer destructor. The object with the following information will be destroyed:\n"
            "CPU usage: 23%\n"
            "Internet status: connected\n"
            "Memory size: 8\n"
            "\n"
            "You are in the computer destructor. The object with the following information will be destroyed:\n"
            "CPU usage: 23%\n"
            "Internet status: connected\n"
            "Memory size: 8\n"
            "\n"
            "You are in the computer destructor. The object with the following information will be destroyed:\n"
            "CPU usage: 23%\n"
            "Internet status: connected\n"
            "Memory size: 8\n" << endl;
    cout << "ACTUAL OUTPUT:" << endl;

    return 0;
}