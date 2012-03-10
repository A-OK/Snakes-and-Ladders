#ifndef java_io_Writer_H
#define java_io_Writer_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class String;
        class Appendable;
        class Class;
        class CharSequence;
    }
}
template<class T> class JArray;

namespace java {
    namespace io {

        class Writer : public ::java::lang::Object {
        public:
            enum {
                mid_append_368f1679,
                mid_append_31d2f801,
                mid_append_b3d4aa31,
                mid_close_54c6a166,
                mid_flush_54c6a166,
                mid_write_5fdc3f48,
                mid_write_700e23d6,
                mid_write_39c7bd3c,
                mid_write_555f322c,
                mid_write_6f0bb356,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Writer(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Writer(const Writer& obj) : ::java::lang::Object(obj) {}

            Writer append(jchar) const;
            Writer append(const ::java::lang::CharSequence &) const;
            Writer append(const ::java::lang::CharSequence &, jint, jint) const;
            void close() const;
            void flush() const;
            void write(const ::java::lang::String &) const;
            void write(const JArray< jchar > &) const;
            void write(jint) const;
            void write(const ::java::lang::String &, jint, jint) const;
            void write(const JArray< jchar > &, jint, jint) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(Writer);

        class t_Writer {
        public:
            PyObject_HEAD
            Writer object;
            static PyObject *wrap_Object(const Writer&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
