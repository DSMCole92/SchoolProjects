//
//  TreeNode.cpp
//  CRProjBT
//
//  Created by Lance Cole on 4/27/22.
//

#include "TreeNode.hpp"
#include "CarRating.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//a default constructor that takes no arguments. Holds zero types.
Node::Node() {
    _parent = NULL;
    _left = NULL;
    _right = NULL;
    _data = NULL;
}

bool Node::isLeaf() const { return !(_left || _right); }

int Node::depth() const {
    int count = 0;
    Node* ancestor = _parent;
    while(!ancestor){
        count++;
        ancestor = ancestor->_parent;
    }
    return count;
}

CarRating*& Node::data() { return _data; }

bool Node::operator<(const CarRating& crs){
    return _data->make() < crs.make();
}

bool Node::operator==(const CarRating& crs){
    return _data->make() == crs.make();
}

bool Node::operator>(const CarRating& crs){
    return _data->make() > crs.make();
}

std::ostream& operator<<(std::ostream& os, const Node& node){
    os << *node._data;
   
    return os;
}
