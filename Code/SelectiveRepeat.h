
#include "iostream"
#include "cmath"
using namespace std;

//static int sendingAckNoSR = 0;
void selectiveRepeat_Sender(int, int, int);
int selectiveRepeat_Receiver(int[], bool[], int, int, int );

void selectiveRepeat_Sender(const int noPackets, const int windowSize, int probability)
{
	int sendingAckNoSR = 0;
	int temp = 0,total_transmissions=0;
	int packets[windowSize + 1], tempWindowSize = 0;
	bool acks[windowSize + 1], ackno[noPackets + 1];

	for (int j = 0; j <= noPackets; j++)
		ackno[j] = 0;
    
	for (int packetNo = 0; packetNo < noPackets;)
	{
		temp = packetNo;
        if(noPackets-packetNo<windowSize)
			tempWindowSize = noPackets - packetNo;
		else
			tempWindowSize = windowSize;

		for (int j = 0; j < tempWindowSize; j++, packetNo++)
		{
			packets[j] = packetNo;
			acks[j] = ackno[packetNo];
		}

		for (int j = 0; j < tempWindowSize; j++)
		{
			if (acks[j] == 0)
			{
				cout << "\n Sending Packet Number : " << packets[j]<< " Sequence Number : " << (packets[j])%(windowSize+1);
				total_transmissions++;
			}
		}
		packetNo = selectiveRepeat_Receiver(packets, acks, tempWindowSize,probability,sendingAckNoSR);
		sendingAckNoSR = packetNo;
		for (int j = 0; j < tempWindowSize; j++)
			ackno[temp + j] = acks[j];

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

int selectiveRepeat_Receiver(int packets[], bool acks[], int tempWindowSize, int probability,int sendingAckNoSR)
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
		if (acks[i] == 0)
			acks[i] = value;
	}

	bool flag = 0;
	for (int i = 0; i < tempWindowSize; i++)
		if (acks[i] == 1)
		{
            cout << "\n Packet No. : "<<packets[i] << " Received .. Sending Acknowledgment .. ";

			if (!flag)
				sendingAckNoSR++;
		}
		else
		{
			flag = 1;
		}
    cout<<"\n";
	
	return sendingAckNoSR;
}