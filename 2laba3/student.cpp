#include "student.hpp"
#include "application.hpp"
#include <iostream>
#include <sstream>


Student::Student() : firstName(""), lastName(""), specialization(""),
courseNumber(1), groupNumber(""), variantNumber(0) {
    std::cout << "Конструктор по умолчанию Student вызван" << std::endl;
}


Student::Student(const std::string& fName, const std::string& lName,
    const std::string& spec, int course, const std::string& group,
    int variant, const std::vector<std::string>& debtList)
    : firstName(fName), lastName(lName), specialization(spec),
    courseNumber(course), groupNumber(group), variantNumber(variant), debts(debtList) {


    if (courseNumber < 1) courseNumber = 1;
    if (courseNumber > 6) courseNumber = 6;
    if (variantNumber < 0) variantNumber = 0;

    std::cout << "Конструктор полного заполнения Student вызван" << std::endl;
}


Student::Student(const Student& other)
    : firstName(other.firstName), lastName(other.lastName),
    specialization(other.specialization), courseNumber(other.courseNumber),
    groupNumber(other.groupNumber), variantNumber(other.variantNumber),
    debts(other.debts) {
    std::cout << "Конструктор копирования Student вызван" << std::endl;
}


Student::~Student() {
    clearDebts();
    std::cout << "Деструктор Student вызван для: " << firstName << " " << lastName << std::endl;
}


Student& Student::operator=(const Student& other) {
    std::cout << "Оператор присваивания Student вызван" << std::endl;

    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        specialization = other.specialization;
        courseNumber = other.courseNumber;
        groupNumber = other.groupNumber;
        variantNumber = other.variantNumber;
        debts = other.debts;
    }

    return *this;
}


Student Student::operator+(const Student& other) const {
    std::cout << "Оператор + вызван" << std::endl;

    std::string newFirstName = firstName + " и " + other.firstName;
    std::string newLastName = lastName + "-" + other.lastName;
    std::string newSpecialization = specialization + "/" + other.specialization;

    std::vector<std::string> newDebts = debts;
    for (const auto& debt : other.debts) {
        if (std::find(newDebts.begin(), newDebts.end(), debt) == newDebts.end()) {
            newDebts.push_back(debt);
        }
    }

    int newCourse = std::max(courseNumber, other.courseNumber);
    std::string newGroup = groupNumber;
    int newVariant = std::max(variantNumber, other.variantNumber);

    return Student(newFirstName, newLastName, newSpecialization,
        newCourse, newGroup, newVariant, newDebts);
}


Student& Student::operator-=(const Student& other) {
    std::cout << "Оператор -= вызван" << std::endl;

    std::vector<std::string> newDebts;
    for (const auto& debt : debts) {
        if (std::find(other.debts.begin(), other.debts.end(), debt) == other.debts.end()) {
            newDebts.push_back(debt);
        }
    }
    debts = newDebts;

    return *this;
}


Student Student::operator/(const Student& other) const {
    std::cout << "Оператор / вызван" << std::endl;

    std::string newFirstName = firstName + " и " + other.firstName;
    std::string newLastName = lastName + "-" + other.lastName;
    std::string newSpecialization = specialization;

    std::vector<std::string> commonDebts;
    for (const auto& debt : debts) {
        if (std::find(other.debts.begin(), other.debts.end(), debt) != other.debts.end()) {
            commonDebts.push_back(debt);
        }
    }

    return Student(newFirstName, newLastName, newSpecialization,
        courseNumber, groupNumber, variantNumber, commonDebts);
}


std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getSpecialization() const { return specialization; }
int Student::getCourseNumber() const { return courseNumber; }
std::string Student::getGroupNumber() const { return groupNumber; }
int Student::getVariantNumber() const { return variantNumber; }
std::vector<std::string> Student::getDebts() const { return debts; }


void Student::setFirstName(const std::string& fName) { firstName = fName; }
void Student::setLastName(const std::string& lName) { lastName = lName; }
void Student::setSpecialization(const std::string& spec) { specialization = spec; }

void Student::setCourseNumber(int course) {
    if (course >= 1 && course <= 6) {
        courseNumber = course;
    }
}

void Student::setGroupNumber(const std::string& group) { groupNumber = group; }

void Student::setVariantNumber(int variant) {
    if (variant >= 0) {
        variantNumber = variant;
    }
}

void Student::setDebts(const std::vector<std::string>& debtList) { debts = debtList; }


void Student::addDebt(const std::string& debt) {
    debts.push_back(debt);
}

void Student::removeDebt(const std::string& debt) {
    auto it = std::find(debts.begin(), debts.end(), debt);
    if (it != debts.end()) {
        debts.erase(it);
    }
}

bool Student::hasDebt(const std::string& debt) const {
    return std::find(debts.begin(), debts.end(), debt) != debts.end();
}


void Student::displayInfo() const {
    std::cout << getInfo();
}

std::string Student::getInfo() const {
    std::stringstream ss;
    ss << "=== Информация о студенте ===" << std::endl;
    ss << "Имя: " << firstName << std::endl;
    ss << "Фамилия: " << lastName << std::endl;
    ss << "Направление: " << specialization << std::endl;
    ss << "Курс: " << courseNumber << std::endl;
    ss << "Группа: " << groupNumber << std::endl;
    ss << "Вариант: " << variantNumber << std::endl;
    ss << "Долги: ";

    if (debts.empty()) {
        ss << "нет долгов";
    }
    else {
        for (size_t i = 0; i < debts.size(); ++i) {
            ss << debts[i];
            if (i < debts.size() - 1) ss << ", ";
        }
    }
    ss << std::endl;
    ss << "=============================" << std::endl;

    return ss.str();
}


Application Student::createPromotionApplication() const {
    int nextCourse = courseNumber + 1;
    return Application(firstName, lastName, "перевод_на_следующий_курс",
        "Заявление на перевод на следующий курс", nextCourse, "");
}


Application Student::createGroupTransferApplication(const std::string& newGroup) const {
    return Application(firstName, lastName, "перевод_в_другую_группу",
        "Заявление на перевод в группу " + newGroup,
        courseNumber, newGroup);
}


void Student::clearDebts() {
    if (!debts.empty()) {
        //std::cout << "Очистка долгов студента " << firstName << " " << lastName << ": удалено " << debts.size() << " элементов" << std::endl;
        debts.clear();
    }
}