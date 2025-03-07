# Define the path to the Micro:bit device
MICROBIT_PATH = /Volumes/MICROBIT

# Get the current Git commit hash and date/time at runtime
GIT_COMMIT = $(shell git rev-parse --short HEAD)
BUILD_DATE = $(shell date +%Y%m%d)
BUILD_TIME = $(shell date +%H%M%S)

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 \
           -I/Users/leannanguyen/project/microbit/microbit-v2-samples/libraries \
           -Iincludes -Iincludes/health_tracker \
           -I/usr/local/include/microbit-dal \
           -I/Users/leannanguyen/project/microbit/microbit-v2-samples/utils

# Add all subdirectories under the libraries directory
CXXFLAGS += $(shell find /Users/leannanguyen/project/microbit/microbit-v2-samples/libraries -type d -exec echo -I{} \; > /dev/null)

# Add all subdirectories under the utils directory
CXXFLAGS += $(shell find /Users/leannanguyen/project/microbit/microbit-v2-samples/utils -type d -exec echo -I{} \; > /dev/null)

# Add a target to generate codal_version.h from codal_version.h.in
CODAL_VERSION_H = /Users/leannanguyen/project/microbit/microbit-v2-samples/libraries/codal-core/inc/core/codal_version.h

# Force re-generation of codal_version.h
$(CODAL_VERSION_H): /Users/leannanguyen/project/microbit/microbit-v2-samples/libraries/codal-core/inc/core/codal_version.h.in
	@echo "Generating codal_version.h from codal_version.h.in..."
	cp $< $@
	@touch $@  # Force Make to think it's been updated

# Directories
SRC_DIR = source/health_tracker
BUILD_DIR = build
HEX_DIR = $(BUILD_DIR)/hex

# Find all source files and corresponding object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Default target (only builds)
all: MICROBIT_$(GIT_COMMIT)_$(BUILD_DATE)_$(BUILD_TIME).hex

# Compile each .cpp file into an object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(CODAL_VERSION_H)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to generate final .hex file
MICROBIT_$(GIT_COMMIT)_$(BUILD_DATE)_$(BUILD_TIME).hex: $(OBJS) $(CODAL_VERSION_H)
	@echo "Building HEX file..."
	@mkdir -p $(HEX_DIR)
	cd $(BUILD_DIR) && cmake .. && make
	@mv MICROBIT.hex MICROBIT_$(GIT_COMMIT)_$(BUILD_DATE)_$(BUILD_TIME).hex
	@echo "Build complete!"

# Flash target (ONLY runs when explicitly called)
flash: MICROBIT_$(GIT_COMMIT)_$(BUILD_DATE)_$(BUILD_TIME).hex
	@echo "Flashing to Micro:bit..."
	@cp MICROBIT_$(GIT_COMMIT)_$(BUILD_DATE)_$(BUILD_TIME).hex $(MICROBIT_PATH)
	@echo "Done!"

# Clean target
clean:
	@echo "Cleaning build directory..."
	rm -rf $(BUILD_DIR)
	@echo "Clean complete!"
