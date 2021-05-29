#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long M = 1e9 + 7;
	int T;
	cin >> T;
	while(T--)
	{
		long long a, b;
		cin >> a >> b;
		long long k = a * b % M;
		cout << k << endl;
	}
}
