#include<iostream>
using namespace std;
class customerdata
{
	protected:
		string first_name;
		string last_name;
		string address;
	public:
		void getdata()
		{
			cout<<"\n Enter first Name\n";
			cin>>first_name;
			cout<<"\n Enter last name\n";
			cin>>last_name;
			cout<<"\n Enter address\n";
			cin>>address;
	    }
	    void setdata()
	    {
	    	cout<<"Customer name:"<<first_name<<" "<<last_name<<endl;
	    	cout<<"Address:"<<address<<endl;
		}
};
class preferred_customer:public customerdata
{
	    float purchase_amount;
    	float discount;
	public:
		void update_purchase_amount(float amount)
		{
			purchase_amount=purchase_amount+amount;
		    update_discount();
		    cout<<"\npurchase amount:"<<purchase_amount<<endl;
		    cout<<"\nDiscount:"<<discount;
		}
		void update_discount()
		{
			if(purchase_amount>=2000.0)
			{
			   cout<<"\ndiscount=10/100\n";
			}
			else if(purchase_amount>=1500.0)
			{
				cout<<"\ndiscount=7/100\n";
			}
			else if (purchase_amount>=1000.0)
			{
			    cout<<"\ndiscount=6/100\n";
		    }
		    else if (purchase_amount>=500.0)
		    {
		    	cout<<"\ndiscount=5/100\n";
			}
			else 
			{
				discount=0.0;
			}
		}
};
int main ()
{
	customerdata a;
	preferred_customer b;
	a.getdata();
	a.setdata();
	b.update_discount();
	b.update_purchase_amount(1600);
	return (0);
}