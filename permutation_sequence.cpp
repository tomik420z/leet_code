/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.


*/


class Solution {
public:

    int extract(std::vector<int>& collection, int k) {
        int tmp = collection[k];
        collection.erase(collection.begin() + k);
        return tmp;
    }

    std::vector<int> init_collection(int n) {
        std::vector<int> collection;
        for(int i = 1; i <= n; ++i) {
            collection.push_back(i);
        }
        return collection;
    }

    size_t fact(int n) {
        size_t ans = 1;
        while(n > 1) {
            ans *= n--;
        }
        return ans;
    }

    string getPermutation(int n, int k) {
        if (n == 1) return "1";
        --k;
        std::string res = "";
        res.reserve(n);
        std::vector<int> collection = init_collection(n);
        
        while(!collection.empty()) {
            int factorial = fact(n - 1);
            int v = extract(collection, k / factorial);
            res.push_back(v + '0');
            k %= factorial;
            --n;
        }
        return res;
    }
};
