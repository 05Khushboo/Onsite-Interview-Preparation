
// https://codeforces.com/contest/1191/problem/C

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
 
   ll n, m, k; cin >> n >> m >> k;
   ll prr[m];
   for(ll i = 0; i < m; i++) 
   {
      cin >> prr[i];
      prr[i]--;
   }
 
   ll idx = 0, ans = 0, jdx = 0, add = 0;
   while(idx < m)
   {
      ans++;
      jdx = idx;
      ll val = 0;
      while(jdx < m && (prr[jdx] - add) / k == (prr[idx] - add) / k) 
      {
         jdx++;
         val++;
      }
      idx = jdx;
      add += val;
   }
   cout << ans << endl;
   
   return 0;
}