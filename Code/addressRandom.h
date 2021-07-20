#include"iostream"
#include"sstream"
#include<string>
using namespace std;
string ipRandom()
{
    string ip="";
    
    for(int i=0;i<4;i++)
    {
        int x = rand()%256;
        string converter;
        stringstream ss;
        ss<<x;
        ss>>converter;
        if(i==3)
        {
            ip+=converter;
        }
        else
        {
           ip+=converter+"."; 
        }
    }
    return ip;
}
string macRandom()
{
    string mac="";
    char alphabet[16] = {'A','B','C','D','E','F','0','1','2','3','4','5',
                            '6','7','8','9'};

    for (int i = 0; i <16; i++) 
    {
        if(i%3 == 2)
            mac += ":";
        else
        {
           mac = mac + alphabet[rand() % 16]; 
        }        
    } 
    return mac;
}
