#ifndef iterator_H
#define iterator_H

/*
 *  use iterator to build the reverse iterator
 */

template <typename iterator>
class reverseIterator{
    private:
        iterator _current;
    public:
        typedef typename iterator::value_type value_type;
        typedef typename iterator::reference reference;
        typedef typename iterator::pointer pointer;

        explicit reverseIterator(const iterator & it = 0) : _current(it){}
        reverseIterator(const reverseIterator& it): _current(it._current){}

        template <typename Iterator>
        reverseIterator(const reverseIterator<Iterator>& it):_current(it.base()){}
        iterator base() const { return _current;}

        reference operator * () const{
            iterator tmp = _current;
            return *--tmp;
        }

        pointer operator -> () const
        {return &(operator*());}

        reverseIterator & operator ++ (){
            -- _current;
            return *this;
        }

        reverseIterator operator ++ (int){
            reverseIterator tmp = *this;
            -- _current;
            return tmp;
        }

        reverseIterator & operator -- (){
            ++ _current;
            return *this;
        }

        reverseIterator operator -- (int){
            reverseIterator tmp = *this;
            ++ _current;
            return tmp;
        }

        friend bool operator == (const reverseIterator & _a , const reverseIterator & _b){
            return _a.base() == _b.base();
        }

        friend bool operator != (const reverseIterator & _a , const reverseIterator & _b){
            return _a.base() != _b.base();
        }
};

#endif // iterator_H
