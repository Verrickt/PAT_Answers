#include "string"
#include "vector"
#include "iostream"
using namespace std;
string inverse_and_add(string n)
{
	string result;
	int carry = 0;
	for (int i = 0; i < n.size(); i++)
	{
		int c1 = n[i] - '0';
		int c2 = n[n.size() - i - 1] - '0';
		int c = c1 + c2 + carry;
		result.insert(result.begin(),c % 10 + '0');
		carry = c / 10;
	}
	if (carry != 0) result.insert(result.begin(),carry + '0');
	return result;
}
bool palindromic(string str)
{
	for (int i = 0; i < str.size(); i++)
		if (str[i] != str[str.size() - i - 1]) return false;
	return true;
}
int main()
{
	string n; int k;
	cin >> n >> k;
	int i = 0;
	while (!palindromic(n)&&i<k)
	{
		n = inverse_and_add(n);
		i++;
	}
	cout << n << endl;
	cout << i << endl;
	return 0;
}