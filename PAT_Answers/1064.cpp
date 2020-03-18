#include "iostream"
#include "algorithm"
using namespace std;
int tree[1024], level[1024], n,k=1;
void in(int root)
{
	if (root <= n)
	{
		in(root * 2);
		level[root] = tree[k++];
		in(root * 2 + 1);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> tree[i];
	sort(tree, tree+n+1);
	in(1);
	for (int i = 1; i <= n; i++)
	{
		cout << level[i];
		if (i != n) cout << " ";
	}
	return 0;
}