class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>firstWord(26,0), secondWord(26,0);
        set<char>setOne,setTwo;
        for(char c:word1){
            firstWord[c-'a']++;
            setOne.insert(c);
        }
        for(char c:word2){
            secondWord[c-'a']++;
            setTwo.insert(c);
        }
        sort(begin(firstWord),end(firstWord));
        sort(begin(secondWord),end(secondWord));
        return firstWord==secondWord&&setOne==setTwo;
    }
};