// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, middle;

        while(low < n){
            middle = low + (n - low)/2;
            if(isBadVersion(middle)){
                n = middle;
            } else {
                low = middle + 1;
            }

        }

        return low;
    }
};