/*
价值为k(1 ≤ k ≤ 1000)的中杯拿铁，
而手上只有一个价值为r(1 ≤ r ≤ 9)的硬币和若干个价值为10的硬币。


如何在不找零的情况下买最少杯中杯拿铁。


Input

单组输入。 一行输入两个整数k和r(1 ≤ k ≤ 1000, 1 ≤ r ≤ 9)，中杯拿铁的价格和r的价值。
有无限个价值为10的硬币，因此，有足够的钱去买无限多的中杯拿铁。

Output

输出在不找零的情况下炸酱面能买的最少中杯拿铁个数。

Sample Input1
117 3
Sample Output1
9

Sample Input2
237 7
Sample Output2
1
*/

//printf("%d %d \n",k,r);

int main_csdn(int argc, char *argv[])
{
	int k = 0, r = 0;
	int i = 1, temp;

	scanf_s("%d %d", &k, &r);
	
	while ((temp = k*i % 10) != r)
	{
		if (temp % 10 == 0) break;
		i++;	
	}
	printf("i = %d \n",i);
}