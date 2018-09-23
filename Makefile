FLAGS_DEBUG = -std=c++14 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -g
FLAGS_RELEASE = -std=c++14 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -O2
OUTPUT_DIRECTORY = bin

PLATFORM := $(shell uname -s)
ifeq ($(PLATFORM),Darwin)
	COMPILER = clang++
	OS = MAC
else
	COMPILER = g++
	OS = LINUX
endif

THREADING_SOURCES = $(wildcard Threading/*.cpp)
ALLOCATOR_SOURCES = $(wildcard Allocators/*.cpp)
DATASTRUCTURE_SOURCES = $(wildcard DataStructures/*.cpp)
SERIALIZATION_SOURCES = $(wildcard Serialization/*.cpp)
PHYSICS_SOURCES = $(wildcard Physics/*.cpp)
AI_SOURCES = $(wildcard AI/*.cpp)
GRAPHICS_SOURCES = $(wildcard Graphics/*.cpp)
NETWORKING_SOURCES = $(wildcard Networking/*.cpp)
CORE_SOURCES = $(wildcard Core/*.cpp)

THREADING_OBJECTS = $(THREADING_SOURCES:Threading/%.cpp=$(OUTPUT_DIRECTORY)/%.o)
ALLOCATOR_OBJECTS = $(ALLOCATOR_SOURCES:Allocators/%.cpp=$(OUTPUT_DIRECTORY)/%.o)
DATASTRUCTURE_OBJECTS = $(DATASTRUCTURE_SOURCES:DataStructures/%.cpp=$(OUTPUT_DIRECTORY)/%.o)
SERIALIZATION_OBJECTS = $(SERIALIZATION_SOURCES:Serialization/%.cpp=$(OUTPUT_DIRECTORY)/%.o)
PHYSICS_OBJECTS = $(PHYSICS_SOURCES:Physics/%.cpp=$(OUTPUT_DIRECTORY)/%.o)
AI_OBJECTS = $(AI_SOURCES:AI/%.cpp=$(OUTPUT_DIRECTORY)/%.o)
GRAPHICS_OBJECTS = $(GRAPHICS_SOURCES:Graphics/%.cpp=$(OUTPUT_DIRECTORY)/%.o)
NETWORKING_OBJECTS = $(NETWORKING_SOURCES:Networking/%.cpp=$(OUTPUT_DIRECTORY)/%.o)
CORE_OBJECTS = $(CORE_SOURCES:Core/%.cpp=$(OUTPUT_DIRECTORY)/%.o)

ALL_OBJECTS = $(THREADING_OBJECTS) $(ALLOCATOR_OBJECTS) $(DATASTRUCTURE_OBJECTS)\
	$(SERIALIZATION_OBJECTS) $(PHYSICS_OBJECTS) $(AI_OBJECTS) $(GRAPHICS_OBJECTS)\
	$(NETWORKING_OBJECTS) $(CORE_OBJECTS)

DEPENDENCIES = $(ALL_OBJECTS:%.o=%.d)

all: debug

debug: Config_d GameEngine.out test

release: Config_r GameEngine.out

Config_d:
	echo "#define PLATFORM $OS" > Config/Platform.h
	echo "#define DEBUG" > Config/DebugRelease.h
	export FLAGS = $(FLAGS_DEBUG)

Config_r:
	echo "define PLATFORM $OS" > Config/Platform.h
	echo "" > Config/DebugRelease.h
	export FLAGS = $(FLAGS_RELEASE)

-include $(DEPENDENCIES)

$(THREADING_OBJECTS): %.o: %.c
	$(COMPILER) $$FLAGS -MMD -c $< -o $@ -lpthreads

$(ALLOCATOR_OBJECTS): %.o: %.c
	$(COMPILER) $$FLAGS -MMD -c $< -o $@

$(DATASTRUCTURE_OBJECTS): %.o: %.c
	$(COMPILER) $$FLAGS -MMD -c $< -o $@

$(SERIALIZATION_OBJECTS): %.o: %.c
	$(COMPILER) $$FLAGS -MMD -c $< -o $@

$(PHYSICS_OBJECTS): %.o: %.c
	$(COMPILER) $$FLAGS -MMD -c $< -o $@

$(AI_OBJECTS): %.o: %.c
	$(COMPILER) $$FLAGS -MMD -c $< -o $@

$(GRAPHICS_OBJECTS): %.o: %.c
	$(COMPILER) $$FLAGS -MMD -c $< -o $@

$(NETWORKING_OBJECTS): %.o: %.c
	$(COMPILER) $$FLAGS -MMD -c $< -o $@

$(CORE_OBJECTS): %.o: %.c
	$(COMPILER) $$FLAGS -MMD -c $< -o $@

$(OUTPUT_DIRECTORY)/Tests.o: Tests.cpp
	$(COMPILER) $$FLAGS -c Tests.cpp -o $(OUTPUT_DIRECTORY)/Tests.o

$(OUTPUT_DIRECTORY)/main.o: main.cpp
	$(COMPILER) $$FLAGS -c main.cpp -o $(OUTPUT_DIRECTORY)/main.o

test: $(OUTPUT_DIRECTORY)/Tests.o $(ALL_OBJECTS)
	$(COMPILER) $$FLAGS $(OUTPUT_DIRECTORY)/Tests.o $(ALL_OBJECTS) -o UnitTests.out
	$(OUTPUT_DIRECTORY)/UnitTests.out

GameEngine.out: $(OUTPUT_DIRECTORY)/main.o $(ALL_OBJECTS)
	$(COMPILER) $$FLAGS $(OUTPUT_DIRECTORY)/main.o $(ALL_OBJECTS) -o GameEngine.out

.PHONY: clean
clean:
	rm $(OUTPUT_DIRECTORY)/*
