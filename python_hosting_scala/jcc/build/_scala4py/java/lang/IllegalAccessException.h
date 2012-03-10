#ifndef java_lang_IllegalAccessException_H
#define java_lang_IllegalAccessException_H

#include "java/lang/Exception.h"

namespace java {
    namespace lang {
        class String;
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class IllegalAccessException : public ::java::lang::Exception {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_5fdc3f48,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit IllegalAccessException(jobject obj) : ::java::lang::Exception(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            IllegalAccessException(const IllegalAccessException& obj) : ::java::lang::Exception(obj) {}

            IllegalAccessException();
            IllegalAccessException(const ::java::lang::String &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(IllegalAccessException);

        class t_IllegalAccessException {
        public:
            PyObject_HEAD
            IllegalAccessException object;
            static PyObject *wrap_Object(const IllegalAccessException&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
