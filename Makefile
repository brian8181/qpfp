# Mon Oct  9 08:25:50 PM CDT 2023
CC = gcc
CXX = g++
CXXFLAGS = -Wall -std=c++17 -DDEBUG -ggdb
LDFLAGS = -static -lcppunit -L/usr/local/lib/
APPNAME = qpfp
ROOT  = ~/src/qpfp
BLD = $(ROOT)/build
OBJ = $(ROOT)/build
SRC = $(ROOT)/src

all: $(APPNAME) mtest ntest node.o

# link
$(APPNAME): $(APPNAME).o main.o utility.o 
	$(CXX) $(CXXFLAGS) -o $(BLD)/$(APPNAME) $(BLD)/$(APPNAME).o $(BLD)/main.o $(BLD)/utility.o

mtest: utility.o node.o
	$(CXX) $(CXXFLAGS) -c $(SRC)/mtest.cpp -o $(BLD)/mtest.o
	$(CXX) $(CXXFLAGS) $(BLD)/mtest.o $(BLD)/utility.o -o $(BLD)/mtest

ntest: utility.o 
	$(CXX) $(CXXFLAGS) -c $(SRC)/ntest.cpp -o $(BLD)/ntest.o
	$(CXX) $(CXXFLAGS) $(BLD)/ntest.o $(BLD)/utility.o -o $(BLD)/ntest

# compile only
$(APPNAME).o: 
	$(CXX) $(CXXFLAGS) -c $(SRC)/$(APPNAME).cpp -o $(BLD)/$(APPNAME).o
	
main.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.cpp -o $(BLD)/main.o

utility.o: 
	$(CXX) $(CXXFLAGS) -c $(SRC)/utility.cpp -o $(BLD)/utility.o

node.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/node.cpp -o $(BLD)/node.o

# terminalnode.o: node.o
# 	$(CXX) $(CXXFLAGS) -c $(SRC)/terminalnode.cpp -o $(BLD)/terminalnode.o

# binarynode.o: terminalnode.o
# 	$(CXX) $(CXXFLAGS) -c $(SRC)/binarynode.cpp -o $(BLD)/binarynode.o


# regular expression where % is a wildcard
# %.o:%.c
# 	$(CC) $(CFLAGS) -c -o $@ $^

# install 
.PHONY: install
install: man
	cp $(BLD)/$(APPNAME) $(prefix)/bin/$(APPNAME)
	rm $(prefix)/bin/$(APPNAME)

# delete object files & app executable
.PHONY: clean
clean:
	-rm -rf $(BLD)/*