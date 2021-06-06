# Makefile to build a project from .cpp files.

# Constants
TRUE = true
FALSE = false

# Chosen compiler
CC = g++

# Chosen modes
DEBUG_MODE = Debug
RELEASE_MODE = Release

BUILD_MODE = $(DEBUG_MODE)
AUTO_RUN = $(TRUE)

# Flags for two build modes
RELEASE_FLAGS = -O3 -s -DNDEBUG
DEBUG_FLAGS = -O0 -g

# EXECUTABLE - use unix commands to find a file with the 'main ()' function and only returns the filename
# COUNTER - returns size of list .cpp files with 'main ()' function
# SOURCES - returns list of all .cpp files
EXECUTABLE = $(shell grep -ril ' main *()*' . | grep -i ".*cpp" | sed -r 's/^.\/(\w+\/)+//' | sed -r 's/.cpp//')
COUNTER = $(shell grep -ril ' main *()*' . | grep -i ".*cpp" |  wc -l)
SOURCES = $(shell find . -name '*.cpp')

# Run build
all: build run
	@echo "makefile: Build successfully!"

# If there are more than one files with the 'main ()' function,\
  then they give an error
check:
ifneq ($(COUNTER),1)
	$(error More then one 'main ()' function)
endif

# Build project
build:
ifeq ($(BUILD_MODE), $(DEBUG_MODE))
all: debug
else
all: release
endif

# Run program after build
run:
ifeq ($(AUTO_RUN),$(TRUE))
ifeq ($(BUILD_MODE), $(DEBUG_MODE))
all: drun
else
all: rrun
endif
endif

# Debug build
debug: check rm_debug
	$(shell mkdir -p $(DEBUG_MODE))
	$(CC) $(DEBUG_FLAGS) $(SOURCES) -o $(DEBUG_MODE)/$(EXECUTABLE)

# Release build
release: check rm_release
	$(shell mkdir -p $(RELEASE_MODE))
	$(CC) $(RELEASE_FLAGS) $(SOURCES) -o $(RELEASE_MODE)/$(EXECUTABLE)

# Run debug executable file
drun:
	@$(DEBUG_MODE)/$(EXECUTABLE)

# Run release executable file
rrun:
	@$(RELEASE_MODE)/$(EXECUTABLE)

.PHONY: clean rm_debug rm_release

# Remove folders with executable files
clean: rm_debug rm_release

rm_debug:
	@rm -rf $(DEBUG_MODE)

rm_release:
	@rm -rf $(RELEASE_MODE)