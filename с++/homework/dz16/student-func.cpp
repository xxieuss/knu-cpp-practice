#include <iostream>
#include <string>
#include <format>
#include "student.h"

Student::Student(){
    this -> age = 18;
    this -> energy = 0;
    this -> studyLVL = 0;
    this -> name = "";
    this -> group = "";
}

Student::Student(int age, int energy, int studyLVL){
    this -> age = age;
    this -> energy = energy;
    this -> studyLVL = studyLVL;
}
Student::Student(int age, int energy, int studyLVL, std::string name, std::string group){
    this -> age = age;
    this -> energy = energy;
    this -> studyLVL = studyLVL;
    this -> name = name;
    this -> group = group;
}

void Student::get_student(){
    std::cout << "Enter student's name: ";
    std::cin >> name;

    std::cout << "Enter student's age: ";
    std::cin >> age;

    std::cout << "Enter student's group: ";
    std::cin >> group;

    std::cout << format("Your student is: {}, {} y.o., from {} group.\n", name, age, group);
}

void Student::status(){
    std::cout << format("{}'s energy: {}, study lvl: {}.\n", name, energy, studyLVL);
}

void Student::sleep(){
    energy += SLEEP_ENERGY;
}

void Student::eat(){
    energy += EAT_ENERGY;
}

void Student::study(){
    if (energy < STUDY_ENERGY){
        std::cout << "Student is too tired for studying." << std::endl;
    }
    else{
        energy -= STUDY_ENERGY;
        studyLVL++;
    }
}