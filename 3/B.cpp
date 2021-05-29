#include <bits/stdc++.h>
using namespace std;
long long C[1000001];
long long M = 1e9;
void Ready()
{
	C[0] = 1;
	for (int i = 1; i < 1000001; i++)
	{
		C[i] = i * C[i - 1];
		while(C[i] % 10 == 0) C[i] /= 10;
		C[i] %= M;
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
		printf("%05d\n", C[a] % 100000);
	}
}
