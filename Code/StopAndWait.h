
#include "iostream"
#include"cmath"
using namespace std;

static bool sendingAckNoSNW = 0;
void stopNwait_Sender(int,int);
int stopNwait_Receiver(int,int);

void stopNwait_Sender(int noPackets,int probability)
{
	int receivedAckNo = 0,totalTransmissions = 0;
	for (int packetNo = 0; packetNo < noPackets; packetNo++)
	{
		cout << "\n Sending Packet Number : " << packetNo << " Sequence Number : " << (packetNo % 2);
		receivedAckNo = stopNwait_Receiver(packetNo % 2,probability);
		totalTransmissions++;
		if ((packetNo % 2) == receivedAckNo)
		{
			if (rand() % 2 == 0)
				cout << "\n Packet Not Received .. Resending .. ";
			else
				cout << "\n Timed Out .. Resending .. ";
			packetNo--;
		}
		else
			cout << "\n Acknowledgment Received .. Sending Next .. \n";
	}
	cout<<"\n Total no. of transmission are : "<<totalTransmissions<<"\n";
	cout<<"\n Total no. of collisions are : "<<totalTransmissions - noPackets<<"\n";
}

int stopNwait_Receiver(int seqNo,int probability)
{
	if(rand()%100<=probability)
	{
		if (sendingAckNoSNW == seqNo)
		{
			cout << "\n Packet Received .. Sending Acknowledgment .. ";
			sendingAckNoSNW = !seqNo;
			return sendingAckNoSNW;
		}
		else
		{
			cout << "\n Packet Already Received .. Resending Acknowledgment .. ";
			return sendingAckNoSNW;
		}
	}
	return sendingAckNoSNW;
}

