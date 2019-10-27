/*  
4. Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Ex: nums1 = [1, 3]
    nums2 = [2]

    The median is 2.0
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void printVect(vector<int> &nums) {
        cout << "[";
        for (int i = 0; i < nums.size(); i++) {
            if (i != nums.size() - 1) {
                cout << nums.at(i) << ", ";
            } else {
                cout << nums.at(i) << "]" << endl;
            }
        }
    }
    void bubbleSort(vector<int> &nums, int rem) {
        /* rem = remaining elements left to be sorted; as function is called, largest element will bubble to the top and there will be less elements to sort
         */
        if (rem <= 1) {
            return;
        } else {
            for (int i = 0; i < rem - 1; i++) {
                if (nums.at(i) > nums.at(i + 1)) {
                    int temp = nums.at(i + 1);
                    nums.at(i + 1) = nums.at(i);
                    nums.at(i) = temp;
                }
            }
            bubbleSort(nums, rem - 1);
        }
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        //concatenate the two vectors
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        printVect(nums1);
        //"brute force" approach using bubble sort to sort
        bubbleSort(nums1, nums1.size());
        cout << "AFTER BUBBLE SORT" << endl;

        printVect(nums1);

        //logic to find median once array is sorted
        double median;
        if (nums1.size() % 2 != 0) {
            median = nums1.at((nums1.size() - 1) / 2);
        } else {
            int num1 = nums1.at((nums1.size() - 2) / 2);
            int num2 = nums1.at(nums1.size() / 2);
            median = (double)(num1 + num2) / 2;
        }

        return median;
    }
};
int main(int argc, char const *argv[]) {
    //For testing purposes in external editor
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(3);
    nums2.push_back(4);
    nums2.push_back(2);

    Solution sol;
    double median = sol.findMedianSortedArrays(nums1, nums2);

    cout << "MEDIAN: " << median << endl;

    return 0;
}
