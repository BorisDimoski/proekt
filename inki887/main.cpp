#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;
//Boris Dimoski INKI887
//Programa za kodiranje i dekodiranje na vnesen string so cetiri cifren broj
//Primeri:
//@mpgq▲Bgkmqig▲GLIG665    -    6688
//Rtcmvkegp"rtqgmv"rq"uvtwmvwtktcpq"rtqitcoktcplg    -    3267
//Moldo^j^↔w^↔hlafo^kgb↔f↔abhlafo^kgb↔k^↔pqofkd     -       7778
string koder(string a, int b)
{
    int i;
    for(i=0;i<a.size();i++)
    {
        a[i]=a[i]+b;
    }
    cout<<"Kodirano: "<<a;
    return a;
}
string dekoder(string a, int b)
{
    int i;
    for(i=0;i<a.size();i++)
    {
        a[i]=a[i]-b;
    }
    cout<<"Dekodirano: "<<a;
    return a;
}
int main()
{
    string odg,broj,str;
    int a=0,b=0,c,d=0,x=9,y,loop=0,v=0,i,g=0,r;
    cout<<"Dali sakas da kodiras ili dekodiras vneseniot string string\n a -kodiraj \n b -dekodiraj"<<endl;
    while(a==0)
    {
        cin>>odg;
        if(odg[0]=='a') {a=1;b=0;}
        else
        if(odg[0]=='b'){a=1;b=1;}
        if(odg[0]!='a' && odg[0]!='b') {cout<<"Nevalidno, vnesi a ili b:"<<endl;}
    }
    cout<<"Vnesi cetiri cifren, pozitiven broj, 0000 ne e dozvoleno"<<endl;
    while(d==0)
    {
       cin>>broj;
       cin.ignore(1,'\n');
        if(broj.size()>4 || broj.size()<4 || broj=="0000" || isalpha(broj[0]) || isalpha(broj[1]) || isalpha(broj[2]) || isalpha(broj[3]) || ispunct(broj[0]) || ispunct(broj[1]) || ispunct(broj[2]) || ispunct(broj[3]))
        {cout<<"Nevaliden broj, vnesi pak:"<<endl;}
        else d=1;
    }
    c=stoi(broj);
    while(c!=0)
    {
        if(c%10<x) x=c%10;
        c/=10;
    }
    y=4-x;
    if(b==0)
    {
    cout<<"Vnesi string so maksimum 600 karakteri, koristenje na znaci ne e dozvoleno"<<endl;
    while(g==0)
    {
    getline(cin,str);
    r=str.size();
    for(i=0;i<r;i++)
    {
        if(ispunct(str[i]) || (r>600))
        {
            cout<<"Stringot ima znaci ili ima nad 600 karakteri, vnesi nov string"<<endl;
            g=0;
            break;
        }
        else
        {
        g=1;
        }
    }
    }
        str=koder(str,y);

    }

    if(b==1)
    {
        cout<<"Vnesi string so maksimum 600 karakteri"<<endl;
       while(g==0)
    {
    getline(cin,str);
    r=str.size();
    if(r>600)
        {
            cout<<"Stringot ima nad 600 karakateri, vnesi string povtorno"<<endl;
            g=0;
        }
    else g=1;
    }
        str=dekoder(str,y);
    }
    return 0;
}

