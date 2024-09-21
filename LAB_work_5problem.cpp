#include<iostream>
using namespace std;
class vechicle
{
protected:
 float speed;
 float distance;
public:
  void setspeed(float t)
      {
     	speed=t;
	  }	
	  void setspeed()
	  {
	  	cout<<"\n speed is:"<<speed;
	  }
	  void setdistance(float s)
	  {
	  distance=s;	
	  }
	  void getspeed()
	  {
	  	cout<<"\n speed is:"<<speed;
	  }
    
};
class wheelvehicle:public vechile
{
	private:
	    int wheels;
	public:
		void setwheels()
		{
			cout<<"\nEnter wheels number";
			cin>>wheels;
		}
		void getwheels()
		{
			cout<<"\nWheels:"<<wheels;
		}
};
class truck:public wheelvehicle
{
 float carrying_load;
 public:
 	void setload()
 	{
 		cout<<"\n Enter load";
 		cin>>carrying_load;
	 }
	 void getload()
	 {
	 	cout<<"\n load:"<<carrying_load;
	 }
};
class wingvehicle:public vechicle
{public:
	int wings;
	void setwings()
	{cout<<"\n Enter no.of wings";
	cin>> wings;
	}
	void getwings()
	{cout<<"\n no.of wings:"<<wings;}
	
};
int main()
{truck s;
wingvehicle d;
s.setwheels();
s.getwheels();
s.setload();
s.getload();
d.setspeed();
d.getspeed();
d.setwings();
d.getwings();
return (0);
}