#pragma once
#include <iostream>
#include <string>

class NumberM{
    int value;
    static const int M = 512;
    int normalize_value(int v) const;

    public:
    NumberM(int value = 0);

    // algebraic operations between class objects
    friend NumberM operator+(NumberM n, const NumberM& m);
    friend NumberM operator-(NumberM n, const NumberM& m);
    friend NumberM operator*(NumberM n, const NumberM& m);

    // comparison operations
    bool operator==(const NumberM& other) const;
    bool operator<(const NumberM& other) const;
    bool operator>(const NumberM& other) const;
    bool operator<=(const NumberM& other) const;
    bool operator>=(const NumberM& other) const;
    bool operator!=(const NumberM& other) const;

    // conversion operations to int, bool, and string
    explicit operator int() const;
    explicit operator bool() const;
    explicit operator std::string() const;

    // reading from (>>) and output to a stream (<<) operations
    friend std::ostream& operator<< (std::ostream& os, const NumberM& obj);
    friend std::istream& operator>> (std::istream& is, NumberM& obj);

    // assignment operations
    NumberM& operator+=(const NumberM& other);
    NumberM& operator-=(const NumberM& other);
    NumberM& operator*=(const NumberM& other);

    // algebraic operations between a class object and an int
    friend NumberM operator+(NumberM n, int m);
    friend NumberM operator-(NumberM n, int m);
    friend NumberM operator*(NumberM n, int m);
};