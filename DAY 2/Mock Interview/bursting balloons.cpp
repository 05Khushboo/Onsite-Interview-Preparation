
// https://codezen.codingninjas.in/practice/79523/3645/bursting-balloons

#include<bits/stdc++.h>
using namespace std;
int main() {
    
    int n; cin >> n;
    int H[n];
    for(int i = 0; i < n; i++)
        cin >> H[i];
    
    map<int, int> freq;
    int arrows = 0;
    for(int i = 0; i < n; i++)
    {
        if(freq.find(H[i] + 1) != freq.end())
        {
            freq[H[i] + 1]--;
            if(freq[H[i] + 1] <= 0) freq.erase(H[i] + 1);
        }
        else
            arrows++;
        freq[H[i]]++;
    }
    
    cout << arrows << endl;
}