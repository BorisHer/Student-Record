#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    string name;
    string srcode;
    string course;
    string subj;
    string prof;
    Node* next;
};

// Stores the head of the Linked List
Node* head = new Node();


bool check(string x)
{
    // Base Case
    if (head == NULL)
        return false;

    Node* t = new Node;
    t = head;

    // Traverse the Linked List
    while (t != NULL) {
        if (t->srcode == x)
            return true;
        t = t->next;
    }

    return false;
}

// Function to insert the record
void Insert_Record(string name,string srcode,
    string course,string subj,
    string prof
)
{
    // if Record Already Exist
    if (check(srcode)) {
        cout << "Student with this record already exists\n";
        return;
    }

    Node* t = new Node();
    t->srcode = srcode;
    t->name = name;
    t->course = course;
    t->subj = subj;
    t->prof = prof;
    t->next = NULL;

    // Insert at Begin
    if (head == NULL
        || (head->srcode >= t->srcode)) {
        t->next = head;
        head = t;
    }

    // Insert at middle or End
    else {
        Node* c = head;
        while (c->next != NULL
               && c->next->srcode < t->srcode) {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }

    cout << "Record Inserted "
         << "Successfully\n";
}

// Function to search record for any
// students Record with roll number
void Search_Record(string srcode)
{
    // if head is NULL
    if (!head) {
        cout << "No such Record Available\n";
        return;
    }

    // Otherwise
    else {
        Node* p = head;
        while (p) {
            if (p->srcode == srcode) {
                cout << "SR CODE\t"
                     << p->srcode << endl;
                cout << "Name\t"
                     << p->name << endl;
                cout << "Course\t"
                     << p->course << endl;
                cout << "Subject\t"
                     << p->subj<< endl;
                cout << "Prof\t"
                     << p->prof << endl;

                return;
            }
            p = p->next;
        }

        if (p == NULL)
            cout << "No such Record Available\n";
    }
}

// Function to delete record students
int Delete_Record(string srcode)
{
    Node* t = head;
    Node* p = NULL;

    // Deletion at Begin
    if (t != NULL
        && t->srcode == srcode) {
        head = t->next;
        delete t;

        cout << "Record Deleted Successfully\n";
        return 0;
    }

    // Deletion Other than Begin
    while (t != NULL && t->srcode != srcode) {
        p = t;
        t = t->next;
    }
    if (t == NULL) {
        cout << "Record does not Exist\n";
        return -1;
        p->next = t->next;

        delete t;
        cout << "Record Deleted "
             << "Successfully\n";

        return 0;
    }
}

// Function to display the Student's
// Record
void Show_Record()
{

    Node* p = head;
    if (p == NULL) {
        cout << "No Record Available\n";
    }
    else {
        cout << "SrCode\tName\tCourse"
             << "\tSubject\tProf\n";

        // Until p is not NULL
        while (p != NULL) {
            cout << p->srcode << "    \t"
                 << p->name << "\t"
                 << p->course << "\t"
                 << p->subj << "\t"
                 << p->prof << endl;
            p = p->next;

        }
    }
}

int main()
{
    head = NULL;
    string name;
    string srcode;
    string course;
    string subj;
    string prof;
    int studno;

    while (true) {
        system("CLS");
        cout << "\n\t\tWelcome to Student Record Management System\n\n"
                "\tChoose\n"
                "\t1 Create a new Record\n"
                "\t2 Delete a student record\n"
                "\t3 Search a Student Record\n"
                "\t4 View all students Record\n"
                "\t5 Exit\n";
        cout << "\nEnter your Choice: ";
        int Choice;

        // Enter Choice
        cin >> Choice;
        if (Choice == 1) {

            system("CLS");
            int studno = 0;
            cout << "No. of students you want to add: ";

            if(!(cin >> studno) || studno < 1) {
                cout << endl << "Invalid input. Please try again. \n";
                cin.clear();
                cin.ignore(132, '\n');
                continue;
            }
        for (int i = 0; i < studno; i++) {
            cout << "\n----Enter the data of student no. " << i + 1 << "-----\n";
            cout << "Enter name of student: ";
            cin >> name;
            cout << "Enter SRCODE: ";
            cin >> srcode;
            cout << "Enter course: ";
            cin >> course;
            cout << "Enter subject: ";
            cin >> subj;
            cout << "Enter prof name: ";
            cin >> prof;
            Insert_Record(name,srcode,course,subj,prof);
        }


        }
        else if (Choice == 2) {
            cout << "Enter  SrCode of Student whose record is to be deleted: ";
            cin >> srcode;
            Delete_Record(srcode);
            system("pause");

        }
        else if (Choice == 3) {
            cout << "Enter Srcode of Student whose record you want to Search: ";
            cin >> srcode;
            Search_Record(srcode);
            system("pause");
        }
        else if (Choice == 4) {
            Show_Record();
            system("pause");
        }
        else if (Choice == 5) {
            exit(0);
        }
        else {
            cout << "Invalid Choice "
                 << "Try Again\n";

        }
    }
    return 0;
}


