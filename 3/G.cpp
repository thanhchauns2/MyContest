#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define ll long long

ll a;

unordered_map<ll,ll> mymap, myend;

void Proceed()
{
	queue<ll> A;
	A.push(a);
	mymap[a] = 0;
	while(!A.empty())
	{
		ll x = A.front();
		A.pop();
// 		if (x == 1) return mymap[x];
		ll steps = mymap[x];
		if (!mymap[x-1])
		{
			A.push(x-1);
			mymap[x-1] = steps + 1;
		}
		FOR(i,2,sqrt(x))
		{
			if (x % i == 0 && !mymap[x/i])
			{
				mymap[x/i] = steps + 1;
				A.push(x/i);
			}
		}
		if (mymap[A.back()] == 7) return;
	}
}

ll Find()
{
    queue<ll> A;
	A.push(1);
	myend[a] = 0;
	while(!A.empty())
	{
		ll x = A.front();
		A.pop();
		if (mymap[x]) return mymap[x] + myend[x];
		ll steps = myend[x];
		if (!myend[x+1])
		{
			A.push(x+1);
			myend[x+1] = steps + 1;
		}
		FOR(i,2,x)
		{
			if (!myend[x*i])
			{
				myend[x*i] = steps + 1;
				A.push(x*i);
			}
		}
		if (myend[A.back()] == 7) return -1;
	}
}

int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		cin>>a;
		mymap.clear();
		myend.clear();
		Proceed();
		cout<<Find()<<endl;
	}
}
