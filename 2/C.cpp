#include <bits/stdc++.h>
using namespace std;
vector<double> C;
double MIN, MAX, k;
int a;
double calculate(double x)
{
	vector<double> F = C;
	double total = 0;
	F[0] -= x;
	for (int i=1; i<a; i++) 
	{
		F[i] -= x;
		F[i] += F[i-1];
	}
	vector<double> K = F;
	double sampleMAX = F[0];
	for (int i=0; i<a; i++)
	{
		F[i] -= total;
		if (F[i] < 0) total += F[i];
		sampleMAX = max(sampleMAX, F[i]);
	}
	double sampleMIN = K[0];
	total = 0;
	for (int i=0; i<a; i++)
	{
		K[i] -= total;
		if (K[i] > 0) total += K[i];
		sampleMIN = min(sampleMIN, K[i]);
	}
	return max(abs(sampleMAX), abs(sampleMIN));
}
int main()
{
	cin>>a;
	double token;
	for (int i=0; i<a; i++) 
	{
		cin>>token;
		C.push_back(token);
	}
	MAX = C[0];
	MIN = C[0];
	for (int i=1; i<a; i++)
	{
		MAX = max(MAX, C[i]);
		MIN = min(MIN, C[i]);
	}
	while (MAX - MIN > 0.000000000005)
	{
		k = (MIN + MAX) / 2;
		double x1 = calculate(MIN);
		double x2 = calculate(MAX);
		double x3 = calculate(k);
		if (x1 > x3 && x3 > x2)
		{
			MIN = k;
		}
		else if (x2 > x3 && x3 > x1)
		{
			MAX = k;
		}
		else
		{
			double x4 = calculate(k - 0.000000000005);
			double x5 = calculate(k + 0.000000000005);
			if (x4 > x3 && x3 > x5) MIN = k;
			else MAX = k;
		}
	}
	// cout<<MIN<<' '<<MAX<<endl;
	cout<<setprecision(6)<<fixed<<min(calculate(MIN), calculate(MAX));
}
