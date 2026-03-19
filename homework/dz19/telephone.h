#pragma once
#include <string>

struct Battery{
    int capacity;
    int b_weight = 10;
    Battery(int cap){capacity = cap;};
};
struct Camera{
    int resolution;
    int c_weight = 5;
    Camera(int res){resolution = res;};
};
struct Antenna{
    std::string mc_tech;
    int a_weight = 15;
    Antenna(std::string type){mc_tech = type;};
};

class Telephone{
private:
    const std::string PHONE_NAME = "PocoPhone";
    const int PHONE_WEIGHT = 150;

    Battery* battery = nullptr;
    Camera* camera = nullptr;
    Antenna* antenna = nullptr;

public:
    Telephone() = default;
    ~Telephone();

    Telephone(const Telephone& other) = delete;
    Telephone& operator=(const Telephone& other) = delete;

    Battery* add(Battery* new_module);
    Camera* add(Camera* new_module);
    Antenna* add(Antenna* new_module);

    Battery* removeBattery();
    Camera* removeCamera();
    Antenna* removeAntenna();

    void call();
    void photo();

    friend std::ostream& operator<<(std::ostream& os, const Telephone& obj);
    explicit operator std::string() const;

    static Telephone* create_phone(std::string model_name);
};