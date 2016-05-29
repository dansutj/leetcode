class Solution 
{
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> mp;
        vector<string> res;
        if(s.empty()) return res;

        for(int i = 0, t = 0; i < s.size(); ++i)
        {
            if(mp[t = t << 3 & 0x3FFFFFFF | s[i] & 7]++ == 1)
                res.push_back(s.substr(i - 9, 10));
        }
        return res;
    }
};