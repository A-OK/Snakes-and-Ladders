#ifndef java_lang_String_H
#define java_lang_String_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class StringBuffer;
        class Comparable;
        class CharSequence;
        class Class;
        class StringBuilder;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class String : public ::java::lang::Object {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_700e23d6,
                mid_init$_49b4f12b,
                mid_init$_44634788,
                mid_init$_9f94ae34,
                mid_init$_b8354c43,
                mid_init$_1a0c6fd5,
                mid_init$_6f0bb356,
                mid_init$_3e1ea22c,
                mid_init$_86f4435f,
                mid_init$_96a25f0b,
                mid_init$_5ab96441,
                mid_charAt_39c7bd29,
                mid_codePointAt_39c7bd23,
                mid_codePointBefore_39c7bd23,
                mid_codePointCount_d8d154b9,
                mid_compareTo_290588f1,
                mid_compareTo_5fdc3f57,
                mid_compareToIgnoreCase_5fdc3f57,
                mid_concat_97a5258f,
                mid_contains_a8afc646,
                mid_contentEquals_a8afc646,
                mid_contentEquals_44634784,
                mid_copyValueOf_c783d655,
                mid_copyValueOf_ddb60785,
                mid_endsWith_5fdc3f44,
                mid_equals_290588e2,
                mid_equalsIgnoreCase_5fdc3f44,
                mid_format_0fb26e3b,
                mid_getBytes_dab10e7e,
                mid_getBytes_94a731a4,
                mid_getBytes_fdf97d27,
                mid_getChars_06518f84,
                mid_hashCode_54c6a179,
                mid_indexOf_39c7bd23,
                mid_indexOf_5fdc3f57,
                mid_indexOf_6e53ccd9,
                mid_indexOf_d8d154b9,
                mid_intern_14c7b5c5,
                mid_isEmpty_54c6a16a,
                mid_lastIndexOf_39c7bd23,
                mid_lastIndexOf_5fdc3f57,
                mid_lastIndexOf_d8d154b9,
                mid_lastIndexOf_6e53ccd9,
                mid_length_54c6a179,
                mid_matches_5fdc3f44,
                mid_offsetByCodePoints_d8d154b9,
                mid_regionMatches_344d8cb6,
                mid_regionMatches_35f2560d,
                mid_replace_f1c62e0d,
                mid_replace_103b702d,
                mid_replaceAll_aacea7e9,
                mid_replaceFirst_aacea7e9,
                mid_split_1f6a174f,
                mid_split_3384fe85,
                mid_startsWith_5fdc3f44,
                mid_startsWith_6e53ccca,
                mid_subSequence_f88dfd57,
                mid_substring_141401b3,
                mid_substring_f9118fe5,
                mid_toCharArray_dab10e7f,
                mid_toLowerCase_14c7b5c5,
                mid_toString_14c7b5c5,
                mid_toUpperCase_14c7b5c5,
                mid_trim_14c7b5c5,
                mid_valueOf_445a175e,
                mid_valueOf_c9db4eed,
                mid_valueOf_5ded254a,
                mid_valueOf_1b4624f8,
                mid_valueOf_141401b3,
                mid_valueOf_c783d655,
                mid_valueOf_7611a535,
                mid_valueOf_3e02f30e,
                mid_valueOf_ddb60785,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit String(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            String(const String& obj) : ::java::lang::Object(obj) {}

            String();
            String(const JArray< jchar > &);
            String(const JArray< jbyte > &);
            String(const ::java::lang::StringBuffer &);
            String(const ::java::lang::StringBuilder &);
            String(const JArray< jbyte > &, jint);
            String(const JArray< jbyte > &, const String &);
            String(const JArray< jchar > &, jint, jint);
            String(const JArray< jint > &, jint, jint);
            String(const JArray< jbyte > &, jint, jint);
            String(const JArray< jbyte > &, jint, jint, jint);
            String(const JArray< jbyte > &, jint, jint, const String &);

            jchar charAt(jint) const;
            jint codePointAt(jint) const;
            jint codePointBefore(jint) const;
            jint codePointCount(jint, jint) const;
            jint compareTo(const ::java::lang::Object &) const;
            jint compareTo(const String &) const;
            jint compareToIgnoreCase(const String &) const;
            String concat(const String &) const;
            jboolean contains(const ::java::lang::CharSequence &) const;
            jboolean contentEquals(const ::java::lang::CharSequence &) const;
            jboolean contentEquals(const ::java::lang::StringBuffer &) const;
            static String copyValueOf(const JArray< jchar > &);
            static String copyValueOf(const JArray< jchar > &, jint, jint);
            jboolean endsWith(const String &) const;
            jboolean equals(const ::java::lang::Object &) const;
            jboolean equalsIgnoreCase(const String &) const;
            static String format(const String &, const JArray< ::java::lang::Object > &);
            JArray< jbyte > getBytes() const;
            JArray< jbyte > getBytes(const String &) const;
            void getBytes(jint, jint, const JArray< jbyte > &, jint) const;
            void getChars(jint, jint, const JArray< jchar > &, jint) const;
            jint hashCode() const;
            jint indexOf(jint) const;
            jint indexOf(const String &) const;
            jint indexOf(const String &, jint) const;
            jint indexOf(jint, jint) const;
            String intern() const;
            jboolean isEmpty() const;
            jint lastIndexOf(jint) const;
            jint lastIndexOf(const String &) const;
            jint lastIndexOf(jint, jint) const;
            jint lastIndexOf(const String &, jint) const;
            jint length() const;
            jboolean matches(const String &) const;
            jint offsetByCodePoints(jint, jint) const;
            jboolean regionMatches(jint, const String &, jint, jint) const;
            jboolean regionMatches(jboolean, jint, const String &, jint, jint) const;
            String replace(jchar, jchar) const;
            String replace(const ::java::lang::CharSequence &, const ::java::lang::CharSequence &) const;
            String replaceAll(const String &, const String &) const;
            String replaceFirst(const String &, const String &) const;
            JArray< String > split(const String &) const;
            JArray< String > split(const String &, jint) const;
            jboolean startsWith(const String &) const;
            jboolean startsWith(const String &, jint) const;
            ::java::lang::CharSequence subSequence(jint, jint) const;
            String substring(jint) const;
            String substring(jint, jint) const;
            JArray< jchar > toCharArray() const;
            String toLowerCase() const;
            String toString() const;
            String toUpperCase() const;
            String trim() const;
            static String valueOf(jboolean);
            static String valueOf(const ::java::lang::Object &);
            static String valueOf(jfloat);
            static String valueOf(jdouble);
            static String valueOf(jint);
            static String valueOf(const JArray< jchar > &);
            static String valueOf(jchar);
            static String valueOf(jlong);
            static String valueOf(const JArray< jchar > &, jint, jint);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(String);

        class t_String {
        public:
            PyObject_HEAD
            String object;
            static PyObject *wrap_Object(const String&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
