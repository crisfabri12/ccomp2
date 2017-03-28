#include <iostream>
#include <string.h>
using namespace std;

bool Bisiesto(int a)
{
    if(a % 4 == 0 &&(a % 100 != 0 || a % 400 == 0))
    {
        cout<<"Es Bisiesto"<<endl;
        return true;
    }
    cout<<"No es Bisiesto"<<endl;
    return false;

}

int Semana(int m,int dia,int anio)
{

int regular[] = {0,3,3,6,1,4,6,2,5,0,3,5};
int bisiesto[]={0,3,4,0,2,5,0,3,6,1,4,6};
if(Bisiesto(anio)){

   m=bisiesto[m-1];
}

m=regular[m-1];

int result1=(anio-1)%7;
int result2=(anio-1)/4;
int result3=(3*(((anio-1)/100)+1))/4;
int result4=(result2-result3)%7;
int result5=dia%7;
dia=(result1+result4+m+result5)%7;

switch(dia)
    {
    case 0:
        cout<<"Domingo"<<endl;
        return 0;
    case 1:
        cout<<"Lunes"<<endl;
        return 1;
    case 2:
        cout<<"Martes"<<endl;
        return 2;
    case 3:
        cout<<"Miercoles"<<endl;
        return 3;
    case 4:
        cout<<"Jueves"<<endl;
        return 4;
    case 5:
         cout<<"Viernes"<<endl;
        return 5;
    case 6:
        cout<<"Sabado"<<endl;
        return 6;
    }


}

void mes(int m,int a)
{
    int max_dias;
    switch (m)
    {
    case 4:
    case 6:
    case 11:
        max_dias = 30;
    case 2:
        if(Bisiesto(a)){
            max_dias = 29;
        }
        max_dias = 28;
    default:
        max_dias = 31;
    }
    int s=Semana(m,1,a);
    int mess[5][7];
    int r=0;
    for(int i = 0;i<s;i++)
    {
        mess[0][i] = 0;
        ++r;
    }
    int j = 0;
    int cont=s;
    for(int i=1;i<=max_dias;i++)
    {
        if(cont==7)
        {
            cout<<"\n";
            ++j;
            s = 0;
            cont=0;
        }
        mess[j][s] = i;
        ++s;
        ++cont;

    }
    cout<<"d  l  m  x  j  v  s"<<"\n";
    j = 0;
    cont =0;
    s= 0;
    for(int i=0;i<max_dias+r;i++)
    {
        if(cont==7)
        {
            cout<<"\n";
            ++j;
            s = 0;
            cont = 0;
        }
        cout<<mess[j][s]<<"  ";
        ++cont;
        ++s;
    }
}

bool Billetes(double billete)
{
    double s[11] = {200,100,50,20,10,50,2,1,0.50,0.20,0.1};
    int temp;
    for(int i=0;i<11;i++)
    {
        if(billete>0){
            cout<<billete<<s[i]<<"\n";
            temp = billete / s[i];
            cout<<temp<<endl;
            cout<<"Hay "<<temp<<" billetes de "<<s[i]<<"\n"<<endl;
            billete = billete-(temp*s[i]);
        }
    }
}

int main()
{
//    int a;
//    int d,m;
//    cout<<"Ingrese un anio: ";
//    cin>>a;
//    cout<<"Ingrese un dia: ";
//    cin>>d;
//    cout<<"Ingrese un mes: ";
//    cin>>m;
//    Bisiesto(a);
//    Semana(m,d,a);
//    mes(m,a);
    double billete;
    cout<<"Ingrese un Billete: ";
    cin>>billete;
    cout<<"\n";
    cout<<0.1/0.1;
    Billetes(billete);
}
