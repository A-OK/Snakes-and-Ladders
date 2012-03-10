#ifndef java_lang_Object_H
#define java_lang_Object_H

#include "JObject.h"

namespace java {
    namespace lang {
        class Class;
        class InterruptedException;
        class String;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class Object : public JObject {
        public:
            enum {
                mid_init$_54c6a166,
                mid_equals_290588e2,
                mid_getClass_44a5f2c9,
                mid_hashCode_54c6a179,
                mid_notify_54c6a166,
                mid_notifyAll_54c6a166,
                mid_toString_14c7b5c5,
                mid_wait_54c6a166,
                mid_wait_0ee6df2f,
                mid_wait_25d05c8f,
                mid_finalize_54c6a166,
                mid_clone_846352c3,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Object(jobject obj) : ::JObject(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Object(const Object& obj) : ::JObject(obj) {}

            Object();

            jboolean equals(const Object &) const;
            ::java::lang::Class getClass() const;
            jint hashCode() const;
            void notify() const;
            void notifyAll() const;
            ::java::lang::String toString() const;
            void wait() const;
            void wait(jlong) const;
            void wait(jlong, jint) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Object);

        class t_Object {
        public:
            PyObject_HEAD
            Object object;
            static PyObject *wrap_Object(const Object&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
