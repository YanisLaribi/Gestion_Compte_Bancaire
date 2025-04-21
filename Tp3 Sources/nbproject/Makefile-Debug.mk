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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Cheque.o \
	${OBJECTDIR}/Client.o \
	${OBJECTDIR}/Compte.o \
	${OBJECTDIR}/CompteAbsentException.o \
	${OBJECTDIR}/CompteDejaPresentException.o \
	${OBJECTDIR}/CompteException.o \
	${OBJECTDIR}/ContratException.o \
	${OBJECTDIR}/Date.o \
	${OBJECTDIR}/Epargne.o \
	${OBJECTDIR}/validationFormat.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f4

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/ChequeTesteur.o \
	${TESTDIR}/ClientTesteur.o \
	${TESTDIR}/CompteTesteur.o \
	${TESTDIR}/DateTesteur.o \
	${TESTDIR}/EpargneTesteur.o

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtp3_sources.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtp3_sources.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtp3_sources.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtp3_sources.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtp3_sources.a

${OBJECTDIR}/Cheque.o: Cheque.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cheque.o Cheque.cpp

${OBJECTDIR}/Client.o: Client.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Client.o Client.cpp

${OBJECTDIR}/Compte.o: Compte.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Compte.o Compte.cpp

${OBJECTDIR}/CompteAbsentException.o: CompteAbsentException.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CompteAbsentException.o CompteAbsentException.cpp

${OBJECTDIR}/CompteDejaPresentException.o: CompteDejaPresentException.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CompteDejaPresentException.o CompteDejaPresentException.cpp

${OBJECTDIR}/CompteException.o: CompteException.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CompteException.o CompteException.cpp

${OBJECTDIR}/ContratException.o: ContratException.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContratException.o ContratException.cpp

${OBJECTDIR}/Date.o: Date.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Date.o Date.cpp

${OBJECTDIR}/Epargne.o: Epargne.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Epargne.o Epargne.cpp

${OBJECTDIR}/validationFormat.o: validationFormat.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/validationFormat.o validationFormat.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f3: ${TESTDIR}/ChequeTesteur.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS}   -lgtest_main -lgtest -lpthread 

${TESTDIR}/TestFiles/f5: ${TESTDIR}/ClientTesteur.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS}   -lgtest_main -lgtest -lpthread 

${TESTDIR}/TestFiles/f2: ${TESTDIR}/CompteTesteur.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   -lgtest_main -lgtest -lpthread 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/DateTesteur.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   -lgtest_main -lgtest -lpthread 

${TESTDIR}/TestFiles/f4: ${TESTDIR}/EpargneTesteur.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS}   -lgtest_main -lgtest -lpthread 


${TESTDIR}/ChequeTesteur.o: ChequeTesteur.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/src/gtest/include -MMD -MP -MF "$@.d" -o ${TESTDIR}/ChequeTesteur.o ChequeTesteur.cpp


${TESTDIR}/ClientTesteur.o: ClientTesteur.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/src/gtest/include -MMD -MP -MF "$@.d" -o ${TESTDIR}/ClientTesteur.o ClientTesteur.cpp


${TESTDIR}/CompteTesteur.o: CompteTesteur.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/src/gtest/include -MMD -MP -MF "$@.d" -o ${TESTDIR}/CompteTesteur.o CompteTesteur.cpp


${TESTDIR}/DateTesteur.o: DateTesteur.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/src/gtest/include -MMD -MP -MF "$@.d" -o ${TESTDIR}/DateTesteur.o DateTesteur.cpp


${TESTDIR}/EpargneTesteur.o: EpargneTesteur.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/src/gtest/include -MMD -MP -MF "$@.d" -o ${TESTDIR}/EpargneTesteur.o EpargneTesteur.cpp


${OBJECTDIR}/Cheque_nomain.o: ${OBJECTDIR}/Cheque.o Cheque.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Cheque.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cheque_nomain.o Cheque.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Cheque.o ${OBJECTDIR}/Cheque_nomain.o;\
	fi

${OBJECTDIR}/Client_nomain.o: ${OBJECTDIR}/Client.o Client.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Client.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Client_nomain.o Client.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Client.o ${OBJECTDIR}/Client_nomain.o;\
	fi

${OBJECTDIR}/Compte_nomain.o: ${OBJECTDIR}/Compte.o Compte.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Compte.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Compte_nomain.o Compte.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Compte.o ${OBJECTDIR}/Compte_nomain.o;\
	fi

${OBJECTDIR}/CompteAbsentException_nomain.o: ${OBJECTDIR}/CompteAbsentException.o CompteAbsentException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/CompteAbsentException.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CompteAbsentException_nomain.o CompteAbsentException.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/CompteAbsentException.o ${OBJECTDIR}/CompteAbsentException_nomain.o;\
	fi

${OBJECTDIR}/CompteDejaPresentException_nomain.o: ${OBJECTDIR}/CompteDejaPresentException.o CompteDejaPresentException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/CompteDejaPresentException.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CompteDejaPresentException_nomain.o CompteDejaPresentException.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/CompteDejaPresentException.o ${OBJECTDIR}/CompteDejaPresentException_nomain.o;\
	fi

${OBJECTDIR}/CompteException_nomain.o: ${OBJECTDIR}/CompteException.o CompteException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/CompteException.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CompteException_nomain.o CompteException.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/CompteException.o ${OBJECTDIR}/CompteException_nomain.o;\
	fi

${OBJECTDIR}/ContratException_nomain.o: ${OBJECTDIR}/ContratException.o ContratException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ContratException.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContratException_nomain.o ContratException.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ContratException.o ${OBJECTDIR}/ContratException_nomain.o;\
	fi

${OBJECTDIR}/Date_nomain.o: ${OBJECTDIR}/Date.o Date.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Date.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Date_nomain.o Date.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Date.o ${OBJECTDIR}/Date_nomain.o;\
	fi

${OBJECTDIR}/Epargne_nomain.o: ${OBJECTDIR}/Epargne.o Epargne.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Epargne.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Epargne_nomain.o Epargne.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Epargne.o ${OBJECTDIR}/Epargne_nomain.o;\
	fi

${OBJECTDIR}/validationFormat_nomain.o: ${OBJECTDIR}/validationFormat.o validationFormat.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/validationFormat.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/validationFormat_nomain.o validationFormat.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/validationFormat.o ${OBJECTDIR}/validationFormat_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
