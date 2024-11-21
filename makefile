CXX=g++
TARGET=brainfuck
DEBUG_FLAG=-fdiagnostics-color=always -g
CXXFLAGS= -Wno-psabi -std=c++0x

SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:src/%cpp=src/%o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

src/%.o: src/%.cpp
	${CXX} $(DEBUG_FLAG) $(CXXFLAGS) -c $< -o $@

run:
	./$(TARGET) source

clean:
	rm -f $(TARGET) src/*.o