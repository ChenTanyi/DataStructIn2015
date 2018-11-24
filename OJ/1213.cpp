#include <iostream>
 
template typename _Tp
class vector{
public
    typedef _Tp value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type pointer;
    typedef const value_type const_pointer;
    typedef value_type iterator;
    typedef const value_type const_iterator;
private
    pointer _start;
    pointer _finish;
    pointer _end_of_storage;
    void create();create a empty vector
    void create(int , const value_type &);create a vector of n element
    void create(const_iterator , const_iterator);copy from first to last to create a vector
    void destroy() {destroy the vector
        if (_start) delete [] _start;
        _start = _finish = _end_of_storage = 0;
    }
    void grow();double the capacity of vector
 
 
public
    class const_reverse_iterator;
    class reverse_iterator;
 
    vector(){create();}
    explicit vector(int _size, const value_type & _value = value_type()){create(_size , _value);}
    vector (const vector & _a) {create(_a.begin(),_a.end());}
    vector (const_iterator & _first , const_iterator & _last) {creat(_first , _last);}
    ~vector(){destroy();}
 
    vector & operator = (const vector &);
    reference operator [] (int n) {return _start[n];}
    const_reference operator [] (int n) const {return _start[n];}
 
    iterator begin () {return _start;}
    const_iterator begin () const {return _start;}
    iterator end () {return _finish;}
    const_iterator end () const {return _finish;}
 
    reverse_iterator rbegin () {return reverse_iterator(end());}
    const_reverse_iterator rbegin () const {return const_reverse_iterator(end());}
    reverse_iterator rend () {return reverse_iterator(begin());}
    const_reverse_iterator rend () const {return const_reverse_iterator(begin());}
 
    int size() const {return _finish - _start;}
    int capacity() const {return _end_of_storage - _start;}
    bool empty() const {return _finish == _start;}
    void clear() {_finish = _start;}
 
    void swap(const vector &);
 
    void push_back(const value_type &);
    void pop_back();
 
    reference front() {return _start;}
    const_reference front() const {return _start;}
    reference back() {return (_finish - 1);}
    const_reference back() const {return (_finish - 1);}
 
    iterator erase(iterator);
    iterator erase(iterator , iterator);
 
    void resize(int , const value_type & _value = value_type());
    void reserve(int);
};
 
 
 
-----------------------definition------------------------------
 
template typename _Tp
void vector_Tp  create(){
    _start = _finish = _end_of_storage = 0;
}
 
template typename _Tp
void vector_Tp  create(int _size , const value_type & _value){
    _start = new value_type[_size];
    _finish = _end_of_storage = _start + _size;
    for (pointer p = _start ; p != _finish ; ++ p)
        p = _value;
}
 
template typename _Tp
void vector_Tp  create(const_iterator _first , const_iterator _last){
    int _size = _last - _first;
    _start = new value_type[_size];
    _finish = _end_of_storage = _start + _size;
    for (int i = 0 ; i  _size ; ++ i){
        _start[i] = _first[i];
    }
}
 
template typename _Tp
void vector_Tp  grow(){
    int _size = 2  (_finish - _start);
    if (_size  1) _size = 1;
    pointer _new_start = new value_type[_size];
    pointer _new_finish = _new_start;
    for (pointer i = _start ; i != _finish ; ++_new_finish , ++ i){
        _new_finish = i;
    }
    destroy();
    _start = _new_start;
    _finish = _new_finish;
    _end_of_storage = _start + _size;
}
 
template typename _Tp
vector_Tp & vector_Tp  operator = (const vector & _a){
    if (this != & _a){
        destroy();
        create(_a.begin() , _a.end());
    }
    return this;
}
 
template typename _Tp
void vector_Tp  swap (const vector & _a){
    std  swap (_start , _a._start);
    std  swap (_finish , _a._finish);
    std  swap (_end_of_storage , _a._end_of_storage);
}
 
template typename _Tp
void vector_Tp  push_back (const value_type & _value){
    if (_finish == _end_of_storage){
        grow();
    }
    _finish = _value;
    ++ _finish;
}
 
template typename _Tp
void vector_Tp  pop_back (){
    if (!empty()) -- _finish;
}
 
template typename _Tp
typename vector_Tpiterator vector_Tp  erase (iterator _pos){
    for (iterator it = _pos ; it != end() - 1 ; ++ it){
        it = (it + 1);
    }
    -- _finish;
    return _pos;
}
 
template typename _Tp
typename vector_Tpiterator vector_Tp  erase (iterator _first , iterator _last){
    iterator it;
    for (it = _first ; _last != end() ; ++ it , ++ _last){
        it = _last;
    }
    _finish = it;
    return _first;
}
 
template typename _Tp
void vector_Tp  resize (int _new_size , const value_type & _value){
    if (_new_size  size()) erase(_start + _new_size , end());
    else if (_new_size  capacity()) {
        std  fill (_finish , _start + _new_size , _value);
        _finish = _start + _new_size;
    }
    else {
        pointer _new_start = new value_type[_new_size];
        for (int i = 0 ; i  size() ; ++ i){
            _new_start[i] = _start[i];
        }
        std  fill (_new_start + size() , _new_start + _new_size , _value);
        destroy();
        _start = _new_start;
        _finish = _end_of_storage = _start + _new_size;
    }
}
 
template typename _Tp
void vector_Tp  reserve (int _new_capacity){
    if (_new_capacity  capacity()){
        pointer _new_start = new value_type[_new_capacity];
        pointer _new_finish = _new_start + size();
        for (int i = 0 ; i  size() ; ++ i){
            _new_start[i] = _start[i];
        }
        destroy();
        _start = _new_start;
        _finish = _new_finish;
        _end_of_storage = _new_start + _new_capacity;
    }
}
 
 
template typename _Tp
class vector_Tp  reverse_iterator{
    private
        iterator _current;
    public
        explicit reverse_iterator(const iterator & it = NULL)  _current(it){}
        reverse_iterator(const reverse_iterator & it)  _current(it._current){}
        reverse_iterator(const const_reverse_iterator & it)  _current(it._current){}
        iterator base() const { return _current;}
 
        reference operator  () const{
            iterator tmp = _current;
            return --tmp;
        }
 
        pointer operator - () const
        {return &(operator());}
 
        reverse_iterator & operator ++ (){
            -- _current;
            return this;
        }
 
        reverse_iterator operator ++ (int){
            reverse_iterator tmp = this;
            -- _current;
            return tmp;
        }
 
        reverse_iterator & operator -- (){
            ++ _current;
            return this;
        }
 
        reverse_iterator operator -- (int){
            reverse_iterator tmp = this;
            ++ _current;
            return tmp;
        }
 
        friend bool operator == (const reverse_iterator & _a , const reverse_iterator & _b){
            return _a.base() == _b.base();
        }
 
        friend bool operator != (const reverse_iterator & _a , const reverse_iterator & _b){
            return _a.base() != _b.base();
        }
};
 
template typename _Tp
class vector_Tp  const_reverse_iterator{
    private
        const_iterator _current;
    public
        explicit const_reverse_iterator(const const_iterator & it = NULL)  _current(it){}
        const_reverse_iterator(const const_reverse_iterator & it)  _current(it._current){}
        const_reverse_iterator(const reverse_iterator & it)  _current(it.base()){}
        const_iterator base() const { return _current;}
 
        const_reference operator  () const{
            const_iterator tmp = _current;
            return --tmp;
        }
 
        const_pointer operator - () const
        {return &(operator());}
 
        const_reverse_iterator & operator ++ (){
            -- _current;
            return this;
        }
 
        const_reverse_iterator operator ++ (int){
            const_reverse_iterator tmp = this;
            -- _current;
            return tmp;
        }
 
        const_reverse_iterator & operator -- (){
            ++ _current;
            return this;
        }
 
        const_reverse_iterator operator -- (int){
            const_reverse_iterator tmp = this;
            ++ _current;
            return tmp;
        }
 
        friend bool operator == (const const_reverse_iterator & _a , const const_reverse_iterator & _b){
            return _a.base() == _b.base();
        }
 
        friend bool operator != (const const_reverse_iterator & _a , const const_reverse_iterator & _b){
            return _a.base() != _b.base();
        }
};
 
 
template typename T
class BinaryTreeNode{
public
    T value;
    int parent;
    int left;
    int right;
    BinaryTreeNode(T val = T(), int p = 0, int l = 0, int r = 0)
        value(val),parent(p),left(l),right(r){}
};
 
template typename T
bool operator == (const BinaryTreeNodeT & a, const BinaryTreeNodeT & b){
    return a.value == b.value;
}
 
vectorBinaryTreeNodeint v[2];
vectorint t[2];
 
void destory(int n){
    for (int c = 0 ; c  2 ; ++ c)
    for (int i = 0 ; i  n ; ++ i){
        delete v[c][i];
    }
}
 
int main(){
    int n ;
    std  cin  n;
  for (int c = 0 ; c  2 ; ++ c){
    v[c].reserve(n+10);
    for (int i = 0 ; i = n ; ++ i){
        v[c].push_back(new BinaryTreeNodeint);
    }
    if (c == 1){
        int m;
        std  cin  m;
        if (n != m){
            std  cout  Nn;
            destory(n + 1);
            return 0;
        }
        for (int i = 0 ; i = n ; ++ i){
            v[c][i]-left = 0;
            v[c][i]-right = 0;
            v[c][i]-parent = 0;
        }
    }
    for (int i = 1 ; i = n ; ++ i){
        int l, r, val;
        std  cin  l  r  val;
        v[c][i]-value = val;
        if (l) {
            v[c][i]-left = l;
            v[c][l]-parent = i;
        }
        if (r) {
            v[c][i]-right = r;
            v[c][r]-parent = i;
        }
    }
    int root = 0;
    for (int i = 1 ; i = n ; ++ i){
        if (!v[c][i]-parent){
            root = i;
            break;
        }
    }
    t[c].push_back(root);
    for (int head = 0 ; head  t[c].size() ; ++ head){
        int x = t[c][head];
        if (v[c][x]-left){
            t[c].push_back(v[c][x]-left);
        }
        if (v[c][x]-right){
            t[c].push_back(v[c][x]-right);
        }
        if (c == 1){
            int y = t[0][head];
            if (v[1][x]-value != v[0][y]-value){
                std  cout  Nn;
                destory(n + 1);
                return 0;
            }
            if (v[1][x]-left  v[0][y]-left){
                if (!(v[1][x]-left && v[0][y]-left && v[1][v[1][x]-left]-value == v[0][v[0][y]-left]-value)){
                    std  cout  Nn;
                    destory(n + 1);
                    return 0;
                }
            }
            if (v[1][x]-right  v[0][y]-right){
                if (!(v[1][x]-right && v[0][y]-right && v[1][v[1][x]-right]-value == v[0][v[0][y]-right]-value)){
                    std  cout  Nn;
                    destory(n + 1);
                    return 0;
                }
            }
            if (v[1][x]-parent  v[0][y]-parent){
                if (!(v[1][x]-parent && v[0][y]-parent && v[1][v[1][x]-parent]-value == v[0][v[0][y]-parent]-value)){
                    std  cout  Nn;
 
                }
            }
        }
    }
  }
    std  cout  Yn;
    destory(n + 1);
    return 0;
}