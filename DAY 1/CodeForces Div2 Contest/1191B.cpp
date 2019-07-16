
// https://codeforces.com/contest/1191/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   map<char, vector<ll> > m;
   for(ll i = 0; i < 3; i++)
   {
      char ch1, ch2; cin >> ch1 >> ch2;
      ll val = ch1 - '0';
      m[ch2].pb(val);
   }
 
   ll ans = 2;
 
   for(auto k : m)
   {
      sort(k.second.begin(), k.second.end());
      ll a1 = -1, a2 = -1, a3 = -1;
      if(k.second.size() == 3)
         a1 = k.second[0], a2 = k.second[1], a3 = k.second[2];
      else if(k.second.size() == 2)
         a1 = k.second[0], a2 = k.second[1];
      else
         a1 = k.second[0];
      if(a1 == a2 && a2 == a3)
      {
         cout << 0 << endl;
         return 0;
      }
      else if(a1 == (a2 - 1) && a2 == (a3 - 1))
      {
         cout << 0 << endl;
         return 0;
      }
      if(a1 == a2 || (a2 == a3 && a2 != -1))
         ans = 1;
      else if(a1 == (a2 - 1) || a1 == (a2 - 2) || a2 == (a3 - 1) || a2 == (a3 - 2))
         ans = 1;
   }
 
   cout << ans << endl;
   
   return 0;
}