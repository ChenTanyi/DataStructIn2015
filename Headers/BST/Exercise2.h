#ifndef Exercise2_H
#define Exercise2_H

#include "BST.h"

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
class exBST : public BST<Key, Value, KeyOfValue, Compare>{
public:
    typedef BST<Key, Value, KeyOfValue, Compare> bst;
    typedef typename bst::key_type key_type;

	void eraseGreater(const key_type& k);
	void eraseLess(const key_type& k);
	void eraseRange(const key_type& k1, const key_type& k2);
};

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
void exBST<Key, Value, KeyOfValue, Compare>::eraseGreater(const key_type& k){
	bst::erase(bst::upper_bound(k), bst::end());
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
void exBST<Key, Value, KeyOfValue, Compare>::eraseLess(const key_type& k){
	bst::erase(bst::begin(), bst::lower_bound(k));
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
void exBST<Key, Value, KeyOfValue, Compare>::eraseRange(const key_type& k1, const key_type& k2){
	bst::erase(bst::upper_bound(k1), bst::lower_bound(k2));
}

#endif // Exercise2_H
