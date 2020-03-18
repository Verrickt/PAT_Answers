#include "iostream"
#include "string"
using namespace std;
int main()
{
	long long t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		long long s = a + b;
		string res;
		if (a > 0 && b > 0 && s < 0) res = "true";
		//LLONG_MIN+LLONG_MIN==0
		else if (a < 0 && b < 0 && s >= 0) res = "false";
		else res = s > c ? "true" : "false";
		cout << "Case #" << i << ": " << res << endl;
	}
	return 0;
}