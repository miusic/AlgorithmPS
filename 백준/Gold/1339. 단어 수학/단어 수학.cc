#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

#define PCI pair<char, int>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int powTen[8] = { 1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000 };
	int n = 0;
	cin >> n;

	string str[10];
	map<char, int> ranking;
	for (register int i = 0; i < n; ++i)
	{
		cin >> str[i];

		int len = str[i].length();
		for (register int j = 0; j < len; ++j)
		{
			int score = powTen[len - j - 1];
			if(ranking.find(str[i][j]) == ranking.end())
				ranking[str[i][j]] = score;
			else
				ranking[str[i][j]] += score;
		}
	}

	vector< pair<char, int> > vec(ranking.begin(), ranking.end());
	sort(vec.begin(), vec.end(),
		[](PCI a, PCI b)
		{
			return a.second > b.second;
		});

	int answer = 0;
	int num = 9;
	for (auto iter = vec.begin(); iter != vec.end(); ++iter)
	{
		char alphabet = (*iter).first;
		for (register int i = 0; i < n; ++i)
		{
			int len = str[i].length();
			for (register int j = 0; j < len; ++j)
			{
				int score = powTen[len - j - 1] * num;
				if (str[i][j] == alphabet)
					answer += score;
			}
		}
		--num;
	}

	cout << answer;

	return 0;
}