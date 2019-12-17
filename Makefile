BUILDDIR = build
INC=-I${CURDIR}/Aufgabe1/ -I${CURDIR}/Aufgabe2/ 

CXX=g++
CXXFLAGS=-std=c++11 

all: createdir a1 a2 a3

createdir:
	@mkdir -p $(BUILDDIR)

a1: Aufgabe1/main_aufgabe1.cpp $(BUILDDIR)/MyQuaternion.o 
	@echo "Building first excercise."
	@echo $(INC)
	$(CXX) -o $(BUILDDIR)/$@ $^

a2: Aufgabe2/main_aufgabe2.cpp $(BUILDDIR)/MyQuaternion.o $(BUILDDIR)/MyFunctions.o
	@echo "Building second excercise."
	$(CXX) -o $(BUILDDIR)/$@ $^ $(INC)

a3: Aufgabe3/main_aufgabe3.cpp $(BUILDDIR)/MyQuaternion.o $(BUILDDIR)/MyFunctions.o
	@echo "Building third excercise."
	$(CXX) -o $(BUILDDIR)/$@ $^ $(INC)

$(BUILDDIR)/MyQuaternion.o: Aufgabe1/MyQuaternion.cpp
	$(CXX) -c $< -o $@

$(BUILDDIR)/MyFunctions.o: Aufgabe2/MyFunctions.cpp
	$(CXX) -c $< $(INC) -o $@
