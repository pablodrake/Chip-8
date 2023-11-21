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
![Screenshot from 2023-11-21 13-16-30](https://github.com/pablodrake/Chip-8/assets/31321612/3553cc1d-33aa-4ddb-a71e-02eb9cb4428d)
![Screenshot from 2023-11-21 13-16-49](https://github.com/pablodrake/Chip-8/assets/31321612/4902618d-0173-412e-a190-8d8e3ccb4930)
### Kaleid
![Screenshot from 2023-11-21 13-14-58](https://github.com/pablodrake/Chip-8/assets/31321612/b2ae51a6-aa1c-4ed7-b187-29e5f3908925)



