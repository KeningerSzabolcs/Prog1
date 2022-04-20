#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <list>


struct Item
{
	std::string name;
	int iid;
	double value;
	 void print(std::ostream& out) {
        out << name << " " << iid << " " << value << std::endl;
    }
};

struct comp
{
	bool operator()(const Item& left,const Item& right)
	{
		return left.name < right.name;
	}
};

int main()
{

	std::vector<Item> vi;
	std::ifstream in("ints.txt");
	for(int i=0;i<10;i++)
	{
		std::string a;
		int b;
		double c;
		in>>a>>b>>c;
		vi.push_back({a,b,c});
	}

	for(Item i:vi)
        i.print(std::cout);
	sort(vi.begin(),vi.end(),comp());
	std::cout<<"sorted by name: \n";
	for(Item i:vi)
        i.print(std::cout);
	sort(vi.begin(),vi.end(),[](Item left,Item right){return left.value > right.value;});
    std::cout << "Sorted by value:\n";
	for(Item i:vi)
        i.print(std::cout);
	sort(vi.begin(),vi.end(),[](Item left,Item right){return left.iid < right.iid;});
		std::cout<<"sorted by iid: \n";

	for(Item i:vi)
        i.print(std::cout);

	vi.push_back({"horse shoe",99,12.34});
	vi.push_back({"Canon s400",9988,499.95});

	for (auto i = vi.begin(); i != vi.end(); i++)
	 {
        if ((*i).name == "alma" || (*i).name == "korte" ) 
        {
            vi.erase(i);
        }
    }
    std::cout << "After erasing alma and korte:\n";
    for (Item i:vi) 
        i.print(std::cout);
    for (auto i = vi.begin(); i != vi.end(); i++) 
    {
        if ((*i).iid == 2 ) 
        {
            vi.erase(i);
        }
    }
    std::cout << "After erasing elements with iid of 2:\n";
    for (Item i:vi) 
        i.print(std::cout);

    std::list<Item> v;
    std::ifstream in("ints.txt");
	for(int i=0;i<10;i++)
	{
		std::string a;
		int b;
		double c;
		in>>a>>b>>c;
		vi.push_back({a,b,c});
	}
	for(Item i:v)
        i.print(std::cout);
	sort(v.begin(),v.end(),comp());
	std::cout<<"sorted by name: \n";
	for(Item i:v)
        i.print(std::cout);
	sort(v.begin(),v.end(),[](Item left,Item right){return left.value > right.value;});
		std::cout<<"sorted by value: \n";
	for(Item i:v)
        i.print(std::cout);
	sort(v.begin(),v.end(),[](Item left,Item right){return left.iid < right.iid;});
		std::cout<<"sorted by iid: \n";

	for(Item i:v)
        i.print(std::cout);
	v.push_back({"horse shoe",99,12.34});
	v.push_back({"Canon s400",9988,499.95});

	for(auto i = v.begin();i != v.end();i++)
	{
		if((*i).name == "alma" || (i*).name == "korte")
		{
			i = v.erase(i);
			i--;
		}
	}

	std::cout<<"After erasing alma and korte:\n";

	for(Item i:v)
        i.print(std::cout);
	 for (auto i = v.begin(); i != v.end(); i++) 
	 {
        if ((*i).iid == 2 ) 
        {
            i = v.erase(i);
            i--;
        }
    }
    std::cout << "After erasing elements with iid of 2:\n";
    for (Item i:v) 
        i.print(std::cout);




}