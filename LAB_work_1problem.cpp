#include<iostream>
using namespace std;
	class faculty
	{
	string first_name;
	string last_name;
	int course_count;
	int telephone_number;
	protected:
		int age;
	public:
		void getdata()
		{
			cout<<"Enter faculty member first name \n";
			cin>>first_name;
			cout<<"Enter faculty member last name \n";
			cin>>last_name;
			cout<<"Enter course count\n";
			cin>>course_count;
			cout<<"Enter telephone number \n";
			cin>>telephone_number;
			cout<<"Enter faculty member age \n";
			cin>>age;
		}
		void setdata()
		{
			cout<<"faculty member name :"<<first_name;
			cout<<" "<<last_name<<endl;
			cout<<"faculty member age:"<<age<<endl;
			cout<<"course count:"<<course_count<<endl;
			cout<<"telephone number :"<<telephone_number<<endl;
		}
	};
	class student
	{
		string first_name;
		string last_name;
		protected:
			int age;
		public:
			void getdata()
			{
			 cout<<"Enter student first name \n";
			 cin>>first_name;
			 cout<<"Enter student last name\n";
			 cin>>last_name;
			 cout<<"Enter Student age \n";
			 cin>>age;
			}
			void setdata()
			{
		     cout<<"Student name :"<<first_name;
			 cout<<" "<<last_name<<endl;
			 cout<<"Student age:"<<age<<endl;
			}
			
	};
	class undergraduate:public student
	{
		string fyp_name;
		public:
			float cgpa;
		void getdata()
		{
			cout<<"Enter student fyp name"<<endl;
			cin>>fyp_name;
			cout<<"Enter cgpa"<<endl;
			cin>>cgpa;
		}
		void setdata()
		{
			cout<<"\nFyp name:"<<fyp_name;
			cout<<"\ncgpa:"<<cgpa<<endl;
		}
	};
	class graduate:public student
	{
	string thesis_topic;
	public:
	float cgpa;
	void getdata()
	{
		cout<<"Enter thesis topic \n";
		cin>>thesis_topic;
		cout<<"Enter cgpa \n";
		cin>>cgpa;
	}
	void setdata()
	{
		cout<<"Thesis topic:"<<thesis_topic<<endl;
		cout<<"CGPA:"<<cgpa;
	}
	};
		int main()
		{
			int x;
			faculty a;
			student b;
			undergraduate c;
			graduate d;
			cout<<"\nEnter 1 for undergraduation or Enter 2 for graduation\n";
			cin>>x;
			if(x==1)
			{
				a.getdata();
		    	b.getdata();
		    	c.getdata();
		    	a.setdata();
			    b.setdata();
		    	c.setdata();
	    	}
	    	else if(x==2)
	    	{
	    		a.getdata();
	    		b.getdata();
	    		d.getdata();
	    		a.setdata();
	    		b.setdata();
	    		d.setdata();
			}
			else
			cout<<"\nInvalid choice";
		    return (0);
		}