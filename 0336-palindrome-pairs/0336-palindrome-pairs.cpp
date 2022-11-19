class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordMap;
        vector<vector<int>> answer;
        
        for(int i=0; i < words.size(); i++)
            wordMap[words[i]] = i;
        
        for(int i =0; i < words.size(); i++){
            if(words[i] == ""){
                for(int j = 0; j < words.size(); j++){
                    string& w = words[j];
                    if(isPal(w, 0, w.size()-1)&& j != i){
                        answer.push_back(vector<int> {i, j});
                        answer.push_back(vector<int> {j, i});
                    }
                }
                
                continue;
                
            }
            
            string backwards = words[i];
            reverse(backwards.begin(), backwards.end());
            if(wordMap.find(backwards) != wordMap.end()) { 
                int result = wordMap[backwards];
                if (result != i) answer.push_back(vector<int> {i,result});
            }
            for(int j = 1; j < backwards.size(); j++){
                if (isPal(backwards,0,j-1)){
                    string s = backwards.substr(j, backwards.size()-j);
                    if(wordMap.find(s) != wordMap.end())
                        answer.push_back(vector<int>{i,wordMap[s]});
                    
                }
                if(isPal(backwards,j,backwards.size()-1)){
                    string s = backwards.substr(0,j);
                    if(wordMap.find(s) != wordMap.end())
                        answer.push_back(vector<int>{wordMap[s],i});
                }
            }
            
        }
        
       return answer;
        
    }
    
private:
    bool isPal(string& word, int i, int j){
        while(i<j)
            if(word[i++] != word[j--]) return false;
        return true;
    }
    
    
    
    
    
    
};