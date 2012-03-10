#ifndef scala_Serializable_H
#define scala_Serializable_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
}
template<class T> class JArray;

namespace scala {

    class Serializable : public ::java::lang::Object {
    public:

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static jclass initializeClass();

        explicit Serializable(jobject obj) : ::java::lang::Object(obj) {
            if (obj != NULL)
                initializeClass();
        }
        Serializable(const Serializable& obj) : ::java::lang::Object(obj) {}
    };
}

#include <Python.h>

namespace scala {
    extern PyTypeObject PY_TYPE(Serializable);

    class t_Serializable {
    public:
        PyObject_HEAD
        Serializable object;
        static PyObject *wrap_Object(const Serializable&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
    };
}

#endif
