// https://codeforces.com/contest/1191/problem/A

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
 
   ll x; cin >> x;
   map<char,ll> m;
   m['A'] = 1; m['B'] = 3; m['C'] = 2; m['D'] = 0;
   for(auto k : m)
   {
      ll rem = k.second;
      for(ll j = 0; j <= 2; j++)
      {
         ll no = x + j;
         if(no % 4 == rem)
         {
            cout << j << " " << k.first << endl;
            return 0;
         }
      }
   }
   
   return 0;
}