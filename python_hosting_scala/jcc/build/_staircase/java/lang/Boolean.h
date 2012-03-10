#ifndef java_lang_Boolean_H
#define java_lang_Boolean_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Comparable;
        class String;
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class Boolean : public ::java::lang::Object {
        public:
            enum {
                mid_init$_bb0c767f,
                mid_init$_5fdc3f48,
                mid_booleanValue_54c6a16a,
                mid_compareTo_d07f0c91,
                mid_compareTo_290588f1,
                mid_equals_290588e2,
                mid_getBoolean_5fdc3f44,
                mid_hashCode_54c6a179,
                mid_parseBoolean_5fdc3f44,
                mid_toString_14c7b5c5,
                mid_toString_445a175e,
                mid_valueOf_a98d5bba,
                mid_valueOf_9d4a8ff9,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Boolean(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Boolean(const Boolean& obj) : ::java::lang::Object(obj) {}

            static Boolean *FALSE;
            static Boolean *TRUE;
            static ::java::lang::Class *TYPE;

            Boolean(jboolean);
            Boolean(const ::java::lang::String &);

            jboolean booleanValue() const;
            jint compareTo(const Boolean &) const;
            jint compareTo(const ::java::lang::Object &) const;
            jboolean equals(const ::java::lang::Object &) const;
            static jboolean getBoolean(const ::java::lang::String &);
            jint hashCode() const;
            static jboolean parseBoolean(const ::java::lang::String &);
            ::java::lang::String toString() const;
            static ::java::lang::String toString(jboolean);
            static Boolean valueOf(jboolean);
            static Boolean valueOf(const ::java::lang::String &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Boolean);

        class t_Boolean {
        public:
            PyObject_HEAD
            Boolean object;
            static PyObject *wrap_Object(const Boolean&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
