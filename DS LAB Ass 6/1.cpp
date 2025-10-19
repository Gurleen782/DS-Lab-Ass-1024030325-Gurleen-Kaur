#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    node* prev;
    node(int d) { 
        data = d; 
        next = prev = NULL; 
    }
};
void insert(node*& tail, int data, int pos = 0, bool after = true) {
    node* n = new node(data);
    if (!tail) { 
        tail = n;
        tail->next = tail->prev = tail;
        return;
    }
    node* curr = tail;
    if (pos == 0) { 
        curr = tail->next;
        n->next = curr;
        n->prev = tail;
        curr->prev = n;
        tail->next = n;
        return;
    }
    do {
        if (curr->data == pos) {
            if (after) {
                n->next = curr->next;
                n->prev = curr;
                curr->next->prev = n;
                curr->next = n;
                if (curr == tail) tail = n;
            } 
            else {
                n->next = curr;
                n->prev = curr->prev;
                curr->prev->next = n;
                curr->prev = n;
                if (curr == tail->next) tail->next = n;
            }
            return;
        }
        curr = curr->next;
    } while (curr != tail->next);
    cout << pos << " position not found\n";
}
void deletenode(node*& tail, int val) {
    if (!tail) { 
        cout << "List empty\n"; 
        return; 
    }
    node* curr = tail->next;
    do {
        if (curr->data == val) {
            if (curr->next == curr) { 
                delete curr; 
                tail = NULL; 
                return; 
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            if (curr == tail) tail = curr->prev;
            delete curr;
            return;
        }
        curr = curr->next;
    } while (curr != tail->next);
    cout << "node not found\n";
}
bool search(node* tail, int val) {
    if (!tail) return false;
    node* curr = tail->next;
    do {
        if (curr->data == val) return true;
        curr = curr->next;
    } while (curr != tail->next);
    return false;
}
void display(node* tail) {
    if (!tail) { 
        cout << "List empty\n"; 
        return; 
    }
    node* curr = tail->next;
    do { 
        cout << curr->data << " "; 
        curr = curr->next; 
    } while (curr != tail->next);
    cout << endl;
}
int main() {
    node* tail = NULL;
    int choice, value, pos;
    bool after;
    do {
        cout << "\nMENU\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: "; 
                cin >> value;
                if (!tail) insert(tail, value); 
                else {
                    cout << "Enter reference node (0 for beginning): "; 
                    cin >> pos;
                    if (pos == 0) insert(tail, value); 
                    else {
                        cout << "Enter 1 to insert after, 0 to insert before: "; 
                        cin >> after;
                        insert(tail, value, pos, after);
                    }
                }
                break;
            case 2:
                cout << "Enter value to delete: "; 
                cin >> value;
                deletenode(tail, value);
                break;
            case 3: display(tail); 
                break;
            case 4:
                cout << "Enter value to search: "; 
                cin >> value;
                cout << (search(tail, value) ? "Found\n" : "Not Found\n");
                break;
        }
    } while (choice != 5);
    return 0;
}
