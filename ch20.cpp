#include <iostream>
#include <vector>
#include <list> 
#include <algorithm>


template<typename Iter1, typename Iter2>
 // requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
 Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2)
 {
 	for(;f1!=e1;f1++)
 	{
 		*f2=*f1;
 		f2++;
 	}
 	return f2;
 }


int main()
{

int array[]={0,1,2,3,4,5,6,7,8,9};
std::vector<int> vector ={0,1,2,3,4,5,6,7,8,9};
std::list<int> list ={0,1,2,3,4,5,6,7,8,9};

int array2[10];

for(int i =0;i<10;i++)
{
	array2[i]=array[i];
}

std::vector<int> vector2(vector);
std::list<int> list2(list);

	for (int& i:array) 
        i += 2;
    for (int& i: vector) 
        i+= 3;
    for (int& i:list)
        i+= 5;

copy(array, array + 10, vector.begin());
copy(list.begin(), list.end(), array);

if(std::find(vector.begin(),vector.end(),3) != vector.end());
{
	for(int i = 0;i<vector.size();i++)
	{
		if(vector[i]==3)
		{
			std::cout<<i<<std::endl;
			break;
		}
		else
{
	std::cout<<"3 not found"<<std::endl;

}
	}


}

if(std::find(list.begin(),list.end(),27)!= list.end())
{
	int id = 0;
	for(int i: list)
	{
		if(i==27)
		{
			std::cout<<id<<std::endl;
			break;
		}
	}id++;
}
else
{
	std::cout<<"27 not found"<<std::endl;
}
}