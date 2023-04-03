#include <pybind11/pybind11.h>

int add(int i, int j)
{
    return i + j;
}

PYBIND11_MODULE(cmake_example, m)
{
    m.def("add", &add, "A function that adds two numbers");
}
