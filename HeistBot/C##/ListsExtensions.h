#pragma once
#include <list>

using namespace std;

namespace CSS
{
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

	int length (int arr []) {
	int len = sizeof(arr)/sizeof(arr[0]);
	return len;
	}

	template<typename T>
	bool contains(T _list [], T _i) {
		bool _b = false;
		for (int i = 0; i < length[_list]; i++)
		{
			if (_i == _list[i]) _b = true;
		}
		return _b;
	}

	template<typename T>
	int getIndex(T _list [], T _i) {
		int __i = -1;
		for (int i = 0; i < length[_list]; i++)
		{
			if (_i == _list[i]) __i = i;
		}
		return __i;
	}
}
