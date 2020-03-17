#include "vector"
#include "iostream"
#include "map"
using namespace std;
#define max 1000000
bool prime[max];
int main()
{
	map<long, int> factor;
	fill(prime, prime + max, true);
	for (long long i = 2; i < max; i++)
	{
		for (long long j = 2; i * j < max; j++)
		{
			prime[i * j] = false;
		}
	}
	long n;
	cin >> n;
	int k = n;
	while (k != 1)
	{
		for (int i = 2; i <= k; i++)
			if (prime[i] && k % i == 0)
			{
				k /= i;
				factor[i]++;
				break;
			}
	}
	cout << n << "=";
	if (n == 1) cout << "1";
	int i = 0;
	for (auto it : factor)
	{
		i++;
		cout << it.first;
		if (it.second != 1) cout << "^" << it.second;
		if (i != factor.size())	cout << "*";
	}
	return 0;
}