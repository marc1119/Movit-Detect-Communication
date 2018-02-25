#include <iostream>
#include <cstdio>
#include <cstring>

#include "mosquitto_broker.h"
#include <mosquittopp.h>

MosquittoBroker::MosquittoBroker(const char *id) : mosquittopp(id)
{
	const char *username = "admin";
	const char *password = "movitplus";

	username_pw_set(username, password); // Not working :( !?
}

MosquittoBroker::~MosquittoBroker()
{
}

void MosquittoBroker::on_connect(int rc)
{
	printf("Connected with code %d.\n", rc);
}

void MosquittoBroker::on_message(const struct mosquitto_message *message)
{
	printf("Message published.\n");
}

void MosquittoBroker::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
	printf("Subscription succeeded.\n");
}

void MosquittoBroker::sendBackRestAngle(const int angle)
{
	std::string strAngle = std::to_string(angle);

	publish(NULL, "data/back_rest_angle", strAngle.length(), strAngle.c_str());
}

void MosquittoBroker::sendSittingTime(const int time)
{
	std::string strTime = std::to_string(time);

	publish(NULL, "data/sitting_time", strTime.length(), strTime.c_str());
}

void MosquittoBroker::sendDistanceTraveled(const int distance)
{
	std::string strDistance = std::to_string(distance);

	publish(NULL, "data/distance_traveled", strDistance.length(), strDistance.c_str());
}