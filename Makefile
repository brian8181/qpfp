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

all: $(APPNAME) mtest ntest otest test1 node.o

# link
$(APPNAME): $(APPNAME).o main.o utility.o 
	$(CXX) $(CXXFLAGS) -o $(BLD)/$(APPNAME) $(BLD)/$(APPNAME).o $(BLD)/main.o $(BLD)/utility.o

mtest: utility.o node.o
	$(CXX) $(CXXFLAGS) -c $(SRC)/mtest.cpp -o $(BLD)/mtest.o
	$(CXX) $(CXXFLAGS) $(BLD)/mtest.o $(BLD)/utility.o -o $(BLD)/mtest

ntest: utility.o 
	$(CXX) $(CXXFLAGS) -c $(SRC)/ntest.cpp -o $(BLD)/ntest.o
	$(CXX) $(CXXFLAGS) $(BLD)/ntest.o $(BLD)/utility.o -o $(BLD)/ntest


otest: utility.o 
	$(CXX) $(CXXFLAGS) -c $(SRC)/otest.cpp -o $(BLD)/otest.o
	$(CXX) $(CXXFLAGS) $(BLD)/otest.o $(BLD)/utility.o -o $(BLD)/otest


test1: utility.o 
	$(CXX) $(CXXFLAGS) -c $(SRC)/test1.cpp -o $(BLD)/test1.o
	$(CXX) $(CXXFLAGS) $(BLD)/test1.o $(BLD)/utility.o -o $(BLD)/test1

# %test:
# 	$(CXX) $(CXXFLAGS) -c $(SRC)/%test.cpp -o $(BLD)/%test.o
# 	$(CXX) $(CXXFLAGS) $(BLD)/%test.o $(BLD)/utility.o -o $(BLD)/%test

# compile only
$(APPNAME).o: 
	$(CXX) $(CXXFLAGS) -c $(SRC)/$(APPNAME).cpp -o $(BLD)/$(APPNAME).o
	
main.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.cpp -o $(BLD)/main.o

utility.o: 
	$(CXX) $(CXXFLAGS) -c $(SRC)/utility.cpp -o $(BLD)/utility.o

node.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/node.cpp -o $(BLD)/node.o

# regular expression where % is a wildcard
# test%:
#  	$(CXX) $(CXXFLAGS) -c -o $@ $^

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