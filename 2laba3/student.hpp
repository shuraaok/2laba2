#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>


struct Application;

class Student {
private:
    std::string firstName;
    std::string lastName;
    std::string specialization;
    int courseNumber;
    std::string groupNumber;
    int variantNumber;
    std::vector<std::string> debts;

public:
    
    Student();
    Student(const std::string& fName, const std::string& lName,
        const std::string& spec, int course, const std::string& group,
        int variant, const std::vector<std::string>& debtList = {});
    Student(const Student& other);

    
    ~Student();

    
    Student& operator=(const Student& other);

    
    Student operator+(const Student& other) const;
    Student& operator-=(const Student& other);
    Student operator/(const Student& other) const;

    
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getSpecialization() const;
    int getCourseNumber() const;
    std::string getGroupNumber() const;
    int getVariantNumber() const;
    std::vector<std::string> getDebts() const;

    
    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setSpecialization(const std::string& spec);
    void setCourseNumber(int course);
    void setGroupNumber(const std::string& group);
    void setVariantNumber(int variant);
    void setDebts(const std::vector<std::string>& debtList);

    
    void addDebt(const std::string& debt);
    void removeDebt(const std::string& debt);
    bool hasDebt(const std::string& debt) const;


    void displayInfo() const;
    std::string getInfo() const;


    Application createPromotionApplication() const;


    Application createGroupTransferApplication(const std::string& newGroup) const;


    void clearDebts();
};

#endif // STUDENT_HPP