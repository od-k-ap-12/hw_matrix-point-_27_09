#pragma once
#include<iostream>
using namespace std;

template<class T>
class Matrix
{
	T** mas;
	int str;
	int stolb;
public:
	Matrix();
	Matrix(int st, int stolb);
	Matrix(const Matrix<T>& obj);
	~Matrix();
	Matrix<T>& operator=(const Matrix<T>& obj);
	Matrix<T> operator+(int a);
	bool operator>(const Matrix<T> obj);
	void Random();
	void Print();
	int GetStr()const;
	int GetStolb()const;
	T** GetMatrix()const;
}; 

template <class T>
int Matrix<T>::GetStr()const {
	return str;
}
template <class T>
int Matrix<T>::GetStolb()const {
	return stolb;
}
template <class T>
T** Matrix<T>::GetMatrix()const {
	return mas;
}
template<class T>
Matrix<T>::Matrix()
{
	mas = nullptr;
	str = stolb = 0;
}
template<class T>
Matrix<T>::Matrix(int st, int stol)
{
	str = st;
	stolb = stol;
	mas = new T * [str];
	for (int i = 0; i < str; i++)
	{
		mas[i] = new T[stolb];
	}
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& obj)
{
	str = obj.str;
	stolb = obj.stolb;
	mas = new T * [str];
	for (int i = 0; i < str; i++)
	{
		mas[i] = new T[stolb];
	}
	// copy
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			mas[i][j] = obj.mas[i][j];
		}
	}
}
template<class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < str; i++)
	{
		delete[] mas[i];
	}
	delete[] mas;
}

template<class T>
void Matrix<T>::Random()
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			mas[i][j] = rand() % 100 * 1.6;
		}
	}
}

template<class T>
void Matrix<T>::Print()
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			cout << mas[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

template<class T>
ostream& operator<<(ostream& os, const Matrix<T>& obj){
	T** resmas = obj.GetMatrix();
	for (int i = 0; i < obj.GetStr(); i++)
	{
		for (int j = 0; j < obj.GetStolb(); j++)
		{
			os << resmas[i][j] << "\t";
		}
		os << endl << endl;
	}
	return os;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	if (mas != nullptr)
	{
		this->~Matrix();
	}

	//copy
	str = obj.str;
	stolb = obj.stolb;
	mas = new T * [str];
	for (int i = 0; i < str; i++)
	{
		mas[i] = new T[stolb];
	}
	// copy
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			mas[i][j] = obj.mas[i][j];
		}
	}
	return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator+(int a)
{
	Matrix<T> res(*this);
	for (int i = 0; i < res.str; i++)
	{
		for (int j = 0; j < res.stolb; j++)
		{
			res.mas[i][j]= res.mas[i][j]+a;
			cout << res.mas[i][j] << " ";
		}
		cout << endl << endl;
	}
	return res;
}
template <class T>
bool Matrix<T>::operator>(const Matrix<T> obj)
{
	if (str * stolb > obj.str * obj.stolb) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T,typename T1>
Matrix<T> operator+(T1 a, Matrix<T>& obj)
{
	Matrix<T> res=obj;
	T** resmas = res.GetMatrix();
	for (int i = 0; i < res.GetStr(); i++)
	{
		for (int j = 0; j < res.GetStolb(); j++)
		{
			resmas[i][j] += a;
			cout << resmas[i][j] << " ";
		}
		cout << endl << endl;
	}
	return res;
}