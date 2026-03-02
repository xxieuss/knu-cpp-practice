#include <iostream>
#include <string>
#include "numberM.h"

NumberM::NumberM(int v){
    value = normalize_value(v);
}

int NumberM::normalize_value(int v) const {
    int res = v % M;
    if (res < 0) res += M;
    return res;
}

// algebraic operations between class objects
NumberM operator+(NumberM n, const NumberM& m){
    n += m;
    return n;
}
NumberM operator-(NumberM n, const NumberM& m){
    n -= m;
    return n;
}
NumberM operator*(NumberM n, const NumberM& m){
    n *= m;
    return n;
}

// comparison operations
bool NumberM::operator==(const NumberM& other) const {
    return value == other.value;
}
bool NumberM::operator<(const NumberM& other) const {
    return value < other.value;
}
bool NumberM::operator>(const NumberM& other) const {
    return value > other.value;
}
bool NumberM::operator<=(const NumberM& other) const {
    return value <= other.value;
}
bool NumberM::operator>=(const NumberM& other) const {
    return value >= other.value;
}
bool NumberM::operator!=(const NumberM& other) const {
    return value != other.value;
}

// conversion operations to int, bool, and string
NumberM::operator int() const {
    return value;
}
NumberM::operator bool() const {
    return value != 0;
}
NumberM::operator std::string() const {
    return std::to_string(value);
}

// reading from (>>) and output to a stream (<<) operations
std::ostream& operator<< (std::ostream& os, const NumberM& obj){
    os << obj.value;
    return os;
}
std::istream& operator>> (std::istream& is, NumberM& obj){
    int temp;
    is >> temp;
    obj.value = obj.normalize_value(temp);
    return is;
}

// assignment operations
NumberM& NumberM::operator+=(const NumberM& other){
    value = normalize_value(value + other.value);
    return *this;
}
NumberM& NumberM::operator-=(const NumberM& other){
    value = normalize_value(value - other.value);
    return *this;
}
NumberM& NumberM::operator*=(const NumberM& other){
    value = normalize_value(value * other.value);
    return *this;
}

// algebraic operations between a class object and an int
NumberM operator+(NumberM n, int m){
    n += NumberM(m);
    return n;
}
NumberM operator-(NumberM n, int m){
    n -= NumberM(m);
    return n;
}
NumberM operator*(NumberM n, int m){
    n *= NumberM(m);
    return n;
}