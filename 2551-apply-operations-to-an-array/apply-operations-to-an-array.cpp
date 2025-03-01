class Solution {
public:
   // Helper function to move all zeroes to the end while preserving the order of non-zero elements
   void shiftZeroesToEnd(vector<int>& nums) {
      int count = 0;  // Keep track of position where next non-zero element should go
    
      // Iterate through array
      for (int i = 0; i < nums.size(); i++) {
           // If current element is non-zero
           if (nums[i] != 0) {
               // Move it to the position tracked by count
               swap(nums[i], nums[count]);
               // Increment position for next non-zero element
               count++;
           }
           // If element is zero, we skip it (don't increment count)
           // This effectively pushes zeroes to the end
       }
   }

   vector<int> applyOperations(vector<int>& nums) {
       // Apply the operation: if two adjacent elements are equal,
       // double the first one and set the second one to zero
       for(int i = 0; i < nums.size() - 1; i++) {
           if(nums[i] == nums[i+1]) {
               nums[i] *= 2;      // Double the current element
               nums[i+1] = 0;     // Set next element to zero
           }
       }
       
       // Move all zeroes to the end while maintaining the order of non-zero elements
       shiftZeroesToEnd(nums);

       // Return the modified array
       return nums;
   }
};