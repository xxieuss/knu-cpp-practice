#include <iostream>
#include <vector>
#include <string>

// БАЗОВИЙ КЛАС
class SmartDevice {
protected:
    std::string name;
    bool isOn;

public:
    SmartDevice(std::string n) : name(n), isOn(false) {}

    // Віртуальний деструктор
    virtual ~SmartDevice() {}

    // ЧИСТА ВІРТУАЛЬНА ФУНКЦІЯ
    virtual void status() const = 0;      // перевизначити в дочірніх класах    (якщо ввімкнено - [Назва пристрою] ввімкнено!! + (SmartLight) -> Яскравість лампочки = ... (brightness))
                                                                                                                            // + (SmartAC)    -> Температура кондиціонера = ... (temperature)
                                                        //     якщо вимкнено - [Назва пристрою] вимкнено!

    void toggle() { isOn = !isOn; }
};

// --- ВАШ КОД ТУТ ---
// 1. Створіть клас SmartLight (нащадок SmartDevice)     attributes: brightness  (int)
class SmartLight : public SmartDevice{
private:
    int brightness;
public:
    SmartLight(std::string n, int b) : SmartDevice(n), brightness(b){}
    void status() const override{
        if (isOn) std::cout << "[" << name << "]" << " ввімкнено!! Яскравість лампочки = " << brightness << std::endl;
        else std::cout << "[" << name << "]" << " вимкнено!" << std::endl;
    }
};
// 2. Створіть клас SmartAC : SmartDevice (нащадок SmartDevice)        attributes: temperature (int)
class SmartAC : public SmartDevice{
private:
    int temperature;
public:
    SmartAC(std::string n, int t) : SmartDevice(n), temperature(t){}
    void status() const override{
        if (isOn) std::cout << "[" << name << "]" << " ввімкнено!! Температура кондиціонера = " << temperature << std::endl;
        else std::cout << "[" << name << "]" << " вимкнено!" << std::endl;
    }
};
// ------------------

int main() {
    std::vector<SmartDevice*> home;

    // 3. Додайте у вектор одну лампу та один кондиціонер
    home.push_back(new SmartLight("light1", 80));
    home.push_back(new SmartAC("ac1", 18));
    // 4. Увімкніть їх та виведіть статус через цикл
    for (auto device : home){
        device->toggle();
        device->status();
    }

    for (auto device : home) {
        delete device;
    }
    return 0;
}




