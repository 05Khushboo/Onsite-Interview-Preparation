/*input
4
0 3
3 3
3 4
4 4
*/

// https://codeforces.com/contest/1194/problem/D

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
		int n, k; cin >> n >> k;
		
		if(k % 3 == 0)
		{
			int rem = n % (k + 1);
			if(rem % 3 != 0 || rem == k)
				cout << "Alice" << endl;
			else 
				cout << "Bob" << endl;
		}
		else
		{
			if(n % 3 == 0)
				cout << "Bob" << endl;
			else
				cout << "Alice" << endl;
		}

	}
	
	return 0;
}