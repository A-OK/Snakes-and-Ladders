#ifndef java_lang_Double_H
#define java_lang_Double_H

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

        class Double : public ::java::lang::Number {
        public:
            enum {
                mid_init$_5d1c7645,
                mid_init$_5fdc3f48,
                mid_byteValue_54c6a172,
                mid_compare_b1e28667,
                mid_compareTo_290588f1,
                mid_compareTo_8baed073,
                mid_doubleToLongBits_5d1c7659,
                mid_doubleToRawLongBits_5d1c7659,
                mid_doubleValue_54c6a174,
                mid_equals_290588e2,
                mid_floatValue_54c6a176,
                mid_hashCode_54c6a179,
                mid_intValue_54c6a179,
                mid_isInfinite_54c6a16a,
                mid_isInfinite_5d1c7649,
                mid_isNaN_54c6a16a,
                mid_isNaN_5d1c7649,
                mid_longBitsToDouble_0ee6df3d,
                mid_longValue_54c6a17a,
                mid_parseDouble_5fdc3f5a,
                mid_shortValue_54c6a163,
                mid_toHexString_1b4624f8,
                mid_toString_14c7b5c5,
                mid_toString_1b4624f8,
                mid_valueOf_ad1fcbf0,
                mid_valueOf_16296787,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Double(jobject obj) : ::java::lang::Number(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Double(const Double& obj) : ::java::lang::Number(obj) {}

            static jint MAX_EXPONENT;
            static jdouble MAX_VALUE;
            static jint MIN_EXPONENT;
            static jdouble MIN_NORMAL;
            static jdouble MIN_VALUE;
            static jdouble NEGATIVE_INFINITY;
            static jdouble NaN;
            static jdouble POSITIVE_INFINITY;
            static jint SIZE;
            static ::java::lang::Class *TYPE;

            Double(jdouble);
            Double(const ::java::lang::String &);

            jbyte byteValue() const;
            static jint compare(jdouble, jdouble);
            jint compareTo(const ::java::lang::Object &) const;
            jint compareTo(const Double &) const;
            static jlong doubleToLongBits(jdouble);
            static jlong doubleToRawLongBits(jdouble);
            jdouble doubleValue() const;
            jboolean equals(const ::java::lang::Object &) const;
            jfloat floatValue() const;
            jint hashCode() const;
            jint intValue() const;
            jboolean isInfinite() const;
            static jboolean isInfinite(jdouble);
            jboolean isNaN() const;
            static jboolean isNaN(jdouble);
            static jdouble longBitsToDouble(jlong);
            jlong longValue() const;
            static jdouble parseDouble(const ::java::lang::String &);
            jshort shortValue() const;
            static ::java::lang::String toHexString(jdouble);
            ::java::lang::String toString() const;
            static ::java::lang::String toString(jdouble);
            static Double valueOf(jdouble);
            static Double valueOf(const ::java::lang::String &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Double);

        class t_Double {
        public:
            PyObject_HEAD
            Double object;
            static PyObject *wrap_Object(const Double&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
