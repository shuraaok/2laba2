#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>
#include <string>
#include <sstream>

struct Application {
    std::string studentFirstName;
    std::string studentLastName;
    std::string applicationType;
    std::string comment;
    int targetCourse;
    std::string targetGroup;

    
    Application(const std::string& fName = "", const std::string& lName = "",
        const std::string& type = "", const std::string& cmt = "",
        int course = 0, const std::string& group = "")
        : studentFirstName(fName), studentLastName(lName),
        applicationType(type), comment(cmt),
        targetCourse(course), targetGroup(group) {
        std::cout << "Создано заявление для: " << studentFirstName << " " << studentLastName
            << ", тип: " << applicationType << std::endl;
    }

    
    void displayInfo() const {
        std::cout << "=== Заявление ===" << std::endl;
        std::cout << "Студент: " << studentFirstName << " " << studentLastName << std::endl;
        std::cout << "Тип: " << applicationType << std::endl;
        std::cout << "Комментарий: " << comment << std::endl;

        if (!targetGroup.empty()) {
            std::cout << "Группа мечты: " << targetGroup << std::endl;
        }
        if (targetCourse > 0) {
            std::cout << "Курс мечты: " << targetCourse << std::endl;
        }
        std::cout << "=================" << std::endl;
    }

    
    std::string getInfo() const {
        std::stringstream ss;
        ss << "Заявление: " << studentFirstName << " " << studentLastName
            << " [" << applicationType << "]";
        return ss.str();
    }
};

#endif // APPLICATION_HPP