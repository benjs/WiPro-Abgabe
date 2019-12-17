BUILDDIR = build
INC=-I${CURDIR}/Aufgabe1/ -I${CURDIR}/Aufgabe2/ -I${CURDIR}/Aufgabe3/

CXX=g++
CXXFLAGS=-std=c++11 

LDFLAGS=-lgtest -lgtest_main -lpthread -L/usr/lib

all: createdir a1 a2 a3 test

createdir:
	@mkdir -p $(BUILDDIR)

a1: Aufgabe1/main_aufgabe1.cpp $(BUILDDIR)/MyQuaternion.o 
	@echo "Building first excercise."
	@$(CXX) -o $(BUILDDIR)/$@ $^

a2: Aufgabe2/main_aufgabe2.cpp $(BUILDDIR)/MyQuaternion.o $(BUILDDIR)/MyFunctions.o
	@echo "Building second excercise."
	@$(CXX) -o $(BUILDDIR)/$@ $^ $(INC)

a3: Aufgabe3/main_aufgabe3.cpp Aufgabe3/quarternion_functions.h $(BUILDDIR)/MyQuaternion.o $(BUILDDIR)/MyFunctions.o
	@echo "Building third excercise."
	@$(CXX) -o $(BUILDDIR)/$@ $^ $(INC)

test: Tests/test_main.cpp Tests/test_quaternion.cpp Tests/test_myfunctions.cpp Tests/test_aufgabe3.cpp $(BUILDDIR)/MyQuaternion.o $(BUILDDIR)/MyFunctions.o
	@echo "Building tests."
	@$(CXX) -o $(BUILDDIR)/$@ $^ $(INC) $(LDFLAGS)

$(BUILDDIR)/MyQuaternion.o: Aufgabe1/MyQuaternion.cpp
	@$(CXX) -c $< -o $@

$(BUILDDIR)/MyFunctions.o: Aufgabe2/MyFunctions.cpp
	@$(CXX) -c $< $(INC) -o $@

clean: 
	@rm -r build/