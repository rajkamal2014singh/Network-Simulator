#include"iostream"
#include"sstream"
#include"vector"
#include"algorithm"
using namespace std;
static int switchDeviceId = 200;
class SDevice
{
public :
    int switchId;
    string displayName;
    bool addressLearning;
    vector<int> connectedToDevices;
};
class Switch
{
    SDevice switchInfo;
public: 
    Switch(){
        switchInfo.switchId = switchDeviceId;
        switchInfo.addressLearning = 0;
        int temp = switchDeviceId-200;
        string converter;
        stringstream ss;
        ss<<temp;
        ss>>converter;
        switchInfo.displayName = "Switch"+converter;
        cout<<"\n .......Creating Switch.....\n";
        cout<<" Device Id : "<<switchInfo.switchId<<" ......Display Name : "<<switchInfo.displayName<<"\n\n";
        switchDeviceId++;
    }
    int getswitchId(){ return switchInfo.switchId;}
    string getDisplayName()
    {
        return switchInfo.displayName;
    }
    void setAddressLearning()
    {
        switchInfo.addressLearning = 1;
    }
    bool getAddressLearning()
    {
        return switchInfo.addressLearning;
    }
    void setConnection(int connectDevice,int endDeviceId,int hubDeviceId,int switchDeviceId, int bridgeDeviceId)
    {
        bool flag = 0;
        for(int i = 0;i<switchInfo.connectedToDevices.size();i++)
        {
            if(connectDevice == switchInfo.connectedToDevices.at(i))
                flag = 1;
        }
        if(flag == 0)
        {
            switchInfo.connectedToDevices.push_back(connectDevice);
            if(connectDevice<endDeviceId)
            {
                cout<<"\n .....Connection Established.....Between "<<switchInfo.displayName<<" and PC"<<connectDevice;
            }
            else if(connectDevice>=100 && connectDevice<hubDeviceId)
            {
                 cout<<"\n .....Connection Established.....Between "<<switchInfo.displayName<<" and Hub"<<connectDevice-100;
            }
            else if(connectDevice>=200 && connectDevice<switchDeviceId)
            {
                 cout<<"\n .....Connection Established.....Between "<<switchInfo.displayName<<" and Switch"<<connectDevice-200;
            }
            else if(connectDevice>=300 && connectDevice<bridgeDeviceId)
                {
                    cout<<"\n .....Connection Established.....Between "<<switchInfo.displayName<<" and Bridge"<<connectDevice-300;
                }
        
            sort(switchInfo.connectedToDevices.begin(),switchInfo.connectedToDevices.end());
        }
        else
        {
            cout<<"\n ..Device is already Connected\n";
        }
    }
    
    vector<int> getConnections()
    {
        return switchInfo.connectedToDevices;
    }   

    void displayDeviceInfo(){
        cout<<"\n ...... Switch ......\n";
        cout<<" Device Id : "<<switchInfo.switchId<<"\n";
        cout<<" Device Name : "<<switchInfo.displayName<<"\n";
       if(switchInfo.connectedToDevices.size())
        {
            cout<<" Device is connected to devices : ";
            for(int i=0;i<switchInfo.connectedToDevices.size();i++)
            {
                cout<<switchInfo.connectedToDevices[i]<<" ";
            }
        cout<<"\n";
        }
        else
        {
            cout<<" No connection is established\n";
        }

    }
};
void displayAllSwitches(vector<Switch> objSwitch){
        if(objSwitch.size()==0)
        {
            cout<<"\n\n No Switch is added \n\n";
            return;
        }
        cout<<"\n\n ......Diaplaying all the switches......";
        cout<<"\n -----------------------------------------------------\n";
        for(int i=0;i<objSwitch.size();i++)
        {
            objSwitch[i].displayDeviceInfo();
        }
       cout<<"\n-----------------------------------------------------\n";
}
