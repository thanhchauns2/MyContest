#include <bits/stdc++.h>
using namespace std;
long long C[65];
void Ready()
{
	C[0] = 1;
	for (int i = 1; i < 65; i++)
	{
		C[i] = 2 * C[i - 1];
	}
}
int main()
{
	Ready();
	int T;
	cin >> T;
	while(T--)
	{
		long long a;
		cin >> a;
		long long b = upper_bound(C, C + 65, a) - C;
		cout << C[b - 1] << endl;
	}
}
