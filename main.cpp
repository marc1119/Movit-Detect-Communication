#include <cstdio>
#include <unistd.h>
#include "mosquitto_broker/mosquitto_broker.h"
#define SLEEP_TIME 2000000
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
		usleep(SLEEP_TIME);
	}

	delete mosquittoBroker;

	return 0;
}
