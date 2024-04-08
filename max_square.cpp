#include <vector>
#include <algorithm>
using namespace std;

// условие задачи https://leetcode.com/problems/maximal-square/

class Solution {
public:

    // рекурентное соотношение
    int val(vector<vector<char>>& matrix, vector<vector<int>>& d,  int i, int j) {
        if (i == 0 || j == 0) {
            return matrix[i][j] - '0';
        }
        
        if (matrix[i][j] == '0') {
            return 0;
        }

        if (matrix[i - 1][j - 1] != '0' && matrix[i - 1][j] != '0' && matrix[i][j - 1] != '0') {
            return std::min({d[i - 1][j - 1], d[i][j - 1], d[i - 1][j]}) + 1;
        }

        return 1;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();

        vector<vector<int>> d(N, std::vector<int>(M, 0));
        
        for(int i = 0; i < N; ++i) {
            int row = i;
            for(int col = 0; col < M && row >= 0; ++col, --row) {
                d[row][col] = val(matrix, d, row, col);
            }
        };

        
        for(int j = 1; j < M; ++j) {
            int col = j;
            for(int row = N - 1; row >= 0 && col < M; --row, ++col) {
                d[row][col] = val(matrix, d, row, col);
            }
        }

        int max_square = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                max_square = std::max(max_square, d[i][j] * d[i][j]);
            }
        }

        return max_square;
    }
};

int main() {



    return 0;
}