#include "iostream"
#include "string"
#include "vector"
#include "cctype"
#include "algorithm"
using namespace std;
long long to_num(string s, long long radex)
{
	long long  result = 0;
	for (auto it = s.begin(); it != s.end(); it++)
	{
		result *= radex;
		long long c;
		if (isdigit(*it)) c = *it - '0';
		else c = *it - 'a' + 10;
		result += c;
	}
	return result;
}
int main()
{
	string n1, n2;
	long long tag, radex;
	cin >> n1 >> n2 >> tag >> radex;
	long long num;
	if (tag == 2)
	{
		swap(n1, n2);
	}
	num = to_num(n1, radex);
	char it = *max_element(n2.begin(), n2.end());
	long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
	long long high = max(num,low);
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long temp = to_num(n2, mid);
		if (temp > num || temp < 0) high = mid - 1;
		else if (temp < num) low = mid + 1;
		else {
			printf("%lld", mid);
			return 0;
		}
	}
	printf("Impossible\n");
	return 0;
}