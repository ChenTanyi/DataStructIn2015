#ifndef Node_H
#include <iostream>
#define Node_H

template < typename Elem >
class Node{
private:
    Elem element;
    Node * next ;
public:
    Node( const Elem & value , Node * nextval = NULL);
    Node( Node * nextval = NULL);
    void setValue( Elem & );
    void setNext( Node * );
    Elem & getValue ();
    Node * & getNext ();
};

template < typename Elem > Node < Elem > :: Node ( Node * nextval) : next(nextval){}

template < typename Elem > Node < Elem > :: Node ( const Elem & value , Node * nextval) :
    element(value) , next (nextval) {}

template < typename Elem > Elem & Node < Elem > :: getValue (){return element;}

template < typename Elem > Node < Elem >  * & Node < Elem > :: getNext(){return next ;}

template < typename Elem > void Node < Elem > :: setValue( Elem & value ){element = value ;}

template < typename Elem > void Node < Elem > :: setNext( Node < Elem > * pointer){next = pointer;}

#endif // Node_H
