#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
using namespace std;
using namespace Numeric_lib;
#include "include/Matrix.h"

int main()
try{

cout<<"sizeof: \n";
cout<< "char\t"<<sizeof(char)<<endl;
cout<< "short\t"<<sizeof(short)<<endl;
cout<< "int\t"<<sizeof(int)<<endl;
cout<< "double\t"<<sizeof(double)<<endl;
cout<< "long\t"<<sizeof(long)<<endl;
cout<< "float\t"<<sizeof(float)<<endl;
cout<< "int*\t"<<sizeof(int*)<<endl;
cout<< "double*\t"<<sizeof(double*)<<endl;

cout<<"\n Matrix sizes:\n";
Matrix<int> a(10);
Matrix<int> b(100);
Matrix<double> c(10);
Matrix<int, 2> d(10,10);
Matrix<int, 3> e(10,10,10);

cout<<"1D int, 10 elem\t\t" << sizeof(a)<<endl;
cout<<"1D int, 100 elem\t\t" << sizeof(b)<<endl;
cout<<"1D double, 10 elem\t\t" << sizeof(c)<<endl;
cout<<"2D int, 10x10 elem\t\t" << sizeof(d)<<endl;
cout<<"3D int, 10x10x10 elem\t\t" << sizeof(e)<<endl;

cout<<"\n Number of elements: \n";
cout<<"a:\t"<<a.size()<<"\n";
cout<<"b:\t"<<b.size()<<"\n";
cout<<"c:\t"<<c.size()<<"\n";
cout<<"d:\t"<<d.size()<<"\n";
cout<<"e:\t"<<e.size()<<"\n";

int i;
cout<<"enter ints"<<endl;
while(cin>>i)
{
	errno = 0;
	double d = sqrt(i);
	if(errno == EDOM)
		cout<<"no square root\n";
	else
		cout<<"sgrt("<<i<<") = "<<d<<'\n';
}
cin.clear();
cin.ignor();

cout<<"Enter 10 floats: "<<endl;
Matrix<double> m(10);
double d;
for(int i= 0;i<m.size();i++)
{
	cin>>d;
	if(!cin) throw runtime_error("Problems reading from cin");
	m[i] = d;
}
cout<<"Matrix: \n"<<m<<endl;

Matrix<complex<double>> m3(10);
cout<<"\nEnter 10 complex numbers(Re, im): ";
complex<double> comp;
for(i=0;i<10;i++)
{
	cin>>comp;
	if(!cin) throw run runtime_error("Problems with reading number!")
	m3[i]=comp;
}

cout<<m3;
complex<double> sum;
for(index i = 0;i<m.size();i++)
{
	sum += m3[i];

}
cout<<"sum: "<<sum<<endl;

Matrix<int, 2> m4(2,3);
cout<<"\nenter six ints: ";
int n;
for(int i= 0;i<m.dim1();i++)
{
	for(int j= 0;j<m.dim2();j++)
	{
		cin>>num;
		m4(i,j) = num;
	}
}
cout<<"Matrix: \n"<<m4<<endl;

}catch(exception& e)
{
	cerr<<"exception: "<<e.what()<<'\n';
}catch(...)
{
	cerr<<"exception!\n";
}