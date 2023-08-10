# BUILD_VERSION = 0.0.1

prefix = /usr/local
# Compiler settings - Can be customized.
CXX = g++
CXXFLAGS = -Wall -std=c++17 -DDEBUG -ggdb

# lib settings
LDFLAGS = -static -lcppunit -L/usr/local/lib/
INCLUDES = -I/usr/local/include/cppunit/
# add addtional libs here

# Makefile settings - Can be customized.
APPNAME = qpfp
EXT = cpp
ROOTDIR  = ~/src/qpfp
BUILD = ~/src/qpfp/build
OBJ = ~/src/qpfp/build
SRC = ~/src/qpfp/src

debug: all
all: $(APPNAME)

# link
$(APPNAME): $(APPNAME).o main.o utility.o
	 $(CXX) $(CXXFLAGS) -o $(BUILD)/$(APPNAME) $(BUILD)/$(APPNAME).o $(BUILD)/main.o $(BUILD)/utility.o

# compile only
$(APPNAME).o: 
	$(CXX) $(CXXFLAGS) -c $(SRC)/$(APPNAME).$(EXT) -o $(BUILD)/$(APPNAME).o
	
main.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.$(EXT) -o $(BUILD)/main.o

utility.o: 
	$(CXX) $(CXXFLAGS) -c $(SRC)/utility.$(EXT) -o $(BUILD)/utility.o

# install 
.PHONY: install
install: man
	cp $(BUILD)/$(APPNAME) $(prefix)/bin/$(APPNAME)
	rm $(prefix)/bin/$(APPNAME)

# delete object files & app executable
.PHONY: clean
clean:
	-rm -rf $(OBJ)/*.o 
	-rm -rf $(BUILD)/$(APPNAME)
