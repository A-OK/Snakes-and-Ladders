#ifndef java_lang_Integer_H
#define java_lang_Integer_H

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

        class Integer : public ::java::lang::Number {
        public:
            enum {
                mid_init$_39c7bd3c,
                mid_init$_5fdc3f48,
                mid_bitCount_39c7bd23,
                mid_byteValue_54c6a172,
                mid_compareTo_290588f1,
                mid_compareTo_af7b73bb,
                mid_decode_da36ea2b,
                mid_doubleValue_54c6a174,
                mid_equals_290588e2,
                mid_floatValue_54c6a176,
                mid_getInteger_da36ea2b,
                mid_getInteger_fe9eddb1,
                mid_getInteger_39b2b79d,
                mid_hashCode_54c6a179,
                mid_highestOneBit_39c7bd23,
                mid_intValue_54c6a179,
                mid_longValue_54c6a17a,
                mid_lowestOneBit_39c7bd23,
                mid_numberOfLeadingZeros_39c7bd23,
                mid_numberOfTrailingZeros_39c7bd23,
                mid_parseInt_5fdc3f57,
                mid_parseInt_6e53ccd9,
                mid_reverse_39c7bd23,
                mid_reverseBytes_39c7bd23,
                mid_rotateLeft_d8d154b9,
                mid_rotateRight_d8d154b9,
                mid_shortValue_54c6a163,
                mid_signum_39c7bd23,
                mid_toBinaryString_141401b3,
                mid_toHexString_141401b3,
                mid_toOctalString_141401b3,
                mid_toString_14c7b5c5,
                mid_toString_141401b3,
                mid_toString_f9118fe5,
                mid_valueOf_7266dabb,
                mid_valueOf_da36ea2b,
                mid_valueOf_39b2b79d,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Integer(jobject obj) : ::java::lang::Number(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Integer(const Integer& obj) : ::java::lang::Number(obj) {}

            static jint MAX_VALUE;
            static jint MIN_VALUE;
            static jint SIZE;
            static ::java::lang::Class *TYPE;

            Integer(jint);
            Integer(const ::java::lang::String &);

            static jint bitCount(jint);
            jbyte byteValue() const;
            jint compareTo(const ::java::lang::Object &) const;
            jint compareTo(const Integer &) const;
            static Integer decode(const ::java::lang::String &);
            jdouble doubleValue() const;
            jboolean equals(const ::java::lang::Object &) const;
            jfloat floatValue() const;
            static Integer getInteger(const ::java::lang::String &);
            static Integer getInteger(const ::java::lang::String &, const Integer &);
            static Integer getInteger(const ::java::lang::String &, jint);
            jint hashCode() const;
            static jint highestOneBit(jint);
            jint intValue() const;
            jlong longValue() const;
            static jint lowestOneBit(jint);
            static jint numberOfLeadingZeros(jint);
            static jint numberOfTrailingZeros(jint);
            static jint parseInt(const ::java::lang::String &);
            static jint parseInt(const ::java::lang::String &, jint);
            static jint reverse(jint);
            static jint reverseBytes(jint);
            static jint rotateLeft(jint, jint);
            static jint rotateRight(jint, jint);
            jshort shortValue() const;
            static jint signum(jint);
            static ::java::lang::String toBinaryString(jint);
            static ::java::lang::String toHexString(jint);
            static ::java::lang::String toOctalString(jint);
            ::java::lang::String toString() const;
            static ::java::lang::String toString(jint);
            static ::java::lang::String toString(jint, jint);
            static Integer valueOf(jint);
            static Integer valueOf(const ::java::lang::String &);
            static Integer valueOf(const ::java::lang::String &, jint);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Integer);

        class t_Integer {
        public:
            PyObject_HEAD
            Integer object;
            static PyObject *wrap_Object(const Integer&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
