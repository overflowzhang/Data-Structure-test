#include <iostream>

using namespace std;

int main()
{
	int T;
		cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int i = 1;
		int num = 0;
		int sum = 0;
		while (n--)
		{
			num = num * 10 + i;
			sum += num;
			i++;
		}
		cout << sum << endl;
	}
	return 0;
}
