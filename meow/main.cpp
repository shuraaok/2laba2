#include <iostream>
#include <vector>
#include <string>
#include "student.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "=== Создание студентов ===" << std::endl;

    std::vector<std::string> debts1 = { "математика", "физика", "информатика" };
    mt::Student student1("Джонни", "Кейдж", debts1);
    student1.displayInfo();

    std::vector<std::string> debts2 = { "математика", "русский язык", "химия" };
    mt::Student student2("Кенши", "Такахаши", debts2);
    student2.displayInfo();

    std::cout << "\n=== Тест оператора + ===" << std::endl;
    mt::Student resultPlus = student1 + student2;
    resultPlus.displayInfo();

    std::cout << "\n=== Тест оператора -= ===" << std::endl;
    mt::Student resultMinus = student1 -= student2;
    resultMinus.displayInfo();

    std::cout << "\n=== Тест оператора / ===" << std::endl;
    mt::Student resultDivide = student1 / student2;
    resultDivide.displayInfo();

    std::cout << "\n=== Тест оператора присваивания ===" << std::endl;
    mt::Student student3;
    student3 = student1;
    std::cout << "После присваивания student3 = student1:" << std::endl;
    student3.displayInfo();

    std::cout << "\n=== Тест конструктора копирования ===" << std::endl;
    mt::Student student4 = student2;
    student4.displayInfo();

    std::cout << "\n=== Добавление и удаление долгов ===" << std::endl;
    student1.addDebt("английский язык");
    std::cout << "После добавления долга:" << std::endl;
    student1.displayInfo();

    student1.removeDebt("физика");
    std::cout << "После удаления долга 'физика':" << std::endl;
    student1.displayInfo();

    std::cout << "\nВсе удалено:(" << std::endl;

    return 0;
}