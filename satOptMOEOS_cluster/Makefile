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
SRCDIR=src

# Here is a Make Macro that uses the backslash to extend to multiple lines.
# Object Files
OBJS = \
	${OBJECTDIR}/Payload.o \
	${OBJECTDIR}/RunResult.o \
	${OBJECTDIR}/FileAccess.o \
	${OBJECTDIR}/Node.o \
	${OBJECTDIR}/Port.o \
	${OBJECTDIR}/PrIns.o \
	${OBJECTDIR}/main.o



PROGRAM = satOptMOEO


INCLUDEDIRS = $(LDLIBINC)

LIBDIRS = 

LIBS = -l $(LDLIBSOPTIONS)



CXXSOURCES =  src/Payload.cpp src/Payload_100.cpp src/Node.cpp src/PrIns.cpp src/Port.cpp src/RunResult.cpp src/FileAccess.cpp main.cpp      # list of source files
CXXOBJECTS = ${OBJECTDIR}/Payload.o ${OBJECTDIR}/Payload_100.o ${OBJECTDIR}/Node.o ${OBJECTDIR}/PrIns.o ${OBJECTDIR}/Port.o ${OBJECTDIR}/RunResult.o ${OBJECTDIR}/FileAccess.o ${OBJECTDIR}/main.o  
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

${OBJECTDIR}/Payload_100.o: ${SRCDIR}/Payload_100.h ${SRCDIR}/Node.h ${SRCDIR}/Port.h ${SRCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/Payload_100.o ${SRCDIR}/Payload_100.cpp

${OBJECTDIR}/Payload.o: ${SRCDIR}/Payload.h ${SRCDIR}/Node.h ${SRCDIR}/Port.h ${SRCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/Payload.o ${SRCDIR}/Payload.cpp

${OBJECTDIR}/Node.o: ${SRCDIR}/Payload.h ${SRCDIR}/Node.h ${SRCDIR}/Port.h ${SRCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/Node.o ${SRCDIR}/Node.cpp

${OBJECTDIR}/PrIns.o: ${SRCDIR}/Payload.h ${SRCDIR}/Node.h ${SRCDIR}/Port.h ${SRCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/PrIns.o ${SRCDIR}/PrIns.cpp
	
${OBJECTDIR}/Port.o: ${SRCDIR}/Payload.h ${SRCDIR}/Node.h ${SRCDIR}/Port.h ${SRCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/Port.o ${SRCDIR}/Port.cpp
	
${OBJECTDIR}/RunResult.o: ${SRCDIR}/RunResult.h ${SRCDIR}/Node.h ${SRCDIR}/Port.h ${SRCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/RunResult.o ${SRCDIR}/RunResult.cpp	

${OBJECTDIR}/FileAccess.o: ${SRCDIR}/FileAccess.h ${SRCDIR}/Node.h ${SRCDIR}/Port.h ${SRCDIR}/PrIns.h
	$(CXX) $(CXXFLAGS) $(LDLIBINC)  -c -o ${OBJECTDIR}/FileAccess.o ${SRCDIR}/FileAccess.cpp

${OBJECTDIR}/main.o: ${SRCDIR}/main.cpp ${SRCDIR}/Payload.h ${SRCDIR}/Payload_100.h ${SRCDIR}/Node.h ${SRCDIR}/Port.h ${SRCDIR}/PrIns.h ${SRCDIR}/RunResult.h ${SRCDIR}/FileAccess.h
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



