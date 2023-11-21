# Chip-8 Emulator


A simple Chip-8 emulator written in c++. This project aims to provide a basic and cross platform implementation of a Chip-8 emulator for educational purposes.


## About

This Chip-8 emulator project was developed as a simple side-project to understand the internals of computer systems.
### Features

  + Interpreter: Basic implementation of the Chip-8 interpreter.
  + Display: Emulation of the Chip-8 display with basic graphics rendering.
  + Input Handling: Keyboard input handling for Chip-8 keypad.
  + Tests: The emulator is currently capable of passing the tests from [Timendus' Chip-8 Test Suite](https://github.com/Timendus/chip8-test-suite) (except for the Quirks test and the GetKey test).

## Getting Started
### Prerequisites

  + Install cmake and SDL2 in your computer and link the dependencies.

## Installation

  Clone the repository:

    https://github.com/pablodrake/Chip-8.git
    
Build the emulator:

    cd Chip-8/build
    make

## Usage

Run the emulator and specify the full path of a compatible ROM(Included [Zophar's](https://www.zophar.net/pdroms/chip8.html
) ROMS in the data folder).

## Screenshots

### Space Invaders
![Screenshot from 2023-11-21 13-16-30](https://github.com/pablodrake/Chip-8/assets/31321612/a1857e16-892c-4078-b1b9-f7630f5ed7d0)
![Screenshot from 2023-11-21 13-16-49](https://github.com/pablodrake/Chip-8/assets/31321612/bf6691f3-8496-4157-8667-5b35f36aacd5)

### Kaleid
![Screenshot from 2023-11-21 13-14-58](https://github.com/pablodrake/Chip-8/assets/31321612/7137ac2c-cc62-4dc6-8e2a-37b630e7dae0)


