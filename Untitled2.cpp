#include <iostream>
#include<string>
#include<cmath>
using namespace std;
class calc{
	public:
		float total;
		void getdata();
		void display();
		
		
};

void calc::getdata()
{
	float t1,nt;
	int i;
	char opchoice;
	cout<<"Enter an Expression";
	cin>>t1;
	total=t1;
	for(i=0;i<10;i++)
	{
		cin>>opchoice;
		switch(opchoice){
			case '+':{
				cin>>nt;
				total=total+nt;
				continue;
			}
			case '-':{
				cin>>nt;
				total=total-nt;
				continue;
			}
			case '*':{
				cin>>nt;
				total=total*nt;
				continue;
			}
			case '/':{
				cin>>nt;
				total=total/nt;
				continue;
			}
			case 'A':{
				
				break;
			}
		break;
		}
	break;
	}
	
}
void calc::display()
{
	cout<<"Result="<<total;
}
int main()
{
	calc c;
	c.getdata();
	c.display();
}

