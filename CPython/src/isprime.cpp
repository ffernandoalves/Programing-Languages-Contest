#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <cmath>
#include <iostream>
#include <time.h>

static PyObject *is_prime(PyObject *self, PyObject *args) {
    int num;
    if (PyTuple_Check(args)) {
        if (!PyArg_ParseTuple(args, "i", &num)) {
            return NULL;    
        }
    } else {
        num = PyLong_AsLong(args);
    }

    if (num == 2) { Py_RETURN_TRUE ; } // { return Py_BuildValue("i", num) ; } // 
    else if ((num <= 1) || (num % 2 == 0)) { Py_RETURN_FALSE; }

    int i_sqrt_num = (int)sqrt(num);

    for (int div = 3; div < i_sqrt_num + 1; div+=2) {
        if (num % div == 0) { Py_RETURN_FALSE; }
    }

//    return Py_BuildValue("i", num);
    Py_RETURN_TRUE;
}


static PyObject *run_program(PyObject *self, PyObject *args) {
    int N;

    if (PyTuple_Check(args)) {
        if (!PyArg_ParseTuple(args, "i", &N)) {
            return NULL;    
        }
    } else {
        N = PyLong_AsLong(args);
    }

    for (int i = 0; i < N; i++) {
        is_prime(self, PyLong_FromLong(i));
    }
}


static PyObject *check_primes(PyObject *self, PyObject *args, PyObject *kwargs) {
    int N = 10000000;
    const char *keywords[5] = {"N", NULL};
    PyArg_ParseTupleAndKeywords(args, kwargs, "|i", const_cast<char **>(keywords), &N);

    clock_t start, end;
    start = clock();

    run_program(self, PyLong_FromLong(N));

    end = clock();
    std::cout << "time: " << (end - start) / ((double)CLOCKS_PER_SEC) << std::endl;

    Py_RETURN_NONE;
}



//===================PYTHON_MODULE_DEFINITION==========================
static PyMethodDef IsPrimeMethods[] = {
    {"is_prime"    , (PyCFunction)is_prime, METH_VARARGS, NULL},
//    {"run_program" , (PyCFunction)run_program , METH_VARARGS, NULL},
    {"check_primes", (PyCFunction)check_primes, METH_VARARGS | METH_KEYWORDS, NULL},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef IsPrimeModule = {
    PyModuleDef_HEAD_INIT,
    "isprime",              /* m_name     */
    "sem doc",              /* m_doc      */
    -1,                     /* m_size     */
    IsPrimeMethods,         /* m_methods  */
    NULL,                   /* m_reload   */
    NULL,                   /* m_traverse */
    NULL,                   /* m_clear    */
    NULL,                   /* m_free     */
};

PyMODINIT_FUNC PyInit_isprime(void){
    Py_Initialize();
    return PyModule_Create(&IsPrimeModule);
}
