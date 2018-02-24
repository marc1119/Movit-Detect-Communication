#ifndef ACTION_LISTENER_H
#define ACTION_LISTENER_H

#include <mosquittopp.h>

class action_listener : public mosqpp::mosquittopp
{
	public:
		action_listener(const char *id, const char *host, int port);
		~action_listener();

		void on_connect(int rc);
		void on_message(const struct mosquitto_message *message);
		void on_subscribe(int mid, int qos_count, const int *granted_qos);
};

#endif
