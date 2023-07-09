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

int calcOrders(vector<int> &dest_indexes, int i, int prev_used_index, int pack_size, int &max_pack_size)
{
    if (i == dest_indexes.size())
    {
        if (pack_size > max_pack_size)
            max_pack_size = pack_size;
        return 1;
    }

    int total_pack_orders = 0;

    if (dest_indexes[i] > prev_used_index)
        total_pack_orders = calcOrders(dest_indexes, i + 1, dest_indexes[i], pack_size + 1, max_pack_size);

    total_pack_orders += calcOrders(dest_indexes, i + 1, prev_used_index, pack_size, max_pack_size);
    return total_pack_orders;
}

void part_a()
{
    string endpoints;
    cin >> endpoints;
    int max_pack_size = 0;
    vector<int> dest_indexes(endpoints.size(), 0);
    for (int i = 0; i < endpoints.size(); i++)
        dest_indexes[i] = endpoints[i] - '0';

    int total_pack_orders = calcOrders(dest_indexes, 0, -1, 0, max_pack_size) - 1; // Must -1 from first number to avoid case where there are no wolves (since there must be at at least 1 wolve in a pack order)
    cout << total_pack_orders << " " << max_pack_size << "\n";
}

void part_b()
{
    string endpoints = "abcdefgh";
    vector<int> dest_indexes(endpoints.size(), 0);
    int max_pack_size = 0;
    for (int i = 0; i < endpoints.size(); i++)
        dest_indexes[i] = endpoints[i] - '0';
    ll total = 0;
    int perms = 0;

    do
    {
        calcOrders(dest_indexes, 0, -1, 0, max_pack_size);
        total += max_pack_size;
        perms++;
        max_pack_size = 0; // Must reset to find max of next permutation
    } while (next_permutation(dest_indexes.begin(), dest_indexes.end()));

    cout << double(total) / perms << "\n";
}

void solve()
{
    part_a();
    // part_b();
}
