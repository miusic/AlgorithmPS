#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int eq2int(string str)
{
	istringstream eq(str);
	string strBuff;
	vector<string> vec;
	while (getline(eq, strBuff, '+'))
		vec.push_back(strBuff);

	int ret = 0;
	for (auto num : vec)
		ret += stoi(num);

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string equation;
	cin >> equation;

	istringstream sEquation(equation);
	string substr;
	vector<string> vec;
	while (getline(sEquation, substr, '-'))
		vec.push_back(substr);

	int answer = 0;
	for (register int i = 0; i < vec.size(); ++i)
	{
		int partial = eq2int(vec[i]);
		if (i == 0)
		{
			if (equation[0] != '-')
				answer += partial;
			continue;
		}
		answer -= partial;
	}

	cout << answer;

	return 0;
}