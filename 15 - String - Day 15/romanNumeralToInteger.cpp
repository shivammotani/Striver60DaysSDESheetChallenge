#include <bits/stdc++.h>
int romanToInt(string s)
{
        // Write your code here
        int ans = 0;
        unordered_map<string, int> mp = {{"I", 1},
                                         {"V", 5},
                                         {"X", 10},
                                         {"L", 50},
                                         {"C", 100},
                                         {"D", 500},
                                         {"M", 1000},
                                         {"IV", 4},
                                         {"IX", 9},
                                         {"XL", 40},
                                         {"XC", 90},
                                         {"CD", 400},
                                         {"CM", 900}};

        for (int i = 0; i < s.length(); i++)
        {
                if (i != s.length() - 1)
                {
                        string x = "";
                        x = x + s[i] + s[i + 1];
                        auto it = mp.find(x);
                        if (it != mp.end())
                        {
                                ans += it->second;
                                i++;
                                continue;
                        }
                }
                string x = "";
                x = s[i];
                auto it = mp.find(x);
                if (it != mp.end())
                        ans += it->second;
        }
        return ans;
}
