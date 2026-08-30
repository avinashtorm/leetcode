class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find indices of minimum and maximum
        for (int i = 0; i < n; i++) {

            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        int i = min(minIndex, maxIndex);
        int j = max(minIndex, maxIndex);

        // Three possible strategies
        int fromFront = j + 1;
        int fromBack = n - i;
        int fromBoth = (i + 1) + (n - j);

        return min({fromFront, fromBack, fromBoth});
    }
};