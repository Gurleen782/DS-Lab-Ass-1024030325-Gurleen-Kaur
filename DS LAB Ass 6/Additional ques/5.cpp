#include <iostream>
using namespace std;
#define N 3
class node{
public:
    int data;
    node *next, *prev, *up, *down;
    node(int data){
        this->data = data;
        this->next = prev = up = down = NULL;
    }
};
node *list(int mat[N][N]){
    node *head = NULL;
    node *prevrow[N] = {NULL};
    for (int i = 0; i < N; i++){
        node *prev = NULL;
        for (int j = 0; j < N; j++){
            node *curr = new node(mat[i][j]);
            if (!head) head = curr;
            if (prev){
                prev->next = curr;
                curr->prev = prev;
            }
            if (prevrow[j]){
                prevrow[j]->down = curr;
                curr->up = prevrow[j];
            }
            prevrow[j] = curr;
            prev = curr;
        }
    }
    return head;
}
void print(node *head){
    node *row = head;
    while (row){
        node *col = row;
        while (col){
            cout << col->data;
            if (col->next)  cout << " <-> ";
            else  cout << " -> NULL";
            col = col->next;
        }
        cout << endl;
        if (row->down)  cout << "  |      |      |" << endl;
        else  cout << "NULL <-> NULL <-> NULL" << endl;
        row = row->down;
    }
}
int main(){
    int mat[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    node *head = list(mat);
    print(head);
    return 0;
}
