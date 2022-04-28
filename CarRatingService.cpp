//
//  CarRatingService.cpp
//  CarRatingproj
//
//  Created by Lance Cole on 3/15/22.
//
#include "CarRating.hpp"
#include "CarRatingService.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//a default constructor that takes no arguments. Holds zero types.
CarRatingService::CarRatingService() {
    _root = NULL;
    _nodeCount = 0;
    _maxDepth = 0;
    
}
// Constructor to read in files
CarRatingService::CarRatingService(std::istream& stream){
    //Loop through file and copy over the stored CarRating info.
    CarRating cr;
    stream >> cr;
    while(stream) {
        this->operator+=(cr);
        stream >> cr;
    }
}

// Return the rating of cars
int CarRatingService::numCars()
{
    return _nodeCount;
}
//Clear the collection
void CarRatingService::clear()
{
    _root = NULL; // Set tree to null
        
}
// Cout the make
void CarRatingService::printMake(const std::string& _make)
{
    cout << "What is the make of car? " << _make << endl;
}
//cout the model
void CarRatingService::printModel(const std::string& _model)
{
    cout << "What is the model of car? " << _model << endl;
}
//cout the year
void CarRatingService::printYear(int _year)
{
    cout << "What is the year of car? " << _year << endl;
}

Node* CarRatingService::TreeInsert(const CarRating& input, Node*& node) {
    if(!node) {
        node = new Node();
        node->data() = new CarRating(input);
        _nodeCount++;
        return node;
    }
    
    if(*node > input) {
        Node* fNode = TreeInsert(input, node->left());
        if(fNode && !fNode->parent()) {
            fNode->parent() = node;
            int depth = fNode->depth();
            if(depth > _maxDepth)
                _maxDepth = depth;
        }
        return fNode;
    }
    
    if(*node == input)
        return node;
    
    Node* fNode = TreeInsert(input, node->right());
    if(fNode && !fNode->parent()) {
        fNode->parent() = node;
        int depth = fNode->depth();
        if(depth > _maxDepth)
            _maxDepth = depth;
    }
    return fNode;
}

Node* CarRatingService::TreeSearch(const std::string& tree, Node* node) {
    if(!node)
        return NULL;
    
    if(node->data()-> make() > tree)
        return TreeSearch(tree, node->left());
    if(node->data()-> make() == tree)
        return node;
    return TreeSearch(tree, node->right());
}

Node* CarRatingService::TreeRemove(const std::string& tree) {
    Node* node = TreeSearch(tree, _root);
    if(!node)
        return NULL;
    
    if(node->isLeaf()) {
        if(node == _root)
            _root=NULL;
        else {
            Node* parent = node->parent();
            if(parent->left() == node)
                parent->left() = NULL;
            else
                parent->right() = NULL;
        }
    } else {
        if(!node->left()){ //Have only right node.
            if(node->parent()->left() == node)
                node->parent()->left() = node->right();
            else
                node->parent()->right() = node->right();
        } else { //Have left node and possbly right node.
            
            //Examine the tree and retrieve the next car...
            Node* car = node->left();
            while(car->right())
                car = car->right();
                
            //Replace the node in the tree
            if(node->parent()->left() == node)
                node->parent()->left() = car;
            else
                node->parent()->right() = car;
                
            //Copy over the node that was replaced
            car->left() = node->left();
            car->right() = node->right();
            
            //Clear the replacements parent before updating its parent.
            if(car->parent()){
                if(car->parent()->left() == car)
                    car->parent()->left() = NULL;
                else
                   car->parent()->right() = NULL;
            }
            car->parent() = node->parent();
        }
    }
    
    //Decrement count.
    _nodeCount--;
    
    //Clear node
    node->parent() = node->left() = node->right() = NULL;
 
    //Return removed node.
    return node;
}

bool CarRatingService::insert(const CarRating& data)
{
    return this->TreeInsert(data, _root);
}

bool CarRatingService::contains(const std::string & data)
{
    return this->TreeSearch(data, _root);
}

bool CarRatingService::remove(const std::string& data)
{
    return this->TreeRemove(data);
}


// Return the empty tree
CarRatingService& CarRatingService::operator=(const CarRatingService& car)
{
    this->clear();

    return *this;
}
// Appends the ratings to the tree, two step approach
CarRatingService& CarRatingService::operator+=(const CarRating& car)
{
    /*Link* link  = new Link(car);
    if (_tail) {
        _tail->next = link;
        _tail = link;
    }
    else
    {
        _head = link;
        _tail = link;
    }
    curIndex++;
    
    */return *this;
}
//Updating the Car Rating index
CarRatingService& CarRatingService::operator+=(const CarRatingService& car)
{
    /*Link* cur = car._head;
    while(cur){
        this->operator+=(cur->data);
        cur = cur->next;
    }
    
    */return *this;
}
//Remove the Car Rating and updates it
CarRatingService& CarRatingService::operator-=(const CarRating& crs)
{
//    Link* prv = NULL;
//    Link* cur = this->_head;
//    while(cur){
//        //comparison
//        // +-> if true, remove block
//        if (cur->data.make()==crs) {
//            if (prv) {
//                prv->next = cur->next;
//            }
//            else {
//                //Interacting with HEAD
//                _head = cur->next;
//            }
//            if (cur->next == NULL) {
//                _tail = prv;
//            }
//            // delete the current node
//            delete cur;
//            curIndex--;
//            break;
//        }
//        //prev node is = to the cur so update the cur node with the next one
//        prv = cur;
//        cur = cur->next;
//    }
//
//
    return *this;

}
//Print out car ratings
std::ostream& operator<<(std::ostream& os, const CarRatingService& crs) {
    //Loop through and print out each item.
   /* const CarRatingService::Link* link = crs._head;
    while(link) {
        os << link->data << std::endl;
        link = link->next;
    }
    */return os;
}
