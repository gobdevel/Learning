CXXFLAGS = -Wall -Werror -std=c++17 -O1
LDLIBS =

PRGM  = webApp
SRCS := $(wildcard *.cc)
OBJS := $(SRCS:.cc=.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all clean

all: $(PRGM)

$(PRGM): $(OBJS)
	$(CXX) $(OBJS) $(LDLIBS) -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJS) $(DEPS) $(PRGM)

-include $(DEPS)
