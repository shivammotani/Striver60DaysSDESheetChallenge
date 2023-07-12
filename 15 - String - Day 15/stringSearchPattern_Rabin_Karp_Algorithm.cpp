vector<int> stringMatch(string text, string pattern)
{
        // Write your code here.
        vector<int> ans;
        int n = text.length();
        int m = pattern.length();
        int patternHash = 0;
        int textHash = 0;
        int base = 256;
        int prime = INT_MAX;
        int basetoRemovewhileSliding = 1;
        for (int i = 0; i < m - 1; i++)
                basetoRemovewhileSliding *= base;

        for (int i = 0; i < m; i++)
        {
                patternHash = (base * patternHash + pattern[i] - 'a' + 1) % prime;
                textHash = (base * textHash + text[i] - 'a' + 1) % prime;
        }
        for (int i = 0; i <= n - m; i++)
        {
                if (patternHash == textHash)
                {
                        int j = 0;
                        for (; j < m; j++)
                        {
                                if (text[i + j] != pattern[j])
                                        break;
                        }
                        if (j == m)
                                ans.push_back(i + 1);
                }
                if (i < n - m)
                {
                        textHash = (base * (textHash - (text[i] - 'a' + 1) * basetoRemovewhileSliding) + (text[i + m] - 'a' + 1)) % prime;
                        if (textHash < 0)
                                textHash += prime;
                }
        }
        return ans;
}
