/*
 * https://www.acwing.com/problem/content/833/
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

const int N = 100010;
const int M = 1000010;
char p[N], s[M];
int n, m;
void Solution()
{
	cin >> n >> p + 1 >> m >> s + 1;

	// p的 next数组，next[i]=j时，表示p[1~j]=p[(i-j)~i]
	int next[N] = {};

	// 求p的next数组
	for (int i = 2, j = 0; i <= n; i++)
	{
		while (j && p[j + 1] != p[i])
			j = next[j];
		if (p[i] == p[j + 1])
			j++;
		next[i] = j;
	}

	// kmp匹配
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j && p[j + 1] != s[i])
			j = next[j];
		if (p[j + 1] == s[i])
			j++;
		if (j == n)
		{
			cout << (i - n + 1) - 1 << ' ';
		}
	}
}
int main()
{
	Solution();
	return 0;
}