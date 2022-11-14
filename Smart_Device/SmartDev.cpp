// Developed by Albert(Neo802)
#include "Header.h"

template <typename T> T OneZero(T a) {
    if (a != 0 && a != 1) {
        throw "Number not 0 and 1";
    }
}

template <typename T> T DevTypes(T a) {
    if (a != 0 && a != 1 && a != 2) {
        throw "Invalid device type";
    }
}

template <typename T> T ModelNr(T a) {
    if (a < 0) { // 0 means nothingPhone
        throw "Invalid device model";
    }
}

template <typename T> T CheckString(T a) {
    if (strlen(a) < 3) { // 0 means error
        throw "String must have at least 3 characters";
    }
}

class SmartDevice {
private:
    struct SmartDev {
        char SmartDevName[100];
        int Smartphone = 0; // 0 or 1
        int Smartwatch = 0; // 0 or 1
        int SmartTV = 0; // 0 or 1

        int ModelNumber = 1;

        char OS[16];
    } SDT;
public:
    SmartDevice() {
        cout << "Constructor initialized" << endl;
        //this->SDT = SDT;
    }
    ~SmartDevice() {
        cout << "Destructor initialized" << endl;
    }

    void Read(int& x) {
        try {
            cin.get();
            cin >> x;
            OneZero(x);
        }

        catch (const char* x) {
            cout << "Exception: Item is different than 0 or 1." << endl;
        }
    }

    void GetDeviceSpecs() {
        cout << endl << "Here are the device specifications!"<< endl;

        cout << "Device name: " << SDT.SmartDevName << endl;
        cout << "Device type: ";
        if (SDT.Smartphone) {
            cout << "Smartphone" << endl;
        }
        if (SDT.Smartwatch) {
            cout << "Smartwatch" << endl;
        }
        if (SDT.SmartTV) {
            cout << "SmartTV" << endl;
        }
        
        cout << "Model: " << SDT.ModelNumber << endl;
        cout << "OS: " << SDT.OS << endl;

        cout << endl;
    }

    void ChangeModel(int model) { // either upgrade or downgrade, no less than zero though
        try {
            ModelNr(model);

            if (model > 0)
                SDT.ModelNumber = model;

            if (model == 0) { // easter egg
                char egg[] = "Nothing";
                strcpy(SDT.SmartDevName, egg);
                SDT.ModelNumber = 1337;
            }

        }

        catch (const char* x) {
            cout << "Exception: Invalid model number, the model stays the same." << endl;
        }
    }

    void ChangeOS() {
        try {
            cout << "Operating system: ";
            cin.get();
            cin.get(SDT.OS, 16);
            CheckString(SDT.OS);
        }

        catch (const char* x) {
            cout << "Exception: The device OS name must be of at least three characters." << endl;
        }
        return;
    }

    void ChangeDevName() {
        try {
            cout << "Device name: ";
            cin.get();
            cin.get(SDT.SmartDevName, 100);
            CheckString(SDT.SmartDevName);
        }

        catch (const char* x) {
            cout << "Exception: The device name must be of at least three characters." << endl;
        }
        return;
    }

    void Transform(int kind) { // change the device type, between 0 and 2
        try {
            DevTypes(kind);
            if (kind == 0) {
                SDT.Smartphone = 1;
                SDT.Smartwatch = 0;
                SDT.SmartTV = 0;
            }
            else if (kind == 1) {
                SDT.Smartphone = 0;
                SDT.Smartwatch = 1;
                SDT.SmartTV = 0;
            }
            else if (kind == 2) {
                SDT.Smartphone = 0;
                SDT.Smartwatch = 0;
                SDT.SmartTV = 1;
            }
        }

        catch (const char* x) {
            cout << "Exception: Invalid device type, the device type stays the same." << endl;
        }
    }

    int CheckDeviceType() {
        return SDT.Smartphone || SDT.Smartwatch || SDT.SmartTV;
    }

    string GetOS() {
        return SDT.OS;
    }

    int GetDevModel() {
        return SDT.ModelNumber;
    }

    void AssignDevice() {

        /*cout << "Device name: ";
        cin.get();
        cin.get(SDT.SmartDevName, 100);*/

        ChangeDevName();
        if (CheckDeviceType() != 1) {
            cout << "Smartphone: ";
            Read(SDT.Smartphone);
        }
        if (CheckDeviceType() != 1) {
            cout << "Smartwatch: ";
            Read(SDT.Smartwatch);
        }
        if (CheckDeviceType() != 1) {
            cout << "SmartTV: ";
            Read(SDT.SmartTV);
        }
        int newmodel;
        cout << "Model number: ";
        cin >> newmodel;
        ChangeModel(newmodel);

        ChangeOS();
        /*cout << "Operating system: ";
        cin.get();
        cin.get(SDT.OS, 16);*/
    }


};

int init() {
    int i;
    int n;
    SmartDevice* sd = new SmartDevice;

    do {
        /*printf("\n1.Read");
        printf("\n2.Get device specifications");
        printf("\n7.Exit");
        printf("\n\nYour option: ");*/

        cout << "1.Read" << endl;
        cout << "2.Get device specifications" << endl;
        cout << "3.Buy a new device model" << endl;
        cout << "4.Change device type" << endl;
        cout << "5.Change device OS" << endl;
        cout << "6.Change device name" << endl;
        cout << "7.Upgrade model" << endl;
        cout << "8.Downgrade model" << endl;
        cout << "9.Exit" << endl;
        cout << "Your option: ";

        //scanf_s("%d", &i);

        cin >> i;
        switch (i)
        {
            case 1:
            {
                sd->AssignDevice();
                break;
            }
            case 2:
            {
                sd->GetDeviceSpecs();
                break;
            }
            case 3: {
                int newmodel;
                cout << "Please introduce the new model number: ";
                cin >> newmodel;
                sd->ChangeModel(newmodel);
                break;
            }
            case 4: {
                int kind;
                cout << "Please introduce the new device type: ";
                cin >> kind;
                sd->Transform(kind);
                break;
            }
            case 5: {
                sd->ChangeOS();
                break;
            }
            case 6: {
                sd->ChangeDevName();
                break;
            }
            case 7: {
                int newModel = sd->GetDevModel();
                newModel++;
                sd->ChangeModel(newModel);
                break;
            }
            case 8: {
                int newModel = sd->GetDevModel();
                newModel--;
                sd->ChangeModel(newModel);
                break;
            }
            case 9:
                delete sd;
                return 0;
            default: {
                cout << "Invalid input" << endl;
                break;
            }
        }
    } while (i);
    return 0;
}