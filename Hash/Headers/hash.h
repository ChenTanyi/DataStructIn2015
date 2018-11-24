#ifndef hash_H
#define hash_H

#include "vector.h"
#include "pair.h"

template <typename Value, typename KeyOfValue>
class Hash{
protected:
    const int size;
	vector< pair<Value, int> > hashTable;
public:
	Hash(int);
	bool insert(const Value&, int&);
	bool erase(const Value&, int&);
	int find(const Value&, int&);
};

template <typename Value, typename KeyOfValue>
Hash<Value, KeyOfValue>::Hash(int num): size(num), hashTable(num){}

template <typename Value, typename KeyOfValue>
bool Hash<Value, KeyOfValue>::insert(const Value& v, int& count){
	count = 0;
    int flag = -1;
	for (int pos = KeyOfValue()(v) % size; count < size ; pos = (pos + 1) % size){
		++count;
		if (hashTable[pos].second != 1){
			if (hashTable[pos].second == 0){
				if (flag == -1){
					hashTable[pos].first = v;
					hashTable[pos].second = 1;
					return 1;
				}
				else break;
			}
			else if (hashTable[pos].second == 2 && flag == -1){
				flag = pos;
			}
		}
		else if (hashTable[pos].first == v){
			return 1;
		}
	}
	if (~flag){
		hashTable[flag].first = v;
		hashTable[flag].second = 1;
		return 1;
	}
	return 0;
}

template <typename Value, typename KeyOfValue>
bool Hash<Value, KeyOfValue>::erase(const Value& v, int& count){
	count = 0;
	for (int pos = KeyOfValue()(v) % size; count < size ; pos = (pos + 1) % size){
		++count;
		if (hashTable[pos].second == 0){
			return 0;
		}
		else if (hashTable[pos].first == v){
			hashTable[pos].second = 2;
			return 1;
		}
	}
	return 0;
}

template <typename Value, typename KeyOfValue>
int Hash<Value, KeyOfValue>::find(const Value& v, int& count){
	count = 0;
	for (int pos = KeyOfValue()(v) % size; count < size ; pos = (pos + 1) % size){
		++count;
		if (hashTable[pos].second == 0){
			return -1;
		}
		if (hashTable[pos].second == 1 && hashTable[pos].first == v){
			return pos;
		}
	}
	return -1;
}

#endif // hash_H
