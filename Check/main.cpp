#include "Header.h"

Complex::Complex(int real = 0, int image = 0) {
		this->real = real;
		this->image = image;

	}
	ostream& operator <<(ostream& os, const Complex& other) {
		if (other.image >= 0) {
			os << other.real << "+" << other.image << "i";
		}
		else {
			os << other.real << other.image << "i";
		}
		return os;
	}
	Complex Complex::operator+(Complex& other) {
		Complex temp;
		temp.real = real + other.real;
		temp.image = image + other.image;
		return temp;
	}
	Complex Complex:: operator-(Complex& other) {
		Complex temp;
		temp.real = real - other.real;
		temp.image = image - other.image;
		return temp;
	}
	Complex Complex:: operator*(Complex& other) {
		Complex temp;
		temp.real = real * other.real;
		temp.image = image * other.image;
		return temp;
	}
	bool Complex::operator!=(Complex& other) {
		return !(real == other.real && image == other.image);
	}
	Complex::~Complex() {
		//cout << "dectructor" << endl;
	}
int main() {
	srand(time(0));
	getFile();
	for (int i = 1;i <= quantityFiles;i++) {
		ofstream ofs;
		string a{ "out" };
		string b{ ".txt" };
		string tempString = a + to_string(i);
		tempString.append(b);
		ofs.open(tempString, std::ofstream::out | std::ofstream::trunc);
		ofs.close();
	}
	ifstream file("input.txt", ios_base::out);
	vector<ComplexVector*> res;
	vector<CFabric*> fabric;
	fabric.push_back(new CFabric1);
	fabric.push_back(new CFabric2);
	string b;
	vector<string*> name;
	ComplexVector::Input(file, res, fabric, name);
	for (size_t i=0; i < res.size(); i++) {
		
		res[i]->print(*name[i]);
	}
	for (size_t i = 0; i < res.size(); ++i) delete res[i];
	for (size_t i = 0; i < name.size(); ++i) delete name[i];
	for (size_t i = 0; i < fabric.size(); ++i) delete fabric[i];
	test();
	file.close();
	return 0;
}