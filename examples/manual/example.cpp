// depends on pybind11 installed with pip
// compile with: c++ -O3 -Wall -shared -fPIC -std=c++11 $(python3 -m pybind11 --includes) example.cpp -o example$(python3-config --extension-suffix)

#include <pybind11/pybind11.h>

int add(int i, int j)
{
    return i + j;
}

PYBIND11_MODULE(example, m)
{
    m.def("add", &add, "A function that adds two numbers");
}
