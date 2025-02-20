#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int id;

public:
    Student() : name(""), id(0) {
        cout << "Student default Constructor is called " << endl;
    }

    Student(string n, int i) : name(n), id(i) {
        cout << "Student paramterized Constructor is called " << endl;
    }

    ~Student() {
        cout << "Student Destructor is called " << endl;
    }

    void setName(string n) { name = n; }
    void setId(int i) { id = i; }

    string getName() const { return name; }
    int getId() const { return id; }

    void print() const {
        cout << "Student Data: Name = " << name << ", ID = " << id << endl;
    }
};

class Course {
private:
    string courseName;
    int courseCode;

public:
    Course() : courseName(""), courseCode(0) {
        cout << "Course default Constructor is called " << endl;
    }

    Course(string cn, int cc) : courseName(cn), courseCode(cc) {
        cout << "Course paramterized Constructor is called " << endl;
    }

    ~Course() {
        cout << "Course Destructor is calling " << endl;
    }

    void setCourseName(string cn) { courseName = cn; }
    void setCourseCode(int cc) { courseCode = cc; }

    string getCourseName() const { return courseName; }
    int getCourseCode() const { return courseCode; }

    void print() const {
        cout << "Course Data: Name = " << courseName << ", Code = " << courseCode << endl;
    }
};

class University {
private:
    int studentNum;
    int courseNum;
    Student* pStudents;
    Course* pCourses;

public:
    University() : studentNum(0), courseNum(0), pStudents(nullptr), pCourses(nullptr) {}

    University(int sn, int cn, Student* sArr, Course* cArr)
        : studentNum(sn), courseNum(cn), pStudents(sArr), pCourses(cArr) {}

    ~University() {
        cout << "University Destructor is calling " << endl;
    }

    void setStudents(int sn, Student* sArr) {
        studentNum = sn;
        pStudents = sArr;
    }

    void setCourses(int cn, Course* cArr) {
        courseNum = cn;
        pCourses = cArr;
    }

    void print() const {
        cout << "University Students:" << endl;
        for (int i = 0; i < studentNum; i++) {
            pStudents[i].print();
        }

        cout << "University Courses:" << endl;
        for (int j = 0; j < courseNum; j++) {
            pCourses[j].print();
        }
    }
};

int main() {
    Student sArr[3] = {Student("Alice", 101), Student("Bob", 102), Student("Charlie", 103)};
    Course cArr[2] = {Course("Mathematics", 201), Course("Physics", 202)};

    University myUni;
    myUni.setStudents(3, sArr);
    myUni.setCourses(2, cArr);

    myUni.print();

    return 0;
}