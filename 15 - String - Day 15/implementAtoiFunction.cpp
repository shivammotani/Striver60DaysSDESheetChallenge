#include <bits/stdc++.h>
int atoi(string s)
{
        // Write your code here.
        bool negative = false;
        int digit = 0;

        for (int i = 0; i < s.size(); i++)
        {
                int rem = (int)s[i] - 48;
                if (rem == -3)
                {
                        negative = true;
                }
                else if (rem >= 0 && rem <= 9)
                {
                        digit = digit * 10 + rem;
                }
                else
                        continue;
        }

        if (negative)
                digit = -1 * digit;
        return digit;
}