#ifndef ScalaUtils_H
#define ScalaUtils_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
}
namespace scala {
    class Function1;
}
template<class T> class JArray;


class ScalaUtils : public ::java::lang::Object {
public:
    enum {
        mid_ageGroupFunction_c83f65c1,
        mid_ageGroupMethod_5d1c765a,
        mid_reptileAgeGroupFunctionMaker_279d294f,
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

    static ::scala::Function1 ageGroupFunction();
    static jint ageGroupMethod(jdouble);
    static ::scala::Function1 reptileAgeGroupFunctionMaker(const ::scala::Function1 &);
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
