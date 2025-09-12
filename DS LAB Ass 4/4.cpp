#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<char>q;
    int freq[256] = {0};
    char ch;
    cout << "Enter characters: ";
    while (cin.peek() != '\n') {
        cin >> ch;
        freq[ch]++;
        q.push(ch);
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }
        if (q.empty())  cout << -1 << " ";
        else  cout << q.front() << " ";
    }
    return 0;
}
