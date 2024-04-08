#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    using table_t = vector<vector<int>>;

    struct item_t {
        int index;
        int height;
    };

    int dist(int left, int right) {
        return right - left + 1;
    }

    int calc_square(std::vector<item_t>& items, int current_height, int right_border) {
        
        if (items.empty()) {
            return 0;
        }

        auto it = std::lower_bound(items.begin(), items.end(), item_t{0, current_height}, 
            [](const auto& _lhs, const auto& _rhs){
                return _lhs.height < _rhs.height;
            });

        if (it == items.end()) {
            return 0;
        }

        int i = std::distance(items.begin(), it);
        
        
        int max_square = 0;

        for(; i < items.size(); ++i) {
            max_square = std::max(dist(items[i].index, right_border) * items[i].height, max_square);  
        }

        it->height = current_height;
        ++it;
        items.erase(it, items.end());
        
        return max_square;
    }

    int calc_max_rectangle(const vector<int>& heights) {

        int max_square = 0;
        
        std::vector<item_t> items;
        items.reserve(heights.size());
        items.emplace_back(0, heights[0]);
        
        for(int i = 1; i < heights.size(); ++i) {
            
            if (heights[i - 1] >= heights[i]) {
                max_square = std::max(calc_square(items, heights[i], i - 1), max_square);
            } else {
                items.emplace_back(i, heights[i]);
            }
        }

        max_square = std::max(calc_square(items, 0, heights.size() - 1), max_square);

        return max_square;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();

        table_t table(N, vector<int>(M));

        for(int j = 0; j < M; ++j) {

            int curr_val = 0;
            
            for(int i = 0; i < N; ++i) {
                if (matrix[i][j] == '0') {
                    curr_val = 0;        
                } else {
                    table[i][j] = ++curr_val;
                }
            }
        }

        int max_square = 0;
        for(const auto& line : table) {
            max_square = std::max(max_square, calc_max_rectangle(line));
        }

        return max_square;

    }
};

int main() {
    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    vector<vector<char>> matrix(N, vector<char>(M)); 
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    Solution sol;
    std::cout << sol.maximalRectangle(matrix) << std::endl;

    return 0;
}