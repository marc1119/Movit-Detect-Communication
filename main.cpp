#include <cstdio>
#include <unistd.h>
#include "mosquitto_broker/mosquitto_broker.h"

void sendDataToWebServer(MosquittoBroker *mosquittoBroker)
{
	mosquittoBroker->sendBackRestAngle(10);
	mosquittoBroker->sendDistanceTraveled(1000);
}

int main(int argc, char *argv[])
{
	MosquittoBroker *mosquittoBroker = new MosquittoBroker("actionlistener");

	while (1)
	{
		sendDataToWebServer(mosquittoBroker);
		usleep(2000000);
	}

	delete mosquittoBroker;

	return 0;
}
