// Problem: Floor and Ceil in Sorted Array
// Source: Leetcode
// Approach: Binary Search (simultaneously track floor and ceil while narrowing search range)
// Time: O(log n)
// Space: O(1)

pair<int, int> findFloorCeil(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int floor = -1, ceil = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) return {arr[mid], arr[mid]};
        else if (arr[mid] < x) {
            floor = arr[mid];
            low = mid + 1;
        } else {
            ceil = arr[mid];
            high = mid - 1;
        }
    }
    return {floor, ceil};
}
