#include <iostream>
using namespace std;
class Department {
private:
 string name;
public:
 Department(string name){
 this->name=name;
 }
 void addCourse(string courseName) {
 cout << "Added course: " << courseName << " to " << name <<
endl;
 }
 void addStudent(string studentName) {
 cout << "Added student: " << studentName << " to " << name <<
endl;
 }
 void display() {
 cout << "Department: " << name << endl;
 }
};
class Course : public Department {
private:
 string courseName;
 string students[25];
 int studentCount;
public:
 Course(string departmentName, string courseName):Department(departmentName){
     this->courseName=courseName;
     studentCount=0;
 }
 void addStudent(const string studentName) {
 if (studentCount < 25) {
 students[studentCount++] = studentName;
 cout << "Added student: " << studentName << " to course: " <<
courseName << endl;
 }
 else{
 cout << "Course is full. Cannot enroll more students" << endl;
 }
 }
 void display() {
 cout << "Course: " << courseName << endl;
 for (int i = 0; i < studentCount; i++) {
 cout << "Student: " << students[i] << endl;
 }
 }
};
class Student : public Course {
private:
 string studentName;
public:
 Student(string departmentName, string courseName, string studentName):Course(departmentName, courseName){
 this->studentName=studentName;
 }
 void display() {
 cout << "Student: " << studentName << endl;
 }
};
int main() {
 Department ob1("SST");
 Course ob2("CS", "OOP(Theory)");
 ob2.addStudent("Affan");
 ob2.addStudent("Adil");
 ob2.addStudent("Moeez");
 ob1.display();
 ob2.display();
}
