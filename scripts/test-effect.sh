#!/bin/bash

# Define the test executable directory
TEST_EXE_DIR="../build/bin"  # Updated to the correct directory
TEST_EXE="$TEST_EXE_DIR/KT_Effect_test"  # Path to the KT_Effect_test executable

# Check if the test executable directory exists
if [ ! -d "$TEST_EXE_DIR" ]; then
    echo "ERROR: Test executable directory not found"
    exit 1  # Exit with error status
else
    echo "..Running KT Audio Test..."

    # Check if the test executable exists
    if [ -f "$TEST_EXE" ]; then
        echo "Executing test: $TEST_EXE"
        "$TEST_EXE"  # Run the test executable
    else
        echo "ERROR: Test executable not found at $TEST_EXE"
        exit 1
    fi
fi
