#ifndef java_lang_Float_H
#define java_lang_Float_H

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

        class Float : public ::java::lang::Number {
        public:
            enum {
                mid_init$_06298cab,
                mid_init$_5fdc3f48,
                mid_init$_5d1c7645,
                mid_byteValue_54c6a172,
                mid_compare_f1b0c01b,
                mid_compareTo_290588f1,
                mid_compareTo_6b30eb75,
                mid_doubleValue_54c6a174,
                mid_equals_290588e2,
                mid_floatToIntBits_06298cb4,
                mid_floatToRawIntBits_06298cb4,
                mid_floatValue_54c6a176,
                mid_hashCode_54c6a179,
                mid_intBitsToFloat_39c7bd2c,
                mid_intValue_54c6a179,
                mid_isInfinite_54c6a16a,
                mid_isInfinite_06298ca7,
                mid_isNaN_54c6a16a,
                mid_isNaN_06298ca7,
                mid_longValue_54c6a17a,
                mid_parseFloat_5fdc3f58,
                mid_shortValue_54c6a163,
                mid_toHexString_5ded254a,
                mid_toString_14c7b5c5,
                mid_toString_5ded254a,
                mid_valueOf_685a245e,
                mid_valueOf_b837041d,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Float(jobject obj) : ::java::lang::Number(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Float(const Float& obj) : ::java::lang::Number(obj) {}

            static jint MAX_EXPONENT;
            static jfloat MAX_VALUE;
            static jint MIN_EXPONENT;
            static jfloat MIN_NORMAL;
            static jfloat MIN_VALUE;
            static jfloat NEGATIVE_INFINITY;
            static jfloat NaN;
            static jfloat POSITIVE_INFINITY;
            static jint SIZE;
            static ::java::lang::Class *TYPE;

            Float(jfloat);
            Float(const ::java::lang::String &);
            Float(jdouble);

            jbyte byteValue() const;
            static jint compare(jfloat, jfloat);
            jint compareTo(const ::java::lang::Object &) const;
            jint compareTo(const Float &) const;
            jdouble doubleValue() const;
            jboolean equals(const ::java::lang::Object &) const;
            static jint floatToIntBits(jfloat);
            static jint floatToRawIntBits(jfloat);
            jfloat floatValue() const;
            jint hashCode() const;
            static jfloat intBitsToFloat(jint);
            jint intValue() const;
            jboolean isInfinite() const;
            static jboolean isInfinite(jfloat);
            jboolean isNaN() const;
            static jboolean isNaN(jfloat);
            jlong longValue() const;
            static jfloat parseFloat(const ::java::lang::String &);
            jshort shortValue() const;
            static ::java::lang::String toHexString(jfloat);
            ::java::lang::String toString() const;
            static ::java::lang::String toString(jfloat);
            static Float valueOf(jfloat);
            static Float valueOf(const ::java::lang::String &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Float);

        class t_Float {
        public:
            PyObject_HEAD
            Float object;
            static PyObject *wrap_Object(const Float&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
