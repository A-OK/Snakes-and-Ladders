#ifndef java_lang_Throwable_H
#define java_lang_Throwable_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class StackTraceElement;
        class String;
        class Class;
    }
    namespace io {
        class PrintWriter;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class Throwable : public ::java::lang::Object {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_5fdc3f48,
                mid_init$_01646a2e,
                mid_fillInStackTrace_9a29189d,
                mid_getCause_9a29189d,
                mid_getLocalizedMessage_14c7b5c5,
                mid_getMessage_14c7b5c5,
                mid_getStackTrace_25f1f6aa,
                mid_initCause_dabad90f,
                mid_printStackTrace_54c6a166,
                mid_printStackTrace_82fffd94,
                mid_setStackTrace_3d8798bf,
                mid_toString_14c7b5c5,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Throwable(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Throwable(const Throwable& obj) : ::java::lang::Object(obj) {}

            Throwable();
            Throwable(const ::java::lang::String &);
            Throwable(const ::java::lang::String &, const Throwable &);

            Throwable fillInStackTrace() const;
            Throwable getCause() const;
            ::java::lang::String getLocalizedMessage() const;
            ::java::lang::String getMessage() const;
            JArray< ::java::lang::StackTraceElement > getStackTrace() const;
            Throwable initCause(const Throwable &) const;
            void printStackTrace() const;
            void printStackTrace(const ::java::io::PrintWriter &) const;
            void setStackTrace(const JArray< ::java::lang::StackTraceElement > &) const;
            ::java::lang::String toString() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Throwable);

        class t_Throwable {
        public:
            PyObject_HEAD
            Throwable object;
            static PyObject *wrap_Object(const Throwable&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
