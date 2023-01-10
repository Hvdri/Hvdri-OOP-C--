#include <iostream>
#include <vector>
#include <string>
//#include <memory>

template <typename T>
class Employee {
private:
    int id;
    std::string name;
    T salary;

public:
    Employee(int id, std::string name, T salary) : id(id), name(name), salary(salary) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    T getSalary() const { return salary; }

    virtual Employee* clone() = 0;  // pure virtual clone method

    // Template Method
    void print() {
        std::cout << "Employee Info:" << "\n";
        std::cout << "ID: " << id << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Salary: " << salary << "\n\n";
    }
};

template <typename T>
class Manager : public Employee<T> {
private:
    std::vector<Employee<T>*> subordinates;

public:
    Manager(int id, std::string name, T salary) : Employee<T>(id, name, salary) {}

    void addSubordinate(Employee<T>* subordinate) {
        subordinates.push_back(subordinate);
    }

    std::vector<Employee<T>*> getSubordinates() const { return subordinates; }

    Employee<T>* clone() override {
        Manager<T>* newManager = new Manager<T>(*this);
        for (const auto& subordinate : subordinates) {
            newManager->addSubordinate(subordinate->clone());
        }
        return newManager;
    }
};

template <typename T>
class OtherEmployee : public Employee<T> {
public:
    OtherEmployee(int id, std::string name, T salary) : Employee<T>(id, name, salary) {}

    Employee<T>* clone() override {
        return new OtherEmployee<T>(*this);
    }
};

class IDGenerator {
private:
    static int nextId;
    static IDGenerator instance;  // Static instance of IDGenerator

    // Private constructor to prevent instantiation
    IDGenerator() {}

public:
    static IDGenerator& getInstance() { return instance; }  // Static method that returns a reference to the instance

    static int generateId() { return ++nextId; }
};

int IDGenerator::nextId = 0;
IDGenerator IDGenerator::instance;  // Define the static instance


int main() {
    // Create an ID generator
    IDGenerator& idGen = IDGenerator::getInstance();  // Use the static method to get the instance

    // Create some employees
    Employee<int>* e1 = new OtherEmployee<int>(idGen.generateId(), "Alice", 10000);
    Employee<int>* e2 = new OtherEmployee<int>(idGen.generateId(), "Bob", 20000);
    Manager<int>* m1 = new Manager<int>(idGen.generateId(), "Eve", 30000);

    // Set up the manager's subordinates
    m1->addSubordinate(e1);
    m1->addSubordinate(e2);

    // Clone the manager and modify the clone
    Manager<int>* m1Clone = dynamic_cast<Manager<int>*>(m1->clone());
    m1Clone->addSubordinate(new OtherEmployee<int>(idGen.generateId(), "Claire", 15000));

    // Print the original and cloned manager and their subordinates
    std::cout << "---------------------------------------\n" << "Original Manager:" << "\n";
    m1->print();
    std::cout << "---------------------------------------\n" << "Subordinates:" << "\n";
    for (const auto& subordinate : m1->getSubordinates()) {
        subordinate->print();
    }
    std::cout << "\n";

    std::cout << "Cloned Manager:" << "\n";
    m1Clone->print();
    std::cout << "Subordinates:" << "\n";
    for (const auto& subordinate : m1Clone->getSubordinates()) {
        subordinate->print();
    }

    return 0;
}
