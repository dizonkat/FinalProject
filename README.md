# Pong!

## Overview
The classic Pong experience, featuring dynamic gameplay and innovative mechanics!

## External Libraries
- [SFML](https://github.com/SFML/SFML): Simple and Fast Multimedia Library
- [FreeType](https://gitlab.freedesktop.org/freetype/freetype): A Font Library for Rendering Fonts

## Build Instructions
SFML depends on a few other libraries, so before starting to configure you must have their development files installed.
On Windows and macOS, all the required dependencies are provided alongside SFML so you won't have to download/install anything else. Building will work out of the box.
On Linux however, nothing is provided. SFML relies on you to install all of its dependencies on your own. The way to get around this is to run *sudo apt-get install libsfml-dev* to install SFML from the repo directly into your system, along with all its dependencies. Once this is done, no further compilation, commands or linking is necessary. You can compile the project through CMake and the program will open and start immediately.
You need to download the sfml library onto your system before compiling. Once the sfml library is downloaded, the project will be able to use the libraries. Otherwise the CMAKE_MODULE_PATH will not be able to find the SFML package.
For Linux:
run *sudo apt-get install libsfml-dev* to install SFML from the repo directly into your system? Once this is done, no further compilation, commands or linking is necessary. You can compile the project through CMake and the program will open and start immediately.

## How to Play
To play, move the paddles with the up and down arrows.

## Gallery
![image](https://github.com/dizonkat/FinalProject/assets/38923686/c57937ed-dbbd-4717-b133-5e96ccf28e34)
