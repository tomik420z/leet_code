#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
// условие задачи https://leetcode.com/problems/asteroid-collision/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:

    vector<int> asteroidCollision(vector<int>& asteroids) {
        // стек астероидов, двигающийся направо 
        std::vector<int> index_positive_asteroids;
        // астероиды, которые летят налево, уничтожив все астероиды, летящие направо  
        std::vector<int> missing_asteroids;
        for(int i = 0;  i < asteroids.size(); ++i) {
            if (asteroids[i] > 0) { // астероид, двигающийся направо 
                index_positive_asteroids.push_back(i);
            } else { // астероид, двигающийся налево 
                while(!index_positive_asteroids.empty() && 
                      std::abs(asteroids[i]) > asteroids[index_positive_asteroids.back()]) {
                    
                    index_positive_asteroids.pop_back();
                }

                if (index_positive_asteroids.empty()) {
                    missing_asteroids.push_back(i);
                }

                if (!index_positive_asteroids.empty() && 
                    std::abs(asteroids[i]) == asteroids[index_positive_asteroids.back()]) {
                    index_positive_asteroids.pop_back();
                } 
                
            }
        }
        // индексы выживших астероидов 
        std::vector<int> indicies_asteroids;
        indicies_asteroids.reserve(index_positive_asteroids.size() + missing_asteroids.size());

        // индексы астероидов упорядоченны, поэтому можно слиять два массива 
        std::merge(index_positive_asteroids.begin(),
                   index_positive_asteroids.end(),
                   missing_asteroids.begin(),
                   missing_asteroids.end(), std::back_inserter(indicies_asteroids));

        // результат - веса оставшихся астероидов 
        std::vector<int> ans;
        ans.reserve(indicies_asteroids.size());

        for(int i = 0; i < indicies_asteroids.size(); ++i) {
            ans.push_back(asteroids[indicies_asteroids[i]]);
        }


        return ans;

    }
};

int main() {




    return 0;
}