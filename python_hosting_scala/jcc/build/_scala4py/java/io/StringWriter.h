#ifndef java_io_StringWriter_H
#define java_io_StringWriter_H

#include "java/io/Writer.h"

namespace java {
    namespace lang {
        class Class;
        class StringBuffer;
        class Appendable;
        class String;
        class CharSequence;
    }
}
template<class T> class JArray;

namespace java {
    namespace io {

        class StringWriter : public ::java::io::Writer {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_39c7bd3c,
                mid_append_3aee6342,
                mid_append_e2d4acee,
                mid_append_199526fa,
                mid_close_54c6a166,
                mid_flush_54c6a166,
                mid_getBuffer_d54172a5,
                mid_toString_14c7b5c5,
                mid_write_5fdc3f48,
                mid_write_39c7bd3c,
                mid_write_555f322c,
                mid_write_6f0bb356,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit StringWriter(jobject obj) : ::java::io::Writer(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            StringWriter(const StringWriter& obj) : ::java::io::Writer(obj) {}

            StringWriter();
            StringWriter(jint);

            StringWriter append(jchar) const;
            StringWriter append(const ::java::lang::CharSequence &) const;
            StringWriter append(const ::java::lang::CharSequence &, jint, jint) const;
            void close() const;
            void flush() const;
            ::java::lang::StringBuffer getBuffer() const;
            ::java::lang::String toString() const;
            void write(const ::java::lang::String &) const;
            void write(jint) const;
            void write(const ::java::lang::String &, jint, jint) const;
            void write(const JArray< jchar > &, jint, jint) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(StringWriter);

        class t_StringWriter {
        public:
            PyObject_HEAD
            StringWriter object;
            static PyObject *wrap_Object(const StringWriter&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
