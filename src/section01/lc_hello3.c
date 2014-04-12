/* Copyright (C) 2012 ~ 2013 Deepin, Inc.
 *               2012 ~ 2013 Long Changjin
 * 
 * Author:     Long Changjin <admin@longchangjin.cn>
 * Maintainer: Long Changjin <admin@longchangjin.cn>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// 该扩展是针对python3的
#include <Python.h>

static PyObject* test_function(PyObject *self);
static PyObject* add_function(PyObject *self, PyObject *args);

static PyMethodDef lc_hello_world_methods[] = {
    {"test", (PyCFunction)test_function, METH_NOARGS, "lc_hello_world extending test"},
    {"add", (PyCFunction)add_function, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef lc_hello_world_module = {
    PyModuleDef_HEAD_INIT,
    "lc_hello_world",        /* name of module */
    NULL,                    /* module documentation, may be NULL */
    -1,                      /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    lc_hello_world_methods   /* A pointer to a table of module-level functions, described by PyMethodDef values. Can be NULL if no functions are present. */
};

PyMODINIT_FUNC PyInit_lc_hello_world(void)
{
    PyObject *m;
    m = PyModule_Create(&lc_hello_world_module);
    if (m == NULL)
        return NULL;
    printf("init lc_hello_world module\n");
    return m;
}

static PyObject* test_function(PyObject *self)
{
    PyObject_Print(self, stdout, 0);
    printf("lc_hello_world test\n");
    Py_INCREF(Py_True);
    return Py_True;
}

static PyObject* add_function(PyObject *self, PyObject *args)
{
    int num1, num2;
    PyObject *result=NULL;
    if (!PyArg_ParseTuple(args, "nn", &num1, &num2)) {
        printf("传入参数错误！\n");
        return NULL;
    }
    result = PyLong_FromLong(num1+num2);
    return result;
}

