#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "lina_types/Array.hpp"

namespace py = pybind11;

template <typename T>
void bind_array(py::module& m, const std::string& name) {
    py::class_<Array<T>>(m, name.c_str())
        .def(py::init<>())
        .def(py::init<const std::vector<T>&>())
        .def("size", &Array<T>::size)
        .def("__getitem__", (T& (Array<T>::*)(size_t)) &Array<T>::operator[], py::return_value_policy::reference)
        .def("__getitem__", (const T& (Array<T>::*)(size_t) const) &Array<T>::operator[], py::return_value_policy::reference)
        .def("set", &Array<T>::set)
        .def("display", &Array<T>::display);
}

PYBIND11_MODULE(lina_types, m) {
    m.doc() = "lina_types module";

    bind_array<int>(m, "ArrayInt");
    bind_array<double>(m, "ArrayDouble");
    bind_array<float>(m, "ArrayFloat");
}