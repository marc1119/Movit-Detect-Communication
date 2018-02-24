#include "mosquitto_broker.h"

void sendAllData(MosquittoBroker *mosquittoBroker)
{
	const int keepAlive = 60;
	const int port = 1883;

	if (mosquittoBroker->connect("localhost", port, keepAlive))
	{
		// Throw error ???
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

	sendAllData(mosquittoBroker);

	mosqpp::lib_cleanup();

	return 0;
}
