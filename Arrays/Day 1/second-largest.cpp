// Problem: Second Largest Element
// Source: GFG
// Approach: Single Pass (Tracking largest & second largest)
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int largest = -1, secondLargest = -1;
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            }
            else if(arr[i] < largest && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }
        return secondLargest;
    }
};
