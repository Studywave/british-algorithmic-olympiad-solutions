#include <bits/stdc++.h>
#include <math.h>
using namespace std;

/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // WARNING: Must create the files yourself
    // Adjust the path depending on where the input/output files are
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    clock_t start, end;
    start = clock();

    solve();

    end = clock();

    cout << "\ntime taken : " << (float)(end - start) / CLOCKS_PER_SEC << " secs";

    return 0;
}

/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////

void part_c() // Baisically just a variant of Gauss' circle problem
{
    ll n;
    cin >> n;
    ll upper_bound = ceil(sqrtl(n)) - 1;
    ll lattice_points = 1 + 2 * upper_bound;
    for (ll i = 1; i < upper_bound + 1; i++)
        lattice_points += sqrtl((n - 1) - powl(i, 2));

    cout << lattice_points << "\n";
}

void solve()
{
    part_c();
}
