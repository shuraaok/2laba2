#ifndef DEANERY_HPP
#define DEANERY_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "student.hpp"
#include "application.hpp"

class Deanery {
private:
    std::string address;
    std::vector<Student*> students;

public:
    
    Deanery(const std::string& addr = "");

    
    ~Deanery();

    
    Deanery(const Deanery& other) = delete;
    Deanery& operator=(const Deanery& other) = delete;

    
    void attachStudent(Student* student);

    
    void detachStudent(Student* student);
    void detachStudentByIndex(size_t index);
    void detachStudentByName(const std::string& firstName, const std::string& lastName);

    
    void processApplication(const Application& app);

    
    void displayAllStudents() const;

    
    size_t getStudentCount() const;

    
    Student* findStudent(const std::string& firstName, const std::string& lastName) const;

    
    std::string getAddress() const;

    
    void setAddress(const std::string& addr);
};

#endif // DEANERY_HPP