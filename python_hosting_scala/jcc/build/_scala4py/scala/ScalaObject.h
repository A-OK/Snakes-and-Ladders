#ifndef scala_ScalaObject_H
#define scala_ScalaObject_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
}
template<class T> class JArray;

namespace scala {

    class ScalaObject : public ::java::lang::Object {
    public:

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static jclass initializeClass();

        explicit ScalaObject(jobject obj) : ::java::lang::Object(obj) {
            if (obj != NULL)
                initializeClass();
        }
        ScalaObject(const ScalaObject& obj) : ::java::lang::Object(obj) {}
    };
}

#include <Python.h>

namespace scala {
    extern PyTypeObject PY_TYPE(ScalaObject);

    class t_ScalaObject {
    public:
        PyObject_HEAD
        ScalaObject object;
        static PyObject *wrap_Object(const ScalaObject&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
    };
}

#endif
