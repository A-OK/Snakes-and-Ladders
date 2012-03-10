#ifndef ScalaUtils_H
#define ScalaUtils_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
}
template<class T> class JArray;


class ScalaUtils : public ::java::lang::Object {
public:
    enum {
        mid_ageGroupMethod_5d1c765a,
        max_mid
    };

    static ::java::lang::Class *class$;
    static jmethodID *mids$;
    static jclass initializeClass();

    explicit ScalaUtils(jobject obj) : ::java::lang::Object(obj) {
        if (obj != NULL)
            initializeClass();
    }
    ScalaUtils(const ScalaUtils& obj) : ::java::lang::Object(obj) {}

    static jint ageGroupMethod(jdouble);
};

#include <Python.h>

extern PyTypeObject PY_TYPE(ScalaUtils);

class t_ScalaUtils {
public:
    PyObject_HEAD
    ScalaUtils object;
    static PyObject *wrap_Object(const ScalaUtils&);
    static PyObject *wrap_jobject(const jobject&);
    static void install(PyObject *module);
    static void initialize(PyObject *module);
};

#endif
