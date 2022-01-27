#pragma once

template <typename T>
void	iter(T *arr, unsigned int n, void (*f)(T &)){
	for (unsigned int i(0); i < n; i++)
		(*f)(arr[i]);
	return;
}

template <char>
void	iter(char *arr, unsigned int n, void (*f)(char &)){
	for (unsigned int i(0); i < n && arr[i] != '\0'; i++)
		(*f)(arr[i]);
	return;
}
