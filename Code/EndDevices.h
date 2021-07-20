#include"iostream"
#include"vector"
#include"sstream"
using namespace std;
static int endDeviceId=0;
class Device{
public:
    int deviceId;
    string displayName;
 	string Ip;
	string macAddress;
    int connectedToDevice;
};
class EndDevices{
	Device deviceInfo;
public :	
    EndDevices(){
        deviceInfo.deviceId = endDeviceId;
        int temp = endDeviceId;
        string converter;
        stringstream ss;
        ss<<temp;
        ss>>converter;
        deviceInfo.displayName = "PC"+converter;
        deviceInfo.connectedToDevice = -1;
        cout<<"\n .......Creating Device.....\n";
        cout<<" Device Id : "<<deviceInfo.deviceId<<" ......Display Name : "<<deviceInfo.displayName<<"\n\n";
        endDeviceId++;
    }
    
	void setInfo(){
        int choice;
		
        cout<<"\n .....Enter Device Details.....\n";
        cout<<" Device Id : "<<deviceInfo.deviceId<<"\n";
        cout<<" .....Assigning ip address...... \n";
            
            while(true)
            {
                cout<<" 1.Assign ip address randomly\n";
                cout<<" 2.Assign Ip \n";
                cout<<" Enter you choice : ";
                cin>>choice;
                if(choice==1)
                {
                    deviceInfo.Ip= ipRandom();
                    cout<<" Ip allocated : "<<deviceInfo.Ip<<"\n";
                    break;
                }
                else if(choice==2)
                {
                    cout<<" Enter Ip address : ";
                    cin>>deviceInfo.Ip;
                    cout<<" Ip address allocated : "<<deviceInfo.Ip<<"\n";
                    break;
                }
                else
                {
                    cout<<" Invalid Choice ........ Please try again\n";
                }
            }
        cout<<" .....Assigning mac address...... \n";
            while(true)
            {
                cout<<" 1.Assign mac address randomly\n";
                cout<<" 2.Assign mac \n";
                cout<<" Enter you choice : ";
                cin>>choice;
                if(choice==1)
                {
                    deviceInfo.macAddress= macRandom();
                    cout<<" Mac address allocated : "<<deviceInfo.macAddress<<"\n";
                    break;
                }
                else if(choice==2)
                {
                    cout<<" Enter mac address : ";
                    cin>>deviceInfo.macAddress;
                    cout<<" Mac address allocated : "<<deviceInfo.macAddress<<"\n";
                    break;
                }
                else
                {
                    cout<<" Invalid Choice ........ Please try again\n";
                }
            } 
	}
    Device getDeviceInfo(){
        return deviceInfo;
    }
    int getDeviceID()
    {
        return deviceInfo.deviceId;
    }
    string getDisplayName()
    {
        return deviceInfo.displayName;
    }
    void setConnection(int connectDevice,int endDeviceId,int hubDeviceId,int switchDeviceId, int bridgeDeviceId)
    {
        deviceInfo.connectedToDevice = connectDevice;
        if(connectDevice<endDeviceId)
            {
                cout<<"\n .....Connection Established.....Between "<<deviceInfo.displayName<<" and PC"<<connectDevice;
            }
            else if(connectDevice>=100 && connectDevice<hubDeviceId)
            {
                 cout<<"\n .....Connection Established.....Between "<<deviceInfo.displayName<<" and Hub"<<connectDevice-100;
            }
            else if(connectDevice>=200 && connectDevice<switchDeviceId)
            {
                 cout<<"\n .....Connection Established.....Between "<<deviceInfo.displayName<<" and Switch"<<connectDevice-200;
            }
            else if(connectDevice>=300 && connectDevice<bridgeDeviceId)
                {
                    cout<<"\n X....Connection cannot be Established.....Between "<<deviceInfo.displayName<<" and Bridge"<<connectDevice-300;
                }
        
    }
    int getConnection()
    {
        return deviceInfo.connectedToDevice;
    }

    void displayDeviceInfo(){
        cout<<"\n ......Displaying details of the device ......\n";
        cout<<" Device Id : "<<deviceInfo.deviceId<<"\n";
        cout<<" Display Name : "<<deviceInfo.displayName<<"\n";
        cout<<" Device ip address : "<<deviceInfo.Ip<<"\n";
        cout<<" Device mac address : "<<deviceInfo.macAddress<<"\n";
        if(deviceInfo.connectedToDevice == -1)
            cout<<" No connection is established\n";
        else
            cout<<" Device is connected to : "<<deviceInfo.connectedToDevice<<"\n";
    }
    
};

void displayAllEndDevices(vector<EndDevices> obj){
        if(obj.size()==0)
        {
            cout<<"\n\n No end device is added \n\n";
            return;
        }
        cout<<"\n\n ......Diaplaying all the end devices......";
        cout<<"\n -----------------------------------------------------\n";
        for(int i=0;i<obj.size();i++)
        {
            obj[i].displayDeviceInfo();
        }
        cout<<"\n -----------------------------------------------------\n";
}

