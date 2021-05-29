#include<bits/stdc++.h>
using namespace std;
const int Max = 1e6 + 1;
const int Mod = 1e6 + 7;
typedef long long ll;
ll a[Max];
bool b[Max];
int n, k;

void solve(){
    cin >> n >> k;
    int x;
    for(int i = 0; i < k; i++){
        cin >> x;
        b[x] = false;
    }
    if(b[1] == false){
        a[1] = 0;
        if(b[2] == true) a[2] = 1;
        else a[2] = 0;
    }
    if(b[1] == true){
        a[1] = 1;
        if(b[2] == true) a[2] = 2;
        else a[2] = 0;
    }
    for(int i = 3; i <= n; i++){
        if(b[i] == false) a[i] = 0;
        else a[i] = (a[i - 1] + a[i - 2])%Mod;
    }
    cout << a[n] << endl;
}
int main (){
    memset(b, true, sizeof b);
    ios_base::sync_with_stdio(false);cin.tie(0);
    solve();
}
