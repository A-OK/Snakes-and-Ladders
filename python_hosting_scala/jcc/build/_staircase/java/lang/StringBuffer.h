#ifndef java_lang_StringBuffer_H
#define java_lang_StringBuffer_H

#include "java/lang/AbstractStringBuilder.h"

namespace java {
    namespace lang {
        class Class;
        class Appendable;
        class Object;
        class String;
        class CharSequence;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class StringBuffer : public ::java::lang::AbstractStringBuilder {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_39c7bd3c,
                mid_init$_5fdc3f48,
                mid_init$_a8afc64a,
                mid_append_35d2e845,
                mid_append_251e110e,
                mid_append_24b69bf0,
                mid_append_67ad01ed,
                mid_append_662d52ca,
                mid_append_bb3a365a,
                mid_append_4ca72be1,
                mid_append_6b1920e9,
                mid_append_2979b2bb,
                mid_append_fdff3523,
                mid_append_a876a4ab,
                mid_append_aa3a4fc5,
                mid_append_f3c776b1,
                mid_appendCodePoint_fdff3523,
                mid_capacity_54c6a179,
                mid_charAt_39c7bd29,
                mid_codePointAt_39c7bd23,
                mid_codePointBefore_39c7bd23,
                mid_codePointCount_d8d154b9,
                mid_delete_644727d5,
                mid_deleteCharAt_fdff3523,
                mid_ensureCapacity_39c7bd3c,
                mid_getChars_06518f84,
                mid_indexOf_5fdc3f57,
                mid_indexOf_6e53ccd9,
                mid_insert_d95ec358,
                mid_insert_bc0ebac7,
                mid_insert_88877b15,
                mid_insert_644727d5,
                mid_insert_b71b2a52,
                mid_insert_2e164a03,
                mid_insert_ed5f9c37,
                mid_insert_3c3656bc,
                mid_insert_3d91488b,
                mid_insert_5e363fec,
                mid_insert_732cbadf,
                mid_insert_6edd3397,
                mid_lastIndexOf_5fdc3f57,
                mid_lastIndexOf_6e53ccd9,
                mid_length_54c6a179,
                mid_offsetByCodePoints_d8d154b9,
                mid_replace_95b69603,
                mid_reverse_d54172a5,
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

            explicit StringBuffer(jobject obj) : ::java::lang::AbstractStringBuilder(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            StringBuffer(const StringBuffer& obj) : ::java::lang::AbstractStringBuilder(obj) {}

            StringBuffer();
            StringBuffer(jint);
            StringBuffer(const ::java::lang::String &);
            StringBuffer(const ::java::lang::CharSequence &);

            StringBuffer append(const JArray< jchar > &) const;
            StringBuffer append(jfloat) const;
            StringBuffer append(jdouble) const;
            StringBuffer append(const ::java::lang::Object &) const;
            StringBuffer append(jlong) const;
            StringBuffer append(jboolean) const;
            StringBuffer append(jchar) const;
            StringBuffer append(const ::java::lang::CharSequence &) const;
            StringBuffer append(const ::java::lang::String &) const;
            StringBuffer append(jint) const;
            StringBuffer append(const StringBuffer &) const;
            StringBuffer append(const JArray< jchar > &, jint, jint) const;
            StringBuffer append(const ::java::lang::CharSequence &, jint, jint) const;
            StringBuffer appendCodePoint(jint) const;
            jint capacity() const;
            jchar charAt(jint) const;
            jint codePointAt(jint) const;
            jint codePointBefore(jint) const;
            jint codePointCount(jint, jint) const;
            StringBuffer delete$(jint, jint) const;
            StringBuffer deleteCharAt(jint) const;
            void ensureCapacity(jint) const;
            void getChars(jint, jint, const JArray< jchar > &, jint) const;
            jint indexOf(const ::java::lang::String &) const;
            jint indexOf(const ::java::lang::String &, jint) const;
            StringBuffer insert(jint, jfloat) const;
            StringBuffer insert(jint, const JArray< jchar > &) const;
            StringBuffer insert(jint, const ::java::lang::String &) const;
            StringBuffer insert(jint, jint) const;
            StringBuffer insert(jint, jdouble) const;
            StringBuffer insert(jint, const ::java::lang::Object &) const;
            StringBuffer insert(jint, const ::java::lang::CharSequence &) const;
            StringBuffer insert(jint, jboolean) const;
            StringBuffer insert(jint, jchar) const;
            StringBuffer insert(jint, jlong) const;
            StringBuffer insert(jint, const ::java::lang::CharSequence &, jint, jint) const;
            StringBuffer insert(jint, const JArray< jchar > &, jint, jint) const;
            jint lastIndexOf(const ::java::lang::String &) const;
            jint lastIndexOf(const ::java::lang::String &, jint) const;
            jint length() const;
            jint offsetByCodePoints(jint, jint) const;
            StringBuffer replace(jint, jint, const ::java::lang::String &) const;
            StringBuffer reverse() const;
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
        extern PyTypeObject PY_TYPE(StringBuffer);

        class t_StringBuffer {
        public:
            PyObject_HEAD
            StringBuffer object;
            static PyObject *wrap_Object(const StringBuffer&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
