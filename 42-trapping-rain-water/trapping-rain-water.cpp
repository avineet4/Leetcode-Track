class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int leftMax = height[0], rightMax = height[n - 1];
        int left = 0, right = n - 1;
        int water = 0;
        
        while(left < right) {
            if(height[left] < height[right]) {
                left++;
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
            }
        }

        return water;
    }
};