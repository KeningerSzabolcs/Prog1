#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
	public:
		Person(){}
		Person(string f,string l,int a) : f{f},l{l},a{a}{
			if(a<0 || a>=150){
				throw runtime_error("invalid age in Person");
			}
			for(int i = 0;l.length();i++)
			{
				if(l[i] == ';',':','*','[',']','&')
				{
					//throw runtime_error("invalid character in Person");
				}	break;
			}

		};
		string first() const {return f;}
		string last() const {return l;}
		int age() const {return a;}

	private:
		string f;
		string l;
		int a;



};
ostream& operator <<(ostream& os, Person& p )
{
	return os <<p.first() <<" "<<p.last() <<" " <<p.age();
}

istream& operator >>(istream& is , Person& p)
{
	string f; 
	string l;
	int a ;

	is>>f>>l>>a;
	p = Person(f, l, a);

	return is;
}



int main()
{

Person p = Person("Goofy","a", 63);
//cout<<p.name<<" "<<p.age<<endl;
cout<<p<<endl;
Person p2;
cin>>p2;
cout<<p2<<endl;

vector<Person> vec;
for(Person p;cin >> p;)
{
	if(p.first() == "end" || p.last() == "end")break;
	vec.push_back(p);
}

for(Person p: vec)
	cout<< p << endl;


return 0;
}