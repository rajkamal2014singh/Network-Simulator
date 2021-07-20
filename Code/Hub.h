#include"iostream"
#include"sstream"
#include"vector"
#include"algorithm"
using namespace std;
static int hubDeviceId = 100;
class HDevice
{
public :
    int hubId;
    string displayName;
    vector<int> connectedToDevices;
};
class Hub
{
    HDevice hubInfo;
public: 
        Hub(){
        hubInfo.hubId = hubDeviceId;
        int temp = hubDeviceId-100;
        string converter;
        stringstream ss;
        ss<<temp;
        ss>>converter;
        hubInfo.displayName = "Hub"+converter;
        cout<<"\n .......Creating Hub.....\n";
        cout<<" Device Id : "<<hubInfo.hubId<<" .....Display Name : "<<hubInfo.displayName<<"\n\n";
        hubDeviceId++;
    }
    int getHubId(){ return hubInfo.hubId;}
    string getDisplayName()
    {
        return hubInfo.displayName;
    }
    void setConnection(int connectDevice,int endDeviceId,int hubDeviceId,int switchDeviceId, int bridgeDeviceId)
    {
         bool flag = 0;
        for(int i = 0;i<hubInfo.connectedToDevices.size();i++)
        {
            if(connectDevice == hubInfo.connectedToDevices.at(i))
                flag = 1;
        }
        if(flag == 0)
        {
            hubInfo.connectedToDevices.push_back(connectDevice);
            if(connectDevice<endDeviceId)
            {
                cout<<"\n .....Connection Established.....Between "<<hubInfo.displayName<<" and PC"<<connectDevice;
            }
            else if(connectDevice>=100 && connectDevice<hubDeviceId)
            {
                 cout<<"\n .....Connection Established.....Between "<<hubInfo.displayName<<" and Hub"<<connectDevice-100;
            }
            else if(connectDevice>=200 && connectDevice<switchDeviceId)
            {
                 cout<<"\n .....Connection Established.....Between "<<hubInfo.displayName<<" and Switch"<<connectDevice-200;
            }
            else if(connectDevice>=300 && connectDevice<bridgeDeviceId)
                {
                    cout<<"\n .....Connection Established.....Between "<<hubInfo.displayName<<" and Bridge"<<connectDevice-300;
                }
            sort(hubInfo.connectedToDevices.begin(),hubInfo.connectedToDevices.end());
        }
        else
        {
            cout<<"\n ..Device is already Connected\n";
        }
    }
    
    vector<int> getConnections()
    {
        return hubInfo.connectedToDevices;
    }   

    void displayDeviceInfo(){
        cout<<"\n ...... Hub ......\n";
        cout<<" Device Id : "<<hubInfo.hubId<<"\n";
        cout<<" Device Name : "<<hubInfo.displayName<<"\n";
        if(hubInfo.connectedToDevices.size())
        {
            cout<<" Device is connected to devices : ";
            for(int i=0;i<hubInfo.connectedToDevices.size();i++)
            {
                cout<<hubInfo.connectedToDevices[i]<<" ";
            }
        cout<<"\n";
        }
        else
        {
            cout<<" No connection is established\n";
        }

    }
};
void displayAllHubs(vector<Hub> objHub){
        if(objHub.size()==0)
        {
            cout<<"\n\n No hub is added \n\n";
            return;
        }
        
        cout<<"\n\n ......Diaplaying all the Hubs......";
        cout<<"\n -----------------------------------------------------\n";
        for(int i=0;i<objHub.size();i++)
        {
            objHub[i].displayDeviceInfo();
        }
        cout<<"\n-----------------------------------------------------\n";
}
