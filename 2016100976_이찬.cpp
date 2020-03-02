#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CMatrix {
private:
	string name;
	float** matrix;
	int nRow;
	int nCol;
	int nElement;
public:
	CMatrix() : name(""), nRow(0), nCol(0), nElement(0) {}
	CMatrix(string _name, int _nRow, int _nCol) :
		name(_name), nRow(_nRow), nCol(_nCol), nElement(_nRow* _nCol) {
		cout << "행렬을 할당합니다." << endl;
	}
	CMatrix(const CMatrix& m1) :
		name(m1.name), matrix(m1.matrix), nRow(m1.nRow), nCol(m1.nCol), nElement(m1.nElement) {
		matrix = new float* [nRow];
		for (int i = 0; i < nRow; i++) {
			matrix[i] = new float[nCol];
		}

		for (int i = 0; i < nRow; i++) {
			for (int j = 0; j < nCol; j++) {
				matrix[i][j] = m1.matrix[i][j];
			}
		}
	}

	~CMatrix() {
		cout << "행렬을 삭제합니다." << endl;
		for (int i = 0; i < nRow; i++)
			delete matrix[i];
		delete[] matrix;
	}

	void setElement() {
		matrix = new float* [nRow];
		for (int i = 0; i < nRow; i++)
			matrix[i] = new float[nCol];

		for (int i = 0; i < nRow; i++) {
			for (int j = 0; j < nCol; j++) {
				cin >> matrix[i][j];
			}
		}
	}

	void printMatrixInfo() {
		cout << "행렬의 이름 : " << this->getName() << endl;
		cout << "행 : " << nRow << endl;
		cout << "열 : " << nCol << endl;
		cout << "요소의 총 수 : " << nElement << endl;
		cout << "행렬 : " << endl << endl;
		for (int i = 0; i < nRow; i++) {
			for (int j = 0; j < nCol; j++) {
				cout << matrix[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl << endl;
	}

	string getName() const { return name; }

	CMatrix operator+(const CMatrix& mat) {
		CMatrix result(*this);
		if (!(nRow == mat.nRow && nCol == mat.nCol))
			throw result;
		result.name = result.name + " + " + mat.name;
		for (int i = 0; i < result.nRow; i++) {
			for (int j = 0; j < result.nCol; j++) {
				result.matrix[i][j] += mat.matrix[i][j];
			}
		}
		cout << "+완료" << endl;
		return result;
	}
	CMatrix operator-(const CMatrix& mat) {
		CMatrix result(*this);
		result.name = result.name + " - " + mat.name;
		for (int i = 0; i < result.nRow; i++) {
			for (int j = 0; j < result.nCol; j++) {
				result.matrix[i][j] -= mat.matrix[i][j];
			}
		}
		cout << "-완료" << endl;

		return result;
	}

	CMatrix operator*(const CMatrix& mat) {
		CMatrix result(*this);
		for (int i = 0; i < nRow; i++) {
			for (int j = 0; j < result.nCol; j++) {
				float sum = 0;
				for (int k = 0; k < result.nCol; k++) {
					sum += this->matrix[i][k] * mat.matrix[k][j];
				}
				result.matrix[i][j] = sum;
			}
		}
		cout << "*완료" << endl;

		return result;

	}
	bool operator==(const CMatrix& mat2) {
		if (nRow != mat2.nRow || nCol != mat2.nCol) {
			return false;
		}
		else {
			for (int i = 0; i < nRow; i++) {
				for (int j = 0; j < nCol; j++) {
					if (matrix[i][j] != mat2.matrix[i][j])
						return false;
				}
			}
			return true;
		}

	}

};

void getData(string& name, int& nRow, int& nCol) {
	cout << "행렬의 이름, 행, 열을 입력하세요 : ";
	cin >> name >> nRow >> nCol;
}

int main() {
	string name;
	int nRow, nCol;
	cout << endl << "<1st Matrix>" << endl;
	getData(name, nRow, nCol);
	CMatrix m1(name, nRow, nCol);
	m1.setElement();
	m1.printMatrixInfo();

	cout << endl << "2st Matrix>" << endl;
	getData(name, nRow, nCol);
	CMatrix m2(name, nRow, nCol);
	m2.setElement();
	m2.printMatrixInfo();

	cout << endl << "<Results>" << endl;

	try {
		CMatrix m3 = m1 + m2;
		m3.printMatrixInfo();

		CMatrix m4 = m1 - m2;
		m4.printMatrixInfo();

		CMatrix m5 = m1 * m2;
		m5.printMatrixInfo();
	}
	catch (CMatrix m3) {
		cout << "못해~" << endl;
	}

	CMatrix m6 = m1 * m2;
	m6.printMatrixInfo();
	

	if (m1 == m2) { cout << "the matrices are equal" << endl; }
	else {
		cout << "the matrices are unequal" << endl;
	}
}