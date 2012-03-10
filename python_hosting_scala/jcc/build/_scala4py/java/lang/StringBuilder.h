#ifndef java_lang_StringBuilder_H
#define java_lang_StringBuilder_H

#include "java/lang/AbstractStringBuilder.h"

namespace java {
    namespace lang {
        class String;
        class StringBuffer;
        class Object;
        class CharSequence;
        class Appendable;
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class StringBuilder : public ::java::lang::AbstractStringBuilder {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_39c7bd3c,
                mid_init$_5fdc3f48,
                mid_init$_a8afc64a,
                mid_append_3c8cf749,
                mid_append_75fd4e14,
                mid_append_1c7ab4ee,
                mid_append_b60c3de1,
                mid_append_d9a60f20,
                mid_append_0f09fb50,
                mid_append_e82ae26d,
                mid_append_50083a71,
                mid_append_2dfc73db,
                mid_append_83777cef,
                mid_append_8358d2a7,
                mid_append_24d5875d,
                mid_append_2bd4722d,
                mid_appendCodePoint_83777cef,
                mid_capacity_54c6a179,
                mid_charAt_39c7bd29,
                mid_codePointAt_39c7bd23,
                mid_codePointBefore_39c7bd23,
                mid_codePointCount_d8d154b9,
                mid_delete_719db8f9,
                mid_deleteCharAt_83777cef,
                mid_ensureCapacity_39c7bd3c,
                mid_getChars_06518f84,
                mid_indexOf_5fdc3f57,
                mid_indexOf_6e53ccd9,
                mid_insert_a08f263a,
                mid_insert_223b06cf,
                mid_insert_012dcedd,
                mid_insert_719db8f9,
                mid_insert_16519a10,
                mid_insert_de03d343,
                mid_insert_f2b36ed3,
                mid_insert_094df9d6,
                mid_insert_4ed4b5eb,
                mid_insert_af7946e6,
                mid_insert_2824e937,
                mid_insert_d3b5ed83,
                mid_lastIndexOf_5fdc3f57,
                mid_lastIndexOf_6e53ccd9,
                mid_length_54c6a179,
                mid_offsetByCodePoints_d8d154b9,
                mid_replace_3740c5ff,
                mid_reverse_a1025355,
                mid_setCharAt_83eec158,
                mid_setLength_39c7bd3c,
                mid_subSequence_f88dfd57,
                mid_substring_141401b3,
                mid_substring_f9118fe5,
                mid_toString_14c7b5c5,
                mid_trimToSize_54c6a166,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit StringBuilder(jobject obj) : ::java::lang::AbstractStringBuilder(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            StringBuilder(const StringBuilder& obj) : ::java::lang::AbstractStringBuilder(obj) {}

            StringBuilder();
            StringBuilder(jint);
            StringBuilder(const ::java::lang::String &);
            StringBuilder(const ::java::lang::CharSequence &);

            StringBuilder append(const JArray< jchar > &) const;
            StringBuilder append(jfloat) const;
            StringBuilder append(jdouble) const;
            StringBuilder append(const ::java::lang::Object &) const;
            StringBuilder append(jlong) const;
            StringBuilder append(jboolean) const;
            StringBuilder append(jchar) const;
            StringBuilder append(const ::java::lang::CharSequence &) const;
            StringBuilder append(const ::java::lang::String &) const;
            StringBuilder append(jint) const;
            StringBuilder append(const ::java::lang::StringBuffer &) const;
            StringBuilder append(const JArray< jchar > &, jint, jint) const;
            StringBuilder append(const ::java::lang::CharSequence &, jint, jint) const;
            StringBuilder appendCodePoint(jint) const;
            jint capacity() const;
            jchar charAt(jint) const;
            jint codePointAt(jint) const;
            jint codePointBefore(jint) const;
            jint codePointCount(jint, jint) const;
            StringBuilder delete$(jint, jint) const;
            StringBuilder deleteCharAt(jint) const;
            void ensureCapacity(jint) const;
            void getChars(jint, jint, const JArray< jchar > &, jint) const;
            jint indexOf(const ::java::lang::String &) const;
            jint indexOf(const ::java::lang::String &, jint) const;
            StringBuilder insert(jint, jfloat) const;
            StringBuilder insert(jint, const JArray< jchar > &) const;
            StringBuilder insert(jint, const ::java::lang::String &) const;
            StringBuilder insert(jint, jint) const;
            StringBuilder insert(jint, jdouble) const;
            StringBuilder insert(jint, const ::java::lang::Object &) const;
            StringBuilder insert(jint, const ::java::lang::CharSequence &) const;
            StringBuilder insert(jint, jboolean) const;
            StringBuilder insert(jint, jchar) const;
            StringBuilder insert(jint, jlong) const;
            StringBuilder insert(jint, const ::java::lang::CharSequence &, jint, jint) const;
            StringBuilder insert(jint, const JArray< jchar > &, jint, jint) const;
            jint lastIndexOf(const ::java::lang::String &) const;
            jint lastIndexOf(const ::java::lang::String &, jint) const;
            jint length() const;
            jint offsetByCodePoints(jint, jint) const;
            StringBuilder replace(jint, jint, const ::java::lang::String &) const;
            StringBuilder reverse() const;
            void setCharAt(jint, jchar) const;
            void setLength(jint) const;
            ::java::lang::CharSequence subSequence(jint, jint) const;
            ::java::lang::String substring(jint) const;
            ::java::lang::String substring(jint, jint) const;
            ::java::lang::String toString() const;
            void trimToSize() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(StringBuilder);

        class t_StringBuilder {
        public:
            PyObject_HEAD
            StringBuilder object;
            static PyObject *wrap_Object(const StringBuilder&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
