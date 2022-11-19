class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer;
        
        if(strs.size() == 0)
            return "";
        
        for(int i = 0; i < strs[0].size(); i++){
            for(string& s : strs){
                if(s.length() <= i || s[i] != strs[0][i])
                    return answer;
            }
            answer += strs[0][i];
        }
        
        return answer;
    }
};