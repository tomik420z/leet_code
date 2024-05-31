#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), 
            [](const auto& _lhs, const auto& _rhs){
                return (_lhs[0] < _rhs[0]) || (_lhs[0] == _rhs[0] && _lhs[1] < _rhs[1]);
            }
        );
        // используем префиксные суммвы
        vector<int> max_suffix(pairs.size());
        max_suffix.back() = 1;

        // проходимся по массиву с конца
        for(int i = (int)pairs.size() - 2; i >= 0; --i) {
            const auto& interval = pairs[i];
            
            int index = std::distance(

                        pairs.begin(), 
                        std::lower_bound(pairs.begin(),
                                         pairs.end(), vector<int>{interval[1] + 1, 0},
                                        [](const auto& _lhs, const auto& _rhs){
                                            return _lhs[0] < _rhs[0];
                                        }));

            if (index == pairs.size()) {
        
                max_suffix[i] = max_suffix[i + 1];
            } else {
                int val  = 1 + max_suffix[index];
                max_suffix[i] = std::max(val, max_suffix[i + 1]); 
            }
        }
        

        return max_suffix.front();
    }
};

int main() {



    return 0;
}