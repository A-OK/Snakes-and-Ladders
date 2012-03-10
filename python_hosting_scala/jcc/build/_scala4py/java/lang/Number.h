#ifndef java_lang_Number_H
#define java_lang_Number_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class Number : public ::java::lang::Object {
        public:
            enum {
                mid_init$_54c6a166,
                mid_byteValue_54c6a172,
                mid_doubleValue_54c6a174,
                mid_floatValue_54c6a176,
                mid_intValue_54c6a179,
                mid_longValue_54c6a17a,
                mid_shortValue_54c6a163,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Number(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Number(const Number& obj) : ::java::lang::Object(obj) {}

            Number();

            jbyte byteValue() const;
            jdouble doubleValue() const;
            jfloat floatValue() const;
            jint intValue() const;
            jlong longValue() const;
            jshort shortValue() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Number);

        class t_Number {
        public:
            PyObject_HEAD
            Number object;
            static PyObject *wrap_Object(const Number&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
