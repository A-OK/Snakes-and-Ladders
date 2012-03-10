#ifndef java_lang_SecurityException_H
#define java_lang_SecurityException_H

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

        class SecurityException : public ::java::lang::RuntimeException {
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

            explicit SecurityException(jobject obj) : ::java::lang::RuntimeException(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            SecurityException(const SecurityException& obj) : ::java::lang::RuntimeException(obj) {}

            SecurityException();
            SecurityException(const ::java::lang::String &);
            SecurityException(const ::java::lang::Throwable &);
            SecurityException(const ::java::lang::String &, const ::java::lang::Throwable &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(SecurityException);

        class t_SecurityException {
        public:
            PyObject_HEAD
            SecurityException object;
            static PyObject *wrap_Object(const SecurityException&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
