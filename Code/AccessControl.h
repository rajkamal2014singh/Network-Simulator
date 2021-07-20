#include"iostream"
#include"cmath"
using namespace std;
int token = 0;
void accessControl(int deviceID,int endDeviceID)
{
    cout<<"\n .....Token Passing.....\n";
    while(token != deviceID)
    {
        cout<<"\nPassing token from PC"<<token<<" to -> PC"<<(token+1)%endDeviceID;
        token++;
        token = token%endDeviceID;
    }
}