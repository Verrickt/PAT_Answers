#include "iostream"
#include "string"
#include "algorithm"
#include "cstdio"
using namespace std;
bool cmp1(char& a, char& b) { return a < b; }
bool cmp2(char& a, char& b) { return a > b; }
int main()
{
	string s1;
	cin >> s1;
	string source = s1;
	while (true)
	{
		while (source.length() != 4) source.insert(source.begin(), '0');
		string max = source;
		string min = source;
		sort(max.begin(), max.end(), cmp2);
		sort(min.begin(), min.end(), cmp1);
		int ma = stoi(max), mi = stoi(min);
		int diff=ma-mi;
		printf("%04d - %04d = %04d\n", ma, mi, diff);
		if (diff == 0 || diff == 6174)
		{
			break;
		}
		source = to_string(diff);
	}
	return 0;
}