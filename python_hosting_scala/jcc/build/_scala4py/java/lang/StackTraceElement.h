#ifndef java_lang_StackTraceElement_H
#define java_lang_StackTraceElement_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class String;
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class StackTraceElement : public ::java::lang::Object {
        public:
            enum {
                mid_init$_fa754eea,
                mid_equals_290588e2,
                mid_getClassName_14c7b5c5,
                mid_getFileName_14c7b5c5,
                mid_getLineNumber_54c6a179,
                mid_getMethodName_14c7b5c5,
                mid_hashCode_54c6a179,
                mid_isNativeMethod_54c6a16a,
                mid_toString_14c7b5c5,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit StackTraceElement(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            StackTraceElement(const StackTraceElement& obj) : ::java::lang::Object(obj) {}

            StackTraceElement(const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &, jint);

            jboolean equals(const ::java::lang::Object &) const;
            ::java::lang::String getClassName() const;
            ::java::lang::String getFileName() const;
            jint getLineNumber() const;
            ::java::lang::String getMethodName() const;
            jint hashCode() const;
            jboolean isNativeMethod() const;
            ::java::lang::String toString() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(StackTraceElement);

        class t_StackTraceElement {
        public:
            PyObject_HEAD
            StackTraceElement object;
            static PyObject *wrap_Object(const StackTraceElement&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
