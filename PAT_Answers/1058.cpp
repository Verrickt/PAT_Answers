#include "cstdio"
int main()
{
	int g1, s1, k1, g2, s2, k2, g3=0, s3 = 0, k3 = 0;
	scanf("%d.%d.%d", &g1, &s1, &k1);
	scanf("%d.%d.%d", &g2, &s2, &k2);
	k3 = k1 + k2;
	s3 += k3 / 29;
	k3 %= 29;
	s3 += (s1 + s2);
	g3 = s3 / 17;
	s3 %= 17;
	g3 += (g1 + g2);
	printf("%d.%d.%d", g3, s3, k3);
	return 0;
}