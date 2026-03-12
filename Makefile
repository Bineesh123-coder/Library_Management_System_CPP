CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = library_management_system
SRC = library_management_system.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)