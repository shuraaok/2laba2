#pragma once
#include<iostream>
#include<vector>

namespace mt {
class Student {
private:
    std::string firstName;
    std::string lastName;
    std::vector<std::string> debts;

public:

    Student();

    Student(const std::string& fName, const std::string& lName,
        const std::vector<std::string>& debtList);

    Student(const Student& other);

    ~Student();

    Student& operator=(const Student& other);

    Student operator+(const Student& other) const;

    Student operator-=(const Student& other) const;

    Student operator/(const Student& other) const;

    std::string getFirstName() const;
    std::string getLastName() const;
    std::vector<std::string> getDebts() const;

    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setDebts(const std::vector<std::string>& debtList);

    void addDebt(const std::string& debt);

    void removeDebt(const std::string& debt);

    void displayInfo() const;

    void clearDebts();

	};
}