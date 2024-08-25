# One File Library

Does the same as the other programs in this repository with the only different 
that everything was written in only on file. Out of the 3, this maight be the 
easiest one to use on an online compiler if you are only given one file

## Programmer's advice

I personally think this is only ok for students new to programming, later on
you should try to write programs more similar to what is on `ProLibrary/`.
That version of the program has the following benefits:

- Entrypoint `main` is small:
  - Ony shows what it will do at a high level without caring much of the details.
- Maintainability:
  - Easier to read and therefore easier to understand (no scrolling up and down all the time).
- Separation of Concerns:
  - Each file is dedicated to only one thing.
  - No need to choose from prototypes or defining everything on top.
  - Use of header files will make it even more decoupled.