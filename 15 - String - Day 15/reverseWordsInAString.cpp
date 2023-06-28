string reverseString(string &str)
{

        // Write your code here.
        vector<string> vec;
        string ans = "";
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
                string temp = "";
                while (i < n && !isspace(str[i]))
                {
                        temp.push_back(str[i++]);
                }
                if (!temp.empty())
                {
                        vec.push_back(temp);
                }
        }

        for (int i = vec.size() - 1; i >= 0; i--)
        {
                ans.append(vec[i]);
                if (i > 0)
                        ans.append(" ");
        }

        return ans;
}