#include <iostream>
#define swap(a, b) \
    {              \
        a += b;    \
        b = a - b; \
        a -= b;    \
    }
using namespace std;


struct adad{                                   // alamat va meghdar adad voroodi
	int alamat;
	char* number=new char[1000];
};



int tool_int(int* a){                         // tedad ragham araye intigeri    
	int i=0;
	while(a[i]!=-11){
		i++;
	}
	return i;
}


void rahat(char* &a, char n){                // dar halati ke + vared nashode va ragham aval bayad dar araye gharar begirad
	
	
	char* b=new char[1000];
	int i=0;
	while(a[i]!='\0'){
		b[i+1]=a[i];
		i++;
	
	}
	b[0]=n;
	b[i+1]='\0';
	delete[] a;
	a=b;
	
	
}

int moghayese(int* a , int* b){                        // a bozorgtar= 0    b bozorgtar=  1     else 2
    if(tool_int(a)==tool_int(b)){
    	int i=0;                                      // moghayese voroodi ha
	while(a[i]!=-11 || b[i]!=-11){
		if(a[i]>b[i])
		return 0;
		
		if(a[i]<b[i])
		return 1;
		i++;
	}
    }
    else if(tool_int(a)>tool_int(b)){
    	return 0;
    }
    else if(tool_int(a)<tool_int(b)){
    	return 1;
    }
	return 2;
}





void makoos(int *a)                                // sar va tah kardan adad baraye asan sazi mohasebe
{
    int length = tool_int(a);
    for (int j = 0; j < length / 2; j++)
    {
        swap(a[j], a[length - j - 1]);
    }
}


void tabdil_char_int(char *a, int *b)            // tabdil reshte voroodi be araye int  baraye mohaseb
{                                                
    int j = 0;
    while (a[j] != '\0')
    {
        b[j] = (int)a[j] - 48;                  // 48  adad aski char '0'
        j++;
    }
    b[j] = -11;
}

void tabdil_int_char(char *a, int *b)          // tabdil hasel javab be halat reshte baraye chap
{
    int j = 0;
    while (b[j] != -11)
    {   
        a[j] = (char)b[j] + 48;               // 48  adad aski char '0'
        j++;
    }
    a[j] = '\0';
}

void enteghal(int *a, int *komaki, int shift)        // baraye shift dadan adad baad az zarb har ragham  
{
    int j = 0;
    while (a[j] != -11)
    {
        komaki[j] = a[j];
        j++;
    }
    for (int x = 0; x < shift; x++)
    {
        komaki[j + x] = 0;
    }
    komaki[j + shift] = -11;
}


void sum(int *a, int *b, int *c);                 // tabe jame

void minius(int *a, int *b, int *c);              // tabe menha

void zarb(int *a, int u);                        // tabe zarb har ragham dar adad digar

void sum_prime(int *a, int *b);                  // tabe jam konande maghadir zarb shode

void zarb_asli(int *a, int *b, int *c);          // tabe anjam dahande nahaii zarb

void dequeue(char* &queue);                      // eslah konande 0 posht adad dar gozar ha

int main()
{
	
    int *a = new int[1000];
    int *b = new int[1000];                    // 2 adad voroodi va hasel dar ghaleb araye az int
    int *c = new int[1000];

    char *c2 = new char[1000];                // khorooji dar ghaleb reshte  (reshte shodeye c)
 
    char amalyat;                            //  jam zarb ya menha
    cin >> amalyat;
    
    adad a2;
    char alamat;
    cin>>alamat;                                      // alamat adad
    if(alamat=='+'||(alamat>='0'&& alamat<='9')){                           // adad mosbat
    	a2.alamat=0;
    }
    else if(alamat=='-'){                                   // adad manfi
    	a2.alamat=1;
    }
    if(alamat>='0'&&alamat<='9'){                      // eslah adadi ke mosbat ast va ragham aval bayad bargardad
    	cin >> a2.number;
    	rahat(a2.number,alamat);
    }else{
    		cin >> a2.number;
    }
    tabdil_char_int(a2.number, a);                   // tabdil voroodi aval be int*


    adad b2;
    char alamat2;                                            
    cin>>alamat2;
    if(alamat2=='+'||(alamat2>='0'&& alamat2<='9')){
    	b2.alamat=0;
    }
    else if(alamat2=='-'){
    	b2.alamat=1;
    }

    if(alamat2>='0'&&alamat2<='9'){
    	cin >> b2.number;
    	rahat(b2.number,alamat2);
    }else{
    	cin >> b2.number;
    }
    tabdil_char_int(b2.number, b);
    
    int mogh=moghayese(a,b);                        // taiin inke voroodi aval bozorgtar ast ya dovomi  
    int test=0;
    if(mogh==1){                                   // flag baraye inke voroodi dovom bozorgtar ast
    	test=1;
    }
    
    if (amalyat == '+')                          // gharar ast voroodi ha jam shavand 
    {
    	if(a2.alamat==0 && b2.alamat==0){        // do adad mosbat
    	if(test==1)
    	sum(b, a, c);                            // agar adad dovom bozorgtar ast jaha avaz shavad
    	else
    	sum(a,b,c);
        tabdil_int_char(c2, c);
        if(c2[0]=='0')  
        dequeue(c2);                           // eslah 0 ghabl adad dar halat gozar 
        cout << c2;
    	}
        else if(a2.alamat==1 && b2.alamat==1){   // do adad manfi
       	if(test==1)
    	sum(b, a, c);
    	else
    	sum(a,b,c);
        tabdil_int_char(c2, c);
        if(c2[0]=='0')
        dequeue(c2);
        cout<<'-'<< c2;
        }
        else if(a2.alamat==0 && b2.alamat==1){          // avali + dovomi -
        if(test==1){
        	minius(b,a,c);
        	tabdil_int_char(c2, c);
        	if(c2[0]=='0')
        dequeue(c2);
        	 cout<<'-'<< c2;
        }
       	else{
       	minius(a,b,c);
    	tabdil_int_char(c2, c);
    	if(c2[0]=='0')
        dequeue(c2);
        cout << c2;
       	}
       	
        }
        else if(a2.alamat==1 && b2.alamat==0){          // avali - dovomi +
       	if(test==1){
       		minius(b,a,c);
       		tabdil_int_char(c2, c);
       		if(c2[0]=='0')
        dequeue(c2);
             cout<< c2;
       	}
       	else
       	minius(a,b,c);
    	tabdil_int_char(c2, c);
    	if(c2[0]=='0')
        dequeue(c2);
        cout<<'-'<< c2;
        }
        
    }
    else if (amalyat == '-')              // tafrigh do adad
    {    
    
    if(a2.alamat==0 && b2.alamat==0){      // har do +
    	if(test==1){
    		minius(b,a,c);
    		tabdil_int_char(c2, c);
    		if(c2[0]=='0')
        dequeue(c2);
        cout<<'-'<<c2;
    	}
       	
       	else{
       		minius(a,b,c);
    	tabdil_int_char(c2, c);
    	if(c2[0]=='0')
        dequeue(c2);
        cout<< c2;
       	}
       	
    	}
        else if(a2.alamat==1 && b2.alamat==1){    // har do -
       	if(test==1){
       		minius(b,a,c);
       		tabdil_int_char(c2, c);
       		if(c2[0]=='0')
        dequeue(c2);
            cout<< c2;
       	}
       	else{
		   minius(a,b,c);
       		tabdil_int_char(c2, c);
       		if(c2[0]=='0')
        dequeue(c2);
            cout<<'-'<< c2;
       	}
        }
        else if(a2.alamat==0 && b2.alamat==1){     // avali + dovomi -
        if(test==1)
       	sum(b,a,c);
       	else
       	sum(a,b,c);
    	tabdil_int_char(c2, c);
    	if(c2[0]=='0')
        dequeue(c2);
        cout << c2;
        }
        else if(a2.alamat==1 && b2.alamat==0){     // avali -  dovomi +
       	if(test==1)
       	sum(b,a,c);
       	else
       	sum(a,b,c);
    	tabdil_int_char(c2, c);
    	if(c2[0]=='0')
        dequeue(c2);
        cout<<'-'<< c2;
        }
    	
    }
    else if (amalyat == '*')    // zarb 
    {
    	
    	if(a2.alamat==0 && b2.alamat==0){           // har do +
    	zarb_asli(a, b, c);
        tabdil_int_char(c2, c);
        cout << c2;
    	}
        else if(a2.alamat==1 && b2.alamat==1){         // har do -
       	zarb_asli(a, b, c);
        tabdil_int_char(c2, c);
        cout << c2;
        }
        else if(a2.alamat==0 && b2.alamat==1){        // avali + dovomi -
       	zarb_asli(a, b, c);
        tabdil_int_char(c2, c);
        cout<<'-'<< c2;
        }
        else if(a2.alamat==1 && b2.alamat==0){         // avali -  dovomi +
       	zarb_asli(a, b, c);
        tabdil_int_char(c2, c);
        cout<<'-'<< c2;
        }
    }

delete[] a;
delete[] b;
delete[] c;
delete[] c2;
delete[] a2.number;
delete[] b2.number;

    return 0;
}

void sum(int *a, int *b, int *c)     // tabe jam
{

    makoos(a);                         // makoos karda adad baraye tashil mohasebe
    makoos(b);

    int j = 0;

    while (a[j] != -11 && b[j] != -11)
    {
        c[j] = a[j] + b[j];               // jam kardan ragham be ragham
        j++;
    }

    if (a[j] != -11)
    {
        while (a[j] != -11)
        {
            c[j] = a[j];               // ragham ezafe ke digari 0 darad
            j++;
        }
    }

    else
    {
        while (b[j] != -11)
        {
            c[j] = b[j];               // ragham ezafe ke digari 0 darad
            j++;
        }
    }

    c[j] = -11;

    for (int x = 0; x < j - 1; x++)
    {
        c[x + 1] = c[x + 1] + c[x] / 10;     // enteghal 1 ezafe be ragham baadi
        c[x] = c[x] % 10;
    }

    if (c[j - 1] > 9)
    {
        c[j] = c[j - 1] / 10;
        c[j - 1] = c[j - 1] % 10;             // ragham akhar agar do raghami shod 
        c[j + 1] = -11;
    }

    makoos(a);
    makoos(b);                                // adadha be halat asli barmigardan
    makoos(c);
}

void minius(int *a, int *b, int *c)         // tabe menha
{

    makoos(a);
    makoos(b);

    int j = 0;

    while (a[j] != -11 && b[j] != -11)
    {
        c[j] = a[j] - b[j];
        j++;
    }

    if (a[j] != -11)
    {
        while (a[j] != -11)
        {
            c[j] = a[j];
            j++;
        }
    }

    else
    {
        while (b[j] != -11)
        {
            c[j] = b[j];
            j++;
        }
    }

    c[j] = -11;

    for (int x = 0; x < j - 1; x++)
    {   if(c[x]<0){
    	c[x+1]-=1;                           // gharz gereftan az ragham baghal
    	c[x]+=10;
    	
    }
       
    }

    makoos(a);
    makoos(b);
    makoos(c);
    
}

void zarb(int *a, int u)              // zarb yek ragham dar kol yek adad
{
    int j = 0;
    makoos(a);
    while (a[j] != -11)
    {
        a[j] = a[j] * u;
        j++;
    }
    for (int x = 0; x < j - 1; x++)
    {
        a[x + 1] = a[x + 1] + a[x] / 10;
        a[x] = a[x] % 10;
    }
    if (a[j - 1] > 9)
    {
        a[j] = a[j - 1] / 10;
        a[j - 1] = a[j - 1] % 10;
        a[j + 1] = -11;
    }
    makoos(a);
}

void sum_prime(int *a, int *b)       // jam kardan maghadir zarbi 
{
    makoos(a);
    makoos(b);

    int j = 0;

    int *c = new int[1000];
    while (a[j] != -11 && b[j] != -11)
    {
        c[j] = a[j] + b[j];
        j++;
    }
    if (a[j] != -11)
    {
        while (a[j] != -11)
        {
            c[j] = a[j];
            j++;
        }
    }
    else
    {
        while (b[j] != -11)
        {
            c[j] = b[j];
            j++;
        }
    }
    c[j] = -11;
    for (int x = 0; x < j - 1; x++)
    {
        c[x + 1] += c[x] / 10;
        c[x] %= 10;
    }
    if (c[j - 1] > 9)
    {
        c[j] = c[j - 1] / 10;
        c[j - 1] %= 10;
        c[j + 1] = -11;
        j++;
    }
    makoos(a);
    makoos(b);
    makoos(c);
    for (;j >= 0;j--)
    {
        a[j] = c[j];
    }
}

void zarb_asli(int *a, int *b, int *c)          // majmooe hame karhaye zarb
{
    int n = tool_int(a);
    int *komaki = new int[1000];
    c[0] = 0;
    c[1] = -11;

    for (int j = 0; j < n; j++)
    {
        enteghal(b, komaki, j);
        zarb(komaki, a[n - 1 - j]);
        sum_prime(c, komaki);
    }
}

void dequeue(char* &queue){                    // eslah halat 0 posht adad 
	char* komaki=new char[1000];
	int i=0;
	while(queue[i]!='\0'){
	   komaki[i]=queue[i+1];
	   i++;
	}
	komaki[i]='\0';
	
	delete[] queue;
	queue=komaki;
		
}
