#include <iostream>
#include <vector>

using namespace std;

// условие задачи https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
    using table_t = std::vector<std::vector<int>>;
    
    int recurrence_relation(const table_t& table, int i, int j) {
        if (i == 0 || j == 0) {
            return 1;
        }  

        return table[i - 1][j] + table[i][j - 1];
    } 

    int uniquePaths(int m, int n) {

        table_t field(n, std::vector<int>(m, 0));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                field[i][j] = recurrence_relation(field, i, j);
            }
        }

        return field[n - 1][m - 1]; 
    }
};

int main() {



    return 0;
}