#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Student
{
public:
    int rollNumber;
    char studentName[15];
    float sgpa;

    void inputStudentDetails()
    {
        cout << "\nEnter the student's name: ";
        cin >> studentName;
        cout << "Enter the roll number: ";
        cin >> rollNumber;
        cout << "Enter the SGPA: ";
        cin >> sgpa;
    }

    void displayStudentDetails()
    {
        cout << "\nStudent name: " << studentName;
        cout << "\nRoll number: " << rollNumber;
        cout << "\nSGPA: " << sgpa << "\n\n";
    }

    static void bubbleSortByRollNumber(vector<Student> &students)
    {
        int n = students.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (students[j].rollNumber > students[j + 1].rollNumber)
                {
                    swap(students[j], students[j + 1]);
                }
            }
        }
    }

    static void insertionSortByName(vector<Student> &students)
    {
        int n = students.size();
        for (int i = 1; i < n; i++)
        {
            Student key = students[i];
            int j = i - 1;
            while (j >= 0 && (strcmp(students[j].studentName, key.studentName) > 0))
            {
                students[j + 1] = students[j];
                j = j - 1;
            }
            students[j + 1] = key;
        }
    }

    static void quickSortBySgpa(vector<Student> &students, int start, int end)
    {
        if (start >= end)
            return;

        int p = partitionBySgpa(students, start, end);

        quickSortBySgpa(students, start, p - 1);
        quickSortBySgpa(students, p + 1, end);
    }

    static int partitionBySgpa(vector<Student> &students, int start, int end)
    {
        float pivot = students[start].sgpa;
        int count = 0;
        for (int i = start + 1; i <= end; i++)
        {
            if (students[i].sgpa <= pivot)
                count++;
        }

        int pivotIndex = start + count;

        swap(students[pivotIndex], students[start]);

        int i = start, j = end;
        while (i < pivotIndex && j > pivotIndex)
        {
            while (students[i].sgpa <= pivot)
            {
                i++;
            }
            while (students[j].sgpa > pivot)
            {
                j--;
            }
            if (i < pivotIndex && j > pivotIndex)
            {
                swap(students[i], students[j]);
            }
        }
        return pivotIndex;
    }

    static void LinearSearch(const vector<Student> &students, float target,int n)
    {
        cout << "Students with SGPA " << target << " are:" << endl;
        bool found = false;
        for (int i=0;i<n;i++)
        {
            if (students[i].sgpa == target)
            {
                cout<<students[i].studentName<<endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "No students found with the specified SGPA." << endl;
        }
    }
    static int binarySearch(const vector<Student>& students, const string& targetName) {
        int left = 0, right = students.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (students[mid].studentName == targetName) {
                return mid;
            } else if (students[mid].studentName < targetName) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    int n;
    cout << "Enter how many student records you want to enter: ";
    cin >> n;
    vector<Student> students(n);

    for (int i = 0; i < n; i++)
    {
        students[i].inputStudentDetails();
    }

    Student::bubbleSortByRollNumber(students);
    cout << "\nAfter Bubble sorting by Roll NO:";
    for (int i = 0; i < n; i++)
    {
        students[i].displayStudentDetails();
        cout << "-----------------------------------\n";
    }
    Student::insertionSortByName(students);
    cout << "\nAfter Insertion sorting by Name:";
    for (int i = 0; i < n; i++)
    {
        students[i].displayStudentDetails();
        cout << "-----------------------------------\n";
    }
    Student::quickSortBySgpa(students, 0, n - 1);

    cout << "\nAfter QUICK sorting by SGPA:";
    for (int i = 0; i < n; i++)
    {
        students[i].displayStudentDetails();
        cout << "-----------------------------------\n";
    }

    float target;
    cout << "Enter the SGPA to search: ";
    cin >> target;
    Student::LinearSearch(students, target,n);
    cout << "Enter the Name to search: ";
    string name;
    cin >> name;
    int index = Student::binarySearch(students,name);
    if(index>=0){
        cout<<"The student is found at index: "<<index;
    }
    else{
        cout<<"Student is not found!";
    }
    return 0;
}
