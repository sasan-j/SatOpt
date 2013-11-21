# if you use this Makefile as a starting point for another application
# you might need to modify the following
DIR_EO = ../ParadisEO-2.0/eo/src
DIR_MO = ../ParadisEO-2.0/mo/src
DIR_MOEO = ../ParadisEO-2.0/moeo/src
DIR_LIB_EO = ../ParadisEO-2.0/build/eo/lib
DIR_LIB_MOEO =../ParadisEO-2.0/build/moeo/lib

# Link Libraries and Options
LDLIBSOPTIONS=  $(DIR_LIB_EO)/libeo.a  $(DIR_LIB_EO)/libcma.a $(DIR_LIB_EO)/libeoutils.a $(DIR_LIB_EO)/libes.a $(DIR_LIB_EO)/libga.a $(DIR_LIB_MOEO)/libmoeo.a
LDLIBINC = -I. -I$(DIR_EO) -I$(DIR_MOEO) -I$(DIR_MO)

# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86_x64
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build



# Object Directory
OBJECTDIR=obj

LIBSRCDIR = ../lib/src
LIBINCDIR = ../lib/inc
SRCDIR=src


PROGRAM = satOptMOEO_WA


INCLUDEDIRS = $(LDLIBINC)

LIBDIRS = 

LIBS = -l $(LDLIBSOPTIONS)



CXXSOURCES =  ${LIBSRCDIR}/Payload.cpp ${LIBSRCDIR}/Payload_100.cpp ${LIBSRCDIR}/Node.cpp ${LIBSRCDIR}/PrIns.cpp ${LIBSRCDIR}/Port.cpp ${LIBSRCDIR}/RunResult.cpp ${LIBSRCDIR}/FileAccess.cpp ${LIBSRCDIR}/ExactExtractor.cpp main.cpp      # list of source files
CXXOBJECTS = ${OBJECTDIR}/Payload.o ${OBJECTDIR}/Payload_100.o ${OBJECTDIR}/Node.o ${OBJECTDIR}/PrIns.o ${OBJECTDIR}/Port.o ${OBJECTDIR}/RunResult.o ${OBJECTDIR}/FileAccess.o ${OBJECTDIR}/ExactExtractor.o ${OBJECTDIR}/main.o  
#$(CXXSOURCES:.cpp=.o)  # expands to list of object files
CXXFLAGS = -DESRI_UNIX -m64 -O3 -std=c++11 $(INCLUDEDIRS) 
CXX = g++
#CXX = icc
LDFLAGS = $(LIBDIRS) $(LIBS)

#
# Default target: the first target is the default target.
# Just type "make -f Makefile.Linux" to build it.
#

all: $(PROGRAM)

#
# Link target: automatically builds its object dependencies before
# executing its link command.
#

$(PROGRAM): $(CXXOBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(CXXOBJECTS) $(LDLIBSOPTIONS)
#$(LDFLAGS)

	
	
	
#
# Object targets: rules that define objects, their dependencies, and
# a list of commands for compilation.
#

${OBJECTDIR}/Payload_100.o: ${LIBINCDIR}/Payload_100.h ${LIBINCDIR}/Node.h ${LIBINCDIR}/Port.h ${LIBINCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/Payload_100.o ${LIBSRCDIR}/Payload_100.cpp

${OBJECTDIR}/Payload.o: ${LIBINCDIR}/Payload.h ${LIBINCDIR}/Node.h ${LIBINCDIR}/Port.h ${LIBINCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/Payload.o ${LIBSRCDIR}/Payload.cpp

${OBJECTDIR}/Node.o: ${LIBINCDIR}/Payload.h ${LIBINCDIR}/Node.h ${LIBINCDIR}/Port.h ${LIBINCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/Node.o ${LIBSRCDIR}/Node.cpp

${OBJECTDIR}/PrIns.o: ${LIBINCDIR}/Payload.h ${LIBINCDIR}/Node.h ${LIBINCDIR}/Port.h ${LIBINCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/PrIns.o ${LIBSRCDIR}/PrIns.cpp
	
${OBJECTDIR}/Port.o: ${LIBINCDIR}/Payload.h ${LIBINCDIR}/Node.h ${LIBINCDIR}/Port.h ${LIBINCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/Port.o ${LIBSRCDIR}/Port.cpp
	
${OBJECTDIR}/RunResult.o: ${LIBINCDIR}/RunResult.h ${LIBINCDIR}/Node.h ${LIBINCDIR}/Port.h ${LIBINCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/RunResult.o ${LIBSRCDIR}/RunResult.cpp	

${OBJECTDIR}/FileAccess.o: ${LIBINCDIR}/FileAccess.h ${LIBINCDIR}/Node.h ${LIBINCDIR}/Port.h ${LIBINCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/FileAccess.o ${LIBSRCDIR}/FileAccess.cpp
	
${OBJECTDIR}/ExactExtractor.o: ${LIBINCDIR}/FileAccess.h ${LIBINCDIR}/Node.h ${LIBINCDIR}/SatOpt.h ${LIBINCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/ExactExtractor.o ${LIBSRCDIR}/ExactExtractor.cpp	

${OBJECTDIR}/main.o: ${SRCDIR}/main.cpp ${LIBINCDIR}/Payload.h ${LIBINCDIR}/Payload_100.h ${LIBINCDIR}/Node.h ${LIBINCDIR}/Port.h ${LIBINCDIR}/PrIns.h ${LIBINCDIR}/ExactExtractor.h ${LIBINCDIR}/RunResult.h ${LIBINCDIR}/FileAccess.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/main.o ${SRCDIR}/main.cpp
	

#
# Clean target: "make -f Makefile.Linux clean" to remove unwanted objects and executables.
#

clean:
	$(RM) -f $(CXXOBJECTS) $(PROGRAM)

#
# Run target: "make -f Makefile.Linux run" to execute the application
#             You will need to add $(VARIABLE_NAME) for any command line parameters 
#             that you defined earlier in this file.
# 

run:
	./$(PROGRAM) 



