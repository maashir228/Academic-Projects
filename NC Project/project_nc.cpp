#include<iostream>
#include<queue>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
const double Pi=3.14159265;

double SecantMethod(double *P, double *F, int i)
{
    double P_i= P[i-1] - (F[i-1]*(P[i-1]-P[i-2]))/(F[i-1]-F[i-2]);
    return P_i; 
}

double FunctionValue_2(double P)
{
    // Change your function according to question here.
    double FunctionValue=cos(P)-P;
    return FunctionValue;
}

double FunctionValue_3(double P)
{
    // Change your function according to question here.
    double FunctionValue=pow(P,2) - 6;
    return FunctionValue;
}

double FunctionValue_4(double P)
{
    // Change your function according to question here.
    double FunctionValue= - pow(P, 3) - cos(P);
    return FunctionValue;
}

double FunctionValue_6(double P)
{
    // Change your function according to question here.
    double x=P-1;
    double FunctionValue= log(x) ;
    FunctionValue+= cos(x);
    return FunctionValue;
}

void SecantMethodMain()
{
    cout<<"NOTE: Change the function according to quetion in the code first.\nIf done, you may continue.";
    int n;
    cout<<"Enter the number of polynomial you want to find.\n";
    cin>>n;                                         
    double *FunctionValue= new double(n);           
    double *Polynomial= new double(n+1);            

    cout<<"Enter Value of first and second Polynomials.\n";
    cin>>Polynomial[0]>>Polynomial[1];              
    int c;
        cout<<"Enter c corresponding to the case.\n";
        cout<<endl<<"2. cos(x) - x"<<endl<<"3. x^2 - 6"<<endl<<"4. -x^3 - cos(x)"<<endl<<"6. ln(x − 1) + cos(x − 1) "<<endl;
        cin>>c;
    
    for (int i = 2; i <= n; i++)
    {        
        switch(c)
        {
            case 2:
                FunctionValue[i-2]=FunctionValue_2(Polynomial[i-2]);
                FunctionValue[i-1]=FunctionValue_2(Polynomial[i-1]);
            break;
            case 3:
                FunctionValue[i-2]=FunctionValue_3(Polynomial[i-2]);
                FunctionValue[i-1]=FunctionValue_3(Polynomial[i-1]);
            break;
            case 4:
                FunctionValue[i-2]=FunctionValue_4(Polynomial[i-2]);
                FunctionValue[i-1]=FunctionValue_4(Polynomial[i-1]);
            break;
            case 6:
                FunctionValue[i-2]=FunctionValue_6(Polynomial[i-2]);
                FunctionValue[i-1]=FunctionValue_6(Polynomial[i-1]);   
            break;
            default:
                cout<<"Wrong function chosen. Ending !";
                return ;
            break;
        }

        Polynomial[i]=SecantMethod(Polynomial, FunctionValue, i);
    }
    for (int i = 0; i <= n; i++)
    {
        cout<<"Polynomial Value for "<<i<<" is "<< Polynomial[i]<<"\t";
        if(i!=n)
        cout<<"Function Value for Polynomial Of "<<i<<" is "<<FunctionValue[i];
        cout<<endl;
    }
    
    return ;
}
void jacabiiteration(){
int n;
cout<<endl<<"How many equations you want to enter:"; cin>>n;
float **array,*ans;
array= new float*[n];
ans=new float[n];

for (int i = 0; i < n; i++)
{
    array[i]= new float[n+1];  
}
for(int i=0;i<n;i++){
cout<<endl<<"Enter "<<n<<" coefficents of variables and constant of equation no."<<i+1<<endl;	
	for(int j=0;j<n+1;j++){
	cin>>array[i][j];
	}	
	}
	float tmp;
for(int i=0;i<n;i++){
tmp=array[i][i];
ans[i]=0;
	for(int j=0;j<n+1;j++){
array[i][j]=array[i][j]/tmp;		
	}
}
queue<float> q;
int itrtn;
cout<<endl<<"enter Number of iterations:"; cin>>itrtn;
for(int k=0;k<itrtn;k++){
for(int i=0;i<n;i++){
tmp=array[i][n];
	for(int j=0;j<n;j++){
		if(i!=j){
float x=array[i][j]*ans[j];
//cout<<"x:"<<x;
tmp=tmp-x;	
//cout<<"tmp:"<<tmp;	
	}
	}
q.push(tmp);
}
int i=0;
while(!q.empty()){
	ans[i]=q.front();
	q.pop();
	cout<<endl<<"value of x"<<i+1<<" on "<<k+1<<" iteration:"<<ans[i];
	i++;
}
}
}
int dy_diff(float h,float y0, float y1)
{
   int x1,x;
    x = (y1-y0);
    x1 = x/h ;
   return x1;
}

int backward_diff(int size1,float x[],int size2, float y[])
{
   if(size1<2 || size2<2 )
   {
      cout << "\n x and y must have 2 values or more";
   }
   
    if(size1 != size2)
    {
      cout << "\n x and y must have same size";
    }
    
    int i;
    float hx;
    float dy[size1];
    for(i=0; i<size1; i++)
    {
      if(i==size1-1)
      {
         hx = x[i] - x[i-1];
         dy[i] = dy_diff(-hx, y[i], y[i-1]);
       }
      else
       {
          hx = x[i+1] - x[i];
          dy[i] = dy_diff(hx, y[i], y[i+1]);
       }
     }
     cout << "ANSWER: " <<  dy[size1-1];
}
void humnamain(){
	int size1,size2;
   cout << "\n enter size of array x: ";
   cin >>  size1;
   cout << "\n enter size of array y: ";
   cin >>  size2;
   float x[size1];
   float y[size2];
   cout << "\nenter values for array x: ";
   for(int i=0;i<size1;i++)
   {
      cin>> x[i];
      cout<<endl;
   }
   cout << "\nenter values for array y: ";
   for (int j=0;j<size2;j++)
   {
      cin>> y[j];
      cout<< endl;
   }
   cout << "\n applying backward difference: ";
   backward_diff(size1, x, size1, y);
}
int main(){
	int ch; char op='y';
while(op == 'y'){
	cout<<endl<<"1.Secant mehod"<<endl<<"2.Backward difference"<<endl<<"3.Jacobi iteration method"<<endl<<"Select one:";
	cin>>ch;

	switch(ch){
case 1:
	SecantMethodMain();
break;
case 2:
	humnamain();
break;
case 3:	
    jacabiiteration();
    break;
  default:
  cout<<"\nwrong choice";
  break;  
}
cout<<endl<<"do you want to try another method(y/n):"; cin>>op;
system("cls");
}
}
