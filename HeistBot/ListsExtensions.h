#pragma once
#include <list>

using namespace std;
//class ListsExtensions
//{
//};


template<typename T>
T get(list<T> _list, int _i) {
	typename list<T>::iterator it = _list.begin();
	advance(it, _i);
	return *it;
}

template<typename T>
bool contains(list<T> _list, T _i) {
	bool _b = (find(_list.begin(), _list.end(), _i) != _list.end());
	return _b;
}



