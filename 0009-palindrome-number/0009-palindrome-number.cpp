class Solution {
public:
    bool isPalindrome(int x) {
        string conv = to_string(x);

        for(int i = 0, j = conv.length() - 1; i < conv.length()/2; i++, j--){
            if(conv[i] != conv[j])
                return false;
        }

        return true;
    }
};