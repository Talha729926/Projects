#include<iostream>
using namespace std;
class PersonData
{
	protected:
		string first_name;
		string last_name;
		string address;
	public:
			void getdata()
			{
				cout<<"Enter first name"<<endl;
				cin>>first_name;
				cout<<"Enter last name"<<endl;
				cin>>last_name;
				cout<<"Enter address"<<endl;
				cin>>address;
			}
			void setdata()
			{
				cout<<"\n Name:"<<first_name<<" "<<last_name<<endl;
				cout<<"Address"<<address<<endl;
			}
};
class CustomerData:public PersonData
{
	int customer_number;
	bool mailing_list;
	public:
	void getdata()
	{
		cout<<"\nEnter Customer number"<<endl;
		cin>>customer_number;
		cout<<"\nEnter mailing list"<<endl;
		cin>>mailing_list;
	}
	void setdata()
	{
      int a;
      cout<<"enter 1 if you want to be in mailing list and any other if not ";
      cin >> a;
      if(a==1) 
       {
         mailing_list= true;
    
       }
      else 
       {
         mailing_list= false;
       }
		cout<<"\nCustomer number:"<<customer_number<<endl;
		cout<<"Mailing list"<<mailing_list<<endl;
	}
	void input_customer_data()
	{
	cout<<"Enter customer first name"<<endl;
	cin>>first_name;
	cout<<"\n Enter coustomer last name"<<endl;
	cin>>last_name;
	cout<<"\n Enter customer address"<<endl;
	cin>>address;
	cout<<"\n Enter customer number"<<endl;
	cin>>customer_number;
	}
	void get_customer_data()
	{
		cout<<"\nCustomer name:"<<first_name<<" "<<last_name;
		cout<<"\n Customer address :"<<address;
		cout<<"\n Customer number :"<<customer_number<<endl;
	}
};
int main()
{
	CustomerData a;
	a.input_customer_data();
	a.get_customer_data();
	a.setdata();
	return (0);
}