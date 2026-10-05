class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> survivors;

        for (int ast : asteroids) {
            if (ast > 0) {
                survivors.push_back(ast);
            } 
            else {
                int currSize = abs(ast);
                bool destroyed = false;

                while (!survivors.empty() && survivors.back() > 0) {
                    int topSize = abs(survivors.back());

                    if (topSize < currSize) {
                        survivors.pop_back();
                    } 
                    else {
                        if (topSize == currSize) {
                            survivors.pop_back();
                        }

                        destroyed = true;
                        break;
                    }
                }

                if (!destroyed) {
                    survivors.push_back(ast);
                }
            }
        }

        return survivors;
    }
};