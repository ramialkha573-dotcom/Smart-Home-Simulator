CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = SmartHomeSimulator
SRCS = Device.cpp Light.cpp AirConditioner.cpp Television.cpp SmartHome.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean
