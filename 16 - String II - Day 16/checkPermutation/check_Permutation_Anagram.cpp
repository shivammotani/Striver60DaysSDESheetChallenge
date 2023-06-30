#include <bits/stdc++.h>
bool areAnagram(string &str1, string &str2)
{
        // Write your code here.
        int arr[256] = {0};
        if (str1.length() != str2.length())
                return false;

        for (int i = 0; i < str1.length(); i++)
        {
                arr[str1[i]]++;
                arr[str2[i]]--;
        }
        for (int i = 0; i < 256; i++)
        {
                if (arr[i] != 0)
                        return false;
        }
        return true;
}