#ifndef java_lang_IllegalArgumentException_H
#define java_lang_IllegalArgumentException_H

#include "java/lang/RuntimeException.h"

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

        class IllegalArgumentException : public ::java::lang::RuntimeException {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_5fdc3f48,
                mid_init$_c5ec8ca4,
                mid_init$_01646a2e,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit IllegalArgumentException(jobject obj) : ::java::lang::RuntimeException(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            IllegalArgumentException(const IllegalArgumentException& obj) : ::java::lang::RuntimeException(obj) {}

            IllegalArgumentException();
            IllegalArgumentException(const ::java::lang::String &);
            IllegalArgumentException(const ::java::lang::Throwable &);
            IllegalArgumentException(const ::java::lang::String &, const ::java::lang::Throwable &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(IllegalArgumentException);

        class t_IllegalArgumentException {
        public:
            PyObject_HEAD
            IllegalArgumentException object;
            static PyObject *wrap_Object(const IllegalArgumentException&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
