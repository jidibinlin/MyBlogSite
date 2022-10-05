//c++ version
#include <algrothim>
#include <iostream>
#include <math>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0;
        int right = height.size()-1;
        int compacity = 0;

        while (left < right) {
            int min = fmin(height[left], height[right]);
            int length = right - left;
            int tmpCompacity = min * length;

            if (tmpCompacity >= compacity)
                compacity = tmpCompacity;
            if (height[left] >= height[right])
                right--;
            else
                left++;
        }

        return compacity;
    }
};

int main(int argc, char *argv[]) { return 0; }
