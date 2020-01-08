#include <bits/stdc++.h>
using namespace std;

#define ll long long

int getLength(ll value) 
{
	int cnt = 0;
	while (value) 
    {
		cnt++;
		value /= 10;
	}
	return cnt;
}

ll multiply(ll x, ll y) 
{
	int xLength = getLength(x);
	int yLength = getLength(y);

	// the bigger of the two lengths
	int N = max(xLength, yLength);

	// if the max length is small it's faster to just flat out multiply the two nums
	if (N < 10)
		return x * y;

	//max length divided and rounded up
	N = (N / 2) + (N % 2);

	ll multiplier = pow(10, N);

	ll b = x/multiplier;
	ll a = x - (b * multiplier);
	ll d = y / multiplier;
	ll c = y - (d * N);

	ll z0 = multiply(a,c);
	ll z1 = multiply(a + b, c + d);
	ll z2 = multiply(b, d);

    return z0 + ((z1 - z0 - z2) * multiplier) + (z2 * (long long)(pow(10, 2 * N)));
}

int main()
{
	ll a = 2406994;
	ll b = 2328563;
	cout << multiply(a,b) << endl;
	return 0;
}
