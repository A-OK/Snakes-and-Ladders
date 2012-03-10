#ifndef java_lang_InstantiationException_H
#define java_lang_InstantiationException_H

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

        class InstantiationException : public ::java::lang::Exception {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_5fdc3f48,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit InstantiationException(jobject obj) : ::java::lang::Exception(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            InstantiationException(const InstantiationException& obj) : ::java::lang::Exception(obj) {}

            InstantiationException();
            InstantiationException(const ::java::lang::String &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(InstantiationException);

        class t_InstantiationException {
        public:
            PyObject_HEAD
            InstantiationException object;
            static PyObject *wrap_Object(const InstantiationException&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
