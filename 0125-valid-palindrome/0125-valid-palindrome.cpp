class Solution {
    bool valid(char ch)
    {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            return 1;
        }
        return 0;
    }
    bool checkPalindrome(string s)
    {
        int start = 0;
        int end = s.size()-1;

        while(start<=end)
        {
            if(s[start]!=s[end])
            {
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        string temp = "";

        for(int i=0; i<s.length(); i++)
        {
            if(valid(s[i]))
            {
                temp.push_back(s[i]);
            }
        }
       std::transform(temp.begin(), temp.end(), 
    temp.begin(), ::tolower); 

         return checkPalindrome(temp);
    }
};