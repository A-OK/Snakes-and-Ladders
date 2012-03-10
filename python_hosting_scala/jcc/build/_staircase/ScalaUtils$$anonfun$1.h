#ifndef ScalaUtils$$anonfun$1_H
#define ScalaUtils$$anonfun$1_H

#include "scala/runtime/AbstractFunction1$mcID$sp.h"

namespace java {
    namespace lang {
        class Object;
        class Class;
    }
}
template<class T> class JArray;


class ScalaUtils$$anonfun$1 : public ::scala::runtime::AbstractFunction1$mcID$sp {
public:
    enum {
        mid_init$_54c6a166,
        mid_apply_a932a95f,
        mid_apply_5d1c765a,
        mid_apply$mcID$sp_5d1c765a,
        max_mid
    };

    static ::java::lang::Class *class$;
    static jmethodID *mids$;
    static jclass initializeClass();

    explicit ScalaUtils$$anonfun$1(jobject obj) : ::scala::runtime::AbstractFunction1$mcID$sp(obj) {
        if (obj != NULL)
            initializeClass();
    }
    ScalaUtils$$anonfun$1(const ScalaUtils$$anonfun$1& obj) : ::scala::runtime::AbstractFunction1$mcID$sp(obj) {}

    static jlong serialVersionUID;

    ScalaUtils$$anonfun$1();

    ::java::lang::Object apply(const ::java::lang::Object &) const;
    jint apply(jdouble) const;
    jint apply$mcID$sp(jdouble) const;
};

#include <Python.h>

extern PyTypeObject PY_TYPE(ScalaUtils$$anonfun$1);

class t_ScalaUtils$$anonfun$1 {
public:
    PyObject_HEAD
    ScalaUtils$$anonfun$1 object;
    static PyObject *wrap_Object(const ScalaUtils$$anonfun$1&);
    static PyObject *wrap_jobject(const jobject&);
    static void install(PyObject *module);
    static void initialize(PyObject *module);
};

#endif
