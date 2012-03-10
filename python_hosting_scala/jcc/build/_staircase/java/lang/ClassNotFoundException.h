#ifndef java_lang_ClassNotFoundException_H
#define java_lang_ClassNotFoundException_H

#include "java/lang/Exception.h"

namespace java {
    namespace lang {
        class Throwable;
        class String;
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class ClassNotFoundException : public ::java::lang::Exception {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_5fdc3f48,
                mid_init$_01646a2e,
                mid_getCause_9a29189d,
                mid_getException_9a29189d,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit ClassNotFoundException(jobject obj) : ::java::lang::Exception(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            ClassNotFoundException(const ClassNotFoundException& obj) : ::java::lang::Exception(obj) {}

            ClassNotFoundException();
            ClassNotFoundException(const ::java::lang::String &);
            ClassNotFoundException(const ::java::lang::String &, const ::java::lang::Throwable &);

            ::java::lang::Throwable getCause() const;
            ::java::lang::Throwable getException() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(ClassNotFoundException);

        class t_ClassNotFoundException {
        public:
            PyObject_HEAD
            ClassNotFoundException object;
            static PyObject *wrap_Object(const ClassNotFoundException&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
