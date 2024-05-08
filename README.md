# C and C++ Development Project

This project contains examples and utilities for C and C++ development.

## Project Structure

- `src/`: Contains the source code files.
  - `examples/`: Contains example C and C++ programs.
  - `init/`: Contains initial C and C++ "Hello, World!" programs.
- `docs/`: Contains documentation files.
  - `conventions.md`: Describes the coding conventions used in this project.
  - `report.md`: Contains a report on Unix development.
- `execute`: A shell script to compile and run C and C++ files.
- `.clang-format`: Configuration file for Clang Format.
- `.editorconfig`: Configuration file for Editor Configuration.
- `.gitattributes`: Configuration file for Git attributes.

## Coding Conventions

This project follows certain coding conventions for C and C++. For more details,
see [`conventions.md`](docs/conventions.md).

## Building and Running

To compile and run a C or C++ file, use the `execute` script:

```sh
./execute src/init/hello_world.c
```

This will compile the `hello_world.c` file and run the resulting executable.

## License

This project is licensed under the MIT License. See the [`LICENSE`](LICENSE)
file for more details.
