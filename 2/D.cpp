#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;i++)
#define fid(i,a,b) for(int i=a;i>=b;i--)
#define getbit(x,i) ((x>>i)&1)
#define pii pair<int,int>
#define ll long long
#define maxn 100005
using namespace std;
int n, m, d[maxn], p[maxn][15], q[maxn][15];
vector<int> xd;
struct dt{int h; ll sum;} a[maxn * 10];
int cnt, bit[maxn * 10];
void update(int u, ll w)
{
    while(u < maxn * 10)
    {
        bit[u] += w;
        u  += u&-u;
    }
}
int get(int u)
{
    int sum = 0;
    while(u)
    {
        sum += bit[u];
        u -= u&-u;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
//    freopen(Hoanghoang".inp", "r", stdin);
//    freopen(Hoanghoang".out", "w", stdout);
    #endif // ONLINE_JUDGE
    cin >> n;
    fi(i, 1, n)
    {
        cin >> d[i];
        int high = 0;
        fi(j, 1, d[i])
        {
            cin >> p[i][j] >> q[i][j];
            high += p[i][j];
            xd.push_back(high);
        }
    }
    sort(xd.begin(), xd.end());
    fi(i, 0, xd.size() - 1)
    if(i == 0 || xd[i] != xd[i - 1])
        a[++cnt] = {xd[i], 0};
    fi(i, 1, n)
    {
        int high = 0;
        a[1].sum += q[i][1];
        fi(j, 1, d[i])
        {
            high += p[i][j];
            int l = 1, r = cnt;
            while(l <= r)
            {
                int mid = (l + r) / 2;
                if(a[mid].h <= high) l = mid + 1; else r = mid - 1;
            }
            a[l].sum += q[i][j + 1] - q[i][j];
        }
    }
    fi(i, 1, cnt) a[i].sum += a[i - 1].sum;
    fi(i, 1, cnt) update(i, a[i].h - a[i - 1].h);
    int tg = a[cnt].h + 1;
    cin >> m;
    while(m--)
    {
        tg--;
        int x;
        cin >> x;
        if(x > tg)
        {
            tg++;
            cout << 0 << '\n';
            continue;
        }
        int res = 0;
        fid(i, 19, 0)
        {
            res += (1 << i);
            if(res < maxn * 10 && bit[res] < x) x -= bit[res];
            else res -= (1 << i);
        }
        res++;
        update(res, -1);
        cout << a[res].sum << '\n';
    }
}  
