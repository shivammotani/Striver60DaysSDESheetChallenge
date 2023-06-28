string longestPalinSubstring(string str)
{
        // Write your code here.
        string ans = "";
        int ansLen = 0;
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
                // For Odd length
                int l = i, r = i;
                while (l >= 0 && r < n && str[l] == str[r])
                {
                        if ((r - l + 1) > ansLen)
                        {
                                ansLen = r - l + 1;
                                ans = str.substr(l, r - l + 1);
                        }
                        l--;
                        r++;
                }
                // For even length
                l = i, r = i + 1;
                while (l >= 0 && r < n && str[l] == str[r])
                {
                        if ((r - l + 1) > ansLen)
                        {
                                ansLen = r - l + 1;
                                ans = str.substr(l, r - l + 1);
                        }
                        l--;
                        r++;
                }
        }
        return ans;
}