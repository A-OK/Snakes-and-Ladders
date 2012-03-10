#ifndef java_lang_Appendable_H
#define java_lang_Appendable_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
        class CharSequence;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class Appendable : public ::java::lang::Object {
        public:
            enum {
                mid_append_fac808c8,
                mid_append_ca3c2aa4,
                mid_append_7f83fd04,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Appendable(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Appendable(const Appendable& obj) : ::java::lang::Object(obj) {}

            Appendable append(jchar) const;
            Appendable append(const ::java::lang::CharSequence &) const;
            Appendable append(const ::java::lang::CharSequence &, jint, jint) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Appendable);

        class t_Appendable {
        public:
            PyObject_HEAD
            Appendable object;
            static PyObject *wrap_Object(const Appendable&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
