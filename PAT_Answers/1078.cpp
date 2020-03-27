#include "cstdio"
#include "vector"
#include "algorithm"
using namespace std;
const int max_prime = 15000;
bool is_prime[max_prime];
int msize, n;
vector<bool> table;
int main()
{
	fill(is_prime, is_prime + max_prime, true);
	for (int i = 2; i < max_prime; i++)
	{
		for (int j = 2; i * j < max_prime; j++)
			is_prime[i * j] = false;
	}
	is_prime[1] = false;
	scanf("%d %d", &msize, &n);
	for (int i = msize; i < max_prime; i++)
		if (is_prime[i]) { msize = i; break; }
	table = vector<bool>(msize);
	for (int i = 0; i < n; i++)
	{
		int p;
		scanf("%d", &p);
		int pos = -1;
		for (int delta = 0; delta <=msize/2; delta++)
		{
			pos = ((p) + delta*delta) % msize;
			if (!table[pos]) {  break; }
		}
		if (table[pos]) printf("-");
		else printf("%d", pos);
		if (i + 1 != n) printf(" ");
		table[pos] = true;
	}
	return 0;
}