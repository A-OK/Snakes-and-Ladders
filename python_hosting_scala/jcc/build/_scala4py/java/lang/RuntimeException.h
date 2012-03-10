#ifndef java_lang_RuntimeException_H
#define java_lang_RuntimeException_H

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

        class RuntimeException : public ::java::lang::Exception {
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

            explicit RuntimeException(jobject obj) : ::java::lang::Exception(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            RuntimeException(const RuntimeException& obj) : ::java::lang::Exception(obj) {}

            RuntimeException();
            RuntimeException(const ::java::lang::String &);
            RuntimeException(const ::java::lang::Throwable &);
            RuntimeException(const ::java::lang::String &, const ::java::lang::Throwable &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(RuntimeException);

        class t_RuntimeException {
        public:
            PyObject_HEAD
            RuntimeException object;
            static PyObject *wrap_Object(const RuntimeException&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
