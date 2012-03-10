#ifndef java_lang_AbstractStringBuilder_H
#define java_lang_AbstractStringBuilder_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class StringBuffer;
        class Class;
        class Appendable;
        class String;
        class CharSequence;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class AbstractStringBuilder : public ::java::lang::Object {
        public:
            enum {
                mid_append_7c173d47,
                mid_append_a2ed0092,
                mid_append_5e58b04c,
                mid_append_db02ec8f,
                mid_append_4d0b6cce,
                mid_append_9dc99a1e,
                mid_append_a6b3f18b,
                mid_append_97dd5503,
                mid_append_0f3b1ca9,
                mid_append_2814c015,
                mid_append_5337ed99,
                mid_append_c2cdc21f,
                mid_append_7e485efb,
                mid_appendCodePoint_2814c015,
                mid_capacity_54c6a179,
                mid_charAt_39c7bd29,
                mid_codePointAt_39c7bd23,
                mid_codePointBefore_39c7bd23,
                mid_codePointCount_d8d154b9,
                mid_delete_2b8ead17,
                mid_deleteCharAt_2814c015,
                mid_ensureCapacity_39c7bd3c,
                mid_getChars_06518f84,
                mid_indexOf_5fdc3f57,
                mid_indexOf_6e53ccd9,
                mid_insert_6089bc60,
                mid_insert_af3c3de9,
                mid_insert_62ac5207,
                mid_insert_2b8ead17,
                mid_insert_d1cc213e,
                mid_insert_5236bc0d,
                mid_insert_8567b539,
                mid_insert_06d282ac,
                mid_insert_063a9eb9,
                mid_insert_9beca11c,
                mid_insert_78ebdb01,
                mid_insert_24aafa89,
                mid_lastIndexOf_5fdc3f57,
                mid_lastIndexOf_6e53ccd9,
                mid_length_54c6a179,
                mid_offsetByCodePoints_d8d154b9,
                mid_replace_349953a9,
                mid_reverse_570c12f7,
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

            explicit AbstractStringBuilder(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            AbstractStringBuilder(const AbstractStringBuilder& obj) : ::java::lang::Object(obj) {}

            AbstractStringBuilder append(const JArray< jchar > &) const;
            AbstractStringBuilder append(jfloat) const;
            AbstractStringBuilder append(jdouble) const;
            AbstractStringBuilder append(const ::java::lang::Object &) const;
            AbstractStringBuilder append(jlong) const;
            AbstractStringBuilder append(jboolean) const;
            AbstractStringBuilder append(jchar) const;
            AbstractStringBuilder append(const ::java::lang::CharSequence &) const;
            AbstractStringBuilder append(const ::java::lang::String &) const;
            AbstractStringBuilder append(jint) const;
            AbstractStringBuilder append(const ::java::lang::StringBuffer &) const;
            AbstractStringBuilder append(const JArray< jchar > &, jint, jint) const;
            AbstractStringBuilder append(const ::java::lang::CharSequence &, jint, jint) const;
            AbstractStringBuilder appendCodePoint(jint) const;
            jint capacity() const;
            jchar charAt(jint) const;
            jint codePointAt(jint) const;
            jint codePointBefore(jint) const;
            jint codePointCount(jint, jint) const;
            AbstractStringBuilder delete$(jint, jint) const;
            AbstractStringBuilder deleteCharAt(jint) const;
            void ensureCapacity(jint) const;
            void getChars(jint, jint, const JArray< jchar > &, jint) const;
            jint indexOf(const ::java::lang::String &) const;
            jint indexOf(const ::java::lang::String &, jint) const;
            AbstractStringBuilder insert(jint, jfloat) const;
            AbstractStringBuilder insert(jint, const JArray< jchar > &) const;
            AbstractStringBuilder insert(jint, const ::java::lang::String &) const;
            AbstractStringBuilder insert(jint, jint) const;
            AbstractStringBuilder insert(jint, jdouble) const;
            AbstractStringBuilder insert(jint, const ::java::lang::Object &) const;
            AbstractStringBuilder insert(jint, const ::java::lang::CharSequence &) const;
            AbstractStringBuilder insert(jint, jboolean) const;
            AbstractStringBuilder insert(jint, jchar) const;
            AbstractStringBuilder insert(jint, jlong) const;
            AbstractStringBuilder insert(jint, const ::java::lang::CharSequence &, jint, jint) const;
            AbstractStringBuilder insert(jint, const JArray< jchar > &, jint, jint) const;
            jint lastIndexOf(const ::java::lang::String &) const;
            jint lastIndexOf(const ::java::lang::String &, jint) const;
            jint length() const;
            jint offsetByCodePoints(jint, jint) const;
            AbstractStringBuilder replace(jint, jint, const ::java::lang::String &) const;
            AbstractStringBuilder reverse() const;
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
        extern PyTypeObject PY_TYPE(AbstractStringBuilder);

        class t_AbstractStringBuilder {
        public:
            PyObject_HEAD
            AbstractStringBuilder object;
            static PyObject *wrap_Object(const AbstractStringBuilder&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
