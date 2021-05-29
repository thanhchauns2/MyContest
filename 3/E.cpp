#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n>2021||n==1)
    {
        cout<<0<<endl;
        return;
    }
    int ans=1;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            ans=((ans%2021)*(abs(a[i]-a[j])%2021))%2021;
    cout<<ans<<endl;


}
int main()
{
    solve();
}
