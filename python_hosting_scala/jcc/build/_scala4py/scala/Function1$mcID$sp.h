#ifndef scala_Function1$mcID$sp_H
#define scala_Function1$mcID$sp_H

#include "scala/Function1.h"

namespace java {
    namespace lang {
        class Object;
        class Class;
    }
}
template<class T> class JArray;

namespace scala {

    class Function1$mcID$sp : public ::scala::Function1 {
    public:
        enum {
            mid_andThen_279d294f,
            mid_andThen$mcID$sp_279d294f,
            mid_apply_5d1c765a,
            mid_compose_279d294f,
            mid_compose$mcID$sp_279d294f,
            max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static jclass initializeClass();

        explicit Function1$mcID$sp(jobject obj) : ::scala::Function1(obj) {
            if (obj != NULL)
                initializeClass();
        }
        Function1$mcID$sp(const Function1$mcID$sp& obj) : ::scala::Function1(obj) {}

        ::scala::Function1 andThen(const ::scala::Function1 &) const;
        ::scala::Function1 andThen$mcID$sp(const ::scala::Function1 &) const;
        jint apply(jdouble) const;
        ::scala::Function1 compose(const ::scala::Function1 &) const;
        ::scala::Function1 compose$mcID$sp(const ::scala::Function1 &) const;
    };
}

#include <Python.h>

namespace scala {
    extern PyTypeObject PY_TYPE(Function1$mcID$sp);

    class t_Function1$mcID$sp {
    public:
        PyObject_HEAD
        Function1$mcID$sp object;
        static PyObject *wrap_Object(const Function1$mcID$sp&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
    };
}

#endif
