#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec = vector<int>(nums1);
        vec.insert(vec.end(),nums2.begin(),nums2.end());
        sort(vec.begin(),vec.end());
        size_t size = vec.size();
        if(size%2 == 1)
            return (double)vec.at(size/2);
        else
            return (double)(vec.at(size/2)+vec.at(size/2 - 1))/2.0;
    }
};