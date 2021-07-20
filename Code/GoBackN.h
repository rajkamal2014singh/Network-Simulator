
#include "iostream"
#include "cmath"
using namespace std;

//static int sendingAckNoGBN = 0;
void goBackN_Sender(int, int, int);
int goBackN_Receiver(int[], bool[], int, int,int );

void goBackN_Sender(const int noPackets, const int windowSize,int probability)
{
	int sendingAckNoGBN = 0;
	int packets[windowSize + 1], tempWindowSize = 0,total_transmissions = 0;
	bool acks[windowSize + 1];

	for (int j = 0; j <= windowSize; j++)
		acks[j] = 0;

	for (int packetNo = 0; packetNo < noPackets;)
	{
		if(noPackets-packetNo<windowSize)
			tempWindowSize = noPackets - packetNo;
		else
			tempWindowSize = windowSize;

		for (int j = 0; j < tempWindowSize; j++, packetNo++)
			packets[j] = packetNo;

		for (int j = 0; j < tempWindowSize; j++)
			cout << "\n Sending Packet Number : " <<packets[j] << " Sequence Number : " << (packets[j])%(windowSize+1);
		
		packetNo = goBackN_Receiver(packets, acks, tempWindowSize, probability,sendingAckNoGBN);
		sendingAckNoGBN = packetNo;
		total_transmissions += tempWindowSize;
		if (packetNo == packets[0])
        {
            	if (rand() % 2 == 0)
				cout << "\n Packet Not Received .. Resending .. ";
			else
				cout << "\n Timed Out .. Resending .. ";
        }
	}
		cout<<"\n Total no. of transmission are : "<<total_transmissions<<"\n";
		cout<<"\n Total no. of collisions are : "<<total_transmissions - noPackets<<"\n";
}

int goBackN_Receiver(int packets[], bool acks[], int tempWindowSize, int probability,int sendingAckNoGBN)
{
	bool value = 0;
	for (int i = 0; i < tempWindowSize; i++)
	{
        if(rand()%100<=probability)
        {
            value = 1;
        }
        else
        {
            value = 0;
        }
        
		acks[i] = value;
	}

	cout << "\n Packets Received : ";
    int i;
	for (i = 0; i < tempWindowSize && acks[i]; i++, sendingAckNoGBN++)
		cout << packets[i] << " ";
	cout <<"\n Sending Cumulative Acknowledgement till packet no : "<<sendingAckNoGBN<<endl;
	return sendingAckNoGBN;
}

