#ifndef MOSQUITTO_BROKER_H
#define MOSQUITTO_BROKER_H

#include <mosquittopp.h>

class MosquittoBroker : public mosqpp::mosquittopp
{
	public:
		MosquittoBroker(const char *id);
		~MosquittoBroker();

		void on_connect(int rc);
		void on_message(const struct mosquitto_message *message);
		void on_subscribe(int mid, int qos_count, const int *granted_qos);

		void sendBackRestAngle(const int angle);
		void sendSittingTime(const int time);
		void sendDistanceTraveled(const int distance);
};

#endif
