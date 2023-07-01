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

int nCr(int n, int r) // Recursive approach using Pascal's identity avoids overflow error
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

bool validCoordinate(int x, int y, int p) // Make sure within bounds of the grid
{
    return !(x < 0 || y < 0 || x > p || y > p);
}

void part_a()
{
    int p, center_x, center_y;
    cin >> p >> center_x >> center_y;

    int grid[p + 1][p + 1];
    memset(grid, 0, sizeof(grid));
    bool visited[p + 1][p + 1];
    memset(visited, false, sizeof(visited));

    grid[center_y][center_x] = 3; // 3 = no depth charge, 2 = origin, 1 = depth charge, 0 = unkown
    visited[center_y][center_x] = true;
    queue<pair<int, int>> queue;
    queue.push(make_pair(center_x, center_y)); // Using queue is wayyyyyy faster than vector
    int depth_charges = 0;

    // BFS
    while (queue.size())
    {
        int x = queue.front().first;
        int y = queue.front().second;
        if (grid[y][x] == 0)
        {
            grid[y][x] = 1;
            depth_charges += 1;
        }
        queue.pop();

        // Ignore all points on the same gradient
        int dy = y - center_y;
        int dx = x - center_x;
        int i = 2;
        while ((dy != 0 || dx != 0) && validCoordinate(center_x + (dx * i), center_y + (dy * i), p) && grid[center_y + (dy * i)][center_x + (dx * i)] != 3) // Make sure there is at least some change (dy or dx) to prevent infinite loop (only occurs for the origin position) and if the gradient line has already been ignored then no need to ignore it again
        {
            grid[center_y + (dy * i)][center_x + (dx * i)] = 3; // Don't mark as visited but instead say there is defo no charge here cus there might be charges around this spot that need to get placed (originally I marked as visited which caused undercounting)
            i += 1;
        }

        if (validCoordinate(x, y + 1, p) and !visited[y + 1][x]) // Up
        {
            queue.push(make_pair(x, y + 1));
            visited[y + 1][x] = true;
        }

        if (validCoordinate(x + 1, y, p) and !visited[y][x + 1]) // Right
        {
            queue.push(make_pair(x + 1, y));
            visited[y][x + 1] = true;
        }

        if (validCoordinate(x, y - 1, p) and !visited[y - 1][x]) // Down
        {
            queue.push(make_pair(x, y - 1));
            visited[y - 1][x] = true;
        }

        if (validCoordinate(x - 1, y, p) and !visited[y][x - 1]) // Left
        {
            queue.push(make_pair(x - 1, y));
            visited[y][x - 1] = true;
        }
    }

    cout << depth_charges << "\n";

    /////////////////////////////////////////////////////
    /////////////////////////////////////////////////////

    // // Part c

    // int boundary_charges[4] = {0}; // {top, right, bottom, left}
    // for (int i = 0; i < p + 1; i++)
    // {
    //     if (grid[p][i] == 1) // Top
    //         boundary_charges[0] += 1;
    //     if (grid[i][p] == 1) // Right
    //         boundary_charges[1] += 1;
    //     if (grid[0][i] == 1) // Bottom
    //         boundary_charges[2] += 1;
    //     if (grid[i][0] == 1) // Left
    //         boundary_charges[3] += 1;
    // }

    // int nautical_triangles = 0;
    // for (const int i : boundary_charges)
    //     nautical_triangles += nCr(i, 2);

    // cout << nautical_triangles + 1 << "\n"; // Must add 1 because of extra right-angle triangle in bottom left corner (sneaky)
}

void solve()
{
    part_a();
}
