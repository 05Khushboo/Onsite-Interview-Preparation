/*input
3
3 1
4 2
69 6
*/

// https://codeforces.com/contest/1194/problem/A

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

	int t; cin >> t;
	while(t--)
	{
		int n, x; cin >> n >> x;
		x = 2 + (x - 1) * 2;
		cout << x << endl;
	}
	
	return 0;
}