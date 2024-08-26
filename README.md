# PADD-PDA

A stylized PDA application

```
TODO: Add instructions for other operating systems and toolchains
```

## Hardware

Runs on a Raspberry Pi Zero 2 W with a touchscreen module

## Build Requirements

The following is a list of system packages that need to be installed for PDA to build

- CMake
- SDL2 (debian: `libsdl2-dev`)
- SDL Image (debian: `libsdl2-image-dev`)
- SDL TTF (debian: `libsdl2-ttf-dev`)

```
apt install cmake libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
```

In order to build for aarch64 targets, you will also need the following dependencies:

- `binutils-aarch64-linux-gnu`
- `gcc-aarch64-linux-gnu`
- `g++-aarch64-linux-gnu`

## Build instructions

### Compiling for native system architecture (x86_64, aarch64, armv7, etc.)

If you are compiling this for an architecture that matches your host system, or you are compiling for your host system:

- Create a new folder (it doesn't matter the name though I would suggest `build` as it's tracked in the gitignore, it **cannot** be in the project root) and set the working directory to that folder
- Run `cmake ..`
- Run `make`
- All you need to do is run the executable file built by make

### Cross-compiling for a system architecture other than the host

If you are compiling this for an architecture that does *not* match your host system, ensure you have the dependencies required to cross compile for that target. Toolchains for the project exist in the `toolchain` folder, though you may create your own if neccessary or you want finer controls and configurations. It is reccommended to keep toolchains in the `toolchain` folder to avoid cluttering the root directory.

Same steps apply as above, however when you run cmake add the following option: `-DCMAKE_TOOLCHAIN_FILE=<toolchain_file-here>`