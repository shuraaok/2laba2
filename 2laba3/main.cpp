#include <iostream>
#include "student.hpp"
#include "deanery.hpp"
#include "application.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "=== Начало :( ===" << std::endl;

  
    std::cout << "\n--- Создание студентов ---" << std::endl;

    std::vector<std::string> debts1 = { "Алгебра", "Геометрия" };
    Student* student1 = new Student("Джонни", "Кейдж", "Информатика", 2, "МО-1", 5, debts1);

    std::vector<std::string> debts2 = { "Алгебра", "Программирование" };
    Student* student2 = new Student("Кенши", "Такахаши", "Информатика", 2, "МО-2", 8, debts2);

    std::vector<std::string> debts3 = { "Мат. анализ", "Питон" };
    Student* student3 = new Student("Соня", "Кейдж", "Прикладная математика", 3, "ПМИ-1", 3, debts3);


    std::cout << "\n--- Создание деканата ---" << std::endl;
    Deanery deanery("ул. Невского, 14");

 
    std::cout << "\n--- Прикрепление студентов ---" << std::endl;
    deanery.attachStudent(student1);
    deanery.attachStudent(student2);
    deanery.attachStudent(student3);

 
    deanery.displayAllStudents();


    std::cout << "\n--- Операторыыыы ---" << std::endl;

    Student resultPlus = *student1 + *student2;
    std::cout << "Результат student1 + student2:" << std::endl;
    resultPlus.displayInfo();

    Student resultDivide = *student1 / *student2;
    std::cout << "Результат student1 / student2 (общие долги):" << std::endl;
    resultDivide.displayInfo();

    Student temp = *student1;
    temp -= *student2;
    std::cout << "Результат student1 -= student2 (удаление общих долгов):" << std::endl;
    temp.displayInfo();


    std::cout << "\n--- Создание заявлений ---" << std::endl;

    Application promotionApp = student1->createPromotionApplication();
    promotionApp.displayInfo();

    Application transferApp = student2->createGroupTransferApplication("МО-1");
    transferApp.displayInfo();


    std::cout << "\n--- Деканат думает ---" << std::endl;
    deanery.processApplication(promotionApp);
    deanery.processApplication(transferApp);


    std::cout << "\n--- Студенты после заявлений ---" << std::endl;
    deanery.displayAllStudents();


    std::cout << "\n--- Поиск студента ---" << std::endl;
    Student* found = deanery.findStudent("Соня", "Кейдж");
    if (found) {
        std::cout << "Найден студент:" << std::endl;
        found->displayInfo();
    }


    std::cout << "\n--- Удаление студента ---" << std::endl;
    deanery.detachStudentByName("Джонни", "Кейдж");
    deanery.displayAllStudents();

    std::cout << "\n=== КОНЕЦ :) ===" << std::endl;

    return 0;
}