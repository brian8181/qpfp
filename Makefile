# BUILD_VERSION = 0.0.1

prefix = /usr/local
mandir = $(prefix)/share/man
man1dir = $(mandir)/man1

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
$(APPNAME): $(APPNAME).o main.o utility.o #@@PREREQUISTE@@
	 $(CXX) $(CXXFLAGS) -o $(BUILD)/$(APPNAME) $(BUILD)/$(APPNAME).o $(BUILD)/main.o $(BUILD)/utility.o #@@CLASS_NAME@@

# compile only
$(APPNAME).o: 
	$(CXX) $(CXXFLAGS) -c $(SRC)/$(APPNAME).$(EXT) -o $(BUILD)/$(APPNAME).o
	
main.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.$(EXT) -o $(BUILD)/main.o

utility.o: 
	$(CXX) $(CXXFLAGS) -c $(SRC)/utility.$(EXT) -o $(BUILD)/utility.o

#AUTO_INSERT_POINT_DO_NOT_REMOVE#


# install man pages
.PHONY: man
man:
	cp ../man/$(APPNAME).1 $(man1dir)
	# gzip $(man1dir)/$(APPNAME).1
	mandb

.PHONY: unman
unman:
	-rm -rf $(man1dir)/$(APPNAME).1.gz
	mandb

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
	-rm -rf $(BUILD)/bash_color_test
	-rm -rf $(BUILD)/*.xml $(BUILD)/$(APPNAME).$(BUILD_VERSION).tar.gz
	-rm -rf $(BUILD)/$(APPNAME).core

# delete object files, app, executables, & all automake/autoconf generated files
.PHONY: distclean
distclean: clean
	-rm -rf $(ROOT)/config.* $(ROOT)/Makefile $(ROOT)/Makefile.in $(ROOT)/INSTALL $(ROOT)/configure 
	-rm -rf $(ROOT)/stamp-h1 $(ROOT)/aclocal.m4 $(ROOT)/compile $(ROOT)/install-sh $(ROOT)/libtool $(ROOT)/ltmain.sh $(ROOT)/stamp-h1 $(ROOT)/missing $(ROOT)/depcomp
	-rm -rf $(SRC)/Makefile $(SRCS)/Makefile.in
	-rm -rf $(ROOT)/autom4te.cache $(SRCS)/.deps $(SRCS)/.libs

clean-local:
	-rm -rf config.status configure config.log
	-rm -rf autom4te.cache/
	-rm =-rf aclocal.m4
	-rm -rf compile install-sh missing Makefile.in
	
dist: 
	git archive HEAD | gzip > $(BUILD)/$(APPNAME).$(BUILD_VERSION).tar.gz

dist-gz: dist
