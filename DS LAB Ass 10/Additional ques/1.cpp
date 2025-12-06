#include<iostream>
#include<unordered_map>
using namespace std;
int main () {
    unordered_map<int, int> freq;
    int maxfreq = 0;
    int ans = 0;
    int arr[6] = {1, 2, 2, 4, 1, 3};
    for (int i = 0; i < 6; i++) {
        freq[arr[i]]++;
        maxfreq = max(maxfreq, freq[arr[i]]);
        if (freq[arr[i]] == maxfreq) {
            ans = max(arr[i],ans);
        }
    }
    cout << ans;
}
