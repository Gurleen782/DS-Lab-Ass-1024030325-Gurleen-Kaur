#include <iostream>
#include <string>
using namespace std;
bool anagrams(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    for (int i = 0; i < s1.length(); i++) {
        bool found = false;
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                s2[j] = '#'; 
                found = true;
                break;
            }
        }
        if (!found)  return false;
    }
    return true;
}
int main() {
    string s1 = "cape";
    string s2 = "pace";
    if (anagrams(s1, s2))  cout << "YES,anagrams";
    else  cout << "NO, not anagrams";
    return 0;
}
