
// https://codeforces.com/contest/1194/problem/B

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
		int n, m; cin >> n >> m;
		int matrix[n][m], row[n], col[m];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				char ch; cin >> ch;
				if(ch == '.') matrix[i][j] = 0;
				else matrix[i][j] = 1;
			}
		}

		for(int i = 0; i < n; i++)
		{
			int cnt = 0;
			for(int j = 0; j < m; j++)
				if(matrix[i][j] == 0)
					cnt++;
			row[i] = cnt;
		}
		for(int j = 0; j < m; j++)
		{
			int cnt = 0;
			for(int i = 0; i < n; i++)
				if(matrix[i][j] == 0)
					cnt++;
			col[j] = cnt;
		}

		int answer = INT_MAX;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				int total = row[i] + col[j];
				if(matrix[i][j] == 0) total--;
				answer = min(answer, total);
			}
		}

		cout << answer << endl;

	}


	return 0;
}