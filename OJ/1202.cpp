#include <iostream>
#include <cstdio>

struct node{
    int value;
    node * next;
    node * prev;
    node(const int & _value = 0 , node * _next = NULL , node * _prev = NULL) : value(_value),next(_next),prev(_prev){}
};

class list{
private:
    node * head;
    node * tail;
    int counter;
public:
    list();
    ~list();
    void clear();
    void push_front(const int & x);
    bool empty() const {return head -> next == tail;}
    int back() const {return tail -> prev -> value;}
    friend list operator + (const list & a, const list & b);
    friend std::ostream & operator << (std::ostream &, const list &);
};

list::list(){
    head = tail = new node;
}

list::~list(){
    clear();
    delete head;
}

void list::clear(){
    node * tmp = tail;
    while (tail != head){
        tail = tail -> prev;
        delete tmp;
        tmp = tail;
    }
}

void list::push_front(const int & x){
    node * tmp = new node(x , head -> next , head);
    if (head -> next) head -> next -> prev = tmp;
    head -> next = tmp;
    if (head == tail) tail = head -> next;
    ++counter;
}

list operator + (const list & a , const list & b){
    list tmp;
    int temp = 0;
    node * p = a.head -> next , * q = b.head -> next;
    while (p && q){
        tmp.push_front((temp + p -> value + q -> value) % 10);
        temp = (temp + p -> value + q -> value ) / 10;
        p = p -> next;
        q = q -> next;
    }
    while (p){
        tmp.push_front((temp + p -> value) % 10);
        temp = (temp + p -> value) / 10;
        p = p -> next;
    }
    while (q){
        tmp.push_front((temp + q -> value) % 10);
        temp = (temp + q -> value) / 10;
        q = q -> next;
    }
    if (temp) tmp.push_front(temp);
    return tmp;
}

std::ostream & operator << (std::ostream & os , const list & a){
    node * p = a.head -> next;
    while (p){
        os << p -> value;
        p = p -> next;
    }
    return os;
}

const int N = 1e6+1111;

char s[N];

int main(){
    gets(s);
    list a , b;
    for (int i = 0 ; s[i] ; ++ i){
        a.push_front(s[i] - '0');
    }
    gets(s);
    for (int i = 0 ; s[i] ; ++ i){
        b.push_front(s[i] - '0');
    }
    list c = a + b;
    std :: cout << c << std :: endl;
    return 0;
}
