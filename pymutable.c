#include "Python.h"

PyObject *mutateInt(PyObject *self, PyObject *args) {
    PyObject *a = NULL;
    PyObject *b = NULL;
    if (!PyArg_ParseTuple(args, "OO", &a, &b))
        return NULL;
    PyLongObject *a1 = (PyLongObject *) a;
    PyLongObject *b1 = (PyLongObject *) b;
    a1->ob_digit[0] = b1->ob_digit[0];
    Py_RETURN_NONE;
}

PyObject *mutateFloat(PyObject *self, PyObject *args) {
    PyObject *a = NULL;
    PyObject *b = NULL;
    if (!PyArg_ParseTuple(args, "OO", &a, &b))
        return NULL;
    PyFloatObject *a1 = (PyFloatObject *) a;
    PyFloatObject *b1 = (PyFloatObject *) b;
    a1->ob_fval = b1->ob_fval;
    Py_RETURN_NONE;
}

PyObject *mutateComplex(PyObject *self, PyObject *args) {
    PyObject *a = NULL;
    PyObject *b = NULL;
    if (!PyArg_ParseTuple(args, "OO", &a, &b))
        return NULL;
    PyComplexObject *a1 = (PyComplexObject *) a;
    PyComplexObject *b1 = (PyComplexObject *) b;
    a1->cval.real = b1->cval.real;
    a1->cval.imag = b1->cval.imag;
    Py_RETURN_NONE;
}

PyObject *mutateTupleSetItem(PyObject *self, PyObject *args) {
    PyObject *a = NULL;
    int b;
    PyObject *c = NULL;
    if (!PyArg_ParseTuple(args, "OiO", &a, &b, &c))
        return NULL;
    PyTuple_SET_ITEM(a, b, c);
    Py_RETURN_NONE;
}

static PyMethodDef methods[] = {
    {"mutate_int", mutateInt, METH_VARARGS},
    {"mutate_float", mutateFloat, METH_VARARGS},
    {"mutate_complex", mutateComplex, METH_VARARGS},
    {"mutate_tuple_set_item", mutateTupleSetItem, METH_VARARGS},
    {NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "pymutable",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit_pymutable(void) {
    return PyModule_Create(&module);
}
