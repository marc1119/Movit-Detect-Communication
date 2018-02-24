CFLAGS=-Wall -ggdb -I lib -I lib/cpp
LDFLAGS=-Llib lib/cpp/libmosquittopp.so.1 lib/libmosquitto.so.1

.PHONY: all clean

all : mqtt_mosquitto_broker

mqtt_mosquitto_broker : main.o mosquitto_broker.o
	${CXX} $^ -o $@ ${LDFLAGS}

main.o : main.cpp
	${CXX} -c $^ -o $@ ${CFLAGS}

mosquitto_broker.o : mosquitto_broker.cpp
	${CXX} -c $^ -o $@ ${CFLAGS}

clean : 
	-rm -f *.o mqtt_mosquitto_broker
