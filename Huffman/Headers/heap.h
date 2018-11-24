#ifndef heap_H
#define heap_H

/*
 *  define the heap function in 2 versions
 *  one is using default comparison functor to build a max heap
 *  the other is using a user-defined comparison functor to build a heap
 */

//Push an element onto a heap

template <typename Iterater, typename Distance, typename Value>
void push_heap(Iterater first, Distance index, Value value, Distance top = 0);

template <typename Iterater, typename Distance, typename Value, typename Compare>
void push_heap(Iterater first, Distance index, Value value, Compare comp, Distance top = 0);

template <typename Iterater>
void push_heap(Iterater first, Iterater last);

template <typename Iterater, typename Compare>
void push_heap(Iterater first, Iterater last, Compare comp);

//Pop an element off a heap

template <typename Iterater, typename Distance, typename Value>
void adjust_heap(Iterater first, Distance index, Distance len, Value value);

template <typename Iterater, typename Distance, typename Value, typename Compare>
void adjust_heap(Iterater first, Distance index, Distance len, Value value, Compare comp);

template <typename Iterater, typename Value>
void pop_heap(Iterater first, Iterater last, Iterater result, Value value);

template <typename Iterater, typename Value, typename Compare>
void pop_heap(Iterater first, Iterater last, Iterater result, Value value, Compare comp);

template <typename Iterater>
void pop_heap(Iterater first, Iterater last);

template <typename Iterater, typename Compare>
void pop_heap(Iterater first, Iterater last, Compare comp);

//Construct a heap over a range

template <typename Iterater>
void make_heap(Iterater first, Iterater last);

template <typename Iterater, typename Compare>
void make_heap(Iterater first, Iterater last, Compare comp);

//Sort a heap

template <typename Iterater>
void sort_heap(Iterater first, Iterater last);

template <typename Iterater, typename Compare>
void sort_heap(Iterater first, Iterater last, Compare comp);



//------------------------definition-----------------------------------------

template <typename Iterater, typename Distance, typename Value>
void push_heap(Iterater first, Distance index, Distance top, Value value){
	Distance parent = (index - 1) / 2;
	while (index > top && first[parent] < value){
		first[index] = first[parent];
		index = parent;
		parent = (index - 1) / 2;
	}
	first[index] = value;
}

template <typename Iterater, typename Distance, typename Value, typename Compare>
void push_heap(Iterater first, Distance index, Distance top, Value value, Compare comp){
	Distance parent = (index - 1) / 2;
	while (index > top && comp(first[parent], value)){
		first[index] = first[parent];
		index = parent;
		parent = (index - 1) / 2;
	}
	first[index] = value;
}

template <typename Iterater>
void push_heap(Iterater first, Iterater last){
	push_heap(first, static_cast<int>(last - first - 1) , static_cast<int>(0) , *(last - 1));
}

template <typename Iterater, typename Compare>
void push_heap(Iterater first, Iterater last, Compare comp){
	push_heap(first, static_cast<int>(last - first - 1) , static_cast<int>(0) , *(last - 1), comp);
}

template <typename Iterater, typename Distance, typename Value>
void adjust_heap(Iterater first, Distance index, Distance len, Value value){
	Distance top = index;
	Distance child = 2 * index + 2;
	while (child < len){
		if (first[child] < first[child - 1])
			--child;
		first[index] = first[child];
		index = child;
		child = 2 * child + 2;
	}
	if (child == len && (len & 1) == 0){
		first[index] = first[child - 1];
		index = child - 1;
	}
	push_heap(first, index, top, value);
}

template <typename Iterater, typename Distance, typename Value, typename Compare>
void adjust_heap(Iterater first, Distance index, Distance len, Value value, Compare comp){
	Distance top = index;
	Distance child = 2 * index + 2;
	while (child < len){
		if (comp(first[child], first[child - 1]))
			--child;
		first[index] = first[child];
		index = child;
		child = 2 * child + 2;
	}
	if (child == len && (len & 1) == 0){
		first[index] = first[child - 1];
		index = child - 1;
	}
	push_heap(first, index, top, value, comp);
}

template <typename Iterater, typename Value>
void pop_heap(Iterater first, Iterater last, Iterater result, Value value){
	*result = *first;
	adjust_heap(first, static_cast<int>(0), static_cast<int>(last - first), value);
}

template <typename Iterater, typename Value, typename Compare>
void pop_heap(Iterater first, Iterater last, Iterater result, Value value, Compare comp){
	*result = *first;
	adjust_heap(first, static_cast<int>(0), static_cast<int>(last - first), value, comp);
}

template <typename Iterater>
void pop_heap(Iterater first, Iterater last){
	if (last - first > 1){
		--last;
		pop_heap(first, last, last, *last);
	}
}

template <typename Iterater, typename Compare>
void pop_heap(Iterater first, Iterater last, Compare comp){
	if (last - first > 1){
		--last;
		pop_heap(first, last, last, *last, comp);
	}
}

template <typename Iterater>
void make_heap(Iterater first, Iterater last){
	if (last - first < 2) return;
	typedef __typeof(last - first) Distance;
	Distance len = last - first;
	for (Distance parent = (len - 2) / 2; parent >= 0 ; -- parent){
		adjust_heap(first, parent, len, first[parent]);
	}
}

template <typename Iterater, typename Compare>
void make_heap(Iterater first, Iterater last, Compare comp){
	if (last - first < 2) return;
	typedef __typeof(last - first) Distance;
	Distance len = last - first;
	for (Distance parent = (len - 2) / 2; parent >= 0 ; -- parent){
		adjust_heap(first, parent, len, first[parent], comp);
	}
}

template <typename Iterater>
void sort_heap(Iterater first, Iterater last){
	while (last - first > 1)
		pop_heap(first, --last);
}

template <typename Iterater, typename Compare>
void sort_heap(Iterater first, Iterater last, Compare comp){
	while (last - first > 1)
		pop_heap(first, --last, comp);
}

/*template <typename Iterater, typename Distance>
Distance is_heap_until(Iterater first, Distance n){
    Distance parent = 0;
    for (Distance child = 1 ; child < n ; ++ child){
        if (first[parent] < first[child])
            return child;
        if ((child & 1) == 0)
            ++ parent;
    }
    return n;
}

template <typename Iterater, typename Distance, typename Compare>
Distance is_heap_until(Iterater first, Distance n, Compare comp){
    Distance parent = 0;
    for (Distance child = 1 ; child < n ; ++ child){
        if (comp(first[parent], first[child]))
            return child;
        if ((child & 1) == 0)
            ++ parent;
    }
    return n;
}*/

#endif // heap_H
