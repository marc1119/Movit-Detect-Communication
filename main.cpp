#include "action_listener.h"

int main(int argc, char *argv[])
{
	class action_listener *actionListener;
	int rc;

	mosqpp::lib_init();

	actionListener = new action_listener("actionlistener", "localhost", 1883);
	
	while(1)
	{
		rc = actionListener->loop();
		
		if(rc)
		{
			actionListener->reconnect();
		}
	}

	mosqpp::lib_cleanup();

	return 0;
}
