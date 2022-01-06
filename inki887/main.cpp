#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;
//Boris Dimoski INKI887
//Zadaca 47
//Programa za kodiranje i dekodiranje na vnesen string so cetiri cifren broj
//Primeri:
//@mpgq▲Bgkmqig▲GLIG665    -    6688
//Rtcmvkegp"rtqgmv"rq"uvtwmvwtktcpq"rtqitcoktcplg    -    3267
//Moldo^j^↔w^↔hlafo^kgb↔f↔abhlafo^kgb↔k^↔pqofkd     -       7778

//funkcii za kodiranje i dekodiranje
string koder(string a, int b)
{
    int i;
//for jamka za menuvanje na vrednosta na sekoj karakter
    for(i=0;i<a.size();i++)
    {
        a[i]=a[i]+b;
    }
    cout<<"====================================================================="<<endl;
    cout<<"Kodirano: "<<a;
    cout<<"\n====================================================================="<<endl;
    return a;
}
string dekoder(string a, int b)
{
    int i;
//for jamka za vranjkanje na vrednosta na kakrakterite
    for(i=0;i<a.size();i++)
    {
        a[i]=a[i]-b;
    }
    cout<<"====================================================================="<<endl;
    cout<<"Dekodirano: "<<a;
    cout<<"\n====================================================================="<<endl;
    return a;
}
int main()
{
    string odg,broj,str;
    int a=0,b=0,c,d=0,x=9,y,loop=0,v=0,i,g=0,r;
    cout<<"Dali sakas da go kodiras ili dekodiras vneseniot string\n a -kodiraj \n b -dekodiraj"<<endl;
    //while jamka za proverka na tocno vnesen odgovor
    while(a==0)
    {
//izbor na kodiranje ili dekodiranje
        cin>>odg;
        if(odg[0]=='a') {a=1;b=0;}
        else
        if(odg[0]=='b'){a=1;b=1;}
        if(odg[0]!='a' && odg[0]!='b') {cout<<"Nevalidno, vnesi a ili b:"<<endl;}
    }
    cout<<"Vnesi cetiri cifren, pozitiven broj, 0000 ne e dozvoleno"<<endl;
//while jamka za proverka na tocno vnesen broj
    while(d==0)
    {
       cin>>broj;
       cin.ignore(1,'\n');
        if(broj.size()>4 || broj.size()<4 || broj=="0000" || isalpha(broj[0]) || isalpha(broj[1]) || isalpha(broj[2]) || isalpha(broj[3]) || ispunct(broj[0]) || ispunct(broj[1]) || ispunct(broj[2]) || ispunct(broj[3]))
        {cout<<"Nevaliden broj, vnesi pak:"<<endl;}
        else d=1;
    }
//pretvoranje na brojot od string vo interger
    c=stoi(broj);
//naojganje na najmala cifra vo brojot
    while(c!=0)
    {
        if(c%10<x) x=c%10;
        c/=10;
    }
//odzemanje na brojot na cifri so najmalata cifra
    y=4-x;
    //koga izborot e kodiranje
    if(b==0)
    {
    cout<<"Vnesi string so maksimum 600 karakteri, koristenje na znaci ne e dozvoleno"<<endl;
//while jamka za moznost na povtorno vnesuvanje pri nevaliden vnes
    while(g==0)
    {
    getline(cin,str);
    r=str.size();
//for jamka so if uslov za proverka dali stringot ima znaci ili e nad 600 karakterti
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
//koga izborot e dekodiranje
    if(b==1)
    {
        cout<<"Vnesi string so maksimum 600 karakteri"<<endl;
        //while jamka za moznost na povtorno vnesuvanje na string
       while(g==0)
    {
    getline(cin,str);
    r=str.size();
//if uslov za proverka dali stringot ima nad 600 karakteri
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

