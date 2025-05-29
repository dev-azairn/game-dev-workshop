# CMake 

## What is CMake?
CMake is the software build system that allows using multiple files in a single project. 

You can read the full documentation and very helpful tutorial by the official documentation.
[Click here](https://cmake.org/cmake/help/latest/guide/tutorial/index.html) 

## Why using CMake?
In this workshop, we mostly use multiple header files and open source librarys which is not included in system library.

Using MakeFiles would be using many flags.

Therefore, I would like to introduce you about CMake to build projects for us!

## Basic Setup
Firstly, you need to create `CMakeLists.txt` file to setup all need in your C/C++ project. 

Next, you need to have these 3 lines in your file.

```CMake
# Define CMake minimun version e.g. 3.15
cmake_minimum_required(VERSION 3.15)

# Setup project name
project(ProjectName)

# To create an executable file
add_executable(ProjectName file_to_compile.c)
```

## Set
Set the variable with value.
### Set C++ Version
use variable `CMAKE_CXX_STANDARD` version and `CMAKE_CXX_STANDARD_REQUIRED`
```CMake
set(CMAKE_CXX_STANDARD 21)
set(CMAE_CXX_STANDARD_REQUIRED True)
```

