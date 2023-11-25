#include <string>
#include <vector>

using namespace std;

int target_num;
int count = 0;

void dfs(int depth, int before, int now, vector<int> number)
{
    if (depth == number.size()-1)
    {
        if((before + now) == target_num)
            count++;
        if((before - now) == target_num)
            count++;
        return;
    }

    dfs(depth + 1, before + now, number[depth+1], number);
    dfs(depth + 1, before - now, number[depth+1], number);
}

int solution(vector<int> numbers, int target)
{
    target_num = target;

    dfs(1, numbers[0], numbers[1], numbers);
    dfs(1, -numbers[0], numbers[1], numbers);

    return count;
}