#ifndef java_io_PrintWriter_H
#define java_io_PrintWriter_H

#include "java/io/Writer.h"

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
    namespace io {

        class PrintWriter : public ::java::io::Writer {
        public:
            enum {
                mid_init$_5fdc3f48,
                mid_init$_5bcd5850,
                mid_init$_53203e9d,
                mid_init$_4a264742,
                mid_append_6cdbddb5,
                mid_append_4ea4b69d,
                mid_append_19a20159,
                mid_checkError_54c6a16a,
                mid_close_54c6a166,
                mid_flush_54c6a166,
                mid_format_d515d1d7,
                mid_print_5d1c7645,
                mid_print_87fd545a,
                mid_print_700e23d6,
                mid_print_bb0c767f,
                mid_print_39c7bd3c,
                mid_print_5fdc3f48,
                mid_print_290588ee,
                mid_print_06298cab,
                mid_print_0ee6df2f,
                mid_printf_d515d1d7,
                mid_println_54c6a166,
                mid_println_39c7bd3c,
                mid_println_5fdc3f48,
                mid_println_0ee6df2f,
                mid_println_bb0c767f,
                mid_println_06298cab,
                mid_println_5d1c7645,
                mid_println_700e23d6,
                mid_println_290588ee,
                mid_println_87fd545a,
                mid_write_5fdc3f48,
                mid_write_700e23d6,
                mid_write_39c7bd3c,
                mid_write_6f0bb356,
                mid_write_555f322c,
                mid_setError_54c6a166,
                mid_clearError_54c6a166,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit PrintWriter(jobject obj) : ::java::io::Writer(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            PrintWriter(const PrintWriter& obj) : ::java::io::Writer(obj) {}

            PrintWriter(const ::java::lang::String &);
            PrintWriter(const ::java::io::Writer &);
            PrintWriter(const ::java::io::Writer &, jboolean);
            PrintWriter(const ::java::lang::String &, const ::java::lang::String &);

            PrintWriter append(jchar) const;
            PrintWriter append(const ::java::lang::CharSequence &) const;
            PrintWriter append(const ::java::lang::CharSequence &, jint, jint) const;
            jboolean checkError() const;
            void close() const;
            void flush() const;
            PrintWriter format(const ::java::lang::String &, const JArray< ::java::lang::Object > &) const;
            void print(jdouble) const;
            void print(jchar) const;
            void print(const JArray< jchar > &) const;
            void print(jboolean) const;
            void print(jint) const;
            void print(const ::java::lang::String &) const;
            void print(const ::java::lang::Object &) const;
            void print(jfloat) const;
            void print(jlong) const;
            PrintWriter printf(const ::java::lang::String &, const JArray< ::java::lang::Object > &) const;
            void println() const;
            void println(jint) const;
            void println(const ::java::lang::String &) const;
            void println(jlong) const;
            void println(jboolean) const;
            void println(jfloat) const;
            void println(jdouble) const;
            void println(const JArray< jchar > &) const;
            void println(const ::java::lang::Object &) const;
            void println(jchar) const;
            void write(const ::java::lang::String &) const;
            void write(const JArray< jchar > &) const;
            void write(jint) const;
            void write(const JArray< jchar > &, jint, jint) const;
            void write(const ::java::lang::String &, jint, jint) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(PrintWriter);

        class t_PrintWriter {
        public:
            PyObject_HEAD
            PrintWriter object;
            static PyObject *wrap_Object(const PrintWriter&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
