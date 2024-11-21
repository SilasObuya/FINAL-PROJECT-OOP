#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Student {
private:
    string name;
    int id;
    float marks;

public:
   
    Student(string name, int id, float marks) : name(name), id(id), marks(marks) {}

    
    string getName() const { return name; }
    int getID() const { return id; }
    float getMarks() const { return marks; }

  
    void setName(const string& newName) { name = newName; }
    void setMarks(float newMarks) { marks = newMarks; }

   
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Marks: " << marks << endl;
    }
};


class StudentManager {
private:
    vector<Student> students;

    
    int findStudentIndexByID(int id) const {
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].getID() == id)
                return i;
        }
        return -1; 
    }

public:
   
    void addStudent() {
        string name;
        int id;
        float marks;

        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Student ID: ";
        cin >> id;

        while (id <= 0 || !isStudentIDUnique(id)) {
            cout << "Invalid or duplicate ID. Enter a positive unique ID: ";
            cin >> id;
        }

        cout << "Enter Marks: ";
        cin >> marks;

        students.emplace_back(name, id, marks);
        cout << "Student added successfully!\n";
    }

   
    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No students in the system.\n";
            return;
        }
        cout << "\nList of Students:\n";
        for (const auto& student : students) {
            student.display();
        }
    }

    
    void updateStudent() {
        int id;
        cout << "Enter Student ID to update: ";
        cin >> id;

        int index = findStudentIndexByID(id);
        if (index == -1) {
            cout << "Student with ID " << id << " not found.\n";
            return;
        }

        string newName;
        float newMarks;
        cout << "Enter new name (or press Enter to skip): ";
        cin.ignore();
        getline(cin, newName);
        cout << "Enter new marks (or -1 to skip): ";
        cin >> newMarks;

        if (!newName.empty())
            students[index].setName(newName);
        if (newMarks >= 0)
            students[index].setMarks(newMarks);

        cout << "Student updated successfully!\n";
    }

    
    void searchStudentByID() const {
        int id;
        cout << "Enter Student ID to search: ";
        cin >> id;

        int index = findStudentIndexByID(id);
        if (index == -1) {
            cout << "Student with ID " << id << " not found.\n";
            return;
        }

        students[index].display();
    }

    
    void deleteStudent() {
        int id;
        cout << "Enter Student ID to delete: ";
        cin >> id;

        int index = findStudentIndexByID(id);
        if (index == -1) {
            cout << "Student with ID " << id << " not found.\n";
            return;
        }

        students.erase(students.begin() + index);
        cout << "Student deleted successfully!\n";
    }

    
    void getStudentCount() const {
        cout << "Total number of students: " << students.size() << endl;
    }

   
    bool isStudentIDUnique(int id) const {
        return findStudentIndexByID(id) == -1;
    }
};


int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\nStudent Record Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Update Student\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Delete Student\n";
        cout << "6. View Total Number of Students\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.addStudent();
            break;
        case 2:
            manager.displayAllStudents();
            break;
        case 3:
            manager.updateStudent();
            break;
        case 4:
            manager.searchStudentByID();
            break;
        case 5:
            manager.deleteStudent();
            break;
        case 6:
            manager.getStudentCount();
            break;
        case 7:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
