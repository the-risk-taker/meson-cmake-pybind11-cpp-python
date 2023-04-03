# Meson/CMake ➕ C++ ➕ pybind11 ➕ Python

A combination of C++ and Python to expose a simple API written in C++ to Python as a module. Achieved through the use of `pybind11`, a lightweight header-only library that facilitates the seamless integration of C++11 code with Python.

## Dependencies

- Meson/CMake
- pybind11
  - for Meson and manual building: `pip install pybind11`
  - for CMake: `git submodule update --init --recursive --remote`
- C++11 compatible compiler (Clang or GCC on Linux, MSVC on Windows)

## Building

### Manually

Building `example` module from `example.cpp`:

```shell
c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) example.cpp -o example_module$(python3-config --extension-suffix)
```

### Meson

```shell
meson setup build-meson
meson compile -C build-meson
python3 main.py build-meson
```

### CMake

```shell
cmake -S . -B build-cmake
cmake --build build-cmake
python3 main.py build-cmake
```

## Useful links

- [pybind11 docs](https://pybind11.readthedocs.io/en/stable/basics.html)
- [CMake pybind11](https://pybind11.readthedocs.io/en/stable/compiling.html#building-with-cmake)
- [Meson Python module](https://mesonbuild.com/Python-module.html#python_installation-object)
- [Thread about using Meson with pybind11](https://github.com/mesonbuild/meson/issues/4677)
