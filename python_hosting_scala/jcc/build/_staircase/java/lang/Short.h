#ifndef java_lang_Short_H
#define java_lang_Short_H

#include "java/lang/Number.h"

namespace java {
    namespace lang {
        class NumberFormatException;
        class Comparable;
        class Object;
        class String;
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class Short : public ::java::lang::Number {
        public:
            enum {
                mid_init$_3bc40c6a,
                mid_init$_5fdc3f48,
                mid_byteValue_54c6a172,
                mid_compareTo_290588f1,
                mid_compareTo_6b8573d1,
                mid_decode_88c4db41,
                mid_doubleValue_54c6a174,
                mid_equals_290588e2,
                mid_floatValue_54c6a176,
                mid_hashCode_54c6a179,
                mid_intValue_54c6a179,
                mid_longValue_54c6a17a,
                mid_parseShort_5fdc3f4d,
                mid_parseShort_6e53ccc3,
                mid_reverseBytes_3bc40c6f,
                mid_shortValue_54c6a163,
                mid_toString_14c7b5c5,
                mid_toString_9c2e4c45,
                mid_valueOf_5d563b1b,
                mid_valueOf_88c4db41,
                mid_valueOf_0f6bcb23,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Short(jobject obj) : ::java::lang::Number(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Short(const Short& obj) : ::java::lang::Number(obj) {}

            static jshort MAX_VALUE;
            static jshort MIN_VALUE;
            static jint SIZE;
            static ::java::lang::Class *TYPE;

            Short(jshort);
            Short(const ::java::lang::String &);

            jbyte byteValue() const;
            jint compareTo(const ::java::lang::Object &) const;
            jint compareTo(const Short &) const;
            static Short decode(const ::java::lang::String &);
            jdouble doubleValue() const;
            jboolean equals(const ::java::lang::Object &) const;
            jfloat floatValue() const;
            jint hashCode() const;
            jint intValue() const;
            jlong longValue() const;
            static jshort parseShort(const ::java::lang::String &);
            static jshort parseShort(const ::java::lang::String &, jint);
            static jshort reverseBytes(jshort);
            jshort shortValue() const;
            ::java::lang::String toString() const;
            static ::java::lang::String toString(jshort);
            static Short valueOf(jshort);
            static Short valueOf(const ::java::lang::String &);
            static Short valueOf(const ::java::lang::String &, jint);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Short);

        class t_Short {
        public:
            PyObject_HEAD
            Short object;
            static PyObject *wrap_Object(const Short&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
