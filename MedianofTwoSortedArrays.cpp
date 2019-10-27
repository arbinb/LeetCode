#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        //brute force
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        for (int x : nums1) 
            cout << x << endl;
        #include <iostream>
        cout << "Hello" << endl;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(3);
    nums2.push_back(2);

    Solution sol;
    double x = sol.findMedianSortedArrays(nums1, nums2);

    return 0;
}
