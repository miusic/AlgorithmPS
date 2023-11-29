#include <iostream>

using namespace std;

void quickSort(int *arr, int first, int last)
{
	if (first >= last)
		return;

	int pivot = first;
	int i = pivot + 1, j = last;
	int temp = 0;

	while (i <= j)
	{
		while (i <= last && arr[i] <= arr[pivot])
			i++;
		while (j > first && arr[j] >= arr[pivot])
			j--;

		if (i >= j)
		{
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		else
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	quickSort(arr, first, j - 1);
	quickSort(arr, j + 1, last);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	int nums[2001] = { 0, };
	for (register int i = 0; i < n; ++i)
		cin >> nums[i];


	quickSort(nums, 0, n - 1);

	int answer = 0;
	for (register int i = 0; i < n; ++i)
	{
		int target = nums[i];
		int left = 0, right = n - 1;

		while (true)
		{
			if (left == i)
				left++;
			else if (right == i)
				right--;
			else
			{
				if (left >= right)
					break;

				int sum = nums[left] + nums[right];

				if (sum < target)
					left++;
				else if (sum > target)
					right--;
				else
				{
					answer++;
					break;
				}
			}
		}
	}

	cout << answer;

	return 0;
}