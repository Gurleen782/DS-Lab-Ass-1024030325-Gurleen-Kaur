#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
    ~node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "\nMemory freed for " << value << endl;
    }
};
void inserthead(node*& head, node*& tail, int d) {
    node* n = new node(d);
    if (head == NULL) {
        head = tail = n;
        cout<<d<<" inserted\n";
        return;
    }
    n->next = head;
    head = n;
    cout<<d<<" inserted\n";
}
void inserttail(node*& tail, node*& head, int d) {
    node* n = new node(d);
    if (tail == NULL) {
        tail = head = n;
        cout<<d<<" inserted\n";
        return;
    }
    tail->next = n;
    tail = n;
    cout<<d<<" inserted\n";
}
void insertbtw(node*& head, node*& tail, int val, int d, bool before) {
    if (head == NULL) {
        inserthead(head, tail, d);
        return;
    }
    node* curr = head;
    node* prev = NULL;
    while (curr != NULL && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << val << " not found in list\n";
        return;
    }
    node* n = new node(d);
    if (before) {
        if (curr == head) {
            n->next = head;
            head = n;
        } 
        else {
            prev->next = n;
            n->next = curr;
        }
        cout<<d<<" inserted before "<<val<<endl;
    } 
    else {
        n->next = curr->next;
        curr->next = n;
        if (curr == tail)  tail = n;
        cout<<d<<" inserted after "<<val<<endl;
    }
}
void dltbeg(node*& head, node*& tail) {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }
    node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    if (head == NULL) tail = NULL;
    cout<<"deleted\n";
}
void dltend(node*& head, node*& tail) {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = NULL;
        cout<<"deleted\n";
        return;
    }
    node* curr = head;
    while (curr->next != tail) {
        curr = curr->next;
    }
    delete tail;
    tail = curr;
    tail->next = NULL;
    cout<<"deleted\n";
}
void dltval(node*& head, node*& tail, int val) {
    if (head == NULL) {
        cout << "List empty.\n";
        return;
    }
    if (head->data == val) {
        dltbeg(head, tail);
        return;
    }
    node* curr = head->next;
    node* prev = head;
    while (curr != NULL && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << val << " not in list\n";
        return;
    }
    prev->next = curr->next;
    if (curr == tail) {
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
    cout<<"deleted\n";
}
void search(node* head, int d) {
    node* curr = head;
    int pos = 1;
    while (curr != NULL) {
        if (curr->data == d) {
            cout << d << " found at pos " << pos << ".\n";
            return;
        }
        curr = curr->next;
        pos++;
    }
    cout << d << " not found in list\n";
}
void print(node* head) {
    if (head == NULL) {
        cout << "List empty.\n";
        return;
    }
    node* n = head;
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
int main() {
    node* head = NULL;
    node* tail = NULL;
    int choice, val, nod;
    bool before;
    while (1) {
        cout << "\nMENU\n";
        cout << "1. Insertion at the beginning\n";
        cout << "2. Insertion at the end\n";
        cout << "3. Insertion in between (before/after node)\n";
        cout << "4. Deletion from the beginning\n";
        cout << "5. Deletion from the end\n";
        cout << "6. Deletion of a node\n";
        cout << "7. Search for a node and display position\n";
        cout << "8. Display all the node values\n";
        cout << "9. Exit\n";
        cout << "Enter a function: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter to insert: ";
            cin >> val;
            inserthead(head, tail, val);
            break;
        case 2:
            cout << "Enter to insert: ";
            cin >> val;
            inserttail(tail, head, val);
            break;
        case 3:
            if (head == NULL) {
                cout << "Enter to insert: ";
                cin >> val;
                inserthead(head, tail, val);
                break;
            }
            cout << "Enter node to insert before/after: ";
            cin >> nod;
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter 1 to insert before and 0 to insert after: ";
            cin >> before;
            insertbtw(head, tail, nod, val, before);
            break;
        case 4:
            dltbeg(head, tail);
            break;
        case 5:
            dltend(head, tail);
            break;
        case 6:
            cout << "Enter node to delete: ";
            cin >> val;
            dltval(head, tail, val);
            break;
        case 7:
            cout << "Enter to search: ";
            cin >> val;
            search(head, val);
            break;
        case 8:
            print(head);
            break;
        case 9:
            cout << "Exiting\n";
            delete head;
            return 0;
        default:
            cout << "Invalid function\n";
        }
    }
    return 0;
}
