#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// условие задачи https://leetcode.com/problems/equal-row-and-column-pairs/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // последовательности строк будем хранить как ключ хэш таблицы 
        std::unordered_map<std::string, int> set_string;

        for(const auto& line : grid) {
            
            std::string tmp;
            for(int num : line) {
                tmp += std::to_string(num) + '#';
            }
            set_string[tmp] += 1;
        }
        // последовательности столбцов будем хранить как ключ хэш таблицы  
        std::unordered_map<std::string, int> set_string_y;

        for(int j = 0; j < grid[0].size(); ++j) {
            string tmp;
            for(int i = 0; i < grid.size(); ++i) {
                tmp += to_string(grid[i][j]) + '#';
            }
            set_string_y[tmp] += 1;
        }
    
        int count_pairs = 0;
        for(auto&&[seq, cnt] : set_string) {
            if (auto it = set_string_y.find(seq); it != set_string.end()) {
                count_pairs += cnt * it->second;
            }
        }
        
        return count_pairs;

    }
};

int main() {



    return 0;
}