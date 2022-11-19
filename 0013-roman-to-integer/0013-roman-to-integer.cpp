#include <iostream>
#include <iterator>
#include <map>

namespace std{
class Solution {
   
public:
    int romanToInt(string s) {
        //declare map roman char => integer
        map<char,int> charsMap;
        //current char in int, & prev
        int current, previous, total = 0;
        
        //pair up equivalent roman chars
        
        charsMap.insert(pair<char,int>('I',1));
        charsMap.insert(pair<char,int>('V',5));
        charsMap.insert(pair<char,int>('X',10));
        charsMap.insert(pair<char,int>('L',50));
        charsMap.insert(pair<char,int>('C',100));
        charsMap.insert(pair<char,int>('D',500));
        charsMap.insert(pair<char,int>('M',1000));
        
        
        for(int i = (s.length()-1); i >= 0; i--){
            current = charsMap.at(s[i]);
            
            if(previous > current){
                total -= current; 
            } else {
                total += current;
                previous = current;
            }
            
        } 
        
         return total;

    }
    
};
}