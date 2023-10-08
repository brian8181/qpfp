CXX = g++
CXXFLAGS = -Wall -std=c++17 -DDEBUG -ggdb
LDFLAGS = -static -lcppunit -L/usr/local/lib/
APPNAME = qpfp
EXT = cpp
ROOTDIR  = ~/src/qpfp
BUILD = ~/src/qpfp/build
OBJ = ~/src/qpfp/build
SRC = ~/src/qpfp/src

all: $(APPNAME) mtest node.o
# link
$(APPNAME): $(APPNAME).o main.o utility.o 
	$(CXX) $(CXXFLAGS) -o $(BUILD)/$(APPNAME) $(BUILD)/$(APPNAME).o $(BUILD)/main.o $(BUILD)/utility.o

mtest: utility.o 
	$(CXX) $(CXXFLAGS) -c $(SRC)/mtest.cpp -o $(BUILD)/mtest.o
	$(CXX) $(CXXFLAGS) $(BUILD)/mtest.o $(BUILD)/utility.o -o $(BUILD)/mtest

# compile only
$(APPNAME).o: 
	$(CXX) $(CXXFLAGS) -c $(SRC)/$(APPNAME).$(EXT) -o $(BUILD)/$(APPNAME).o
	
main.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.$(EXT) -o $(BUILD)/main.o

utility.o: 
	$(CXX) $(CXXFLAGS) -c $(SRC)/utility.$(EXT) -o $(BUILD)/utility.o

node.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/node.$(EXT) -o $(BUILD)/node.o

# terminalnode.o: node.o
# 	$(CXX) $(CXXFLAGS) -c $(SRC)/terminalnode.$(EXT) -o $(BUILD)/terminalnode.o

# binarynode.o: terminalnode.o
# 	$(CXX) $(CXXFLAGS) -c $(SRC)/binarynode.$(EXT) -o $(BUILD)/binarynode.o


# regular expression where % is a wildcard
# %.o:%.c
# 	$(CC) $(CFLAGS) -c -o $@ $^

# install 
.PHONY: install
install: man
	cp $(BUILD)/$(APPNAME) $(prefix)/bin/$(APPNAME)
	rm $(prefix)/bin/$(APPNAME)

# delete object files & app executable
.PHONY: clean
clean:
	-rm -rf $(BUILD)/*