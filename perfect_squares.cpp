#include <vector>
#include <limits>
#include <cmath>
using namespace std;
// условие задачи https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int numSquares(int n) {
        // динамическо программирование (кузнечик)
        vector<int> d(n + 1, std::numeric_limits<int>::max());
        d[0] = 0;
        for(int i = 1; i < d.size(); ++i) {

            int sq = static_cast<int>(std::sqrt(i));
            
            if (sq == 1) {
                d[i] = 1 + d[i - 1];
            } else {
                for(int q = sq; q >= 1; --q) {
                    d[i] = std::min(d[i - q * q] + 1, d[i]);
                }
            }
        }

        return d.back();

    
    }
};

int main() {



    return 0;
}