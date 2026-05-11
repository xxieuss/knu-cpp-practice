#include <iostream>
#include <string>
#include <vector>

// --- БАЗОВИЙ КЛАС 1 (Реалізовано за вас) ---
class Vehicle {
protected:
    std::string brand;
    float fuelLevel;

public:
    Vehicle(std::string b, float f) : brand(b), fuelLevel(f) {}

    // Віртуальний деструктор - ПАМ'ЯТАЄТЕ НАВІЩО?
    virtual ~Vehicle() {}

    // Чиста віртуальна функція (Абстрактний метод)
    virtual void move() = 0;

    // Звичайний метод (Інкапсуляція в дії)
    void showFuel() const {
        std::cout << "Транспорт [" << brand << "], паливо: " << fuelLevel << " л.\n";
    }
};

// --- БАЗОВИЙ КЛАС 2 (ЗАВДАННЯ: Реалізуйте самі) ---
// Створіть абстрактний клас "Engine", який має:
// 1. Приватне поле power (потужність).
// 2. Конструктор.
// 3. Віртуальну функцію startEngine() = 0.
class Engine{
private:
    int power;
public:
    Engine(int p) : power(p){}
    virtual ~Engine() = default;
    virtual void startEngine() = 0;
};
// ------------------------------------------------

// --- НАСЛІДУВАННЯ (ЗАВДАННЯ: Створіть клас Car) ---
// 1. Успадкуйте Car від Vehicle.
// 2. Додайте приватне поле maxSpeed.
// 3. Перевизначте (override) метод move().
class Car : public Vehicle{
private:
    int maxSpeed;
public:
    Car(std::string b, float f, int m_speed) : Vehicle(b, f), maxSpeed(m_speed){}
    void move() override{
        std::cout << "The car " << brand << " drives at a speed of " << maxSpeed << "km/h." << std::endl;
    }
};
// ------------------------------------------------

// --- ПОЛІМОРФІЗМ (ЗАВДАННЯ: Створіть клас Truck) ---
// 1. Успадкуйте Truck від Vehicle.
// 2. Додайте поле loadCapacity (вантажопідйомність).
// 3. Реалізуйте move() так, щоб він виводив вагу вантажу.
class Truck : public Vehicle{
    private:
    int loadCapacity;
    public:
    Truck(std::string b, float f, int lc) : Vehicle(b, f), loadCapacity(lc){}
    void move() override{
        std::cout << "The truck carries " << loadCapacity << " tons of cargo." << std::endl;
    }
};
// ------------------------------------------------

int main() {
    // ТУТ СТУДЕНТИ МАЮТЬ:
    // 1. Створити вектор вказівників на Vehicle.
    std::vector<Vehicle*> vehicles;
    // 2. Додати в нього один Car та один Truck (використовуйте new).
    vehicles.push_back(new Car("Tesla", 50, 200));
    vehicles.push_back(new Truck("Volvo", 300, 20));
    // 3. У циклі викликати move() та showFuel() для кожного.
    for (Vehicle* v : vehicles){
        v->move();
        v->showFuel();
        std::cout << std::endl;
    }
    // 4. Очистити пам'ять (delete).
    for (Vehicle* v : vehicles){
        delete v;
    }
    vehicles.clear();

    return 0;
}