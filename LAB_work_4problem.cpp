#include<iostream>
using namespace std;
class person
{
	protected:
		string name;
		int age;
		string gender;
	public:
	void getdata()
	{
		cout<<"\n Enter name";
		cin>>name;
		cout<<"\n Enter gender";
		cin>>gender;
		cout<<"\n Enter age";
		cin>>age;
	}
	void setdata()
	{
		cout<<"\nName:"<<name;
		cout<<"\nGender:"<<gender;
		cout<<"\nAge:"<<age;
	}
};
class Employed_person:public person
{
	protected:
	string CNIC_number;
	public:
		void getdata()
		{
			cout<<"\n Enter Employ name";
			cin>>name;
			cout<<"\n Enter CNIC number";
			cin>>CNIC_number;
		}
		void setdata()
		{
			cout<<"\n Employ Name:"<<name;
			cout<<"\n CNIC number:"<<CNIC_number;
		}
	void employ()
	{
		cout<<"\nHi,I am employ from employed class";
	}
};
class unemployed:public person
{
	public:
		void getdata()
		{
			cout<<"\n Enter Unemployed name";
			cin>>name;
		}
		void setdata()
		{
			cout<<"\nUemployed name"<<name;
		}
		unemployed()
		{
			cout<<"\nHi,I am Unemploy from Unemployed class";
		}
};
class Businessman:Employed_person
{
	public:
		void getdata()
		{
			cout<<"\n Enter Businessman CNIC number";
			cin>>CNIC_number;
		}
		void setdata()
		{
			cout<<"\n Businessman CNIC number:"<<CNIC_number<<endl;
			employ();
	    }
	    void display_function()
	    {
	    	cout<<"\n This class has no his attribute";
		}
};
int main()
{
	unemployed b;
	Businessman a;
	a.getdata();
	a.setdata();
	a.display_function();
}