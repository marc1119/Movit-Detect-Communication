CFLAGS=-Wall -ggdb -I../lib -I../mosquitto-1.4.14/lib/cpp
LDFLAGS=-L../mosquitto-1.4.14/lib ../mosquitto-1.4.14/lib/cpp/libmosquittopp.so.1 ../mosquitto-1.4.14/lib/libmosquitto.so.1

.PHONY: all clean

all : mqtt_action_listener

mqtt_action_listener : main.o action_listener.o
	${CXX} $^ -o $@ ${LDFLAGS}

main.o : main.cpp
	${CXX} -c $^ -o $@ ${CFLAGS}

action_listener.o : action_listener.cpp
	${CXX} -c $^ -o $@ ${CFLAGS}

clean : 
	-rm -f *.o mqtt_action_listener
