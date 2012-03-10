#ifndef java_lang_Exception_H
#define java_lang_Exception_H

#include "java/lang/Throwable.h"

namespace java {
    namespace lang {
        class String;
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class Exception : public ::java::lang::Throwable {
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

            explicit Exception(jobject obj) : ::java::lang::Throwable(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Exception(const Exception& obj) : ::java::lang::Throwable(obj) {}

            Exception();
            Exception(const ::java::lang::String &);
            Exception(const ::java::lang::Throwable &);
            Exception(const ::java::lang::String &, const ::java::lang::Throwable &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Exception);

        class t_Exception {
        public:
            PyObject_HEAD
            Exception object;
            static PyObject *wrap_Object(const Exception&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
