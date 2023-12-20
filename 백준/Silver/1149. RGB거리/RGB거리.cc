#include <iostream>
#define INF 987654321

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int color[1001][3];

	cin >> n;
	int red = 0, green = 0, blue = 0;
	for (register int i = 0; i < n; ++i)
		cin >> color[i][0] >> color[i][1] >> color[i][2];

	int dp[1001][3];
	for (register int i = 0; i < 1001; ++i)
	{
		dp[i][0] = INF;
		dp[i][1] = INF;
		dp[i][2] = INF;
	}
	dp[0][0] = color[0][0];
	dp[0][1] = color[0][1];
	dp[0][2] = color[0][2];

	for (register int i = 1; i < n; ++i)
	{
		dp[i][0] = dp[i - 1][1] + color[i][0] < dp[i - 1][2] + color[i][0] ? dp[i - 1][1] + color[i][0] : dp[i - 1][2] + color[i][0];
		dp[i][1] = dp[i - 1][0] + color[i][1] < dp[i - 1][2] + color[i][1] ? dp[i - 1][0] + color[i][1] : dp[i - 1][2] + color[i][1];
		dp[i][2] = dp[i - 1][0] + color[i][2] < dp[i - 1][1] + color[i][2] ? dp[i - 1][0] + color[i][2] : dp[i - 1][1] + color[i][2];
	}

	int ans = INF;
	for (register int i = 0; i < 3; ++i)
	{
		if (dp[n - 1][i] < ans)
			ans = dp[n - 1][i];
	}

	cout << ans;

	return 0;
}