#include "api.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(api, m)
{
    py::enum_<api::message_type>(m, "message_type")
        .value("RED", api::message_type::RED)
        .value("GREEN", api::message_type::GREEN)
        .value("BLUE", api::message_type::BLUE)
        .export_values();

    py::class_<api::message>(m, "message").def(py::init<>()).def_readwrite("type", &api::message::type).def_readwrite("data", &api::message::data);

    m.def("send", &api::send, "Send message");
    m.def("read", &api::read, "Read message");
}
