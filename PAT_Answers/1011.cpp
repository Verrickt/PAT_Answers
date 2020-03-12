#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
int main()
{
	vector<vector<double>> v = vector<vector<double>>(3);
	for (int i = 0; i < 3; i++)
	{
		v[i].resize(3);
		for (int j = 0; j < 3; j++)
		{
			scanf("%lf", &v[i][j]);
		}
	}
	vector<double> bets;
	char bet[3] = { 'W','T','L' };
	for (int i = 0; i < 3; i++)
	{
		double max = v[i][0];
		int index = 0;
		for (int j = 1; j < 3; j++)
		{
			if (max < v[i][j])
			{
				max = v[i][j];
				index = j;
			}
		}
		bets.push_back(max);
		printf("%c ", bet[index]);
	}
	double result = 1;
	for (int i = 0; i < 3; i++) result *= bets[i];
	result= (result * 0.65 - 1) * 2;
	printf("%.2lf",result);
	return 0;
}