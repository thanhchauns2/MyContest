/*

 * @author SangND
 * IT2 - 03
 * HUST - K63
 * -- Must try to do something for the future and someone --

				 ─────▄██▀▀▀▀▀▀▀▀▀▀▀▀▀██▄─────
				 ────███───────────────███────
				 ───███─────────────────███───
				 ──███───▄▀▀▄─────▄▀▀▄───███──
				 ─████─▄▀────▀▄─▄▀────▀▄─████─
				  ████──▄████─────████▄──█████
				 █████─██▓▓▓██───██▓▓▓██─█████
				 █████─██▓█▓██───██▓█▓██─█████
				 █████─██▓▓▓█▀─▄─▀█▓▓▓██─█████
				 ████▀──▀▀▀▀▀─▄█▄─▀▀▀▀▀──▀████
				 ███─▄▀▀▀▄────███────▄▀▀▀▄─███
				 ███──▄▀▄─█──█████──█─▄▀▄──███
				 ███─█──█─█──█████──█─█──█─███
				 ███─█─▀──█─▄█████▄─█──▀─█─███
				 ███▄─▀▀▀▀──█─▀█▀─█──▀▀▀▀─▄███
				 ████─────────────────────████
				 ─███───▀█████████████▀───████
				 ─███───────█─────█───────████
				 ─████─────█───────█─────█████
				 ───███▄──█────█────█──▄█████─
				 ─────▀█████▄▄███▄▄█████▀─────
				 ──────────█▄─────▄█──────────
				 ──────────▄█─────█▄──────────
				 ───────▄████─────████▄───────
				 ─────▄███████───███████▄─────
				 ───▄█████████████████████▄───
				 ─▄███▀───███████████───▀███▄─
				 ███▀─────███████████─────▀███
				 ▌▌▌▌▒▒───███████████───▒▒▐▐▐▐
				 ─────▒▒──███████████──▒▒─────
				 ──────▒▒─███████████─▒▒──────
				 ───────▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒───────
				 ─────────████░░█████─────────
				 ────────█████░░██████────────
				 ──────███████░░███████───────
				 ─────█████──█░░█──█████──────
				 ─────█████──████──█████──────
				 ──────████──████──████───────
				 ──────████──████──████───────
				 ──────████───██───████───────
				 ──────████───██───████───────
				 ──────████──████──████───────
				 ─██────██───████───██─────██─
				 ─██───████──████──████────██─
				 ─███████████████████████████─
				 ─██─────────████──────────██─
				 ─██─────────████──────────██─
				 ────────────████─────────────
				 ─────────────██──────────────
-  Play with me and enjoy coding...

------------------------------------------------------------------------
- *** Everything will be okay in the end
-   If it isn't okay, it isn't the end ***
			-- From someone who has been --

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <numeric>
#include <chrono>
#include <random>
#include <functional>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <array>
#include <bitset>
#include <unordered_map>

#define lb lower_bound
#define up upper_bound
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pob pop_back
#define fs first
#define sd second
#define gcd __gcd
#define endl "\n"
#define NDS ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 1e6 + 1;

int n, sa[N], ra[N], rb[N], G, ans;
string a, s;

bool cmp(int x, int y){
    if(ra[x] != ra[y]) return ra[x] < ra[y];
    return ra[x + G] < ra[y + G];
}

void build(){
    getline(cin, a);
    //fflush(stdin);
    n = a.size();

    for(int i = 0; i < n; i++){
        sa[i] = i;
        ra[i] = a[i];
    }

    for(G = 1; G <= n; G *= 2){
        sort(sa, sa + n, cmp);
        for(int i = 0; i < n; i++){
            rb[sa[i]] = rb[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        }
        for(int i = 0; i < n; i++){
            ra[i] = rb[i];
        }
        if(ra[sa[n - 1]] == n - 1) break;
    }
}

int binary(int d, int c, string p){
    if(d > c) return 0;
    int tg = (d + c)/2;
    if(a[sa[tg]] == p[0]){
        bool flag = true;
        int x;
        for(int j = 0; j < p.size(); j++){
            if(a[sa[tg] + j] != p[j]){
                flag = false;
                x = j;
                break;
            }
        }
        if(flag) return 1;
        else {
            if(a[sa[tg] + x] > p[x]) return binary(d, tg - 1, p);
            else return binary(tg + 1, c, p);
        }
    }
    if(a[sa[tg]] > p[0]) return binary(d, tg - 1, p);
    else return binary(tg + 1, c, p);
}

void solve(){
    getline(cin, s);
    if(binary(0, n - 1, s)) ans++;
}

int main () {
	NDS
    build();
    string ss;
    getline(cin, ss);
    int t = 0;
    for(int i = 0; i < ss.size(); i++){
        t = t*10 + ss[i] - '0';
    }
    while(t--){
        solve();
    }
    cout << ans << endl;
}
