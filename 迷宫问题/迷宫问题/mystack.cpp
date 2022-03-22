#pragma once
#include"mystack.h"

template<class T>
SequentialStack<T>::SequentialStack() {
	_top = 0;
}

template<class T>
SequentialStack<T>::~SequentialStack() {
	_top = 0;
}

template<class T>
SequentialStack<T>* SequentialStack<T>::initStack() {
	return new SequentialStack;
}

template<class T>
bool SequentialStack<T>::destoryStack(SequentialStack<T>* _pSStack) {
	return delete _pSStack;
}

template<class T>
bool SequentialStack<T>::StackEmpty() {
	return _top == 0;
}

template<class T>
bool SequentialStack<T>::push(T value) {
	_DArr.add(value);
	_top++;
	return true;
}

template<class T>
T SequentialStack<T>::pop() {
	if (_top != 0) {
		T t = _DArr[--_top];
		//_DArr[_top] = 0;
		_DArr.out();
		return t;
	}
	else {
		return _DArr[0];
	}
}

template<class T>
T SequentialStack<T>::GetTop() {
	return _DArr[_top - 1];
}

template<class T>
SequentialStack<T>& SequentialStack<T>::operator = (SequentialStack<T> rhs) {
	_top = rhs._top;
	_DArr = rhs._DArr;
	return *this;
}

template<class T>
size_t SequentialStack<T>::size() {
	return _top;
}