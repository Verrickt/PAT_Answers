#include "iostream"
using namespace std;
int main()
{
	int n;
	int cur = 0;
	cin >> n;
	int c;
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		int diff = c - cur;
		if (diff > 0) t += diff * 6;
		else if (diff < 0) t += abs(diff)* 4;
		t += 5;
		cur = c;
	}
	cout<<c<<endl;
	return 0;
}