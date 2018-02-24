#include <cstdio>
#include <cstring>

#include "action_listener.h"
#include <mosquittopp.h>

action_listener::action_listener(const char *id, const char *host, int port) : mosquittopp(id)
{
	int keepalive = 60;

	connect(host, port, keepalive);
};

action_listener::~action_listener()
{
}

void action_listener::on_connect(int rc)
{
	printf("Connected with code %d.\n", rc);

	if(rc == 0)
	{
		subscribe(NULL, "temperature/celsius");
	}
}

void action_listener::on_message(const struct mosquitto_message *message)
{
	printf("Message received.\n");
}

void action_listener::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
	printf("Subscription succeeded.\n");
}
