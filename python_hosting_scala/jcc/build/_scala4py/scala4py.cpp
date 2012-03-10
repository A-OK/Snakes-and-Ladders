#include <Python.h>
#include "macros.h"
#include "jccfuncs.h"

PyObject *initJCC(PyObject *module);
void __install__(PyObject *module);
extern PyTypeObject PY_TYPE(JObject), PY_TYPE(ConstVariableDescriptor), PY_TYPE(FinalizerClass), PY_TYPE(FinalizerProxy);
extern void _install_jarray(PyObject *);

extern "C" {

    void init_scala4py(void)
    {
        PyObject *module = Py_InitModule3("_scala4py", jcc_funcs, "");

        initJCC(module);

        INSTALL_TYPE(JObject, module);
        INSTALL_TYPE(ConstVariableDescriptor, module);
        INSTALL_TYPE(FinalizerClass, module);
        INSTALL_TYPE(FinalizerProxy, module);
        _install_jarray(module);
        __install__(module);
    }
}
