EXEC = Sistema_Bancario_Simples.exe
CXX = g++
CXXFLAGS = -Wall -O0 -pedantic
OBJS = main.o Cliente.o ContaBancaria.o

$(EXEC): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS)

main.o: main.cpp Cliente.h ContaBancaria.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Cliente.o: Cliente.cpp Cliente.h
	$(CXX) $(CXXFLAGS) -c Cliente.cpp

ContaBancaria.o: ContaBancaria.cpp ContaBancaria.h Cliente.h
	$(CXX) $(CXXFLAGS) -c ContaBancaria.cpp

 clean:
	@if exist *.o del /Q *.o
	@if exist $(EXEC) del /Q $(EXEC)