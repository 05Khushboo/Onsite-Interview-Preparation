
// https://codeforces.com/contest/1191/problem/D

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
 
   ll n; cin >> n;
   ll arr[n];
   map<ll,ll> m;
   for(ll i = 0; i < n; i++) 
   {
      cin >> arr[i];
      m[arr[i]]++;
   }
   vector<ll> v;
   for(auto k : m)
   {
      if(k.second >= 2)
         v.pb(k.first);
   }
   if(v.size() >= 2)
   {
      cout << "cslnb" << endl;
      return 0;
   }
   ll player = 1;
   if(v.size() == 1)
   {
      ll val = v[0];
      m[val]--;
      val--;
      if(val < 0 || m.find(val) != m.end() || m[val + 1] >= 2)
      {
         cout << "cslnb" << endl;
         return 0;
      }
      m[val]++;
      player = 2;
   }
   v.clear();
   for(auto k : m)
      v.pb(k.first);
   ll mn = 0;
   for(auto k : v)
   {
      if(k == mn) 
      {
         mn++;
         continue;
      }
      ll diff = k - mn;
      if(diff & 1)
      {
         if(player == 2) 
            player = 1;
         else
            player = 2;
      }
      mn++;
   }
   if(player == 1)
      cout << "cslnb" << endl;
   else 
      cout << "sjfnb" << endl;
   return 0;
}