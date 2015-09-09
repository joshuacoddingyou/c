#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


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
CND_PLATFORM=None-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/connected-peer.o \
	${OBJECTDIR}/connectionless-receiver.o \
	${OBJECTDIR}/connectionless-sender.o \
	${OBJECTDIR}/echo-process.o \
	${OBJECTDIR}/echo-thread.o \
	${OBJECTDIR}/exec-server.o \
	${OBJECTDIR}/html-ls-server.o \
	${OBJECTDIR}/html-ls-server2.o \
	${OBJECTDIR}/http-client.o \
	${OBJECTDIR}/http-dir.o \
	${OBJECTDIR}/ls-server.o \
	${OBJECTDIR}/parent-child.o \
	${OBJECTDIR}/serverls.o \
	${OBJECTDIR}/simple-client.o \
	${OBJECTDIR}/simple-server.o \
	${OBJECTDIR}/snooper.o \
	${OBJECTDIR}/test-port-client.o \
	${OBJECTDIR}/thread-mutex.o \
	${OBJECTDIR}/trivial-server.o \
	${OBJECTDIR}/ttcp-client.o \
	${OBJECTDIR}/ttcp-server.o \
	${OBJECTDIR}/udp-reconnect.o \
	${OBJECTDIR}/udp-server.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/connected-peer.o: connected-peer.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/connected-peer.o connected-peer.c

${OBJECTDIR}/connectionless-receiver.o: connectionless-receiver.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/connectionless-receiver.o connectionless-receiver.c

${OBJECTDIR}/connectionless-sender.o: connectionless-sender.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/connectionless-sender.o connectionless-sender.c

${OBJECTDIR}/echo-process.o: echo-process.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/echo-process.o echo-process.c

${OBJECTDIR}/echo-thread.o: echo-thread.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/echo-thread.o echo-thread.c

${OBJECTDIR}/exec-server.o: exec-server.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exec-server.o exec-server.c

${OBJECTDIR}/html-ls-server.o: html-ls-server.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/html-ls-server.o html-ls-server.c

${OBJECTDIR}/html-ls-server2.o: html-ls-server2.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/html-ls-server2.o html-ls-server2.c

${OBJECTDIR}/http-client.o: http-client.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/http-client.o http-client.c

${OBJECTDIR}/http-dir.o: http-dir.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/http-dir.o http-dir.c

${OBJECTDIR}/ls-server.o: ls-server.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ls-server.o ls-server.c

${OBJECTDIR}/parent-child.o: parent-child.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parent-child.o parent-child.c

${OBJECTDIR}/serverls.o: serverls.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/serverls.o serverls.c

${OBJECTDIR}/simple-client.o: simple-client.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/simple-client.o simple-client.c

${OBJECTDIR}/simple-server.o: simple-server.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/simple-server.o simple-server.c

${OBJECTDIR}/snooper.o: snooper.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/snooper.o snooper.c

${OBJECTDIR}/test-port-client.o: test-port-client.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/test-port-client.o test-port-client.c

${OBJECTDIR}/thread-mutex.o: thread-mutex.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thread-mutex.o thread-mutex.c

${OBJECTDIR}/trivial-server.o: trivial-server.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/trivial-server.o trivial-server.c

${OBJECTDIR}/ttcp-client.o: ttcp-client.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ttcp-client.o ttcp-client.c

${OBJECTDIR}/ttcp-server.o: ttcp-server.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ttcp-server.o ttcp-server.c

${OBJECTDIR}/udp-reconnect.o: udp-reconnect.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/udp-reconnect.o udp-reconnect.c

${OBJECTDIR}/udp-server.o: udp-server.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/udp-server.o udp-server.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
