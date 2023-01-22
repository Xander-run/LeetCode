#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::max;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left_index = 0, right_index = height.size() - 1;
        int max_capacity = 0;
        while (left_index < right_index) {
            int width = right_index - left_index;
            int min_height = min(height[right_index], height[left_index]);
            max_capacity = max(max_capacity, width * min_height);
            if (height[left_index] < height[right_index]) {
                move_until_higher(height, left_index, true);
            } else {
                move_until_higher(height, right_index, false);
            }
            
        }
        return max_capacity;
    }

private:
    void move_until_higher(vector<int>& height, int& index, bool is_left) {
        int next_index;

        while (index >= 0 && index < height.size()) {
            if (is_left) {
                next_index = index + 1;   
                if (next_index >= height.size()) {
                    break;
                }
            } else {
                next_index = index - 1;
                if (next_index < 0) {
                    break;
                }
            }

            if (height[next_index] > height[index]) {
                index = next_index;
                break;
            } else {
                index = next_index;
            }
        }
    } 
};