# Simple Library example in C++

This repository shows how to implement a basic library program with c++.

## Getting Started

To run this software, make sure you have a C++ compiler installed in your machine. 
Otherwise, find an online compiler and copy-paste the code to that environment.

### Downloading the example

You can download this example by either, downloading the code as zip or 
by clonning the repo. 

### Running locally

#### Windows (g++ command)

Check if your terminal recognize the `g++` command by running
```
g++ --version
```

If not, the follow these steps to configure your Visual Studio Code (takes around 10 minutes to complete)
- [C/C++ for Visual Studio Code](https://code.visualstudio.com/docs/languages/cpp)
  - The most important section is: [Example: Install MinGW-x64 on Windows](https://code.visualstudio.com/docs/languages/cpp#_example-install-mingwx64-on-windows)

#### MacOs (via terminal)

To run this program locally, first run this to compile the code:
```
g++ ./proLibrary.cpp -o proLibrary.out
```

Then, run this to execute the program:
``` 
./proLibrary.out
```

### Some IDEs

You may also use some of the following IDEs to run your code:
- Visual Studio Community
- Visual Studio Code (with Extensions)
- CLion (not free)
- XCode (mac only)

## Project Structure
 This project contains the same program 3 times but written differently:
 - `OneFileLibrary` contains the program in one file.
 - `OverDocumentedLibrary` this is similar to `ProLibrary` but with more comments as guidance.
 - `ProLibrary` follows some best practices

 ## Enhanncing

 Feel free to use this program and enhance it with more best practices, data structures, and more complex models. Or if you feel like an expert and like challenges, you may also connect to a real database. Repository will remain read only so that no one can push code to it and allow other students to start from the same place as you.