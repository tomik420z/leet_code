#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> indices;
        std::vector<int> ans(temperatures.size(), 0);
         
        for(int i = 0; i < temperatures.size(); ++i) {
            if (indices.empty()) {
                indices.push(i);
            }
            else if (temperatures[i] < temperatures[indices.top()]) {
                indices.push(i);
            } 
            else {
                while(!indices.empty() && temperatures[i] > temperatures[indices.top()]) {
                    ans[indices.top()] = i - indices.top();
                    indices.pop();
                }

                indices.push(i);
            }

        }


        return ans;
        

        
    }
};

int main() {



    return 0;
}