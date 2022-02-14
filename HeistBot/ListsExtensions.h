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

