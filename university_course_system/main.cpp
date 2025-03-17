#include <iostream>
#include <string>
using namespace std;

// Forward declaration of Student class
class Student;

class Course {
private:
    string courseName;
    int maxEnrollment;
    Student* enrolledStudents[100];
    int currentEnrollment;

public:
    // Constructor to initialize course name and maximum enrollment
    Course(const string& name, int maxEnroll) : courseName(name), maxEnrollment(maxEnroll), currentEnrollment(0) {}

    // Method to enroll a student in the course
    bool enroll(Student* student);
    
    // Method to drop a student from the course
    void drop(Student* student);
    
    // Method to get the list of enrolled students
    Student** getEnrolledStudents() const;

    // Getter for course name
    string getCourseName() const { return courseName; }
    
    // Getter for current enrollment count
    int getCurrentEnrollment() const { return currentEnrollment; }
};

class Student {
private:
    string studentName;
    Course* enrolledCourses[10];
    int currentCourses;

public:
    // Constructor to initialize student name
    Student(const string& name) : studentName(name), currentCourses(0) {}

    // Method to enroll in a course
    void enroll(Course* course);

    // Method to drop a course
    void drop(Course* course);

    // Method to get the list of enrolled courses
    Course** getEnrolledCourses() const;

    // Getter for student name
    string getStudentName() const { return studentName; }

    // Getter for current number of enrolled courses
    int getCurrentCourses() const { return currentCourses; }
};

// Implementation of Course::enroll method
bool Course::enroll(Student* student) {
    if (currentEnrollment < maxEnrollment) {
        enrolledStudents[currentEnrollment++] = student;
        return true;
    }
    return false;
}

// Implementation of Course::drop method
void Course::drop(Student* student) {
    for (int i = 0; i < currentEnrollment; ++i) {
        if (enrolledStudents[i] == student) {
            for (int j = i; j < currentEnrollment - 1; ++j) {
                enrolledStudents[j] = enrolledStudents[j + 1];
            }
            --currentEnrollment;
            break;
        }
    }
}

// Implementation of Course::getEnrolledStudents method
Student** Course::getEnrolledStudents() const {
    return const_cast<Student**>(enrolledStudents);
}

// Implementation of Student::enroll method
void Student::enroll(Course* course) {
    if (course->enroll(this)) {
        enrolledCourses[currentCourses++] = course;
    } else {
        cout << "Enrollment failed for course: " << course->getCourseName() << endl;
        cout << endl;
    }
}

// Implementation of Student::drop method
void Student::drop(Course* course) {
    for (int i = 0; i < currentCourses; ++i) {
        if (enrolledCourses[i] == course) {
            for (int j = i; j < currentCourses - 1; ++j) {
                enrolledCourses[j] = enrolledCourses[j + 1];
            }
            --currentCourses;
            course->drop(this);
            break;
        }
    }
}

// Implementation of Student::getEnrolledCourses method
Course** Student::getEnrolledCourses() const {
    return const_cast<Course**>(enrolledCourses);
}

int main() {
    // Create courses with maximum enrollment of 2 students each
    Course math("Math", 2);
    Course science("Science", 2);
    Course informatics("Informatics", 2);

    // Create students
    Student alice("Alice");
    Student bob("Bob");
    Student charlie("Charlie");
    Student charles("Charles");

    // Enroll students in courses
    alice.enroll(&math);
    bob.enroll(&math);
    
    alice.enroll(&science);
    bob.enroll(&science);
    charles.enroll(&science); // Should fail due to max enrollment

    charles.enroll(&informatics);
    alice.enroll(&informatics);
    bob.enroll(&informatics); // Should fail due to max enrollment


    // Drop students from courses
    alice.drop(&math);

    // Print students enrolled in Math
    cout << "Students enrolled in Math:" << endl;
    for (int i = 0; i < math.getCurrentEnrollment(); ++i) {
        cout << math.getEnrolledStudents()[i]->getStudentName() << endl;
    }

    // Print students enrolled in Science
    cout << endl;
    cout << "Students enrolled in Science:" << endl;
    for (int i = 0; i < science.getCurrentEnrollment(); ++i) {
        cout << science.getEnrolledStudents()[i]->getStudentName() << endl;
    }


    // Print students enrolled in Informatics
    cout << endl;
    cout << "Students enrolled in Informatics:" << endl;
    for (int i = 0; i < informatics.getCurrentEnrollment(); ++i) {
        cout << informatics.getEnrolledStudents()[i]->getStudentName() << endl;
    }

    return 0;
}
