#include "telephone.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

Battery* Telephone::add(Battery* new_module){
    Battery* old_module = battery;
    battery = new_module;
    return old_module;
}
Camera* Telephone::add(Camera* new_module){
    Camera* old_module = camera;
    camera = new_module;
    return old_module;
}
Antenna* Telephone::add(Antenna* new_module){
    Antenna* old_module = antenna;
    antenna = new_module;
    return old_module;
}

Battery* Telephone::removeBattery(){
    Battery* old_module = battery;
    battery = nullptr;
    return old_module;
}
Camera* Telephone::removeCamera(){
    Camera* old_module = camera;
    camera = nullptr;
    return old_module;
}
Antenna* Telephone::removeAntenna(){
    Antenna* old_module = antenna;
    antenna = nullptr;
    return old_module;
}

void Telephone::call(){
    if (battery == nullptr) throw logic_error("There's no battery in the phone.");
    if (antenna == nullptr) throw logic_error("There's no antenna in the phone.");
    cout << "*Beep-Beep*" << endl;
}
void Telephone::photo(){
    if (battery == nullptr) throw logic_error("There's no battery in the phone.");
    if (camera == nullptr) throw logic_error("There's no camera in the phone.");
    cout << "*Click*" << endl;
}

Telephone::operator string() const{
    int total_weight;
    string info = "Name: " + PHONE_NAME + "\nAdded modules:\n";
    if (battery != nullptr){
        total_weight += battery->b_weight;
        info += "battery " + to_string(battery->capacity) + "mAh\n";
    }
    if (camera != nullptr){
        total_weight += camera->c_weight;
        info += "camera " + to_string(camera->resolution) + "Mp\n";
    }
    if (antenna != nullptr){
        total_weight += antenna->a_weight;
        info += "antenna " + antenna->mc_tech + "\n";
    }
    if (battery == nullptr && camera == nullptr && antenna == nullptr){
        info += "none\n";
    }
    return info + "total weight: " + to_string(total_weight) + "g\n";
}
ostream& operator<<(ostream& os, const Telephone& obj){
    os << static_cast<string>(obj);
    return os;
}

Telephone::~Telephone(){
    delete battery;
    delete camera;
    delete antenna;
}

Telephone* Telephone::create_phone(string model_name){
    Telephone* device = new Telephone;
    if (model_name == "Pon M10"){
        device->add(new Battery(4000));
        device->add(new Camera(5));
        device->add(new Antenna("3G"));
    }
    else if (model_name == "Pon M10 Pro"){
        device->add(new Battery(3000));
        device->add(new Camera(25));
        device->add(new Antenna("4G"));
    }
    else if (model_name == "Pon M10 Pro Max"){
        device->add(new Battery(2800));
        device->add(new Camera(40));
        device->add(new Antenna("5G"));
    }
    else{
        delete device;
        throw invalid_argument("There's no such model names");
    }
    return device;
}