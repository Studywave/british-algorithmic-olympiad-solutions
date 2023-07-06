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

int XOR(int a, int b)
{
    return a ^ b; // Yes there is official XOR operator
    // Alternatives
    // return (a+b)%2;
    // return (a == 1 && b == 0) || (a == 0 && b == 1); // Remember true casts to 1 and false casts to 0
}

int C(int s0, int s1, int ci)
{
    return XOR(XOR(s0, s1), ci);
}

void performShift(vector<int> &shift, int direction)
{
    if (direction > 0)
    {
        int front = shift[0];
        shift.erase(shift.begin());
        shift.push_back(front);
    }
    else
    {
        int last_digit = shift[shift.size() - 1];
        shift.erase(shift.begin() + shift.size() - 1);
        shift.insert(shift.begin(), last_digit);
    }
}

void performTurn(vector<int> &shift, vector<int> &check, int direction, int i, int r)
{
    for (int x = 0; x < r; x++)
        performShift(shift, direction);
    check[i] = C(shift[0], shift[shift.size() - 1], check[i]);
}

void part_a()
{
    string shift, check;
    ll r;
    int L, direction = 1;
    cin >> shift >> check >> r;
    L = shift.size();
    if (r < 0)
    {
        direction = -1;
        r *= -1;
    }
    r %= L; // CRUCIAL FOR SPEED - no point rotating in many loops if it is only the final position that matters so take modulo

    vector<int> shift_arr(L, 0);
    vector<int> check_arr(L, 0);
    for (int i = 0; i < L; i++)
    {
        shift_arr[i] = shift[i] - '0';
        check_arr[i] = check[i] - '0';
    }

    for (int i = 0; i < L; i++)
        performTurn(shift_arr, check_arr, direction, i, r); // Safe to cast r (which is long long) to an int since it has been taken modulo L so max possible value is (2^6 - 1)

    for (int i = 0; i < L; i++)
        cout << check_arr[i];
    cout << "\n";
}

void part_c()
{
    ll n = (pow(2, 23) * (pow(2, 23) - 1)) / 2; // Better to just simplify (2^(23)) choose 2 instead of creating nCr function to avoid annoying overflow errors
    cout << n << "\n";
}

pair<ll, ll> addFractions(pair<ll, ll> &frac1, pair<ll, ll> &frac2) // Just cross multiply and simplify
{
    ll numerator = (frac1.first * frac2.second) + (frac2.first * frac1.second);
    ll denomiator = frac1.second * frac2.second;
    ll gcd = __gcd(numerator, denomiator);
    return make_pair(numerator / gcd, denomiator / gcd);
}

void part_d() // Personally I would prefer to implement this in python just in case there is an overflow
{
    pair<ll, ll> frac1(1281, 4095);
    pair<ll, ll> frac2(216, 46655);
    pair<ll, ll> frac3(12, 2985983);
    pair<ll, ll> sum1 = addFractions(frac1, frac2);
    pair<ll, ll> sum2 = addFractions(frac3, sum1);
    cout << sum2.second / __gcd(sum2.second, 6ll) << "\n"; // Must check if the final multiplication by L (which is 6) affects the final denominator
}

void solve()
{
    part_a();
    // part_c();
    // part_d();
}
