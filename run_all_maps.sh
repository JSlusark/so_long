#!/bin/bash

# Path to the directory containing the map files
MAP_INV="./maps/invalid_map/"
MAP_VAL="./maps/valid_map/"

# Define color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
RESET='\033[0m' # No color

# Loop through each file in the directory and run the so_long program
for map in "$MAP_INV"/*
do
    echo -e "${CYAN}Running invalid maps:${RESET} ${RED}$map${RESET}"

    # Run the program
    ./so_long "$map"

    # Check if the program exited with a non-zero status
    if [ $? -ne 0 ]; then
        echo -e "${RED}EXITED${RESET}"
    else
        echo -e "${GREEN}Test passed: No exit encountered.${RESET}"
    fi
	   # Add a new line after each test
    echo

done

# Loop through each file in the directory and run the so_long program
for map in "$MAP_VAL"/*
do
    echo -e "${CYAN}Running valid maps:${RESET} ${GREEN}$map${RESET}"

    # Run the program
    ./so_long "$map"

    # Check if the program exited with a non-zero status
    if [ $? -ne 0 ]; then
        echo -e "${RED}EXITED${RESET}"
    else
        echo -e "${GREEN}PASSED.${RESET}"
    fi
	   # Add a new line after each test
    echo

done
