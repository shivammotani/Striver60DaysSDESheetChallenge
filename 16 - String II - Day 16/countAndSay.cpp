#include <bits/stdc++.h>
string writeAsYouSpeak(int n)
{
	// Write your code here.
	string ans = "1";
	if (n == 1)
		return ans;
	n--;
	while (n--)
	{
		string temp = "";
		for (int i = 0; i < ans.size();)
		{
			int j = i;
			int cnt = 0;
			while (j < ans.size() && ans[j] == ans[i])
			{
				cnt++;
				j++;
			}

			temp += to_string(cnt) + ans[i];
			i = j;
		}
		ans = temp;
	}

	return ans;
}