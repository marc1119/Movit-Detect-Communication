#include <cstdio>
#include <unistd.h>
#include "mosquitto_broker/mosquitto_broker.h"

void sendAllData(MosquittoBroker *mosquittoBroker)
{
	const char * host = "localhost";
	const int keepAlive = 60;
	const int port = 1883;

	if (mosquittoBroker->connect(host, port, keepAlive))
	{
		throw;
	}
	else
	{
		mosquittoBroker->sendBackRestAngle(10);
		mosquittoBroker->sendDistanceTraveled(1000);
	}
}

int main(int argc, char *argv[])
{
	mosqpp::lib_init();

	MosquittoBroker *mosquittoBroker = new MosquittoBroker("actionlistener");

	while (1)
	{
		sendAllData(mosquittoBroker);
		usleep(2000000);
	}

	mosqpp::lib_cleanup();

	return 0;
}
