CXX			= g++

CXXFLAGS = -std=c++1z -Wconversion -Wall -Werror -Wextra -pedantic

EXECUTABLE = euler
EXECUTABLE_SOURCE = euler.cpp

# list of test drivers (with main()) for development
TESTSOURCES = $(wildcard test*.cpp)

# names of test executables
TESTS       = $(TESTSOURCES:%.cpp=%)

# list of sources used in project
OBJECTS             = $(wildcard *.o)
SOURCES 			= $(wildcard *.cpp)
NONTESTSOURCES     	= $(filter-out $(TESTSOURCES), $(SOURCES))
NONEXECUTABLESOURCES =  $(filter-out $(EXECUTABLE_SOURCE), $(SOURCES))

NONTESTOBJECTS		= $(NONTESTSOURCES:%.cpp=%.o)
TESTOBJECTS 		= $(NONEXECUTABLESOURCES:%.cpp=%.o)

all: $(EXECUTABLE)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp

$(EXECUTABLE): $(NONTESTOBJECTS)
	$(CXX) $(CXXFLAGS) $(NONTESTOBJECTS) -o $(EXECUTABLE)

define make_tests
    SRCS = $$(filter-out $$(EXECUTABLE_SOURCE), $$(NONTESTSOURCES))
    OBJS = $$(SRCS:%.cpp=%.o)
    HDRS = $$(wildcard *.h)
    $(1): CXXFLAGS += -g3 -DDEBUG
    $(1): $$(OBJS) $$(HDRS) $(1).cpp
	$$(CXX) $$(CXXFLAGS) $$(OBJS) $(1).cpp -o $(1)
endef
$(foreach test, $(TESTS), $(eval $(call make_tests, $(test))))


clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(TESTS) 

tests: clean $(TESTS)

.PHONY: all release debug profile clean alltests