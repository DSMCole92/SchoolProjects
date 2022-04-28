//
//  CarRatingService.hpp
//  CarRatingproj
//
//  Created by Lance Cole on 3/15/22.
//

#ifndef CarRatingService_hpp
#define CarRatingService_hpp

#include <ostream>
#include <fstream>
#include <string>
#include "CarRating.hpp"
#include "TreeNode.hpp"

//Build Class
class CarRatingService
{
private:
    Node* _root;
    int _nodeCount;
    int _maxDepth;
    
    Node* TreeInsert(const CarRating&,Node*&);
    Node* TreeSearch(const std::string&,Node*);
    Node* TreeRemove(const std::string&);
    
public:
 
    bool insert(const CarRating&);
    bool contains(const std::string&);
    bool remove(const std::string&);

    
    //carRatingservice method for constructor also serves as the root of the tree
    CarRatingService();

    //a constructor that takes a single argument of type istream
    CarRatingService(std::istream&);
    
    //a method called numCars that takes no parameters and returns an integer
    int numCars();
    
    //a method called clear that simply empties out the collection. After calling this, it should appear as if there are no CarRatings in the current collection. This method should return nothing.
    void clear();
    
    //a method called printMake that should take a single parameter of type string as its only parameter. Make sure to pass this parameter efficiently and guarantee that it cannot be modified. This method should return nothing. The method itself should print out (to standard output using cout) all CarRatings whose make is the same as the value passed in as the parameter.
    void printMake(const std::string&);
    
    //a method called printModel that should take a single parameter of type string as its only parameter.
    void printModel(const std::string&);
    
    //a method called printYear that should take a single parameter of type int as its only parameter. This method should return nothing
    void printYear(int);
    
    //the = operator should be overloaded. The right hand side of this operator should be another CarRatingService (which should be guaranteed not to change and should be passed efficiently.) Using this operator should cause the operand on the left hand side to change to be a copy of the one on the right hand side. Be warned that the result should not “share” the same internal array! Finally, this method should return the copied CarRatingService.
    CarRatingService& operator=(const CarRatingService&);
    
    //the += operator should be overloaded with the right hand side being a single CarRating. Make sure to pass the CarRating efficiently and guarantee that it will not be modified by this method. This method should simply add the CarRating corresponding to the parameter to this CarRatingService. If the underlying car is already in this CarRatingService, then this CarRatingService should update the rating appropriately, keeping in mind the number of ratings in each object and the ratings value for each CarRating object. If this math seems complicated to you, ask Dr. Blythe about it! Finally this method should return a copy of the updated CarRatingService as efficiently as possible.
    CarRatingService& operator+=(const CarRating&);
    
    //the += operator should also be overloaded with the right hand side being another CarRatingService (not the small difference with the previous version of +=.) Make sure to pass the right hand side CarRatingService efficiently and guarantee that it will not be modified by this method. This method should simply add all of the the CarRatings corresponding to the parameter to this collection (making sure to properly handle cars that are already in this CarRatingService.) Finally this method should return a copy of the updated CarRatingService as efficiently as possible.
    CarRatingService& operator+=(const CarRatingService&);
    
    //the -= operator should be overloaded with the right hand side being a single CarRating. Make sure to pass the CarRating efficiently and guarantee that it will not be modified by this method. This method should simply remove the car corresponding to the parameter from this CarRatingService (or do nothing when the car is not present.) Finally this method should return the updated CarRatingService as efficiently as possible.
    CarRatingService& operator-=(const CarRating&);

    //overload the << operator for CarRatingService to output to a stream.
    friend std::ostream& operator<<(std::ostream&, const CarRatingService&);
 
};

#endif /* CarRatingService_hpp */
