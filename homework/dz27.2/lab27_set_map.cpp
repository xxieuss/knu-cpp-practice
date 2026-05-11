#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>

// 1. Абстрактний клас
class OfficeDevice {
protected:
    std::string model;
public:
    OfficeDevice(std::string m) : model(m) {}
    virtual ~OfficeDevice() {}
    virtual void work() = 0;
};

// 2. Нащадок: Принтер
class Printer : public OfficeDevice {
public:
    Printer(std::string m) : OfficeDevice(m) {}
    void work() override { std::cout << "Принтер " << model << " друкує документи...\n"; }
};

// 3. Нащадок: Сканер
class Scanner : public OfficeDevice {
public:
    Scanner(std::string m) : OfficeDevice(m) {}
    void work() override { std::cout << "Сканер " << model << " сканує папери...\n"; }
};

int main() {
    // ТУТ ВИ МАЄТЕ:

    // А) Реалізувати лог відвідувачів через std::set
    std::set<std::string> badge_logs;
    badge_logs.insert("Ivan");
    badge_logs.insert("Alex");
    badge_logs.insert("Bob");
    badge_logs.insert("Alex");
    badge_logs.insert("Caine");
    std::cout << "Today there were:\n";
    for (const auto& name : badge_logs){
        std::cout << name << std::endl;
    }
    // Б) Реалізувати мережу офісу через std::map<int, std::unique_ptr<OfficeDevice>>
    std::map<int, std::unique_ptr<OfficeDevice>> office_network;
    office_network[1] = std::make_unique<Printer>("GoodPrinter");
    office_network[2] = std::make_unique<Printer>("CoolPrinter");
    office_network[3] = std::make_unique<Scanner>("AwesomeScanner");
    // В) Написати функцію пошуку пристрою за номером: 
    //    користувач вводить ID -> якщо пристрій є, він викликає work(), якщо немає — пише "Error".
    int search_id;
    std::cout << "Enter device id: ";
    std::cin >> search_id;
    auto it = office_network.find(search_id);
    if (it != office_network.end()) it->second->work();
    else std::cout << "Error" << std::endl;

    return 0;
}