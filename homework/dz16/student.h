#pragma once
#include <string>

struct Student{
    int age;
    int energy;
    int studyLVL;
    std::string name;
    std::string group;

    static const int EAT_ENERGY = 3;
    static const int SLEEP_ENERGY = 10;
    static const int STUDY_ENERGY = 7;
    
    void get_student();
    void status();
    void sleep();
    void eat();
    void study();

    Student();
    Student(int age, int energy, int studyLVL);
    Student(int age, int energy, int studyLVL, std::string name, std::string group);
};