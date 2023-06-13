#include<iostream>
#include<conio.h>

using namespace std;

void inputNumber(short int x[]);
void printNumber(short int x[]);
void reverseNumber(short int x[]);
int lengthNumber(short int x[]);
void addNumber(short int x[],short int y[],short int z[]);
void addNumber2(short int x[],short int y[]);
void mulNumber(short int x[],short int y[],short int z[]);
void multiply(short int d, short int x[]);
void shiftNumber(short int x[],short int r[], int s);

int main()
{
    short int x[1000],y[1000],z[1000];
    cout<<"Enter x:";
    inputNumber(x);
    cout<<"Enter y:";
    inputNumber(y);
//    addNumber(x,y,z);
//    cout<<"adding up x,y:\n";
//    printNumber(z);
    mulNumber(x,y,z);
    cout<<"x*y=\n";
    printNumber(z);
    return 0;
}

void inputNumber(short int x[])
{
    char ch=0;
    int i=0;
    while(ch!=13)
    {
        ch=getch();
        if((ch>='0')&&(ch<='9'))
        {
            x[i++]=ch-'0';
            cout<<ch;
        }
    }
    cout<<endl;
    x[i]=-1;
}

void printNumber(short int x[])
{
    int i=0;
    while(x[i]!=-1)
    {
        cout<<x[i++];
    }
}

void reverseNumber(short int x[])
{
    int n=lengthNumber(x);
    for(int i=0;i<n/2;i++)
        swap(x[i],x[n-i-1]);
}

int lengthNumber(short int x[])
{
    int i=0;
    while(x[i]!=-1)
        i++;
    return i;
}

void addNumber(short int x[],short int y[],short int z[])
{
    int i=0,j;
    reverseNumber(x);
    reverseNumber(y);
    while((x[i]!=-1)&&(y[i]!=-1))
    {
        z[i]=x[i]+y[i];
        i++;
    }
    if(x[i]!=-1)
    {
        while(x[i]!=-1)
        {
            z[i]=x[i];
            i++;
        }
    }
    else
    {
        while(y[i]!=-1)
        {
            z[i]=y[i];
            i++;
        }
    }
    z[i]=-1;
    for(j=0;j<i-1;j++)
    {
        z[j+1]+=z[j]/10;
        z[j]%=10;
    }
    if(z[i-1]>9)
    {
        z[i]=z[i-1]/10;
        z[i-1]%=10;
        z[i+1]=-1;
    }
    reverseNumber(x);
    reverseNumber(y);
    reverseNumber(z);
}

void mulNumber(short int x[],short int y[],short int z[])
{
    int n=lengthNumber(x);
    short int t[1000];
    z[0]=0;
    z[1]=-1;

    for(int i=0;i<n;i++)
    {
        shiftNumber(y,t,i);
        multiply(x[n-1-i],t);
        addNumber2(z,t);
    }
}

void multiply(short int d, short int x[])
{
    int i=0;
    reverseNumber(x);
    while(x[i]!=-1)
    {
        x[i++]*=d;
    }
    for(int j=0;j<i-1;j++)
    {
        x[j+1]+=x[j]/10;
        x[j]%=10;
    }
    if(x[i-1]>9)
    {
        x[i]=x[i-1]/10;
        x[i-1]%=10;
        x[i+1]=-1;
    }
    reverseNumber(x);
}

void shiftNumber(short int x[],short int r[], int s)
{
    int i=0;
    while(x[i]!=-1)
    {
        r[i]=x[i];
        i++;
    }
    for(int j=0;j<s;j++)
    {
        r[i+j]=0;
    }
    r[i+s]=-1;
}

void addNumber2(short int x[],short int y[])
{
    int i=0,j;
    reverseNumber(x);
    reverseNumber(y);
    short int z[1000];
    while((x[i]!=-1)&&(y[i]!=-1))
    {
        z[i]=x[i]+y[i];
        i++;
    }
    if(x[i]!=-1)
    {
        while(x[i]!=-1)
        {
            z[i]=x[i];
            i++;
        }
    }
    else
    {
        while(y[i]!=-1)
        {
            z[i]=y[i];
            i++;
        }
    }
    z[i]=-1;
    for(j=0;j<i-1;j++)
    {
        z[j+1]+=z[j]/10;
        z[j]%=10;
    }
    if(z[i-1]>9)
    {
        z[i]=z[i-1]/10;
        z[i-1]%=10;
        z[i+1]=-1;
        i++;
    }
    reverseNumber(x);
    reverseNumber(y);
    reverseNumber(z);
    while(i>=0)
    {
        x[i]=z[i];
        i--;
    }
}
