CXX = g++
CFLAGS = -std = c++14 -Wall -Wextra
SRC_SERVER = $(shell find ./src/server ./src/db -name "*.ccp")
SRC_CLIENT = $(shell find ./src/client -name "*.ccp")
SRC_UTILS = $(shell find ./src/utils -name "*.ccp")
OBJ_SERVER = $(subst .ccp, .o, $(SRC_SERVER))
OBJ_CLIENT = $(subst .ccp, .o, $(SRC_CLIENT))
OBJ_UTILS = $(subst .ccp, .o, $(SRC_UTILS))

all: server client

server: $(OBJ_SERVER) $(OBJ_UTILS) src/server/server.h src/db/database.h
	$(CXX) $(CFLAGS) -c -o src/server/main.o src/server/main.ccp
	$(CXX) $(CFLAGS) -o server $(OBJ_SERVER) $(OBJ_UTILS)

client: $(OBJ_CLIENT) $(OBJ_UTILS) src/client/client.h
	$(CXX) $(CFLAGS) -o client $(OBJ_CLIENT) $(OBJ_UTILS)

%.o: %.ccp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean: clean-client clean-server clean-database
	rm -rf $(shell find . -name "*.o")

clean-client:
	rm -rf $(shell find src/client -name "*.o")
	rm -f ./client

clean-server:
	rm -rf $(shell find src/server -name "*.o")
	rm -f ./server

clean-database:
	rm -rf $(shell find src/db -name "*.o")
