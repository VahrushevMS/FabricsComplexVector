#include "Header.h"
ComplexVector::ComplexVector(vector<Complex> elems) {
	this->elems = elems;
}
ostream& operator<<(ostream& os, const ComplexVector& vector) {
	for (const Complex& element : vector.elems) {
		os << element << " ; ";
	}
	return os;
}

bool ComplexVector:: operator==(ComplexVector& other) {
	for (int i = 0; i < elems.size(); i++) {
		if (elems[i] != other.elems[i]) {
			return false;
		}
	}

	return true;
}

int ComplexVector::Input(ifstream& filename, vector<ComplexVector*>& res, vector<CFabric*>& fabric, vector<string*> &name) {
    for (int i = 0; i < N; i++) {
        int a;
        string b;
        filename >> b;
        filename >> a;
        name.push_back(new string(b));
        if (a == 1) {
            vector<int> elems;
            vector<Complex> arr;
            for (int j = 0; j < 2 * len; j += 2) {
                int a, b;
                filename >> a >> b;
                elems.push_back(a);
                elems.push_back(b);
                Complex num(elems[j], elems[j + 1]);
                arr.push_back(num);
            }
            ComplexVector* num = fabric[0]->Create(arr);
            res.push_back(num);
        }
        else {
            vector<int> elems;
            vector<Complex> arr;
            for (int j = 0; j < 2 * len; j += 2) {
                int a, b;
                filename >> a >> b;
                elems.push_back(a);
                elems.push_back(b);
                Complex num(elems[j], elems[j + 1]);
                arr.push_back(num);
            }
            ComplexVector* num = fabric[1]->Create(arr);
            res.push_back(num);
        }
    }
    return 0;
}

Complex& ComplexVector::operator[](int index) {
	if (index < 0 || index >= elems.size()) {
		std::cerr << "Index out of range!" << std::endl;
		exit(1);
	}
	return elems[index];
}



ComplexVector:: ~ComplexVector() {
	//cout << "virtual dectructor";
}