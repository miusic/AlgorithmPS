#include <iostream>

using namespace std;

int cnt = 0;

void dfs(int depth, int end, int target, int sum, int arr[], bool zero)
{
	if (depth == end)
	{
		if (zero)
			return;
		if (sum == target)
			cnt++;
		return;
	}

	dfs(depth + 1, end, target, sum, arr, (zero && true));
	dfs(depth + 1, end, target, sum + arr[depth], arr, (zero && false));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, S = 0;
	int arr[21] = { 0, };

	cin >> N >> S;
	for (register int i = 0; i < N; ++i)
		cin >> arr[i];

	dfs(1, N, S, 0, arr, true);
	dfs(1, N, S, arr[0], arr, false);

	cout << cnt;

	return 0;
}