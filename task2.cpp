#include <iostream>
using namespace std;
class printable
{
	public:
	virtual void print ()=0;
};
class Document:public printable
{
	public:
    	void print ()
{
		cout<<"Printing Document\n";
	}
};
class Image:public printable
{
	public:
    	void print ()
{
		cout<<"Printing Image\n";
	}
	
};
int main ()
{
	Document d;
	Image i;
	d.print();
	i.print();
}