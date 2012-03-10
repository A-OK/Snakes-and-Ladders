#ifndef scala_runtime_AbstractFunction1$mcID$sp_H
#define scala_runtime_AbstractFunction1$mcID$sp_H

#include "scala/runtime/AbstractFunction1.h"

namespace java {
    namespace lang {
        class Object;
        class Class;
    }
}
namespace scala {
    class Function1;
    class Function1$mcID$sp;
}
template<class T> class JArray;

namespace scala {
    namespace runtime {

        class AbstractFunction1$mcID$sp : public ::scala::runtime::AbstractFunction1 {
        public:
            enum {
                mid_init$_54c6a166,
                mid_andThen_279d294f,
                mid_andThen$mcID$sp_279d294f,
                mid_apply_5d1c765a,
                mid_apply_a932a95f,
                mid_compose_279d294f,
                mid_compose$mcID$sp_279d294f,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit AbstractFunction1$mcID$sp(jobject obj) : ::scala::runtime::AbstractFunction1(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            AbstractFunction1$mcID$sp(const AbstractFunction1$mcID$sp& obj) : ::scala::runtime::AbstractFunction1(obj) {}

            AbstractFunction1$mcID$sp();

            ::scala::Function1 andThen(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcID$sp(const ::scala::Function1 &) const;
            jint apply(jdouble) const;
            ::java::lang::Object apply(const ::java::lang::Object &) const;
            ::scala::Function1 compose(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcID$sp(const ::scala::Function1 &) const;
        };
    }
}

#include <Python.h>

namespace scala {
    namespace runtime {
        extern PyTypeObject PY_TYPE(AbstractFunction1$mcID$sp);

        class t_AbstractFunction1$mcID$sp {
        public:
            PyObject_HEAD
            AbstractFunction1$mcID$sp object;
            static PyObject *wrap_Object(const AbstractFunction1$mcID$sp&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
