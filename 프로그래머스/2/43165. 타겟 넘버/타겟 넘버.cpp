#include <string>
#include <vector>
#include <stack>

using namespace std;

int results[20000000];
int cnt;

void dfs(int depth, int before, int now, vector<int> number)
{
    if (depth == number.size()-1)
    {
        results[cnt++] = before + now;
        results[cnt++] = before - now;
        return;
    }

    dfs(depth + 1, before + now, number[depth+1], number);
    dfs(depth + 1, before - now, number[depth+1], number);
}

int solution(vector<int> numbers, int target)
{
    cnt = 0;
    for (int i = 0; i < 1000; ++i)
        results[i] = 0;
    int count = 0;

    dfs(1, numbers[0], numbers[1], numbers);
    dfs(1, -numbers[0], numbers[1], numbers);

    for (int i = 0; i < cnt; ++i)
    {
        if (results[i] == target)
            count++;
    }

    return count;
}