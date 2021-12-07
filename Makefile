SRCDIR   = ./
OBJDIR   = ./
EXEDIR   = ./
TARGET   = chess
CXX      = g++

SRC      = $(wildcard $(addsuffix *.cpp,$(SRCDIR)))

OBJ      = $(addprefix $(OBJDIR), $(patsubst %.cpp, %.o, $(notdir $(SRC))))

VPATH    = $(SRCDIR)

CXXFLAGS = -Wall -g -std=c++2a

$(TARGET) : $(OBJ)
	@echo Linking...
	@$(CXX) $(CXXFLAGS) -o $(EXEDIR)$@ $(OBJ)

$(OBJDIR)%.o : %.cpp
	@echo Compiling $< in $@...
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean

clean :
	rm *.o
