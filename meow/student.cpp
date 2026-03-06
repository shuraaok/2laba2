#include "student.hpp"
#include <iostream>
#include <vector>
#include <string>

namespace mt {
Student::Student() : firstName(""), lastName("") {
    std::cout << "Конструктор по умолчанию вызван" << std::endl;
}

// Конструктор полного заполнения
Student::Student(const std::string& fName, const std::string& lName,
    const std::vector<std::string>& debtList)
    : firstName(fName), lastName(lName), debts(debtList) {
    std::cout << "Конструктор полного заполнения вызван" << std::endl;
}

// Конструктор копирования
Student::Student(const Student& other)
    : firstName(other.firstName), lastName(other.lastName), debts(other.debts) {
    std::cout << "Конструктор копирования вызван" << std::endl;
}

// Деструктор
Student::~Student() {
    clearDebts();
}

// Оператор присваивания
Student& Student::operator=(const Student& other) {
    std::cout << "Оператор присваивания вызван" << std::endl;

    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        debts = other.debts;
    }

    return *this;
}

Student Student::operator+(const Student& other) const {
    std::cout << "Оператор + вызван" << std::endl;

    std::string newFirstName = firstName + " и " + other.firstName;

    std::string newLastName = lastName + " и " + other.lastName;

    std::vector<std::string> newDebts = debts;

    for (const auto& debt : other.debts) {
        if (std::find(newDebts.begin(), newDebts.end(), debt) == newDebts.end()) {
            newDebts.push_back(debt);
        }
    }

    return Student(newFirstName, newLastName, newDebts);
}

Student Student::operator-=(const Student& other) const {
    std::cout << "Оператор -= вызван" << std::endl;

    std::string newFirstName = firstName + " без " + other.firstName;

    std::string newLastName = lastName;

    std::vector<std::string> newDebts;

    for (const auto& debt : debts) {
        if (std::find(other.debts.begin(), other.debts.end(), debt) == other.debts.end()) {
            newDebts.push_back(debt);
        }
    }

    return Student(newFirstName, newLastName, newDebts);
}

Student Student::operator/(const Student& other) const {
    std::cout << "Оператор / вызван" << std::endl;

    std::string newFirstName = firstName + " и " + other.firstName;

    std::string newLastName = lastName + " и " + other.lastName;

    std::vector<std::string> newDebts;

    for (const auto& debt : debts) {
        if (std::find(other.debts.begin(), other.debts.end(), debt) != other.debts.end()) {
            newDebts.push_back(debt);
        }
    }

    return Student(newFirstName, newLastName, newDebts);
}

// Геттеры
std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

std::vector<std::string> Student::getDebts() const {
    return debts;
}

// Сеттеры
void Student::setFirstName(const std::string& fName) {
    firstName = fName;
}

void Student::setLastName(const std::string& lName) {
    lastName = lName;
}

void Student::setDebts(const std::vector<std::string>& debtList) {
    debts = debtList;
}

//добавление долга
void Student::addDebt(const std::string& debt) {
    debts.push_back(debt);
}

//удаление долга
void Student::removeDebt(const std::string& debt) {
    auto it = std::find(debts.begin(), debts.end(), debt);
    if (it != debts.end()) {
        debts.erase(it);
    }
}

//вывод информации о студенте
void Student::displayInfo() const {
    std::cout << "=== Информация о студенте ===" << std::endl;
    std::cout << "Имя: " << firstName << std::endl;
    std::cout << "Фамилия: " << lastName << std::endl;
    std::cout << "Долги: ";

    if (debts.empty()) {
        std::cout << "нет долгов";
    }
    else {
        for (size_t i = 0; i < debts.size(); ++i) {
            std::cout << debts[i];
            if (i < debts.size() - 1) {
                std::cout << ", ";
            }
        }
    }
    std::cout << std::endl;
    std::cout << "=============================" << std::endl;
}

void Student::clearDebts() {
    if (!debts.empty()) {
        debts.clear();
    }
}
}