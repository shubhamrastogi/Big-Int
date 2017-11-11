//-----------------HEADER FILES---------------------
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

//----------------CLASS-----------------------------
class bint
{
vector<int> data;
int count1;
int sign;                                            // 1 for -ve numbers
public:	
//--------------------------------------------------
bint()
{
	data.push_back(0);
	count1=1;
	sign=0;
}
//--------------------------------------------------
friend istream &operator>>(istream &a,bint &bi)
{
	/*char i;
	loop:
	i=getch();
	if(i==' '||i=='\n')
	return a;
	bi.data.push_back((int)(i-0));
	bi.count1++;
	goto loop;*/
	string s;
	cin>>s;
	int n=s.size();
	bi.data.resize(0);
	bi.count1=0;
	for(int i=n-1;i>=0;i--)
	{
		if(i==0&&s[i]=='-')
		{
			bi.sign=1;
			break;
		}
		bi.data.push_back((int)(s[i]-0)-48);
		bi.count1++;
		}	
		return a;
}
//-------------------------------------------------
friend ostream &operator<<(ostream &a,bint &bi)
{
	int i;
	if(bi.sign==1)
	cout<<"-";
	for(i=bi.count1-1;i>=0;i--)
	a<<bi.data[i];
	a<<endl;
	return a;
}
//--------------------------------------------------
bint operator+(bint b1);
bint operator++();
bint operator++(int a);
bint operator-(bint b1);
bint operator*(bint b1);
bint operator/(bint b1);
bint operator%(bint b1);
bint operator=(string s);
int operator<(bint b1);
int operator>(bint b1);
int operator==(bint b1);
int operator<=(bint b1);
int operator>=(bint b1);
int operator!=(bint b1);
bint operator+=(bint b1);
bint operator-=(bint b1);
bint operator*=(bint b1);
bint operator/=(bint b1);
bint operator%=(bint b1);
//-----------TYPE_CASTING---------------------------
operator int()
{
	int i,a=0;
	i=(count1>9?8:count1-1);
	cout<<i<<"\n";
	for(;i>=0;i--)
	{
		//cout<<data[i]<<" ";
		a=(a*10+data[i]);
	}
	//cout<<a;
	if(sign==1)
	return -a;
	return a;
}
//--------------------------------------
operator long long int()
{
	long long int i,a=0;
	i=(count1>18?17:count1-1);
	cout<<i<<"\n";
	for(;i>=0;i--)
	{
		//cout<<data[i]<<" ";
		a=(a*10+data[i]);
	}
	//cout<<a;
	if(sign==1)
	return -a;
	return a;
}
//--------------------------------------
operator long int()
{
	long int i,a=0;
	i=(count1>10?9:count1-1);
	cout<<i<<"\n";
	for(;i>=0;i--)
	{
		//cout<<data[i]<<" ";
		a=(a*10+data[i]);
	}
	//cout<<a;
	if(sign==1)
	return -a;
	return a;
}
//--------------------------------------
operator char()
{
	int a= *this;
	char b=a;
	return b;
}
//--------------------------------------
operator float()
{
	long long a= *this;
	float b=a;
	return b;
}
//--------------------------------------
operator double()
{
    long long a= *this;
	double b=a;
	return b;	
}
//--------------------------------------
operator long double()
{
	long long a= *this;
	long double b=a;
	return b;
}
//-----------END_OF_CLASS---------------
};
//-----------LOGICAL_OPERATORS----------
int bint::operator<(bint b1)
{
	int i;
	if(sign==b1.sign&&sign==0)
	{
		if(count1>b1.count1)
		return 0;
		if(count1<b1.count1)
		return 1;
		for(i=count1-1;i>=0;i--)
		{
			if(data[i]>b1.data[i])
			return 0;
			if(data[i]<b1.data[i])
			return 1;
		}
		if(data[0]==b1.data[0])
		return 0;
		return 1;
	}
	else
	if(sign==b1.sign&&sign==1)
	{
		if(count1>b1.count1)
		return 1;
		if(count1<b1.count1)
		return 0;
		for(i=count1-1;i>=0;i--)
		{
			if(data[i]<b1.data[i])
			return 0;
			if(data[i]>b1.data[i])
			return 1;
		}
		if(data[0]==b1.data[0])
		return 0;
		return 1;
	}
	else
	{
		return sign;
	}
}
//--------------------------------------
int bint::operator>(bint b1)
{
	int i;
	if(sign==b1.sign&&sign==1)
	{
		if(count1>b1.count1)
		return 0;
		if(count1<b1.count1)
		return 1;
		for(i=count1-1;i>=0;i--)
		{
			if(data[i]>b1.data[i])
			return 0;
			if(data[i]<b1.data[i])
			return 1;
		}
		if(data[0]==b1.data[0])
		return 0;
		return 1;
	}
	else
	if(sign==b1.sign&&sign==0)
	{
		if(count1>b1.count1)
		return 1;
		if(count1<b1.count1)
		return 0;
		for(i=count1-1;i>=0;i--)
		{
			if(data[i]<b1.data[i])
			return 0;
			if(data[i]>b1.data[i])
			return 1;
		}
		if(data[0]==b1.data[0])
		return 0;
		return 1;
	}
	else
	{
		return b1.sign;
	}
}
//--------------------------------------
int bint::operator==(bint b1)
{
	int i;
	if(sign!=b1.sign)
	return 0;
	if(count1!=b1.count1)
	return 0;
	for(i=count1-1;i>=0;i--)
		{
			if(data[i]!=b1.data[i])
			return 0;
		}
	return 1;	
}
//--------------------------------------
int bint::operator!=(bint b1)
{
	if(*this==b1)
	return 0;
	return 1;
}
//======================================
int bint::operator<=(bint b1)
{
	if(*this<b1 || *this==b1)
	return 1;
	return 0;
}
//--------------------------------------
int bint::operator>=(bint b1)
{
	if(*this>b1 || *this==b1)
	return 1;
	return 0;
}
//-----------ARITHMETIC_OPERATORS-------
bint bint::operator+(bint b1)
{
	bint b;
	int n,x,c=0,i,m;
	b.data.resize(0);
	b.count1=0;
	if(sign==b1.sign)
   {
   	b.sign=sign;
	n=max(count1,b1.count1);
	m=min(count1,b1.count1);
	for(i=0;i<m;i++)
	{
		x=data[i]+b1.data[i]+c;
		if(x>9)
		{
			c=x/10;
			x=x%10;
		}
		else
		c=0;
		b.data.push_back(x);
		b.count1++;
		}
		if(m!=n)
		while(i<n)
		{
			if(n==count1)
			{
			   x=data[i++]+c;
		     if(x>9)
		     {
			   c=x/10;
			   x=x%10;
		     }
		     else
		     c=0;
		    b.data.push_back(x);
		    b.count1++;	
			}
		    else
		    {
			x=b1.data[i++]+c;
		    if(x>9)
		    {
			  c=x/10;
			  x=x%10;
		    }
		    else
		    c=0;
		    b.data.push_back(x);
		    b.count1++;
		    }
		}
		if(c!=0)
		{
			b.data.push_back(c);
		b.count1++;
		}
		//cout<<b;
   }
   else
   {
   	
   }
		return b;
}
//--------------------------------------
bint bint:: operator++()
{
	bint b;
	b="1";
	*this=b+ *this;
	return *this;
}
//--------------------------------------
bint bint::operator++(int a)
{
	bint b1,b2;
	b1="1";
	b2=*this;
	*this=b1+ *this;
	return b2;
}

//--------------------------------------
bint bint::operator-(bint b1)
{
	bint b;
	if(sign!=b1.sign)
	{
		if(b1.sign==1)
		b1.sign=0;
		else 
		b1.sign=1;
		//cout<<"vvvvvvvvvvvvv";
		b= *this+b1;
	}
	else
	{
		//cout<< (*this >b1);
	  if(*this>b1 && sign==0)
	  {
	  	int i,j;
	  	b= *this;
	  	for(i=0,j=0;i<b1.count1;i++,j++)
	  	{
	  		if(b.data[j]<b1.data[i])
	  		{
	  			b.data[j+1]--;
	  			b.data[j]+=10;
			  }
	  		b.data[j]-=b1.data[i];
		  } 
	  }
	  else
	  if(*this<b1 && sign==0)
	  {
	  	int i,j;
	  	b= b1;
	  	for(i=0,j=0;i<count1;i++,j++)
	  	{
	  		if(b.data[j]<data[i])
	  		{
	  			b.data[j+1]--;
	  			b.data[j]+=10;
			  }
	  		b.data[j]-=data[i];
		  }
		  b.sign=1;
	  }
	  else
	  if(*this<b1 && sign==1)
	  {
	  	int i,j;
	  	b= *this;
	  	for(i=0,j=0;i<b1.count1;i++,j++)
	  	{
	  		if(b.data[j]<b1.data[i])
	  		{
	  			b.data[j+1]--;
	  			b.data[j]+=10;
			  }
	  		b.data[j]-=b1.data[i];
		  } 
	  }
	  else
	  {
	  	int i,j;
	  	b= b1;
	  	for(i=0,j=0;i<count1;i++,j++)
	  	{
	  		if(b.data[j]<data[i])
	  		{
	  			b.data[j+1]--;
	  			b.data[j]+=10;
			  }
	  		b.data[j]-=data[i];
		  }
		  b.sign=0;
	  }
	  int i;
	  for(i=b.count1-1;i>=0&&b.data[i]==0;i--);
	  i=b.count1 -i -1;
	  if(i==b.count1)
	  b.count1=1;
	  else
	  b.count1-=i;
	  b.data.resize(b.count1);	
	}
	return b;
}
//--------------------------------------
/*bint bint::operator--()
{
	bint b;
	b="-1";
	*this=b+ *this;
	return *this;
}
//--------------------------------------
bint bint::operator--(int a)
{
	bint b1,b2;
	b1="-1";
	b2=*this;
	*this=b1+ *this;
	return b2;
}
*/

//--------------------------------------
bint bint::operator*(bint b1)
{
	bint b,c;
	string s;
	int i,j,d=0,x,k;
	for(i=0;i<count1;i++)
	{
			for(k=0;k<i;k++)
			{
				c.data.push_back(0);
				c.count1++;
			}
		for(j=0;j<b1.count1;j++)
		{
			x=data[i]*b1.data[j]+d;
			if(x>9)
			{
				d=x/10;
				x%=10;
			}
			else
			d=0;
			c.data.push_back(x);
			c.count1++;
		}
		if(d!=0)
		{
			c.data.push_back(d);
			c.count1++;
			d=0;
		}
		c.data.erase(c.data.begin());
	    c.count1--;
		b=b+c;
	//	cout<<c<<"\n";
		c="0";
	}
	if(sign==b1.sign)
	b.sign=0;
	else
	b.sign=1;
	
	return b;
}
//--------------------------------------
bint bint::operator/(bint b1)
{
	bint b,b2,q;
	int x;
	b2= *this-b;
	//cout<<b2<<q;
	while(b2>=b1)
	{
		q++;
		b=b+b1;
		b2= *this-b;
	//	cout<<b2<<b;	
    }
    return q;
}
//--------------------------------------
bint bint::operator%(bint b1)
{
	bint b,b2,q;
	int x;
	b2= *this-b;
	//cout<<b2<<q;
	while(b2>=b1)
	{
		q++;
		b=b+b1;
		b2= *this-b;
	//	cout<<b2<<b;	
    }
    return b2;
}
//---------SHORT-HANDS------------------
bint bint::operator+=(bint b1)
{
	*this = *this + b1;
	return (*this);
}
//--------------------------------------
bint bint::operator-=(bint b1)
{
	*this = *this - b1;
	return (*this );
}
//--------------------------------------
bint bint::operator*=(bint b1)
{
	*this = *this * b1;
	return (*this );
}
//--------------------------------------
bint bint::operator/=(bint b1)
{
	*this = *this / b1;
	return (*this );
}
//--------------------------------------
bint bint::operator%=(bint b1)
{
	*this = *this % b1;
	return (*this );
}
//---------PARAMETRISED_CONSTRUCTOR-----
bint bint::operator=(string s)
{
	/*bint b;
	b.data.resize(0);
	b.data=b1.data;
	b.count1=b1.count1;
	return b;*/
	//bint bi;
	int n=s.size();
	data.resize(0);
	count1=0;
	for(int i=n-1;i>=0;i--)
	{
		if(i==0&&s[i]=='-')
		{
			sign=1;
			break;
		}
		data.push_back((int)(s[i]-0)-48);
		count1++;
		}
		//cout<<bi;	
		return *this;
}
//--------------------------------------
/*int bint::operator int()
{
	int i,a=0;
	for(i=count1>9?9:count1;i>=0;i--)
	{
		a+=a*10+data[i];
	}
	cout<<a;
	if(sign==1)
	return -a;
	return a;
}*/
//--------------------MAIN--------------
int main()
{
	bint b1,b2,b3;
	long long int a,b;
	cin>>b1>>b2;
	//cout<<b1;
	//b1+=b2;
	//a=(long long int)b1;
//	b=1234567891;
	//b=b2;
	//b3="-11111111111111111111111111111111111";
	//cin>>b3;
	//b2=++b3;
	//b3=b1-b2;
	//cout<<(b1-b2);//<<" ";/*
	b3=b1+b2;
	cout<<b3;
}
