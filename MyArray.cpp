#include "MyArray.h"
Matrix::Matrix()
{
	this->rowN = 1;
	this->colN = 1;
	this->data = 0;
}
Matrix::Matrix(const int rN,const int cN)
{
	this->rowN = rN;
	this->colN = cN;
	data = new float[rN*cN];
	int x = 0;
	for (int i=0; i<rowN; i++)
	{
		for(int j=0; j<colN; j++)
		{
			this->data[i*colN + j] = 0;
		}
	}
}
Matrix::Matrix(const Matrix &srcMatrix)
{
	this->rowN = srcMatrix.rowN;
	this->colN = srcMatrix.colN;
	data = new float(rowN*colN);
	int len = rowN*colN;
	int i=0;
	while(i<len)
	{
		this->data[i] = srcMatrix.data[i];
		i++;
	}
}
Matrix::Matrix(const int rN, const int cN, float *srcPtr)
{
	this->rowN = rN;
	this->colN = cN;
	data = new float[rN*cN];
	for (int i=0; i<rowN; i++)
	{
		for(int j=0; j<colN; j++)
		{
			data[i*colN + j] = srcPtr[i*colN + j];
		}
	}	
}
const float* Matrix::getData()const
{
	float *temp = new float[rowN*colN];
	for (int i=0; i<rowN; i++)
	{
		for(int j=0; j<colN; j++)
		{
			temp[i*colN + j] = this->data[i*colN + j];
		}
	}
	return temp;
}
int Matrix::getRowN()const
{
	return this->rowN;
}

int Matrix::getColN()const
{
	return this->colN;
}
ostream& operator << (ostream &output, const Matrix & rhs)
{
	for (int i=0; i<rhs.rowN; i++)
	{
		for(int j=0; j<rhs.colN; j++)
		{
			output << rhs.data[i*rhs.colN + j] << " ";
		}
	}
	output << endl;
	return output;
}
void Matrix::print()const
{
	for (int i=0; i<rowN; i++)
	{
		for(int j=0; j<colN; j++)
		{
			cout << this->data[i*colN + j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
Matrix Matrix::transpose()
{
	int a = 0;
	float temp;
	Matrix m(colN, rowN);
	for (int i = 0; i < colN; ++i)
	{
    	for (int j = 0; j < rowN; ++j) 
	  	{
       		m.data[a] = data[j*colN + i];
       		a++;
      	}
	}
	return m;
}
Matrix Matrix::operator+(const Matrix &rhsMatrix)const
{
	Matrix temp(rowN,colN);
	if(rowN == rhsMatrix.rowN && colN == rhsMatrix.colN)
	{
		for (int i=0; i<rowN; i++)
		{
			for(int j=0; j<colN; j++)
			{
				temp.data[i*colN + j]= data[i*colN + j] + rhsMatrix[i*colN + j];
			}
		}
	}
	return temp;
}
Matrix Matrix::operator-(const Matrix &rhsMatrix)const
{
	Matrix temp(rowN,colN);
	if(rowN == rhsMatrix.rowN && colN == rhsMatrix.colN)
	{
		for (int i=0; i<rowN; i++)
		{
			for(int j=0; j<colN; j++)
			{
				temp.data[i*colN + j]= data[i*colN + j] - rhsMatrix[i*colN + j];
			}
		}
	}
	return temp;
}
Matrix Matrix::operator*(const Matrix &rhsMatrix)const
{
	Matrix temp(rowN,colN);
	if(rowN == rhsMatrix.rowN && colN == rhsMatrix.colN)
	{
		for (int i=0; i<rowN; i++)
		{
			for(int j=0; j<colN; j++)
			{
				temp.data[i*colN + j]= data[i*colN + j] * rhsMatrix[i*colN + j];
			}
		}
	}
	return temp;
}
float Matrix::operator()(const int r,const int c)const
{
	return data[r*colN + c];
}
float& Matrix::operator[](int ind)
{
	return data[ind];
}
float Matrix::operator[](int ind)const
{
	return data[ind];
}
Matrix& Matrix::operator=(const Matrix &rhsMatrix)
{
	this->rowN = rhsMatrix.rowN;
	this->colN = rhsMatrix.colN;
	data = new float[rowN*colN];
	for (int i=0; i<rowN; i++)
	{
		for(int j=0; j<colN; j++)
		{
			this->data[i*colN + j] = rhsMatrix.data[i*colN + j];
		}
	}
	return *this;
}
Matrix& Matrix::operator+=(const Matrix &rhsMatrix)
{
	for (int i=0; i<rowN; i++)
	{
		for(int j=0; j<colN; j++)
		{
			data[i*colN + j] +=  rhsMatrix[i*colN + j];
		}
	}
	return *this;
}
Matrix& Matrix::operator-=(const Matrix &rhsMatrix)
{
	for (int i=0; i<rowN; i++)
	{
		for(int j=0; j<colN; j++)
		{
			data[i*colN + j] -=  rhsMatrix[i*colN + j];
		}
	}
	return *this;
}
Matrix& Matrix::operator*=(const Matrix &rhsMatrix)
{
	for (int i=0; i<rowN; i++)
	{
		for(int j=0; j<colN; j++)
		{
			data[i*colN + j] *=  rhsMatrix[i*colN + j];
		}
	}
	return *this;
}
int Matrix::operator==(const Matrix &rhsMatrix)const
{
	int isSame = 0;
	if(rowN == rhsMatrix.rowN && colN == rhsMatrix.colN)
	{
		isSame = 1;
		for (int i=0; i<rowN; i++)
		{
			for(int j=0; j<colN; j++)
			{
				if(data[i*colN + j] != rhsMatrix[i*colN + j])
				{
					isSame = 0;
				}
			}
		}
	}
	return isSame;
}
int Matrix::operator!=(const Matrix &rhsMatrix)const
{
	int isDiff = 0;
	if(rowN != rhsMatrix.rowN || colN != rhsMatrix.colN)
	{
		isDiff = 1;	
	}
	else if (rowN == rhsMatrix.rowN && colN == rhsMatrix.colN)
	{
		for (int i=0; i<rowN; i++)
		{
			for(int j=0; j<colN; j++)
			{
				if(data[i*colN + j] != rhsMatrix[i*colN + j])
				{
					isDiff = 1;
				}
			}
		}
	}
	return isDiff;
}