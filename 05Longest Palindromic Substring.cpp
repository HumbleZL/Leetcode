#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
class Solution {
public:
     string longestPalindrome(string s) {
    	int len = s.length();
        if(len == 0) return "";
    	int max_len = 0, start,end;
    	vector<vector<int> > dp(len,vector<int>(len,0));
    	for(int i = len-2; i >= 0; i--) {
    		for(int j = i+1; j < len; j++) {
    			if(s[i] == s[j]) {
    				if(i == j-1) dp[i][j] = 2;
    				else if(i == j-2) dp[i][j] = 3;
    				else if(dp[i+1][j-1]) dp[i][j] = dp[i+1][j-1] + 2;
    				if(dp[i][j] > max_len) {
    					max_len = dp[i][j];
    					start = i;
					}
				}
			}
		}
        if(!max_len) return s.substr(len-1,1);
		return s.substr(start, max_len);
    }
};


int main() {
	string s = "xabay";
	Solution solution;
	cout << solution.longestPalindrome(s) << endl;
} 
