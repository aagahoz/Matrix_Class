#include <iostream>
#include "MyArray.h"

int main() 
{
	Matrix m2(3,4);
	cout << " > Only Matrix with row and column" << endl;
	cout << m2 << endl;
	
	
	float array[] = {1.3,2.4,3.2,4.4,5.2,6.6,7.8,8.9,9.5,10.5,11.3,12.3,13.6,14.8,15.3};
	Matrix m3(3,5, array);
	cout << " > Default Matrix" << endl;
	m3.print();
	
	
	const float *data = m3.getData();
	cout << " > Printing Matrix using m3.getData() function" << endl;
	for (int i=0; i< m3.getColN()*m3.getRowN(); i++)
	{
		cout << data[i] << " ";
	}
	cout << endl << endl;
	
	
	cout << " > m3 Matrix have " << m3.getColN() << " column and " << m3.getRowN() << " row" << endl << endl;
	
	
	cout << " > Traspose of m3 matrix" << endl;
	Matrix m4;
	m4 = m3.transpose();
	m4.print();

	
	float array2[] = {4.5,2.2,3.5,5.2,6.6,7.6,8.4,4.3,2,4.2,5.5,6.2,78.3,9.3,3};
	Matrix m5(3,5, array2);
	cout << " > m5 Matrix" << endl;
	m5.print();
	m5 = m3 + m5;
	cout << " > Sum of m3 and m5 and assigning m5 Matrix" << endl;
	m5.print();
	
	
	m5 = m5 - m3;
	cout << " > Differences of m3 and m5 and assigning m5 Matrix" << endl;
	m5.print();
	
	float array3[] = {1.2,2.1,3.3,4.4,5.6,6.7};
	float array4[] = {6.7,5.6,4.4,3.3,2.1,1.2};
	Matrix m6(2,3,array3);
	Matrix m7(2,3,array4);
	cout << " m6 Matrix" << endl;
	m6.print();
	cout << " m7 Matrix" << endl;
	m7.print();
	cout << " > Multiplying m6 and m7 Matrixes and assigning to m6" << endl;
	m6 = m6*m7;
	m6.print();
	
	cout << " > Printing m6[1][2]" << endl;
	cout << m6(1,2) << endl << endl;
	
	cout << " > m6 += m7 and printing m6" << endl;
	m6 += m7;
	m6.print();
	
	float array5[] = {4,3,2,1,3,5};
	cout << "m8 Matrix" << endl;
	Matrix m8(2,3, array5);
	m8.print();
	cout << " > m6 -= m8 and printing m6" << endl;
	m6 -= m8;
	m6.print();
	
	
	cout << " > m6 *= m8 and printing m6" << endl;
	m6 *= m8;
	m6.print();
	
	
	float array6[] = {32, 36, 28, 14, 27, 10};
	Matrix m9(2,3, array6);
	cout << " m9 Matrix" << endl;
	m9.print();
	cout << " > m6 == m9 and printing m6" << endl;
	int state1 = (m6 == m9);
	cout << state1 << endl << endl;
	
	float array7[] = {2, 36, 14, 27, 10, 2};
	Matrix m10(2,3, array7);
	cout << " m10 Matrix" << endl;
	m10.print();
	cout << " > m6 != m10 and printing m6" << endl;
	int state2 = (m6 != m10);
	cout << state2 << endl << endl;
	
}	