class Solution {
public:
    bool isAdditiveNumber(string num) 
    {
        for(int i = 0; i <= num.length() / 2; ++i)
        {
        	string num1 = num.substr(0, i);
        	if(i > 1 && num1[0] == '0') break;

        	for(int j = i; j <= (num.length() - i) / 2; ++j)
        	{
        		string num2 = num.substr(i, j);
        		if(j > 1 && num2[0] == '0') break;

        		if(dfs(num1, num2, num.substr(i + j)))
        			return true;
        	}
        }
        return false;
    }

    bool dfs(const string& num1, const string& num2, const string& num)
    {
    	string sum = addTwoNumber(num1, num2);
    	if(sum == num) return true;

    	if(sum.length() >= num.length() || sum != num.substr(0, sum.length()))
    		return false;

    	return dfs(num2, sum, num.substr(sum.length()));
    }

    string addTwoNumber(const string& num1, const string& num2)
    {
    	if(num1.empty() && num2.empty())
    		return "";

    	int i = num1.length() - 1;
    	int j = num2.length() - 1;
    	int sum = 0;
    	string res;

    	while(i >= 0 || j >= 0)
    	{
    		sum += (i >= 0 ? num1[i] - '0' : 0);
    		sum += (j >= 0 ? num2[j] - '0' : 0);

    		res += to_string(sum % 10);
    		sum /= 10;
    	}
    	if(sum) res += to_string(sum);
    	reverse(res.begin(),res.end());
    	return res;
   }
};