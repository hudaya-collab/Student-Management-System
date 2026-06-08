#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student
{
public:
    int id;
    string name;
    int age;
    string course;
};
void addStudent()
{
  Student s;
  ofstream file("students.txt", ios::app);
  cout << "\nEnter Student ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, s.name);
    cout << "Enter Age: ";
    cin >> s.age;
    cin.ignore();
    cout << "Enter Course: ";
    getline(cin, s.course);
         file << s.id << "|"
         << s.name << "|"
         << s.age << "|"
         << s.course << endl;
         file.close();
cout << "\nStudent Added Successfully!\n";
}
void displayStudents()
{
    ifstream file("students.txt");
    string line;
    cout << "\n----- Student Records -----\n";
    while (getline(file, line))
    {
        cout << line << endl;
    }
file.close();
}
void searchStudent()
{
    ifstream file("students.txt");
    int searchId;
    string line;
    cout << "\nEnter Student ID to Search: ";
    cin >> searchId;
    bool found = false;
   while (getline(file, line))
    {
        size_t pos = line.find("|");
        int id = stoi(line.substr(0, pos));

        if (id == searchId)
        {
            cout << "\nRecord Found:\n";
            cout << line << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nStudent Not Found!\n";

    file.close();
}

void deleteStudent()
{
    int deleteId;

    cout << "\nEnter Student ID to Delete: ";
    cin >> deleteId;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    string line;
    bool found = false;

    while (getline(file, line))
    {
        size_t pos = line.find("|");
        int id = stoi(line.substr(0, pos));

        if (id != deleteId)
        {
            temp << line << endl;
        }
        else
        {
            found = true;
        }
    }

    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (found)
        cout << "\nStudent Deleted Successfully!\n";
    else
        cout << "\nStudent Not Found!\n";
}
void updateStudent()
{
    int updateId;
    cout << "\nEnter Student ID to Update: ";
    cin >> updateId;
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    string line;
    bool found = false;
    while (getline(file, line))
    {
        size_t pos = line.find("|");
        int id = stoi(line.substr(0, pos));
        if (id == updateId)
        {
            found = true;
            Student s;
            s.id = updateId;
            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, s.name);
            cout << "Enter New Age: ";
            cin >> s.age;
            cin.ignore();
            cout << "Enter New Course: ";
            getline(cin, s.course);

            temp << s.id << "|"
                 << s.name << "|"
                 << s.age << "|"
                 << s.course << endl;
        }
        else
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (found)
        cout << "\nStudent Updated Successfully!\n";
    else
       cout << "\nStudent Not Found!\n";
}
int main()
{
    int choice;
    do
    {
        cout << "\n==============================";
        cout << "\n STUDENT MANAGEMENT SYSTEM";
        cout << "\n==============================";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Exit";
        cout << "\n\nEnter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            updateStudent();
            break;
        case 5:
            deleteStudent();
            break;
        case 6:
            cout << "\nThank You!\n";
            break;
 default:
            cout << "\nInvalid Choice!\n";
        }
} while (choice != 6);
return 0;
}
