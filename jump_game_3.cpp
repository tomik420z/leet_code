#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        std::vector<bool> used(arr.size());
        used[start] = true;

        std::stack<int> stack_ind;
        stack_ind.push(start);
        while(!stack_ind.empty()) {
            int curr_ind = stack_ind.top();
            stack_ind.pop();
            int jmp = arr[curr_ind];
            if (curr_ind + jmp < arr.size() && !used[curr_ind + jmp]) {
                used[curr_ind + jmp] = true;
                stack_ind.push(curr_ind + jmp);
            }

            if (curr_ind - jmp >= 0 && !used[curr_ind - jmp]) {
                used[curr_ind - jmp] = true;
                stack_ind.push(curr_ind - jmp);
            }
        }

        for(int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 0 && used[i]) {
                return true;
            }
        } 

        return false;

    }
};


int main() {



    return 0;
}