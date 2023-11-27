#include <iostream>
#include <queue>
#define PII pair<int, int>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, D = 0;
	int arr[10001] = { 0, };
	vector<PII> shortcut[10001];

	cin >> N >> D;

	for (register int i = 0; i <= D; ++i)
		arr[i] = i;

	for (register int i = 0; i < N; ++i)
	{
		int start = 0, end = 0, dist = 0;
		cin >> start >> end >> dist;
		
		if (end > D)
			continue;
		if (end - start <= dist)
			continue;

		shortcut[start].push_back(make_pair(end, dist));
	}
	
	for(register int i = 0; i<=D; ++i)
	{
		if (i == 0)
			arr[i] = 0;
		else
			arr[i] = (arr[i] <= arr[i - 1] + 1) ? arr[i] : (arr[i - 1] + 1);
	
		if (shortcut[i].empty())
			continue;

		for (auto cut = shortcut[i].begin(); cut != shortcut[i].end(); cut++)
		{
			int end = (*cut).first;
			int dist = (*cut).second;

			if (arr[end] > arr[i] + dist)
				arr[end] = arr[i] + dist;
		}
	}

	cout << arr[D];

	return 0;
}