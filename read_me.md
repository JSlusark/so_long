# About the project:
So_long is a simple 2D game made as an assignment at 42 school. You play as a cute mushroom fairy who needs to collect colorful mushrooms, avoid touching the deadly ones, so that she can reach the cauldron to win the game and have soup! 😋🍄

# Tools used:
Instead of using modern game engines, this project was built using the MinilibX library, a simplified version of the X-Window (X11R6) programming API in C.

The game's functionalities were completely built from scratch with custom made implementations that handle different aspects such as: rendering each tile, frame animation and keyboard interaction, cross-platform support for macOS and Linux, in-game error handling for unplayable and oversized maps or missing assets, memory management to prevent leaks and more.


# How to Build and Run the Game

### Compilation

To compile the executable, in the terminal run:

`make`

The Makefile is configured to detect your operating system (Linux or macOS) and compile accordingly.
macOS: Integrated with AppKit and OpenGL.
Linux: Uses X Window System and X11.

### Running the Game

To play the game, run the following command:

`./game maps/mapfile.ber`

Alternatively, you can run all levels using the created script:

`./play_all_levels.sh`

### Testing and debugging

*I also created scripts to test and handle different scenarios:*

**test_wrong_format.sh** runs all invalid maps from the maps/wrong_format directory and:
 - Checks the exit codes.
 - Validates leaks (only on Linux using Valgrind).
 - Prints the specific type of error encountered.
 Maps are considered invalid if they are not rectangular, not framed by walls, contain invalid symbols and contain empty lines.

**test_unplayable.sh** runs all unplayable maps from the maps/unplayable directory.
Maps are considered unplayable when the map is bigger than the computer screen or when the player is not able to reach all collectibles and reach the cauldron to complete the game.
 - Checks the exit codes.
 - Validates leaks (only on Linux using Valgrind).
 - Prints the specific type of error encountered.

**test_playable.sh** runs all playable maps from the maps/unplayable directory.
- Checks the exit codes.
- Validates leaks (only on Linux using Valgrind).
- If leaks are present, it prints details of leaks.

#### About leaks
- **Linux:** Leak-free and verified with Valgrind (mandatory at 42 Berlin school to pas the project's requirements).
- **macOS:** Known minor leaks due to differences in memory handling within MinilibX for linux (optional, to be fixed in a later moment)

### Gameplay

**Objective:**
Collect all the colorful mushrooms.
Avoid deadly mushrooms.
Reach the cauldron to complete the level.

**Controls:**
Move the character using arrow keys or WASD.
Exit the game using Q, ESC, or by clicking the exit button.

**Resolution:**
The game's resolution was meant to be fixed. No support for scaling or expansion is needed.

**Sprites and Animations**
Character Sprite:
Initially based on a design from <artist> (reference to the base inspiration) as I really liked the cute, fairy like feel of the character. It was then replaced with a custom-designed character sprite created by me and inspired to such character.

**Animation and Pixel Art:**
All animation sprites and pixel art were created by me.
The pixel art was kept simple without focusing on high resolution or advanced techniques.

**Level Design:**
The character collects mushrooms to prepare mushroom soup.Deadly mushrooms kill the character instantly.

### How to Contribute

Feel free to explore the codebase, create more maps and play the game.
Also thank you for passing by and tested things out if you have 😊

