#include "Header.h"
ostream& operator<<(ostream& os, const ComplexVector1& vector) {
	for (const Complex& element : vector.elems) {
		os << element << ";";
	}
	os << endl;
	return os;
}
ComplexVector* ComplexVector1:: operator+(ComplexVector& other) {
	vector<Complex> result;
	for (int i = 0;i < elems.size();i++) {
		result.push_back(elems[i] + other.elems[i]);
	}
	ComplexVector* num = new ComplexVector1(result);
	return num;
}
ComplexVector* ComplexVector1:: operator-(ComplexVector& other) {
	vector<Complex> result;
	for (int i = 0;i < elems.size();i++) {
		result.push_back(elems[i] - other.elems[i]);
	}
	ComplexVector* num = new ComplexVector1(result);
	return num;
}
ComplexVector1 ComplexVector1:: operator*(ComplexVector1& other) {
	vector<Complex> result;
	for (int i = 0;i < elems.size();i++) {
		result.push_back(elems[i] * other.elems[i]);
	}

	return ComplexVector1(result);
}
bool ComplexVector1:: operator==(ComplexVector& other) {
	for (int i = 0; i < elems.size(); i++) {
		if (elems[i] != other.elems[i]) {
			return false;
		}
	}

	return true;
}
bool ComplexVector1:: operator==(ComplexVector1& other) {
	for (int i = 0; i < elems.size(); i++) {
		if (elems[i] != other.elems[i]) {
			return false;
		}
	}

	return true;
}
void ComplexVector1::print(string a) {
	ofstream file(a, ios_base::app);
	if (file.is_open()) {
		file << "1 " << endl;
		for (int i = 0;i < len;i++) {
			
			file  << elems[i] << ";" << endl;
		}
		file << "--------" << endl;
	}
	else {
		cout << "File error" << endl;
	}
	file.close();
}
ComplexVector1::~ComplexVector1() {}
ostream& operator<<(ostream& os, const ComplexVector2& vector) {
	for (const Complex& element : vector.elems) {
		os << element << ";";
	}
	os << endl;
	return os;
}
ComplexVector* ComplexVector2:: operator+(ComplexVector& other) {
	vector<Complex> result;
	for (int i = 0;i < elems.size();i++) {
		result.push_back(elems[i] + other.elems[i]);
	}
	ComplexVector* num = new ComplexVector2(result);
	return num;
}
ComplexVector* ComplexVector2:: operator-(ComplexVector& other) {
	vector<Complex> result;
	for (int i = 0;i < elems.size();i++) {
		result.push_back(elems[i] - other.elems[i]);
	}
	ComplexVector* num = new ComplexVector2(result);
	return num;
}
ComplexVector2 ComplexVector2:: operator*(ComplexVector2& other) {
	vector<Complex> result;
	for (int i = 0;i < elems.size();i++) {
		result.push_back(elems[i] * other.elems[i]);
	}

	return ComplexVector2(result);
}
bool ComplexVector2:: operator==(ComplexVector& other) {
	for (int i = 0; i < elems.size(); i++) {
		if (elems[i] != other.elems[i]) {
			return false;
		}
	}

	return true;
}
void ComplexVector2::print(string a) {
	ofstream file(a, ios_base::app);
	if (file.is_open()) {
		file << "2 ";
		for (int i = 0;i < len;i++) {
			
			file << elems[i] << ";" << " ";
		}
		file << endl;
		file << "-------" << endl;
	}
	else {
		cout << "File error" << endl;
	}
	file.close();
}
ComplexVector2::~ComplexVector2() {}