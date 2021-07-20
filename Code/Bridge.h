#include"iostream"
#include"sstream"
#include"vector"
#include"algorithm"
using namespace std;
static int bridgeDeviceId = 300;
class BDevice
{
public :
    int bridgeId;
    string displayName;
    vector<int> connectedToDevices;
};
class Bridge
{
    BDevice bridgeInfo;
public: 
    Bridge(){
        bridgeInfo.bridgeId = bridgeDeviceId;
        int temp = bridgeDeviceId-300;
        string converter;
        stringstream ss;
        ss<<temp;
        ss>>converter;
        bridgeInfo.displayName = "Bridge"+converter;
        cout<<"\n .......Creating Bridge.....\n";
        cout<<" Device Id : "<<bridgeInfo.bridgeId<<" ......Display Name : "<<bridgeInfo.displayName<<"\n\n";
        bridgeDeviceId++;
    }
    int getbridgeId(){ return bridgeInfo.bridgeId;}
    string getDisplayName()
    {
        return bridgeInfo.displayName;
    }
    void setConnection(int connectDevice,int endDeviceId,int hubDeviceId,int switchDeviceId, int bridgeDeviceId)
    {
        bool flag = 0;
        if(bridgeInfo.connectedToDevices.size()<2)
        {
            for(int i = 0;i<bridgeInfo.connectedToDevices.size();i++)
            {
                if(connectDevice == bridgeInfo.connectedToDevices.at(i))
                    flag = 1;
            }
            if(flag == 0)
            {
                if(connectDevice<endDeviceId)
                {
                cout<<"\n X....Connection cannot be Established.....Between "<<bridgeInfo.displayName<<" and PC"<<connectDevice;
                }
                else if(connectDevice>=100 && connectDevice<hubDeviceId)
                {
                    bridgeInfo.connectedToDevices.push_back(connectDevice);
                    cout<<"\n .....Connection Established.....Between "<<bridgeInfo.displayName<<" and Hub"<<connectDevice-100;
                }
                else if(connectDevice>=200 && connectDevice<switchDeviceId)
                {
                    bridgeInfo.connectedToDevices.push_back(connectDevice);
                    cout<<"\n .....Connection Established.....Between "<<bridgeInfo.displayName<<" and Bridge"<<connectDevice-200;
                }
                else if(connectDevice>=300 && connectDevice<bridgeDeviceId)
                {
                    cout<<"\n X....Connection cannot be Established.....Between "<<bridgeInfo.displayName<<" and Bridge"<<connectDevice-300;
                }
            
                sort(bridgeInfo.connectedToDevices.begin(),bridgeInfo.connectedToDevices.end());
            }
            else
            {
                cout<<"\n ..Device is already Connected\n";
            }
        }
        else 
        {
            cout<<"\n .... Connections already completed \n";
        }
    }
    
    vector<int> getConnections()
    {
        return bridgeInfo.connectedToDevices;
    }   

    void displayDeviceInfo(){
        cout<<"\n ...... Bridge ......\n";
        cout<<" Device Id : "<<bridgeInfo.bridgeId<<"\n";
        cout<<" Device Name : "<<bridgeInfo.displayName<<"\n";
       if(bridgeInfo.connectedToDevices.size())
        {
            cout<<" Device is connected to devices : ";
            for(int i=0;i<bridgeInfo.connectedToDevices.size();i++)
            {
                cout<<bridgeInfo.connectedToDevices[i]<<" ";
            }
        cout<<"\n";
        }
        else
        {
            cout<<" No connection is established\n";
        }

    }
};
void displayAllbridges(vector<Bridge> objbridge){
        if(objbridge.size()==0)
        {
            cout<<"\n\n No Bridge is added \n\n";
            return;
        }
        cout<<"\n\n ......Diaplaying all the Bridgees......";
        cout<<"\n -----------------------------------------------------\n";
        for(int i=0;i<objbridge.size();i++)
        {
            objbridge[i].displayDeviceInfo();
        }
       cout<<"\n-----------------------------------------------------\n";
}
