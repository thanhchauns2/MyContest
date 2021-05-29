#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const int maxlg = 19;
const int maxd = 105;
int a[maxn];
int ld[maxn], rd[maxn];
int min_ld[maxlg][maxn], min_rd[maxlg][maxn];
int fl[maxn][maxd], fr[maxn][maxd];
int posl[maxn][maxd], posr[maxn][maxd];
bool okl[maxn][maxd], okr[maxn][maxd];
bool ddl[maxn][maxd], ddr[maxn][maxd];
int n, m;

void calc_delta()
{
    a[0] = 1e9;
    a[n + 1] = 1e9;

    for (int i = n; i >= 1; i--)
        ld[i] = ld[i + 1] + a[i] - a[i - 1] - 1;

    for (int i = 1; i <= n; i++)
    {
        min_ld[0][i] = ld[i];
        for (int j = 1; i - (1 << j) >= 0; j++)
            min_ld[j][i] = min(min_ld[j - 1][i], min_ld[j - 1][i - (1 << (j - 1))]);
    }

    for (int i = 1; i <= n; i++)
        rd[i] = rd[i - 1] + a[i] - a[i + 1] - 1;

    for (int i = n; i >= 1; i--)
    {
        min_rd[0][i] = rd[i];
        for (int j = 1; i + (1 << j) <= n + 1; j++)
            min_rd[j][i] = min(min_rd[j - 1][i], min_rd[j - 1][i + (1 << (j - 1))]);
    }
}

void calc_posl()
{
    for (int i = 1; i <= n; i++)
    {
        int p = i;
        int v = 1;

        for (int lg = maxlg; lg >= 0; lg--)
            if (p - (1 << lg) > 0){
                if (min_ld[lg][p] - ld[i + 1] + v > 0)
                    p = p - (1 << lg);
            }

        v = ld[p + 1] - ld[i + 1] + 1;
        posl[i][1] = p - 1;

        for (int j = 2; j <= 100; j++){
            v++;
            if (v + a[p] - a[p - 1] >= 2){
                p = posl[p - 1][1] + 1;
                v = ld[p + 1] - ld[i + 1] + j;
            }
            posl[i][j] = p - 1;
        }

    }
}

void calc_posr()
{
    for (int i = n; i >= 1; i--)
    {
        int p = i;
        int v = 1;

        for (int lg = maxlg; lg >= 0; lg--)
            if (p + (1 << lg) <= n){
                if (min_rd[lg][p] - rd[i - 1] + v > 0)
                    p = p + (1 << lg);
            }

        v = rd[p - 1] - rd[i - 1] + 1;
        posr[i][1] = p + 1;

        for (int j = 2; j <= 100; j++){
            v++;
            if (v + a[p] - a[p + 1] >= 2){
                p = posr[p + 1][1] - 1;
                v = rd[p - 1] - rd[i - 1] + j;
            }
            posr[i][j] = p + 1;
        }
    }
}

int calc_r(int, int);

int calc_l(int i, int j)
{
    if (okl[i][j]) return fl[i][j];
    okl[i][j] = true;

    int p = posl[i][j] + 1;
    int v = ld[p + 1] - ld[i + 1] + j;

    if (p == 1 || abs(v + a[p] - a[p - 1]) <= 1)
        fl[i][j] = p - 1;
    else{
        v = abs(v + a[p] - a[p - 1]) - 1;
        p--;
        if (!okr[p][v] || (okr[p][v] && ddr[p][v]))
            fl[i][j] = calc_r(p, v);
        else
            fl[i][j] = -1;
    }
    ddl[i][j] = true;
    return fl[i][j];
}

int calc_r(int i, int j)
{
    if (okr[i][j]) return fr[i][j];
    okr[i][j] = true;

    int p = posr[i][j] - 1;
    int v = rd[p - 1] - rd[i - 1] + j;

    if (p == n || abs(v + a[p] - a[p + 1]) <= 1)
        fr[i][j] = p + 1;
    else{
        v = abs(v + a[p] - a[p + 1]) - 1;
        p++;
        if (!okl[p][v] || (okl[p][v] && ddl[p][v]))
            fr[i][j] = calc_l(p, v);
        else
            fr[i][j] = -1;
    }

    ddr[i][j] = true;

    return fr[i][j];
}

int solve_r(int v, int c)
{
    int p = c;
    v -= rd[c - 1];
    for (int lg = maxlg; lg >= 0; lg--)
        if (p + (1 << lg) <= n){
            if (min_rd[lg][p] + v > 0)
                p = p + (1 << lg);
        }

    v = rd[p - 1] + v;

    if (p == n || abs(v + a[p] - a[p + 1]) <= 1)
        return p + 1;
    else return fl[p + 1][abs(v + a[p] - a[p + 1]) - 1];
}

int solve_l(int v, int c)
{
    int p = c;
    v -= ld[c + 1];
    for (int lg = maxlg; lg >= 0; --lg)
        if (p - (1 << lg) > 0){
            if (min_ld[lg][p] + v > 0)
                p = p - (1 << lg);
        }

    v = ld[p + 1] + v;

    if (p == 1 || abs(v + a[p] - a[p - 1]) <= 1)
        return p - 1;
    else return fr[p - 1][abs(v + a[p] - a[p - 1]) - 1];
}

int solve(int v, int c){
    if (v == 0) return c;
    if (v > 0) return solve_r(v, c);
    return solve_l(-v, c);
}

int main()
{
    ios::sync_with_stdio(false), cin.tie();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    calc_delta();
    calc_posl();
    calc_posr();


    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 100; j++){
        calc_l(i, j);
        calc_r(i, j);
    }

    int v, c;
    for (int i = 0; i < m; i++){
        cin >> c >> v;
        cout << solve(v, c) << endl;
    }

    return 0;
}
