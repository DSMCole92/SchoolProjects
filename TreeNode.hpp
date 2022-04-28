//
//  TreeNode.hpp
//  CRProjBT
//
//  Created by Lance Cole on 4/27/22.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <ostream>
#include <fstream>
#include <string>
#include "CarRating.hpp"

//Build Class
class Node { //Put this in its own .hpp
private:
    CarRating* _data;
    Node* _parent;
    Node* _left;
    Node* _right;

public:
    Node();
    bool isLeaf() const;
    int depth() const;

    
    const Node* parent() const {return _parent;}
    Node*& parent() {return _parent;}
    
    const Node* left() const {return _left;}
    Node*& left() {return _left;}
    
    const Node* right() const {return _right;}
    Node*& right() {return _right;}

    CarRating*& data();

    bool operator<(const CarRating&);
    bool operator==(const CarRating&);
    bool operator>(const CarRating&);
    friend std::ostream& operator<<(std::ostream&, const Node&);
};



#endif /* TreeNode_hpp */
