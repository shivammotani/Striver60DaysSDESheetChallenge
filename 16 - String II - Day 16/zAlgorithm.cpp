int zAlgorithm(string s, string p, int n, int m)
{
        // Write your code here
        int ans = 0;
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
                if (s[i] == p[j])
                {
                        j++;
                        i++;
                }
                if (j == p.size())
                {
                        ans++;
                        j = 0;
                        if (p.size() != 1)
                                i--;
                }
                else if (s[i] != p[j])
                {
                        if (j != 0)
                                j = lps[j - 1];
                        else
                                i++;
                }
        }
        return ans;
}