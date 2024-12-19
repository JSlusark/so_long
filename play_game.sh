#!/bin/bash

# Path to the directory containing the map files
MAP="maps/playable"

# Define color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
RESET='\033[0m' # No color

# Function to run the game executable and check output
run_levels() {
    local map=$1
    echo -e "${CYAN}Running map:${RESET} ${map}"

    # Run the executable with the current map
    ./linux "$map"
    exit_status=$?

    # Add a new line after each test
    echo
}

# Ensure the MAP directory exists
if [ ! -d "$MAP" ]; then
    echo -e "${RED}Error: Directory $MAP does not exist.${RESET}"
    exit 1
fi

# Loop through all .ber files in the map directory
for map in "$MAP"/*.ber; do
    if [ -f "$map" ]; then
        run_levels "$map"
    else
        echo -e "${YELLOW}No valid .ber files found in $MAP.${RESET}"
        break
    fi
done
