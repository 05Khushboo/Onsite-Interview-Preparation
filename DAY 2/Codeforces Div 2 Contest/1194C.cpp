/*input
4
ab
acxb
cax
a
aaaa
aaabbcc
a
aaaa
aabbcc
ab
baaa
aaaaa
*/

// https://codeforces.com/contest/1194/problem/C

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

	int q; cin >> q;
	while(q--)
	{
		string s, t, p; cin >> s >> t >> p;
		bool flag = true;

		vector<int> freq(26, 0);
		for(auto k : p) freq[k - 'a']++;

		int j = 0;
		string ans;
		for(int i = 0; i < t.size(); i++)
		{
			if(s[j] == t[i]) ans += s[j++];
			else
			{
				if(freq[t[i] - 'a'] <= 0)
				{
					flag = false;
					break;
				}
				else
				{
					ans += t[i];
					freq[t[i] - 'a']--;
				}
			}
		}
		while(j < s.size()) 
			ans += s[j++];

		if(ans != t) flag = false;
		
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	
	return 0;
}