#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <math.h>
#include <typeinfo>
using namespace std;
const int len = 3;
const int N = 1000;
const int quantityFiles = 11;
#define eps 1e-20
void test();
class CFabric;
class Complex {
protected:
	int real;
	int image;
public:
	Complex(int real, int image);
	friend ostream& operator <<(ostream& os, const Complex& other);
	Complex operator+(Complex& other);
	Complex operator-(Complex& other);
	Complex operator*(Complex& other);
	bool operator!=(Complex& other);
	~Complex();

};
class ComplexVector {
	friend class ComplexVector1;
	friend class ComplexVector2;
public:
	vector<Complex> elems;
	ComplexVector(){}
	ComplexVector(vector<Complex> elems);
	Complex& operator[](int index);
	friend ostream& operator<<(ostream& os, const ComplexVector& vector);
	virtual ComplexVector* operator+(ComplexVector& other)=0;
	virtual ComplexVector* operator-(ComplexVector& other)=0;
	//ComplexVector operator*(ComplexVector& other);
	static int Input(ifstream& filename, vector<ComplexVector*>& res, vector<CFabric*>& fabric, vector<string*>& name);
	virtual ~ComplexVector();
	virtual void print(string a) {}
	bool operator==(ComplexVector& other);
};
class ComplexVector1 : public ComplexVector{
public:
	ComplexVector1():ComplexVector(){}
	ComplexVector1(vector<Complex> elems) : ComplexVector(elems){}
	ComplexVector* operator-(ComplexVector& other);
	ComplexVector* operator+(ComplexVector& other);
	ComplexVector1 operator*(ComplexVector1& other);
	friend ostream& operator<<(ostream& os, const ComplexVector1& vector);
	void print(string a);
	bool operator==(ComplexVector& other);
	bool operator==(ComplexVector1& other);
	~ComplexVector1();
};
class ComplexVector2 : public ComplexVector{
public:
	ComplexVector2():ComplexVector(){}
	ComplexVector2(vector<Complex> elems) : ComplexVector(elems) {}
	ComplexVector* operator-(ComplexVector& other);
	ComplexVector* operator+(ComplexVector& other);
	ComplexVector2 operator*(ComplexVector2& other);
	friend ostream& operator<<(ostream& os, const ComplexVector2& vector);
	void print(string a);
	bool operator==(ComplexVector& other);
	~ComplexVector2();
};
class CFabric
{
public:
	virtual ComplexVector* Create(vector<Complex> arr) = 0;
	virtual ~CFabric() {};
};

class CFabric1 : public CFabric
{
public:
	virtual ComplexVector* Create(vector<Complex> arr) { return new ComplexVector1(arr); }
};

class CFabric2 : public CFabric
{
public:
	virtual ComplexVector* Create(vector<Complex> arr) { return new ComplexVector2(arr); }
};

void getFile();

