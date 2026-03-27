#include "deanery.hpp"
#include <iostream>


Deanery::Deanery(const std::string& addr) : address(addr) {
    std::cout << "Конструктор деканата вызван. Адрес: " << address << std::endl;
}

// Деструктор
Deanery::~Deanery() {
    //std::cout << "Деструктор деканата вызван. Удаление всех студентов..." << std::endl;

    for (Student* student : students) {
        delete student;
    }
    students.clear();

    std::cout << "Деканат уничтожен, бдыщщ" << std::endl;
}


void Deanery::attachStudent(Student* student) {
    if (student != nullptr) {
        students.push_back(student);
        std::cout << "Студент " << student->getFirstName() << " " << student->getLastName()
            << " прикреплен к деканату" << std::endl;
    }
    else {
        std::cout << "Ошибка: попытка прикрепить пустой указатель" << std::endl;
    }
}


void Deanery::detachStudent(Student* student) {
    auto it = std::find(students.begin(), students.end(), student);
    if (it != students.end()) {
        std::cout << "Студент " << (*it)->getFirstName() << " " << (*it)->getLastName()
            << " отчислен из деканата" << std::endl;
        delete* it;
        students.erase(it);
    }
    else {
        std::cout << "Студент не найден в деканате" << std::endl;
    }
}


void Deanery::detachStudentByIndex(size_t index) {
    if (index < students.size()) {
        std::cout << "Студент " << students[index]->getFirstName() << " " << students[index]->getLastName()
            << " отчислен из деканата" << std::endl;
        delete students[index];
        students.erase(students.begin() + index);
    }
    else {
        std::cout << "Неверный индекс студента" << std::endl;
    }
}


void Deanery::detachStudentByName(const std::string& firstName, const std::string& lastName) {
    auto it = std::find_if(students.begin(), students.end(),
        [&firstName, &lastName](Student* s) {
            return s->getFirstName() == firstName && s->getLastName() == lastName;
        });

    if (it != students.end()) {
        std::cout << "Студент " << (*it)->getFirstName() << " " << (*it)->getLastName()
            << " отчислен из деканата" << std::endl;
        delete* it;
        students.erase(it);
    }
    else {
        std::cout << "Студент " << firstName << " " << lastName << " не найден" << std::endl;
    }
}


void Deanery::processApplication(const Application& app) {
    std::cout << "\n=== Обработка заявления ===" << std::endl;
    app.displayInfo();

    Student* student = findStudent(app.studentFirstName, app.studentLastName);

    if (student == nullptr) {
        std::cout << "Ошибка: студент не найден в деканате" << std::endl;
        return;
    }

    if (app.applicationType == "перевод_на_следующий_курс") {
        if (app.targetCourse <= 6 && app.targetCourse > 0) {
            student->setCourseNumber(app.targetCourse);
            std::cout << "Студент " << app.studentFirstName << " " << app.studentLastName
                << " переведен на " << app.targetCourse << " курс" << std::endl;
        }
        else {
            std::cout << "Ошибка: некорректный номер курса" << std::endl;
        }
    }
    else if (app.applicationType == "перевод_в_другую_группу") {
        if (!app.targetGroup.empty()) {
            student->setGroupNumber(app.targetGroup);
            std::cout << "Студент " << app.studentFirstName << " " << app.studentLastName
                << " переведен в группу " << app.targetGroup << std::endl;
        }
        else {
            std::cout << "Ошибка: некорректное название группы" << std::endl;
        }
    }
    else {
        std::cout << "Неизвестный тип заявления: " << app.applicationType << std::endl;
    }

    std::cout << "Обработка заявления завершена" << std::endl;
}


void Deanery::displayAllStudents() const {
    std::cout << "\n=== Список студентов деканата (адрес: " << address << ") ===" << std::endl;
    std::cout << "Всего студентов: " << students.size() << std::endl;

    if (students.empty()) {
        std::cout << "Нет студентов в деканате" << std::endl;
    }
    else {
        for (size_t i = 0; i < students.size(); ++i) {
            std::cout << "\n[" << i + 1 << "] ";
            students[i]->displayInfo();
        }
    }
    std::cout << "===================================" << std::endl;
}


size_t Deanery::getStudentCount() const {
    return students.size();
}


Student* Deanery::findStudent(const std::string& firstName, const std::string& lastName) const {
    auto it = std::find_if(students.begin(), students.end(),
        [&firstName, &lastName](Student* s) {
            return s->getFirstName() == firstName && s->getLastName() == lastName;
        });

    if (it != students.end()) {
        return *it;
    }
    return nullptr;
}


std::string Deanery::getAddress() const {
    return address;
}


void Deanery::setAddress(const std::string& addr) {
    address = addr;
}
