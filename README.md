# Pong!

## Overview
A single player Pong game written in C++ with simple but efficient controls, a resizeable window, and the flexibility for more C++ packages and features to be added in the future.

## External Libraries
- [SFML](https://github.com/SFML/SFML): Simple and Fast Multimedia Library
- [Vcpkg](https://github.com/Microsoft/vcpkg) a library package manager for C++

  SFML is a multimedia library for C++, built to be used for the creation of multimedia applications and games, and to run on multiple platforms and with CMake. It has five modules - system, window, graphics, audio, and network - and uses a number of external libraries of its own, so it was a perfect choice to start with as a baseline that still had plenty of functionality. We utilize it to create the game objects and screen, and provide baseline behavior for the graphics and animation.

  Vcpkg is a library package manager for C++ that makes it easy to implement, integrate, and install many C++ libraries for use in a project, without much hassle with "include"s and "find package". One of the packages it supports is SFML. With our project, one rooted in simplicity, but has ample options to build on it deven more, Vcpkg was the perfect choice. If we wanted to incorporate physics into our game, experiment with a main menu, or more, Vcpkg would make it easy to get the libraries accessible in our project. We were already thinking of the Box2D library and got the inspiration to use Vcpkg that way. 

## Build Instructions
In order to run this program, you need to download the vcpkg package onto your system if you don't already have it

For Ubuntu, you will have to run the following commands to download the necessary developer tools first (you can copy and past from here):
```sh
$ sudo apt-get update
$ sudo apt-get install build-essential tar curl zip unzip
```

For Ubuntu, there are further dependencies required by the sfml package itself.
You will need to run:
```sh
$ sudo apt-get install libx11-dev libxrandr-dev libxcursor-dev libxi-dev libudev-dev libgl1-mesa-dev autoconf libtool
```

On MacOS, you will need to run the following command:
```sh
$ xcode-select --install
```

You can can get vcpkg from the command line, but if you are using CLion, you also have the option to use their built in vcpkg integration, which will make it easier to download the project and other libraries/packages through it (for this project, just the SFML library) as well as use integrate the libraries with cmake with the proper toolchain. If you download vcpkg from the command line, you can still run and build the project in CLion. And if you already have vcpkg on your system, you can also use the CLion vcpkg integration and use it for this program/project and downloading sfml

To use the vcpkg CLion integration:
- Select View, then Tool Windows, then Vcpkg from the main menu
- This opens the "Add Vcpkg Repository" dialogue. Use https://github.com/Microsoft/vcpkg as the url
- In installation directory put where you want vcpkg to be installed, or the path to it if you already have it installed
- Make sure to check the "Add vcpkg integration to existing CMake profiles option"
- To integrate this library, a special cmake toolchain is used, and select the CMake profiles you want it to be added to (for this project you only need the one toolchain with vcpkg anyway). You can now find it added to the profile under CMake options
- Click ok
- Search for "sfml" in the search field to find the package
- Click the sfml package and install it
- CLion will prompt you to add it to vcpkg.json and then switch to manifest mode. WE MADE THIS PROJECT WITH CLASSIC MODE AND HAVE NOT TRIED/TESTED MANIFEST MODE, SO WE WOULD RECOMMEND NOT ADDING IT AND CREATING THE .JSON FILE TO CONTINUE WITH CLASSIC MODE. MANIFEST MODE SHOULD WORK IN THEORY THOUGH. WE ALSO HAVE NOT USED THE VCPKG INTEGRATION AND INSTALLED THROUGH COMMAND LINE AND UTILIZED THE TOOLCHAIN.
  - The vcpkg package/library has two modes: classic and manifest
  - Classic mode means vcpkg is integrated globally on your system and all you need is the toolchain. Any project using vcpkg can access a package you have installed with vcpkg, as the cmake search paths are appropriately set, and you can use "include" and "find package" freely like we did with sfml. The vcpkg library and and other libraries used in your project and downloaded with vcpkg don't need to be located inside the project and take up unncessary space
  - Manifest mode has a vcpkg json file and separate vcpkgs and installed packages for each project, but this project wasn't made that way (and thus doesn't have a vcpkg.json)

To download vcpkg (and sfml) through the command line:
```sh
$ git clone https://github.com/microsoft/vcpkg
```
Navigate to the vcpkg directory.
For windows run:
```cmd
> .\vcpkg\bootstrap-vcpkg.bat
```
And for Linux and Mac run:
```sh
$ ./bootstrap-vcpkg.sh
```
for all run:
```sh
$ ./vcpkg integrate install
```
This applies user-wide integration for the vcpkg root. (Classic Mode)
The terminal should tell you what CMake projects should use a toolchain. 
For CLion, you can go to settings -> Build, Execution, and Deployment -> CMake -> and paste the toolchain path given by the terminal into the "CMake options" in the CMake profile. Whether running from CLion after downloading from vcpkg from the terminal, or having done it straight through CLion, the toolchain should be all the program needs to run right from CLion, after SFML is downloaded.

To get sfml:
Navigate to the vcpkg directory and run:
```sh
$ ./vcpkg install sfml
```
Make sure you downloaded the Linux dependencies for sfml (stated above) beforehand.

To run the project from the command line:
```sh
$ cmake -B [build directory] -S . "-DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake"
$ cmake --build [build directory]
```
If you weren't provided a toolchain by the terminal, use the format above, or that can be pasted in.

## How to Play
To play, move the paddles with the up and down arrow keys on your keyboard. You can move and resize the window with your mouse, and click the "x" on the upper right hand corner to exit. The ball will bounce around the screen.

## Gallery
![image](https://github.com/dizonkat/FinalProject/assets/38923686/c57937ed-dbbd-4717-b133-5e96ccf28e34)
