class Solution {
public:
    int trap(vector<int>& height) {

        int N = height.size();
        if(N == 0) { 
            return 0;
        }

        int leftSide = 0, rightSide = N-1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while(leftSide < rightSide){
            if(height[leftSide] > leftMax){
                leftMax = height[leftSide];
            }
            if(height[rightSide] > rightMax){
                rightMax = height[rightSide];
            }
            if(leftMax < rightMax){
                ans += max(0, leftMax - height[leftSide]);
                leftSide++;
            } else {
                ans += max(0, rightMax - height[rightSide]);
                rightSide--;
            }
        }
    return ans;
    }
};