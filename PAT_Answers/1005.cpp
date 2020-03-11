#include "string"
#include "map"
#include "iostream"
using namespace std;
int main()
{
	string s;
	cin >> s;
	string str[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	int sum = 0;
	for (auto i = s.begin(); i != s.end(); i++)
	{
		sum += (*i)-'0';
	}
	string res = to_string(sum);
	for (auto it = res.begin(); it != res.end(); it++)
	{
		cout << str[*it - '0'];
		if (it + 1 != res.end()) printf(" ");
	}
	return 0;
}