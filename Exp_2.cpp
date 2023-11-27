#include <iostream>
#include <string>
using namespace std;

struct Member {
    int MIS;
    string name;
    Member* next;
};

class ClubList {
private:
    Member* head;
    Member* tail;
    int totalMembers;

public:
    ClubList() {
        head = nullptr;
        tail = nullptr;
        totalMembers = 0;
    }

    // Function to add a member to the list
    void add(int MIS, string name) {
        Member* newMember = new Member;
        newMember->MIS = MIS;
        newMember->name = name;
        newMember->next = nullptr;

        if (head == nullptr) {
            head = newMember;
            tail = newMember;
        } else {
            tail->next = newMember;
            tail = newMember;
        }
        totalMembers++;
    }

    // Function to remove a member from the list
    void remove(int MIS) {
        Member* current = head;
        Member* prev = nullptr;

        while (current != nullptr) {
            if (current->MIS == MIS) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                totalMembers--;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Member with MIS " << MIS << " not found." << endl;
    }

    // Function to display all members in the list
    void displayMembers() {
        Member* current = head;
        while (current != nullptr) {
            cout << "MIS: " << current->MIS << " Name: " << current->name << endl;
            current = current->next;
        }
    }

    // Function to get the total number of members in the list
    int getTotalMembers() {
        return totalMembers;
    }

    // Function to concatenate two lists
    void concatenateLists(ClubList& list2) {
        if (head == nullptr) {
            head = list2.head;
        } else {
            tail->next = list2.head;
            tail = list2.tail;
        }
        totalMembers += list2.totalMembers;
    }
};

int main() {
    ClubList firstYear;
    ClubList secondYear;

    int choice;

    do {
        cout << "Select an option:" << endl;
        cout << "1. Add Member" << endl;
        cout << "2. Remove Member" << endl;
        cout << "3. Total Members" << endl;
        cout << "4. Display Members" << endl; 
        cout << "5. Concatenate Lists" << endl;
        cout << "6. Exit" << endl; 

        cin >> choice;

        switch (choice) {
            case 1: {
                int listChoice;
                cout << "Select the list (1. First / 2. Second): ";
                cin >> listChoice;
                int MIS;
                string name;
                cout << "Enter MIS and name: ";
                cin >> MIS >> name;
                if (listChoice == 1) {
                    firstYear.add(MIS, name);
                } else if (listChoice == 2) {
                    secondYear.add(MIS, name);
                } else {
                    cout << "Invalid choice." << endl;
                }
                break;
            }
            case 2: {
                int listChoice;
                cout << "Select the list (1. First / 2. Second): ";
                cin >> listChoice;
                int MIS;
                cout << "Enter MIS to remove: ";
                cin >> MIS;
                if (listChoice == 1) {
                    firstYear.remove(MIS);
                } else if (listChoice == 2) {
                    secondYear.remove(MIS);
                } else {
                    cout << "Invalid choice." << endl;
                }
                break;
            }
            case 3: {
                int listChoice;
                cout << "Select the list (1. First / 2. Second): ";
                cin >> listChoice;
                if (listChoice == 1) {
                    cout << "Total members in First: " << firstYear.getTotalMembers() << endl;
                } else if (listChoice == 2) {
                    cout << "Total members in Second: " << secondYear.getTotalMembers() << endl;
                } else {
                    cout << "Invalid choice." << endl;
                }
                break;
            }
            case 4: {
                int listChoice;
                cout << "Select the list to display members (1. First / 2. Second): ";
                cin >> listChoice;
                if (listChoice == 1) {
                    cout << "Members in the First list:" << endl;
                    firstYear.displayMembers();
                } else if (listChoice == 2) {
                    cout << "Members in the Second list:" << endl;
                    secondYear.displayMembers();
                } else {
                    cout << "Invalid choice." << endl;
                }
                break;
            }
            case 5: {
                firstYear.concatenateLists(secondYear);
                cout << "Lists concatenated." << endl;
                break;
            }
            case 6: {
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}
