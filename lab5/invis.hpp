#ifndef HEADER_HPP53
#define HEADER_HPP53
#include "../lab3/firstlab.hpp"
#include "../lab3/secondlab.hpp"
#include <vector>
#include "figure.hpp"

class Tree{
    public:
        class TreeNode{
            public:
                Polygon3d pol;
                TreeNode* front;
                TreeNode* back;
                TreeNode(Polygon3d p){
                    pol = p;
                    front = NULL;
                    back = NULL;
                }

            
        };
        TreeNode* root;
        Tree(Polygon3d p){
            root = new TreeNode(p);
        }
    

};
std::vector<Polygon3d> getPolygons(Figure f){
    auto out = std::vector<Polygon3d>();
    out.emplace_back(f.up);
    out.emplace_back(f.down);
    int n = f.up.x.size();
    for (int i = 0; i<n;++i){
        
        std::vector<std::vector<float>> vpol = std::vector<std::vector<float>>();
        vpol.emplace_back(f.up.x[i]);
        vpol.emplace_back(f.up.x[(i+1)%n]);
        vpol.emplace_back(f.down.x[(i+1)%n]);
        vpol.emplace_back(f.down.x[i]);
        out.emplace_back(Polygon3d(vpol));
    }
    return out;
}



#endif