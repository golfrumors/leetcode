class Solution {
public:
    //problem about building concave hull using monotone chain
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> hull;
        
        //sort points
        sort(begin(trees), end(trees), [](const auto& a, const auto& b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        
        for(const auto& tree : trees){
            while(hull.size()>1&& 
                 cross(hull.back(), hull[hull.size() - 2], tree) > 0)
                hull.pop_back();
            hull.push_back(tree);
        }
        hull.pop_back();
        
        //build top rtl
        for(int i = trees.size() - 1; i >= 0; --i){
            while(hull.size() > 1 &&
                 cross(hull.back(), hull[hull.size() - 2], trees[i]) > 0)
                hull.pop_back();
            hull.push_back(trees[i]);
        }
        
        //remove
        sort(begin(hull), end(hull), [](const auto& a, const auto& b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        
        hull.erase(
            unique(begin(hull), end(hull),
                  [](const auto& a,
                    const auto& b){
                      return a[0] == b[0] && a[1] == b[1];
                  }),
            end(hull));
        return hull;
        
    }
    
    private:
        int cross(const vector<int>& p, const vector<int>& q, const vector<int>& r){
            return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
        }
};