#include <iostream>
#include <set>

using namespace std;

long long power[50002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (long long i = 1; i < 50002; ++i)
		power[i] = i * i;

	long long G = 0;
	cin >> G;

	set<int> answers;
	for (register int i = 1; i < 50002; ++i)
	{
		if (power[i] <= G)
			continue;

		int start = 1, end = i, now = 0;
		while (start <= end)
		{
			now = (start + end) / 2;

			long long diff = power[i] - power[now];

			if (diff == G)
			{
				answers.insert(i);
				break;
			}
			else
			{
				if (diff > G)
					start = now + 1;
				else
					end = now - 1;
			}
		}
	}

	if (answers.empty())
		cout << -1;
	else
	{
		for (auto iter : answers)
			cout << iter << '\n';
	}

	return 0;
}