#-*- mode: makefile -*-
# GNU Makefile for DCML

ifndef MIDASSYS
MIDASSYS := /opt/DAQ
endif

OSTYPE = $(shell uname | tr '[A-Z]' '[a-z]')

#-------- ROOT
ROOTCFG := $(shell which root-config)
ifdef ROOTCFG
	ROOTSYS = $(shell $(ROOTCFG) --prefix)
endif
ifdef ROOTSYS
	ROOTCFLAGS := $(shell $(ROOTCFG) --cflags)
	ROOTCFLAGS += -DHAVE_ROOT -DUSE_ROOT
	ROOTLIBS   := $(shell $(ROOTCFG) --libs) -W1,-rpath,$(shell $(ROOTCFG) --libdir)
	ROOTLIBS   += -lThread
endif

#-------- CAEN DigitizerSDK flags
CAEN_CFLAGS :=  -I${MIDASSYS}/include -DLINUX
CAEN_LDFLAGS:=  -L${MIDASSYS}/lib -lCAENVME -lCAENdigitizerSDK

#-------- linux flags
ifeq ($(OSTYPE), linux)
	M_CFLAGS = -DOS_LINUX -Dextname -I$(MIDASSYS)/include/midas
	M_LIBS   = -lm -lz -lrt -lutil -lnsl -lpthread -L$(MIDASSYS)/lib -lmidas
endif
M_OBJDIR := $(MIDASSYS)/lib/midas

#------- List of analyzer modules
ANAMODS   =
#ANALYZERS = dcmlana

#------- Frontend code
UFES = dcmlfe

#-----------------------------------------------------------------------
CC   = gcc
CXX  = g++
CFLAGS   += -g -O2 -Wall $(M_CFLAGS) $(CAEN_CFLAGS)
CXXFLAGS += -g -O2 -Wall $(M_CFLAGS) $(ROOTCFLAGS)
LDFLAGS  += $(M_LIBS) $(CAEN_LDFLAGS)

all: $(UFES) $(ANALYZERS)

.PHONY: clean

clean:
	rm -f *.o *~ \#* $(UFES) $(ANALYZERS)

dcmlfe: dcmlfe.o $(M_OBJDIR)/mfe.o
	$(CC) -o $@ $^ $(LDFLAGS)

dcmlana: $(M_OBJDIR)/rmana.o dcmlana.o $(ANAMODS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(ROOTLIBS)

%.o: %.cpp dcml.h
%.o: %.c dcml.h
