#ifndef CircularLinkList_H
#define CircularLinkList_H
#include <iostream>
#include "List.h"
#include "Node.h"

template < typename Elem >
class CircularLinkList { //: public List<Elem>{;
private:
    Node <Elem> * head;
    Node <Elem> * tail;
    Node <Elem> * fence;
    int counter;
    void init();
    void removeall();
public:
    CircularLinkList();
    ~CircularLinkList();
    void clear();
    int length() const;
    void moveToStart();
    void moveToEnd();
    void next();
    Node <Elem> * & next() const ;
    int currPos() const;
    void moveToPos(int );
    void move(int );
    bool getValue(Elem &) const;
    //bool insert(const Elem &);
    void append(const Elem &);
    bool remove(Elem &);
};

template <typename Elem>
void CircularLinkList <Elem> :: init(){
    fence = head = tail = new Node <Elem>;
    counter = 0 ;
}

template <typename Elem>
void CircularLinkList <Elem> :: removeall(){
    while (head != tail){
        fence = head;
        head = head->getNext();
        delete fence;
    }
    delete head;
}

template <typename Elem>
CircularLinkList <Elem> :: CircularLinkList(){init();}

template <typename Elem>
CircularLinkList <Elem> :: ~CircularLinkList(){removeall();}

template <typename Elem>
void CircularLinkList <Elem> :: clear(){removeall();init();}

template <typename Elem>
int CircularLinkList <Elem> :: length() const {return counter;}

template <typename Elem>
void CircularLinkList <Elem> :: moveToStart(){fence = head;}

template <typename Elem>
void CircularLinkList <Elem> :: moveToEnd(){fence = tail;}

template <typename Elem>
void CircularLinkList <Elem> :: next(){fence = fence->getNext();}

template <typename Elem>
Node <Elem> * & CircularLinkList <Elem> :: next() const {return fence->getNext();}

template <typename Elem>
int CircularLinkList <Elem> :: currPos() const{
    if (head -> getNext() == NULL) return 0;
    int i = 0;
    Node <Elem> * temp = head;
    for (;fence != temp ; ++i){
        temp = temp->getNext();
    }
    return i;
}

template <typename Elem>
void CircularLinkList <Elem> :: moveToPos(int pos){
    if (head -> getNext() == NULL) return ;
    pos %= counter;
    if (pos < 0) pos += counter;
    int i = 0;
    for (fence = head ; i < pos ; ++ i){
        fence = fence->getNext();
    }
}

template <typename Elem>
void CircularLinkList <Elem> :: move(int num){
    if (head -> getNext() == NULL) return;
    num %= counter;
    if (num < 0) num += counter;
    for (int i = 0 ; i < num ; ++ i){
        fence = fence->getNext();
    }
}

template <typename Elem>
bool CircularLinkList <Elem> :: getValue(Elem & value) const{
    if (fence -> getNext() == NULL) return 0;
    value = fence -> getNext() -> getValue();
    return 1;
}

template <typename Elem>
void CircularLinkList <Elem> :: append(const Elem & value){
    tail -> getNext() = new Node <Elem> (value);
    tail = tail -> getNext();
    tail -> setNext(head -> getNext());
    ++ counter;
}

template <typename Elem>
bool CircularLinkList <Elem> :: remove(Elem & value){
    if (fence -> getNext() == NULL || counter == 0) return 0;
    value = fence -> getNext() -> getValue();
    Node <Elem> * temp = fence -> getNext();
    fence -> getNext() = temp -> getNext();
    if (tail == temp) tail = fence;
    if (tail == fence) head -> getNext() = fence -> getNext();
    delete temp;
    --counter;
    return 1;
}

#endif // CircularLinkList_H
