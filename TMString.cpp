#include<iostream>
#include<string.h> 
using namespace std;
class TMString
{
private:
char *ptr;
int size;
public:
TMString();
TMString(const char *ptr);
virtual ~TMString();
TMString & operator=(const TMString &other);
TMString & operator=(const char *ptr);
int operator<(const TMString &other);
int operator<=(const TMString &other);
int operator>(const TMString &other);
int operator>=(const TMString &other);
int operator==(const TMString &other);
int operator!=(const TMString &other);
void operator+=(const TMString &other);
TMString operator+(const TMString &other);
friend ostream & operator<<(ostream &out,TMString &tmString);
};
TMString::TMString()
{
this->ptr=NULL;
this->size=0;
}
TMString::TMString(const char *ptr)
{
this->ptr=NULL;
if(ptr==NULL) return;
this->size=strlen(ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,ptr);
}
TMString & TMString::operator=(const TMString &other)
{
if(this->ptr) delete [] this->ptr;
this->ptr=NULL;
this->size=0;
if(other.ptr==NULL) return *this;
this->size=strlen(other.ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,other.ptr);
return *this;
}
TMString & TMString::operator=(const char *ptr)
{
if(this->ptr) delete [] this->ptr;
this->ptr=NULL;
this->size=0;
if(ptr==NULL) return *this;
this->size=strlen(ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,ptr);
return *this;
}
TMString::~TMString()
{
if(this->ptr) delete [] this->ptr;
}
ostream & operator<<(ostream &out,TMString &tmString)
{
if(tmString.ptr==NULL) return out;
out<<tmString.ptr;
return out;
}
int TMString::operator<(const TMString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(this->ptr==NULL) return 1;
if(other.ptr==NULL) return 0;
return strcmp(this->ptr,other.ptr)<0;
}
int TMString::operator<=(const TMString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL) return 1;
if(other.ptr==NULL) return 0;
return strcmp(this->ptr,other.ptr)<=0;
}
int TMString::operator>(const TMString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(this->ptr==NULL) return 0;
if(other.ptr==NULL) return 1;
return strcmp(this->ptr,other.ptr)>0;
}
int TMString::operator>=(const TMString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL) return 0;
if(other.ptr==NULL) return 1;
return strcmp(this->ptr,other.ptr)>=0;
}
int TMString::operator==(const TMString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL) return 0;
if(other.ptr==NULL) return 0;
return strcmp(this->ptr,other.ptr)==0;
}
int TMString::operator!=(const TMString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(this->ptr==NULL) return 1;
if(other.ptr==NULL) return 1;
return strcmp(this->ptr,other.ptr)!=0;
}
void TMString::operator+=(const TMString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return;
if(other.ptr==NULL) return;
if(this->ptr==NULL)
{
(*this)=other;
return;
}
char *tmp=new char[this->size+other.size+1];
strcpy(tmp,this->ptr);
strcat(tmp,other.ptr);
delete [] this->ptr;
this->ptr=tmp;
this->size=this->size+other.size;
}
TMString TMString::operator+(const TMString &other)
{
TMString k;
if(this->ptr==NULL && other.ptr==NULL) return k;
if(this->ptr==NULL) k=other;
else if(other.ptr==NULL) k=(*this);
else
{
k=(*this);
k+=other;
}
return k;
}
int main()
{
/*TMString g="Cool";
cout<<g<<endl;
TMString m;
m="Very Cool";
cout<<m<<endl;
TMString k;
k=m;
cout<<k<<endl;
return 0;
*/
TMString a ="Cool";
TMString b="Bombay";
/*(testing operator function)
cout<<"a="<<a<<endl;
cout<<"b="<<b<<endl;
cout<<"(a<b)"<<(a<b)<<endl;
cout<<"(a>b)"<<(a>b)<<endl;
cout<<"(a<=b)"<<(a<=b)<<endl;
cout<<"(a>=b)"<<(a>=b)<<endl;
cout<<"(a==b)"<<(a==b)<<endl;
cout<<"(a!=b)"<<(a!=b)<<endl;
*/
/*(implementing +=)
a+=b;
cout<<a<<endl;
TMString c; 
c+=a;
cout<<c<<endl;
TMString d="Ujjain";
TMString e="Indore";
TMString f;
f=d+e;
cout<<d<<endl;
cout<<e<<endl;
cout<<f<<endl;
*/
//sortring concept,just for fun
TMString str[10];
str[0]="Zaheer";
str[1]="Suresh";
str[2]="Mahesh";
str[3]="Lokesh";
str[4]="Amit";
str[5]="Rohit";
str[6]="Sameer";
str[7]="Gopal";
str[8]="Rounak";
str[9]="Bobby";
int e,f,m;
m=8;
TMString g;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
if(str[f]<str[e])
{
g=str[e];
str[e]=str[f];
str[f]=g;
}
e++;
f++;
}
m--;
}
for(int i=0;i<=9;i++) cout<<str[i]<<endl;
return 0;
}
