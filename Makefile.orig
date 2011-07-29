# output executable name
EXEC = checkpoint_check
# source files
CXX = g++
CXXFLAGS = -W -Wall -Iinclude/
LDFLAGS =
SRCS = $(wildcard src/*.cpp)
INCS = $(wildcard inc/*.h)
OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC) : obj/$(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

obj/%.o : %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)


.PHONY: clean mrproper

clean :
	rm -rf obj/$(OBJS)

doc : $(SRCS) $(INCS)
	doxygen doc/Doxyfile

mrproper: clean
	@rm $(EXEC)
