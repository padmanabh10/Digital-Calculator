#include<iostream>
using namespace std;

class calc
{
	public:
		float total;
		char op[10];
		float t[11];
		void getdata();
		void display();
		
};
void calc::getdata()
{
	int i;
	char op[10];
	float t[11];
	cout<<"Enter an expression :";
	cin>>t[0];
	for(i=0;i<10;i++)
	{
		if(op[i]!='e')
		{
			cin>>op[i];
			if(op[i]!='e')
			{
				break;
			}
			cin>>t[i+1];
		}
		else
		{
			break;
		}
		
	}
	
	
}
void calc::display()
{
	int i;
	char op[10];
	float t[11];
	for(i=0;i<10;i++)
	{
		cout<<t[i];
		cout<<op[i];
	}
}
int main()
{
	calc c;
	c.getdata();
	c.display();
}
