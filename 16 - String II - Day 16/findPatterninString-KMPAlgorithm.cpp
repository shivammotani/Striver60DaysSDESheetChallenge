#include <bits/stdc++.h>
bool findPattern(string p, string s)
{
        // Write your code here.
        vector<int> lps(p.size(), 0);
        int i = 0, j = 1;

        while (j < p.size())
        {
                if (p[i] == p[j])
                        lps[j++] = ++i;
                else if (i != 0)
                        i = lps[i - 1];
                else
                        j++;
        }
        for (int i = 0, j = 0; i < s.size();)
        {
                // cout << i << " " << j << " " << s[i] << " " << p[j] << " " << p.size() << endl;
                if (s[i] == p[j])
                {
                        j++;
                        i++;
                }
                if (j == p.size())
                        return true;
                else if (s[i] != p[j])
                {
                        if (j != 0)
                                j = lps[j - 1];
                        else
                                i++;
                }
        }
        return false;
}