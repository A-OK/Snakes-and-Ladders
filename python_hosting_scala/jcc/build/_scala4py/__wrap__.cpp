#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Object.h"
#include "java/lang/InterruptedException.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Object::class$ = NULL;
        jmethodID *Object::mids$ = NULL;

        jclass Object::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Object");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
                mids$[mid_getClass_44a5f2c9] = env->getMethodID(cls, "getClass", "()Ljava/lang/Class;");
                mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
                mids$[mid_notify_54c6a166] = env->getMethodID(cls, "notify", "()V");
                mids$[mid_notifyAll_54c6a166] = env->getMethodID(cls, "notifyAll", "()V");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
                mids$[mid_wait_54c6a166] = env->getMethodID(cls, "wait", "()V");
                mids$[mid_wait_0ee6df2f] = env->getMethodID(cls, "wait", "(J)V");
                mids$[mid_wait_25d05c8f] = env->getMethodID(cls, "wait", "(JI)V");
                mids$[mid_finalize_54c6a166] = env->getMethodID(cls, "finalize", "()V");
                mids$[mid_clone_846352c3] = env->getMethodID(cls, "clone", "()Ljava/lang/Object;");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        Object::Object() : ::JObject(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        jboolean Object::equals(const Object & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
        }

        ::java::lang::Class Object::getClass() const
        {
            return ::java::lang::Class(env->callObjectMethod(this$, mids$[mid_getClass_44a5f2c9]));
        }

        jint Object::hashCode() const
        {
            return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
        }

        void Object::notify() const
        {
            env->callVoidMethod(this$, mids$[mid_notify_54c6a166]);
        }

        void Object::notifyAll() const
        {
            env->callVoidMethod(this$, mids$[mid_notifyAll_54c6a166]);
        }

        ::java::lang::String Object::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }

        void Object::wait() const
        {
            env->callVoidMethod(this$, mids$[mid_wait_54c6a166]);
        }

        void Object::wait(jlong a0) const
        {
            env->callVoidMethod(this$, mids$[mid_wait_0ee6df2f], a0);
        }

        void Object::wait(jlong a0, jint a1) const
        {
            env->callVoidMethod(this$, mids$[mid_wait_25d05c8f], a0, a1);
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Object_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Object_instance_(PyTypeObject *type, PyObject *arg);
        static int t_Object_init_(t_Object *self, PyObject *args, PyObject *kwds);
        static PyObject *t_Object_equals(t_Object *self, PyObject *arg);
        static PyObject *t_Object_getClass(t_Object *self);
        static PyObject *t_Object_hashCode(t_Object *self);
        static PyObject *t_Object_notify(t_Object *self);
        static PyObject *t_Object_notifyAll(t_Object *self);
        static PyObject *t_Object_toString(t_Object *self);
        static PyObject *t_Object_wait(t_Object *self, PyObject *args);
        static PyObject *t_Object_get__class(t_Object *self, void *data);
        static PyGetSetDef t_Object__fields_[] = {
            DECLARE_GET_FIELD(t_Object, class),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_Object__methods_[] = {
            DECLARE_METHOD(t_Object, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Object, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Object, equals, METH_O),
            DECLARE_METHOD(t_Object, getClass, METH_NOARGS),
            DECLARE_METHOD(t_Object, hashCode, METH_NOARGS),
            DECLARE_METHOD(t_Object, notify, METH_NOARGS),
            DECLARE_METHOD(t_Object, notifyAll, METH_NOARGS),
            DECLARE_METHOD(t_Object, toString, METH_NOARGS),
            DECLARE_METHOD(t_Object, wait, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Object, t_Object, JObject, Object, t_Object_init_, 0, 0, t_Object__fields_, 0, 0);

        void t_Object::install(PyObject *module)
        {
            installType(&PY_TYPE(Object), module, "Object", 0);
        }

        void t_Object::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Object).tp_dict, "class_", make_descriptor(Object::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Object).tp_dict, "wrapfn_", make_descriptor(t_Object::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(Object).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_Object_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Object::initializeClass, 1)))
                return NULL;
            return t_Object::wrap_Object(Object(((t_Object *) arg)->object.this$));
        }
        static PyObject *t_Object_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Object::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_Object_init_(t_Object *self, PyObject *args, PyObject *kwds)
        {
            Object object((jobject) NULL);

            INT_CALL(object = Object());
            self->object = object;

            return 0;
        }

        static PyObject *t_Object_equals(t_Object *self, PyObject *arg)
        {
            Object a0((jobject) NULL);
            jboolean result;

            if (!parseArg(arg, "o", &a0))
            {
                OBJ_CALL(result = self->object.equals(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError((PyObject *) self, "equals", arg);
            return NULL;
        }

        static PyObject *t_Object_getClass(t_Object *self)
        {
            ::java::lang::Class result((jobject) NULL);
            OBJ_CALL(result = self->object.getClass());
            return ::java::lang::t_Class::wrap_Object(result);
        }

        static PyObject *t_Object_hashCode(t_Object *self)
        {
            jint result;
            OBJ_CALL(result = self->object.hashCode());
            return PyInt_FromLong((long) result);
        }

        static PyObject *t_Object_notify(t_Object *self)
        {
            OBJ_CALL(self->object.notify());
            Py_RETURN_NONE;
        }

        static PyObject *t_Object_notifyAll(t_Object *self)
        {
            OBJ_CALL(self->object.notifyAll());
            Py_RETURN_NONE;
        }

        static PyObject *t_Object_toString(t_Object *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.toString());
            return j2p(result);
        }

        static PyObject *t_Object_wait(t_Object *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    OBJ_CALL(self->object.wait());
                    Py_RETURN_NONE;
                }
                break;
              case 1:
                {
                    jlong a0;

                    if (!parseArgs(args, "J", &a0))
                    {
                        OBJ_CALL(self->object.wait(a0));
                        Py_RETURN_NONE;
                    }
                }
                break;
              case 2:
                {
                    jlong a0;
                    jint a1;

                    if (!parseArgs(args, "JI", &a0, &a1))
                    {
                        OBJ_CALL(self->object.wait(a0, a1));
                        Py_RETURN_NONE;
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "wait", args);
            return NULL;
        }

        static PyObject *t_Object_get__class(t_Object *self, void *data)
        {
            ::java::lang::Class value((jobject) NULL);
            OBJ_CALL(value = self->object.getClass());
            return ::java::lang::t_Class::wrap_Object(value);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/io/PrintWriter.h"
#include "java/lang/String.h"
#include "java/lang/Object.h"
#include "java/lang/CharSequence.h"
#include "java/lang/Appendable.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace io {

        ::java::lang::Class *PrintWriter::class$ = NULL;
        jmethodID *PrintWriter::mids$ = NULL;

        jclass PrintWriter::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/io/PrintWriter");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_init$_5bcd5850] = env->getMethodID(cls, "<init>", "(Ljava/io/Writer;)V");
                mids$[mid_init$_53203e9d] = env->getMethodID(cls, "<init>", "(Ljava/io/Writer;Z)V");
                mids$[mid_init$_4a264742] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/String;)V");
                mids$[mid_append_6cdbddb5] = env->getMethodID(cls, "append", "(C)Ljava/io/PrintWriter;");
                mids$[mid_append_4ea4b69d] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;)Ljava/io/PrintWriter;");
                mids$[mid_append_19a20159] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;II)Ljava/io/PrintWriter;");
                mids$[mid_checkError_54c6a16a] = env->getMethodID(cls, "checkError", "()Z");
                mids$[mid_close_54c6a166] = env->getMethodID(cls, "close", "()V");
                mids$[mid_flush_54c6a166] = env->getMethodID(cls, "flush", "()V");
                mids$[mid_format_d515d1d7] = env->getMethodID(cls, "format", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintWriter;");
                mids$[mid_print_5d1c7645] = env->getMethodID(cls, "print", "(D)V");
                mids$[mid_print_87fd545a] = env->getMethodID(cls, "print", "(C)V");
                mids$[mid_print_700e23d6] = env->getMethodID(cls, "print", "([C)V");
                mids$[mid_print_bb0c767f] = env->getMethodID(cls, "print", "(Z)V");
                mids$[mid_print_39c7bd3c] = env->getMethodID(cls, "print", "(I)V");
                mids$[mid_print_5fdc3f48] = env->getMethodID(cls, "print", "(Ljava/lang/String;)V");
                mids$[mid_print_290588ee] = env->getMethodID(cls, "print", "(Ljava/lang/Object;)V");
                mids$[mid_print_06298cab] = env->getMethodID(cls, "print", "(F)V");
                mids$[mid_print_0ee6df2f] = env->getMethodID(cls, "print", "(J)V");
                mids$[mid_printf_d515d1d7] = env->getMethodID(cls, "printf", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintWriter;");
                mids$[mid_println_54c6a166] = env->getMethodID(cls, "println", "()V");
                mids$[mid_println_39c7bd3c] = env->getMethodID(cls, "println", "(I)V");
                mids$[mid_println_5fdc3f48] = env->getMethodID(cls, "println", "(Ljava/lang/String;)V");
                mids$[mid_println_0ee6df2f] = env->getMethodID(cls, "println", "(J)V");
                mids$[mid_println_bb0c767f] = env->getMethodID(cls, "println", "(Z)V");
                mids$[mid_println_06298cab] = env->getMethodID(cls, "println", "(F)V");
                mids$[mid_println_5d1c7645] = env->getMethodID(cls, "println", "(D)V");
                mids$[mid_println_700e23d6] = env->getMethodID(cls, "println", "([C)V");
                mids$[mid_println_290588ee] = env->getMethodID(cls, "println", "(Ljava/lang/Object;)V");
                mids$[mid_println_87fd545a] = env->getMethodID(cls, "println", "(C)V");
                mids$[mid_write_5fdc3f48] = env->getMethodID(cls, "write", "(Ljava/lang/String;)V");
                mids$[mid_write_700e23d6] = env->getMethodID(cls, "write", "([C)V");
                mids$[mid_write_39c7bd3c] = env->getMethodID(cls, "write", "(I)V");
                mids$[mid_write_6f0bb356] = env->getMethodID(cls, "write", "([CII)V");
                mids$[mid_write_555f322c] = env->getMethodID(cls, "write", "(Ljava/lang/String;II)V");
                mids$[mid_setError_54c6a166] = env->getMethodID(cls, "setError", "()V");
                mids$[mid_clearError_54c6a166] = env->getMethodID(cls, "clearError", "()V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        PrintWriter::PrintWriter(const ::java::lang::String & a0) : ::java::io::Writer(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        PrintWriter::PrintWriter(const ::java::io::Writer & a0) : ::java::io::Writer(env->newObject(initializeClass, &mids$, mid_init$_5bcd5850, a0.this$)) {}

        PrintWriter::PrintWriter(const ::java::io::Writer & a0, jboolean a1) : ::java::io::Writer(env->newObject(initializeClass, &mids$, mid_init$_53203e9d, a0.this$, a1)) {}

        PrintWriter::PrintWriter(const ::java::lang::String & a0, const ::java::lang::String & a1) : ::java::io::Writer(env->newObject(initializeClass, &mids$, mid_init$_4a264742, a0.this$, a1.this$)) {}

        PrintWriter PrintWriter::append(jchar a0) const
        {
            return PrintWriter(env->callObjectMethod(this$, mids$[mid_append_6cdbddb5], a0));
        }

        PrintWriter PrintWriter::append(const ::java::lang::CharSequence & a0) const
        {
            return PrintWriter(env->callObjectMethod(this$, mids$[mid_append_4ea4b69d], a0.this$));
        }

        PrintWriter PrintWriter::append(const ::java::lang::CharSequence & a0, jint a1, jint a2) const
        {
            return PrintWriter(env->callObjectMethod(this$, mids$[mid_append_19a20159], a0.this$, a1, a2));
        }

        jboolean PrintWriter::checkError() const
        {
            return env->callBooleanMethod(this$, mids$[mid_checkError_54c6a16a]);
        }

        void PrintWriter::close() const
        {
            env->callVoidMethod(this$, mids$[mid_close_54c6a166]);
        }

        void PrintWriter::flush() const
        {
            env->callVoidMethod(this$, mids$[mid_flush_54c6a166]);
        }

        PrintWriter PrintWriter::format(const ::java::lang::String & a0, const JArray< ::java::lang::Object > & a1) const
        {
            return PrintWriter(env->callObjectMethod(this$, mids$[mid_format_d515d1d7], a0.this$, a1.this$));
        }

        void PrintWriter::print(jdouble a0) const
        {
            env->callVoidMethod(this$, mids$[mid_print_5d1c7645], a0);
        }

        void PrintWriter::print(jchar a0) const
        {
            env->callVoidMethod(this$, mids$[mid_print_87fd545a], a0);
        }

        void PrintWriter::print(const JArray< jchar > & a0) const
        {
            env->callVoidMethod(this$, mids$[mid_print_700e23d6], a0.this$);
        }

        void PrintWriter::print(jboolean a0) const
        {
            env->callVoidMethod(this$, mids$[mid_print_bb0c767f], a0);
        }

        void PrintWriter::print(jint a0) const
        {
            env->callVoidMethod(this$, mids$[mid_print_39c7bd3c], a0);
        }

        void PrintWriter::print(const ::java::lang::String & a0) const
        {
            env->callVoidMethod(this$, mids$[mid_print_5fdc3f48], a0.this$);
        }

        void PrintWriter::print(const ::java::lang::Object & a0) const
        {
            env->callVoidMethod(this$, mids$[mid_print_290588ee], a0.this$);
        }

        void PrintWriter::print(jfloat a0) const
        {
            env->callVoidMethod(this$, mids$[mid_print_06298cab], a0);
        }

        void PrintWriter::print(jlong a0) const
        {
            env->callVoidMethod(this$, mids$[mid_print_0ee6df2f], a0);
        }

        PrintWriter PrintWriter::printf(const ::java::lang::String & a0, const JArray< ::java::lang::Object > & a1) const
        {
            return PrintWriter(env->callObjectMethod(this$, mids$[mid_printf_d515d1d7], a0.this$, a1.this$));
        }

        void PrintWriter::println() const
        {
            env->callVoidMethod(this$, mids$[mid_println_54c6a166]);
        }

        void PrintWriter::println(jint a0) const
        {
            env->callVoidMethod(this$, mids$[mid_println_39c7bd3c], a0);
        }

        void PrintWriter::println(const ::java::lang::String & a0) const
        {
            env->callVoidMethod(this$, mids$[mid_println_5fdc3f48], a0.this$);
        }

        void PrintWriter::println(jlong a0) const
        {
            env->callVoidMethod(this$, mids$[mid_println_0ee6df2f], a0);
        }

        void PrintWriter::println(jboolean a0) const
        {
            env->callVoidMethod(this$, mids$[mid_println_bb0c767f], a0);
        }

        void PrintWriter::println(jfloat a0) const
        {
            env->callVoidMethod(this$, mids$[mid_println_06298cab], a0);
        }

        void PrintWriter::println(jdouble a0) const
        {
            env->callVoidMethod(this$, mids$[mid_println_5d1c7645], a0);
        }

        void PrintWriter::println(const JArray< jchar > & a0) const
        {
            env->callVoidMethod(this$, mids$[mid_println_700e23d6], a0.this$);
        }

        void PrintWriter::println(const ::java::lang::Object & a0) const
        {
            env->callVoidMethod(this$, mids$[mid_println_290588ee], a0.this$);
        }

        void PrintWriter::println(jchar a0) const
        {
            env->callVoidMethod(this$, mids$[mid_println_87fd545a], a0);
        }

        void PrintWriter::write(const ::java::lang::String & a0) const
        {
            env->callVoidMethod(this$, mids$[mid_write_5fdc3f48], a0.this$);
        }

        void PrintWriter::write(const JArray< jchar > & a0) const
        {
            env->callVoidMethod(this$, mids$[mid_write_700e23d6], a0.this$);
        }

        void PrintWriter::write(jint a0) const
        {
            env->callVoidMethod(this$, mids$[mid_write_39c7bd3c], a0);
        }

        void PrintWriter::write(const JArray< jchar > & a0, jint a1, jint a2) const
        {
            env->callVoidMethod(this$, mids$[mid_write_6f0bb356], a0.this$, a1, a2);
        }

        void PrintWriter::write(const ::java::lang::String & a0, jint a1, jint a2) const
        {
            env->callVoidMethod(this$, mids$[mid_write_555f322c], a0.this$, a1, a2);
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace io {
        static PyObject *t_PrintWriter_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_PrintWriter_instance_(PyTypeObject *type, PyObject *arg);
        static int t_PrintWriter_init_(t_PrintWriter *self, PyObject *args, PyObject *kwds);
        static PyObject *t_PrintWriter_append(t_PrintWriter *self, PyObject *args);
        static PyObject *t_PrintWriter_checkError(t_PrintWriter *self);
        static PyObject *t_PrintWriter_close(t_PrintWriter *self, PyObject *args);
        static PyObject *t_PrintWriter_flush(t_PrintWriter *self, PyObject *args);
        static PyObject *t_PrintWriter_format(t_PrintWriter *self, PyObject *args);
        static PyObject *t_PrintWriter_print(t_PrintWriter *self, PyObject *args);
        static PyObject *t_PrintWriter_printf(t_PrintWriter *self, PyObject *args);
        static PyObject *t_PrintWriter_println(t_PrintWriter *self, PyObject *args);
        static PyObject *t_PrintWriter_write(t_PrintWriter *self, PyObject *args);

        static PyMethodDef t_PrintWriter__methods_[] = {
            DECLARE_METHOD(t_PrintWriter, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_PrintWriter, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_PrintWriter, append, METH_VARARGS),
            DECLARE_METHOD(t_PrintWriter, checkError, METH_NOARGS),
            DECLARE_METHOD(t_PrintWriter, close, METH_VARARGS),
            DECLARE_METHOD(t_PrintWriter, flush, METH_VARARGS),
            DECLARE_METHOD(t_PrintWriter, format, METH_VARARGS),
            DECLARE_METHOD(t_PrintWriter, print, METH_VARARGS),
            DECLARE_METHOD(t_PrintWriter, printf, METH_VARARGS),
            DECLARE_METHOD(t_PrintWriter, println, METH_VARARGS),
            DECLARE_METHOD(t_PrintWriter, write, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(PrintWriter, t_PrintWriter, ::java::io::Writer, PrintWriter, t_PrintWriter_init_, 0, 0, 0, 0, 0);

        void t_PrintWriter::install(PyObject *module)
        {
            installType(&PY_TYPE(PrintWriter), module, "PrintWriter", 0);
        }

        void t_PrintWriter::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(PrintWriter).tp_dict, "class_", make_descriptor(PrintWriter::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(PrintWriter).tp_dict, "wrapfn_", make_descriptor(t_PrintWriter::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(PrintWriter).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_PrintWriter_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, PrintWriter::initializeClass, 1)))
                return NULL;
            return t_PrintWriter::wrap_Object(PrintWriter(((t_PrintWriter *) arg)->object.this$));
        }
        static PyObject *t_PrintWriter_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, PrintWriter::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_PrintWriter_init_(t_PrintWriter *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    PrintWriter object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = PrintWriter(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::io::Writer a0((jobject) NULL);
                    PrintWriter object((jobject) NULL);

                    if (!parseArgs(args, "k", ::java::io::Writer::initializeClass, &a0))
                    {
                        INT_CALL(object = PrintWriter(a0));
                        self->object = object;
                        break;
                    }
                }
                goto err;
              case 2:
                {
                    ::java::io::Writer a0((jobject) NULL);
                    jboolean a1;
                    PrintWriter object((jobject) NULL);

                    if (!parseArgs(args, "kZ", ::java::io::Writer::initializeClass, &a0, &a1))
                    {
                        INT_CALL(object = PrintWriter(a0, a1));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    ::java::lang::String a1((jobject) NULL);
                    PrintWriter object((jobject) NULL);

                    if (!parseArgs(args, "ss", &a0, &a1))
                    {
                        INT_CALL(object = PrintWriter(a0, a1));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_PrintWriter_append(t_PrintWriter *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jchar a0;
                    PrintWriter result((jobject) NULL);

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_PrintWriter::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    PrintWriter result((jobject) NULL);

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_PrintWriter::wrap_Object(result);
                    }
                }
                break;
              case 3:
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    PrintWriter result((jobject) NULL);

                    if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = self->object.append(a0, a1, a2));
                        return t_PrintWriter::wrap_Object(result);
                    }
                }
            }

            return callSuper(&PY_TYPE(PrintWriter), (PyObject *) self, "append", args, 2);
        }

        static PyObject *t_PrintWriter_checkError(t_PrintWriter *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.checkError());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_PrintWriter_close(t_PrintWriter *self, PyObject *args)
        {

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(self->object.close());
                Py_RETURN_NONE;
            }

            return callSuper(&PY_TYPE(PrintWriter), (PyObject *) self, "close", args, 2);
        }

        static PyObject *t_PrintWriter_flush(t_PrintWriter *self, PyObject *args)
        {

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(self->object.flush());
                Py_RETURN_NONE;
            }

            return callSuper(&PY_TYPE(PrintWriter), (PyObject *) self, "flush", args, 2);
        }

        static PyObject *t_PrintWriter_format(t_PrintWriter *self, PyObject *args)
        {
            ::java::lang::String a0((jobject) NULL);
            JArray< ::java::lang::Object > a1((jobject) NULL);
            PrintWriter result((jobject) NULL);

            if (!parseArgs(args, "s[o", &a0, &a1))
            {
                OBJ_CALL(result = self->object.format(a0, a1));
                return t_PrintWriter::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "format", args);
            return NULL;
        }

        static PyObject *t_PrintWriter_print(t_PrintWriter *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jdouble a0;

                    if (!parseArgs(args, "D", &a0))
                    {
                        OBJ_CALL(self->object.print(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    jchar a0;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(self->object.print(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    JArray< jchar > a0((jobject) NULL);

                    if (!parseArgs(args, "[C", &a0))
                    {
                        OBJ_CALL(self->object.print(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    jboolean a0;

                    if (!parseArgs(args, "Z", &a0))
                    {
                        OBJ_CALL(self->object.print(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    jint a0;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(self->object.print(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(self->object.print(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    ::java::lang::Object a0((jobject) NULL);

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(self->object.print(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    jfloat a0;

                    if (!parseArgs(args, "F", &a0))
                    {
                        OBJ_CALL(self->object.print(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    jlong a0;

                    if (!parseArgs(args, "J", &a0))
                    {
                        OBJ_CALL(self->object.print(a0));
                        Py_RETURN_NONE;
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "print", args);
            return NULL;
        }

        static PyObject *t_PrintWriter_printf(t_PrintWriter *self, PyObject *args)
        {
            ::java::lang::String a0((jobject) NULL);
            JArray< ::java::lang::Object > a1((jobject) NULL);
            PrintWriter result((jobject) NULL);

            if (!parseArgs(args, "s[o", &a0, &a1))
            {
                OBJ_CALL(result = self->object.printf(a0, a1));
                return t_PrintWriter::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "printf", args);
            return NULL;
        }

        static PyObject *t_PrintWriter_println(t_PrintWriter *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    OBJ_CALL(self->object.println());
                    Py_RETURN_NONE;
                }
                break;
              case 1:
                {
                    jint a0;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(self->object.println(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(self->object.println(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    jlong a0;

                    if (!parseArgs(args, "J", &a0))
                    {
                        OBJ_CALL(self->object.println(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    jboolean a0;

                    if (!parseArgs(args, "Z", &a0))
                    {
                        OBJ_CALL(self->object.println(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    jfloat a0;

                    if (!parseArgs(args, "F", &a0))
                    {
                        OBJ_CALL(self->object.println(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    jdouble a0;

                    if (!parseArgs(args, "D", &a0))
                    {
                        OBJ_CALL(self->object.println(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    JArray< jchar > a0((jobject) NULL);

                    if (!parseArgs(args, "[C", &a0))
                    {
                        OBJ_CALL(self->object.println(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    ::java::lang::Object a0((jobject) NULL);

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(self->object.println(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    jchar a0;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(self->object.println(a0));
                        Py_RETURN_NONE;
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "println", args);
            return NULL;
        }

        static PyObject *t_PrintWriter_write(t_PrintWriter *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(self->object.write(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    JArray< jchar > a0((jobject) NULL);

                    if (!parseArgs(args, "[C", &a0))
                    {
                        OBJ_CALL(self->object.write(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    jint a0;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(self->object.write(a0));
                        Py_RETURN_NONE;
                    }
                }
                break;
              case 3:
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint a2;

                    if (!parseArgs(args, "[CII", &a0, &a1, &a2))
                    {
                        OBJ_CALL(self->object.write(a0, a1, a2));
                        Py_RETURN_NONE;
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    jint a2;

                    if (!parseArgs(args, "sII", &a0, &a1, &a2))
                    {
                        OBJ_CALL(self->object.write(a0, a1, a2));
                        Py_RETURN_NONE;
                    }
                }
            }

            return callSuper(&PY_TYPE(PrintWriter), (PyObject *) self, "write", args, 2);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "scala/runtime/AbstractFunction1.h"
#include "scala/Function1.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "scala/ScalaObject.h"
#include "JArray.h"

namespace scala {
    namespace runtime {

        ::java::lang::Class *AbstractFunction1::class$ = NULL;
        jmethodID *AbstractFunction1::mids$ = NULL;

        jclass AbstractFunction1::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("scala/runtime/AbstractFunction1");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_andThen_279d294f] = env->getMethodID(cls, "andThen", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcDD$sp_279d294f] = env->getMethodID(cls, "andThen$mcDD$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcDF$sp_279d294f] = env->getMethodID(cls, "andThen$mcDF$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcDI$sp_279d294f] = env->getMethodID(cls, "andThen$mcDI$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcDJ$sp_279d294f] = env->getMethodID(cls, "andThen$mcDJ$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcFD$sp_279d294f] = env->getMethodID(cls, "andThen$mcFD$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcFF$sp_279d294f] = env->getMethodID(cls, "andThen$mcFF$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcFI$sp_279d294f] = env->getMethodID(cls, "andThen$mcFI$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcFJ$sp_279d294f] = env->getMethodID(cls, "andThen$mcFJ$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcID$sp_279d294f] = env->getMethodID(cls, "andThen$mcID$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcIF$sp_279d294f] = env->getMethodID(cls, "andThen$mcIF$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcII$sp_279d294f] = env->getMethodID(cls, "andThen$mcII$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcIJ$sp_279d294f] = env->getMethodID(cls, "andThen$mcIJ$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcJD$sp_279d294f] = env->getMethodID(cls, "andThen$mcJD$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcJF$sp_279d294f] = env->getMethodID(cls, "andThen$mcJF$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcJI$sp_279d294f] = env->getMethodID(cls, "andThen$mcJI$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcJJ$sp_279d294f] = env->getMethodID(cls, "andThen$mcJJ$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcZD$sp_279d294f] = env->getMethodID(cls, "andThen$mcZD$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcZF$sp_279d294f] = env->getMethodID(cls, "andThen$mcZF$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcZI$sp_279d294f] = env->getMethodID(cls, "andThen$mcZI$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcZJ$sp_279d294f] = env->getMethodID(cls, "andThen$mcZJ$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_apply$mcDD$sp_5d1c7657] = env->getMethodID(cls, "apply$mcDD$sp", "(D)D");
                mids$[mid_apply$mcDF$sp_06298cb9] = env->getMethodID(cls, "apply$mcDF$sp", "(F)D");
                mids$[mid_apply$mcDI$sp_39c7bd2e] = env->getMethodID(cls, "apply$mcDI$sp", "(I)D");
                mids$[mid_apply$mcDJ$sp_0ee6df3d] = env->getMethodID(cls, "apply$mcDJ$sp", "(J)D");
                mids$[mid_apply$mcFD$sp_5d1c7655] = env->getMethodID(cls, "apply$mcFD$sp", "(D)F");
                mids$[mid_apply$mcFF$sp_06298cbb] = env->getMethodID(cls, "apply$mcFF$sp", "(F)F");
                mids$[mid_apply$mcFI$sp_39c7bd2c] = env->getMethodID(cls, "apply$mcFI$sp", "(I)F");
                mids$[mid_apply$mcFJ$sp_0ee6df3f] = env->getMethodID(cls, "apply$mcFJ$sp", "(J)F");
                mids$[mid_apply$mcID$sp_5d1c765a] = env->getMethodID(cls, "apply$mcID$sp", "(D)I");
                mids$[mid_apply$mcIF$sp_06298cb4] = env->getMethodID(cls, "apply$mcIF$sp", "(F)I");
                mids$[mid_apply$mcII$sp_39c7bd23] = env->getMethodID(cls, "apply$mcII$sp", "(I)I");
                mids$[mid_apply$mcIJ$sp_0ee6df30] = env->getMethodID(cls, "apply$mcIJ$sp", "(J)I");
                mids$[mid_apply$mcJD$sp_5d1c7659] = env->getMethodID(cls, "apply$mcJD$sp", "(D)J");
                mids$[mid_apply$mcJF$sp_06298cb7] = env->getMethodID(cls, "apply$mcJF$sp", "(F)J");
                mids$[mid_apply$mcJI$sp_39c7bd20] = env->getMethodID(cls, "apply$mcJI$sp", "(I)J");
                mids$[mid_apply$mcJJ$sp_0ee6df33] = env->getMethodID(cls, "apply$mcJJ$sp", "(J)J");
                mids$[mid_apply$mcVD$sp_5d1c7645] = env->getMethodID(cls, "apply$mcVD$sp", "(D)V");
                mids$[mid_apply$mcVF$sp_06298cab] = env->getMethodID(cls, "apply$mcVF$sp", "(F)V");
                mids$[mid_apply$mcVI$sp_39c7bd3c] = env->getMethodID(cls, "apply$mcVI$sp", "(I)V");
                mids$[mid_apply$mcVJ$sp_0ee6df2f] = env->getMethodID(cls, "apply$mcVJ$sp", "(J)V");
                mids$[mid_apply$mcZD$sp_5d1c7649] = env->getMethodID(cls, "apply$mcZD$sp", "(D)Z");
                mids$[mid_apply$mcZF$sp_06298ca7] = env->getMethodID(cls, "apply$mcZF$sp", "(F)Z");
                mids$[mid_apply$mcZI$sp_39c7bd30] = env->getMethodID(cls, "apply$mcZI$sp", "(I)Z");
                mids$[mid_apply$mcZJ$sp_0ee6df23] = env->getMethodID(cls, "apply$mcZJ$sp", "(J)Z");
                mids$[mid_compose_279d294f] = env->getMethodID(cls, "compose", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcDD$sp_279d294f] = env->getMethodID(cls, "compose$mcDD$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcDF$sp_279d294f] = env->getMethodID(cls, "compose$mcDF$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcDI$sp_279d294f] = env->getMethodID(cls, "compose$mcDI$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcDJ$sp_279d294f] = env->getMethodID(cls, "compose$mcDJ$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcFD$sp_279d294f] = env->getMethodID(cls, "compose$mcFD$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcFF$sp_279d294f] = env->getMethodID(cls, "compose$mcFF$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcFI$sp_279d294f] = env->getMethodID(cls, "compose$mcFI$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcFJ$sp_279d294f] = env->getMethodID(cls, "compose$mcFJ$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcID$sp_279d294f] = env->getMethodID(cls, "compose$mcID$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcIF$sp_279d294f] = env->getMethodID(cls, "compose$mcIF$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcII$sp_279d294f] = env->getMethodID(cls, "compose$mcII$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcIJ$sp_279d294f] = env->getMethodID(cls, "compose$mcIJ$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcJD$sp_279d294f] = env->getMethodID(cls, "compose$mcJD$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcJF$sp_279d294f] = env->getMethodID(cls, "compose$mcJF$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcJI$sp_279d294f] = env->getMethodID(cls, "compose$mcJI$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcJJ$sp_279d294f] = env->getMethodID(cls, "compose$mcJJ$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcZD$sp_279d294f] = env->getMethodID(cls, "compose$mcZD$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcZF$sp_279d294f] = env->getMethodID(cls, "compose$mcZF$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcZI$sp_279d294f] = env->getMethodID(cls, "compose$mcZI$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcZJ$sp_279d294f] = env->getMethodID(cls, "compose$mcZJ$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        AbstractFunction1::AbstractFunction1() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        ::scala::Function1 AbstractFunction1::andThen(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcDD$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcDD$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcDF$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcDF$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcDI$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcDI$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcDJ$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcDJ$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcFD$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcFD$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcFF$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcFF$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcFI$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcFI$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcFJ$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcFJ$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcID$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcID$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcIF$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcIF$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcII$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcII$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcIJ$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcIJ$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcJD$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcJD$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcJF$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcJF$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcJI$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcJI$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcJJ$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcJJ$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcZD$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcZD$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcZF$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcZF$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcZI$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcZI$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::andThen$mcZJ$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcZJ$sp_279d294f], a0.this$));
        }

        jdouble AbstractFunction1::apply$mcDD$sp(jdouble a0) const
        {
            return env->callDoubleMethod(this$, mids$[mid_apply$mcDD$sp_5d1c7657], a0);
        }

        jdouble AbstractFunction1::apply$mcDF$sp(jfloat a0) const
        {
            return env->callDoubleMethod(this$, mids$[mid_apply$mcDF$sp_06298cb9], a0);
        }

        jdouble AbstractFunction1::apply$mcDI$sp(jint a0) const
        {
            return env->callDoubleMethod(this$, mids$[mid_apply$mcDI$sp_39c7bd2e], a0);
        }

        jdouble AbstractFunction1::apply$mcDJ$sp(jlong a0) const
        {
            return env->callDoubleMethod(this$, mids$[mid_apply$mcDJ$sp_0ee6df3d], a0);
        }

        jfloat AbstractFunction1::apply$mcFD$sp(jdouble a0) const
        {
            return env->callFloatMethod(this$, mids$[mid_apply$mcFD$sp_5d1c7655], a0);
        }

        jfloat AbstractFunction1::apply$mcFF$sp(jfloat a0) const
        {
            return env->callFloatMethod(this$, mids$[mid_apply$mcFF$sp_06298cbb], a0);
        }

        jfloat AbstractFunction1::apply$mcFI$sp(jint a0) const
        {
            return env->callFloatMethod(this$, mids$[mid_apply$mcFI$sp_39c7bd2c], a0);
        }

        jfloat AbstractFunction1::apply$mcFJ$sp(jlong a0) const
        {
            return env->callFloatMethod(this$, mids$[mid_apply$mcFJ$sp_0ee6df3f], a0);
        }

        jint AbstractFunction1::apply$mcID$sp(jdouble a0) const
        {
            return env->callIntMethod(this$, mids$[mid_apply$mcID$sp_5d1c765a], a0);
        }

        jint AbstractFunction1::apply$mcIF$sp(jfloat a0) const
        {
            return env->callIntMethod(this$, mids$[mid_apply$mcIF$sp_06298cb4], a0);
        }

        jint AbstractFunction1::apply$mcII$sp(jint a0) const
        {
            return env->callIntMethod(this$, mids$[mid_apply$mcII$sp_39c7bd23], a0);
        }

        jint AbstractFunction1::apply$mcIJ$sp(jlong a0) const
        {
            return env->callIntMethod(this$, mids$[mid_apply$mcIJ$sp_0ee6df30], a0);
        }

        jlong AbstractFunction1::apply$mcJD$sp(jdouble a0) const
        {
            return env->callLongMethod(this$, mids$[mid_apply$mcJD$sp_5d1c7659], a0);
        }

        jlong AbstractFunction1::apply$mcJF$sp(jfloat a0) const
        {
            return env->callLongMethod(this$, mids$[mid_apply$mcJF$sp_06298cb7], a0);
        }

        jlong AbstractFunction1::apply$mcJI$sp(jint a0) const
        {
            return env->callLongMethod(this$, mids$[mid_apply$mcJI$sp_39c7bd20], a0);
        }

        jlong AbstractFunction1::apply$mcJJ$sp(jlong a0) const
        {
            return env->callLongMethod(this$, mids$[mid_apply$mcJJ$sp_0ee6df33], a0);
        }

        void AbstractFunction1::apply$mcVD$sp(jdouble a0) const
        {
            env->callVoidMethod(this$, mids$[mid_apply$mcVD$sp_5d1c7645], a0);
        }

        void AbstractFunction1::apply$mcVF$sp(jfloat a0) const
        {
            env->callVoidMethod(this$, mids$[mid_apply$mcVF$sp_06298cab], a0);
        }

        void AbstractFunction1::apply$mcVI$sp(jint a0) const
        {
            env->callVoidMethod(this$, mids$[mid_apply$mcVI$sp_39c7bd3c], a0);
        }

        void AbstractFunction1::apply$mcVJ$sp(jlong a0) const
        {
            env->callVoidMethod(this$, mids$[mid_apply$mcVJ$sp_0ee6df2f], a0);
        }

        jboolean AbstractFunction1::apply$mcZD$sp(jdouble a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_apply$mcZD$sp_5d1c7649], a0);
        }

        jboolean AbstractFunction1::apply$mcZF$sp(jfloat a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_apply$mcZF$sp_06298ca7], a0);
        }

        jboolean AbstractFunction1::apply$mcZI$sp(jint a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_apply$mcZI$sp_39c7bd30], a0);
        }

        jboolean AbstractFunction1::apply$mcZJ$sp(jlong a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_apply$mcZJ$sp_0ee6df23], a0);
        }

        ::scala::Function1 AbstractFunction1::compose(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcDD$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcDD$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcDF$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcDF$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcDI$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcDI$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcDJ$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcDJ$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcFD$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcFD$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcFF$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcFF$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcFI$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcFI$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcFJ$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcFJ$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcID$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcID$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcIF$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcIF$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcII$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcII$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcIJ$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcIJ$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcJD$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcJD$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcJF$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcJF$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcJI$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcJI$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcJJ$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcJJ$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcZD$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcZD$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcZF$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcZF$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcZI$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcZI$sp_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1::compose$mcZJ$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcZJ$sp_279d294f], a0.this$));
        }

        ::java::lang::String AbstractFunction1::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace scala {
    namespace runtime {
        static PyObject *t_AbstractFunction1_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_AbstractFunction1_instance_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_AbstractFunction1_of_(t_AbstractFunction1 *self, PyObject *args);
        static int t_AbstractFunction1_init_(t_AbstractFunction1 *self, PyObject *args, PyObject *kwds);
        static PyObject *t_AbstractFunction1_andThen(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcDD$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcDF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcDI$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcDJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcFD$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcFF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcFI$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcFJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcID$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcIF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcII$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcIJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcJD$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcJF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcJI$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcJJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcZD$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcZF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcZI$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_andThen$mcZJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcDD$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcDF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcDI$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcDJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcFD$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcFF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcFI$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcFJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcID$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcIF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcII$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcIJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcJD$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcJF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcJI$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcJJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcVD$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcVF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcVI$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcVJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcZD$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcZF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcZI$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_apply$mcZJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcDD$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcDF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcDI$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcDJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcFD$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcFF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcFI$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcFJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcID$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcIF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcII$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcIJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcJD$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcJF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcJI$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcJJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcZD$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcZF$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcZI$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_compose$mcZJ$sp(t_AbstractFunction1 *self, PyObject *arg);
        static PyObject *t_AbstractFunction1_toString(t_AbstractFunction1 *self, PyObject *args);
        static PyObject *t_AbstractFunction1_get__parameters_(t_AbstractFunction1 *self, void *data);
        static PyGetSetDef t_AbstractFunction1__fields_[] = {
            DECLARE_GET_FIELD(t_AbstractFunction1, parameters_),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_AbstractFunction1__methods_[] = {
            DECLARE_METHOD(t_AbstractFunction1, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_AbstractFunction1, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_AbstractFunction1, of_, METH_VARARGS),
            DECLARE_METHOD(t_AbstractFunction1, andThen, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcDD$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcDF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcDI$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcDJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcFD$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcFF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcFI$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcFJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcID$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcIF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcII$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcIJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcJD$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcJF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcJI$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcJJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcZD$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcZF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcZI$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, andThen$mcZJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcDD$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcDF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcDI$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcDJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcFD$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcFF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcFI$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcFJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcID$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcIF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcII$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcIJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcJD$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcJF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcJI$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcJJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcVD$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcVF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcVI$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcVJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcZD$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcZF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcZI$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, apply$mcZJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcDD$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcDF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcDI$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcDJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcFD$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcFF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcFI$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcFJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcID$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcIF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcII$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcIJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcJD$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcJF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcJI$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcJJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcZD$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcZF$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcZI$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, compose$mcZJ$sp, METH_O),
            DECLARE_METHOD(t_AbstractFunction1, toString, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(AbstractFunction1, t_AbstractFunction1, ::java::lang::Object, AbstractFunction1, t_AbstractFunction1_init_, 0, 0, t_AbstractFunction1__fields_, 0, 0);
        PyObject *t_AbstractFunction1::wrap_Object(const AbstractFunction1& object, PyTypeObject *T1, PyTypeObject *R)
        {
            PyObject *obj = t_AbstractFunction1::wrap_Object(object);
            if (obj != NULL && obj != Py_None)
            {
                t_AbstractFunction1 *self = (t_AbstractFunction1 *) obj;
                self->parameters[0] = T1;
                self->parameters[1] = R;
            }
            return obj;
        }

        PyObject *t_AbstractFunction1::wrap_jobject(const jobject& object, PyTypeObject *T1, PyTypeObject *R)
        {
            PyObject *obj = t_AbstractFunction1::wrap_jobject(object);
            if (obj != NULL && obj != Py_None)
            {
                t_AbstractFunction1 *self = (t_AbstractFunction1 *) obj;
                self->parameters[0] = T1;
                self->parameters[1] = R;
            }
            return obj;
        }

        void t_AbstractFunction1::install(PyObject *module)
        {
            installType(&PY_TYPE(AbstractFunction1), module, "AbstractFunction1", 0);
        }

        void t_AbstractFunction1::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(AbstractFunction1).tp_dict, "class_", make_descriptor(AbstractFunction1::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(AbstractFunction1).tp_dict, "wrapfn_", make_descriptor(t_AbstractFunction1::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(AbstractFunction1).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_AbstractFunction1_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, AbstractFunction1::initializeClass, 1)))
                return NULL;
            return t_AbstractFunction1::wrap_Object(AbstractFunction1(((t_AbstractFunction1 *) arg)->object.this$));
        }
        static PyObject *t_AbstractFunction1_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, AbstractFunction1::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static PyObject *t_AbstractFunction1_of_(t_AbstractFunction1 *self, PyObject *args)
        {
            if (!parseArg(args, "T", 2, &(self->parameters)))
                Py_RETURN_SELF;
            return PyErr_SetArgsError((PyObject *) self, "of_", args);
        }

        static int t_AbstractFunction1_init_(t_AbstractFunction1 *self, PyObject *args, PyObject *kwds)
        {
            AbstractFunction1 object((jobject) NULL);

            INT_CALL(object = AbstractFunction1());
            self->object = object;

            return 0;
        }

        static PyObject *t_AbstractFunction1_andThen(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcDD$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcDD$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcDD$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcDF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcDF$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcDF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcDI$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcDI$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcDI$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcDJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcDJ$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcDJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcFD$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcFD$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcFD$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcFF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcFF$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcFF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcFI$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcFI$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcFI$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcFJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcFJ$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcFJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcID$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcID$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcID$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcIF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcIF$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcIF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcII$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcII$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcII$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcIJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcIJ$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcIJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcJD$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcJD$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcJD$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcJF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcJF$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcJF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcJI$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcJI$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcJI$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcJJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcJJ$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcJJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcZD$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcZD$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcZD$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcZF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcZF$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcZF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcZI$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcZI$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcZI$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_andThen$mcZJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcZJ$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "andThen$mcZJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcDD$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jdouble a0;
            jdouble result;

            if (!parseArg(arg, "D", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcDD$sp(a0));
                return PyFloat_FromDouble((double) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcDD$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcDF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jfloat a0;
            jdouble result;

            if (!parseArg(arg, "F", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcDF$sp(a0));
                return PyFloat_FromDouble((double) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcDF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcDI$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jint a0;
            jdouble result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcDI$sp(a0));
                return PyFloat_FromDouble((double) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcDI$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcDJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jlong a0;
            jdouble result;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcDJ$sp(a0));
                return PyFloat_FromDouble((double) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcDJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcFD$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jdouble a0;
            jfloat result;

            if (!parseArg(arg, "D", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcFD$sp(a0));
                return PyFloat_FromDouble((double) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcFD$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcFF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jfloat a0;
            jfloat result;

            if (!parseArg(arg, "F", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcFF$sp(a0));
                return PyFloat_FromDouble((double) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcFF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcFI$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jint a0;
            jfloat result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcFI$sp(a0));
                return PyFloat_FromDouble((double) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcFI$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcFJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jlong a0;
            jfloat result;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcFJ$sp(a0));
                return PyFloat_FromDouble((double) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcFJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcID$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jdouble a0;
            jint result;

            if (!parseArg(arg, "D", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcID$sp(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcID$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcIF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jfloat a0;
            jint result;

            if (!parseArg(arg, "F", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcIF$sp(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcIF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcII$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jint a0;
            jint result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcII$sp(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcII$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcIJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jlong a0;
            jint result;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcIJ$sp(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcIJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcJD$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jdouble a0;
            jlong result;

            if (!parseArg(arg, "D", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcJD$sp(a0));
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcJD$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcJF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jfloat a0;
            jlong result;

            if (!parseArg(arg, "F", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcJF$sp(a0));
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcJF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcJI$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jint a0;
            jlong result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcJI$sp(a0));
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcJI$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcJJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jlong a0;
            jlong result;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcJJ$sp(a0));
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcJJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcVD$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jdouble a0;

            if (!parseArg(arg, "D", &a0))
            {
                OBJ_CALL(self->object.apply$mcVD$sp(a0));
                Py_RETURN_NONE;
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcVD$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcVF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jfloat a0;

            if (!parseArg(arg, "F", &a0))
            {
                OBJ_CALL(self->object.apply$mcVF$sp(a0));
                Py_RETURN_NONE;
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcVF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcVI$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jint a0;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(self->object.apply$mcVI$sp(a0));
                Py_RETURN_NONE;
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcVI$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcVJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jlong a0;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(self->object.apply$mcVJ$sp(a0));
                Py_RETURN_NONE;
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcVJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcZD$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jdouble a0;
            jboolean result;

            if (!parseArg(arg, "D", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcZD$sp(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcZD$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcZF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jfloat a0;
            jboolean result;

            if (!parseArg(arg, "F", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcZF$sp(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcZF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcZI$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jint a0;
            jboolean result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcZI$sp(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcZI$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_apply$mcZJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            jlong a0;
            jboolean result;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = self->object.apply$mcZJ$sp(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError((PyObject *) self, "apply$mcZJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcDD$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcDD$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcDD$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcDF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcDF$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcDF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcDI$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcDI$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcDI$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcDJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcDJ$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcDJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcFD$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcFD$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcFD$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcFF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcFF$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcFF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcFI$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcFI$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcFI$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcFJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcFJ$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcFJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcID$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcID$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcID$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcIF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcIF$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcIF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcII$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcII$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcII$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcIJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcIJ$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcIJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcJD$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcJD$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcJD$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcJF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcJF$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcJF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcJI$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcJI$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcJI$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcJJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcJJ$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcJJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcZD$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcZD$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcZD$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcZF$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcZF$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcZF$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcZI$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcZI$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcZI$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_compose$mcZJ$sp(t_AbstractFunction1 *self, PyObject *arg)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcZJ$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "compose$mcZJ$sp", arg);
            return NULL;
        }

        static PyObject *t_AbstractFunction1_toString(t_AbstractFunction1 *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(AbstractFunction1), (PyObject *) self, "toString", args, 2);
        }
        static PyObject *t_AbstractFunction1_get__parameters_(t_AbstractFunction1 *self, void *data)
        {
            return typeParameters(self->parameters, sizeof(self->parameters));
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/io/StringWriter.h"
#include "java/lang/String.h"
#include "java/lang/CharSequence.h"
#include "java/lang/Appendable.h"
#include "java/lang/StringBuffer.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace io {

        ::java::lang::Class *StringWriter::class$ = NULL;
        jmethodID *StringWriter::mids$ = NULL;

        jclass StringWriter::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/io/StringWriter");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_init$_39c7bd3c] = env->getMethodID(cls, "<init>", "(I)V");
                mids$[mid_append_3aee6342] = env->getMethodID(cls, "append", "(C)Ljava/io/StringWriter;");
                mids$[mid_append_e2d4acee] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;)Ljava/io/StringWriter;");
                mids$[mid_append_199526fa] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;II)Ljava/io/StringWriter;");
                mids$[mid_close_54c6a166] = env->getMethodID(cls, "close", "()V");
                mids$[mid_flush_54c6a166] = env->getMethodID(cls, "flush", "()V");
                mids$[mid_getBuffer_d54172a5] = env->getMethodID(cls, "getBuffer", "()Ljava/lang/StringBuffer;");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
                mids$[mid_write_5fdc3f48] = env->getMethodID(cls, "write", "(Ljava/lang/String;)V");
                mids$[mid_write_39c7bd3c] = env->getMethodID(cls, "write", "(I)V");
                mids$[mid_write_555f322c] = env->getMethodID(cls, "write", "(Ljava/lang/String;II)V");
                mids$[mid_write_6f0bb356] = env->getMethodID(cls, "write", "([CII)V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        StringWriter::StringWriter() : ::java::io::Writer(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        StringWriter::StringWriter(jint a0) : ::java::io::Writer(env->newObject(initializeClass, &mids$, mid_init$_39c7bd3c, a0)) {}

        StringWriter StringWriter::append(jchar a0) const
        {
            return StringWriter(env->callObjectMethod(this$, mids$[mid_append_3aee6342], a0));
        }

        StringWriter StringWriter::append(const ::java::lang::CharSequence & a0) const
        {
            return StringWriter(env->callObjectMethod(this$, mids$[mid_append_e2d4acee], a0.this$));
        }

        StringWriter StringWriter::append(const ::java::lang::CharSequence & a0, jint a1, jint a2) const
        {
            return StringWriter(env->callObjectMethod(this$, mids$[mid_append_199526fa], a0.this$, a1, a2));
        }

        void StringWriter::close() const
        {
            env->callVoidMethod(this$, mids$[mid_close_54c6a166]);
        }

        void StringWriter::flush() const
        {
            env->callVoidMethod(this$, mids$[mid_flush_54c6a166]);
        }

        ::java::lang::StringBuffer StringWriter::getBuffer() const
        {
            return ::java::lang::StringBuffer(env->callObjectMethod(this$, mids$[mid_getBuffer_d54172a5]));
        }

        ::java::lang::String StringWriter::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }

        void StringWriter::write(const ::java::lang::String & a0) const
        {
            env->callVoidMethod(this$, mids$[mid_write_5fdc3f48], a0.this$);
        }

        void StringWriter::write(jint a0) const
        {
            env->callVoidMethod(this$, mids$[mid_write_39c7bd3c], a0);
        }

        void StringWriter::write(const ::java::lang::String & a0, jint a1, jint a2) const
        {
            env->callVoidMethod(this$, mids$[mid_write_555f322c], a0.this$, a1, a2);
        }

        void StringWriter::write(const JArray< jchar > & a0, jint a1, jint a2) const
        {
            env->callVoidMethod(this$, mids$[mid_write_6f0bb356], a0.this$, a1, a2);
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace io {
        static PyObject *t_StringWriter_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_StringWriter_instance_(PyTypeObject *type, PyObject *arg);
        static int t_StringWriter_init_(t_StringWriter *self, PyObject *args, PyObject *kwds);
        static PyObject *t_StringWriter_append(t_StringWriter *self, PyObject *args);
        static PyObject *t_StringWriter_close(t_StringWriter *self, PyObject *args);
        static PyObject *t_StringWriter_flush(t_StringWriter *self, PyObject *args);
        static PyObject *t_StringWriter_getBuffer(t_StringWriter *self);
        static PyObject *t_StringWriter_toString(t_StringWriter *self, PyObject *args);
        static PyObject *t_StringWriter_write(t_StringWriter *self, PyObject *args);
        static PyObject *t_StringWriter_get__buffer(t_StringWriter *self, void *data);
        static PyGetSetDef t_StringWriter__fields_[] = {
            DECLARE_GET_FIELD(t_StringWriter, buffer),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_StringWriter__methods_[] = {
            DECLARE_METHOD(t_StringWriter, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_StringWriter, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_StringWriter, append, METH_VARARGS),
            DECLARE_METHOD(t_StringWriter, close, METH_VARARGS),
            DECLARE_METHOD(t_StringWriter, flush, METH_VARARGS),
            DECLARE_METHOD(t_StringWriter, getBuffer, METH_NOARGS),
            DECLARE_METHOD(t_StringWriter, toString, METH_VARARGS),
            DECLARE_METHOD(t_StringWriter, write, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(StringWriter, t_StringWriter, ::java::io::Writer, StringWriter, t_StringWriter_init_, 0, 0, t_StringWriter__fields_, 0, 0);

        void t_StringWriter::install(PyObject *module)
        {
            installType(&PY_TYPE(StringWriter), module, "StringWriter", 0);
        }

        void t_StringWriter::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(StringWriter).tp_dict, "class_", make_descriptor(StringWriter::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(StringWriter).tp_dict, "wrapfn_", make_descriptor(t_StringWriter::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(StringWriter).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_StringWriter_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, StringWriter::initializeClass, 1)))
                return NULL;
            return t_StringWriter::wrap_Object(StringWriter(((t_StringWriter *) arg)->object.this$));
        }
        static PyObject *t_StringWriter_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, StringWriter::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_StringWriter_init_(t_StringWriter *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    StringWriter object((jobject) NULL);

                    INT_CALL(object = StringWriter());
                    self->object = object;
                    break;
                }
                goto err;
              case 1:
                {
                    jint a0;
                    StringWriter object((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        INT_CALL(object = StringWriter(a0));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_StringWriter_append(t_StringWriter *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jchar a0;
                    StringWriter result((jobject) NULL);

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringWriter::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    StringWriter result((jobject) NULL);

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringWriter::wrap_Object(result);
                    }
                }
                break;
              case 3:
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    StringWriter result((jobject) NULL);

                    if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = self->object.append(a0, a1, a2));
                        return t_StringWriter::wrap_Object(result);
                    }
                }
            }

            return callSuper(&PY_TYPE(StringWriter), (PyObject *) self, "append", args, 2);
        }

        static PyObject *t_StringWriter_close(t_StringWriter *self, PyObject *args)
        {

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(self->object.close());
                Py_RETURN_NONE;
            }

            return callSuper(&PY_TYPE(StringWriter), (PyObject *) self, "close", args, 2);
        }

        static PyObject *t_StringWriter_flush(t_StringWriter *self, PyObject *args)
        {

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(self->object.flush());
                Py_RETURN_NONE;
            }

            return callSuper(&PY_TYPE(StringWriter), (PyObject *) self, "flush", args, 2);
        }

        static PyObject *t_StringWriter_getBuffer(t_StringWriter *self)
        {
            ::java::lang::StringBuffer result((jobject) NULL);
            OBJ_CALL(result = self->object.getBuffer());
            return ::java::lang::t_StringBuffer::wrap_Object(result);
        }

        static PyObject *t_StringWriter_toString(t_StringWriter *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(StringWriter), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_StringWriter_write(t_StringWriter *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(self->object.write(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    jint a0;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(self->object.write(a0));
                        Py_RETURN_NONE;
                    }
                }
                break;
              case 3:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    jint a2;

                    if (!parseArgs(args, "sII", &a0, &a1, &a2))
                    {
                        OBJ_CALL(self->object.write(a0, a1, a2));
                        Py_RETURN_NONE;
                    }
                }
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint a2;

                    if (!parseArgs(args, "[CII", &a0, &a1, &a2))
                    {
                        OBJ_CALL(self->object.write(a0, a1, a2));
                        Py_RETURN_NONE;
                    }
                }
            }

            return callSuper(&PY_TYPE(StringWriter), (PyObject *) self, "write", args, 2);
        }

        static PyObject *t_StringWriter_get__buffer(t_StringWriter *self, void *data)
        {
            ::java::lang::StringBuffer value((jobject) NULL);
            OBJ_CALL(value = self->object.getBuffer());
            return ::java::lang::t_StringBuffer::wrap_Object(value);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "scala/runtime/AbstractFunction1$mcID$sp.h"
#include "scala/Function1.h"
#include "scala/Function1$mcID$sp.h"
#include "java/lang/Object.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace scala {
    namespace runtime {

        ::java::lang::Class *AbstractFunction1$mcID$sp::class$ = NULL;
        jmethodID *AbstractFunction1$mcID$sp::mids$ = NULL;

        jclass AbstractFunction1$mcID$sp::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("scala/runtime/AbstractFunction1$mcID$sp");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_andThen_279d294f] = env->getMethodID(cls, "andThen", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_andThen$mcID$sp_279d294f] = env->getMethodID(cls, "andThen$mcID$sp", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_apply_5d1c765a] = env->getMethodID(cls, "apply", "(D)I");
                mids$[mid_apply_a932a95f] = env->getMethodID(cls, "apply", "(Ljava/lang/Object;)Ljava/lang/Object;");
                mids$[mid_compose_279d294f] = env->getMethodID(cls, "compose", "(Lscala/Function1;)Lscala/Function1;");
                mids$[mid_compose$mcID$sp_279d294f] = env->getMethodID(cls, "compose$mcID$sp", "(Lscala/Function1;)Lscala/Function1;");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        AbstractFunction1$mcID$sp::AbstractFunction1$mcID$sp() : ::scala::runtime::AbstractFunction1(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        ::scala::Function1 AbstractFunction1$mcID$sp::andThen(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1$mcID$sp::andThen$mcID$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcID$sp_279d294f], a0.this$));
        }

        jint AbstractFunction1$mcID$sp::apply(jdouble a0) const
        {
            return env->callIntMethod(this$, mids$[mid_apply_5d1c765a], a0);
        }

        ::java::lang::Object AbstractFunction1$mcID$sp::apply(const ::java::lang::Object & a0) const
        {
            return ::java::lang::Object(env->callObjectMethod(this$, mids$[mid_apply_a932a95f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1$mcID$sp::compose(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose_279d294f], a0.this$));
        }

        ::scala::Function1 AbstractFunction1$mcID$sp::compose$mcID$sp(const ::scala::Function1 & a0) const
        {
            return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcID$sp_279d294f], a0.this$));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace scala {
    namespace runtime {
        static PyObject *t_AbstractFunction1$mcID$sp_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_AbstractFunction1$mcID$sp_instance_(PyTypeObject *type, PyObject *arg);
        static int t_AbstractFunction1$mcID$sp_init_(t_AbstractFunction1$mcID$sp *self, PyObject *args, PyObject *kwds);
        static PyObject *t_AbstractFunction1$mcID$sp_andThen(t_AbstractFunction1$mcID$sp *self, PyObject *args);
        static PyObject *t_AbstractFunction1$mcID$sp_andThen$mcID$sp(t_AbstractFunction1$mcID$sp *self, PyObject *args);
        static PyObject *t_AbstractFunction1$mcID$sp_apply(t_AbstractFunction1$mcID$sp *self, PyObject *args);
        static PyObject *t_AbstractFunction1$mcID$sp_compose(t_AbstractFunction1$mcID$sp *self, PyObject *args);
        static PyObject *t_AbstractFunction1$mcID$sp_compose$mcID$sp(t_AbstractFunction1$mcID$sp *self, PyObject *args);

        static PyMethodDef t_AbstractFunction1$mcID$sp__methods_[] = {
            DECLARE_METHOD(t_AbstractFunction1$mcID$sp, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_AbstractFunction1$mcID$sp, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_AbstractFunction1$mcID$sp, andThen, METH_VARARGS),
            DECLARE_METHOD(t_AbstractFunction1$mcID$sp, andThen$mcID$sp, METH_VARARGS),
            DECLARE_METHOD(t_AbstractFunction1$mcID$sp, apply, METH_VARARGS),
            DECLARE_METHOD(t_AbstractFunction1$mcID$sp, compose, METH_VARARGS),
            DECLARE_METHOD(t_AbstractFunction1$mcID$sp, compose$mcID$sp, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(AbstractFunction1$mcID$sp, t_AbstractFunction1$mcID$sp, ::scala::runtime::AbstractFunction1, AbstractFunction1$mcID$sp, t_AbstractFunction1$mcID$sp_init_, 0, 0, 0, 0, 0);

        void t_AbstractFunction1$mcID$sp::install(PyObject *module)
        {
            installType(&PY_TYPE(AbstractFunction1$mcID$sp), module, "AbstractFunction1$mcID$sp", 0);
        }

        void t_AbstractFunction1$mcID$sp::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(AbstractFunction1$mcID$sp).tp_dict, "class_", make_descriptor(AbstractFunction1$mcID$sp::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(AbstractFunction1$mcID$sp).tp_dict, "wrapfn_", make_descriptor(t_AbstractFunction1$mcID$sp::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(AbstractFunction1$mcID$sp).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_AbstractFunction1$mcID$sp_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, AbstractFunction1$mcID$sp::initializeClass, 1)))
                return NULL;
            return t_AbstractFunction1$mcID$sp::wrap_Object(AbstractFunction1$mcID$sp(((t_AbstractFunction1$mcID$sp *) arg)->object.this$));
        }
        static PyObject *t_AbstractFunction1$mcID$sp_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, AbstractFunction1$mcID$sp::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_AbstractFunction1$mcID$sp_init_(t_AbstractFunction1$mcID$sp *self, PyObject *args, PyObject *kwds)
        {
            AbstractFunction1$mcID$sp object((jobject) NULL);

            INT_CALL(object = AbstractFunction1$mcID$sp());
            self->object = object;

            return 0;
        }

        static PyObject *t_AbstractFunction1$mcID$sp_andThen(t_AbstractFunction1$mcID$sp *self, PyObject *args)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArgs(args, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(AbstractFunction1$mcID$sp), (PyObject *) self, "andThen", args, 2);
        }

        static PyObject *t_AbstractFunction1$mcID$sp_andThen$mcID$sp(t_AbstractFunction1$mcID$sp *self, PyObject *args)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArgs(args, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.andThen$mcID$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(AbstractFunction1$mcID$sp), (PyObject *) self, "andThen$mcID$sp", args, 2);
        }

        static PyObject *t_AbstractFunction1$mcID$sp_apply(t_AbstractFunction1$mcID$sp *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jdouble a0;
                    jint result;

                    if (!parseArgs(args, "D", &a0))
                    {
                        OBJ_CALL(result = self->object.apply(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    ::java::lang::Object a0((jobject) NULL);
                    ::java::lang::Object result((jobject) NULL);

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(result = self->object.apply(a0));
                        return ::java::lang::t_Object::wrap_Object(result);
                    }
                }
            }

            return callSuper(&PY_TYPE(AbstractFunction1$mcID$sp), (PyObject *) self, "apply", args, 2);
        }

        static PyObject *t_AbstractFunction1$mcID$sp_compose(t_AbstractFunction1$mcID$sp *self, PyObject *args)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArgs(args, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(AbstractFunction1$mcID$sp), (PyObject *) self, "compose", args, 2);
        }

        static PyObject *t_AbstractFunction1$mcID$sp_compose$mcID$sp(t_AbstractFunction1$mcID$sp *self, PyObject *args)
        {
            ::scala::Function1 a0((jobject) NULL);
            PyTypeObject **p0;
            ::scala::Function1 result((jobject) NULL);

            if (!parseArgs(args, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
            {
                OBJ_CALL(result = self->object.compose$mcID$sp(a0));
                return ::scala::t_Function1::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(AbstractFunction1$mcID$sp), (PyObject *) self, "compose$mcID$sp", args, 2);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/util/Enumeration.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace util {

        ::java::lang::Class *Enumeration::class$ = NULL;
        jmethodID *Enumeration::mids$ = NULL;

        jclass Enumeration::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/util/Enumeration");

                mids$ = new jmethodID[max_mid];
                mids$[mid_hasMoreElements_54c6a16a] = env->getMethodID(cls, "hasMoreElements", "()Z");
                mids$[mid_nextElement_846352c3] = env->getMethodID(cls, "nextElement", "()Ljava/lang/Object;");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        jboolean Enumeration::hasMoreElements() const
        {
            return env->callBooleanMethod(this$, mids$[mid_hasMoreElements_54c6a16a]);
        }

        ::java::lang::Object Enumeration::nextElement() const
        {
            return ::java::lang::Object(env->callObjectMethod(this$, mids$[mid_nextElement_846352c3]));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace util {
        static PyObject *t_Enumeration_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Enumeration_instance_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Enumeration_of_(t_Enumeration *self, PyObject *args);
        static PyObject *t_Enumeration_hasMoreElements(t_Enumeration *self);
        static PyObject *t_Enumeration_nextElement(t_Enumeration *self);
        static PyObject *t_Enumeration_get__parameters_(t_Enumeration *self, void *data);
        static PyGetSetDef t_Enumeration__fields_[] = {
            DECLARE_GET_FIELD(t_Enumeration, parameters_),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_Enumeration__methods_[] = {
            DECLARE_METHOD(t_Enumeration, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Enumeration, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Enumeration, of_, METH_VARARGS),
            DECLARE_METHOD(t_Enumeration, hasMoreElements, METH_NOARGS),
            DECLARE_METHOD(t_Enumeration, nextElement, METH_NOARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Enumeration, t_Enumeration, ::java::lang::Object, Enumeration, abstract_init, PyObject_SelfIter, ((PyObject *(*)(::java::util::t_Enumeration *)) get_generic_enumeration_next< ::java::util::t_Enumeration,::java::lang::t_Object >), t_Enumeration__fields_, 0, 0);
        PyObject *t_Enumeration::wrap_Object(const Enumeration& object, PyTypeObject *E)
        {
            PyObject *obj = t_Enumeration::wrap_Object(object);
            if (obj != NULL && obj != Py_None)
            {
                t_Enumeration *self = (t_Enumeration *) obj;
                self->parameters[0] = E;
            }
            return obj;
        }

        PyObject *t_Enumeration::wrap_jobject(const jobject& object, PyTypeObject *E)
        {
            PyObject *obj = t_Enumeration::wrap_jobject(object);
            if (obj != NULL && obj != Py_None)
            {
                t_Enumeration *self = (t_Enumeration *) obj;
                self->parameters[0] = E;
            }
            return obj;
        }

        void t_Enumeration::install(PyObject *module)
        {
            installType(&PY_TYPE(Enumeration), module, "Enumeration", 0);
        }

        void t_Enumeration::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Enumeration).tp_dict, "class_", make_descriptor(Enumeration::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Enumeration).tp_dict, "wrapfn_", make_descriptor(t_Enumeration::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(Enumeration).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_Enumeration_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Enumeration::initializeClass, 1)))
                return NULL;
            return t_Enumeration::wrap_Object(Enumeration(((t_Enumeration *) arg)->object.this$));
        }
        static PyObject *t_Enumeration_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Enumeration::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static PyObject *t_Enumeration_of_(t_Enumeration *self, PyObject *args)
        {
            if (!parseArg(args, "T", 1, &(self->parameters)))
                Py_RETURN_SELF;
            return PyErr_SetArgsError((PyObject *) self, "of_", args);
        }

        static PyObject *t_Enumeration_hasMoreElements(t_Enumeration *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.hasMoreElements());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Enumeration_nextElement(t_Enumeration *self)
        {
            ::java::lang::Object result((jobject) NULL);
            OBJ_CALL(result = self->object.nextElement());
            return self->parameters[0] != NULL ? wrapType(self->parameters[0], result.this$) : ::java::lang::t_Object::wrap_Object(result);
        }
        static PyObject *t_Enumeration_get__parameters_(t_Enumeration *self, void *data)
        {
            return typeParameters(self->parameters, sizeof(self->parameters));
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Boolean.h"
#include "java/lang/String.h"
#include "java/lang/Comparable.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Boolean::class$ = NULL;
        jmethodID *Boolean::mids$ = NULL;
        Boolean *Boolean::FALSE = NULL;
        Boolean *Boolean::TRUE = NULL;
        ::java::lang::Class *Boolean::TYPE = NULL;

        jclass Boolean::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Boolean");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_bb0c767f] = env->getMethodID(cls, "<init>", "(Z)V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_booleanValue_54c6a16a] = env->getMethodID(cls, "booleanValue", "()Z");
                mids$[mid_compareTo_d07f0c91] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Boolean;)I");
                mids$[mid_compareTo_290588f1] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Object;)I");
                mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
                mids$[mid_getBoolean_5fdc3f44] = env->getStaticMethodID(cls, "getBoolean", "(Ljava/lang/String;)Z");
                mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
                mids$[mid_parseBoolean_5fdc3f44] = env->getStaticMethodID(cls, "parseBoolean", "(Ljava/lang/String;)Z");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
                mids$[mid_toString_445a175e] = env->getStaticMethodID(cls, "toString", "(Z)Ljava/lang/String;");
                mids$[mid_valueOf_a98d5bba] = env->getStaticMethodID(cls, "valueOf", "(Z)Ljava/lang/Boolean;");
                mids$[mid_valueOf_9d4a8ff9] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Ljava/lang/Boolean;");

                class$ = (::java::lang::Class *) new JObject(cls);
                cls = (jclass) class$->this$;

                FALSE = new Boolean(env->getStaticObjectField(cls, "FALSE", "Ljava/lang/Boolean;"));
                TRUE = new Boolean(env->getStaticObjectField(cls, "TRUE", "Ljava/lang/Boolean;"));
                TYPE = new ::java::lang::Class(env->getStaticObjectField(cls, "TYPE", "Ljava/lang/Class;"));
            }
            return (jclass) class$->this$;
        }

        Boolean::Boolean(jboolean a0) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_bb0c767f, a0)) {}

        Boolean::Boolean(const ::java::lang::String & a0) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        jboolean Boolean::booleanValue() const
        {
            return env->callBooleanMethod(this$, mids$[mid_booleanValue_54c6a16a]);
        }

        jint Boolean::compareTo(const Boolean & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_d07f0c91], a0.this$);
        }

        jint Boolean::compareTo(const ::java::lang::Object & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_290588f1], a0.this$);
        }

        jboolean Boolean::equals(const ::java::lang::Object & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
        }

        jboolean Boolean::getBoolean(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_getBoolean_5fdc3f44], a0.this$);
        }

        jint Boolean::hashCode() const
        {
            return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
        }

        jboolean Boolean::parseBoolean(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_parseBoolean_5fdc3f44], a0.this$);
        }

        ::java::lang::String Boolean::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }

        ::java::lang::String Boolean::toString(jboolean a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_445a175e], a0));
        }

        Boolean Boolean::valueOf(jboolean a0)
        {
            jclass cls = initializeClass();
            return Boolean(env->callStaticObjectMethod(cls, mids$[mid_valueOf_a98d5bba], a0));
        }

        Boolean Boolean::valueOf(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Boolean(env->callStaticObjectMethod(cls, mids$[mid_valueOf_9d4a8ff9], a0.this$));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Boolean_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Boolean_instance_(PyTypeObject *type, PyObject *arg);
        static int t_Boolean_init_(t_Boolean *self, PyObject *args, PyObject *kwds);
        static PyObject *t_Boolean_booleanValue(t_Boolean *self);
        static PyObject *t_Boolean_compareTo(t_Boolean *self, PyObject *args);
        static PyObject *t_Boolean_equals(t_Boolean *self, PyObject *args);
        static PyObject *t_Boolean_getBoolean(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Boolean_hashCode(t_Boolean *self, PyObject *args);
        static PyObject *t_Boolean_parseBoolean(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Boolean_toString(t_Boolean *self, PyObject *args);
        static PyObject *t_Boolean_toString_(PyTypeObject *type, PyObject *args);
        static PyObject *t_Boolean_valueOf(PyTypeObject *type, PyObject *args);

        static PyMethodDef t_Boolean__methods_[] = {
            DECLARE_METHOD(t_Boolean, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Boolean, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Boolean, booleanValue, METH_NOARGS),
            DECLARE_METHOD(t_Boolean, compareTo, METH_VARARGS),
            DECLARE_METHOD(t_Boolean, equals, METH_VARARGS),
            DECLARE_METHOD(t_Boolean, getBoolean, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Boolean, hashCode, METH_VARARGS),
            DECLARE_METHOD(t_Boolean, parseBoolean, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Boolean, toString, METH_VARARGS),
            DECLARE_METHOD(t_Boolean, toString_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Boolean, valueOf, METH_VARARGS | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Boolean, t_Boolean, ::java::lang::Object, Boolean, t_Boolean_init_, 0, 0, 0, 0, 0);

        void t_Boolean::install(PyObject *module)
        {
            installType(&PY_TYPE(Boolean), module, "Boolean", 0);
        }

        void t_Boolean::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Boolean).tp_dict, "class_", make_descriptor(Boolean::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Boolean).tp_dict, "wrapfn_", make_descriptor(unboxBoolean));
            PyDict_SetItemString(PY_TYPE(Boolean).tp_dict, "boxfn_", make_descriptor(boxBoolean));
            Boolean::initializeClass();
            PyDict_SetItemString(PY_TYPE(Boolean).tp_dict, "FALSE", make_descriptor(t_Boolean::wrap_Object(*Boolean::FALSE)));
            PyDict_SetItemString(PY_TYPE(Boolean).tp_dict, "TRUE", make_descriptor(t_Boolean::wrap_Object(*Boolean::TRUE)));
            PyDict_SetItemString(PY_TYPE(Boolean).tp_dict, "TYPE", make_descriptor(::java::lang::t_Class::wrap_Object(*Boolean::TYPE)));
        }

        static PyObject *t_Boolean_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Boolean::initializeClass, 1)))
                return NULL;
            return t_Boolean::wrap_Object(Boolean(((t_Boolean *) arg)->object.this$));
        }
        static PyObject *t_Boolean_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Boolean::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_Boolean_init_(t_Boolean *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jboolean a0;
                    Boolean object((jobject) NULL);

                    if (!parseArgs(args, "Z", &a0))
                    {
                        INT_CALL(object = Boolean(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Boolean object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = Boolean(a0));
                        self->object = object;
                        break;
                    }
                }
              default:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_Boolean_booleanValue(t_Boolean *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.booleanValue());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Boolean_compareTo(t_Boolean *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    Boolean a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(Boolean), &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    ::java::lang::Object a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "compareTo", args);
            return NULL;
        }

        static PyObject *t_Boolean_equals(t_Boolean *self, PyObject *args)
        {
            ::java::lang::Object a0((jobject) NULL);
            jboolean result;

            if (!parseArgs(args, "o", &a0))
            {
                OBJ_CALL(result = self->object.equals(a0));
                Py_RETURN_BOOL(result);
            }

            return callSuper(&PY_TYPE(Boolean), (PyObject *) self, "equals", args, 2);
        }

        static PyObject *t_Boolean_getBoolean(PyTypeObject *type, PyObject *arg)
        {
            ::java::lang::String a0((jobject) NULL);
            jboolean result;

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = ::java::lang::Boolean::getBoolean(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError(type, "getBoolean", arg);
            return NULL;
        }

        static PyObject *t_Boolean_hashCode(t_Boolean *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.hashCode());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Boolean), (PyObject *) self, "hashCode", args, 2);
        }

        static PyObject *t_Boolean_parseBoolean(PyTypeObject *type, PyObject *arg)
        {
            ::java::lang::String a0((jobject) NULL);
            jboolean result;

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = ::java::lang::Boolean::parseBoolean(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError(type, "parseBoolean", arg);
            return NULL;
        }

        static PyObject *t_Boolean_toString(t_Boolean *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(Boolean), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_Boolean_toString_(PyTypeObject *type, PyObject *args)
        {
            jboolean a0;
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, "Z", &a0))
            {
                OBJ_CALL(result = ::java::lang::Boolean::toString(a0));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "toString_", args);
            return NULL;
        }

        static PyObject *t_Boolean_valueOf(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jboolean a0;
                    Boolean result((jobject) NULL);

                    if (!parseArgs(args, "Z", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Boolean::valueOf(a0));
                        return t_Boolean::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Boolean result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Boolean::valueOf(a0));
                        return t_Boolean::wrap_Object(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "valueOf", args);
            return NULL;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Character.h"
#include "java/lang/String.h"
#include "java/lang/CharSequence.h"
#include "java/lang/Class.h"
#include "java/lang/Comparable.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Character::class$ = NULL;
        jmethodID *Character::mids$ = NULL;
        jbyte Character::COMBINING_SPACING_MARK = (jbyte) 0;
        jbyte Character::CONNECTOR_PUNCTUATION = (jbyte) 0;
        jbyte Character::CONTROL = (jbyte) 0;
        jbyte Character::CURRENCY_SYMBOL = (jbyte) 0;
        jbyte Character::DASH_PUNCTUATION = (jbyte) 0;
        jbyte Character::DECIMAL_DIGIT_NUMBER = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_ARABIC_NUMBER = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_BOUNDARY_NEUTRAL = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_COMMON_NUMBER_SEPARATOR = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_EUROPEAN_NUMBER = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_LEFT_TO_RIGHT = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_NONSPACING_MARK = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_OTHER_NEUTRALS = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_PARAGRAPH_SEPARATOR = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_POP_DIRECTIONAL_FORMAT = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_RIGHT_TO_LEFT = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_SEGMENT_SEPARATOR = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_UNDEFINED = (jbyte) 0;
        jbyte Character::DIRECTIONALITY_WHITESPACE = (jbyte) 0;
        jbyte Character::ENCLOSING_MARK = (jbyte) 0;
        jbyte Character::END_PUNCTUATION = (jbyte) 0;
        jbyte Character::FINAL_QUOTE_PUNCTUATION = (jbyte) 0;
        jbyte Character::FORMAT = (jbyte) 0;
        jbyte Character::INITIAL_QUOTE_PUNCTUATION = (jbyte) 0;
        jbyte Character::LETTER_NUMBER = (jbyte) 0;
        jbyte Character::LINE_SEPARATOR = (jbyte) 0;
        jbyte Character::LOWERCASE_LETTER = (jbyte) 0;
        jbyte Character::MATH_SYMBOL = (jbyte) 0;
        jint Character::MAX_CODE_POINT = (jint) 0;
        jchar Character::MAX_HIGH_SURROGATE = (jchar) 0;
        jchar Character::MAX_LOW_SURROGATE = (jchar) 0;
        jint Character::MAX_RADIX = (jint) 0;
        jchar Character::MAX_SURROGATE = (jchar) 0;
        jchar Character::MAX_VALUE = (jchar) 0;
        jint Character::MIN_CODE_POINT = (jint) 0;
        jchar Character::MIN_HIGH_SURROGATE = (jchar) 0;
        jchar Character::MIN_LOW_SURROGATE = (jchar) 0;
        jint Character::MIN_RADIX = (jint) 0;
        jint Character::MIN_SUPPLEMENTARY_CODE_POINT = (jint) 0;
        jchar Character::MIN_SURROGATE = (jchar) 0;
        jchar Character::MIN_VALUE = (jchar) 0;
        jbyte Character::MODIFIER_LETTER = (jbyte) 0;
        jbyte Character::MODIFIER_SYMBOL = (jbyte) 0;
        jbyte Character::NON_SPACING_MARK = (jbyte) 0;
        jbyte Character::OTHER_LETTER = (jbyte) 0;
        jbyte Character::OTHER_NUMBER = (jbyte) 0;
        jbyte Character::OTHER_PUNCTUATION = (jbyte) 0;
        jbyte Character::OTHER_SYMBOL = (jbyte) 0;
        jbyte Character::PARAGRAPH_SEPARATOR = (jbyte) 0;
        jbyte Character::PRIVATE_USE = (jbyte) 0;
        jint Character::SIZE = (jint) 0;
        jbyte Character::SPACE_SEPARATOR = (jbyte) 0;
        jbyte Character::START_PUNCTUATION = (jbyte) 0;
        jbyte Character::SURROGATE = (jbyte) 0;
        jbyte Character::TITLECASE_LETTER = (jbyte) 0;
        ::java::lang::Class *Character::TYPE = NULL;
        jbyte Character::UNASSIGNED = (jbyte) 0;
        jbyte Character::UPPERCASE_LETTER = (jbyte) 0;

        jclass Character::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Character");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_87fd545a] = env->getMethodID(cls, "<init>", "(C)V");
                mids$[mid_charCount_39c7bd23] = env->getStaticMethodID(cls, "charCount", "(I)I");
                mids$[mid_charValue_54c6a173] = env->getMethodID(cls, "charValue", "()C");
                mids$[mid_codePointAt_ec6430eb] = env->getStaticMethodID(cls, "codePointAt", "([CI)I");
                mids$[mid_codePointAt_2fbf15bf] = env->getStaticMethodID(cls, "codePointAt", "(Ljava/lang/CharSequence;I)I");
                mids$[mid_codePointAt_6f0bb349] = env->getStaticMethodID(cls, "codePointAt", "([CII)I");
                mids$[mid_codePointBefore_2fbf15bf] = env->getStaticMethodID(cls, "codePointBefore", "(Ljava/lang/CharSequence;I)I");
                mids$[mid_codePointBefore_ec6430eb] = env->getStaticMethodID(cls, "codePointBefore", "([CI)I");
                mids$[mid_codePointBefore_6f0bb349] = env->getStaticMethodID(cls, "codePointBefore", "([CII)I");
                mids$[mid_codePointCount_6cc8d7fd] = env->getStaticMethodID(cls, "codePointCount", "(Ljava/lang/CharSequence;II)I");
                mids$[mid_codePointCount_6f0bb349] = env->getStaticMethodID(cls, "codePointCount", "([CII)I");
                mids$[mid_compareTo_290588f1] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Object;)I");
                mids$[mid_compareTo_35927258] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Character;)I");
                mids$[mid_digit_3108448f] = env->getStaticMethodID(cls, "digit", "(CI)I");
                mids$[mid_digit_d8d154b9] = env->getStaticMethodID(cls, "digit", "(II)I");
                mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
                mids$[mid_forDigit_d8d154b3] = env->getStaticMethodID(cls, "forDigit", "(II)C");
                mids$[mid_getDirectionality_87fd544e] = env->getStaticMethodID(cls, "getDirectionality", "(C)B");
                mids$[mid_getDirectionality_39c7bd28] = env->getStaticMethodID(cls, "getDirectionality", "(I)B");
                mids$[mid_getNumericValue_39c7bd23] = env->getStaticMethodID(cls, "getNumericValue", "(I)I");
                mids$[mid_getNumericValue_87fd5445] = env->getStaticMethodID(cls, "getNumericValue", "(C)I");
                mids$[mid_getType_87fd5445] = env->getStaticMethodID(cls, "getType", "(C)I");
                mids$[mid_getType_39c7bd23] = env->getStaticMethodID(cls, "getType", "(I)I");
                mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
                mids$[mid_isDefined_87fd5456] = env->getStaticMethodID(cls, "isDefined", "(C)Z");
                mids$[mid_isDefined_39c7bd30] = env->getStaticMethodID(cls, "isDefined", "(I)Z");
                mids$[mid_isDigit_39c7bd30] = env->getStaticMethodID(cls, "isDigit", "(I)Z");
                mids$[mid_isDigit_87fd5456] = env->getStaticMethodID(cls, "isDigit", "(C)Z");
                mids$[mid_isHighSurrogate_87fd5456] = env->getStaticMethodID(cls, "isHighSurrogate", "(C)Z");
                mids$[mid_isISOControl_39c7bd30] = env->getStaticMethodID(cls, "isISOControl", "(I)Z");
                mids$[mid_isISOControl_87fd5456] = env->getStaticMethodID(cls, "isISOControl", "(C)Z");
                mids$[mid_isIdentifierIgnorable_39c7bd30] = env->getStaticMethodID(cls, "isIdentifierIgnorable", "(I)Z");
                mids$[mid_isIdentifierIgnorable_87fd5456] = env->getStaticMethodID(cls, "isIdentifierIgnorable", "(C)Z");
                mids$[mid_isJavaIdentifierPart_39c7bd30] = env->getStaticMethodID(cls, "isJavaIdentifierPart", "(I)Z");
                mids$[mid_isJavaIdentifierPart_87fd5456] = env->getStaticMethodID(cls, "isJavaIdentifierPart", "(C)Z");
                mids$[mid_isJavaIdentifierStart_87fd5456] = env->getStaticMethodID(cls, "isJavaIdentifierStart", "(C)Z");
                mids$[mid_isJavaIdentifierStart_39c7bd30] = env->getStaticMethodID(cls, "isJavaIdentifierStart", "(I)Z");
                mids$[mid_isJavaLetter_87fd5456] = env->getStaticMethodID(cls, "isJavaLetter", "(C)Z");
                mids$[mid_isJavaLetterOrDigit_87fd5456] = env->getStaticMethodID(cls, "isJavaLetterOrDigit", "(C)Z");
                mids$[mid_isLetter_87fd5456] = env->getStaticMethodID(cls, "isLetter", "(C)Z");
                mids$[mid_isLetter_39c7bd30] = env->getStaticMethodID(cls, "isLetter", "(I)Z");
                mids$[mid_isLetterOrDigit_39c7bd30] = env->getStaticMethodID(cls, "isLetterOrDigit", "(I)Z");
                mids$[mid_isLetterOrDigit_87fd5456] = env->getStaticMethodID(cls, "isLetterOrDigit", "(C)Z");
                mids$[mid_isLowSurrogate_87fd5456] = env->getStaticMethodID(cls, "isLowSurrogate", "(C)Z");
                mids$[mid_isLowerCase_39c7bd30] = env->getStaticMethodID(cls, "isLowerCase", "(I)Z");
                mids$[mid_isLowerCase_87fd5456] = env->getStaticMethodID(cls, "isLowerCase", "(C)Z");
                mids$[mid_isMirrored_87fd5456] = env->getStaticMethodID(cls, "isMirrored", "(C)Z");
                mids$[mid_isMirrored_39c7bd30] = env->getStaticMethodID(cls, "isMirrored", "(I)Z");
                mids$[mid_isSpace_87fd5456] = env->getStaticMethodID(cls, "isSpace", "(C)Z");
                mids$[mid_isSpaceChar_87fd5456] = env->getStaticMethodID(cls, "isSpaceChar", "(C)Z");
                mids$[mid_isSpaceChar_39c7bd30] = env->getStaticMethodID(cls, "isSpaceChar", "(I)Z");
                mids$[mid_isSupplementaryCodePoint_39c7bd30] = env->getStaticMethodID(cls, "isSupplementaryCodePoint", "(I)Z");
                mids$[mid_isSurrogatePair_37c94822] = env->getStaticMethodID(cls, "isSurrogatePair", "(CC)Z");
                mids$[mid_isTitleCase_39c7bd30] = env->getStaticMethodID(cls, "isTitleCase", "(I)Z");
                mids$[mid_isTitleCase_87fd5456] = env->getStaticMethodID(cls, "isTitleCase", "(C)Z");
                mids$[mid_isUnicodeIdentifierPart_87fd5456] = env->getStaticMethodID(cls, "isUnicodeIdentifierPart", "(C)Z");
                mids$[mid_isUnicodeIdentifierPart_39c7bd30] = env->getStaticMethodID(cls, "isUnicodeIdentifierPart", "(I)Z");
                mids$[mid_isUnicodeIdentifierStart_39c7bd30] = env->getStaticMethodID(cls, "isUnicodeIdentifierStart", "(I)Z");
                mids$[mid_isUnicodeIdentifierStart_87fd5456] = env->getStaticMethodID(cls, "isUnicodeIdentifierStart", "(C)Z");
                mids$[mid_isUpperCase_39c7bd30] = env->getStaticMethodID(cls, "isUpperCase", "(I)Z");
                mids$[mid_isUpperCase_87fd5456] = env->getStaticMethodID(cls, "isUpperCase", "(C)Z");
                mids$[mid_isValidCodePoint_39c7bd30] = env->getStaticMethodID(cls, "isValidCodePoint", "(I)Z");
                mids$[mid_isWhitespace_39c7bd30] = env->getStaticMethodID(cls, "isWhitespace", "(I)Z");
                mids$[mid_isWhitespace_87fd5456] = env->getStaticMethodID(cls, "isWhitespace", "(C)Z");
                mids$[mid_offsetByCodePoints_6cc8d7fd] = env->getStaticMethodID(cls, "offsetByCodePoints", "(Ljava/lang/CharSequence;II)I");
                mids$[mid_offsetByCodePoints_f453ace9] = env->getStaticMethodID(cls, "offsetByCodePoints", "([CIIII)I");
                mids$[mid_reverseBytes_87fd544f] = env->getStaticMethodID(cls, "reverseBytes", "(C)C");
                mids$[mid_toChars_b4292e99] = env->getStaticMethodID(cls, "toChars", "(I)[C");
                mids$[mid_toChars_273c5d2d] = env->getStaticMethodID(cls, "toChars", "(I[CI)I");
                mids$[mid_toCodePoint_37c94831] = env->getStaticMethodID(cls, "toCodePoint", "(CC)I");
                mids$[mid_toLowerCase_39c7bd23] = env->getStaticMethodID(cls, "toLowerCase", "(I)I");
                mids$[mid_toLowerCase_87fd544f] = env->getStaticMethodID(cls, "toLowerCase", "(C)C");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
                mids$[mid_toString_7611a535] = env->getStaticMethodID(cls, "toString", "(C)Ljava/lang/String;");
                mids$[mid_toTitleCase_87fd544f] = env->getStaticMethodID(cls, "toTitleCase", "(C)C");
                mids$[mid_toTitleCase_39c7bd23] = env->getStaticMethodID(cls, "toTitleCase", "(I)I");
                mids$[mid_toUpperCase_39c7bd23] = env->getStaticMethodID(cls, "toUpperCase", "(I)I");
                mids$[mid_toUpperCase_87fd544f] = env->getStaticMethodID(cls, "toUpperCase", "(C)C");
                mids$[mid_valueOf_58724da6] = env->getStaticMethodID(cls, "valueOf", "(C)Ljava/lang/Character;");

                class$ = (::java::lang::Class *) new JObject(cls);
                cls = (jclass) class$->this$;

                COMBINING_SPACING_MARK = env->getStaticByteField(cls, "COMBINING_SPACING_MARK");
                CONNECTOR_PUNCTUATION = env->getStaticByteField(cls, "CONNECTOR_PUNCTUATION");
                CONTROL = env->getStaticByteField(cls, "CONTROL");
                CURRENCY_SYMBOL = env->getStaticByteField(cls, "CURRENCY_SYMBOL");
                DASH_PUNCTUATION = env->getStaticByteField(cls, "DASH_PUNCTUATION");
                DECIMAL_DIGIT_NUMBER = env->getStaticByteField(cls, "DECIMAL_DIGIT_NUMBER");
                DIRECTIONALITY_ARABIC_NUMBER = env->getStaticByteField(cls, "DIRECTIONALITY_ARABIC_NUMBER");
                DIRECTIONALITY_BOUNDARY_NEUTRAL = env->getStaticByteField(cls, "DIRECTIONALITY_BOUNDARY_NEUTRAL");
                DIRECTIONALITY_COMMON_NUMBER_SEPARATOR = env->getStaticByteField(cls, "DIRECTIONALITY_COMMON_NUMBER_SEPARATOR");
                DIRECTIONALITY_EUROPEAN_NUMBER = env->getStaticByteField(cls, "DIRECTIONALITY_EUROPEAN_NUMBER");
                DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR = env->getStaticByteField(cls, "DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR");
                DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR = env->getStaticByteField(cls, "DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR");
                DIRECTIONALITY_LEFT_TO_RIGHT = env->getStaticByteField(cls, "DIRECTIONALITY_LEFT_TO_RIGHT");
                DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING = env->getStaticByteField(cls, "DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING");
                DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE = env->getStaticByteField(cls, "DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE");
                DIRECTIONALITY_NONSPACING_MARK = env->getStaticByteField(cls, "DIRECTIONALITY_NONSPACING_MARK");
                DIRECTIONALITY_OTHER_NEUTRALS = env->getStaticByteField(cls, "DIRECTIONALITY_OTHER_NEUTRALS");
                DIRECTIONALITY_PARAGRAPH_SEPARATOR = env->getStaticByteField(cls, "DIRECTIONALITY_PARAGRAPH_SEPARATOR");
                DIRECTIONALITY_POP_DIRECTIONAL_FORMAT = env->getStaticByteField(cls, "DIRECTIONALITY_POP_DIRECTIONAL_FORMAT");
                DIRECTIONALITY_RIGHT_TO_LEFT = env->getStaticByteField(cls, "DIRECTIONALITY_RIGHT_TO_LEFT");
                DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC = env->getStaticByteField(cls, "DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC");
                DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING = env->getStaticByteField(cls, "DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING");
                DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE = env->getStaticByteField(cls, "DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE");
                DIRECTIONALITY_SEGMENT_SEPARATOR = env->getStaticByteField(cls, "DIRECTIONALITY_SEGMENT_SEPARATOR");
                DIRECTIONALITY_UNDEFINED = env->getStaticByteField(cls, "DIRECTIONALITY_UNDEFINED");
                DIRECTIONALITY_WHITESPACE = env->getStaticByteField(cls, "DIRECTIONALITY_WHITESPACE");
                ENCLOSING_MARK = env->getStaticByteField(cls, "ENCLOSING_MARK");
                END_PUNCTUATION = env->getStaticByteField(cls, "END_PUNCTUATION");
                FINAL_QUOTE_PUNCTUATION = env->getStaticByteField(cls, "FINAL_QUOTE_PUNCTUATION");
                FORMAT = env->getStaticByteField(cls, "FORMAT");
                INITIAL_QUOTE_PUNCTUATION = env->getStaticByteField(cls, "INITIAL_QUOTE_PUNCTUATION");
                LETTER_NUMBER = env->getStaticByteField(cls, "LETTER_NUMBER");
                LINE_SEPARATOR = env->getStaticByteField(cls, "LINE_SEPARATOR");
                LOWERCASE_LETTER = env->getStaticByteField(cls, "LOWERCASE_LETTER");
                MATH_SYMBOL = env->getStaticByteField(cls, "MATH_SYMBOL");
                MAX_CODE_POINT = env->getStaticIntField(cls, "MAX_CODE_POINT");
                MAX_HIGH_SURROGATE = env->getStaticCharField(cls, "MAX_HIGH_SURROGATE");
                MAX_LOW_SURROGATE = env->getStaticCharField(cls, "MAX_LOW_SURROGATE");
                MAX_RADIX = env->getStaticIntField(cls, "MAX_RADIX");
                MAX_SURROGATE = env->getStaticCharField(cls, "MAX_SURROGATE");
                MAX_VALUE = env->getStaticCharField(cls, "MAX_VALUE");
                MIN_CODE_POINT = env->getStaticIntField(cls, "MIN_CODE_POINT");
                MIN_HIGH_SURROGATE = env->getStaticCharField(cls, "MIN_HIGH_SURROGATE");
                MIN_LOW_SURROGATE = env->getStaticCharField(cls, "MIN_LOW_SURROGATE");
                MIN_RADIX = env->getStaticIntField(cls, "MIN_RADIX");
                MIN_SUPPLEMENTARY_CODE_POINT = env->getStaticIntField(cls, "MIN_SUPPLEMENTARY_CODE_POINT");
                MIN_SURROGATE = env->getStaticCharField(cls, "MIN_SURROGATE");
                MIN_VALUE = env->getStaticCharField(cls, "MIN_VALUE");
                MODIFIER_LETTER = env->getStaticByteField(cls, "MODIFIER_LETTER");
                MODIFIER_SYMBOL = env->getStaticByteField(cls, "MODIFIER_SYMBOL");
                NON_SPACING_MARK = env->getStaticByteField(cls, "NON_SPACING_MARK");
                OTHER_LETTER = env->getStaticByteField(cls, "OTHER_LETTER");
                OTHER_NUMBER = env->getStaticByteField(cls, "OTHER_NUMBER");
                OTHER_PUNCTUATION = env->getStaticByteField(cls, "OTHER_PUNCTUATION");
                OTHER_SYMBOL = env->getStaticByteField(cls, "OTHER_SYMBOL");
                PARAGRAPH_SEPARATOR = env->getStaticByteField(cls, "PARAGRAPH_SEPARATOR");
                PRIVATE_USE = env->getStaticByteField(cls, "PRIVATE_USE");
                SIZE = env->getStaticIntField(cls, "SIZE");
                SPACE_SEPARATOR = env->getStaticByteField(cls, "SPACE_SEPARATOR");
                START_PUNCTUATION = env->getStaticByteField(cls, "START_PUNCTUATION");
                SURROGATE = env->getStaticByteField(cls, "SURROGATE");
                TITLECASE_LETTER = env->getStaticByteField(cls, "TITLECASE_LETTER");
                TYPE = new ::java::lang::Class(env->getStaticObjectField(cls, "TYPE", "Ljava/lang/Class;"));
                UNASSIGNED = env->getStaticByteField(cls, "UNASSIGNED");
                UPPERCASE_LETTER = env->getStaticByteField(cls, "UPPERCASE_LETTER");
            }
            return (jclass) class$->this$;
        }

        Character::Character(jchar a0) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_87fd545a, a0)) {}

        jint Character::charCount(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_charCount_39c7bd23], a0);
        }

        jchar Character::charValue() const
        {
            return env->callCharMethod(this$, mids$[mid_charValue_54c6a173]);
        }

        jint Character::codePointAt(const JArray< jchar > & a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_codePointAt_ec6430eb], a0.this$, a1);
        }

        jint Character::codePointAt(const ::java::lang::CharSequence & a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_codePointAt_2fbf15bf], a0.this$, a1);
        }

        jint Character::codePointAt(const JArray< jchar > & a0, jint a1, jint a2)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_codePointAt_6f0bb349], a0.this$, a1, a2);
        }

        jint Character::codePointBefore(const ::java::lang::CharSequence & a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_codePointBefore_2fbf15bf], a0.this$, a1);
        }

        jint Character::codePointBefore(const JArray< jchar > & a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_codePointBefore_ec6430eb], a0.this$, a1);
        }

        jint Character::codePointBefore(const JArray< jchar > & a0, jint a1, jint a2)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_codePointBefore_6f0bb349], a0.this$, a1, a2);
        }

        jint Character::codePointCount(const ::java::lang::CharSequence & a0, jint a1, jint a2)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_codePointCount_6cc8d7fd], a0.this$, a1, a2);
        }

        jint Character::codePointCount(const JArray< jchar > & a0, jint a1, jint a2)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_codePointCount_6f0bb349], a0.this$, a1, a2);
        }

        jint Character::compareTo(const ::java::lang::Object & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_290588f1], a0.this$);
        }

        jint Character::compareTo(const Character & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_35927258], a0.this$);
        }

        jint Character::digit(jchar a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_digit_3108448f], a0, a1);
        }

        jint Character::digit(jint a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_digit_d8d154b9], a0, a1);
        }

        jboolean Character::equals(const ::java::lang::Object & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
        }

        jchar Character::forDigit(jint a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticCharMethod(cls, mids$[mid_forDigit_d8d154b3], a0, a1);
        }

        jbyte Character::getDirectionality(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticByteMethod(cls, mids$[mid_getDirectionality_87fd544e], a0);
        }

        jbyte Character::getDirectionality(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticByteMethod(cls, mids$[mid_getDirectionality_39c7bd28], a0);
        }

        jint Character::getNumericValue(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_getNumericValue_39c7bd23], a0);
        }

        jint Character::getNumericValue(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_getNumericValue_87fd5445], a0);
        }

        jint Character::getType(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_getType_87fd5445], a0);
        }

        jint Character::getType(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_getType_39c7bd23], a0);
        }

        jint Character::hashCode() const
        {
            return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
        }

        jboolean Character::isDefined(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isDefined_87fd5456], a0);
        }

        jboolean Character::isDefined(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isDefined_39c7bd30], a0);
        }

        jboolean Character::isDigit(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isDigit_39c7bd30], a0);
        }

        jboolean Character::isDigit(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isDigit_87fd5456], a0);
        }

        jboolean Character::isHighSurrogate(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isHighSurrogate_87fd5456], a0);
        }

        jboolean Character::isISOControl(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isISOControl_39c7bd30], a0);
        }

        jboolean Character::isISOControl(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isISOControl_87fd5456], a0);
        }

        jboolean Character::isIdentifierIgnorable(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isIdentifierIgnorable_39c7bd30], a0);
        }

        jboolean Character::isIdentifierIgnorable(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isIdentifierIgnorable_87fd5456], a0);
        }

        jboolean Character::isJavaIdentifierPart(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isJavaIdentifierPart_39c7bd30], a0);
        }

        jboolean Character::isJavaIdentifierPart(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isJavaIdentifierPart_87fd5456], a0);
        }

        jboolean Character::isJavaIdentifierStart(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isJavaIdentifierStart_87fd5456], a0);
        }

        jboolean Character::isJavaIdentifierStart(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isJavaIdentifierStart_39c7bd30], a0);
        }

        jboolean Character::isJavaLetter(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isJavaLetter_87fd5456], a0);
        }

        jboolean Character::isJavaLetterOrDigit(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isJavaLetterOrDigit_87fd5456], a0);
        }

        jboolean Character::isLetter(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isLetter_87fd5456], a0);
        }

        jboolean Character::isLetter(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isLetter_39c7bd30], a0);
        }

        jboolean Character::isLetterOrDigit(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isLetterOrDigit_39c7bd30], a0);
        }

        jboolean Character::isLetterOrDigit(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isLetterOrDigit_87fd5456], a0);
        }

        jboolean Character::isLowSurrogate(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isLowSurrogate_87fd5456], a0);
        }

        jboolean Character::isLowerCase(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isLowerCase_39c7bd30], a0);
        }

        jboolean Character::isLowerCase(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isLowerCase_87fd5456], a0);
        }

        jboolean Character::isMirrored(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isMirrored_87fd5456], a0);
        }

        jboolean Character::isMirrored(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isMirrored_39c7bd30], a0);
        }

        jboolean Character::isSpace(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isSpace_87fd5456], a0);
        }

        jboolean Character::isSpaceChar(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isSpaceChar_87fd5456], a0);
        }

        jboolean Character::isSpaceChar(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isSpaceChar_39c7bd30], a0);
        }

        jboolean Character::isSupplementaryCodePoint(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isSupplementaryCodePoint_39c7bd30], a0);
        }

        jboolean Character::isSurrogatePair(jchar a0, jchar a1)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isSurrogatePair_37c94822], a0, a1);
        }

        jboolean Character::isTitleCase(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isTitleCase_39c7bd30], a0);
        }

        jboolean Character::isTitleCase(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isTitleCase_87fd5456], a0);
        }

        jboolean Character::isUnicodeIdentifierPart(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isUnicodeIdentifierPart_87fd5456], a0);
        }

        jboolean Character::isUnicodeIdentifierPart(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isUnicodeIdentifierPart_39c7bd30], a0);
        }

        jboolean Character::isUnicodeIdentifierStart(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isUnicodeIdentifierStart_39c7bd30], a0);
        }

        jboolean Character::isUnicodeIdentifierStart(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isUnicodeIdentifierStart_87fd5456], a0);
        }

        jboolean Character::isUpperCase(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isUpperCase_39c7bd30], a0);
        }

        jboolean Character::isUpperCase(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isUpperCase_87fd5456], a0);
        }

        jboolean Character::isValidCodePoint(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isValidCodePoint_39c7bd30], a0);
        }

        jboolean Character::isWhitespace(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isWhitespace_39c7bd30], a0);
        }

        jboolean Character::isWhitespace(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isWhitespace_87fd5456], a0);
        }

        jint Character::offsetByCodePoints(const ::java::lang::CharSequence & a0, jint a1, jint a2)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_offsetByCodePoints_6cc8d7fd], a0.this$, a1, a2);
        }

        jint Character::offsetByCodePoints(const JArray< jchar > & a0, jint a1, jint a2, jint a3, jint a4)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_offsetByCodePoints_f453ace9], a0.this$, a1, a2, a3, a4);
        }

        jchar Character::reverseBytes(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticCharMethod(cls, mids$[mid_reverseBytes_87fd544f], a0);
        }

        JArray< jchar > Character::toChars(jint a0)
        {
            jclass cls = initializeClass();
            return JArray< jchar >(env->callStaticObjectMethod(cls, mids$[mid_toChars_b4292e99], a0));
        }

        jint Character::toChars(jint a0, const JArray< jchar > & a1, jint a2)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_toChars_273c5d2d], a0, a1.this$, a2);
        }

        jint Character::toCodePoint(jchar a0, jchar a1)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_toCodePoint_37c94831], a0, a1);
        }

        jint Character::toLowerCase(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_toLowerCase_39c7bd23], a0);
        }

        jchar Character::toLowerCase(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticCharMethod(cls, mids$[mid_toLowerCase_87fd544f], a0);
        }

        ::java::lang::String Character::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }

        ::java::lang::String Character::toString(jchar a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_7611a535], a0));
        }

        jchar Character::toTitleCase(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticCharMethod(cls, mids$[mid_toTitleCase_87fd544f], a0);
        }

        jint Character::toTitleCase(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_toTitleCase_39c7bd23], a0);
        }

        jint Character::toUpperCase(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_toUpperCase_39c7bd23], a0);
        }

        jchar Character::toUpperCase(jchar a0)
        {
            jclass cls = initializeClass();
            return env->callStaticCharMethod(cls, mids$[mid_toUpperCase_87fd544f], a0);
        }

        Character Character::valueOf(jchar a0)
        {
            jclass cls = initializeClass();
            return Character(env->callStaticObjectMethod(cls, mids$[mid_valueOf_58724da6], a0));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Character_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Character_instance_(PyTypeObject *type, PyObject *arg);
        static int t_Character_init_(t_Character *self, PyObject *args, PyObject *kwds);
        static PyObject *t_Character_charCount(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Character_charValue(t_Character *self);
        static PyObject *t_Character_codePointAt(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_codePointBefore(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_codePointCount(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_compareTo(t_Character *self, PyObject *args);
        static PyObject *t_Character_digit(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_equals(t_Character *self, PyObject *args);
        static PyObject *t_Character_forDigit(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_getDirectionality(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_getNumericValue(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_getType(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_hashCode(t_Character *self, PyObject *args);
        static PyObject *t_Character_isDefined(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isDigit(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isHighSurrogate(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Character_isISOControl(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isIdentifierIgnorable(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isJavaIdentifierPart(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isJavaIdentifierStart(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isJavaLetter(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Character_isJavaLetterOrDigit(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Character_isLetter(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isLetterOrDigit(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isLowSurrogate(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Character_isLowerCase(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isMirrored(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isSpace(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Character_isSpaceChar(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isSupplementaryCodePoint(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Character_isSurrogatePair(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isTitleCase(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isUnicodeIdentifierPart(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isUnicodeIdentifierStart(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isUpperCase(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_isValidCodePoint(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Character_isWhitespace(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_offsetByCodePoints(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_reverseBytes(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Character_toChars(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_toCodePoint(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_toLowerCase(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_toString(t_Character *self, PyObject *args);
        static PyObject *t_Character_toString_(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_toTitleCase(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_toUpperCase(PyTypeObject *type, PyObject *args);
        static PyObject *t_Character_valueOf(PyTypeObject *type, PyObject *arg);

        static PyMethodDef t_Character__methods_[] = {
            DECLARE_METHOD(t_Character, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Character, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Character, charCount, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Character, charValue, METH_NOARGS),
            DECLARE_METHOD(t_Character, codePointAt, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, codePointBefore, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, codePointCount, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, compareTo, METH_VARARGS),
            DECLARE_METHOD(t_Character, digit, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, equals, METH_VARARGS),
            DECLARE_METHOD(t_Character, forDigit, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, getDirectionality, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, getNumericValue, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, getType, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, hashCode, METH_VARARGS),
            DECLARE_METHOD(t_Character, isDefined, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isDigit, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isHighSurrogate, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Character, isISOControl, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isIdentifierIgnorable, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isJavaIdentifierPart, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isJavaIdentifierStart, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isJavaLetter, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Character, isJavaLetterOrDigit, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Character, isLetter, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isLetterOrDigit, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isLowSurrogate, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Character, isLowerCase, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isMirrored, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isSpace, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Character, isSpaceChar, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isSupplementaryCodePoint, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Character, isSurrogatePair, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isTitleCase, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isUnicodeIdentifierPart, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isUnicodeIdentifierStart, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isUpperCase, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, isValidCodePoint, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Character, isWhitespace, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, offsetByCodePoints, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, reverseBytes, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Character, toChars, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, toCodePoint, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, toLowerCase, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, toString, METH_VARARGS),
            DECLARE_METHOD(t_Character, toString_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Character, toTitleCase, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, toUpperCase, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Character, valueOf, METH_O | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Character, t_Character, ::java::lang::Object, Character, t_Character_init_, 0, 0, 0, 0, 0);

        void t_Character::install(PyObject *module)
        {
            installType(&PY_TYPE(Character), module, "Character", 0);
        }

        void t_Character::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "class_", make_descriptor(Character::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "wrapfn_", make_descriptor(unboxCharacter));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "boxfn_", make_descriptor(boxCharacter));
            Character::initializeClass();
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "COMBINING_SPACING_MARK", make_descriptor(Character::COMBINING_SPACING_MARK));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "CONNECTOR_PUNCTUATION", make_descriptor(Character::CONNECTOR_PUNCTUATION));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "CONTROL", make_descriptor(Character::CONTROL));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "CURRENCY_SYMBOL", make_descriptor(Character::CURRENCY_SYMBOL));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DASH_PUNCTUATION", make_descriptor(Character::DASH_PUNCTUATION));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DECIMAL_DIGIT_NUMBER", make_descriptor(Character::DECIMAL_DIGIT_NUMBER));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_ARABIC_NUMBER", make_descriptor(Character::DIRECTIONALITY_ARABIC_NUMBER));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_BOUNDARY_NEUTRAL", make_descriptor(Character::DIRECTIONALITY_BOUNDARY_NEUTRAL));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_COMMON_NUMBER_SEPARATOR", make_descriptor(Character::DIRECTIONALITY_COMMON_NUMBER_SEPARATOR));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_EUROPEAN_NUMBER", make_descriptor(Character::DIRECTIONALITY_EUROPEAN_NUMBER));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR", make_descriptor(Character::DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR", make_descriptor(Character::DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_LEFT_TO_RIGHT", make_descriptor(Character::DIRECTIONALITY_LEFT_TO_RIGHT));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING", make_descriptor(Character::DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE", make_descriptor(Character::DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_NONSPACING_MARK", make_descriptor(Character::DIRECTIONALITY_NONSPACING_MARK));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_OTHER_NEUTRALS", make_descriptor(Character::DIRECTIONALITY_OTHER_NEUTRALS));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_PARAGRAPH_SEPARATOR", make_descriptor(Character::DIRECTIONALITY_PARAGRAPH_SEPARATOR));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_POP_DIRECTIONAL_FORMAT", make_descriptor(Character::DIRECTIONALITY_POP_DIRECTIONAL_FORMAT));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_RIGHT_TO_LEFT", make_descriptor(Character::DIRECTIONALITY_RIGHT_TO_LEFT));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC", make_descriptor(Character::DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING", make_descriptor(Character::DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE", make_descriptor(Character::DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_SEGMENT_SEPARATOR", make_descriptor(Character::DIRECTIONALITY_SEGMENT_SEPARATOR));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_UNDEFINED", make_descriptor(Character::DIRECTIONALITY_UNDEFINED));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "DIRECTIONALITY_WHITESPACE", make_descriptor(Character::DIRECTIONALITY_WHITESPACE));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "ENCLOSING_MARK", make_descriptor(Character::ENCLOSING_MARK));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "END_PUNCTUATION", make_descriptor(Character::END_PUNCTUATION));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "FINAL_QUOTE_PUNCTUATION", make_descriptor(Character::FINAL_QUOTE_PUNCTUATION));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "FORMAT", make_descriptor(Character::FORMAT));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "INITIAL_QUOTE_PUNCTUATION", make_descriptor(Character::INITIAL_QUOTE_PUNCTUATION));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "LETTER_NUMBER", make_descriptor(Character::LETTER_NUMBER));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "LINE_SEPARATOR", make_descriptor(Character::LINE_SEPARATOR));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "LOWERCASE_LETTER", make_descriptor(Character::LOWERCASE_LETTER));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MATH_SYMBOL", make_descriptor(Character::MATH_SYMBOL));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MAX_CODE_POINT", make_descriptor(Character::MAX_CODE_POINT));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MAX_HIGH_SURROGATE", make_descriptor(Character::MAX_HIGH_SURROGATE));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MAX_LOW_SURROGATE", make_descriptor(Character::MAX_LOW_SURROGATE));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MAX_RADIX", make_descriptor(Character::MAX_RADIX));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MAX_SURROGATE", make_descriptor(Character::MAX_SURROGATE));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MAX_VALUE", make_descriptor(Character::MAX_VALUE));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MIN_CODE_POINT", make_descriptor(Character::MIN_CODE_POINT));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MIN_HIGH_SURROGATE", make_descriptor(Character::MIN_HIGH_SURROGATE));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MIN_LOW_SURROGATE", make_descriptor(Character::MIN_LOW_SURROGATE));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MIN_RADIX", make_descriptor(Character::MIN_RADIX));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MIN_SUPPLEMENTARY_CODE_POINT", make_descriptor(Character::MIN_SUPPLEMENTARY_CODE_POINT));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MIN_SURROGATE", make_descriptor(Character::MIN_SURROGATE));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MIN_VALUE", make_descriptor(Character::MIN_VALUE));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MODIFIER_LETTER", make_descriptor(Character::MODIFIER_LETTER));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "MODIFIER_SYMBOL", make_descriptor(Character::MODIFIER_SYMBOL));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "NON_SPACING_MARK", make_descriptor(Character::NON_SPACING_MARK));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "OTHER_LETTER", make_descriptor(Character::OTHER_LETTER));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "OTHER_NUMBER", make_descriptor(Character::OTHER_NUMBER));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "OTHER_PUNCTUATION", make_descriptor(Character::OTHER_PUNCTUATION));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "OTHER_SYMBOL", make_descriptor(Character::OTHER_SYMBOL));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "PARAGRAPH_SEPARATOR", make_descriptor(Character::PARAGRAPH_SEPARATOR));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "PRIVATE_USE", make_descriptor(Character::PRIVATE_USE));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "SIZE", make_descriptor(Character::SIZE));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "SPACE_SEPARATOR", make_descriptor(Character::SPACE_SEPARATOR));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "START_PUNCTUATION", make_descriptor(Character::START_PUNCTUATION));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "SURROGATE", make_descriptor(Character::SURROGATE));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "TITLECASE_LETTER", make_descriptor(Character::TITLECASE_LETTER));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "TYPE", make_descriptor(::java::lang::t_Class::wrap_Object(*Character::TYPE)));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "UNASSIGNED", make_descriptor(Character::UNASSIGNED));
            PyDict_SetItemString(PY_TYPE(Character).tp_dict, "UPPERCASE_LETTER", make_descriptor(Character::UPPERCASE_LETTER));
        }

        static PyObject *t_Character_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Character::initializeClass, 1)))
                return NULL;
            return t_Character::wrap_Object(Character(((t_Character *) arg)->object.this$));
        }
        static PyObject *t_Character_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Character::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_Character_init_(t_Character *self, PyObject *args, PyObject *kwds)
        {
            jchar a0;
            Character object((jobject) NULL);

            if (!parseArgs(args, "C", &a0))
            {
                INT_CALL(object = Character(a0));
                self->object = object;
            }
            else
            {
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_Character_charCount(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            jint result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Character::charCount(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "charCount", arg);
            return NULL;
        }

        static PyObject *t_Character_charValue(t_Character *self)
        {
            jchar result;
            OBJ_CALL(result = self->object.charValue());
            return PyUnicode_FromUnicode((Py_UNICODE *) &result, 1);
        }

        static PyObject *t_Character_codePointAt(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 2:
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "[CI", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Character::codePointAt(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "OI", &::java::lang::PY_TYPE(CharSequence), &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Character::codePointAt(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
                break;
              case 3:
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    jint result;

                    if (!parseArgs(args, "[CII", &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = ::java::lang::Character::codePointAt(a0, a1, a2));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError(type, "codePointAt", args);
            return NULL;
        }

        static PyObject *t_Character_codePointBefore(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 2:
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "OI", &::java::lang::PY_TYPE(CharSequence), &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Character::codePointBefore(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "[CI", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Character::codePointBefore(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
                break;
              case 3:
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    jint result;

                    if (!parseArgs(args, "[CII", &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = ::java::lang::Character::codePointBefore(a0, a1, a2));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError(type, "codePointBefore", args);
            return NULL;
        }

        static PyObject *t_Character_codePointCount(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 3:
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    jint result;

                    if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = ::java::lang::Character::codePointCount(a0, a1, a2));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    jint result;

                    if (!parseArgs(args, "[CII", &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = ::java::lang::Character::codePointCount(a0, a1, a2));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError(type, "codePointCount", args);
            return NULL;
        }

        static PyObject *t_Character_compareTo(t_Character *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::Object a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    Character a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(Character), &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "compareTo", args);
            return NULL;
        }

        static PyObject *t_Character_digit(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 2:
                {
                    jchar a0;
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "CI", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Character::digit(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    jint a0;
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "II", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Character::digit(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError(type, "digit", args);
            return NULL;
        }

        static PyObject *t_Character_equals(t_Character *self, PyObject *args)
        {
            ::java::lang::Object a0((jobject) NULL);
            jboolean result;

            if (!parseArgs(args, "o", &a0))
            {
                OBJ_CALL(result = self->object.equals(a0));
                Py_RETURN_BOOL(result);
            }

            return callSuper(&PY_TYPE(Character), (PyObject *) self, "equals", args, 2);
        }

        static PyObject *t_Character_forDigit(PyTypeObject *type, PyObject *args)
        {
            jint a0;
            jint a1;
            jchar result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = ::java::lang::Character::forDigit(a0, a1));
                return PyUnicode_FromUnicode((Py_UNICODE *) &result, 1);
            }

            PyErr_SetArgsError(type, "forDigit", args);
            return NULL;
        }

        static PyObject *t_Character_getDirectionality(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jchar a0;
                    jbyte result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::getDirectionality(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    jint a0;
                    jbyte result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::getDirectionality(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError(type, "getDirectionality", args);
            return NULL;
        }

        static PyObject *t_Character_getNumericValue(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jint result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::getNumericValue(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    jchar a0;
                    jint result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::getNumericValue(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError(type, "getNumericValue", args);
            return NULL;
        }

        static PyObject *t_Character_getType(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jchar a0;
                    jint result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::getType(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    jint a0;
                    jint result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::getType(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError(type, "getType", args);
            return NULL;
        }

        static PyObject *t_Character_hashCode(t_Character *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.hashCode());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Character), (PyObject *) self, "hashCode", args, 2);
        }

        static PyObject *t_Character_isDefined(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isDefined(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isDefined(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isDefined", args);
            return NULL;
        }

        static PyObject *t_Character_isDigit(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isDigit(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isDigit(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isDigit", args);
            return NULL;
        }

        static PyObject *t_Character_isHighSurrogate(PyTypeObject *type, PyObject *arg)
        {
            jchar a0;
            jboolean result;

            if (!parseArg(arg, "C", &a0))
            {
                OBJ_CALL(result = ::java::lang::Character::isHighSurrogate(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError(type, "isHighSurrogate", arg);
            return NULL;
        }

        static PyObject *t_Character_isISOControl(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isISOControl(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isISOControl(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isISOControl", args);
            return NULL;
        }

        static PyObject *t_Character_isIdentifierIgnorable(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isIdentifierIgnorable(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isIdentifierIgnorable(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isIdentifierIgnorable", args);
            return NULL;
        }

        static PyObject *t_Character_isJavaIdentifierPart(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isJavaIdentifierPart(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isJavaIdentifierPart(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isJavaIdentifierPart", args);
            return NULL;
        }

        static PyObject *t_Character_isJavaIdentifierStart(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isJavaIdentifierStart(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isJavaIdentifierStart(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isJavaIdentifierStart", args);
            return NULL;
        }

        static PyObject *t_Character_isJavaLetter(PyTypeObject *type, PyObject *arg)
        {
            jchar a0;
            jboolean result;

            if (!parseArg(arg, "C", &a0))
            {
                OBJ_CALL(result = ::java::lang::Character::isJavaLetter(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError(type, "isJavaLetter", arg);
            return NULL;
        }

        static PyObject *t_Character_isJavaLetterOrDigit(PyTypeObject *type, PyObject *arg)
        {
            jchar a0;
            jboolean result;

            if (!parseArg(arg, "C", &a0))
            {
                OBJ_CALL(result = ::java::lang::Character::isJavaLetterOrDigit(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError(type, "isJavaLetterOrDigit", arg);
            return NULL;
        }

        static PyObject *t_Character_isLetter(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isLetter(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isLetter(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isLetter", args);
            return NULL;
        }

        static PyObject *t_Character_isLetterOrDigit(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isLetterOrDigit(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isLetterOrDigit(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isLetterOrDigit", args);
            return NULL;
        }

        static PyObject *t_Character_isLowSurrogate(PyTypeObject *type, PyObject *arg)
        {
            jchar a0;
            jboolean result;

            if (!parseArg(arg, "C", &a0))
            {
                OBJ_CALL(result = ::java::lang::Character::isLowSurrogate(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError(type, "isLowSurrogate", arg);
            return NULL;
        }

        static PyObject *t_Character_isLowerCase(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isLowerCase(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isLowerCase(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isLowerCase", args);
            return NULL;
        }

        static PyObject *t_Character_isMirrored(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isMirrored(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isMirrored(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isMirrored", args);
            return NULL;
        }

        static PyObject *t_Character_isSpace(PyTypeObject *type, PyObject *arg)
        {
            jchar a0;
            jboolean result;

            if (!parseArg(arg, "C", &a0))
            {
                OBJ_CALL(result = ::java::lang::Character::isSpace(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError(type, "isSpace", arg);
            return NULL;
        }

        static PyObject *t_Character_isSpaceChar(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isSpaceChar(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isSpaceChar(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isSpaceChar", args);
            return NULL;
        }

        static PyObject *t_Character_isSupplementaryCodePoint(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            jboolean result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Character::isSupplementaryCodePoint(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError(type, "isSupplementaryCodePoint", arg);
            return NULL;
        }

        static PyObject *t_Character_isSurrogatePair(PyTypeObject *type, PyObject *args)
        {
            jchar a0;
            jchar a1;
            jboolean result;

            if (!parseArgs(args, "CC", &a0, &a1))
            {
                OBJ_CALL(result = ::java::lang::Character::isSurrogatePair(a0, a1));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError(type, "isSurrogatePair", args);
            return NULL;
        }

        static PyObject *t_Character_isTitleCase(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isTitleCase(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isTitleCase(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isTitleCase", args);
            return NULL;
        }

        static PyObject *t_Character_isUnicodeIdentifierPart(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isUnicodeIdentifierPart(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isUnicodeIdentifierPart(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isUnicodeIdentifierPart", args);
            return NULL;
        }

        static PyObject *t_Character_isUnicodeIdentifierStart(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isUnicodeIdentifierStart(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isUnicodeIdentifierStart(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isUnicodeIdentifierStart", args);
            return NULL;
        }

        static PyObject *t_Character_isUpperCase(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isUpperCase(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isUpperCase(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isUpperCase", args);
            return NULL;
        }

        static PyObject *t_Character_isValidCodePoint(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            jboolean result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Character::isValidCodePoint(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError(type, "isValidCodePoint", arg);
            return NULL;
        }

        static PyObject *t_Character_isWhitespace(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jboolean result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isWhitespace(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    jchar a0;
                    jboolean result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::isWhitespace(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "isWhitespace", args);
            return NULL;
        }

        static PyObject *t_Character_offsetByCodePoints(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 3:
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    jint result;

                    if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = ::java::lang::Character::offsetByCodePoints(a0, a1, a2));
                        return PyInt_FromLong((long) result);
                    }
                }
                break;
              case 5:
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    jint a3;
                    jint a4;
                    jint result;

                    if (!parseArgs(args, "[CIIII", &a0, &a1, &a2, &a3, &a4))
                    {
                        OBJ_CALL(result = ::java::lang::Character::offsetByCodePoints(a0, a1, a2, a3, a4));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError(type, "offsetByCodePoints", args);
            return NULL;
        }

        static PyObject *t_Character_reverseBytes(PyTypeObject *type, PyObject *arg)
        {
            jchar a0;
            jchar result;

            if (!parseArg(arg, "C", &a0))
            {
                OBJ_CALL(result = ::java::lang::Character::reverseBytes(a0));
                return PyUnicode_FromUnicode((Py_UNICODE *) &result, 1);
            }

            PyErr_SetArgsError(type, "reverseBytes", arg);
            return NULL;
        }

        static PyObject *t_Character_toChars(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    JArray< jchar > result((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::toChars(a0));
                        return result.wrap();
                    }
                }
                break;
              case 3:
                {
                    jint a0;
                    JArray< jchar > a1((jobject) NULL);
                    jint a2;
                    jint result;

                    if (!parseArgs(args, "I[CI", &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = ::java::lang::Character::toChars(a0, a1, a2));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError(type, "toChars", args);
            return NULL;
        }

        static PyObject *t_Character_toCodePoint(PyTypeObject *type, PyObject *args)
        {
            jchar a0;
            jchar a1;
            jint result;

            if (!parseArgs(args, "CC", &a0, &a1))
            {
                OBJ_CALL(result = ::java::lang::Character::toCodePoint(a0, a1));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "toCodePoint", args);
            return NULL;
        }

        static PyObject *t_Character_toLowerCase(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jint result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::toLowerCase(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    jchar a0;
                    jchar result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::toLowerCase(a0));
                        return PyUnicode_FromUnicode((Py_UNICODE *) &result, 1);
                    }
                }
            }

            PyErr_SetArgsError(type, "toLowerCase", args);
            return NULL;
        }

        static PyObject *t_Character_toString(t_Character *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(Character), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_Character_toString_(PyTypeObject *type, PyObject *args)
        {
            jchar a0;
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, "C", &a0))
            {
                OBJ_CALL(result = ::java::lang::Character::toString(a0));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "toString_", args);
            return NULL;
        }

        static PyObject *t_Character_toTitleCase(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jchar a0;
                    jchar result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::toTitleCase(a0));
                        return PyUnicode_FromUnicode((Py_UNICODE *) &result, 1);
                    }
                }
                {
                    jint a0;
                    jint result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::toTitleCase(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError(type, "toTitleCase", args);
            return NULL;
        }

        static PyObject *t_Character_toUpperCase(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jint result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::toUpperCase(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    jchar a0;
                    jchar result;

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Character::toUpperCase(a0));
                        return PyUnicode_FromUnicode((Py_UNICODE *) &result, 1);
                    }
                }
            }

            PyErr_SetArgsError(type, "toUpperCase", args);
            return NULL;
        }

        static PyObject *t_Character_valueOf(PyTypeObject *type, PyObject *arg)
        {
            jchar a0;
            Character result((jobject) NULL);

            if (!parseArg(arg, "C", &a0))
            {
                OBJ_CALL(result = ::java::lang::Character::valueOf(a0));
                return t_Character::wrap_Object(result);
            }

            PyErr_SetArgsError(type, "valueOf", arg);
            return NULL;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/String.h"
#include "java/lang/Comparable.h"
#include "java/lang/CharSequence.h"
#include "java/lang/StringBuilder.h"
#include "java/lang/Class.h"
#include "java/lang/StringBuffer.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *String::class$ = NULL;
        jmethodID *String::mids$ = NULL;

        jclass String::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/String");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_init$_700e23d6] = env->getMethodID(cls, "<init>", "([C)V");
                mids$[mid_init$_49b4f12b] = env->getMethodID(cls, "<init>", "([B)V");
                mids$[mid_init$_44634788] = env->getMethodID(cls, "<init>", "(Ljava/lang/StringBuffer;)V");
                mids$[mid_init$_9f94ae34] = env->getMethodID(cls, "<init>", "(Ljava/lang/StringBuilder;)V");
                mids$[mid_init$_b8354c43] = env->getMethodID(cls, "<init>", "([BI)V");
                mids$[mid_init$_1a0c6fd5] = env->getMethodID(cls, "<init>", "([BLjava/lang/String;)V");
                mids$[mid_init$_6f0bb356] = env->getMethodID(cls, "<init>", "([CII)V");
                mids$[mid_init$_3e1ea22c] = env->getMethodID(cls, "<init>", "([III)V");
                mids$[mid_init$_86f4435f] = env->getMethodID(cls, "<init>", "([BII)V");
                mids$[mid_init$_96a25f0b] = env->getMethodID(cls, "<init>", "([BIII)V");
                mids$[mid_init$_5ab96441] = env->getMethodID(cls, "<init>", "([BIILjava/lang/String;)V");
                mids$[mid_charAt_39c7bd29] = env->getMethodID(cls, "charAt", "(I)C");
                mids$[mid_codePointAt_39c7bd23] = env->getMethodID(cls, "codePointAt", "(I)I");
                mids$[mid_codePointBefore_39c7bd23] = env->getMethodID(cls, "codePointBefore", "(I)I");
                mids$[mid_codePointCount_d8d154b9] = env->getMethodID(cls, "codePointCount", "(II)I");
                mids$[mid_compareTo_290588f1] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Object;)I");
                mids$[mid_compareTo_5fdc3f57] = env->getMethodID(cls, "compareTo", "(Ljava/lang/String;)I");
                mids$[mid_compareToIgnoreCase_5fdc3f57] = env->getMethodID(cls, "compareToIgnoreCase", "(Ljava/lang/String;)I");
                mids$[mid_concat_97a5258f] = env->getMethodID(cls, "concat", "(Ljava/lang/String;)Ljava/lang/String;");
                mids$[mid_contains_a8afc646] = env->getMethodID(cls, "contains", "(Ljava/lang/CharSequence;)Z");
                mids$[mid_contentEquals_a8afc646] = env->getMethodID(cls, "contentEquals", "(Ljava/lang/CharSequence;)Z");
                mids$[mid_contentEquals_44634784] = env->getMethodID(cls, "contentEquals", "(Ljava/lang/StringBuffer;)Z");
                mids$[mid_copyValueOf_c783d655] = env->getStaticMethodID(cls, "copyValueOf", "([C)Ljava/lang/String;");
                mids$[mid_copyValueOf_ddb60785] = env->getStaticMethodID(cls, "copyValueOf", "([CII)Ljava/lang/String;");
                mids$[mid_endsWith_5fdc3f44] = env->getMethodID(cls, "endsWith", "(Ljava/lang/String;)Z");
                mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
                mids$[mid_equalsIgnoreCase_5fdc3f44] = env->getMethodID(cls, "equalsIgnoreCase", "(Ljava/lang/String;)Z");
                mids$[mid_format_0fb26e3b] = env->getStaticMethodID(cls, "format", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;");
                mids$[mid_getBytes_dab10e7e] = env->getMethodID(cls, "getBytes", "()[B");
                mids$[mid_getBytes_94a731a4] = env->getMethodID(cls, "getBytes", "(Ljava/lang/String;)[B");
                mids$[mid_getBytes_fdf97d27] = env->getMethodID(cls, "getBytes", "(II[BI)V");
                mids$[mid_getChars_06518f84] = env->getMethodID(cls, "getChars", "(II[CI)V");
                mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
                mids$[mid_indexOf_39c7bd23] = env->getMethodID(cls, "indexOf", "(I)I");
                mids$[mid_indexOf_5fdc3f57] = env->getMethodID(cls, "indexOf", "(Ljava/lang/String;)I");
                mids$[mid_indexOf_6e53ccd9] = env->getMethodID(cls, "indexOf", "(Ljava/lang/String;I)I");
                mids$[mid_indexOf_d8d154b9] = env->getMethodID(cls, "indexOf", "(II)I");
                mids$[mid_intern_14c7b5c5] = env->getMethodID(cls, "intern", "()Ljava/lang/String;");
                mids$[mid_isEmpty_54c6a16a] = env->getMethodID(cls, "isEmpty", "()Z");
                mids$[mid_lastIndexOf_39c7bd23] = env->getMethodID(cls, "lastIndexOf", "(I)I");
                mids$[mid_lastIndexOf_5fdc3f57] = env->getMethodID(cls, "lastIndexOf", "(Ljava/lang/String;)I");
                mids$[mid_lastIndexOf_d8d154b9] = env->getMethodID(cls, "lastIndexOf", "(II)I");
                mids$[mid_lastIndexOf_6e53ccd9] = env->getMethodID(cls, "lastIndexOf", "(Ljava/lang/String;I)I");
                mids$[mid_length_54c6a179] = env->getMethodID(cls, "length", "()I");
                mids$[mid_matches_5fdc3f44] = env->getMethodID(cls, "matches", "(Ljava/lang/String;)Z");
                mids$[mid_offsetByCodePoints_d8d154b9] = env->getMethodID(cls, "offsetByCodePoints", "(II)I");
                mids$[mid_regionMatches_344d8cb6] = env->getMethodID(cls, "regionMatches", "(ILjava/lang/String;II)Z");
                mids$[mid_regionMatches_35f2560d] = env->getMethodID(cls, "regionMatches", "(ZILjava/lang/String;II)Z");
                mids$[mid_replace_f1c62e0d] = env->getMethodID(cls, "replace", "(CC)Ljava/lang/String;");
                mids$[mid_replace_103b702d] = env->getMethodID(cls, "replace", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;");
                mids$[mid_replaceAll_aacea7e9] = env->getMethodID(cls, "replaceAll", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
                mids$[mid_replaceFirst_aacea7e9] = env->getMethodID(cls, "replaceFirst", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
                mids$[mid_split_1f6a174f] = env->getMethodID(cls, "split", "(Ljava/lang/String;)[Ljava/lang/String;");
                mids$[mid_split_3384fe85] = env->getMethodID(cls, "split", "(Ljava/lang/String;I)[Ljava/lang/String;");
                mids$[mid_startsWith_5fdc3f44] = env->getMethodID(cls, "startsWith", "(Ljava/lang/String;)Z");
                mids$[mid_startsWith_6e53ccca] = env->getMethodID(cls, "startsWith", "(Ljava/lang/String;I)Z");
                mids$[mid_subSequence_f88dfd57] = env->getMethodID(cls, "subSequence", "(II)Ljava/lang/CharSequence;");
                mids$[mid_substring_141401b3] = env->getMethodID(cls, "substring", "(I)Ljava/lang/String;");
                mids$[mid_substring_f9118fe5] = env->getMethodID(cls, "substring", "(II)Ljava/lang/String;");
                mids$[mid_toCharArray_dab10e7f] = env->getMethodID(cls, "toCharArray", "()[C");
                mids$[mid_toLowerCase_14c7b5c5] = env->getMethodID(cls, "toLowerCase", "()Ljava/lang/String;");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
                mids$[mid_toUpperCase_14c7b5c5] = env->getMethodID(cls, "toUpperCase", "()Ljava/lang/String;");
                mids$[mid_trim_14c7b5c5] = env->getMethodID(cls, "trim", "()Ljava/lang/String;");
                mids$[mid_valueOf_445a175e] = env->getStaticMethodID(cls, "valueOf", "(Z)Ljava/lang/String;");
                mids$[mid_valueOf_c9db4eed] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/Object;)Ljava/lang/String;");
                mids$[mid_valueOf_5ded254a] = env->getStaticMethodID(cls, "valueOf", "(F)Ljava/lang/String;");
                mids$[mid_valueOf_1b4624f8] = env->getStaticMethodID(cls, "valueOf", "(D)Ljava/lang/String;");
                mids$[mid_valueOf_141401b3] = env->getStaticMethodID(cls, "valueOf", "(I)Ljava/lang/String;");
                mids$[mid_valueOf_c783d655] = env->getStaticMethodID(cls, "valueOf", "([C)Ljava/lang/String;");
                mids$[mid_valueOf_7611a535] = env->getStaticMethodID(cls, "valueOf", "(C)Ljava/lang/String;");
                mids$[mid_valueOf_3e02f30e] = env->getStaticMethodID(cls, "valueOf", "(J)Ljava/lang/String;");
                mids$[mid_valueOf_ddb60785] = env->getStaticMethodID(cls, "valueOf", "([CII)Ljava/lang/String;");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        String::String() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        String::String(const JArray< jchar > & a0) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_700e23d6, a0.this$)) {}

        String::String(const JArray< jbyte > & a0) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_49b4f12b, a0.this$)) {}

        String::String(const ::java::lang::StringBuffer & a0) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_44634788, a0.this$)) {}

        String::String(const ::java::lang::StringBuilder & a0) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_9f94ae34, a0.this$)) {}

        String::String(const JArray< jbyte > & a0, jint a1) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_b8354c43, a0.this$, a1)) {}

        String::String(const JArray< jbyte > & a0, const String & a1) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_1a0c6fd5, a0.this$, a1.this$)) {}

        String::String(const JArray< jchar > & a0, jint a1, jint a2) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_6f0bb356, a0.this$, a1, a2)) {}

        String::String(const JArray< jint > & a0, jint a1, jint a2) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_3e1ea22c, a0.this$, a1, a2)) {}

        String::String(const JArray< jbyte > & a0, jint a1, jint a2) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_86f4435f, a0.this$, a1, a2)) {}

        String::String(const JArray< jbyte > & a0, jint a1, jint a2, jint a3) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_96a25f0b, a0.this$, a1, a2, a3)) {}

        String::String(const JArray< jbyte > & a0, jint a1, jint a2, const String & a3) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_5ab96441, a0.this$, a1, a2, a3.this$)) {}

        jchar String::charAt(jint a0) const
        {
            return env->callCharMethod(this$, mids$[mid_charAt_39c7bd29], a0);
        }

        jint String::codePointAt(jint a0) const
        {
            return env->callIntMethod(this$, mids$[mid_codePointAt_39c7bd23], a0);
        }

        jint String::codePointBefore(jint a0) const
        {
            return env->callIntMethod(this$, mids$[mid_codePointBefore_39c7bd23], a0);
        }

        jint String::codePointCount(jint a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_codePointCount_d8d154b9], a0, a1);
        }

        jint String::compareTo(const ::java::lang::Object & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_290588f1], a0.this$);
        }

        jint String::compareTo(const String & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_5fdc3f57], a0.this$);
        }

        jint String::compareToIgnoreCase(const String & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareToIgnoreCase_5fdc3f57], a0.this$);
        }

        String String::concat(const String & a0) const
        {
            return String(env->callObjectMethod(this$, mids$[mid_concat_97a5258f], a0.this$));
        }

        jboolean String::contains(const ::java::lang::CharSequence & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_contains_a8afc646], a0.this$);
        }

        jboolean String::contentEquals(const ::java::lang::CharSequence & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_contentEquals_a8afc646], a0.this$);
        }

        jboolean String::contentEquals(const ::java::lang::StringBuffer & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_contentEquals_44634784], a0.this$);
        }

        String String::copyValueOf(const JArray< jchar > & a0)
        {
            jclass cls = initializeClass();
            return String(env->callStaticObjectMethod(cls, mids$[mid_copyValueOf_c783d655], a0.this$));
        }

        String String::copyValueOf(const JArray< jchar > & a0, jint a1, jint a2)
        {
            jclass cls = initializeClass();
            return String(env->callStaticObjectMethod(cls, mids$[mid_copyValueOf_ddb60785], a0.this$, a1, a2));
        }

        jboolean String::endsWith(const String & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_endsWith_5fdc3f44], a0.this$);
        }

        jboolean String::equals(const ::java::lang::Object & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
        }

        jboolean String::equalsIgnoreCase(const String & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_equalsIgnoreCase_5fdc3f44], a0.this$);
        }

        String String::format(const String & a0, const JArray< ::java::lang::Object > & a1)
        {
            jclass cls = initializeClass();
            return String(env->callStaticObjectMethod(cls, mids$[mid_format_0fb26e3b], a0.this$, a1.this$));
        }

        JArray< jbyte > String::getBytes() const
        {
            return JArray< jbyte >(env->callObjectMethod(this$, mids$[mid_getBytes_dab10e7e]));
        }

        JArray< jbyte > String::getBytes(const String & a0) const
        {
            return JArray< jbyte >(env->callObjectMethod(this$, mids$[mid_getBytes_94a731a4], a0.this$));
        }

        void String::getBytes(jint a0, jint a1, const JArray< jbyte > & a2, jint a3) const
        {
            env->callVoidMethod(this$, mids$[mid_getBytes_fdf97d27], a0, a1, a2.this$, a3);
        }

        void String::getChars(jint a0, jint a1, const JArray< jchar > & a2, jint a3) const
        {
            env->callVoidMethod(this$, mids$[mid_getChars_06518f84], a0, a1, a2.this$, a3);
        }

        jint String::hashCode() const
        {
            return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
        }

        jint String::indexOf(jint a0) const
        {
            return env->callIntMethod(this$, mids$[mid_indexOf_39c7bd23], a0);
        }

        jint String::indexOf(const String & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_indexOf_5fdc3f57], a0.this$);
        }

        jint String::indexOf(const String & a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_indexOf_6e53ccd9], a0.this$, a1);
        }

        jint String::indexOf(jint a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_indexOf_d8d154b9], a0, a1);
        }

        String String::intern() const
        {
            return String(env->callObjectMethod(this$, mids$[mid_intern_14c7b5c5]));
        }

        jboolean String::isEmpty() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isEmpty_54c6a16a]);
        }

        jint String::lastIndexOf(jint a0) const
        {
            return env->callIntMethod(this$, mids$[mid_lastIndexOf_39c7bd23], a0);
        }

        jint String::lastIndexOf(const String & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_lastIndexOf_5fdc3f57], a0.this$);
        }

        jint String::lastIndexOf(jint a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_lastIndexOf_d8d154b9], a0, a1);
        }

        jint String::lastIndexOf(const String & a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_lastIndexOf_6e53ccd9], a0.this$, a1);
        }

        jint String::length() const
        {
            return env->callIntMethod(this$, mids$[mid_length_54c6a179]);
        }

        jboolean String::matches(const String & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_matches_5fdc3f44], a0.this$);
        }

        jint String::offsetByCodePoints(jint a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_offsetByCodePoints_d8d154b9], a0, a1);
        }

        jboolean String::regionMatches(jint a0, const String & a1, jint a2, jint a3) const
        {
            return env->callBooleanMethod(this$, mids$[mid_regionMatches_344d8cb6], a0, a1.this$, a2, a3);
        }

        jboolean String::regionMatches(jboolean a0, jint a1, const String & a2, jint a3, jint a4) const
        {
            return env->callBooleanMethod(this$, mids$[mid_regionMatches_35f2560d], a0, a1, a2.this$, a3, a4);
        }

        String String::replace(jchar a0, jchar a1) const
        {
            return String(env->callObjectMethod(this$, mids$[mid_replace_f1c62e0d], a0, a1));
        }

        String String::replace(const ::java::lang::CharSequence & a0, const ::java::lang::CharSequence & a1) const
        {
            return String(env->callObjectMethod(this$, mids$[mid_replace_103b702d], a0.this$, a1.this$));
        }

        String String::replaceAll(const String & a0, const String & a1) const
        {
            return String(env->callObjectMethod(this$, mids$[mid_replaceAll_aacea7e9], a0.this$, a1.this$));
        }

        String String::replaceFirst(const String & a0, const String & a1) const
        {
            return String(env->callObjectMethod(this$, mids$[mid_replaceFirst_aacea7e9], a0.this$, a1.this$));
        }

        JArray< String > String::split(const String & a0) const
        {
            return JArray< String >(env->callObjectMethod(this$, mids$[mid_split_1f6a174f], a0.this$));
        }

        JArray< String > String::split(const String & a0, jint a1) const
        {
            return JArray< String >(env->callObjectMethod(this$, mids$[mid_split_3384fe85], a0.this$, a1));
        }

        jboolean String::startsWith(const String & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_startsWith_5fdc3f44], a0.this$);
        }

        jboolean String::startsWith(const String & a0, jint a1) const
        {
            return env->callBooleanMethod(this$, mids$[mid_startsWith_6e53ccca], a0.this$, a1);
        }

        ::java::lang::CharSequence String::subSequence(jint a0, jint a1) const
        {
            return ::java::lang::CharSequence(env->callObjectMethod(this$, mids$[mid_subSequence_f88dfd57], a0, a1));
        }

        String String::substring(jint a0) const
        {
            return String(env->callObjectMethod(this$, mids$[mid_substring_141401b3], a0));
        }

        String String::substring(jint a0, jint a1) const
        {
            return String(env->callObjectMethod(this$, mids$[mid_substring_f9118fe5], a0, a1));
        }

        JArray< jchar > String::toCharArray() const
        {
            return JArray< jchar >(env->callObjectMethod(this$, mids$[mid_toCharArray_dab10e7f]));
        }

        String String::toLowerCase() const
        {
            return String(env->callObjectMethod(this$, mids$[mid_toLowerCase_14c7b5c5]));
        }

        String String::toString() const
        {
            return String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }

        String String::toUpperCase() const
        {
            return String(env->callObjectMethod(this$, mids$[mid_toUpperCase_14c7b5c5]));
        }

        String String::trim() const
        {
            return String(env->callObjectMethod(this$, mids$[mid_trim_14c7b5c5]));
        }

        String String::valueOf(jboolean a0)
        {
            jclass cls = initializeClass();
            return String(env->callStaticObjectMethod(cls, mids$[mid_valueOf_445a175e], a0));
        }

        String String::valueOf(const ::java::lang::Object & a0)
        {
            jclass cls = initializeClass();
            return String(env->callStaticObjectMethod(cls, mids$[mid_valueOf_c9db4eed], a0.this$));
        }

        String String::valueOf(jfloat a0)
        {
            jclass cls = initializeClass();
            return String(env->callStaticObjectMethod(cls, mids$[mid_valueOf_5ded254a], a0));
        }

        String String::valueOf(jdouble a0)
        {
            jclass cls = initializeClass();
            return String(env->callStaticObjectMethod(cls, mids$[mid_valueOf_1b4624f8], a0));
        }

        String String::valueOf(jint a0)
        {
            jclass cls = initializeClass();
            return String(env->callStaticObjectMethod(cls, mids$[mid_valueOf_141401b3], a0));
        }

        String String::valueOf(const JArray< jchar > & a0)
        {
            jclass cls = initializeClass();
            return String(env->callStaticObjectMethod(cls, mids$[mid_valueOf_c783d655], a0.this$));
        }

        String String::valueOf(jchar a0)
        {
            jclass cls = initializeClass();
            return String(env->callStaticObjectMethod(cls, mids$[mid_valueOf_7611a535], a0));
        }

        String String::valueOf(jlong a0)
        {
            jclass cls = initializeClass();
            return String(env->callStaticObjectMethod(cls, mids$[mid_valueOf_3e02f30e], a0));
        }

        String String::valueOf(const JArray< jchar > & a0, jint a1, jint a2)
        {
            jclass cls = initializeClass();
            return String(env->callStaticObjectMethod(cls, mids$[mid_valueOf_ddb60785], a0.this$, a1, a2));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_String_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_String_instance_(PyTypeObject *type, PyObject *arg);
        static int t_String_init_(t_String *self, PyObject *args, PyObject *kwds);
        static PyObject *t_String_charAt(t_String *self, PyObject *arg);
        static PyObject *t_String_codePointAt(t_String *self, PyObject *arg);
        static PyObject *t_String_codePointBefore(t_String *self, PyObject *arg);
        static PyObject *t_String_codePointCount(t_String *self, PyObject *args);
        static PyObject *t_String_compareTo(t_String *self, PyObject *args);
        static PyObject *t_String_compareToIgnoreCase(t_String *self, PyObject *arg);
        static PyObject *t_String_concat(t_String *self, PyObject *arg);
        static PyObject *t_String_contains(t_String *self, PyObject *arg);
        static PyObject *t_String_contentEquals(t_String *self, PyObject *args);
        static PyObject *t_String_copyValueOf(PyTypeObject *type, PyObject *args);
        static PyObject *t_String_endsWith(t_String *self, PyObject *arg);
        static PyObject *t_String_equals(t_String *self, PyObject *args);
        static PyObject *t_String_equalsIgnoreCase(t_String *self, PyObject *arg);
        static PyObject *t_String_format(PyTypeObject *type, PyObject *args);
        static PyObject *t_String_getBytes(t_String *self, PyObject *args);
        static PyObject *t_String_getChars(t_String *self, PyObject *args);
        static PyObject *t_String_hashCode(t_String *self, PyObject *args);
        static PyObject *t_String_indexOf(t_String *self, PyObject *args);
        static PyObject *t_String_intern(t_String *self);
        static PyObject *t_String_isEmpty(t_String *self);
        static PyObject *t_String_lastIndexOf(t_String *self, PyObject *args);
        static PyObject *t_String_length(t_String *self);
        static PyObject *t_String_matches(t_String *self, PyObject *arg);
        static PyObject *t_String_offsetByCodePoints(t_String *self, PyObject *args);
        static PyObject *t_String_regionMatches(t_String *self, PyObject *args);
        static PyObject *t_String_replace(t_String *self, PyObject *args);
        static PyObject *t_String_replaceAll(t_String *self, PyObject *args);
        static PyObject *t_String_replaceFirst(t_String *self, PyObject *args);
        static PyObject *t_String_split(t_String *self, PyObject *args);
        static PyObject *t_String_startsWith(t_String *self, PyObject *args);
        static PyObject *t_String_subSequence(t_String *self, PyObject *args);
        static PyObject *t_String_substring(t_String *self, PyObject *args);
        static PyObject *t_String_toCharArray(t_String *self);
        static PyObject *t_String_toLowerCase(t_String *self);
        static PyObject *t_String_toString(t_String *self, PyObject *args);
        static PyObject *t_String_toUpperCase(t_String *self);
        static PyObject *t_String_trim(t_String *self);
        static PyObject *t_String_valueOf(PyTypeObject *type, PyObject *args);
        static PyObject *t_String_get__bytes(t_String *self, void *data);
        static PyObject *t_String_get__empty(t_String *self, void *data);
        static PyGetSetDef t_String__fields_[] = {
            DECLARE_GET_FIELD(t_String, bytes),
            DECLARE_GET_FIELD(t_String, empty),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_String__methods_[] = {
            DECLARE_METHOD(t_String, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_String, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_String, charAt, METH_O),
            DECLARE_METHOD(t_String, codePointAt, METH_O),
            DECLARE_METHOD(t_String, codePointBefore, METH_O),
            DECLARE_METHOD(t_String, codePointCount, METH_VARARGS),
            DECLARE_METHOD(t_String, compareTo, METH_VARARGS),
            DECLARE_METHOD(t_String, compareToIgnoreCase, METH_O),
            DECLARE_METHOD(t_String, concat, METH_O),
            DECLARE_METHOD(t_String, contains, METH_O),
            DECLARE_METHOD(t_String, contentEquals, METH_VARARGS),
            DECLARE_METHOD(t_String, copyValueOf, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_String, endsWith, METH_O),
            DECLARE_METHOD(t_String, equals, METH_VARARGS),
            DECLARE_METHOD(t_String, equalsIgnoreCase, METH_O),
            DECLARE_METHOD(t_String, format, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_String, getBytes, METH_VARARGS),
            DECLARE_METHOD(t_String, getChars, METH_VARARGS),
            DECLARE_METHOD(t_String, hashCode, METH_VARARGS),
            DECLARE_METHOD(t_String, indexOf, METH_VARARGS),
            DECLARE_METHOD(t_String, intern, METH_NOARGS),
            DECLARE_METHOD(t_String, isEmpty, METH_NOARGS),
            DECLARE_METHOD(t_String, lastIndexOf, METH_VARARGS),
            DECLARE_METHOD(t_String, length, METH_NOARGS),
            DECLARE_METHOD(t_String, matches, METH_O),
            DECLARE_METHOD(t_String, offsetByCodePoints, METH_VARARGS),
            DECLARE_METHOD(t_String, regionMatches, METH_VARARGS),
            DECLARE_METHOD(t_String, replace, METH_VARARGS),
            DECLARE_METHOD(t_String, replaceAll, METH_VARARGS),
            DECLARE_METHOD(t_String, replaceFirst, METH_VARARGS),
            DECLARE_METHOD(t_String, split, METH_VARARGS),
            DECLARE_METHOD(t_String, startsWith, METH_VARARGS),
            DECLARE_METHOD(t_String, subSequence, METH_VARARGS),
            DECLARE_METHOD(t_String, substring, METH_VARARGS),
            DECLARE_METHOD(t_String, toCharArray, METH_NOARGS),
            DECLARE_METHOD(t_String, toLowerCase, METH_NOARGS),
            DECLARE_METHOD(t_String, toString, METH_VARARGS),
            DECLARE_METHOD(t_String, toUpperCase, METH_NOARGS),
            DECLARE_METHOD(t_String, trim, METH_NOARGS),
            DECLARE_METHOD(t_String, valueOf, METH_VARARGS | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(String, t_String, ::java::lang::Object, String, t_String_init_, 0, 0, t_String__fields_, 0, 0);

        void t_String::install(PyObject *module)
        {
            installType(&PY_TYPE(String), module, "String", 0);
        }

        void t_String::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(String).tp_dict, "class_", make_descriptor(String::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(String).tp_dict, "wrapfn_", make_descriptor(unboxString));
            PyDict_SetItemString(PY_TYPE(String).tp_dict, "boxfn_", make_descriptor(boxString));
        }

        static PyObject *t_String_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, String::initializeClass, 1)))
                return NULL;
            return t_String::wrap_Object(String(((t_String *) arg)->object.this$));
        }
        static PyObject *t_String_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, String::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_String_init_(t_String *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    String object((jobject) NULL);

                    INT_CALL(object = String());
                    self->object = object;
                    break;
                }
                goto err;
              case 1:
                {
                    JArray< jchar > a0((jobject) NULL);
                    String object((jobject) NULL);

                    if (!parseArgs(args, "[C", &a0))
                    {
                        INT_CALL(object = String(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    JArray< jbyte > a0((jobject) NULL);
                    String object((jobject) NULL);

                    if (!parseArgs(args, "[B", &a0))
                    {
                        INT_CALL(object = String(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::StringBuffer a0((jobject) NULL);
                    String object((jobject) NULL);

                    if (!parseArgs(args, "k", ::java::lang::StringBuffer::initializeClass, &a0))
                    {
                        INT_CALL(object = String(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::StringBuilder a0((jobject) NULL);
                    String object((jobject) NULL);

                    if (!parseArgs(args, "k", ::java::lang::StringBuilder::initializeClass, &a0))
                    {
                        INT_CALL(object = String(a0));
                        self->object = object;
                        break;
                    }
                }
                goto err;
              case 2:
                {
                    JArray< jbyte > a0((jobject) NULL);
                    jint a1;
                    String object((jobject) NULL);

                    if (!parseArgs(args, "[BI", &a0, &a1))
                    {
                        INT_CALL(object = String(a0, a1));
                        self->object = object;
                        break;
                    }
                }
                {
                    JArray< jbyte > a0((jobject) NULL);
                    String a1((jobject) NULL);
                    String object((jobject) NULL);

                    if (!parseArgs(args, "[Bs", &a0, &a1))
                    {
                        INT_CALL(object = String(a0, a1));
                        self->object = object;
                        break;
                    }
                }
                goto err;
              case 3:
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    String object((jobject) NULL);

                    if (!parseArgs(args, "[CII", &a0, &a1, &a2))
                    {
                        INT_CALL(object = String(a0, a1, a2));
                        self->object = object;
                        break;
                    }
                }
                {
                    JArray< jint > a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    String object((jobject) NULL);

                    if (!parseArgs(args, "[III", &a0, &a1, &a2))
                    {
                        INT_CALL(object = String(a0, a1, a2));
                        self->object = object;
                        break;
                    }
                }
                {
                    JArray< jbyte > a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    String object((jobject) NULL);

                    if (!parseArgs(args, "[BII", &a0, &a1, &a2))
                    {
                        INT_CALL(object = String(a0, a1, a2));
                        self->object = object;
                        break;
                    }
                }
                goto err;
              case 4:
                {
                    JArray< jbyte > a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    jint a3;
                    String object((jobject) NULL);

                    if (!parseArgs(args, "[BIII", &a0, &a1, &a2, &a3))
                    {
                        INT_CALL(object = String(a0, a1, a2, a3));
                        self->object = object;
                        break;
                    }
                }
                {
                    JArray< jbyte > a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    String a3((jobject) NULL);
                    String object((jobject) NULL);

                    if (!parseArgs(args, "[BIIs", &a0, &a1, &a2, &a3))
                    {
                        INT_CALL(object = String(a0, a1, a2, a3));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_String_charAt(t_String *self, PyObject *arg)
        {
            jint a0;
            jchar result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = self->object.charAt(a0));
                return PyUnicode_FromUnicode((Py_UNICODE *) &result, 1);
            }

            PyErr_SetArgsError((PyObject *) self, "charAt", arg);
            return NULL;
        }

        static PyObject *t_String_codePointAt(t_String *self, PyObject *arg)
        {
            jint a0;
            jint result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = self->object.codePointAt(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError((PyObject *) self, "codePointAt", arg);
            return NULL;
        }

        static PyObject *t_String_codePointBefore(t_String *self, PyObject *arg)
        {
            jint a0;
            jint result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = self->object.codePointBefore(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError((PyObject *) self, "codePointBefore", arg);
            return NULL;
        }

        static PyObject *t_String_codePointCount(t_String *self, PyObject *args)
        {
            jint a0;
            jint a1;
            jint result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.codePointCount(a0, a1));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError((PyObject *) self, "codePointCount", args);
            return NULL;
        }

        static PyObject *t_String_compareTo(t_String *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::Object a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    String a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "compareTo", args);
            return NULL;
        }

        static PyObject *t_String_compareToIgnoreCase(t_String *self, PyObject *arg)
        {
            String a0((jobject) NULL);
            jint result;

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = self->object.compareToIgnoreCase(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError((PyObject *) self, "compareToIgnoreCase", arg);
            return NULL;
        }

        static PyObject *t_String_concat(t_String *self, PyObject *arg)
        {
            String a0((jobject) NULL);
            String result((jobject) NULL);

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = self->object.concat(a0));
                return j2p(result);
            }

            PyErr_SetArgsError((PyObject *) self, "concat", arg);
            return NULL;
        }

        static PyObject *t_String_contains(t_String *self, PyObject *arg)
        {
            ::java::lang::CharSequence a0((jobject) NULL);
            jboolean result;

            if (!parseArg(arg, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
            {
                OBJ_CALL(result = self->object.contains(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError((PyObject *) self, "contains", arg);
            return NULL;
        }

        static PyObject *t_String_contentEquals(t_String *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    jboolean result;

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
                    {
                        OBJ_CALL(result = self->object.contentEquals(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                {
                    ::java::lang::StringBuffer a0((jobject) NULL);
                    jboolean result;

                    if (!parseArgs(args, "k", ::java::lang::StringBuffer::initializeClass, &a0))
                    {
                        OBJ_CALL(result = self->object.contentEquals(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "contentEquals", args);
            return NULL;
        }

        static PyObject *t_String_copyValueOf(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    JArray< jchar > a0((jobject) NULL);
                    String result((jobject) NULL);

                    if (!parseArgs(args, "[C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::String::copyValueOf(a0));
                        return j2p(result);
                    }
                }
                break;
              case 3:
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    String result((jobject) NULL);

                    if (!parseArgs(args, "[CII", &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = ::java::lang::String::copyValueOf(a0, a1, a2));
                        return j2p(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "copyValueOf", args);
            return NULL;
        }

        static PyObject *t_String_endsWith(t_String *self, PyObject *arg)
        {
            String a0((jobject) NULL);
            jboolean result;

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = self->object.endsWith(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError((PyObject *) self, "endsWith", arg);
            return NULL;
        }

        static PyObject *t_String_equals(t_String *self, PyObject *args)
        {
            ::java::lang::Object a0((jobject) NULL);
            jboolean result;

            if (!parseArgs(args, "o", &a0))
            {
                OBJ_CALL(result = self->object.equals(a0));
                Py_RETURN_BOOL(result);
            }

            return callSuper(&PY_TYPE(String), (PyObject *) self, "equals", args, 2);
        }

        static PyObject *t_String_equalsIgnoreCase(t_String *self, PyObject *arg)
        {
            String a0((jobject) NULL);
            jboolean result;

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = self->object.equalsIgnoreCase(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError((PyObject *) self, "equalsIgnoreCase", arg);
            return NULL;
        }

        static PyObject *t_String_format(PyTypeObject *type, PyObject *args)
        {
            String a0((jobject) NULL);
            JArray< ::java::lang::Object > a1((jobject) NULL);
            String result((jobject) NULL);

            if (!parseArgs(args, "s[o", &a0, &a1))
            {
                OBJ_CALL(result = ::java::lang::String::format(a0, a1));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "format", args);
            return NULL;
        }

        static PyObject *t_String_getBytes(t_String *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    JArray< jbyte > result((jobject) NULL);
                    OBJ_CALL(result = self->object.getBytes());
                    return result.wrap();
                }
                break;
              case 1:
                {
                    String a0((jobject) NULL);
                    JArray< jbyte > result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.getBytes(a0));
                        return result.wrap();
                    }
                }
                break;
              case 4:
                {
                    jint a0;
                    jint a1;
                    JArray< jbyte > a2((jobject) NULL);
                    jint a3;

                    if (!parseArgs(args, "II[BI", &a0, &a1, &a2, &a3))
                    {
                        OBJ_CALL(self->object.getBytes(a0, a1, a2, a3));
                        Py_RETURN_NONE;
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "getBytes", args);
            return NULL;
        }

        static PyObject *t_String_getChars(t_String *self, PyObject *args)
        {
            jint a0;
            jint a1;
            JArray< jchar > a2((jobject) NULL);
            jint a3;

            if (!parseArgs(args, "II[CI", &a0, &a1, &a2, &a3))
            {
                OBJ_CALL(self->object.getChars(a0, a1, a2, a3));
                Py_RETURN_NONE;
            }

            PyErr_SetArgsError((PyObject *) self, "getChars", args);
            return NULL;
        }

        static PyObject *t_String_hashCode(t_String *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.hashCode());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(String), (PyObject *) self, "hashCode", args, 2);
        }

        static PyObject *t_String_indexOf(t_String *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jint result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = self->object.indexOf(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    String a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.indexOf(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                break;
              case 2:
                {
                    String a0((jobject) NULL);
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.indexOf(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    jint a0;
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "II", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.indexOf(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "indexOf", args);
            return NULL;
        }

        static PyObject *t_String_intern(t_String *self)
        {
            String result((jobject) NULL);
            OBJ_CALL(result = self->object.intern());
            return j2p(result);
        }

        static PyObject *t_String_isEmpty(t_String *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isEmpty());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_String_lastIndexOf(t_String *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    jint result;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = self->object.lastIndexOf(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    String a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.lastIndexOf(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                break;
              case 2:
                {
                    jint a0;
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "II", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.lastIndexOf(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    String a0((jobject) NULL);
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.lastIndexOf(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "lastIndexOf", args);
            return NULL;
        }

        static PyObject *t_String_length(t_String *self)
        {
            jint result;
            OBJ_CALL(result = self->object.length());
            return PyInt_FromLong((long) result);
        }

        static PyObject *t_String_matches(t_String *self, PyObject *arg)
        {
            String a0((jobject) NULL);
            jboolean result;

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = self->object.matches(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError((PyObject *) self, "matches", arg);
            return NULL;
        }

        static PyObject *t_String_offsetByCodePoints(t_String *self, PyObject *args)
        {
            jint a0;
            jint a1;
            jint result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.offsetByCodePoints(a0, a1));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError((PyObject *) self, "offsetByCodePoints", args);
            return NULL;
        }

        static PyObject *t_String_regionMatches(t_String *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 4:
                {
                    jint a0;
                    String a1((jobject) NULL);
                    jint a2;
                    jint a3;
                    jboolean result;

                    if (!parseArgs(args, "IsII", &a0, &a1, &a2, &a3))
                    {
                        OBJ_CALL(result = self->object.regionMatches(a0, a1, a2, a3));
                        Py_RETURN_BOOL(result);
                    }
                }
                break;
              case 5:
                {
                    jboolean a0;
                    jint a1;
                    String a2((jobject) NULL);
                    jint a3;
                    jint a4;
                    jboolean result;

                    if (!parseArgs(args, "ZIsII", &a0, &a1, &a2, &a3, &a4))
                    {
                        OBJ_CALL(result = self->object.regionMatches(a0, a1, a2, a3, a4));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "regionMatches", args);
            return NULL;
        }

        static PyObject *t_String_replace(t_String *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 2:
                {
                    jchar a0;
                    jchar a1;
                    String result((jobject) NULL);

                    if (!parseArgs(args, "CC", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.replace(a0, a1));
                        return j2p(result);
                    }
                }
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    ::java::lang::CharSequence a1((jobject) NULL);
                    String result((jobject) NULL);

                    if (!parseArgs(args, "OO", &::java::lang::PY_TYPE(CharSequence), &::java::lang::PY_TYPE(CharSequence), &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.replace(a0, a1));
                        return j2p(result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "replace", args);
            return NULL;
        }

        static PyObject *t_String_replaceAll(t_String *self, PyObject *args)
        {
            String a0((jobject) NULL);
            String a1((jobject) NULL);
            String result((jobject) NULL);

            if (!parseArgs(args, "ss", &a0, &a1))
            {
                OBJ_CALL(result = self->object.replaceAll(a0, a1));
                return j2p(result);
            }

            PyErr_SetArgsError((PyObject *) self, "replaceAll", args);
            return NULL;
        }

        static PyObject *t_String_replaceFirst(t_String *self, PyObject *args)
        {
            String a0((jobject) NULL);
            String a1((jobject) NULL);
            String result((jobject) NULL);

            if (!parseArgs(args, "ss", &a0, &a1))
            {
                OBJ_CALL(result = self->object.replaceFirst(a0, a1));
                return j2p(result);
            }

            PyErr_SetArgsError((PyObject *) self, "replaceFirst", args);
            return NULL;
        }

        static PyObject *t_String_split(t_String *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    String a0((jobject) NULL);
                    JArray< String > result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.split(a0));
                        return JArray<jstring>(result.this$).wrap();
                    }
                }
                break;
              case 2:
                {
                    String a0((jobject) NULL);
                    jint a1;
                    JArray< String > result((jobject) NULL);

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.split(a0, a1));
                        return JArray<jstring>(result.this$).wrap();
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "split", args);
            return NULL;
        }

        static PyObject *t_String_startsWith(t_String *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    String a0((jobject) NULL);
                    jboolean result;

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.startsWith(a0));
                        Py_RETURN_BOOL(result);
                    }
                }
                break;
              case 2:
                {
                    String a0((jobject) NULL);
                    jint a1;
                    jboolean result;

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.startsWith(a0, a1));
                        Py_RETURN_BOOL(result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "startsWith", args);
            return NULL;
        }

        static PyObject *t_String_subSequence(t_String *self, PyObject *args)
        {
            jint a0;
            jint a1;
            ::java::lang::CharSequence result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.subSequence(a0, a1));
                return ::java::lang::t_CharSequence::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "subSequence", args);
            return NULL;
        }

        static PyObject *t_String_substring(t_String *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    String result((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = self->object.substring(a0));
                        return j2p(result);
                    }
                }
                break;
              case 2:
                {
                    jint a0;
                    jint a1;
                    String result((jobject) NULL);

                    if (!parseArgs(args, "II", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.substring(a0, a1));
                        return j2p(result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "substring", args);
            return NULL;
        }

        static PyObject *t_String_toCharArray(t_String *self)
        {
            JArray< jchar > result((jobject) NULL);
            OBJ_CALL(result = self->object.toCharArray());
            return result.wrap();
        }

        static PyObject *t_String_toLowerCase(t_String *self)
        {
            String result((jobject) NULL);
            OBJ_CALL(result = self->object.toLowerCase());
            return j2p(result);
        }

        static PyObject *t_String_toString(t_String *self, PyObject *args)
        {
            String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(String), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_String_toUpperCase(t_String *self)
        {
            String result((jobject) NULL);
            OBJ_CALL(result = self->object.toUpperCase());
            return j2p(result);
        }

        static PyObject *t_String_trim(t_String *self)
        {
            String result((jobject) NULL);
            OBJ_CALL(result = self->object.trim());
            return j2p(result);
        }

        static PyObject *t_String_valueOf(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jboolean a0;
                    String result((jobject) NULL);

                    if (!parseArgs(args, "Z", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::String::valueOf(a0));
                        return j2p(result);
                    }
                }
                {
                    ::java::lang::Object a0((jobject) NULL);
                    String result((jobject) NULL);

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::String::valueOf(a0));
                        return j2p(result);
                    }
                }
                {
                    jfloat a0;
                    String result((jobject) NULL);

                    if (!parseArgs(args, "F", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::String::valueOf(a0));
                        return j2p(result);
                    }
                }
                {
                    jdouble a0;
                    String result((jobject) NULL);

                    if (!parseArgs(args, "D", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::String::valueOf(a0));
                        return j2p(result);
                    }
                }
                {
                    jint a0;
                    String result((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::String::valueOf(a0));
                        return j2p(result);
                    }
                }
                {
                    JArray< jchar > a0((jobject) NULL);
                    String result((jobject) NULL);

                    if (!parseArgs(args, "[C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::String::valueOf(a0));
                        return j2p(result);
                    }
                }
                {
                    jchar a0;
                    String result((jobject) NULL);

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::String::valueOf(a0));
                        return j2p(result);
                    }
                }
                {
                    jlong a0;
                    String result((jobject) NULL);

                    if (!parseArgs(args, "J", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::String::valueOf(a0));
                        return j2p(result);
                    }
                }
                break;
              case 3:
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    String result((jobject) NULL);

                    if (!parseArgs(args, "[CII", &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = ::java::lang::String::valueOf(a0, a1, a2));
                        return j2p(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "valueOf", args);
            return NULL;
        }

        static PyObject *t_String_get__bytes(t_String *self, void *data)
        {
            JArray< jbyte > value((jobject) NULL);
            OBJ_CALL(value = self->object.getBytes());
            return value.wrap();
        }

        static PyObject *t_String_get__empty(t_String *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isEmpty());
            Py_RETURN_BOOL(value);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Float.h"
#include "java/lang/String.h"
#include "java/lang/Comparable.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/Class.h"
#include "java/lang/Object.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Float::class$ = NULL;
        jmethodID *Float::mids$ = NULL;
        jint Float::MAX_EXPONENT = (jint) 0;
        jfloat Float::MAX_VALUE = (jfloat) 0;
        jint Float::MIN_EXPONENT = (jint) 0;
        jfloat Float::MIN_NORMAL = (jfloat) 0;
        jfloat Float::MIN_VALUE = (jfloat) 0;
        jfloat Float::NEGATIVE_INFINITY = (jfloat) 0;
        jfloat Float::NaN = (jfloat) 0;
        jfloat Float::POSITIVE_INFINITY = (jfloat) 0;
        jint Float::SIZE = (jint) 0;
        ::java::lang::Class *Float::TYPE = NULL;

        jclass Float::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Float");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_06298cab] = env->getMethodID(cls, "<init>", "(F)V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_init$_5d1c7645] = env->getMethodID(cls, "<init>", "(D)V");
                mids$[mid_byteValue_54c6a172] = env->getMethodID(cls, "byteValue", "()B");
                mids$[mid_compare_f1b0c01b] = env->getStaticMethodID(cls, "compare", "(FF)I");
                mids$[mid_compareTo_290588f1] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Object;)I");
                mids$[mid_compareTo_6b30eb75] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Float;)I");
                mids$[mid_doubleValue_54c6a174] = env->getMethodID(cls, "doubleValue", "()D");
                mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
                mids$[mid_floatToIntBits_06298cb4] = env->getStaticMethodID(cls, "floatToIntBits", "(F)I");
                mids$[mid_floatToRawIntBits_06298cb4] = env->getStaticMethodID(cls, "floatToRawIntBits", "(F)I");
                mids$[mid_floatValue_54c6a176] = env->getMethodID(cls, "floatValue", "()F");
                mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
                mids$[mid_intBitsToFloat_39c7bd2c] = env->getStaticMethodID(cls, "intBitsToFloat", "(I)F");
                mids$[mid_intValue_54c6a179] = env->getMethodID(cls, "intValue", "()I");
                mids$[mid_isInfinite_54c6a16a] = env->getMethodID(cls, "isInfinite", "()Z");
                mids$[mid_isInfinite_06298ca7] = env->getStaticMethodID(cls, "isInfinite", "(F)Z");
                mids$[mid_isNaN_54c6a16a] = env->getMethodID(cls, "isNaN", "()Z");
                mids$[mid_isNaN_06298ca7] = env->getStaticMethodID(cls, "isNaN", "(F)Z");
                mids$[mid_longValue_54c6a17a] = env->getMethodID(cls, "longValue", "()J");
                mids$[mid_parseFloat_5fdc3f58] = env->getStaticMethodID(cls, "parseFloat", "(Ljava/lang/String;)F");
                mids$[mid_shortValue_54c6a163] = env->getMethodID(cls, "shortValue", "()S");
                mids$[mid_toHexString_5ded254a] = env->getStaticMethodID(cls, "toHexString", "(F)Ljava/lang/String;");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
                mids$[mid_toString_5ded254a] = env->getStaticMethodID(cls, "toString", "(F)Ljava/lang/String;");
                mids$[mid_valueOf_685a245e] = env->getStaticMethodID(cls, "valueOf", "(F)Ljava/lang/Float;");
                mids$[mid_valueOf_b837041d] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Ljava/lang/Float;");

                class$ = (::java::lang::Class *) new JObject(cls);
                cls = (jclass) class$->this$;

                MAX_EXPONENT = env->getStaticIntField(cls, "MAX_EXPONENT");
                MAX_VALUE = env->getStaticFloatField(cls, "MAX_VALUE");
                MIN_EXPONENT = env->getStaticIntField(cls, "MIN_EXPONENT");
                MIN_NORMAL = env->getStaticFloatField(cls, "MIN_NORMAL");
                MIN_VALUE = env->getStaticFloatField(cls, "MIN_VALUE");
                NEGATIVE_INFINITY = env->getStaticFloatField(cls, "NEGATIVE_INFINITY");
                NaN = env->getStaticFloatField(cls, "NaN");
                POSITIVE_INFINITY = env->getStaticFloatField(cls, "POSITIVE_INFINITY");
                SIZE = env->getStaticIntField(cls, "SIZE");
                TYPE = new ::java::lang::Class(env->getStaticObjectField(cls, "TYPE", "Ljava/lang/Class;"));
            }
            return (jclass) class$->this$;
        }

        Float::Float(jfloat a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_06298cab, a0)) {}

        Float::Float(const ::java::lang::String & a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        Float::Float(jdouble a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_5d1c7645, a0)) {}

        jbyte Float::byteValue() const
        {
            return env->callByteMethod(this$, mids$[mid_byteValue_54c6a172]);
        }

        jint Float::compare(jfloat a0, jfloat a1)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_compare_f1b0c01b], a0, a1);
        }

        jint Float::compareTo(const ::java::lang::Object & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_290588f1], a0.this$);
        }

        jint Float::compareTo(const Float & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_6b30eb75], a0.this$);
        }

        jdouble Float::doubleValue() const
        {
            return env->callDoubleMethod(this$, mids$[mid_doubleValue_54c6a174]);
        }

        jboolean Float::equals(const ::java::lang::Object & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
        }

        jint Float::floatToIntBits(jfloat a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_floatToIntBits_06298cb4], a0);
        }

        jint Float::floatToRawIntBits(jfloat a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_floatToRawIntBits_06298cb4], a0);
        }

        jfloat Float::floatValue() const
        {
            return env->callFloatMethod(this$, mids$[mid_floatValue_54c6a176]);
        }

        jint Float::hashCode() const
        {
            return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
        }

        jfloat Float::intBitsToFloat(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticFloatMethod(cls, mids$[mid_intBitsToFloat_39c7bd2c], a0);
        }

        jint Float::intValue() const
        {
            return env->callIntMethod(this$, mids$[mid_intValue_54c6a179]);
        }

        jboolean Float::isInfinite() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isInfinite_54c6a16a]);
        }

        jboolean Float::isInfinite(jfloat a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isInfinite_06298ca7], a0);
        }

        jboolean Float::isNaN() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isNaN_54c6a16a]);
        }

        jboolean Float::isNaN(jfloat a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isNaN_06298ca7], a0);
        }

        jlong Float::longValue() const
        {
            return env->callLongMethod(this$, mids$[mid_longValue_54c6a17a]);
        }

        jfloat Float::parseFloat(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return env->callStaticFloatMethod(cls, mids$[mid_parseFloat_5fdc3f58], a0.this$);
        }

        jshort Float::shortValue() const
        {
            return env->callShortMethod(this$, mids$[mid_shortValue_54c6a163]);
        }

        ::java::lang::String Float::toHexString(jfloat a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toHexString_5ded254a], a0));
        }

        ::java::lang::String Float::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }

        ::java::lang::String Float::toString(jfloat a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_5ded254a], a0));
        }

        Float Float::valueOf(jfloat a0)
        {
            jclass cls = initializeClass();
            return Float(env->callStaticObjectMethod(cls, mids$[mid_valueOf_685a245e], a0));
        }

        Float Float::valueOf(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Float(env->callStaticObjectMethod(cls, mids$[mid_valueOf_b837041d], a0.this$));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Float_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Float_instance_(PyTypeObject *type, PyObject *arg);
        static int t_Float_init_(t_Float *self, PyObject *args, PyObject *kwds);
        static PyObject *t_Float_byteValue(t_Float *self, PyObject *args);
        static PyObject *t_Float_compare(PyTypeObject *type, PyObject *args);
        static PyObject *t_Float_compareTo(t_Float *self, PyObject *args);
        static PyObject *t_Float_doubleValue(t_Float *self, PyObject *args);
        static PyObject *t_Float_equals(t_Float *self, PyObject *args);
        static PyObject *t_Float_floatToIntBits(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Float_floatToRawIntBits(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Float_floatValue(t_Float *self, PyObject *args);
        static PyObject *t_Float_hashCode(t_Float *self, PyObject *args);
        static PyObject *t_Float_intBitsToFloat(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Float_intValue(t_Float *self, PyObject *args);
        static PyObject *t_Float_isInfinite(t_Float *self);
        static PyObject *t_Float_isInfinite_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Float_isNaN(t_Float *self);
        static PyObject *t_Float_isNaN_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Float_longValue(t_Float *self, PyObject *args);
        static PyObject *t_Float_parseFloat(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Float_shortValue(t_Float *self, PyObject *args);
        static PyObject *t_Float_toHexString(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Float_toString(t_Float *self, PyObject *args);
        static PyObject *t_Float_toString_(PyTypeObject *type, PyObject *args);
        static PyObject *t_Float_valueOf(PyTypeObject *type, PyObject *args);
        static PyObject *t_Float_get__infinite(t_Float *self, void *data);
        static PyObject *t_Float_get__naN(t_Float *self, void *data);
        static PyGetSetDef t_Float__fields_[] = {
            DECLARE_GET_FIELD(t_Float, infinite),
            DECLARE_GET_FIELD(t_Float, naN),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_Float__methods_[] = {
            DECLARE_METHOD(t_Float, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Float, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Float, byteValue, METH_VARARGS),
            DECLARE_METHOD(t_Float, compare, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Float, compareTo, METH_VARARGS),
            DECLARE_METHOD(t_Float, doubleValue, METH_VARARGS),
            DECLARE_METHOD(t_Float, equals, METH_VARARGS),
            DECLARE_METHOD(t_Float, floatToIntBits, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Float, floatToRawIntBits, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Float, floatValue, METH_VARARGS),
            DECLARE_METHOD(t_Float, hashCode, METH_VARARGS),
            DECLARE_METHOD(t_Float, intBitsToFloat, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Float, intValue, METH_VARARGS),
            DECLARE_METHOD(t_Float, isInfinite, METH_NOARGS),
            DECLARE_METHOD(t_Float, isInfinite_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Float, isNaN, METH_NOARGS),
            DECLARE_METHOD(t_Float, isNaN_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Float, longValue, METH_VARARGS),
            DECLARE_METHOD(t_Float, parseFloat, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Float, shortValue, METH_VARARGS),
            DECLARE_METHOD(t_Float, toHexString, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Float, toString, METH_VARARGS),
            DECLARE_METHOD(t_Float, toString_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Float, valueOf, METH_VARARGS | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Float, t_Float, ::java::lang::Number, Float, t_Float_init_, 0, 0, t_Float__fields_, 0, 0);

        void t_Float::install(PyObject *module)
        {
            installType(&PY_TYPE(Float), module, "Float", 0);
        }

        void t_Float::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Float).tp_dict, "class_", make_descriptor(Float::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Float).tp_dict, "wrapfn_", make_descriptor(unboxFloat));
            PyDict_SetItemString(PY_TYPE(Float).tp_dict, "boxfn_", make_descriptor(boxFloat));
            Float::initializeClass();
            PyDict_SetItemString(PY_TYPE(Float).tp_dict, "MAX_EXPONENT", make_descriptor(Float::MAX_EXPONENT));
            PyDict_SetItemString(PY_TYPE(Float).tp_dict, "MAX_VALUE", make_descriptor(Float::MAX_VALUE));
            PyDict_SetItemString(PY_TYPE(Float).tp_dict, "MIN_EXPONENT", make_descriptor(Float::MIN_EXPONENT));
            PyDict_SetItemString(PY_TYPE(Float).tp_dict, "MIN_NORMAL", make_descriptor(Float::MIN_NORMAL));
            PyDict_SetItemString(PY_TYPE(Float).tp_dict, "MIN_VALUE", make_descriptor(Float::MIN_VALUE));
            PyDict_SetItemString(PY_TYPE(Float).tp_dict, "NEGATIVE_INFINITY", make_descriptor(Float::NEGATIVE_INFINITY));
            PyDict_SetItemString(PY_TYPE(Float).tp_dict, "NaN", make_descriptor(Float::NaN));
            PyDict_SetItemString(PY_TYPE(Float).tp_dict, "POSITIVE_INFINITY", make_descriptor(Float::POSITIVE_INFINITY));
            PyDict_SetItemString(PY_TYPE(Float).tp_dict, "SIZE", make_descriptor(Float::SIZE));
            PyDict_SetItemString(PY_TYPE(Float).tp_dict, "TYPE", make_descriptor(::java::lang::t_Class::wrap_Object(*Float::TYPE)));
        }

        static PyObject *t_Float_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Float::initializeClass, 1)))
                return NULL;
            return t_Float::wrap_Object(Float(((t_Float *) arg)->object.this$));
        }
        static PyObject *t_Float_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Float::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_Float_init_(t_Float *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jfloat a0;
                    Float object((jobject) NULL);

                    if (!parseArgs(args, "F", &a0))
                    {
                        INT_CALL(object = Float(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Float object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = Float(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    jdouble a0;
                    Float object((jobject) NULL);

                    if (!parseArgs(args, "D", &a0))
                    {
                        INT_CALL(object = Float(a0));
                        self->object = object;
                        break;
                    }
                }
              default:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_Float_byteValue(t_Float *self, PyObject *args)
        {
            jbyte result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.byteValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Float), (PyObject *) self, "byteValue", args, 2);
        }

        static PyObject *t_Float_compare(PyTypeObject *type, PyObject *args)
        {
            jfloat a0;
            jfloat a1;
            jint result;

            if (!parseArgs(args, "FF", &a0, &a1))
            {
                OBJ_CALL(result = ::java::lang::Float::compare(a0, a1));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "compare", args);
            return NULL;
        }

        static PyObject *t_Float_compareTo(t_Float *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::Object a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    Float a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(Float), &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "compareTo", args);
            return NULL;
        }

        static PyObject *t_Float_doubleValue(t_Float *self, PyObject *args)
        {
            jdouble result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.doubleValue());
                return PyFloat_FromDouble((double) result);
            }

            return callSuper(&PY_TYPE(Float), (PyObject *) self, "doubleValue", args, 2);
        }

        static PyObject *t_Float_equals(t_Float *self, PyObject *args)
        {
            ::java::lang::Object a0((jobject) NULL);
            jboolean result;

            if (!parseArgs(args, "o", &a0))
            {
                OBJ_CALL(result = self->object.equals(a0));
                Py_RETURN_BOOL(result);
            }

            return callSuper(&PY_TYPE(Float), (PyObject *) self, "equals", args, 2);
        }

        static PyObject *t_Float_floatToIntBits(PyTypeObject *type, PyObject *arg)
        {
            jfloat a0;
            jint result;

            if (!parseArg(arg, "F", &a0))
            {
                OBJ_CALL(result = ::java::lang::Float::floatToIntBits(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "floatToIntBits", arg);
            return NULL;
        }

        static PyObject *t_Float_floatToRawIntBits(PyTypeObject *type, PyObject *arg)
        {
            jfloat a0;
            jint result;

            if (!parseArg(arg, "F", &a0))
            {
                OBJ_CALL(result = ::java::lang::Float::floatToRawIntBits(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "floatToRawIntBits", arg);
            return NULL;
        }

        static PyObject *t_Float_floatValue(t_Float *self, PyObject *args)
        {
            jfloat result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.floatValue());
                return PyFloat_FromDouble((double) result);
            }

            return callSuper(&PY_TYPE(Float), (PyObject *) self, "floatValue", args, 2);
        }

        static PyObject *t_Float_hashCode(t_Float *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.hashCode());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Float), (PyObject *) self, "hashCode", args, 2);
        }

        static PyObject *t_Float_intBitsToFloat(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            jfloat result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Float::intBitsToFloat(a0));
                return PyFloat_FromDouble((double) result);
            }

            PyErr_SetArgsError(type, "intBitsToFloat", arg);
            return NULL;
        }

        static PyObject *t_Float_intValue(t_Float *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.intValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Float), (PyObject *) self, "intValue", args, 2);
        }

        static PyObject *t_Float_isInfinite(t_Float *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isInfinite());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Float_isInfinite_(PyTypeObject *type, PyObject *arg)
        {
            jfloat a0;
            jboolean result;

            if (!parseArg(arg, "F", &a0))
            {
                OBJ_CALL(result = ::java::lang::Float::isInfinite(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError(type, "isInfinite_", arg);
            return NULL;
        }

        static PyObject *t_Float_isNaN(t_Float *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isNaN());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Float_isNaN_(PyTypeObject *type, PyObject *arg)
        {
            jfloat a0;
            jboolean result;

            if (!parseArg(arg, "F", &a0))
            {
                OBJ_CALL(result = ::java::lang::Float::isNaN(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError(type, "isNaN_", arg);
            return NULL;
        }

        static PyObject *t_Float_longValue(t_Float *self, PyObject *args)
        {
            jlong result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.longValue());
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            return callSuper(&PY_TYPE(Float), (PyObject *) self, "longValue", args, 2);
        }

        static PyObject *t_Float_parseFloat(PyTypeObject *type, PyObject *arg)
        {
            ::java::lang::String a0((jobject) NULL);
            jfloat result;

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = ::java::lang::Float::parseFloat(a0));
                return PyFloat_FromDouble((double) result);
            }

            PyErr_SetArgsError(type, "parseFloat", arg);
            return NULL;
        }

        static PyObject *t_Float_shortValue(t_Float *self, PyObject *args)
        {
            jshort result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.shortValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Float), (PyObject *) self, "shortValue", args, 2);
        }

        static PyObject *t_Float_toHexString(PyTypeObject *type, PyObject *arg)
        {
            jfloat a0;
            ::java::lang::String result((jobject) NULL);

            if (!parseArg(arg, "F", &a0))
            {
                OBJ_CALL(result = ::java::lang::Float::toHexString(a0));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "toHexString", arg);
            return NULL;
        }

        static PyObject *t_Float_toString(t_Float *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(Float), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_Float_toString_(PyTypeObject *type, PyObject *args)
        {
            jfloat a0;
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, "F", &a0))
            {
                OBJ_CALL(result = ::java::lang::Float::toString(a0));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "toString_", args);
            return NULL;
        }

        static PyObject *t_Float_valueOf(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jfloat a0;
                    Float result((jobject) NULL);

                    if (!parseArgs(args, "F", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Float::valueOf(a0));
                        return t_Float::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Float result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Float::valueOf(a0));
                        return t_Float::wrap_Object(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "valueOf", args);
            return NULL;
        }

        static PyObject *t_Float_get__infinite(t_Float *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isInfinite());
            Py_RETURN_BOOL(value);
        }

        static PyObject *t_Float_get__naN(t_Float *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isNaN());
            Py_RETURN_BOOL(value);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Throwable.h"
#include "java/io/PrintWriter.h"
#include "java/lang/String.h"
#include "java/lang/StackTraceElement.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Throwable::class$ = NULL;
        jmethodID *Throwable::mids$ = NULL;

        jclass Throwable::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Throwable");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_init$_01646a2e] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");
                mids$[mid_fillInStackTrace_9a29189d] = env->getMethodID(cls, "fillInStackTrace", "()Ljava/lang/Throwable;");
                mids$[mid_getCause_9a29189d] = env->getMethodID(cls, "getCause", "()Ljava/lang/Throwable;");
                mids$[mid_getLocalizedMessage_14c7b5c5] = env->getMethodID(cls, "getLocalizedMessage", "()Ljava/lang/String;");
                mids$[mid_getMessage_14c7b5c5] = env->getMethodID(cls, "getMessage", "()Ljava/lang/String;");
                mids$[mid_getStackTrace_25f1f6aa] = env->getMethodID(cls, "getStackTrace", "()[Ljava/lang/StackTraceElement;");
                mids$[mid_initCause_dabad90f] = env->getMethodID(cls, "initCause", "(Ljava/lang/Throwable;)Ljava/lang/Throwable;");
                mids$[mid_printStackTrace_54c6a166] = env->getMethodID(cls, "printStackTrace", "()V");
                mids$[mid_printStackTrace_82fffd94] = env->getMethodID(cls, "printStackTrace", "(Ljava/io/PrintWriter;)V");
                mids$[mid_setStackTrace_3d8798bf] = env->getMethodID(cls, "setStackTrace", "([Ljava/lang/StackTraceElement;)V");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        Throwable::Throwable() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        Throwable::Throwable(const ::java::lang::String & a0) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        Throwable::Throwable(const ::java::lang::String & a0, const Throwable & a1) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_01646a2e, a0.this$, a1.this$)) {}

        Throwable Throwable::fillInStackTrace() const
        {
            return Throwable(env->callObjectMethod(this$, mids$[mid_fillInStackTrace_9a29189d]));
        }

        Throwable Throwable::getCause() const
        {
            return Throwable(env->callObjectMethod(this$, mids$[mid_getCause_9a29189d]));
        }

        ::java::lang::String Throwable::getLocalizedMessage() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getLocalizedMessage_14c7b5c5]));
        }

        ::java::lang::String Throwable::getMessage() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getMessage_14c7b5c5]));
        }

        JArray< ::java::lang::StackTraceElement > Throwable::getStackTrace() const
        {
            return JArray< ::java::lang::StackTraceElement >(env->callObjectMethod(this$, mids$[mid_getStackTrace_25f1f6aa]));
        }

        Throwable Throwable::initCause(const Throwable & a0) const
        {
            return Throwable(env->callObjectMethod(this$, mids$[mid_initCause_dabad90f], a0.this$));
        }

        void Throwable::printStackTrace() const
        {
            env->callVoidMethod(this$, mids$[mid_printStackTrace_54c6a166]);
        }

        void Throwable::printStackTrace(const ::java::io::PrintWriter & a0) const
        {
            env->callVoidMethod(this$, mids$[mid_printStackTrace_82fffd94], a0.this$);
        }

        void Throwable::setStackTrace(const JArray< ::java::lang::StackTraceElement > & a0) const
        {
            env->callVoidMethod(this$, mids$[mid_setStackTrace_3d8798bf], a0.this$);
        }

        ::java::lang::String Throwable::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Throwable_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Throwable_instance_(PyTypeObject *type, PyObject *arg);
        static int t_Throwable_init_(t_Throwable *self, PyObject *args, PyObject *kwds);
        static PyObject *t_Throwable_fillInStackTrace(t_Throwable *self);
        static PyObject *t_Throwable_getCause(t_Throwable *self);
        static PyObject *t_Throwable_getLocalizedMessage(t_Throwable *self);
        static PyObject *t_Throwable_getMessage(t_Throwable *self);
        static PyObject *t_Throwable_getStackTrace(t_Throwable *self);
        static PyObject *t_Throwable_initCause(t_Throwable *self, PyObject *arg);
        static PyObject *t_Throwable_printStackTrace(t_Throwable *self, PyObject *args);
        static PyObject *t_Throwable_setStackTrace(t_Throwable *self, PyObject *arg);
        static PyObject *t_Throwable_toString(t_Throwable *self, PyObject *args);
        static PyObject *t_Throwable_get__cause(t_Throwable *self, void *data);
        static PyObject *t_Throwable_get__localizedMessage(t_Throwable *self, void *data);
        static PyObject *t_Throwable_get__message(t_Throwable *self, void *data);
        static PyObject *t_Throwable_get__stackTrace(t_Throwable *self, void *data);
        static int t_Throwable_set__stackTrace(t_Throwable *self, PyObject *arg, void *data);
        static PyGetSetDef t_Throwable__fields_[] = {
            DECLARE_GET_FIELD(t_Throwable, cause),
            DECLARE_GET_FIELD(t_Throwable, localizedMessage),
            DECLARE_GET_FIELD(t_Throwable, message),
            DECLARE_GETSET_FIELD(t_Throwable, stackTrace),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_Throwable__methods_[] = {
            DECLARE_METHOD(t_Throwable, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Throwable, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Throwable, fillInStackTrace, METH_NOARGS),
            DECLARE_METHOD(t_Throwable, getCause, METH_NOARGS),
            DECLARE_METHOD(t_Throwable, getLocalizedMessage, METH_NOARGS),
            DECLARE_METHOD(t_Throwable, getMessage, METH_NOARGS),
            DECLARE_METHOD(t_Throwable, getStackTrace, METH_NOARGS),
            DECLARE_METHOD(t_Throwable, initCause, METH_O),
            DECLARE_METHOD(t_Throwable, printStackTrace, METH_VARARGS),
            DECLARE_METHOD(t_Throwable, setStackTrace, METH_O),
            DECLARE_METHOD(t_Throwable, toString, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Throwable, t_Throwable, ::java::lang::Object, Throwable, t_Throwable_init_, 0, 0, t_Throwable__fields_, 0, 0);

        void t_Throwable::install(PyObject *module)
        {
            installType(&PY_TYPE(Throwable), module, "Throwable", 0);
        }

        void t_Throwable::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Throwable).tp_dict, "class_", make_descriptor(Throwable::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Throwable).tp_dict, "wrapfn_", make_descriptor(t_Throwable::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(Throwable).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_Throwable_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Throwable::initializeClass, 1)))
                return NULL;
            return t_Throwable::wrap_Object(Throwable(((t_Throwable *) arg)->object.this$));
        }
        static PyObject *t_Throwable_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Throwable::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_Throwable_init_(t_Throwable *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    Throwable object((jobject) NULL);

                    INT_CALL(object = Throwable());
                    self->object = object;
                    break;
                }
                goto err;
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    Throwable object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = Throwable(a0));
                        self->object = object;
                        break;
                    }
                }
                goto err;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    Throwable a1((jobject) NULL);
                    Throwable object((jobject) NULL);

                    if (!parseArgs(args, "sk", Throwable::initializeClass, &a0, &a1))
                    {
                        INT_CALL(object = Throwable(a0, a1));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_Throwable_fillInStackTrace(t_Throwable *self)
        {
            Throwable result((jobject) NULL);
            OBJ_CALL(result = self->object.fillInStackTrace());
            return t_Throwable::wrap_Object(result);
        }

        static PyObject *t_Throwable_getCause(t_Throwable *self)
        {
            Throwable result((jobject) NULL);
            OBJ_CALL(result = self->object.getCause());
            return t_Throwable::wrap_Object(result);
        }

        static PyObject *t_Throwable_getLocalizedMessage(t_Throwable *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getLocalizedMessage());
            return j2p(result);
        }

        static PyObject *t_Throwable_getMessage(t_Throwable *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getMessage());
            return j2p(result);
        }

        static PyObject *t_Throwable_getStackTrace(t_Throwable *self)
        {
            JArray< ::java::lang::StackTraceElement > result((jobject) NULL);
            OBJ_CALL(result = self->object.getStackTrace());
            return JArray<jobject>(result.this$).wrap(::java::lang::t_StackTraceElement::wrap_jobject);
        }

        static PyObject *t_Throwable_initCause(t_Throwable *self, PyObject *arg)
        {
            Throwable a0((jobject) NULL);
            Throwable result((jobject) NULL);

            if (!parseArg(arg, "k", Throwable::initializeClass, &a0))
            {
                OBJ_CALL(result = self->object.initCause(a0));
                return t_Throwable::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "initCause", arg);
            return NULL;
        }

        static PyObject *t_Throwable_printStackTrace(t_Throwable *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    OBJ_CALL(self->object.printStackTrace());
                    Py_RETURN_NONE;
                }
                break;
              case 1:
                {
                    ::java::io::PrintWriter a0((jobject) NULL);

                    if (!parseArgs(args, "k", ::java::io::PrintWriter::initializeClass, &a0))
                    {
                        OBJ_CALL(self->object.printStackTrace(a0));
                        Py_RETURN_NONE;
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "printStackTrace", args);
            return NULL;
        }

        static PyObject *t_Throwable_setStackTrace(t_Throwable *self, PyObject *arg)
        {
            JArray< ::java::lang::StackTraceElement > a0((jobject) NULL);

            if (!parseArg(arg, "[k", ::java::lang::StackTraceElement::initializeClass, &a0))
            {
                OBJ_CALL(self->object.setStackTrace(a0));
                Py_RETURN_NONE;
            }

            PyErr_SetArgsError((PyObject *) self, "setStackTrace", arg);
            return NULL;
        }

        static PyObject *t_Throwable_toString(t_Throwable *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(Throwable), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_Throwable_get__cause(t_Throwable *self, void *data)
        {
            Throwable value((jobject) NULL);
            OBJ_CALL(value = self->object.getCause());
            return t_Throwable::wrap_Object(value);
        }

        static PyObject *t_Throwable_get__localizedMessage(t_Throwable *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getLocalizedMessage());
            return j2p(value);
        }

        static PyObject *t_Throwable_get__message(t_Throwable *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getMessage());
            return j2p(value);
        }

        static PyObject *t_Throwable_get__stackTrace(t_Throwable *self, void *data)
        {
            JArray< ::java::lang::StackTraceElement > value((jobject) NULL);
            OBJ_CALL(value = self->object.getStackTrace());
            return JArray<jobject>(value.this$).wrap(::java::lang::t_StackTraceElement::wrap_jobject);
        }
        static int t_Throwable_set__stackTrace(t_Throwable *self, PyObject *arg, void *data)
        {
            {
                JArray< ::java::lang::StackTraceElement > value((jobject) NULL);
                if (!parseArg(arg, "[k", ::java::lang::StackTraceElement::initializeClass, &value))
                {
                    INT_CALL(self->object.setStackTrace(value));
                    return 0;
                }
            }
            PyErr_SetArgsError((PyObject *) self, "stackTrace", arg);
            return -1;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Double.h"
#include "java/lang/String.h"
#include "java/lang/Comparable.h"
#include "java/lang/Object.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Double::class$ = NULL;
        jmethodID *Double::mids$ = NULL;
        jint Double::MAX_EXPONENT = (jint) 0;
        jdouble Double::MAX_VALUE = (jdouble) 0;
        jint Double::MIN_EXPONENT = (jint) 0;
        jdouble Double::MIN_NORMAL = (jdouble) 0;
        jdouble Double::MIN_VALUE = (jdouble) 0;
        jdouble Double::NEGATIVE_INFINITY = (jdouble) 0;
        jdouble Double::NaN = (jdouble) 0;
        jdouble Double::POSITIVE_INFINITY = (jdouble) 0;
        jint Double::SIZE = (jint) 0;
        ::java::lang::Class *Double::TYPE = NULL;

        jclass Double::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Double");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_5d1c7645] = env->getMethodID(cls, "<init>", "(D)V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_byteValue_54c6a172] = env->getMethodID(cls, "byteValue", "()B");
                mids$[mid_compare_b1e28667] = env->getStaticMethodID(cls, "compare", "(DD)I");
                mids$[mid_compareTo_290588f1] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Object;)I");
                mids$[mid_compareTo_8baed073] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Double;)I");
                mids$[mid_doubleToLongBits_5d1c7659] = env->getStaticMethodID(cls, "doubleToLongBits", "(D)J");
                mids$[mid_doubleToRawLongBits_5d1c7659] = env->getStaticMethodID(cls, "doubleToRawLongBits", "(D)J");
                mids$[mid_doubleValue_54c6a174] = env->getMethodID(cls, "doubleValue", "()D");
                mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
                mids$[mid_floatValue_54c6a176] = env->getMethodID(cls, "floatValue", "()F");
                mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
                mids$[mid_intValue_54c6a179] = env->getMethodID(cls, "intValue", "()I");
                mids$[mid_isInfinite_54c6a16a] = env->getMethodID(cls, "isInfinite", "()Z");
                mids$[mid_isInfinite_5d1c7649] = env->getStaticMethodID(cls, "isInfinite", "(D)Z");
                mids$[mid_isNaN_54c6a16a] = env->getMethodID(cls, "isNaN", "()Z");
                mids$[mid_isNaN_5d1c7649] = env->getStaticMethodID(cls, "isNaN", "(D)Z");
                mids$[mid_longBitsToDouble_0ee6df3d] = env->getStaticMethodID(cls, "longBitsToDouble", "(J)D");
                mids$[mid_longValue_54c6a17a] = env->getMethodID(cls, "longValue", "()J");
                mids$[mid_parseDouble_5fdc3f5a] = env->getStaticMethodID(cls, "parseDouble", "(Ljava/lang/String;)D");
                mids$[mid_shortValue_54c6a163] = env->getMethodID(cls, "shortValue", "()S");
                mids$[mid_toHexString_1b4624f8] = env->getStaticMethodID(cls, "toHexString", "(D)Ljava/lang/String;");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
                mids$[mid_toString_1b4624f8] = env->getStaticMethodID(cls, "toString", "(D)Ljava/lang/String;");
                mids$[mid_valueOf_ad1fcbf0] = env->getStaticMethodID(cls, "valueOf", "(D)Ljava/lang/Double;");
                mids$[mid_valueOf_16296787] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Ljava/lang/Double;");

                class$ = (::java::lang::Class *) new JObject(cls);
                cls = (jclass) class$->this$;

                MAX_EXPONENT = env->getStaticIntField(cls, "MAX_EXPONENT");
                MAX_VALUE = env->getStaticDoubleField(cls, "MAX_VALUE");
                MIN_EXPONENT = env->getStaticIntField(cls, "MIN_EXPONENT");
                MIN_NORMAL = env->getStaticDoubleField(cls, "MIN_NORMAL");
                MIN_VALUE = env->getStaticDoubleField(cls, "MIN_VALUE");
                NEGATIVE_INFINITY = env->getStaticDoubleField(cls, "NEGATIVE_INFINITY");
                NaN = env->getStaticDoubleField(cls, "NaN");
                POSITIVE_INFINITY = env->getStaticDoubleField(cls, "POSITIVE_INFINITY");
                SIZE = env->getStaticIntField(cls, "SIZE");
                TYPE = new ::java::lang::Class(env->getStaticObjectField(cls, "TYPE", "Ljava/lang/Class;"));
            }
            return (jclass) class$->this$;
        }

        Double::Double(jdouble a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_5d1c7645, a0)) {}

        Double::Double(const ::java::lang::String & a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        jbyte Double::byteValue() const
        {
            return env->callByteMethod(this$, mids$[mid_byteValue_54c6a172]);
        }

        jint Double::compare(jdouble a0, jdouble a1)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_compare_b1e28667], a0, a1);
        }

        jint Double::compareTo(const ::java::lang::Object & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_290588f1], a0.this$);
        }

        jint Double::compareTo(const Double & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_8baed073], a0.this$);
        }

        jlong Double::doubleToLongBits(jdouble a0)
        {
            jclass cls = initializeClass();
            return env->callStaticLongMethod(cls, mids$[mid_doubleToLongBits_5d1c7659], a0);
        }

        jlong Double::doubleToRawLongBits(jdouble a0)
        {
            jclass cls = initializeClass();
            return env->callStaticLongMethod(cls, mids$[mid_doubleToRawLongBits_5d1c7659], a0);
        }

        jdouble Double::doubleValue() const
        {
            return env->callDoubleMethod(this$, mids$[mid_doubleValue_54c6a174]);
        }

        jboolean Double::equals(const ::java::lang::Object & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
        }

        jfloat Double::floatValue() const
        {
            return env->callFloatMethod(this$, mids$[mid_floatValue_54c6a176]);
        }

        jint Double::hashCode() const
        {
            return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
        }

        jint Double::intValue() const
        {
            return env->callIntMethod(this$, mids$[mid_intValue_54c6a179]);
        }

        jboolean Double::isInfinite() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isInfinite_54c6a16a]);
        }

        jboolean Double::isInfinite(jdouble a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isInfinite_5d1c7649], a0);
        }

        jboolean Double::isNaN() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isNaN_54c6a16a]);
        }

        jboolean Double::isNaN(jdouble a0)
        {
            jclass cls = initializeClass();
            return env->callStaticBooleanMethod(cls, mids$[mid_isNaN_5d1c7649], a0);
        }

        jdouble Double::longBitsToDouble(jlong a0)
        {
            jclass cls = initializeClass();
            return env->callStaticDoubleMethod(cls, mids$[mid_longBitsToDouble_0ee6df3d], a0);
        }

        jlong Double::longValue() const
        {
            return env->callLongMethod(this$, mids$[mid_longValue_54c6a17a]);
        }

        jdouble Double::parseDouble(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return env->callStaticDoubleMethod(cls, mids$[mid_parseDouble_5fdc3f5a], a0.this$);
        }

        jshort Double::shortValue() const
        {
            return env->callShortMethod(this$, mids$[mid_shortValue_54c6a163]);
        }

        ::java::lang::String Double::toHexString(jdouble a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toHexString_1b4624f8], a0));
        }

        ::java::lang::String Double::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }

        ::java::lang::String Double::toString(jdouble a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_1b4624f8], a0));
        }

        Double Double::valueOf(jdouble a0)
        {
            jclass cls = initializeClass();
            return Double(env->callStaticObjectMethod(cls, mids$[mid_valueOf_ad1fcbf0], a0));
        }

        Double Double::valueOf(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Double(env->callStaticObjectMethod(cls, mids$[mid_valueOf_16296787], a0.this$));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Double_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Double_instance_(PyTypeObject *type, PyObject *arg);
        static int t_Double_init_(t_Double *self, PyObject *args, PyObject *kwds);
        static PyObject *t_Double_byteValue(t_Double *self, PyObject *args);
        static PyObject *t_Double_compare(PyTypeObject *type, PyObject *args);
        static PyObject *t_Double_compareTo(t_Double *self, PyObject *args);
        static PyObject *t_Double_doubleToLongBits(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Double_doubleToRawLongBits(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Double_doubleValue(t_Double *self, PyObject *args);
        static PyObject *t_Double_equals(t_Double *self, PyObject *args);
        static PyObject *t_Double_floatValue(t_Double *self, PyObject *args);
        static PyObject *t_Double_hashCode(t_Double *self, PyObject *args);
        static PyObject *t_Double_intValue(t_Double *self, PyObject *args);
        static PyObject *t_Double_isInfinite(t_Double *self);
        static PyObject *t_Double_isInfinite_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Double_isNaN(t_Double *self);
        static PyObject *t_Double_isNaN_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Double_longBitsToDouble(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Double_longValue(t_Double *self, PyObject *args);
        static PyObject *t_Double_parseDouble(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Double_shortValue(t_Double *self, PyObject *args);
        static PyObject *t_Double_toHexString(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Double_toString(t_Double *self, PyObject *args);
        static PyObject *t_Double_toString_(PyTypeObject *type, PyObject *args);
        static PyObject *t_Double_valueOf(PyTypeObject *type, PyObject *args);
        static PyObject *t_Double_get__infinite(t_Double *self, void *data);
        static PyObject *t_Double_get__naN(t_Double *self, void *data);
        static PyGetSetDef t_Double__fields_[] = {
            DECLARE_GET_FIELD(t_Double, infinite),
            DECLARE_GET_FIELD(t_Double, naN),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_Double__methods_[] = {
            DECLARE_METHOD(t_Double, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Double, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Double, byteValue, METH_VARARGS),
            DECLARE_METHOD(t_Double, compare, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Double, compareTo, METH_VARARGS),
            DECLARE_METHOD(t_Double, doubleToLongBits, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Double, doubleToRawLongBits, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Double, doubleValue, METH_VARARGS),
            DECLARE_METHOD(t_Double, equals, METH_VARARGS),
            DECLARE_METHOD(t_Double, floatValue, METH_VARARGS),
            DECLARE_METHOD(t_Double, hashCode, METH_VARARGS),
            DECLARE_METHOD(t_Double, intValue, METH_VARARGS),
            DECLARE_METHOD(t_Double, isInfinite, METH_NOARGS),
            DECLARE_METHOD(t_Double, isInfinite_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Double, isNaN, METH_NOARGS),
            DECLARE_METHOD(t_Double, isNaN_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Double, longBitsToDouble, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Double, longValue, METH_VARARGS),
            DECLARE_METHOD(t_Double, parseDouble, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Double, shortValue, METH_VARARGS),
            DECLARE_METHOD(t_Double, toHexString, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Double, toString, METH_VARARGS),
            DECLARE_METHOD(t_Double, toString_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Double, valueOf, METH_VARARGS | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Double, t_Double, ::java::lang::Number, Double, t_Double_init_, 0, 0, t_Double__fields_, 0, 0);

        void t_Double::install(PyObject *module)
        {
            installType(&PY_TYPE(Double), module, "Double", 0);
        }

        void t_Double::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Double).tp_dict, "class_", make_descriptor(Double::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Double).tp_dict, "wrapfn_", make_descriptor(unboxDouble));
            PyDict_SetItemString(PY_TYPE(Double).tp_dict, "boxfn_", make_descriptor(boxDouble));
            Double::initializeClass();
            PyDict_SetItemString(PY_TYPE(Double).tp_dict, "MAX_EXPONENT", make_descriptor(Double::MAX_EXPONENT));
            PyDict_SetItemString(PY_TYPE(Double).tp_dict, "MAX_VALUE", make_descriptor(Double::MAX_VALUE));
            PyDict_SetItemString(PY_TYPE(Double).tp_dict, "MIN_EXPONENT", make_descriptor(Double::MIN_EXPONENT));
            PyDict_SetItemString(PY_TYPE(Double).tp_dict, "MIN_NORMAL", make_descriptor(Double::MIN_NORMAL));
            PyDict_SetItemString(PY_TYPE(Double).tp_dict, "MIN_VALUE", make_descriptor(Double::MIN_VALUE));
            PyDict_SetItemString(PY_TYPE(Double).tp_dict, "NEGATIVE_INFINITY", make_descriptor(Double::NEGATIVE_INFINITY));
            PyDict_SetItemString(PY_TYPE(Double).tp_dict, "NaN", make_descriptor(Double::NaN));
            PyDict_SetItemString(PY_TYPE(Double).tp_dict, "POSITIVE_INFINITY", make_descriptor(Double::POSITIVE_INFINITY));
            PyDict_SetItemString(PY_TYPE(Double).tp_dict, "SIZE", make_descriptor(Double::SIZE));
            PyDict_SetItemString(PY_TYPE(Double).tp_dict, "TYPE", make_descriptor(::java::lang::t_Class::wrap_Object(*Double::TYPE)));
        }

        static PyObject *t_Double_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Double::initializeClass, 1)))
                return NULL;
            return t_Double::wrap_Object(Double(((t_Double *) arg)->object.this$));
        }
        static PyObject *t_Double_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Double::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_Double_init_(t_Double *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jdouble a0;
                    Double object((jobject) NULL);

                    if (!parseArgs(args, "D", &a0))
                    {
                        INT_CALL(object = Double(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Double object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = Double(a0));
                        self->object = object;
                        break;
                    }
                }
              default:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_Double_byteValue(t_Double *self, PyObject *args)
        {
            jbyte result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.byteValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Double), (PyObject *) self, "byteValue", args, 2);
        }

        static PyObject *t_Double_compare(PyTypeObject *type, PyObject *args)
        {
            jdouble a0;
            jdouble a1;
            jint result;

            if (!parseArgs(args, "DD", &a0, &a1))
            {
                OBJ_CALL(result = ::java::lang::Double::compare(a0, a1));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "compare", args);
            return NULL;
        }

        static PyObject *t_Double_compareTo(t_Double *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::Object a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    Double a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(Double), &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "compareTo", args);
            return NULL;
        }

        static PyObject *t_Double_doubleToLongBits(PyTypeObject *type, PyObject *arg)
        {
            jdouble a0;
            jlong result;

            if (!parseArg(arg, "D", &a0))
            {
                OBJ_CALL(result = ::java::lang::Double::doubleToLongBits(a0));
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            PyErr_SetArgsError(type, "doubleToLongBits", arg);
            return NULL;
        }

        static PyObject *t_Double_doubleToRawLongBits(PyTypeObject *type, PyObject *arg)
        {
            jdouble a0;
            jlong result;

            if (!parseArg(arg, "D", &a0))
            {
                OBJ_CALL(result = ::java::lang::Double::doubleToRawLongBits(a0));
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            PyErr_SetArgsError(type, "doubleToRawLongBits", arg);
            return NULL;
        }

        static PyObject *t_Double_doubleValue(t_Double *self, PyObject *args)
        {
            jdouble result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.doubleValue());
                return PyFloat_FromDouble((double) result);
            }

            return callSuper(&PY_TYPE(Double), (PyObject *) self, "doubleValue", args, 2);
        }

        static PyObject *t_Double_equals(t_Double *self, PyObject *args)
        {
            ::java::lang::Object a0((jobject) NULL);
            jboolean result;

            if (!parseArgs(args, "o", &a0))
            {
                OBJ_CALL(result = self->object.equals(a0));
                Py_RETURN_BOOL(result);
            }

            return callSuper(&PY_TYPE(Double), (PyObject *) self, "equals", args, 2);
        }

        static PyObject *t_Double_floatValue(t_Double *self, PyObject *args)
        {
            jfloat result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.floatValue());
                return PyFloat_FromDouble((double) result);
            }

            return callSuper(&PY_TYPE(Double), (PyObject *) self, "floatValue", args, 2);
        }

        static PyObject *t_Double_hashCode(t_Double *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.hashCode());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Double), (PyObject *) self, "hashCode", args, 2);
        }

        static PyObject *t_Double_intValue(t_Double *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.intValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Double), (PyObject *) self, "intValue", args, 2);
        }

        static PyObject *t_Double_isInfinite(t_Double *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isInfinite());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Double_isInfinite_(PyTypeObject *type, PyObject *arg)
        {
            jdouble a0;
            jboolean result;

            if (!parseArg(arg, "D", &a0))
            {
                OBJ_CALL(result = ::java::lang::Double::isInfinite(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError(type, "isInfinite_", arg);
            return NULL;
        }

        static PyObject *t_Double_isNaN(t_Double *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isNaN());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Double_isNaN_(PyTypeObject *type, PyObject *arg)
        {
            jdouble a0;
            jboolean result;

            if (!parseArg(arg, "D", &a0))
            {
                OBJ_CALL(result = ::java::lang::Double::isNaN(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError(type, "isNaN_", arg);
            return NULL;
        }

        static PyObject *t_Double_longBitsToDouble(PyTypeObject *type, PyObject *arg)
        {
            jlong a0;
            jdouble result;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = ::java::lang::Double::longBitsToDouble(a0));
                return PyFloat_FromDouble((double) result);
            }

            PyErr_SetArgsError(type, "longBitsToDouble", arg);
            return NULL;
        }

        static PyObject *t_Double_longValue(t_Double *self, PyObject *args)
        {
            jlong result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.longValue());
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            return callSuper(&PY_TYPE(Double), (PyObject *) self, "longValue", args, 2);
        }

        static PyObject *t_Double_parseDouble(PyTypeObject *type, PyObject *arg)
        {
            ::java::lang::String a0((jobject) NULL);
            jdouble result;

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = ::java::lang::Double::parseDouble(a0));
                return PyFloat_FromDouble((double) result);
            }

            PyErr_SetArgsError(type, "parseDouble", arg);
            return NULL;
        }

        static PyObject *t_Double_shortValue(t_Double *self, PyObject *args)
        {
            jshort result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.shortValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Double), (PyObject *) self, "shortValue", args, 2);
        }

        static PyObject *t_Double_toHexString(PyTypeObject *type, PyObject *arg)
        {
            jdouble a0;
            ::java::lang::String result((jobject) NULL);

            if (!parseArg(arg, "D", &a0))
            {
                OBJ_CALL(result = ::java::lang::Double::toHexString(a0));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "toHexString", arg);
            return NULL;
        }

        static PyObject *t_Double_toString(t_Double *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(Double), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_Double_toString_(PyTypeObject *type, PyObject *args)
        {
            jdouble a0;
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, "D", &a0))
            {
                OBJ_CALL(result = ::java::lang::Double::toString(a0));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "toString_", args);
            return NULL;
        }

        static PyObject *t_Double_valueOf(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jdouble a0;
                    Double result((jobject) NULL);

                    if (!parseArgs(args, "D", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Double::valueOf(a0));
                        return t_Double::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Double result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Double::valueOf(a0));
                        return t_Double::wrap_Object(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "valueOf", args);
            return NULL;
        }

        static PyObject *t_Double_get__infinite(t_Double *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isInfinite());
            Py_RETURN_BOOL(value);
        }

        static PyObject *t_Double_get__naN(t_Double *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isNaN());
            Py_RETURN_BOOL(value);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Exception.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Exception::class$ = NULL;
        jmethodID *Exception::mids$ = NULL;

        jclass Exception::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Exception");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_init$_c5ec8ca4] = env->getMethodID(cls, "<init>", "(Ljava/lang/Throwable;)V");
                mids$[mid_init$_01646a2e] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        Exception::Exception() : ::java::lang::Throwable(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        Exception::Exception(const ::java::lang::String & a0) : ::java::lang::Throwable(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        Exception::Exception(const ::java::lang::Throwable & a0) : ::java::lang::Throwable(env->newObject(initializeClass, &mids$, mid_init$_c5ec8ca4, a0.this$)) {}

        Exception::Exception(const ::java::lang::String & a0, const ::java::lang::Throwable & a1) : ::java::lang::Throwable(env->newObject(initializeClass, &mids$, mid_init$_01646a2e, a0.this$, a1.this$)) {}
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Exception_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Exception_instance_(PyTypeObject *type, PyObject *arg);
        static int t_Exception_init_(t_Exception *self, PyObject *args, PyObject *kwds);

        static PyMethodDef t_Exception__methods_[] = {
            DECLARE_METHOD(t_Exception, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Exception, instance_, METH_O | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Exception, t_Exception, ::java::lang::Throwable, Exception, t_Exception_init_, 0, 0, 0, 0, 0);

        void t_Exception::install(PyObject *module)
        {
            installType(&PY_TYPE(Exception), module, "Exception", 0);
        }

        void t_Exception::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Exception).tp_dict, "class_", make_descriptor(Exception::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Exception).tp_dict, "wrapfn_", make_descriptor(t_Exception::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(Exception).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_Exception_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Exception::initializeClass, 1)))
                return NULL;
            return t_Exception::wrap_Object(Exception(((t_Exception *) arg)->object.this$));
        }
        static PyObject *t_Exception_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Exception::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_Exception_init_(t_Exception *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    Exception object((jobject) NULL);

                    INT_CALL(object = Exception());
                    self->object = object;
                    break;
                }
                goto err;
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    Exception object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = Exception(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::Throwable a0((jobject) NULL);
                    Exception object((jobject) NULL);

                    if (!parseArgs(args, "k", ::java::lang::Throwable::initializeClass, &a0))
                    {
                        INT_CALL(object = Exception(a0));
                        self->object = object;
                        break;
                    }
                }
                goto err;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    ::java::lang::Throwable a1((jobject) NULL);
                    Exception object((jobject) NULL);

                    if (!parseArgs(args, "sk", ::java::lang::Throwable::initializeClass, &a0, &a1))
                    {
                        INT_CALL(object = Exception(a0, a1));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Number.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Number::class$ = NULL;
        jmethodID *Number::mids$ = NULL;

        jclass Number::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Number");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_byteValue_54c6a172] = env->getMethodID(cls, "byteValue", "()B");
                mids$[mid_doubleValue_54c6a174] = env->getMethodID(cls, "doubleValue", "()D");
                mids$[mid_floatValue_54c6a176] = env->getMethodID(cls, "floatValue", "()F");
                mids$[mid_intValue_54c6a179] = env->getMethodID(cls, "intValue", "()I");
                mids$[mid_longValue_54c6a17a] = env->getMethodID(cls, "longValue", "()J");
                mids$[mid_shortValue_54c6a163] = env->getMethodID(cls, "shortValue", "()S");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        Number::Number() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        jbyte Number::byteValue() const
        {
            return env->callByteMethod(this$, mids$[mid_byteValue_54c6a172]);
        }

        jdouble Number::doubleValue() const
        {
            return env->callDoubleMethod(this$, mids$[mid_doubleValue_54c6a174]);
        }

        jfloat Number::floatValue() const
        {
            return env->callFloatMethod(this$, mids$[mid_floatValue_54c6a176]);
        }

        jint Number::intValue() const
        {
            return env->callIntMethod(this$, mids$[mid_intValue_54c6a179]);
        }

        jlong Number::longValue() const
        {
            return env->callLongMethod(this$, mids$[mid_longValue_54c6a17a]);
        }

        jshort Number::shortValue() const
        {
            return env->callShortMethod(this$, mids$[mid_shortValue_54c6a163]);
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Number_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Number_instance_(PyTypeObject *type, PyObject *arg);
        static int t_Number_init_(t_Number *self, PyObject *args, PyObject *kwds);
        static PyObject *t_Number_byteValue(t_Number *self);
        static PyObject *t_Number_doubleValue(t_Number *self);
        static PyObject *t_Number_floatValue(t_Number *self);
        static PyObject *t_Number_intValue(t_Number *self);
        static PyObject *t_Number_longValue(t_Number *self);
        static PyObject *t_Number_shortValue(t_Number *self);

        static PyMethodDef t_Number__methods_[] = {
            DECLARE_METHOD(t_Number, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Number, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Number, byteValue, METH_NOARGS),
            DECLARE_METHOD(t_Number, doubleValue, METH_NOARGS),
            DECLARE_METHOD(t_Number, floatValue, METH_NOARGS),
            DECLARE_METHOD(t_Number, intValue, METH_NOARGS),
            DECLARE_METHOD(t_Number, longValue, METH_NOARGS),
            DECLARE_METHOD(t_Number, shortValue, METH_NOARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Number, t_Number, ::java::lang::Object, Number, t_Number_init_, 0, 0, 0, 0, 0);

        void t_Number::install(PyObject *module)
        {
            installType(&PY_TYPE(Number), module, "Number", 0);
        }

        void t_Number::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Number).tp_dict, "class_", make_descriptor(Number::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Number).tp_dict, "wrapfn_", make_descriptor(t_Number::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(Number).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_Number_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Number::initializeClass, 1)))
                return NULL;
            return t_Number::wrap_Object(Number(((t_Number *) arg)->object.this$));
        }
        static PyObject *t_Number_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Number::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_Number_init_(t_Number *self, PyObject *args, PyObject *kwds)
        {
            Number object((jobject) NULL);

            INT_CALL(object = Number());
            self->object = object;

            return 0;
        }

        static PyObject *t_Number_byteValue(t_Number *self)
        {
            jbyte result;
            OBJ_CALL(result = self->object.byteValue());
            return PyInt_FromLong((long) result);
        }

        static PyObject *t_Number_doubleValue(t_Number *self)
        {
            jdouble result;
            OBJ_CALL(result = self->object.doubleValue());
            return PyFloat_FromDouble((double) result);
        }

        static PyObject *t_Number_floatValue(t_Number *self)
        {
            jfloat result;
            OBJ_CALL(result = self->object.floatValue());
            return PyFloat_FromDouble((double) result);
        }

        static PyObject *t_Number_intValue(t_Number *self)
        {
            jint result;
            OBJ_CALL(result = self->object.intValue());
            return PyInt_FromLong((long) result);
        }

        static PyObject *t_Number_longValue(t_Number *self)
        {
            jlong result;
            OBJ_CALL(result = self->object.longValue());
            return PyLong_FromLongLong((PY_LONG_LONG) result);
        }

        static PyObject *t_Number_shortValue(t_Number *self)
        {
            jshort result;
            OBJ_CALL(result = self->object.shortValue());
            return PyInt_FromLong((long) result);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Short.h"
#include "java/lang/String.h"
#include "java/lang/Comparable.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/Class.h"
#include "java/lang/Object.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Short::class$ = NULL;
        jmethodID *Short::mids$ = NULL;
        jshort Short::MAX_VALUE = (jshort) 0;
        jshort Short::MIN_VALUE = (jshort) 0;
        jint Short::SIZE = (jint) 0;
        ::java::lang::Class *Short::TYPE = NULL;

        jclass Short::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Short");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_3bc40c6a] = env->getMethodID(cls, "<init>", "(S)V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_byteValue_54c6a172] = env->getMethodID(cls, "byteValue", "()B");
                mids$[mid_compareTo_290588f1] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Object;)I");
                mids$[mid_compareTo_6b8573d1] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Short;)I");
                mids$[mid_decode_88c4db41] = env->getStaticMethodID(cls, "decode", "(Ljava/lang/String;)Ljava/lang/Short;");
                mids$[mid_doubleValue_54c6a174] = env->getMethodID(cls, "doubleValue", "()D");
                mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
                mids$[mid_floatValue_54c6a176] = env->getMethodID(cls, "floatValue", "()F");
                mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
                mids$[mid_intValue_54c6a179] = env->getMethodID(cls, "intValue", "()I");
                mids$[mid_longValue_54c6a17a] = env->getMethodID(cls, "longValue", "()J");
                mids$[mid_parseShort_5fdc3f4d] = env->getStaticMethodID(cls, "parseShort", "(Ljava/lang/String;)S");
                mids$[mid_parseShort_6e53ccc3] = env->getStaticMethodID(cls, "parseShort", "(Ljava/lang/String;I)S");
                mids$[mid_reverseBytes_3bc40c6f] = env->getStaticMethodID(cls, "reverseBytes", "(S)S");
                mids$[mid_shortValue_54c6a163] = env->getMethodID(cls, "shortValue", "()S");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
                mids$[mid_toString_9c2e4c45] = env->getStaticMethodID(cls, "toString", "(S)Ljava/lang/String;");
                mids$[mid_valueOf_5d563b1b] = env->getStaticMethodID(cls, "valueOf", "(S)Ljava/lang/Short;");
                mids$[mid_valueOf_88c4db41] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Ljava/lang/Short;");
                mids$[mid_valueOf_0f6bcb23] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;I)Ljava/lang/Short;");

                class$ = (::java::lang::Class *) new JObject(cls);
                cls = (jclass) class$->this$;

                MAX_VALUE = env->getStaticShortField(cls, "MAX_VALUE");
                MIN_VALUE = env->getStaticShortField(cls, "MIN_VALUE");
                SIZE = env->getStaticIntField(cls, "SIZE");
                TYPE = new ::java::lang::Class(env->getStaticObjectField(cls, "TYPE", "Ljava/lang/Class;"));
            }
            return (jclass) class$->this$;
        }

        Short::Short(jshort a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_3bc40c6a, a0)) {}

        Short::Short(const ::java::lang::String & a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        jbyte Short::byteValue() const
        {
            return env->callByteMethod(this$, mids$[mid_byteValue_54c6a172]);
        }

        jint Short::compareTo(const ::java::lang::Object & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_290588f1], a0.this$);
        }

        jint Short::compareTo(const Short & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_6b8573d1], a0.this$);
        }

        Short Short::decode(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Short(env->callStaticObjectMethod(cls, mids$[mid_decode_88c4db41], a0.this$));
        }

        jdouble Short::doubleValue() const
        {
            return env->callDoubleMethod(this$, mids$[mid_doubleValue_54c6a174]);
        }

        jboolean Short::equals(const ::java::lang::Object & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
        }

        jfloat Short::floatValue() const
        {
            return env->callFloatMethod(this$, mids$[mid_floatValue_54c6a176]);
        }

        jint Short::hashCode() const
        {
            return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
        }

        jint Short::intValue() const
        {
            return env->callIntMethod(this$, mids$[mid_intValue_54c6a179]);
        }

        jlong Short::longValue() const
        {
            return env->callLongMethod(this$, mids$[mid_longValue_54c6a17a]);
        }

        jshort Short::parseShort(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return env->callStaticShortMethod(cls, mids$[mid_parseShort_5fdc3f4d], a0.this$);
        }

        jshort Short::parseShort(const ::java::lang::String & a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticShortMethod(cls, mids$[mid_parseShort_6e53ccc3], a0.this$, a1);
        }

        jshort Short::reverseBytes(jshort a0)
        {
            jclass cls = initializeClass();
            return env->callStaticShortMethod(cls, mids$[mid_reverseBytes_3bc40c6f], a0);
        }

        jshort Short::shortValue() const
        {
            return env->callShortMethod(this$, mids$[mid_shortValue_54c6a163]);
        }

        ::java::lang::String Short::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }

        ::java::lang::String Short::toString(jshort a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_9c2e4c45], a0));
        }

        Short Short::valueOf(jshort a0)
        {
            jclass cls = initializeClass();
            return Short(env->callStaticObjectMethod(cls, mids$[mid_valueOf_5d563b1b], a0));
        }

        Short Short::valueOf(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Short(env->callStaticObjectMethod(cls, mids$[mid_valueOf_88c4db41], a0.this$));
        }

        Short Short::valueOf(const ::java::lang::String & a0, jint a1)
        {
            jclass cls = initializeClass();
            return Short(env->callStaticObjectMethod(cls, mids$[mid_valueOf_0f6bcb23], a0.this$, a1));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Short_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Short_instance_(PyTypeObject *type, PyObject *arg);
        static int t_Short_init_(t_Short *self, PyObject *args, PyObject *kwds);
        static PyObject *t_Short_byteValue(t_Short *self, PyObject *args);
        static PyObject *t_Short_compareTo(t_Short *self, PyObject *args);
        static PyObject *t_Short_decode(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Short_doubleValue(t_Short *self, PyObject *args);
        static PyObject *t_Short_equals(t_Short *self, PyObject *args);
        static PyObject *t_Short_floatValue(t_Short *self, PyObject *args);
        static PyObject *t_Short_hashCode(t_Short *self, PyObject *args);
        static PyObject *t_Short_intValue(t_Short *self, PyObject *args);
        static PyObject *t_Short_longValue(t_Short *self, PyObject *args);
        static PyObject *t_Short_parseShort(PyTypeObject *type, PyObject *args);
        static PyObject *t_Short_reverseBytes(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Short_shortValue(t_Short *self, PyObject *args);
        static PyObject *t_Short_toString(t_Short *self, PyObject *args);
        static PyObject *t_Short_toString_(PyTypeObject *type, PyObject *args);
        static PyObject *t_Short_valueOf(PyTypeObject *type, PyObject *args);

        static PyMethodDef t_Short__methods_[] = {
            DECLARE_METHOD(t_Short, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Short, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Short, byteValue, METH_VARARGS),
            DECLARE_METHOD(t_Short, compareTo, METH_VARARGS),
            DECLARE_METHOD(t_Short, decode, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Short, doubleValue, METH_VARARGS),
            DECLARE_METHOD(t_Short, equals, METH_VARARGS),
            DECLARE_METHOD(t_Short, floatValue, METH_VARARGS),
            DECLARE_METHOD(t_Short, hashCode, METH_VARARGS),
            DECLARE_METHOD(t_Short, intValue, METH_VARARGS),
            DECLARE_METHOD(t_Short, longValue, METH_VARARGS),
            DECLARE_METHOD(t_Short, parseShort, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Short, reverseBytes, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Short, shortValue, METH_VARARGS),
            DECLARE_METHOD(t_Short, toString, METH_VARARGS),
            DECLARE_METHOD(t_Short, toString_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Short, valueOf, METH_VARARGS | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Short, t_Short, ::java::lang::Number, Short, t_Short_init_, 0, 0, 0, 0, 0);

        void t_Short::install(PyObject *module)
        {
            installType(&PY_TYPE(Short), module, "Short", 0);
        }

        void t_Short::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Short).tp_dict, "class_", make_descriptor(Short::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Short).tp_dict, "wrapfn_", make_descriptor(unboxShort));
            PyDict_SetItemString(PY_TYPE(Short).tp_dict, "boxfn_", make_descriptor(boxShort));
            Short::initializeClass();
            PyDict_SetItemString(PY_TYPE(Short).tp_dict, "MAX_VALUE", make_descriptor(Short::MAX_VALUE));
            PyDict_SetItemString(PY_TYPE(Short).tp_dict, "MIN_VALUE", make_descriptor(Short::MIN_VALUE));
            PyDict_SetItemString(PY_TYPE(Short).tp_dict, "SIZE", make_descriptor(Short::SIZE));
            PyDict_SetItemString(PY_TYPE(Short).tp_dict, "TYPE", make_descriptor(::java::lang::t_Class::wrap_Object(*Short::TYPE)));
        }

        static PyObject *t_Short_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Short::initializeClass, 1)))
                return NULL;
            return t_Short::wrap_Object(Short(((t_Short *) arg)->object.this$));
        }
        static PyObject *t_Short_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Short::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_Short_init_(t_Short *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jshort a0;
                    Short object((jobject) NULL);

                    if (!parseArgs(args, "S", &a0))
                    {
                        INT_CALL(object = Short(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Short object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = Short(a0));
                        self->object = object;
                        break;
                    }
                }
              default:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_Short_byteValue(t_Short *self, PyObject *args)
        {
            jbyte result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.byteValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Short), (PyObject *) self, "byteValue", args, 2);
        }

        static PyObject *t_Short_compareTo(t_Short *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::Object a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    Short a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(Short), &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "compareTo", args);
            return NULL;
        }

        static PyObject *t_Short_decode(PyTypeObject *type, PyObject *arg)
        {
            ::java::lang::String a0((jobject) NULL);
            Short result((jobject) NULL);

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = ::java::lang::Short::decode(a0));
                return t_Short::wrap_Object(result);
            }

            PyErr_SetArgsError(type, "decode", arg);
            return NULL;
        }

        static PyObject *t_Short_doubleValue(t_Short *self, PyObject *args)
        {
            jdouble result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.doubleValue());
                return PyFloat_FromDouble((double) result);
            }

            return callSuper(&PY_TYPE(Short), (PyObject *) self, "doubleValue", args, 2);
        }

        static PyObject *t_Short_equals(t_Short *self, PyObject *args)
        {
            ::java::lang::Object a0((jobject) NULL);
            jboolean result;

            if (!parseArgs(args, "o", &a0))
            {
                OBJ_CALL(result = self->object.equals(a0));
                Py_RETURN_BOOL(result);
            }

            return callSuper(&PY_TYPE(Short), (PyObject *) self, "equals", args, 2);
        }

        static PyObject *t_Short_floatValue(t_Short *self, PyObject *args)
        {
            jfloat result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.floatValue());
                return PyFloat_FromDouble((double) result);
            }

            return callSuper(&PY_TYPE(Short), (PyObject *) self, "floatValue", args, 2);
        }

        static PyObject *t_Short_hashCode(t_Short *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.hashCode());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Short), (PyObject *) self, "hashCode", args, 2);
        }

        static PyObject *t_Short_intValue(t_Short *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.intValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Short), (PyObject *) self, "intValue", args, 2);
        }

        static PyObject *t_Short_longValue(t_Short *self, PyObject *args)
        {
            jlong result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.longValue());
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            return callSuper(&PY_TYPE(Short), (PyObject *) self, "longValue", args, 2);
        }

        static PyObject *t_Short_parseShort(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jshort result;

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Short::parseShort(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    jshort result;

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Short::parseShort(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError(type, "parseShort", args);
            return NULL;
        }

        static PyObject *t_Short_reverseBytes(PyTypeObject *type, PyObject *arg)
        {
            jshort a0;
            jshort result;

            if (!parseArg(arg, "S", &a0))
            {
                OBJ_CALL(result = ::java::lang::Short::reverseBytes(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "reverseBytes", arg);
            return NULL;
        }

        static PyObject *t_Short_shortValue(t_Short *self, PyObject *args)
        {
            jshort result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.shortValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Short), (PyObject *) self, "shortValue", args, 2);
        }

        static PyObject *t_Short_toString(t_Short *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(Short), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_Short_toString_(PyTypeObject *type, PyObject *args)
        {
            jshort a0;
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, "S", &a0))
            {
                OBJ_CALL(result = ::java::lang::Short::toString(a0));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "toString_", args);
            return NULL;
        }

        static PyObject *t_Short_valueOf(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jshort a0;
                    Short result((jobject) NULL);

                    if (!parseArgs(args, "S", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Short::valueOf(a0));
                        return t_Short::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Short result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Short::valueOf(a0));
                        return t_Short::wrap_Object(result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    Short result((jobject) NULL);

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Short::valueOf(a0, a1));
                        return t_Short::wrap_Object(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "valueOf", args);
            return NULL;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Byte.h"
#include "java/lang/String.h"
#include "java/lang/Comparable.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/Class.h"
#include "java/lang/Object.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Byte::class$ = NULL;
        jmethodID *Byte::mids$ = NULL;
        jbyte Byte::MAX_VALUE = (jbyte) 0;
        jbyte Byte::MIN_VALUE = (jbyte) 0;
        jint Byte::SIZE = (jint) 0;
        ::java::lang::Class *Byte::TYPE = NULL;

        jclass Byte::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Byte");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_b2271687] = env->getMethodID(cls, "<init>", "(B)V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_byteValue_54c6a172] = env->getMethodID(cls, "byteValue", "()B");
                mids$[mid_compareTo_290588f1] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Object;)I");
                mids$[mid_compareTo_c2b89a9a] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Byte;)I");
                mids$[mid_decode_4a53f64a] = env->getStaticMethodID(cls, "decode", "(Ljava/lang/String;)Ljava/lang/Byte;");
                mids$[mid_doubleValue_54c6a174] = env->getMethodID(cls, "doubleValue", "()D");
                mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
                mids$[mid_floatValue_54c6a176] = env->getMethodID(cls, "floatValue", "()F");
                mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
                mids$[mid_intValue_54c6a179] = env->getMethodID(cls, "intValue", "()I");
                mids$[mid_longValue_54c6a17a] = env->getMethodID(cls, "longValue", "()J");
                mids$[mid_parseByte_5fdc3f5c] = env->getStaticMethodID(cls, "parseByte", "(Ljava/lang/String;)B");
                mids$[mid_parseByte_6e53ccd2] = env->getStaticMethodID(cls, "parseByte", "(Ljava/lang/String;I)B");
                mids$[mid_shortValue_54c6a163] = env->getMethodID(cls, "shortValue", "()S");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
                mids$[mid_toString_fce80606] = env->getStaticMethodID(cls, "toString", "(B)Ljava/lang/String;");
                mids$[mid_valueOf_f1e1a5a7] = env->getStaticMethodID(cls, "valueOf", "(B)Ljava/lang/Byte;");
                mids$[mid_valueOf_4a53f64a] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Ljava/lang/Byte;");
                mids$[mid_valueOf_83e30bb0] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;I)Ljava/lang/Byte;");

                class$ = (::java::lang::Class *) new JObject(cls);
                cls = (jclass) class$->this$;

                MAX_VALUE = env->getStaticByteField(cls, "MAX_VALUE");
                MIN_VALUE = env->getStaticByteField(cls, "MIN_VALUE");
                SIZE = env->getStaticIntField(cls, "SIZE");
                TYPE = new ::java::lang::Class(env->getStaticObjectField(cls, "TYPE", "Ljava/lang/Class;"));
            }
            return (jclass) class$->this$;
        }

        Byte::Byte(jbyte a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_b2271687, a0)) {}

        Byte::Byte(const ::java::lang::String & a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        jbyte Byte::byteValue() const
        {
            return env->callByteMethod(this$, mids$[mid_byteValue_54c6a172]);
        }

        jint Byte::compareTo(const ::java::lang::Object & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_290588f1], a0.this$);
        }

        jint Byte::compareTo(const Byte & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_c2b89a9a], a0.this$);
        }

        Byte Byte::decode(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Byte(env->callStaticObjectMethod(cls, mids$[mid_decode_4a53f64a], a0.this$));
        }

        jdouble Byte::doubleValue() const
        {
            return env->callDoubleMethod(this$, mids$[mid_doubleValue_54c6a174]);
        }

        jboolean Byte::equals(const ::java::lang::Object & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
        }

        jfloat Byte::floatValue() const
        {
            return env->callFloatMethod(this$, mids$[mid_floatValue_54c6a176]);
        }

        jint Byte::hashCode() const
        {
            return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
        }

        jint Byte::intValue() const
        {
            return env->callIntMethod(this$, mids$[mid_intValue_54c6a179]);
        }

        jlong Byte::longValue() const
        {
            return env->callLongMethod(this$, mids$[mid_longValue_54c6a17a]);
        }

        jbyte Byte::parseByte(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return env->callStaticByteMethod(cls, mids$[mid_parseByte_5fdc3f5c], a0.this$);
        }

        jbyte Byte::parseByte(const ::java::lang::String & a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticByteMethod(cls, mids$[mid_parseByte_6e53ccd2], a0.this$, a1);
        }

        jshort Byte::shortValue() const
        {
            return env->callShortMethod(this$, mids$[mid_shortValue_54c6a163]);
        }

        ::java::lang::String Byte::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }

        ::java::lang::String Byte::toString(jbyte a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_fce80606], a0));
        }

        Byte Byte::valueOf(jbyte a0)
        {
            jclass cls = initializeClass();
            return Byte(env->callStaticObjectMethod(cls, mids$[mid_valueOf_f1e1a5a7], a0));
        }

        Byte Byte::valueOf(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Byte(env->callStaticObjectMethod(cls, mids$[mid_valueOf_4a53f64a], a0.this$));
        }

        Byte Byte::valueOf(const ::java::lang::String & a0, jint a1)
        {
            jclass cls = initializeClass();
            return Byte(env->callStaticObjectMethod(cls, mids$[mid_valueOf_83e30bb0], a0.this$, a1));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Byte_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Byte_instance_(PyTypeObject *type, PyObject *arg);
        static int t_Byte_init_(t_Byte *self, PyObject *args, PyObject *kwds);
        static PyObject *t_Byte_byteValue(t_Byte *self, PyObject *args);
        static PyObject *t_Byte_compareTo(t_Byte *self, PyObject *args);
        static PyObject *t_Byte_decode(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Byte_doubleValue(t_Byte *self, PyObject *args);
        static PyObject *t_Byte_equals(t_Byte *self, PyObject *args);
        static PyObject *t_Byte_floatValue(t_Byte *self, PyObject *args);
        static PyObject *t_Byte_hashCode(t_Byte *self, PyObject *args);
        static PyObject *t_Byte_intValue(t_Byte *self, PyObject *args);
        static PyObject *t_Byte_longValue(t_Byte *self, PyObject *args);
        static PyObject *t_Byte_parseByte(PyTypeObject *type, PyObject *args);
        static PyObject *t_Byte_shortValue(t_Byte *self, PyObject *args);
        static PyObject *t_Byte_toString(t_Byte *self, PyObject *args);
        static PyObject *t_Byte_toString_(PyTypeObject *type, PyObject *args);
        static PyObject *t_Byte_valueOf(PyTypeObject *type, PyObject *args);

        static PyMethodDef t_Byte__methods_[] = {
            DECLARE_METHOD(t_Byte, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Byte, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Byte, byteValue, METH_VARARGS),
            DECLARE_METHOD(t_Byte, compareTo, METH_VARARGS),
            DECLARE_METHOD(t_Byte, decode, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Byte, doubleValue, METH_VARARGS),
            DECLARE_METHOD(t_Byte, equals, METH_VARARGS),
            DECLARE_METHOD(t_Byte, floatValue, METH_VARARGS),
            DECLARE_METHOD(t_Byte, hashCode, METH_VARARGS),
            DECLARE_METHOD(t_Byte, intValue, METH_VARARGS),
            DECLARE_METHOD(t_Byte, longValue, METH_VARARGS),
            DECLARE_METHOD(t_Byte, parseByte, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Byte, shortValue, METH_VARARGS),
            DECLARE_METHOD(t_Byte, toString, METH_VARARGS),
            DECLARE_METHOD(t_Byte, toString_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Byte, valueOf, METH_VARARGS | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Byte, t_Byte, ::java::lang::Number, Byte, t_Byte_init_, 0, 0, 0, 0, 0);

        void t_Byte::install(PyObject *module)
        {
            installType(&PY_TYPE(Byte), module, "Byte", 0);
        }

        void t_Byte::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Byte).tp_dict, "class_", make_descriptor(Byte::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Byte).tp_dict, "wrapfn_", make_descriptor(unboxByte));
            PyDict_SetItemString(PY_TYPE(Byte).tp_dict, "boxfn_", make_descriptor(boxByte));
            Byte::initializeClass();
            PyDict_SetItemString(PY_TYPE(Byte).tp_dict, "MAX_VALUE", make_descriptor(Byte::MAX_VALUE));
            PyDict_SetItemString(PY_TYPE(Byte).tp_dict, "MIN_VALUE", make_descriptor(Byte::MIN_VALUE));
            PyDict_SetItemString(PY_TYPE(Byte).tp_dict, "SIZE", make_descriptor(Byte::SIZE));
            PyDict_SetItemString(PY_TYPE(Byte).tp_dict, "TYPE", make_descriptor(::java::lang::t_Class::wrap_Object(*Byte::TYPE)));
        }

        static PyObject *t_Byte_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Byte::initializeClass, 1)))
                return NULL;
            return t_Byte::wrap_Object(Byte(((t_Byte *) arg)->object.this$));
        }
        static PyObject *t_Byte_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Byte::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_Byte_init_(t_Byte *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jbyte a0;
                    Byte object((jobject) NULL);

                    if (!parseArgs(args, "B", &a0))
                    {
                        INT_CALL(object = Byte(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Byte object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = Byte(a0));
                        self->object = object;
                        break;
                    }
                }
              default:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_Byte_byteValue(t_Byte *self, PyObject *args)
        {
            jbyte result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.byteValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Byte), (PyObject *) self, "byteValue", args, 2);
        }

        static PyObject *t_Byte_compareTo(t_Byte *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::Object a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    Byte a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(Byte), &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "compareTo", args);
            return NULL;
        }

        static PyObject *t_Byte_decode(PyTypeObject *type, PyObject *arg)
        {
            ::java::lang::String a0((jobject) NULL);
            Byte result((jobject) NULL);

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = ::java::lang::Byte::decode(a0));
                return t_Byte::wrap_Object(result);
            }

            PyErr_SetArgsError(type, "decode", arg);
            return NULL;
        }

        static PyObject *t_Byte_doubleValue(t_Byte *self, PyObject *args)
        {
            jdouble result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.doubleValue());
                return PyFloat_FromDouble((double) result);
            }

            return callSuper(&PY_TYPE(Byte), (PyObject *) self, "doubleValue", args, 2);
        }

        static PyObject *t_Byte_equals(t_Byte *self, PyObject *args)
        {
            ::java::lang::Object a0((jobject) NULL);
            jboolean result;

            if (!parseArgs(args, "o", &a0))
            {
                OBJ_CALL(result = self->object.equals(a0));
                Py_RETURN_BOOL(result);
            }

            return callSuper(&PY_TYPE(Byte), (PyObject *) self, "equals", args, 2);
        }

        static PyObject *t_Byte_floatValue(t_Byte *self, PyObject *args)
        {
            jfloat result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.floatValue());
                return PyFloat_FromDouble((double) result);
            }

            return callSuper(&PY_TYPE(Byte), (PyObject *) self, "floatValue", args, 2);
        }

        static PyObject *t_Byte_hashCode(t_Byte *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.hashCode());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Byte), (PyObject *) self, "hashCode", args, 2);
        }

        static PyObject *t_Byte_intValue(t_Byte *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.intValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Byte), (PyObject *) self, "intValue", args, 2);
        }

        static PyObject *t_Byte_longValue(t_Byte *self, PyObject *args)
        {
            jlong result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.longValue());
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            return callSuper(&PY_TYPE(Byte), (PyObject *) self, "longValue", args, 2);
        }

        static PyObject *t_Byte_parseByte(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jbyte result;

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Byte::parseByte(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    jbyte result;

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Byte::parseByte(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError(type, "parseByte", args);
            return NULL;
        }

        static PyObject *t_Byte_shortValue(t_Byte *self, PyObject *args)
        {
            jshort result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.shortValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Byte), (PyObject *) self, "shortValue", args, 2);
        }

        static PyObject *t_Byte_toString(t_Byte *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(Byte), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_Byte_toString_(PyTypeObject *type, PyObject *args)
        {
            jbyte a0;
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, "B", &a0))
            {
                OBJ_CALL(result = ::java::lang::Byte::toString(a0));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "toString_", args);
            return NULL;
        }

        static PyObject *t_Byte_valueOf(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jbyte a0;
                    Byte result((jobject) NULL);

                    if (!parseArgs(args, "B", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Byte::valueOf(a0));
                        return t_Byte::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Byte result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Byte::valueOf(a0));
                        return t_Byte::wrap_Object(result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    Byte result((jobject) NULL);

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Byte::valueOf(a0, a1));
                        return t_Byte::wrap_Object(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "valueOf", args);
            return NULL;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "ScalaUtils.h"
#include "scala/Function1.h"
#include "java/lang/Class.h"
#include "JArray.h"


::java::lang::Class *ScalaUtils::class$ = NULL;
jmethodID *ScalaUtils::mids$ = NULL;

jclass ScalaUtils::initializeClass()
{
    if (!class$)
    {

        jclass cls = (jclass) env->findClass("ScalaUtils");

        mids$ = new jmethodID[max_mid];
        mids$[mid_ageGroupFunction_c83f65c1] = env->getStaticMethodID(cls, "ageGroupFunction", "()Lscala/Function1;");
        mids$[mid_ageGroupMethod_5d1c765a] = env->getStaticMethodID(cls, "ageGroupMethod", "(D)I");
        mids$[mid_reptileAgeGroupFunctionMaker_279d294f] = env->getStaticMethodID(cls, "reptileAgeGroupFunctionMaker", "(Lscala/Function1;)Lscala/Function1;");

        class$ = (::java::lang::Class *) new JObject(cls);
    }
    return (jclass) class$->this$;
}

::scala::Function1 ScalaUtils::ageGroupFunction()
{
    jclass cls = initializeClass();
    return ::scala::Function1(env->callStaticObjectMethod(cls, mids$[mid_ageGroupFunction_c83f65c1]));
}

jint ScalaUtils::ageGroupMethod(jdouble a0)
{
    jclass cls = initializeClass();
    return env->callStaticIntMethod(cls, mids$[mid_ageGroupMethod_5d1c765a], a0);
}

::scala::Function1 ScalaUtils::reptileAgeGroupFunctionMaker(const ::scala::Function1 & a0)
{
    jclass cls = initializeClass();
    return ::scala::Function1(env->callStaticObjectMethod(cls, mids$[mid_reptileAgeGroupFunctionMaker_279d294f], a0.this$));
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"
#include "ScalaUtils$$anonfun$1.h"

static PyObject *t_ScalaUtils_cast_(PyTypeObject *type, PyObject *arg);
static PyObject *t_ScalaUtils_instance_(PyTypeObject *type, PyObject *arg);
static PyObject *t_ScalaUtils_ageGroupFunction(PyTypeObject *type);
static PyObject *t_ScalaUtils_ageGroupMethod(PyTypeObject *type, PyObject *arg);
static PyObject *t_ScalaUtils_reptileAgeGroupFunctionMaker(PyTypeObject *type, PyObject *arg);

static PyMethodDef t_ScalaUtils__methods_[] = {
    DECLARE_METHOD(t_ScalaUtils, cast_, METH_O | METH_CLASS),
    DECLARE_METHOD(t_ScalaUtils, instance_, METH_O | METH_CLASS),
    DECLARE_METHOD(t_ScalaUtils, ageGroupFunction, METH_NOARGS | METH_CLASS),
    DECLARE_METHOD(t_ScalaUtils, ageGroupMethod, METH_O | METH_CLASS),
    DECLARE_METHOD(t_ScalaUtils, reptileAgeGroupFunctionMaker, METH_O | METH_CLASS),
    { NULL, NULL, 0, NULL }
};

DECLARE_TYPE(ScalaUtils, t_ScalaUtils, ::java::lang::Object, ScalaUtils, abstract_init, 0, 0, 0, 0, 0);

void t_ScalaUtils::install(PyObject *module)
{
    installType(&PY_TYPE(ScalaUtils), module, "ScalaUtils", 0);
    PyDict_SetItemString(PY_TYPE(ScalaUtils).tp_dict, "$anonfun$1", make_descriptor(&PY_TYPE(ScalaUtils$$anonfun$1)));
}

void t_ScalaUtils::initialize(PyObject *module)
{
    PyDict_SetItemString(PY_TYPE(ScalaUtils).tp_dict, "class_", make_descriptor(ScalaUtils::initializeClass, 1));
    PyDict_SetItemString(PY_TYPE(ScalaUtils).tp_dict, "wrapfn_", make_descriptor(t_ScalaUtils::wrap_jobject));
    PyDict_SetItemString(PY_TYPE(ScalaUtils).tp_dict, "boxfn_", make_descriptor(boxObject));
}

static PyObject *t_ScalaUtils_cast_(PyTypeObject *type, PyObject *arg)
{
    if (!(arg = castCheck(arg, ScalaUtils::initializeClass, 1)))
        return NULL;
    return t_ScalaUtils::wrap_Object(ScalaUtils(((t_ScalaUtils *) arg)->object.this$));
}
static PyObject *t_ScalaUtils_instance_(PyTypeObject *type, PyObject *arg)
{
    if (!castCheck(arg, ScalaUtils::initializeClass, 0))
        Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}

static PyObject *t_ScalaUtils_ageGroupFunction(PyTypeObject *type)
{
    ::scala::Function1 result((jobject) NULL);
    OBJ_CALL(result = ::ScalaUtils::ageGroupFunction());
    return ::scala::t_Function1::wrap_Object(result, &::java::lang::PY_TYPE(Object), &::java::lang::PY_TYPE(Object));
}

static PyObject *t_ScalaUtils_ageGroupMethod(PyTypeObject *type, PyObject *arg)
{
    jdouble a0;
    jint result;

    if (!parseArg(arg, "D", &a0))
    {
        OBJ_CALL(result = ::ScalaUtils::ageGroupMethod(a0));
        return PyInt_FromLong((long) result);
    }

    PyErr_SetArgsError(type, "ageGroupMethod", arg);
    return NULL;
}

static PyObject *t_ScalaUtils_reptileAgeGroupFunctionMaker(PyTypeObject *type, PyObject *arg)
{
    ::scala::Function1 a0((jobject) NULL);
    PyTypeObject **p0;
    ::scala::Function1 result((jobject) NULL);

    if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
    {
        OBJ_CALL(result = ::ScalaUtils::reptileAgeGroupFunctionMaker(a0));
        return ::scala::t_Function1::wrap_Object(result, &::java::lang::PY_TYPE(Object), &::java::lang::PY_TYPE(Object));
    }

    PyErr_SetArgsError(type, "reptileAgeGroupFunctionMaker", arg);
    return NULL;
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/util/Iterator.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace util {

        ::java::lang::Class *Iterator::class$ = NULL;
        jmethodID *Iterator::mids$ = NULL;

        jclass Iterator::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/util/Iterator");

                mids$ = new jmethodID[max_mid];
                mids$[mid_hasNext_54c6a16a] = env->getMethodID(cls, "hasNext", "()Z");
                mids$[mid_next_846352c3] = env->getMethodID(cls, "next", "()Ljava/lang/Object;");
                mids$[mid_remove_54c6a166] = env->getMethodID(cls, "remove", "()V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        jboolean Iterator::hasNext() const
        {
            return env->callBooleanMethod(this$, mids$[mid_hasNext_54c6a16a]);
        }

        ::java::lang::Object Iterator::next() const
        {
            return ::java::lang::Object(env->callObjectMethod(this$, mids$[mid_next_846352c3]));
        }

        void Iterator::remove() const
        {
            env->callVoidMethod(this$, mids$[mid_remove_54c6a166]);
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace util {
        static PyObject *t_Iterator_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Iterator_instance_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Iterator_of_(t_Iterator *self, PyObject *args);
        static PyObject *t_Iterator_hasNext(t_Iterator *self);
        static PyObject *t_Iterator_next(t_Iterator *self);
        static PyObject *t_Iterator_remove(t_Iterator *self);
        static PyObject *t_Iterator_get__parameters_(t_Iterator *self, void *data);
        static PyGetSetDef t_Iterator__fields_[] = {
            DECLARE_GET_FIELD(t_Iterator, parameters_),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_Iterator__methods_[] = {
            DECLARE_METHOD(t_Iterator, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Iterator, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Iterator, of_, METH_VARARGS),
            DECLARE_METHOD(t_Iterator, hasNext, METH_NOARGS),
            DECLARE_METHOD(t_Iterator, next, METH_NOARGS),
            DECLARE_METHOD(t_Iterator, remove, METH_NOARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Iterator, t_Iterator, ::java::lang::Object, Iterator, abstract_init, PyObject_SelfIter, ((PyObject *(*)(::java::util::t_Iterator *)) get_generic_iterator_next< ::java::util::t_Iterator,::java::lang::t_Object >), t_Iterator__fields_, 0, 0);
        PyObject *t_Iterator::wrap_Object(const Iterator& object, PyTypeObject *E)
        {
            PyObject *obj = t_Iterator::wrap_Object(object);
            if (obj != NULL && obj != Py_None)
            {
                t_Iterator *self = (t_Iterator *) obj;
                self->parameters[0] = E;
            }
            return obj;
        }

        PyObject *t_Iterator::wrap_jobject(const jobject& object, PyTypeObject *E)
        {
            PyObject *obj = t_Iterator::wrap_jobject(object);
            if (obj != NULL && obj != Py_None)
            {
                t_Iterator *self = (t_Iterator *) obj;
                self->parameters[0] = E;
            }
            return obj;
        }

        void t_Iterator::install(PyObject *module)
        {
            installType(&PY_TYPE(Iterator), module, "Iterator", 0);
        }

        void t_Iterator::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Iterator).tp_dict, "class_", make_descriptor(Iterator::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Iterator).tp_dict, "wrapfn_", make_descriptor(t_Iterator::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(Iterator).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_Iterator_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Iterator::initializeClass, 1)))
                return NULL;
            return t_Iterator::wrap_Object(Iterator(((t_Iterator *) arg)->object.this$));
        }
        static PyObject *t_Iterator_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Iterator::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static PyObject *t_Iterator_of_(t_Iterator *self, PyObject *args)
        {
            if (!parseArg(args, "T", 1, &(self->parameters)))
                Py_RETURN_SELF;
            return PyErr_SetArgsError((PyObject *) self, "of_", args);
        }

        static PyObject *t_Iterator_hasNext(t_Iterator *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.hasNext());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Iterator_next(t_Iterator *self)
        {
            ::java::lang::Object result((jobject) NULL);
            OBJ_CALL(result = self->object.next());
            return self->parameters[0] != NULL ? wrapType(self->parameters[0], result.this$) : ::java::lang::t_Object::wrap_Object(result);
        }

        static PyObject *t_Iterator_remove(t_Iterator *self)
        {
            OBJ_CALL(self->object.remove());
            Py_RETURN_NONE;
        }
        static PyObject *t_Iterator_get__parameters_(t_Iterator *self, void *data)
        {
            return typeParameters(self->parameters, sizeof(self->parameters));
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Class.h"
#include "java/lang/SecurityException.h"
#include "java/lang/ClassLoader.h"
#include "java/lang/String.h"
#include "java/lang/Package.h"
#include "java/lang/InstantiationException.h"
#include "java/lang/IllegalAccessException.h"
#include "java/lang/ClassNotFoundException.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Class::class$ = NULL;
        jmethodID *Class::mids$ = NULL;

        jclass Class::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Class");

                mids$ = new jmethodID[max_mid];
                mids$[mid_asSubclass_ecb22eb3] = env->getMethodID(cls, "asSubclass", "(Ljava/lang/Class;)Ljava/lang/Class;");
                mids$[mid_cast_a932a95f] = env->getMethodID(cls, "cast", "(Ljava/lang/Object;)Ljava/lang/Object;");
                mids$[mid_desiredAssertionStatus_54c6a16a] = env->getMethodID(cls, "desiredAssertionStatus", "()Z");
                mids$[mid_forName_7d663d97] = env->getStaticMethodID(cls, "forName", "(Ljava/lang/String;)Ljava/lang/Class;");
                mids$[mid_forName_4c5c10fb] = env->getStaticMethodID(cls, "forName", "(Ljava/lang/String;ZLjava/lang/ClassLoader;)Ljava/lang/Class;");
                mids$[mid_getCanonicalName_14c7b5c5] = env->getMethodID(cls, "getCanonicalName", "()Ljava/lang/String;");
                mids$[mid_getClassLoader_8d2f11fc] = env->getMethodID(cls, "getClassLoader", "()Ljava/lang/ClassLoader;");
                mids$[mid_getClasses_ffb25e7d] = env->getMethodID(cls, "getClasses", "()[Ljava/lang/Class;");
                mids$[mid_getComponentType_44a5f2c9] = env->getMethodID(cls, "getComponentType", "()Ljava/lang/Class;");
                mids$[mid_getDeclaredClasses_ffb25e7d] = env->getMethodID(cls, "getDeclaredClasses", "()[Ljava/lang/Class;");
                mids$[mid_getDeclaringClass_44a5f2c9] = env->getMethodID(cls, "getDeclaringClass", "()Ljava/lang/Class;");
                mids$[mid_getEnclosingClass_44a5f2c9] = env->getMethodID(cls, "getEnclosingClass", "()Ljava/lang/Class;");
                mids$[mid_getEnumConstants_94e49c77] = env->getMethodID(cls, "getEnumConstants", "()[Ljava/lang/Object;");
                mids$[mid_getInterfaces_ffb25e7d] = env->getMethodID(cls, "getInterfaces", "()[Ljava/lang/Class;");
                mids$[mid_getModifiers_54c6a179] = env->getMethodID(cls, "getModifiers", "()I");
                mids$[mid_getName_14c7b5c5] = env->getMethodID(cls, "getName", "()Ljava/lang/String;");
                mids$[mid_getPackage_b0f2f7bb] = env->getMethodID(cls, "getPackage", "()Ljava/lang/Package;");
                mids$[mid_getSigners_94e49c77] = env->getMethodID(cls, "getSigners", "()[Ljava/lang/Object;");
                mids$[mid_getSimpleName_14c7b5c5] = env->getMethodID(cls, "getSimpleName", "()Ljava/lang/String;");
                mids$[mid_getSuperclass_44a5f2c9] = env->getMethodID(cls, "getSuperclass", "()Ljava/lang/Class;");
                mids$[mid_isAnnotation_54c6a16a] = env->getMethodID(cls, "isAnnotation", "()Z");
                mids$[mid_isAnonymousClass_54c6a16a] = env->getMethodID(cls, "isAnonymousClass", "()Z");
                mids$[mid_isArray_54c6a16a] = env->getMethodID(cls, "isArray", "()Z");
                mids$[mid_isAssignableFrom_a5deaff8] = env->getMethodID(cls, "isAssignableFrom", "(Ljava/lang/Class;)Z");
                mids$[mid_isEnum_54c6a16a] = env->getMethodID(cls, "isEnum", "()Z");
                mids$[mid_isInstance_290588e2] = env->getMethodID(cls, "isInstance", "(Ljava/lang/Object;)Z");
                mids$[mid_isInterface_54c6a16a] = env->getMethodID(cls, "isInterface", "()Z");
                mids$[mid_isLocalClass_54c6a16a] = env->getMethodID(cls, "isLocalClass", "()Z");
                mids$[mid_isMemberClass_54c6a16a] = env->getMethodID(cls, "isMemberClass", "()Z");
                mids$[mid_isPrimitive_54c6a16a] = env->getMethodID(cls, "isPrimitive", "()Z");
                mids$[mid_isSynthetic_54c6a16a] = env->getMethodID(cls, "isSynthetic", "()Z");
                mids$[mid_newInstance_846352c3] = env->getMethodID(cls, "newInstance", "()Ljava/lang/Object;");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        Class Class::asSubclass(const Class & a0) const
        {
            return Class(env->callObjectMethod(this$, mids$[mid_asSubclass_ecb22eb3], a0.this$));
        }

        ::java::lang::Object Class::cast(const ::java::lang::Object & a0) const
        {
            return ::java::lang::Object(env->callObjectMethod(this$, mids$[mid_cast_a932a95f], a0.this$));
        }

        jboolean Class::desiredAssertionStatus() const
        {
            return env->callBooleanMethod(this$, mids$[mid_desiredAssertionStatus_54c6a16a]);
        }

        Class Class::forName(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Class(env->callStaticObjectMethod(cls, mids$[mid_forName_7d663d97], a0.this$));
        }

        Class Class::forName(const ::java::lang::String & a0, jboolean a1, const ::java::lang::ClassLoader & a2)
        {
            jclass cls = initializeClass();
            return Class(env->callStaticObjectMethod(cls, mids$[mid_forName_4c5c10fb], a0.this$, a1, a2.this$));
        }

        ::java::lang::String Class::getCanonicalName() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getCanonicalName_14c7b5c5]));
        }

        ::java::lang::ClassLoader Class::getClassLoader() const
        {
            return ::java::lang::ClassLoader(env->callObjectMethod(this$, mids$[mid_getClassLoader_8d2f11fc]));
        }

        JArray< Class > Class::getClasses() const
        {
            return JArray< Class >(env->callObjectMethod(this$, mids$[mid_getClasses_ffb25e7d]));
        }

        Class Class::getComponentType() const
        {
            return Class(env->callObjectMethod(this$, mids$[mid_getComponentType_44a5f2c9]));
        }

        JArray< Class > Class::getDeclaredClasses() const
        {
            return JArray< Class >(env->callObjectMethod(this$, mids$[mid_getDeclaredClasses_ffb25e7d]));
        }

        Class Class::getDeclaringClass() const
        {
            return Class(env->callObjectMethod(this$, mids$[mid_getDeclaringClass_44a5f2c9]));
        }

        Class Class::getEnclosingClass() const
        {
            return Class(env->callObjectMethod(this$, mids$[mid_getEnclosingClass_44a5f2c9]));
        }

        JArray< ::java::lang::Object > Class::getEnumConstants() const
        {
            return JArray< ::java::lang::Object >(env->callObjectMethod(this$, mids$[mid_getEnumConstants_94e49c77]));
        }

        JArray< Class > Class::getInterfaces() const
        {
            return JArray< Class >(env->callObjectMethod(this$, mids$[mid_getInterfaces_ffb25e7d]));
        }

        jint Class::getModifiers() const
        {
            return env->callIntMethod(this$, mids$[mid_getModifiers_54c6a179]);
        }

        ::java::lang::String Class::getName() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getName_14c7b5c5]));
        }

        ::java::lang::Package Class::getPackage() const
        {
            return ::java::lang::Package(env->callObjectMethod(this$, mids$[mid_getPackage_b0f2f7bb]));
        }

        JArray< ::java::lang::Object > Class::getSigners() const
        {
            return JArray< ::java::lang::Object >(env->callObjectMethod(this$, mids$[mid_getSigners_94e49c77]));
        }

        ::java::lang::String Class::getSimpleName() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getSimpleName_14c7b5c5]));
        }

        Class Class::getSuperclass() const
        {
            return Class(env->callObjectMethod(this$, mids$[mid_getSuperclass_44a5f2c9]));
        }

        jboolean Class::isAnnotation() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isAnnotation_54c6a16a]);
        }

        jboolean Class::isAnonymousClass() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isAnonymousClass_54c6a16a]);
        }

        jboolean Class::isArray() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isArray_54c6a16a]);
        }

        jboolean Class::isAssignableFrom(const Class & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_isAssignableFrom_a5deaff8], a0.this$);
        }

        jboolean Class::isEnum() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isEnum_54c6a16a]);
        }

        jboolean Class::isInstance(const ::java::lang::Object & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_isInstance_290588e2], a0.this$);
        }

        jboolean Class::isInterface() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isInterface_54c6a16a]);
        }

        jboolean Class::isLocalClass() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isLocalClass_54c6a16a]);
        }

        jboolean Class::isMemberClass() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isMemberClass_54c6a16a]);
        }

        jboolean Class::isPrimitive() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isPrimitive_54c6a16a]);
        }

        jboolean Class::isSynthetic() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isSynthetic_54c6a16a]);
        }

        ::java::lang::Object Class::newInstance() const
        {
            return ::java::lang::Object(env->callObjectMethod(this$, mids$[mid_newInstance_846352c3]));
        }

        ::java::lang::String Class::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Class_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Class_instance_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Class_of_(t_Class *self, PyObject *args);
        static PyObject *t_Class_asSubclass(t_Class *self, PyObject *arg);
        static PyObject *t_Class_cast(t_Class *self, PyObject *arg);
        static PyObject *t_Class_desiredAssertionStatus(t_Class *self);
        static PyObject *t_Class_forName(PyTypeObject *type, PyObject *args);
        static PyObject *t_Class_getCanonicalName(t_Class *self);
        static PyObject *t_Class_getClassLoader(t_Class *self);
        static PyObject *t_Class_getClasses(t_Class *self);
        static PyObject *t_Class_getComponentType(t_Class *self);
        static PyObject *t_Class_getDeclaredClasses(t_Class *self);
        static PyObject *t_Class_getDeclaringClass(t_Class *self);
        static PyObject *t_Class_getEnclosingClass(t_Class *self);
        static PyObject *t_Class_getEnumConstants(t_Class *self);
        static PyObject *t_Class_getInterfaces(t_Class *self);
        static PyObject *t_Class_getModifiers(t_Class *self);
        static PyObject *t_Class_getName(t_Class *self);
        static PyObject *t_Class_getPackage(t_Class *self);
        static PyObject *t_Class_getSigners(t_Class *self);
        static PyObject *t_Class_getSimpleName(t_Class *self);
        static PyObject *t_Class_getSuperclass(t_Class *self);
        static PyObject *t_Class_isAnnotation(t_Class *self);
        static PyObject *t_Class_isAnonymousClass(t_Class *self);
        static PyObject *t_Class_isArray(t_Class *self);
        static PyObject *t_Class_isAssignableFrom(t_Class *self, PyObject *arg);
        static PyObject *t_Class_isEnum(t_Class *self);
        static PyObject *t_Class_isInstance(t_Class *self, PyObject *arg);
        static PyObject *t_Class_isInterface(t_Class *self);
        static PyObject *t_Class_isLocalClass(t_Class *self);
        static PyObject *t_Class_isMemberClass(t_Class *self);
        static PyObject *t_Class_isPrimitive(t_Class *self);
        static PyObject *t_Class_isSynthetic(t_Class *self);
        static PyObject *t_Class_newInstance(t_Class *self);
        static PyObject *t_Class_toString(t_Class *self, PyObject *args);
        static PyObject *t_Class_get__annotation(t_Class *self, void *data);
        static PyObject *t_Class_get__anonymousClass(t_Class *self, void *data);
        static PyObject *t_Class_get__array(t_Class *self, void *data);
        static PyObject *t_Class_get__canonicalName(t_Class *self, void *data);
        static PyObject *t_Class_get__classLoader(t_Class *self, void *data);
        static PyObject *t_Class_get__classes(t_Class *self, void *data);
        static PyObject *t_Class_get__componentType(t_Class *self, void *data);
        static PyObject *t_Class_get__declaredClasses(t_Class *self, void *data);
        static PyObject *t_Class_get__declaringClass(t_Class *self, void *data);
        static PyObject *t_Class_get__enclosingClass(t_Class *self, void *data);
        static PyObject *t_Class_get__enum(t_Class *self, void *data);
        static PyObject *t_Class_get__enumConstants(t_Class *self, void *data);
        static PyObject *t_Class_get__interface(t_Class *self, void *data);
        static PyObject *t_Class_get__interfaces(t_Class *self, void *data);
        static PyObject *t_Class_get__localClass(t_Class *self, void *data);
        static PyObject *t_Class_get__memberClass(t_Class *self, void *data);
        static PyObject *t_Class_get__modifiers(t_Class *self, void *data);
        static PyObject *t_Class_get__name(t_Class *self, void *data);
        static PyObject *t_Class_get__package(t_Class *self, void *data);
        static PyObject *t_Class_get__primitive(t_Class *self, void *data);
        static PyObject *t_Class_get__signers(t_Class *self, void *data);
        static PyObject *t_Class_get__simpleName(t_Class *self, void *data);
        static PyObject *t_Class_get__superclass(t_Class *self, void *data);
        static PyObject *t_Class_get__synthetic(t_Class *self, void *data);
        static PyObject *t_Class_get__parameters_(t_Class *self, void *data);
        static PyGetSetDef t_Class__fields_[] = {
            DECLARE_GET_FIELD(t_Class, annotation),
            DECLARE_GET_FIELD(t_Class, anonymousClass),
            DECLARE_GET_FIELD(t_Class, array),
            DECLARE_GET_FIELD(t_Class, canonicalName),
            DECLARE_GET_FIELD(t_Class, classLoader),
            DECLARE_GET_FIELD(t_Class, classes),
            DECLARE_GET_FIELD(t_Class, componentType),
            DECLARE_GET_FIELD(t_Class, declaredClasses),
            DECLARE_GET_FIELD(t_Class, declaringClass),
            DECLARE_GET_FIELD(t_Class, enclosingClass),
            DECLARE_GET_FIELD(t_Class, enum),
            DECLARE_GET_FIELD(t_Class, enumConstants),
            DECLARE_GET_FIELD(t_Class, interface),
            DECLARE_GET_FIELD(t_Class, interfaces),
            DECLARE_GET_FIELD(t_Class, localClass),
            DECLARE_GET_FIELD(t_Class, memberClass),
            DECLARE_GET_FIELD(t_Class, modifiers),
            DECLARE_GET_FIELD(t_Class, name),
            DECLARE_GET_FIELD(t_Class, package),
            DECLARE_GET_FIELD(t_Class, primitive),
            DECLARE_GET_FIELD(t_Class, signers),
            DECLARE_GET_FIELD(t_Class, simpleName),
            DECLARE_GET_FIELD(t_Class, superclass),
            DECLARE_GET_FIELD(t_Class, synthetic),
            DECLARE_GET_FIELD(t_Class, parameters_),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_Class__methods_[] = {
            DECLARE_METHOD(t_Class, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Class, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Class, of_, METH_VARARGS),
            DECLARE_METHOD(t_Class, asSubclass, METH_O),
            DECLARE_METHOD(t_Class, cast, METH_O),
            DECLARE_METHOD(t_Class, desiredAssertionStatus, METH_NOARGS),
            DECLARE_METHOD(t_Class, forName, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Class, getCanonicalName, METH_NOARGS),
            DECLARE_METHOD(t_Class, getClassLoader, METH_NOARGS),
            DECLARE_METHOD(t_Class, getClasses, METH_NOARGS),
            DECLARE_METHOD(t_Class, getComponentType, METH_NOARGS),
            DECLARE_METHOD(t_Class, getDeclaredClasses, METH_NOARGS),
            DECLARE_METHOD(t_Class, getDeclaringClass, METH_NOARGS),
            DECLARE_METHOD(t_Class, getEnclosingClass, METH_NOARGS),
            DECLARE_METHOD(t_Class, getEnumConstants, METH_NOARGS),
            DECLARE_METHOD(t_Class, getInterfaces, METH_NOARGS),
            DECLARE_METHOD(t_Class, getModifiers, METH_NOARGS),
            DECLARE_METHOD(t_Class, getName, METH_NOARGS),
            DECLARE_METHOD(t_Class, getPackage, METH_NOARGS),
            DECLARE_METHOD(t_Class, getSigners, METH_NOARGS),
            DECLARE_METHOD(t_Class, getSimpleName, METH_NOARGS),
            DECLARE_METHOD(t_Class, getSuperclass, METH_NOARGS),
            DECLARE_METHOD(t_Class, isAnnotation, METH_NOARGS),
            DECLARE_METHOD(t_Class, isAnonymousClass, METH_NOARGS),
            DECLARE_METHOD(t_Class, isArray, METH_NOARGS),
            DECLARE_METHOD(t_Class, isAssignableFrom, METH_O),
            DECLARE_METHOD(t_Class, isEnum, METH_NOARGS),
            DECLARE_METHOD(t_Class, isInstance, METH_O),
            DECLARE_METHOD(t_Class, isInterface, METH_NOARGS),
            DECLARE_METHOD(t_Class, isLocalClass, METH_NOARGS),
            DECLARE_METHOD(t_Class, isMemberClass, METH_NOARGS),
            DECLARE_METHOD(t_Class, isPrimitive, METH_NOARGS),
            DECLARE_METHOD(t_Class, isSynthetic, METH_NOARGS),
            DECLARE_METHOD(t_Class, newInstance, METH_NOARGS),
            DECLARE_METHOD(t_Class, toString, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Class, t_Class, ::java::lang::Object, Class, abstract_init, 0, 0, t_Class__fields_, 0, 0);
        PyObject *t_Class::wrap_Object(const Class& object, PyTypeObject *T)
        {
            PyObject *obj = t_Class::wrap_Object(object);
            if (obj != NULL && obj != Py_None)
            {
                t_Class *self = (t_Class *) obj;
                self->parameters[0] = T;
            }
            return obj;
        }

        PyObject *t_Class::wrap_jobject(const jobject& object, PyTypeObject *T)
        {
            PyObject *obj = t_Class::wrap_jobject(object);
            if (obj != NULL && obj != Py_None)
            {
                t_Class *self = (t_Class *) obj;
                self->parameters[0] = T;
            }
            return obj;
        }

        void t_Class::install(PyObject *module)
        {
            installType(&PY_TYPE(Class), module, "Class", 0);
        }

        void t_Class::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Class).tp_dict, "class_", make_descriptor(Class::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Class).tp_dict, "wrapfn_", make_descriptor(t_Class::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(Class).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_Class_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Class::initializeClass, 1)))
                return NULL;
            return t_Class::wrap_Object(Class(((t_Class *) arg)->object.this$));
        }
        static PyObject *t_Class_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Class::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static PyObject *t_Class_of_(t_Class *self, PyObject *args)
        {
            if (!parseArg(args, "T", 1, &(self->parameters)))
                Py_RETURN_SELF;
            return PyErr_SetArgsError((PyObject *) self, "of_", args);
        }

        static PyObject *t_Class_asSubclass(t_Class *self, PyObject *arg)
        {
            Class a0((jobject) NULL);
            PyTypeObject **p0;
            Class result((jobject) NULL);

            if (!parseArg(arg, "K", Class::initializeClass, &a0, &p0, t_Class::parameters_))
            {
                OBJ_CALL(result = self->object.asSubclass(a0));
                return t_Class::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "asSubclass", arg);
            return NULL;
        }

        static PyObject *t_Class_cast(t_Class *self, PyObject *arg)
        {
            ::java::lang::Object a0((jobject) NULL);
            ::java::lang::Object result((jobject) NULL);

            if (!parseArg(arg, "o", &a0))
            {
                OBJ_CALL(result = self->object.cast(a0));
                return self->parameters[0] != NULL ? wrapType(self->parameters[0], result.this$) : ::java::lang::t_Object::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "cast", arg);
            return NULL;
        }

        static PyObject *t_Class_desiredAssertionStatus(t_Class *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.desiredAssertionStatus());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Class_forName(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    Class result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Class::forName(a0));
                        return t_Class::wrap_Object(result);
                    }
                }
                break;
              case 3:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jboolean a1;
                    ::java::lang::ClassLoader a2((jobject) NULL);
                    Class result((jobject) NULL);

                    if (!parseArgs(args, "sZk", ::java::lang::ClassLoader::initializeClass, &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = ::java::lang::Class::forName(a0, a1, a2));
                        return t_Class::wrap_Object(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "forName", args);
            return NULL;
        }

        static PyObject *t_Class_getCanonicalName(t_Class *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getCanonicalName());
            return j2p(result);
        }

        static PyObject *t_Class_getClassLoader(t_Class *self)
        {
            ::java::lang::ClassLoader result((jobject) NULL);
            OBJ_CALL(result = self->object.getClassLoader());
            return ::java::lang::t_ClassLoader::wrap_Object(result);
        }

        static PyObject *t_Class_getClasses(t_Class *self)
        {
            JArray< Class > result((jobject) NULL);
            OBJ_CALL(result = self->object.getClasses());
            return JArray<jobject>(result.this$).wrap(t_Class::wrap_jobject);
        }

        static PyObject *t_Class_getComponentType(t_Class *self)
        {
            Class result((jobject) NULL);
            OBJ_CALL(result = self->object.getComponentType());
            return t_Class::wrap_Object(result);
        }

        static PyObject *t_Class_getDeclaredClasses(t_Class *self)
        {
            JArray< Class > result((jobject) NULL);
            OBJ_CALL(result = self->object.getDeclaredClasses());
            return JArray<jobject>(result.this$).wrap(t_Class::wrap_jobject);
        }

        static PyObject *t_Class_getDeclaringClass(t_Class *self)
        {
            Class result((jobject) NULL);
            OBJ_CALL(result = self->object.getDeclaringClass());
            return t_Class::wrap_Object(result);
        }

        static PyObject *t_Class_getEnclosingClass(t_Class *self)
        {
            Class result((jobject) NULL);
            OBJ_CALL(result = self->object.getEnclosingClass());
            return t_Class::wrap_Object(result);
        }

        static PyObject *t_Class_getEnumConstants(t_Class *self)
        {
            JArray< ::java::lang::Object > result((jobject) NULL);
            OBJ_CALL(result = self->object.getEnumConstants());
            return JArray<jobject>(result.this$).wrap(::java::lang::t_Object::wrap_jobject);
        }

        static PyObject *t_Class_getInterfaces(t_Class *self)
        {
            JArray< Class > result((jobject) NULL);
            OBJ_CALL(result = self->object.getInterfaces());
            return JArray<jobject>(result.this$).wrap(t_Class::wrap_jobject);
        }

        static PyObject *t_Class_getModifiers(t_Class *self)
        {
            jint result;
            OBJ_CALL(result = self->object.getModifiers());
            return PyInt_FromLong((long) result);
        }

        static PyObject *t_Class_getName(t_Class *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getName());
            return j2p(result);
        }

        static PyObject *t_Class_getPackage(t_Class *self)
        {
            ::java::lang::Package result((jobject) NULL);
            OBJ_CALL(result = self->object.getPackage());
            return ::java::lang::t_Package::wrap_Object(result);
        }

        static PyObject *t_Class_getSigners(t_Class *self)
        {
            JArray< ::java::lang::Object > result((jobject) NULL);
            OBJ_CALL(result = self->object.getSigners());
            return JArray<jobject>(result.this$).wrap(::java::lang::t_Object::wrap_jobject);
        }

        static PyObject *t_Class_getSimpleName(t_Class *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getSimpleName());
            return j2p(result);
        }

        static PyObject *t_Class_getSuperclass(t_Class *self)
        {
            Class result((jobject) NULL);
            OBJ_CALL(result = self->object.getSuperclass());
            return t_Class::wrap_Object(result);
        }

        static PyObject *t_Class_isAnnotation(t_Class *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isAnnotation());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Class_isAnonymousClass(t_Class *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isAnonymousClass());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Class_isArray(t_Class *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isArray());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Class_isAssignableFrom(t_Class *self, PyObject *arg)
        {
            Class a0((jobject) NULL);
            PyTypeObject **p0;
            jboolean result;

            if (!parseArg(arg, "K", Class::initializeClass, &a0, &p0, t_Class::parameters_))
            {
                OBJ_CALL(result = self->object.isAssignableFrom(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError((PyObject *) self, "isAssignableFrom", arg);
            return NULL;
        }

        static PyObject *t_Class_isEnum(t_Class *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isEnum());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Class_isInstance(t_Class *self, PyObject *arg)
        {
            ::java::lang::Object a0((jobject) NULL);
            jboolean result;

            if (!parseArg(arg, "o", &a0))
            {
                OBJ_CALL(result = self->object.isInstance(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError((PyObject *) self, "isInstance", arg);
            return NULL;
        }

        static PyObject *t_Class_isInterface(t_Class *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isInterface());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Class_isLocalClass(t_Class *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isLocalClass());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Class_isMemberClass(t_Class *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isMemberClass());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Class_isPrimitive(t_Class *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isPrimitive());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Class_isSynthetic(t_Class *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isSynthetic());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Class_newInstance(t_Class *self)
        {
            ::java::lang::Object result((jobject) NULL);
            OBJ_CALL(result = self->object.newInstance());
            return self->parameters[0] != NULL ? wrapType(self->parameters[0], result.this$) : ::java::lang::t_Object::wrap_Object(result);
        }

        static PyObject *t_Class_toString(t_Class *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(Class), (PyObject *) self, "toString", args, 2);
        }
        static PyObject *t_Class_get__parameters_(t_Class *self, void *data)
        {
            return typeParameters(self->parameters, sizeof(self->parameters));
        }

        static PyObject *t_Class_get__annotation(t_Class *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isAnnotation());
            Py_RETURN_BOOL(value);
        }

        static PyObject *t_Class_get__anonymousClass(t_Class *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isAnonymousClass());
            Py_RETURN_BOOL(value);
        }

        static PyObject *t_Class_get__array(t_Class *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isArray());
            Py_RETURN_BOOL(value);
        }

        static PyObject *t_Class_get__canonicalName(t_Class *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getCanonicalName());
            return j2p(value);
        }

        static PyObject *t_Class_get__classLoader(t_Class *self, void *data)
        {
            ::java::lang::ClassLoader value((jobject) NULL);
            OBJ_CALL(value = self->object.getClassLoader());
            return ::java::lang::t_ClassLoader::wrap_Object(value);
        }

        static PyObject *t_Class_get__classes(t_Class *self, void *data)
        {
            JArray< Class > value((jobject) NULL);
            OBJ_CALL(value = self->object.getClasses());
            return JArray<jobject>(value.this$).wrap(t_Class::wrap_jobject);
        }

        static PyObject *t_Class_get__componentType(t_Class *self, void *data)
        {
            Class value((jobject) NULL);
            OBJ_CALL(value = self->object.getComponentType());
            return t_Class::wrap_Object(value);
        }

        static PyObject *t_Class_get__declaredClasses(t_Class *self, void *data)
        {
            JArray< Class > value((jobject) NULL);
            OBJ_CALL(value = self->object.getDeclaredClasses());
            return JArray<jobject>(value.this$).wrap(t_Class::wrap_jobject);
        }

        static PyObject *t_Class_get__declaringClass(t_Class *self, void *data)
        {
            Class value((jobject) NULL);
            OBJ_CALL(value = self->object.getDeclaringClass());
            return t_Class::wrap_Object(value);
        }

        static PyObject *t_Class_get__enclosingClass(t_Class *self, void *data)
        {
            Class value((jobject) NULL);
            OBJ_CALL(value = self->object.getEnclosingClass());
            return t_Class::wrap_Object(value);
        }

        static PyObject *t_Class_get__enum(t_Class *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isEnum());
            Py_RETURN_BOOL(value);
        }

        static PyObject *t_Class_get__enumConstants(t_Class *self, void *data)
        {
            JArray< ::java::lang::Object > value((jobject) NULL);
            OBJ_CALL(value = self->object.getEnumConstants());
            return JArray<jobject>(value.this$).wrap(::java::lang::t_Object::wrap_jobject);
        }

        static PyObject *t_Class_get__interface(t_Class *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isInterface());
            Py_RETURN_BOOL(value);
        }

        static PyObject *t_Class_get__interfaces(t_Class *self, void *data)
        {
            JArray< Class > value((jobject) NULL);
            OBJ_CALL(value = self->object.getInterfaces());
            return JArray<jobject>(value.this$).wrap(t_Class::wrap_jobject);
        }

        static PyObject *t_Class_get__localClass(t_Class *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isLocalClass());
            Py_RETURN_BOOL(value);
        }

        static PyObject *t_Class_get__memberClass(t_Class *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isMemberClass());
            Py_RETURN_BOOL(value);
        }

        static PyObject *t_Class_get__modifiers(t_Class *self, void *data)
        {
            jint value;
            OBJ_CALL(value = self->object.getModifiers());
            return PyInt_FromLong((long) value);
        }

        static PyObject *t_Class_get__name(t_Class *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getName());
            return j2p(value);
        }

        static PyObject *t_Class_get__package(t_Class *self, void *data)
        {
            ::java::lang::Package value((jobject) NULL);
            OBJ_CALL(value = self->object.getPackage());
            return ::java::lang::t_Package::wrap_Object(value);
        }

        static PyObject *t_Class_get__primitive(t_Class *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isPrimitive());
            Py_RETURN_BOOL(value);
        }

        static PyObject *t_Class_get__signers(t_Class *self, void *data)
        {
            JArray< ::java::lang::Object > value((jobject) NULL);
            OBJ_CALL(value = self->object.getSigners());
            return JArray<jobject>(value.this$).wrap(::java::lang::t_Object::wrap_jobject);
        }

        static PyObject *t_Class_get__simpleName(t_Class *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getSimpleName());
            return j2p(value);
        }

        static PyObject *t_Class_get__superclass(t_Class *self, void *data)
        {
            Class value((jobject) NULL);
            OBJ_CALL(value = self->object.getSuperclass());
            return t_Class::wrap_Object(value);
        }

        static PyObject *t_Class_get__synthetic(t_Class *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isSynthetic());
            Py_RETURN_BOOL(value);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "ScalaUtils$$anonfun$1.h"
#include "scala/Serializable.h"
#include "java/lang/Class.h"
#include "java/lang/Object.h"
#include "JArray.h"


::java::lang::Class *ScalaUtils$$anonfun$1::class$ = NULL;
jmethodID *ScalaUtils$$anonfun$1::mids$ = NULL;
jlong ScalaUtils$$anonfun$1::serialVersionUID = (jlong) 0;

jclass ScalaUtils$$anonfun$1::initializeClass()
{
    if (!class$)
    {

        jclass cls = (jclass) env->findClass("ScalaUtils$$anonfun$1");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_apply_a932a95f] = env->getMethodID(cls, "apply", "(Ljava/lang/Object;)Ljava/lang/Object;");
        mids$[mid_apply_5d1c765a] = env->getMethodID(cls, "apply", "(D)I");
        mids$[mid_apply$mcID$sp_5d1c765a] = env->getMethodID(cls, "apply$mcID$sp", "(D)I");

        class$ = (::java::lang::Class *) new JObject(cls);
        cls = (jclass) class$->this$;

        serialVersionUID = env->getStaticLongField(cls, "serialVersionUID");
    }
    return (jclass) class$->this$;
}

ScalaUtils$$anonfun$1::ScalaUtils$$anonfun$1() : ::scala::runtime::AbstractFunction1$mcID$sp(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

::java::lang::Object ScalaUtils$$anonfun$1::apply(const ::java::lang::Object & a0) const
{
    return ::java::lang::Object(env->callObjectMethod(this$, mids$[mid_apply_a932a95f], a0.this$));
}

jint ScalaUtils$$anonfun$1::apply(jdouble a0) const
{
    return env->callIntMethod(this$, mids$[mid_apply_5d1c765a], a0);
}

jint ScalaUtils$$anonfun$1::apply$mcID$sp(jdouble a0) const
{
    return env->callIntMethod(this$, mids$[mid_apply$mcID$sp_5d1c765a], a0);
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

static PyObject *t_ScalaUtils$$anonfun$1_cast_(PyTypeObject *type, PyObject *arg);
static PyObject *t_ScalaUtils$$anonfun$1_instance_(PyTypeObject *type, PyObject *arg);
static int t_ScalaUtils$$anonfun$1_init_(t_ScalaUtils$$anonfun$1 *self, PyObject *args, PyObject *kwds);
static PyObject *t_ScalaUtils$$anonfun$1_apply(t_ScalaUtils$$anonfun$1 *self, PyObject *args);
static PyObject *t_ScalaUtils$$anonfun$1_apply$mcID$sp(t_ScalaUtils$$anonfun$1 *self, PyObject *args);

static PyMethodDef t_ScalaUtils$$anonfun$1__methods_[] = {
    DECLARE_METHOD(t_ScalaUtils$$anonfun$1, cast_, METH_O | METH_CLASS),
    DECLARE_METHOD(t_ScalaUtils$$anonfun$1, instance_, METH_O | METH_CLASS),
    DECLARE_METHOD(t_ScalaUtils$$anonfun$1, apply, METH_VARARGS),
    DECLARE_METHOD(t_ScalaUtils$$anonfun$1, apply$mcID$sp, METH_VARARGS),
    { NULL, NULL, 0, NULL }
};

DECLARE_TYPE(ScalaUtils$$anonfun$1, t_ScalaUtils$$anonfun$1, ::scala::runtime::AbstractFunction1$mcID$sp, ScalaUtils$$anonfun$1, t_ScalaUtils$$anonfun$1_init_, 0, 0, 0, 0, 0);

void t_ScalaUtils$$anonfun$1::install(PyObject *module)
{
    installType(&PY_TYPE(ScalaUtils$$anonfun$1), module, "ScalaUtils$$anonfun$1", 0);
}

void t_ScalaUtils$$anonfun$1::initialize(PyObject *module)
{
    PyDict_SetItemString(PY_TYPE(ScalaUtils$$anonfun$1).tp_dict, "class_", make_descriptor(ScalaUtils$$anonfun$1::initializeClass, 1));
    PyDict_SetItemString(PY_TYPE(ScalaUtils$$anonfun$1).tp_dict, "wrapfn_", make_descriptor(t_ScalaUtils$$anonfun$1::wrap_jobject));
    PyDict_SetItemString(PY_TYPE(ScalaUtils$$anonfun$1).tp_dict, "boxfn_", make_descriptor(boxObject));
    ScalaUtils$$anonfun$1::initializeClass();
    PyDict_SetItemString(PY_TYPE(ScalaUtils$$anonfun$1).tp_dict, "serialVersionUID", make_descriptor(ScalaUtils$$anonfun$1::serialVersionUID));
}

static PyObject *t_ScalaUtils$$anonfun$1_cast_(PyTypeObject *type, PyObject *arg)
{
    if (!(arg = castCheck(arg, ScalaUtils$$anonfun$1::initializeClass, 1)))
        return NULL;
    return t_ScalaUtils$$anonfun$1::wrap_Object(ScalaUtils$$anonfun$1(((t_ScalaUtils$$anonfun$1 *) arg)->object.this$));
}
static PyObject *t_ScalaUtils$$anonfun$1_instance_(PyTypeObject *type, PyObject *arg)
{
    if (!castCheck(arg, ScalaUtils$$anonfun$1::initializeClass, 0))
        Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}

static int t_ScalaUtils$$anonfun$1_init_(t_ScalaUtils$$anonfun$1 *self, PyObject *args, PyObject *kwds)
{
    ScalaUtils$$anonfun$1 object((jobject) NULL);

    INT_CALL(object = ScalaUtils$$anonfun$1());
    self->object = object;

    return 0;
}

static PyObject *t_ScalaUtils$$anonfun$1_apply(t_ScalaUtils$$anonfun$1 *self, PyObject *args)
{
    switch (PyTuple_GET_SIZE(args)) {
      case 1:
        {
            ::java::lang::Object a0((jobject) NULL);
            ::java::lang::Object result((jobject) NULL);

            if (!parseArgs(args, "o", &a0))
            {
                OBJ_CALL(result = self->object.apply(a0));
                return ::java::lang::t_Object::wrap_Object(result);
            }
        }
        {
            jdouble a0;
            jint result;

            if (!parseArgs(args, "D", &a0))
            {
                OBJ_CALL(result = self->object.apply(a0));
                return PyInt_FromLong((long) result);
            }
        }
    }

    return callSuper(&PY_TYPE(ScalaUtils$$anonfun$1), (PyObject *) self, "apply", args, 2);
}

static PyObject *t_ScalaUtils$$anonfun$1_apply$mcID$sp(t_ScalaUtils$$anonfun$1 *self, PyObject *args)
{
    jdouble a0;
    jint result;

    if (!parseArgs(args, "D", &a0))
    {
        OBJ_CALL(result = self->object.apply$mcID$sp(a0));
        return PyInt_FromLong((long) result);
    }

    return callSuper(&PY_TYPE(ScalaUtils$$anonfun$1), (PyObject *) self, "apply$mcID$sp", args, 2);
}
#include <jni.h>
#include "JCCEnv.h"
#include "ScalaUtils$.h"
#include "scala/ScalaObject.h"
#include "java/lang/Class.h"
#include "scala/Function1.h"
#include "JArray.h"


::java::lang::Class *ScalaUtils$::class$ = NULL;
jmethodID *ScalaUtils$::mids$ = NULL;
ScalaUtils$ *ScalaUtils$::MODULE$ = NULL;

jclass ScalaUtils$::initializeClass()
{
    if (!class$)
    {

        jclass cls = (jclass) env->findClass("ScalaUtils$");

        mids$ = new jmethodID[max_mid];
        mids$[mid_ageGroupFunction_c83f65c1] = env->getMethodID(cls, "ageGroupFunction", "()Lscala/Function1;");
        mids$[mid_ageGroupMethod_5d1c765a] = env->getMethodID(cls, "ageGroupMethod", "(D)I");
        mids$[mid_reptileAgeGroupFunctionMaker_279d294f] = env->getMethodID(cls, "reptileAgeGroupFunctionMaker", "(Lscala/Function1;)Lscala/Function1;");

        class$ = (::java::lang::Class *) new JObject(cls);
        cls = (jclass) class$->this$;

        MODULE$ = new ScalaUtils$(env->getStaticObjectField(cls, "MODULE$", "LScalaUtils$;"));
    }
    return (jclass) class$->this$;
}

::scala::Function1 ScalaUtils$::ageGroupFunction() const
{
    return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_ageGroupFunction_c83f65c1]));
}

jint ScalaUtils$::ageGroupMethod(jdouble a0) const
{
    return env->callIntMethod(this$, mids$[mid_ageGroupMethod_5d1c765a], a0);
}

::scala::Function1 ScalaUtils$::reptileAgeGroupFunctionMaker(const ::scala::Function1 & a0) const
{
    return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_reptileAgeGroupFunctionMaker_279d294f], a0.this$));
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

static PyObject *t_ScalaUtils$_cast_(PyTypeObject *type, PyObject *arg);
static PyObject *t_ScalaUtils$_instance_(PyTypeObject *type, PyObject *arg);
static PyObject *t_ScalaUtils$_ageGroupFunction(t_ScalaUtils$ *self);
static PyObject *t_ScalaUtils$_ageGroupMethod(t_ScalaUtils$ *self, PyObject *arg);
static PyObject *t_ScalaUtils$_reptileAgeGroupFunctionMaker(t_ScalaUtils$ *self, PyObject *arg);

static PyMethodDef t_ScalaUtils$__methods_[] = {
    DECLARE_METHOD(t_ScalaUtils$, cast_, METH_O | METH_CLASS),
    DECLARE_METHOD(t_ScalaUtils$, instance_, METH_O | METH_CLASS),
    DECLARE_METHOD(t_ScalaUtils$, ageGroupFunction, METH_NOARGS),
    DECLARE_METHOD(t_ScalaUtils$, ageGroupMethod, METH_O),
    DECLARE_METHOD(t_ScalaUtils$, reptileAgeGroupFunctionMaker, METH_O),
    { NULL, NULL, 0, NULL }
};

DECLARE_TYPE(ScalaUtils$, t_ScalaUtils$, ::java::lang::Object, ScalaUtils$, abstract_init, 0, 0, 0, 0, 0);

void t_ScalaUtils$::install(PyObject *module)
{
    installType(&PY_TYPE(ScalaUtils$), module, "ScalaUtils$", 0);
}

void t_ScalaUtils$::initialize(PyObject *module)
{
    PyDict_SetItemString(PY_TYPE(ScalaUtils$).tp_dict, "class_", make_descriptor(ScalaUtils$::initializeClass, 1));
    PyDict_SetItemString(PY_TYPE(ScalaUtils$).tp_dict, "wrapfn_", make_descriptor(t_ScalaUtils$::wrap_jobject));
    PyDict_SetItemString(PY_TYPE(ScalaUtils$).tp_dict, "boxfn_", make_descriptor(boxObject));
    ScalaUtils$::initializeClass();
    PyDict_SetItemString(PY_TYPE(ScalaUtils$).tp_dict, "MODULE$", make_descriptor(t_ScalaUtils$::wrap_Object(*ScalaUtils$::MODULE$)));
}

static PyObject *t_ScalaUtils$_cast_(PyTypeObject *type, PyObject *arg)
{
    if (!(arg = castCheck(arg, ScalaUtils$::initializeClass, 1)))
        return NULL;
    return t_ScalaUtils$::wrap_Object(ScalaUtils$(((t_ScalaUtils$ *) arg)->object.this$));
}
static PyObject *t_ScalaUtils$_instance_(PyTypeObject *type, PyObject *arg)
{
    if (!castCheck(arg, ScalaUtils$::initializeClass, 0))
        Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}

static PyObject *t_ScalaUtils$_ageGroupFunction(t_ScalaUtils$ *self)
{
    ::scala::Function1 result((jobject) NULL);
    OBJ_CALL(result = self->object.ageGroupFunction());
    return ::scala::t_Function1::wrap_Object(result, &::java::lang::PY_TYPE(Object), &::java::lang::PY_TYPE(Object));
}

static PyObject *t_ScalaUtils$_ageGroupMethod(t_ScalaUtils$ *self, PyObject *arg)
{
    jdouble a0;
    jint result;

    if (!parseArg(arg, "D", &a0))
    {
        OBJ_CALL(result = self->object.ageGroupMethod(a0));
        return PyInt_FromLong((long) result);
    }

    PyErr_SetArgsError((PyObject *) self, "ageGroupMethod", arg);
    return NULL;
}

static PyObject *t_ScalaUtils$_reptileAgeGroupFunctionMaker(t_ScalaUtils$ *self, PyObject *arg)
{
    ::scala::Function1 a0((jobject) NULL);
    PyTypeObject **p0;
    ::scala::Function1 result((jobject) NULL);

    if (!parseArg(arg, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
    {
        OBJ_CALL(result = self->object.reptileAgeGroupFunctionMaker(a0));
        return ::scala::t_Function1::wrap_Object(result, &::java::lang::PY_TYPE(Object), &::java::lang::PY_TYPE(Object));
    }

    PyErr_SetArgsError((PyObject *) self, "reptileAgeGroupFunctionMaker", arg);
    return NULL;
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Long.h"
#include "java/lang/String.h"
#include "java/lang/Comparable.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/Class.h"
#include "java/lang/Object.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Long::class$ = NULL;
        jmethodID *Long::mids$ = NULL;
        jlong Long::MAX_VALUE = (jlong) 0;
        jlong Long::MIN_VALUE = (jlong) 0;
        jint Long::SIZE = (jint) 0;
        ::java::lang::Class *Long::TYPE = NULL;

        jclass Long::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Long");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_0ee6df2f] = env->getMethodID(cls, "<init>", "(J)V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_bitCount_0ee6df30] = env->getStaticMethodID(cls, "bitCount", "(J)I");
                mids$[mid_byteValue_54c6a172] = env->getMethodID(cls, "byteValue", "()B");
                mids$[mid_compareTo_290588f1] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Object;)I");
                mids$[mid_compareTo_da55802e] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Long;)I");
                mids$[mid_decode_ee9f94be] = env->getStaticMethodID(cls, "decode", "(Ljava/lang/String;)Ljava/lang/Long;");
                mids$[mid_doubleValue_54c6a174] = env->getMethodID(cls, "doubleValue", "()D");
                mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
                mids$[mid_floatValue_54c6a176] = env->getMethodID(cls, "floatValue", "()F");
                mids$[mid_getLong_ee9f94be] = env->getStaticMethodID(cls, "getLong", "(Ljava/lang/String;)Ljava/lang/Long;");
                mids$[mid_getLong_9f081a1d] = env->getStaticMethodID(cls, "getLong", "(Ljava/lang/String;J)Ljava/lang/Long;");
                mids$[mid_getLong_9a12142f] = env->getStaticMethodID(cls, "getLong", "(Ljava/lang/String;Ljava/lang/Long;)Ljava/lang/Long;");
                mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
                mids$[mid_highestOneBit_0ee6df33] = env->getStaticMethodID(cls, "highestOneBit", "(J)J");
                mids$[mid_intValue_54c6a179] = env->getMethodID(cls, "intValue", "()I");
                mids$[mid_longValue_54c6a17a] = env->getMethodID(cls, "longValue", "()J");
                mids$[mid_lowestOneBit_0ee6df33] = env->getStaticMethodID(cls, "lowestOneBit", "(J)J");
                mids$[mid_numberOfLeadingZeros_0ee6df30] = env->getStaticMethodID(cls, "numberOfLeadingZeros", "(J)I");
                mids$[mid_numberOfTrailingZeros_0ee6df30] = env->getStaticMethodID(cls, "numberOfTrailingZeros", "(J)I");
                mids$[mid_parseLong_5fdc3f54] = env->getStaticMethodID(cls, "parseLong", "(Ljava/lang/String;)J");
                mids$[mid_parseLong_6e53ccda] = env->getStaticMethodID(cls, "parseLong", "(Ljava/lang/String;I)J");
                mids$[mid_reverse_0ee6df33] = env->getStaticMethodID(cls, "reverse", "(J)J");
                mids$[mid_reverseBytes_0ee6df33] = env->getStaticMethodID(cls, "reverseBytes", "(J)J");
                mids$[mid_rotateLeft_25d05c93] = env->getStaticMethodID(cls, "rotateLeft", "(JI)J");
                mids$[mid_rotateRight_25d05c93] = env->getStaticMethodID(cls, "rotateRight", "(JI)J");
                mids$[mid_shortValue_54c6a163] = env->getMethodID(cls, "shortValue", "()S");
                mids$[mid_signum_0ee6df30] = env->getStaticMethodID(cls, "signum", "(J)I");
                mids$[mid_toBinaryString_3e02f30e] = env->getStaticMethodID(cls, "toBinaryString", "(J)Ljava/lang/String;");
                mids$[mid_toHexString_3e02f30e] = env->getStaticMethodID(cls, "toHexString", "(J)Ljava/lang/String;");
                mids$[mid_toOctalString_3e02f30e] = env->getStaticMethodID(cls, "toOctalString", "(J)Ljava/lang/String;");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
                mids$[mid_toString_3e02f30e] = env->getStaticMethodID(cls, "toString", "(J)Ljava/lang/String;");
                mids$[mid_toString_36a2b01a] = env->getStaticMethodID(cls, "toString", "(JI)Ljava/lang/String;");
                mids$[mid_valueOf_62a69723] = env->getStaticMethodID(cls, "valueOf", "(J)Ljava/lang/Long;");
                mids$[mid_valueOf_ee9f94be] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Ljava/lang/Long;");
                mids$[mid_valueOf_212f058c] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;I)Ljava/lang/Long;");

                class$ = (::java::lang::Class *) new JObject(cls);
                cls = (jclass) class$->this$;

                MAX_VALUE = env->getStaticLongField(cls, "MAX_VALUE");
                MIN_VALUE = env->getStaticLongField(cls, "MIN_VALUE");
                SIZE = env->getStaticIntField(cls, "SIZE");
                TYPE = new ::java::lang::Class(env->getStaticObjectField(cls, "TYPE", "Ljava/lang/Class;"));
            }
            return (jclass) class$->this$;
        }

        Long::Long(jlong a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_0ee6df2f, a0)) {}

        Long::Long(const ::java::lang::String & a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        jint Long::bitCount(jlong a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_bitCount_0ee6df30], a0);
        }

        jbyte Long::byteValue() const
        {
            return env->callByteMethod(this$, mids$[mid_byteValue_54c6a172]);
        }

        jint Long::compareTo(const ::java::lang::Object & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_290588f1], a0.this$);
        }

        jint Long::compareTo(const Long & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_da55802e], a0.this$);
        }

        Long Long::decode(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Long(env->callStaticObjectMethod(cls, mids$[mid_decode_ee9f94be], a0.this$));
        }

        jdouble Long::doubleValue() const
        {
            return env->callDoubleMethod(this$, mids$[mid_doubleValue_54c6a174]);
        }

        jboolean Long::equals(const ::java::lang::Object & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
        }

        jfloat Long::floatValue() const
        {
            return env->callFloatMethod(this$, mids$[mid_floatValue_54c6a176]);
        }

        Long Long::getLong(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Long(env->callStaticObjectMethod(cls, mids$[mid_getLong_ee9f94be], a0.this$));
        }

        Long Long::getLong(const ::java::lang::String & a0, jlong a1)
        {
            jclass cls = initializeClass();
            return Long(env->callStaticObjectMethod(cls, mids$[mid_getLong_9f081a1d], a0.this$, a1));
        }

        Long Long::getLong(const ::java::lang::String & a0, const Long & a1)
        {
            jclass cls = initializeClass();
            return Long(env->callStaticObjectMethod(cls, mids$[mid_getLong_9a12142f], a0.this$, a1.this$));
        }

        jint Long::hashCode() const
        {
            return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
        }

        jlong Long::highestOneBit(jlong a0)
        {
            jclass cls = initializeClass();
            return env->callStaticLongMethod(cls, mids$[mid_highestOneBit_0ee6df33], a0);
        }

        jint Long::intValue() const
        {
            return env->callIntMethod(this$, mids$[mid_intValue_54c6a179]);
        }

        jlong Long::longValue() const
        {
            return env->callLongMethod(this$, mids$[mid_longValue_54c6a17a]);
        }

        jlong Long::lowestOneBit(jlong a0)
        {
            jclass cls = initializeClass();
            return env->callStaticLongMethod(cls, mids$[mid_lowestOneBit_0ee6df33], a0);
        }

        jint Long::numberOfLeadingZeros(jlong a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_numberOfLeadingZeros_0ee6df30], a0);
        }

        jint Long::numberOfTrailingZeros(jlong a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_numberOfTrailingZeros_0ee6df30], a0);
        }

        jlong Long::parseLong(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return env->callStaticLongMethod(cls, mids$[mid_parseLong_5fdc3f54], a0.this$);
        }

        jlong Long::parseLong(const ::java::lang::String & a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticLongMethod(cls, mids$[mid_parseLong_6e53ccda], a0.this$, a1);
        }

        jlong Long::reverse(jlong a0)
        {
            jclass cls = initializeClass();
            return env->callStaticLongMethod(cls, mids$[mid_reverse_0ee6df33], a0);
        }

        jlong Long::reverseBytes(jlong a0)
        {
            jclass cls = initializeClass();
            return env->callStaticLongMethod(cls, mids$[mid_reverseBytes_0ee6df33], a0);
        }

        jlong Long::rotateLeft(jlong a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticLongMethod(cls, mids$[mid_rotateLeft_25d05c93], a0, a1);
        }

        jlong Long::rotateRight(jlong a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticLongMethod(cls, mids$[mid_rotateRight_25d05c93], a0, a1);
        }

        jshort Long::shortValue() const
        {
            return env->callShortMethod(this$, mids$[mid_shortValue_54c6a163]);
        }

        jint Long::signum(jlong a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_signum_0ee6df30], a0);
        }

        ::java::lang::String Long::toBinaryString(jlong a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toBinaryString_3e02f30e], a0));
        }

        ::java::lang::String Long::toHexString(jlong a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toHexString_3e02f30e], a0));
        }

        ::java::lang::String Long::toOctalString(jlong a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toOctalString_3e02f30e], a0));
        }

        ::java::lang::String Long::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }

        ::java::lang::String Long::toString(jlong a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_3e02f30e], a0));
        }

        ::java::lang::String Long::toString(jlong a0, jint a1)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_36a2b01a], a0, a1));
        }

        Long Long::valueOf(jlong a0)
        {
            jclass cls = initializeClass();
            return Long(env->callStaticObjectMethod(cls, mids$[mid_valueOf_62a69723], a0));
        }

        Long Long::valueOf(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Long(env->callStaticObjectMethod(cls, mids$[mid_valueOf_ee9f94be], a0.this$));
        }

        Long Long::valueOf(const ::java::lang::String & a0, jint a1)
        {
            jclass cls = initializeClass();
            return Long(env->callStaticObjectMethod(cls, mids$[mid_valueOf_212f058c], a0.this$, a1));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Long_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Long_instance_(PyTypeObject *type, PyObject *arg);
        static int t_Long_init_(t_Long *self, PyObject *args, PyObject *kwds);
        static PyObject *t_Long_bitCount(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Long_byteValue(t_Long *self, PyObject *args);
        static PyObject *t_Long_compareTo(t_Long *self, PyObject *args);
        static PyObject *t_Long_decode(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Long_doubleValue(t_Long *self, PyObject *args);
        static PyObject *t_Long_equals(t_Long *self, PyObject *args);
        static PyObject *t_Long_floatValue(t_Long *self, PyObject *args);
        static PyObject *t_Long_getLong(PyTypeObject *type, PyObject *args);
        static PyObject *t_Long_hashCode(t_Long *self, PyObject *args);
        static PyObject *t_Long_highestOneBit(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Long_intValue(t_Long *self, PyObject *args);
        static PyObject *t_Long_longValue(t_Long *self, PyObject *args);
        static PyObject *t_Long_lowestOneBit(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Long_numberOfLeadingZeros(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Long_numberOfTrailingZeros(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Long_parseLong(PyTypeObject *type, PyObject *args);
        static PyObject *t_Long_reverse(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Long_reverseBytes(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Long_rotateLeft(PyTypeObject *type, PyObject *args);
        static PyObject *t_Long_rotateRight(PyTypeObject *type, PyObject *args);
        static PyObject *t_Long_shortValue(t_Long *self, PyObject *args);
        static PyObject *t_Long_signum(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Long_toBinaryString(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Long_toHexString(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Long_toOctalString(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Long_toString(t_Long *self, PyObject *args);
        static PyObject *t_Long_toString_(PyTypeObject *type, PyObject *args);
        static PyObject *t_Long_valueOf(PyTypeObject *type, PyObject *args);

        static PyMethodDef t_Long__methods_[] = {
            DECLARE_METHOD(t_Long, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Long, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Long, bitCount, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Long, byteValue, METH_VARARGS),
            DECLARE_METHOD(t_Long, compareTo, METH_VARARGS),
            DECLARE_METHOD(t_Long, decode, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Long, doubleValue, METH_VARARGS),
            DECLARE_METHOD(t_Long, equals, METH_VARARGS),
            DECLARE_METHOD(t_Long, floatValue, METH_VARARGS),
            DECLARE_METHOD(t_Long, getLong, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Long, hashCode, METH_VARARGS),
            DECLARE_METHOD(t_Long, highestOneBit, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Long, intValue, METH_VARARGS),
            DECLARE_METHOD(t_Long, longValue, METH_VARARGS),
            DECLARE_METHOD(t_Long, lowestOneBit, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Long, numberOfLeadingZeros, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Long, numberOfTrailingZeros, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Long, parseLong, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Long, reverse, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Long, reverseBytes, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Long, rotateLeft, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Long, rotateRight, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Long, shortValue, METH_VARARGS),
            DECLARE_METHOD(t_Long, signum, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Long, toBinaryString, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Long, toHexString, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Long, toOctalString, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Long, toString, METH_VARARGS),
            DECLARE_METHOD(t_Long, toString_, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Long, valueOf, METH_VARARGS | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Long, t_Long, ::java::lang::Number, Long, t_Long_init_, 0, 0, 0, 0, 0);

        void t_Long::install(PyObject *module)
        {
            installType(&PY_TYPE(Long), module, "Long", 0);
        }

        void t_Long::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Long).tp_dict, "class_", make_descriptor(Long::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Long).tp_dict, "wrapfn_", make_descriptor(unboxLong));
            PyDict_SetItemString(PY_TYPE(Long).tp_dict, "boxfn_", make_descriptor(boxLong));
            Long::initializeClass();
            PyDict_SetItemString(PY_TYPE(Long).tp_dict, "MAX_VALUE", make_descriptor(Long::MAX_VALUE));
            PyDict_SetItemString(PY_TYPE(Long).tp_dict, "MIN_VALUE", make_descriptor(Long::MIN_VALUE));
            PyDict_SetItemString(PY_TYPE(Long).tp_dict, "SIZE", make_descriptor(Long::SIZE));
            PyDict_SetItemString(PY_TYPE(Long).tp_dict, "TYPE", make_descriptor(::java::lang::t_Class::wrap_Object(*Long::TYPE)));
        }

        static PyObject *t_Long_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Long::initializeClass, 1)))
                return NULL;
            return t_Long::wrap_Object(Long(((t_Long *) arg)->object.this$));
        }
        static PyObject *t_Long_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Long::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_Long_init_(t_Long *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jlong a0;
                    Long object((jobject) NULL);

                    if (!parseArgs(args, "J", &a0))
                    {
                        INT_CALL(object = Long(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Long object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = Long(a0));
                        self->object = object;
                        break;
                    }
                }
              default:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_Long_bitCount(PyTypeObject *type, PyObject *arg)
        {
            jlong a0;
            jint result;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = ::java::lang::Long::bitCount(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "bitCount", arg);
            return NULL;
        }

        static PyObject *t_Long_byteValue(t_Long *self, PyObject *args)
        {
            jbyte result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.byteValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Long), (PyObject *) self, "byteValue", args, 2);
        }

        static PyObject *t_Long_compareTo(t_Long *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::Object a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    Long a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(Long), &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "compareTo", args);
            return NULL;
        }

        static PyObject *t_Long_decode(PyTypeObject *type, PyObject *arg)
        {
            ::java::lang::String a0((jobject) NULL);
            Long result((jobject) NULL);

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = ::java::lang::Long::decode(a0));
                return t_Long::wrap_Object(result);
            }

            PyErr_SetArgsError(type, "decode", arg);
            return NULL;
        }

        static PyObject *t_Long_doubleValue(t_Long *self, PyObject *args)
        {
            jdouble result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.doubleValue());
                return PyFloat_FromDouble((double) result);
            }

            return callSuper(&PY_TYPE(Long), (PyObject *) self, "doubleValue", args, 2);
        }

        static PyObject *t_Long_equals(t_Long *self, PyObject *args)
        {
            ::java::lang::Object a0((jobject) NULL);
            jboolean result;

            if (!parseArgs(args, "o", &a0))
            {
                OBJ_CALL(result = self->object.equals(a0));
                Py_RETURN_BOOL(result);
            }

            return callSuper(&PY_TYPE(Long), (PyObject *) self, "equals", args, 2);
        }

        static PyObject *t_Long_floatValue(t_Long *self, PyObject *args)
        {
            jfloat result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.floatValue());
                return PyFloat_FromDouble((double) result);
            }

            return callSuper(&PY_TYPE(Long), (PyObject *) self, "floatValue", args, 2);
        }

        static PyObject *t_Long_getLong(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    Long result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Long::getLong(a0));
                        return t_Long::wrap_Object(result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jlong a1;
                    Long result((jobject) NULL);

                    if (!parseArgs(args, "sJ", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Long::getLong(a0, a1));
                        return t_Long::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Long a1((jobject) NULL);
                    Long result((jobject) NULL);

                    if (!parseArgs(args, "sO", &::java::lang::PY_TYPE(Long), &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Long::getLong(a0, a1));
                        return t_Long::wrap_Object(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "getLong", args);
            return NULL;
        }

        static PyObject *t_Long_hashCode(t_Long *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.hashCode());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Long), (PyObject *) self, "hashCode", args, 2);
        }

        static PyObject *t_Long_highestOneBit(PyTypeObject *type, PyObject *arg)
        {
            jlong a0;
            jlong result;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = ::java::lang::Long::highestOneBit(a0));
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            PyErr_SetArgsError(type, "highestOneBit", arg);
            return NULL;
        }

        static PyObject *t_Long_intValue(t_Long *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.intValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Long), (PyObject *) self, "intValue", args, 2);
        }

        static PyObject *t_Long_longValue(t_Long *self, PyObject *args)
        {
            jlong result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.longValue());
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            return callSuper(&PY_TYPE(Long), (PyObject *) self, "longValue", args, 2);
        }

        static PyObject *t_Long_lowestOneBit(PyTypeObject *type, PyObject *arg)
        {
            jlong a0;
            jlong result;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = ::java::lang::Long::lowestOneBit(a0));
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            PyErr_SetArgsError(type, "lowestOneBit", arg);
            return NULL;
        }

        static PyObject *t_Long_numberOfLeadingZeros(PyTypeObject *type, PyObject *arg)
        {
            jlong a0;
            jint result;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = ::java::lang::Long::numberOfLeadingZeros(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "numberOfLeadingZeros", arg);
            return NULL;
        }

        static PyObject *t_Long_numberOfTrailingZeros(PyTypeObject *type, PyObject *arg)
        {
            jlong a0;
            jint result;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = ::java::lang::Long::numberOfTrailingZeros(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "numberOfTrailingZeros", arg);
            return NULL;
        }

        static PyObject *t_Long_parseLong(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jlong result;

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Long::parseLong(a0));
                        return PyLong_FromLongLong((PY_LONG_LONG) result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    jlong result;

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Long::parseLong(a0, a1));
                        return PyLong_FromLongLong((PY_LONG_LONG) result);
                    }
                }
            }

            PyErr_SetArgsError(type, "parseLong", args);
            return NULL;
        }

        static PyObject *t_Long_reverse(PyTypeObject *type, PyObject *arg)
        {
            jlong a0;
            jlong result;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = ::java::lang::Long::reverse(a0));
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            PyErr_SetArgsError(type, "reverse", arg);
            return NULL;
        }

        static PyObject *t_Long_reverseBytes(PyTypeObject *type, PyObject *arg)
        {
            jlong a0;
            jlong result;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = ::java::lang::Long::reverseBytes(a0));
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            PyErr_SetArgsError(type, "reverseBytes", arg);
            return NULL;
        }

        static PyObject *t_Long_rotateLeft(PyTypeObject *type, PyObject *args)
        {
            jlong a0;
            jint a1;
            jlong result;

            if (!parseArgs(args, "JI", &a0, &a1))
            {
                OBJ_CALL(result = ::java::lang::Long::rotateLeft(a0, a1));
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            PyErr_SetArgsError(type, "rotateLeft", args);
            return NULL;
        }

        static PyObject *t_Long_rotateRight(PyTypeObject *type, PyObject *args)
        {
            jlong a0;
            jint a1;
            jlong result;

            if (!parseArgs(args, "JI", &a0, &a1))
            {
                OBJ_CALL(result = ::java::lang::Long::rotateRight(a0, a1));
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            PyErr_SetArgsError(type, "rotateRight", args);
            return NULL;
        }

        static PyObject *t_Long_shortValue(t_Long *self, PyObject *args)
        {
            jshort result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.shortValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Long), (PyObject *) self, "shortValue", args, 2);
        }

        static PyObject *t_Long_signum(PyTypeObject *type, PyObject *arg)
        {
            jlong a0;
            jint result;

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = ::java::lang::Long::signum(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "signum", arg);
            return NULL;
        }

        static PyObject *t_Long_toBinaryString(PyTypeObject *type, PyObject *arg)
        {
            jlong a0;
            ::java::lang::String result((jobject) NULL);

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = ::java::lang::Long::toBinaryString(a0));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "toBinaryString", arg);
            return NULL;
        }

        static PyObject *t_Long_toHexString(PyTypeObject *type, PyObject *arg)
        {
            jlong a0;
            ::java::lang::String result((jobject) NULL);

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = ::java::lang::Long::toHexString(a0));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "toHexString", arg);
            return NULL;
        }

        static PyObject *t_Long_toOctalString(PyTypeObject *type, PyObject *arg)
        {
            jlong a0;
            ::java::lang::String result((jobject) NULL);

            if (!parseArg(arg, "J", &a0))
            {
                OBJ_CALL(result = ::java::lang::Long::toOctalString(a0));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "toOctalString", arg);
            return NULL;
        }

        static PyObject *t_Long_toString(t_Long *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(Long), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_Long_toString_(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jlong a0;
                    ::java::lang::String result((jobject) NULL);

                    if (!parseArgs(args, "J", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Long::toString(a0));
                        return j2p(result);
                    }
                }
                break;
              case 2:
                {
                    jlong a0;
                    jint a1;
                    ::java::lang::String result((jobject) NULL);

                    if (!parseArgs(args, "JI", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Long::toString(a0, a1));
                        return j2p(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "toString_", args);
            return NULL;
        }

        static PyObject *t_Long_valueOf(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jlong a0;
                    Long result((jobject) NULL);

                    if (!parseArgs(args, "J", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Long::valueOf(a0));
                        return t_Long::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Long result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Long::valueOf(a0));
                        return t_Long::wrap_Object(result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    Long result((jobject) NULL);

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Long::valueOf(a0, a1));
                        return t_Long::wrap_Object(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "valueOf", args);
            return NULL;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Integer.h"
#include "java/lang/String.h"
#include "java/lang/Comparable.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/Class.h"
#include "java/lang/Object.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Integer::class$ = NULL;
        jmethodID *Integer::mids$ = NULL;
        jint Integer::MAX_VALUE = (jint) 0;
        jint Integer::MIN_VALUE = (jint) 0;
        jint Integer::SIZE = (jint) 0;
        ::java::lang::Class *Integer::TYPE = NULL;

        jclass Integer::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Integer");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_39c7bd3c] = env->getMethodID(cls, "<init>", "(I)V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_bitCount_39c7bd23] = env->getStaticMethodID(cls, "bitCount", "(I)I");
                mids$[mid_byteValue_54c6a172] = env->getMethodID(cls, "byteValue", "()B");
                mids$[mid_compareTo_290588f1] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Object;)I");
                mids$[mid_compareTo_af7b73bb] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Integer;)I");
                mids$[mid_decode_da36ea2b] = env->getStaticMethodID(cls, "decode", "(Ljava/lang/String;)Ljava/lang/Integer;");
                mids$[mid_doubleValue_54c6a174] = env->getMethodID(cls, "doubleValue", "()D");
                mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
                mids$[mid_floatValue_54c6a176] = env->getMethodID(cls, "floatValue", "()F");
                mids$[mid_getInteger_da36ea2b] = env->getStaticMethodID(cls, "getInteger", "(Ljava/lang/String;)Ljava/lang/Integer;");
                mids$[mid_getInteger_fe9eddb1] = env->getStaticMethodID(cls, "getInteger", "(Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;");
                mids$[mid_getInteger_39b2b79d] = env->getStaticMethodID(cls, "getInteger", "(Ljava/lang/String;I)Ljava/lang/Integer;");
                mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
                mids$[mid_highestOneBit_39c7bd23] = env->getStaticMethodID(cls, "highestOneBit", "(I)I");
                mids$[mid_intValue_54c6a179] = env->getMethodID(cls, "intValue", "()I");
                mids$[mid_longValue_54c6a17a] = env->getMethodID(cls, "longValue", "()J");
                mids$[mid_lowestOneBit_39c7bd23] = env->getStaticMethodID(cls, "lowestOneBit", "(I)I");
                mids$[mid_numberOfLeadingZeros_39c7bd23] = env->getStaticMethodID(cls, "numberOfLeadingZeros", "(I)I");
                mids$[mid_numberOfTrailingZeros_39c7bd23] = env->getStaticMethodID(cls, "numberOfTrailingZeros", "(I)I");
                mids$[mid_parseInt_5fdc3f57] = env->getStaticMethodID(cls, "parseInt", "(Ljava/lang/String;)I");
                mids$[mid_parseInt_6e53ccd9] = env->getStaticMethodID(cls, "parseInt", "(Ljava/lang/String;I)I");
                mids$[mid_reverse_39c7bd23] = env->getStaticMethodID(cls, "reverse", "(I)I");
                mids$[mid_reverseBytes_39c7bd23] = env->getStaticMethodID(cls, "reverseBytes", "(I)I");
                mids$[mid_rotateLeft_d8d154b9] = env->getStaticMethodID(cls, "rotateLeft", "(II)I");
                mids$[mid_rotateRight_d8d154b9] = env->getStaticMethodID(cls, "rotateRight", "(II)I");
                mids$[mid_shortValue_54c6a163] = env->getMethodID(cls, "shortValue", "()S");
                mids$[mid_signum_39c7bd23] = env->getStaticMethodID(cls, "signum", "(I)I");
                mids$[mid_toBinaryString_141401b3] = env->getStaticMethodID(cls, "toBinaryString", "(I)Ljava/lang/String;");
                mids$[mid_toHexString_141401b3] = env->getStaticMethodID(cls, "toHexString", "(I)Ljava/lang/String;");
                mids$[mid_toOctalString_141401b3] = env->getStaticMethodID(cls, "toOctalString", "(I)Ljava/lang/String;");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
                mids$[mid_toString_141401b3] = env->getStaticMethodID(cls, "toString", "(I)Ljava/lang/String;");
                mids$[mid_toString_f9118fe5] = env->getStaticMethodID(cls, "toString", "(II)Ljava/lang/String;");
                mids$[mid_valueOf_7266dabb] = env->getStaticMethodID(cls, "valueOf", "(I)Ljava/lang/Integer;");
                mids$[mid_valueOf_da36ea2b] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Ljava/lang/Integer;");
                mids$[mid_valueOf_39b2b79d] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;I)Ljava/lang/Integer;");

                class$ = (::java::lang::Class *) new JObject(cls);
                cls = (jclass) class$->this$;

                MAX_VALUE = env->getStaticIntField(cls, "MAX_VALUE");
                MIN_VALUE = env->getStaticIntField(cls, "MIN_VALUE");
                SIZE = env->getStaticIntField(cls, "SIZE");
                TYPE = new ::java::lang::Class(env->getStaticObjectField(cls, "TYPE", "Ljava/lang/Class;"));
            }
            return (jclass) class$->this$;
        }

        Integer::Integer(jint a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_39c7bd3c, a0)) {}

        Integer::Integer(const ::java::lang::String & a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        jint Integer::bitCount(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_bitCount_39c7bd23], a0);
        }

        jbyte Integer::byteValue() const
        {
            return env->callByteMethod(this$, mids$[mid_byteValue_54c6a172]);
        }

        jint Integer::compareTo(const ::java::lang::Object & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_290588f1], a0.this$);
        }

        jint Integer::compareTo(const Integer & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_af7b73bb], a0.this$);
        }

        Integer Integer::decode(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Integer(env->callStaticObjectMethod(cls, mids$[mid_decode_da36ea2b], a0.this$));
        }

        jdouble Integer::doubleValue() const
        {
            return env->callDoubleMethod(this$, mids$[mid_doubleValue_54c6a174]);
        }

        jboolean Integer::equals(const ::java::lang::Object & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
        }

        jfloat Integer::floatValue() const
        {
            return env->callFloatMethod(this$, mids$[mid_floatValue_54c6a176]);
        }

        Integer Integer::getInteger(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Integer(env->callStaticObjectMethod(cls, mids$[mid_getInteger_da36ea2b], a0.this$));
        }

        Integer Integer::getInteger(const ::java::lang::String & a0, const Integer & a1)
        {
            jclass cls = initializeClass();
            return Integer(env->callStaticObjectMethod(cls, mids$[mid_getInteger_fe9eddb1], a0.this$, a1.this$));
        }

        Integer Integer::getInteger(const ::java::lang::String & a0, jint a1)
        {
            jclass cls = initializeClass();
            return Integer(env->callStaticObjectMethod(cls, mids$[mid_getInteger_39b2b79d], a0.this$, a1));
        }

        jint Integer::hashCode() const
        {
            return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
        }

        jint Integer::highestOneBit(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_highestOneBit_39c7bd23], a0);
        }

        jint Integer::intValue() const
        {
            return env->callIntMethod(this$, mids$[mid_intValue_54c6a179]);
        }

        jlong Integer::longValue() const
        {
            return env->callLongMethod(this$, mids$[mid_longValue_54c6a17a]);
        }

        jint Integer::lowestOneBit(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_lowestOneBit_39c7bd23], a0);
        }

        jint Integer::numberOfLeadingZeros(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_numberOfLeadingZeros_39c7bd23], a0);
        }

        jint Integer::numberOfTrailingZeros(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_numberOfTrailingZeros_39c7bd23], a0);
        }

        jint Integer::parseInt(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_parseInt_5fdc3f57], a0.this$);
        }

        jint Integer::parseInt(const ::java::lang::String & a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_parseInt_6e53ccd9], a0.this$, a1);
        }

        jint Integer::reverse(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_reverse_39c7bd23], a0);
        }

        jint Integer::reverseBytes(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_reverseBytes_39c7bd23], a0);
        }

        jint Integer::rotateLeft(jint a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_rotateLeft_d8d154b9], a0, a1);
        }

        jint Integer::rotateRight(jint a0, jint a1)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_rotateRight_d8d154b9], a0, a1);
        }

        jshort Integer::shortValue() const
        {
            return env->callShortMethod(this$, mids$[mid_shortValue_54c6a163]);
        }

        jint Integer::signum(jint a0)
        {
            jclass cls = initializeClass();
            return env->callStaticIntMethod(cls, mids$[mid_signum_39c7bd23], a0);
        }

        ::java::lang::String Integer::toBinaryString(jint a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toBinaryString_141401b3], a0));
        }

        ::java::lang::String Integer::toHexString(jint a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toHexString_141401b3], a0));
        }

        ::java::lang::String Integer::toOctalString(jint a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toOctalString_141401b3], a0));
        }

        ::java::lang::String Integer::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }

        ::java::lang::String Integer::toString(jint a0)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_141401b3], a0));
        }

        ::java::lang::String Integer::toString(jint a0, jint a1)
        {
            jclass cls = initializeClass();
            return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_f9118fe5], a0, a1));
        }

        Integer Integer::valueOf(jint a0)
        {
            jclass cls = initializeClass();
            return Integer(env->callStaticObjectMethod(cls, mids$[mid_valueOf_7266dabb], a0));
        }

        Integer Integer::valueOf(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Integer(env->callStaticObjectMethod(cls, mids$[mid_valueOf_da36ea2b], a0.this$));
        }

        Integer Integer::valueOf(const ::java::lang::String & a0, jint a1)
        {
            jclass cls = initializeClass();
            return Integer(env->callStaticObjectMethod(cls, mids$[mid_valueOf_39b2b79d], a0.this$, a1));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Integer_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Integer_instance_(PyTypeObject *type, PyObject *arg);
        static int t_Integer_init_(t_Integer *self, PyObject *args, PyObject *kwds);
        static PyObject *t_Integer_bitCount(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Integer_byteValue(t_Integer *self, PyObject *args);
        static PyObject *t_Integer_compareTo(t_Integer *self, PyObject *args);
        static PyObject *t_Integer_decode(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Integer_doubleValue(t_Integer *self, PyObject *args);
        static PyObject *t_Integer_equals(t_Integer *self, PyObject *args);
        static PyObject *t_Integer_floatValue(t_Integer *self, PyObject *args);
        static PyObject *t_Integer_getInteger(PyTypeObject *type, PyObject *args);
        static PyObject *t_Integer_hashCode(t_Integer *self, PyObject *args);
        static PyObject *t_Integer_highestOneBit(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Integer_intValue(t_Integer *self, PyObject *args);
        static PyObject *t_Integer_longValue(t_Integer *self, PyObject *args);
        static PyObject *t_Integer_lowestOneBit(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Integer_numberOfLeadingZeros(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Integer_numberOfTrailingZeros(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Integer_parseInt(PyTypeObject *type, PyObject *args);
        static PyObject *t_Integer_reverse(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Integer_reverseBytes(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Integer_rotateLeft(PyTypeObject *type, PyObject *args);
        static PyObject *t_Integer_rotateRight(PyTypeObject *type, PyObject *args);
        static PyObject *t_Integer_shortValue(t_Integer *self, PyObject *args);
        static PyObject *t_Integer_signum(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Integer_toBinaryString(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Integer_toHexString(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Integer_toOctalString(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Integer_toString(t_Integer *self, PyObject *args);
        static PyObject *t_Integer_toString_(PyTypeObject *type, PyObject *args);
        static PyObject *t_Integer_valueOf(PyTypeObject *type, PyObject *args);

        static PyMethodDef t_Integer__methods_[] = {
            DECLARE_METHOD(t_Integer, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Integer, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Integer, bitCount, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Integer, byteValue, METH_VARARGS),
            DECLARE_METHOD(t_Integer, compareTo, METH_VARARGS),
            DECLARE_METHOD(t_Integer, decode, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Integer, doubleValue, METH_VARARGS),
            DECLARE_METHOD(t_Integer, equals, METH_VARARGS),
            DECLARE_METHOD(t_Integer, floatValue, METH_VARARGS),
            DECLARE_METHOD(t_Integer, getInteger, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Integer, hashCode, METH_VARARGS),
            DECLARE_METHOD(t_Integer, highestOneBit, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Integer, intValue, METH_VARARGS),
            DECLARE_METHOD(t_Integer, longValue, METH_VARARGS),
            DECLARE_METHOD(t_Integer, lowestOneBit, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Integer, numberOfLeadingZeros, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Integer, numberOfTrailingZeros, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Integer, parseInt, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Integer, reverse, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Integer, reverseBytes, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Integer, rotateLeft, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Integer, rotateRight, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Integer, shortValue, METH_VARARGS),
            DECLARE_METHOD(t_Integer, signum, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Integer, toBinaryString, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Integer, toHexString, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Integer, toOctalString, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Integer, toString, METH_VARARGS),
            DECLARE_METHOD(t_Integer, toString_, METH_VARARGS | METH_CLASS),
            DECLARE_METHOD(t_Integer, valueOf, METH_VARARGS | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Integer, t_Integer, ::java::lang::Number, Integer, t_Integer_init_, 0, 0, 0, 0, 0);

        void t_Integer::install(PyObject *module)
        {
            installType(&PY_TYPE(Integer), module, "Integer", 0);
        }

        void t_Integer::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Integer).tp_dict, "class_", make_descriptor(Integer::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Integer).tp_dict, "wrapfn_", make_descriptor(unboxInteger));
            PyDict_SetItemString(PY_TYPE(Integer).tp_dict, "boxfn_", make_descriptor(boxInteger));
            Integer::initializeClass();
            PyDict_SetItemString(PY_TYPE(Integer).tp_dict, "MAX_VALUE", make_descriptor(Integer::MAX_VALUE));
            PyDict_SetItemString(PY_TYPE(Integer).tp_dict, "MIN_VALUE", make_descriptor(Integer::MIN_VALUE));
            PyDict_SetItemString(PY_TYPE(Integer).tp_dict, "SIZE", make_descriptor(Integer::SIZE));
            PyDict_SetItemString(PY_TYPE(Integer).tp_dict, "TYPE", make_descriptor(::java::lang::t_Class::wrap_Object(*Integer::TYPE)));
        }

        static PyObject *t_Integer_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Integer::initializeClass, 1)))
                return NULL;
            return t_Integer::wrap_Object(Integer(((t_Integer *) arg)->object.this$));
        }
        static PyObject *t_Integer_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Integer::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_Integer_init_(t_Integer *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    Integer object((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        INT_CALL(object = Integer(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Integer object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = Integer(a0));
                        self->object = object;
                        break;
                    }
                }
              default:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_Integer_bitCount(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            jint result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Integer::bitCount(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "bitCount", arg);
            return NULL;
        }

        static PyObject *t_Integer_byteValue(t_Integer *self, PyObject *args)
        {
            jbyte result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.byteValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Integer), (PyObject *) self, "byteValue", args, 2);
        }

        static PyObject *t_Integer_compareTo(t_Integer *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::Object a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                {
                    Integer a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(Integer), &a0))
                    {
                        OBJ_CALL(result = self->object.compareTo(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "compareTo", args);
            return NULL;
        }

        static PyObject *t_Integer_decode(PyTypeObject *type, PyObject *arg)
        {
            ::java::lang::String a0((jobject) NULL);
            Integer result((jobject) NULL);

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = ::java::lang::Integer::decode(a0));
                return t_Integer::wrap_Object(result);
            }

            PyErr_SetArgsError(type, "decode", arg);
            return NULL;
        }

        static PyObject *t_Integer_doubleValue(t_Integer *self, PyObject *args)
        {
            jdouble result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.doubleValue());
                return PyFloat_FromDouble((double) result);
            }

            return callSuper(&PY_TYPE(Integer), (PyObject *) self, "doubleValue", args, 2);
        }

        static PyObject *t_Integer_equals(t_Integer *self, PyObject *args)
        {
            ::java::lang::Object a0((jobject) NULL);
            jboolean result;

            if (!parseArgs(args, "o", &a0))
            {
                OBJ_CALL(result = self->object.equals(a0));
                Py_RETURN_BOOL(result);
            }

            return callSuper(&PY_TYPE(Integer), (PyObject *) self, "equals", args, 2);
        }

        static PyObject *t_Integer_floatValue(t_Integer *self, PyObject *args)
        {
            jfloat result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.floatValue());
                return PyFloat_FromDouble((double) result);
            }

            return callSuper(&PY_TYPE(Integer), (PyObject *) self, "floatValue", args, 2);
        }

        static PyObject *t_Integer_getInteger(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    Integer result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Integer::getInteger(a0));
                        return t_Integer::wrap_Object(result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    Integer a1((jobject) NULL);
                    Integer result((jobject) NULL);

                    if (!parseArgs(args, "sO", &::java::lang::PY_TYPE(Integer), &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Integer::getInteger(a0, a1));
                        return t_Integer::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    Integer result((jobject) NULL);

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Integer::getInteger(a0, a1));
                        return t_Integer::wrap_Object(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "getInteger", args);
            return NULL;
        }

        static PyObject *t_Integer_hashCode(t_Integer *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.hashCode());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Integer), (PyObject *) self, "hashCode", args, 2);
        }

        static PyObject *t_Integer_highestOneBit(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            jint result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Integer::highestOneBit(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "highestOneBit", arg);
            return NULL;
        }

        static PyObject *t_Integer_intValue(t_Integer *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.intValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Integer), (PyObject *) self, "intValue", args, 2);
        }

        static PyObject *t_Integer_longValue(t_Integer *self, PyObject *args)
        {
            jlong result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.longValue());
                return PyLong_FromLongLong((PY_LONG_LONG) result);
            }

            return callSuper(&PY_TYPE(Integer), (PyObject *) self, "longValue", args, 2);
        }

        static PyObject *t_Integer_lowestOneBit(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            jint result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Integer::lowestOneBit(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "lowestOneBit", arg);
            return NULL;
        }

        static PyObject *t_Integer_numberOfLeadingZeros(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            jint result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Integer::numberOfLeadingZeros(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "numberOfLeadingZeros", arg);
            return NULL;
        }

        static PyObject *t_Integer_numberOfTrailingZeros(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            jint result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Integer::numberOfTrailingZeros(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "numberOfTrailingZeros", arg);
            return NULL;
        }

        static PyObject *t_Integer_parseInt(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Integer::parseInt(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Integer::parseInt(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError(type, "parseInt", args);
            return NULL;
        }

        static PyObject *t_Integer_reverse(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            jint result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Integer::reverse(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "reverse", arg);
            return NULL;
        }

        static PyObject *t_Integer_reverseBytes(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            jint result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Integer::reverseBytes(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "reverseBytes", arg);
            return NULL;
        }

        static PyObject *t_Integer_rotateLeft(PyTypeObject *type, PyObject *args)
        {
            jint a0;
            jint a1;
            jint result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = ::java::lang::Integer::rotateLeft(a0, a1));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "rotateLeft", args);
            return NULL;
        }

        static PyObject *t_Integer_rotateRight(PyTypeObject *type, PyObject *args)
        {
            jint a0;
            jint a1;
            jint result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = ::java::lang::Integer::rotateRight(a0, a1));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "rotateRight", args);
            return NULL;
        }

        static PyObject *t_Integer_shortValue(t_Integer *self, PyObject *args)
        {
            jshort result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.shortValue());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Integer), (PyObject *) self, "shortValue", args, 2);
        }

        static PyObject *t_Integer_signum(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            jint result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Integer::signum(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError(type, "signum", arg);
            return NULL;
        }

        static PyObject *t_Integer_toBinaryString(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            ::java::lang::String result((jobject) NULL);

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Integer::toBinaryString(a0));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "toBinaryString", arg);
            return NULL;
        }

        static PyObject *t_Integer_toHexString(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            ::java::lang::String result((jobject) NULL);

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Integer::toHexString(a0));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "toHexString", arg);
            return NULL;
        }

        static PyObject *t_Integer_toOctalString(PyTypeObject *type, PyObject *arg)
        {
            jint a0;
            ::java::lang::String result((jobject) NULL);

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = ::java::lang::Integer::toOctalString(a0));
                return j2p(result);
            }

            PyErr_SetArgsError(type, "toOctalString", arg);
            return NULL;
        }

        static PyObject *t_Integer_toString(t_Integer *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(Integer), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_Integer_toString_(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    ::java::lang::String result((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Integer::toString(a0));
                        return j2p(result);
                    }
                }
                break;
              case 2:
                {
                    jint a0;
                    jint a1;
                    ::java::lang::String result((jobject) NULL);

                    if (!parseArgs(args, "II", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Integer::toString(a0, a1));
                        return j2p(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "toString_", args);
            return NULL;
        }

        static PyObject *t_Integer_valueOf(PyTypeObject *type, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    Integer result((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Integer::valueOf(a0));
                        return t_Integer::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    Integer result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = ::java::lang::Integer::valueOf(a0));
                        return t_Integer::wrap_Object(result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    Integer result((jobject) NULL);

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = ::java::lang::Integer::valueOf(a0, a1));
                        return t_Integer::wrap_Object(result);
                    }
                }
            }

            PyErr_SetArgsError(type, "valueOf", args);
            return NULL;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/io/Writer.h"
#include "java/lang/CharSequence.h"
#include "java/lang/String.h"
#include "java/lang/Appendable.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace io {

        ::java::lang::Class *Writer::class$ = NULL;
        jmethodID *Writer::mids$ = NULL;

        jclass Writer::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/io/Writer");

                mids$ = new jmethodID[max_mid];
                mids$[mid_append_368f1679] = env->getMethodID(cls, "append", "(C)Ljava/io/Writer;");
                mids$[mid_append_31d2f801] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;)Ljava/io/Writer;");
                mids$[mid_append_b3d4aa31] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;II)Ljava/io/Writer;");
                mids$[mid_close_54c6a166] = env->getMethodID(cls, "close", "()V");
                mids$[mid_flush_54c6a166] = env->getMethodID(cls, "flush", "()V");
                mids$[mid_write_5fdc3f48] = env->getMethodID(cls, "write", "(Ljava/lang/String;)V");
                mids$[mid_write_700e23d6] = env->getMethodID(cls, "write", "([C)V");
                mids$[mid_write_39c7bd3c] = env->getMethodID(cls, "write", "(I)V");
                mids$[mid_write_555f322c] = env->getMethodID(cls, "write", "(Ljava/lang/String;II)V");
                mids$[mid_write_6f0bb356] = env->getMethodID(cls, "write", "([CII)V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        Writer Writer::append(jchar a0) const
        {
            return Writer(env->callObjectMethod(this$, mids$[mid_append_368f1679], a0));
        }

        Writer Writer::append(const ::java::lang::CharSequence & a0) const
        {
            return Writer(env->callObjectMethod(this$, mids$[mid_append_31d2f801], a0.this$));
        }

        Writer Writer::append(const ::java::lang::CharSequence & a0, jint a1, jint a2) const
        {
            return Writer(env->callObjectMethod(this$, mids$[mid_append_b3d4aa31], a0.this$, a1, a2));
        }

        void Writer::close() const
        {
            env->callVoidMethod(this$, mids$[mid_close_54c6a166]);
        }

        void Writer::flush() const
        {
            env->callVoidMethod(this$, mids$[mid_flush_54c6a166]);
        }

        void Writer::write(const ::java::lang::String & a0) const
        {
            env->callVoidMethod(this$, mids$[mid_write_5fdc3f48], a0.this$);
        }

        void Writer::write(const JArray< jchar > & a0) const
        {
            env->callVoidMethod(this$, mids$[mid_write_700e23d6], a0.this$);
        }

        void Writer::write(jint a0) const
        {
            env->callVoidMethod(this$, mids$[mid_write_39c7bd3c], a0);
        }

        void Writer::write(const ::java::lang::String & a0, jint a1, jint a2) const
        {
            env->callVoidMethod(this$, mids$[mid_write_555f322c], a0.this$, a1, a2);
        }

        void Writer::write(const JArray< jchar > & a0, jint a1, jint a2) const
        {
            env->callVoidMethod(this$, mids$[mid_write_6f0bb356], a0.this$, a1, a2);
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace io {
        static PyObject *t_Writer_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Writer_instance_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Writer_append(t_Writer *self, PyObject *args);
        static PyObject *t_Writer_close(t_Writer *self);
        static PyObject *t_Writer_flush(t_Writer *self);
        static PyObject *t_Writer_write(t_Writer *self, PyObject *args);

        static PyMethodDef t_Writer__methods_[] = {
            DECLARE_METHOD(t_Writer, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Writer, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Writer, append, METH_VARARGS),
            DECLARE_METHOD(t_Writer, close, METH_NOARGS),
            DECLARE_METHOD(t_Writer, flush, METH_NOARGS),
            DECLARE_METHOD(t_Writer, write, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Writer, t_Writer, ::java::lang::Object, Writer, abstract_init, 0, 0, 0, 0, 0);

        void t_Writer::install(PyObject *module)
        {
            installType(&PY_TYPE(Writer), module, "Writer", 0);
        }

        void t_Writer::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Writer).tp_dict, "class_", make_descriptor(Writer::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Writer).tp_dict, "wrapfn_", make_descriptor(t_Writer::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(Writer).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_Writer_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Writer::initializeClass, 1)))
                return NULL;
            return t_Writer::wrap_Object(Writer(((t_Writer *) arg)->object.this$));
        }
        static PyObject *t_Writer_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Writer::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static PyObject *t_Writer_append(t_Writer *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jchar a0;
                    Writer result((jobject) NULL);

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_Writer::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    Writer result((jobject) NULL);

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_Writer::wrap_Object(result);
                    }
                }
                break;
              case 3:
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    Writer result((jobject) NULL);

                    if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = self->object.append(a0, a1, a2));
                        return t_Writer::wrap_Object(result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "append", args);
            return NULL;
        }

        static PyObject *t_Writer_close(t_Writer *self)
        {
            OBJ_CALL(self->object.close());
            Py_RETURN_NONE;
        }

        static PyObject *t_Writer_flush(t_Writer *self)
        {
            OBJ_CALL(self->object.flush());
            Py_RETURN_NONE;
        }

        static PyObject *t_Writer_write(t_Writer *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(self->object.write(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    JArray< jchar > a0((jobject) NULL);

                    if (!parseArgs(args, "[C", &a0))
                    {
                        OBJ_CALL(self->object.write(a0));
                        Py_RETURN_NONE;
                    }
                }
                {
                    jint a0;

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(self->object.write(a0));
                        Py_RETURN_NONE;
                    }
                }
                break;
              case 3:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    jint a2;

                    if (!parseArgs(args, "sII", &a0, &a1, &a2))
                    {
                        OBJ_CALL(self->object.write(a0, a1, a2));
                        Py_RETURN_NONE;
                    }
                }
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint a2;

                    if (!parseArgs(args, "[CII", &a0, &a1, &a2))
                    {
                        OBJ_CALL(self->object.write(a0, a1, a2));
                        Py_RETURN_NONE;
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "write", args);
            return NULL;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/RuntimeException.h"
#include "java/lang/Throwable.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *RuntimeException::class$ = NULL;
        jmethodID *RuntimeException::mids$ = NULL;

        jclass RuntimeException::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/RuntimeException");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_init$_c5ec8ca4] = env->getMethodID(cls, "<init>", "(Ljava/lang/Throwable;)V");
                mids$[mid_init$_01646a2e] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        RuntimeException::RuntimeException() : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        RuntimeException::RuntimeException(const ::java::lang::String & a0) : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        RuntimeException::RuntimeException(const ::java::lang::Throwable & a0) : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_c5ec8ca4, a0.this$)) {}

        RuntimeException::RuntimeException(const ::java::lang::String & a0, const ::java::lang::Throwable & a1) : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_01646a2e, a0.this$, a1.this$)) {}
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_RuntimeException_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_RuntimeException_instance_(PyTypeObject *type, PyObject *arg);
        static int t_RuntimeException_init_(t_RuntimeException *self, PyObject *args, PyObject *kwds);

        static PyMethodDef t_RuntimeException__methods_[] = {
            DECLARE_METHOD(t_RuntimeException, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_RuntimeException, instance_, METH_O | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(RuntimeException, t_RuntimeException, ::java::lang::Exception, RuntimeException, t_RuntimeException_init_, 0, 0, 0, 0, 0);

        void t_RuntimeException::install(PyObject *module)
        {
            installType(&PY_TYPE(RuntimeException), module, "RuntimeException", 0);
        }

        void t_RuntimeException::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(RuntimeException).tp_dict, "class_", make_descriptor(RuntimeException::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(RuntimeException).tp_dict, "wrapfn_", make_descriptor(t_RuntimeException::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(RuntimeException).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_RuntimeException_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, RuntimeException::initializeClass, 1)))
                return NULL;
            return t_RuntimeException::wrap_Object(RuntimeException(((t_RuntimeException *) arg)->object.this$));
        }
        static PyObject *t_RuntimeException_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, RuntimeException::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_RuntimeException_init_(t_RuntimeException *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    RuntimeException object((jobject) NULL);

                    INT_CALL(object = RuntimeException());
                    self->object = object;
                    break;
                }
                goto err;
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    RuntimeException object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = RuntimeException(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::Throwable a0((jobject) NULL);
                    RuntimeException object((jobject) NULL);

                    if (!parseArgs(args, "k", ::java::lang::Throwable::initializeClass, &a0))
                    {
                        INT_CALL(object = RuntimeException(a0));
                        self->object = object;
                        break;
                    }
                }
                goto err;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    ::java::lang::Throwable a1((jobject) NULL);
                    RuntimeException object((jobject) NULL);

                    if (!parseArgs(args, "sk", ::java::lang::Throwable::initializeClass, &a0, &a1))
                    {
                        INT_CALL(object = RuntimeException(a0, a1));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/SecurityException.h"
#include "java/lang/Throwable.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *SecurityException::class$ = NULL;
        jmethodID *SecurityException::mids$ = NULL;

        jclass SecurityException::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/SecurityException");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_init$_c5ec8ca4] = env->getMethodID(cls, "<init>", "(Ljava/lang/Throwable;)V");
                mids$[mid_init$_01646a2e] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        SecurityException::SecurityException() : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        SecurityException::SecurityException(const ::java::lang::String & a0) : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        SecurityException::SecurityException(const ::java::lang::Throwable & a0) : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_c5ec8ca4, a0.this$)) {}

        SecurityException::SecurityException(const ::java::lang::String & a0, const ::java::lang::Throwable & a1) : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_01646a2e, a0.this$, a1.this$)) {}
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_SecurityException_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_SecurityException_instance_(PyTypeObject *type, PyObject *arg);
        static int t_SecurityException_init_(t_SecurityException *self, PyObject *args, PyObject *kwds);

        static PyMethodDef t_SecurityException__methods_[] = {
            DECLARE_METHOD(t_SecurityException, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_SecurityException, instance_, METH_O | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(SecurityException, t_SecurityException, ::java::lang::RuntimeException, SecurityException, t_SecurityException_init_, 0, 0, 0, 0, 0);

        void t_SecurityException::install(PyObject *module)
        {
            installType(&PY_TYPE(SecurityException), module, "SecurityException", 0);
        }

        void t_SecurityException::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(SecurityException).tp_dict, "class_", make_descriptor(SecurityException::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(SecurityException).tp_dict, "wrapfn_", make_descriptor(t_SecurityException::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(SecurityException).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_SecurityException_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, SecurityException::initializeClass, 1)))
                return NULL;
            return t_SecurityException::wrap_Object(SecurityException(((t_SecurityException *) arg)->object.this$));
        }
        static PyObject *t_SecurityException_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, SecurityException::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_SecurityException_init_(t_SecurityException *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    SecurityException object((jobject) NULL);

                    INT_CALL(object = SecurityException());
                    self->object = object;
                    break;
                }
                goto err;
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    SecurityException object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = SecurityException(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::Throwable a0((jobject) NULL);
                    SecurityException object((jobject) NULL);

                    if (!parseArgs(args, "k", ::java::lang::Throwable::initializeClass, &a0))
                    {
                        INT_CALL(object = SecurityException(a0));
                        self->object = object;
                        break;
                    }
                }
                goto err;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    ::java::lang::Throwable a1((jobject) NULL);
                    SecurityException object((jobject) NULL);

                    if (!parseArgs(args, "sk", ::java::lang::Throwable::initializeClass, &a0, &a1))
                    {
                        INT_CALL(object = SecurityException(a0, a1));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/ClassLoader.h"
#include "java/lang/String.h"
#include "java/lang/ClassNotFoundException.h"
#include "java/util/Enumeration.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *ClassLoader::class$ = NULL;
        jmethodID *ClassLoader::mids$ = NULL;

        jclass ClassLoader::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/ClassLoader");

                mids$ = new jmethodID[max_mid];
                mids$[mid_clearAssertionStatus_54c6a166] = env->getMethodID(cls, "clearAssertionStatus", "()V");
                mids$[mid_getParent_8d2f11fc] = env->getMethodID(cls, "getParent", "()Ljava/lang/ClassLoader;");
                mids$[mid_getSystemClassLoader_8d2f11fc] = env->getStaticMethodID(cls, "getSystemClassLoader", "()Ljava/lang/ClassLoader;");
                mids$[mid_loadClass_7d663d97] = env->getMethodID(cls, "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;");
                mids$[mid_setClassAssertionStatus_f3691645] = env->getMethodID(cls, "setClassAssertionStatus", "(Ljava/lang/String;Z)V");
                mids$[mid_setDefaultAssertionStatus_bb0c767f] = env->getMethodID(cls, "setDefaultAssertionStatus", "(Z)V");
                mids$[mid_setPackageAssertionStatus_f3691645] = env->getMethodID(cls, "setPackageAssertionStatus", "(Ljava/lang/String;Z)V");
                mids$[mid_loadClass_dfdc0682] = env->getMethodID(cls, "loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;");
                mids$[mid_getPackage_d9fbaba1] = env->getMethodID(cls, "getPackage", "(Ljava/lang/String;)Ljava/lang/Package;");
                mids$[mid_setSigners_34aa77b4] = env->getMethodID(cls, "setSigners", "(Ljava/lang/Class;[Ljava/lang/Object;)V");
                mids$[mid_findClass_7d663d97] = env->getMethodID(cls, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;");
                mids$[mid_defineClass_43666462] = env->getMethodID(cls, "defineClass", "(Ljava/lang/String;[BIILjava/security/ProtectionDomain;)Ljava/lang/Class;");
                mids$[mid_defineClass_deb30b89] = env->getMethodID(cls, "defineClass", "(Ljava/lang/String;Ljava/nio/ByteBuffer;Ljava/security/ProtectionDomain;)Ljava/lang/Class;");
                mids$[mid_defineClass_fd7e66de] = env->getMethodID(cls, "defineClass", "(Ljava/lang/String;[BII)Ljava/lang/Class;");
                mids$[mid_defineClass_2476a918] = env->getMethodID(cls, "defineClass", "([BII)Ljava/lang/Class;");
                mids$[mid_resolveClass_a5deaff4] = env->getMethodID(cls, "resolveClass", "(Ljava/lang/Class;)V");
                mids$[mid_findSystemClass_7d663d97] = env->getMethodID(cls, "findSystemClass", "(Ljava/lang/String;)Ljava/lang/Class;");
                mids$[mid_findLoadedClass_7d663d97] = env->getMethodID(cls, "findLoadedClass", "(Ljava/lang/String;)Ljava/lang/Class;");
                mids$[mid_findResource_77de5daa] = env->getMethodID(cls, "findResource", "(Ljava/lang/String;)Ljava/net/URL;");
                mids$[mid_findResources_1aac6a8a] = env->getMethodID(cls, "findResources", "(Ljava/lang/String;)Ljava/util/Enumeration;");
                mids$[mid_definePackage_ebf4cbfe] = env->getMethodID(cls, "definePackage", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/net/URL;)Ljava/lang/Package;");
                mids$[mid_getPackages_c03e7c17] = env->getMethodID(cls, "getPackages", "()[Ljava/lang/Package;");
                mids$[mid_findLibrary_97a5258f] = env->getMethodID(cls, "findLibrary", "(Ljava/lang/String;)Ljava/lang/String;");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        void ClassLoader::clearAssertionStatus() const
        {
            env->callVoidMethod(this$, mids$[mid_clearAssertionStatus_54c6a166]);
        }

        ClassLoader ClassLoader::getParent() const
        {
            return ClassLoader(env->callObjectMethod(this$, mids$[mid_getParent_8d2f11fc]));
        }

        ClassLoader ClassLoader::getSystemClassLoader()
        {
            jclass cls = initializeClass();
            return ClassLoader(env->callStaticObjectMethod(cls, mids$[mid_getSystemClassLoader_8d2f11fc]));
        }

        ::java::lang::Class ClassLoader::loadClass(const ::java::lang::String & a0) const
        {
            return ::java::lang::Class(env->callObjectMethod(this$, mids$[mid_loadClass_7d663d97], a0.this$));
        }

        void ClassLoader::setClassAssertionStatus(const ::java::lang::String & a0, jboolean a1) const
        {
            env->callVoidMethod(this$, mids$[mid_setClassAssertionStatus_f3691645], a0.this$, a1);
        }

        void ClassLoader::setDefaultAssertionStatus(jboolean a0) const
        {
            env->callVoidMethod(this$, mids$[mid_setDefaultAssertionStatus_bb0c767f], a0);
        }

        void ClassLoader::setPackageAssertionStatus(const ::java::lang::String & a0, jboolean a1) const
        {
            env->callVoidMethod(this$, mids$[mid_setPackageAssertionStatus_f3691645], a0.this$, a1);
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_ClassLoader_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_ClassLoader_instance_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_ClassLoader_clearAssertionStatus(t_ClassLoader *self);
        static PyObject *t_ClassLoader_getParent(t_ClassLoader *self);
        static PyObject *t_ClassLoader_getSystemClassLoader(PyTypeObject *type);
        static PyObject *t_ClassLoader_loadClass(t_ClassLoader *self, PyObject *arg);
        static PyObject *t_ClassLoader_setClassAssertionStatus(t_ClassLoader *self, PyObject *args);
        static PyObject *t_ClassLoader_setDefaultAssertionStatus(t_ClassLoader *self, PyObject *arg);
        static PyObject *t_ClassLoader_setPackageAssertionStatus(t_ClassLoader *self, PyObject *args);
        static int t_ClassLoader_set__defaultAssertionStatus(t_ClassLoader *self, PyObject *arg, void *data);
        static PyObject *t_ClassLoader_get__parent(t_ClassLoader *self, void *data);
        static PyObject *t_ClassLoader_get__systemClassLoader(t_ClassLoader *self, void *data);
        static PyGetSetDef t_ClassLoader__fields_[] = {
            DECLARE_SET_FIELD(t_ClassLoader, defaultAssertionStatus),
            DECLARE_GET_FIELD(t_ClassLoader, parent),
            DECLARE_GET_FIELD(t_ClassLoader, systemClassLoader),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_ClassLoader__methods_[] = {
            DECLARE_METHOD(t_ClassLoader, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_ClassLoader, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_ClassLoader, clearAssertionStatus, METH_NOARGS),
            DECLARE_METHOD(t_ClassLoader, getParent, METH_NOARGS),
            DECLARE_METHOD(t_ClassLoader, getSystemClassLoader, METH_NOARGS | METH_CLASS),
            DECLARE_METHOD(t_ClassLoader, loadClass, METH_O),
            DECLARE_METHOD(t_ClassLoader, setClassAssertionStatus, METH_VARARGS),
            DECLARE_METHOD(t_ClassLoader, setDefaultAssertionStatus, METH_O),
            DECLARE_METHOD(t_ClassLoader, setPackageAssertionStatus, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(ClassLoader, t_ClassLoader, ::java::lang::Object, ClassLoader, abstract_init, 0, 0, t_ClassLoader__fields_, 0, 0);

        void t_ClassLoader::install(PyObject *module)
        {
            installType(&PY_TYPE(ClassLoader), module, "ClassLoader", 0);
        }

        void t_ClassLoader::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(ClassLoader).tp_dict, "class_", make_descriptor(ClassLoader::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(ClassLoader).tp_dict, "wrapfn_", make_descriptor(t_ClassLoader::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(ClassLoader).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_ClassLoader_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, ClassLoader::initializeClass, 1)))
                return NULL;
            return t_ClassLoader::wrap_Object(ClassLoader(((t_ClassLoader *) arg)->object.this$));
        }
        static PyObject *t_ClassLoader_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, ClassLoader::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static PyObject *t_ClassLoader_clearAssertionStatus(t_ClassLoader *self)
        {
            OBJ_CALL(self->object.clearAssertionStatus());
            Py_RETURN_NONE;
        }

        static PyObject *t_ClassLoader_getParent(t_ClassLoader *self)
        {
            ClassLoader result((jobject) NULL);
            OBJ_CALL(result = self->object.getParent());
            return t_ClassLoader::wrap_Object(result);
        }

        static PyObject *t_ClassLoader_getSystemClassLoader(PyTypeObject *type)
        {
            ClassLoader result((jobject) NULL);
            OBJ_CALL(result = ::java::lang::ClassLoader::getSystemClassLoader());
            return t_ClassLoader::wrap_Object(result);
        }

        static PyObject *t_ClassLoader_loadClass(t_ClassLoader *self, PyObject *arg)
        {
            ::java::lang::String a0((jobject) NULL);
            ::java::lang::Class result((jobject) NULL);

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = self->object.loadClass(a0));
                return ::java::lang::t_Class::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "loadClass", arg);
            return NULL;
        }

        static PyObject *t_ClassLoader_setClassAssertionStatus(t_ClassLoader *self, PyObject *args)
        {
            ::java::lang::String a0((jobject) NULL);
            jboolean a1;

            if (!parseArgs(args, "sZ", &a0, &a1))
            {
                OBJ_CALL(self->object.setClassAssertionStatus(a0, a1));
                Py_RETURN_NONE;
            }

            PyErr_SetArgsError((PyObject *) self, "setClassAssertionStatus", args);
            return NULL;
        }

        static PyObject *t_ClassLoader_setDefaultAssertionStatus(t_ClassLoader *self, PyObject *arg)
        {
            jboolean a0;

            if (!parseArg(arg, "Z", &a0))
            {
                OBJ_CALL(self->object.setDefaultAssertionStatus(a0));
                Py_RETURN_NONE;
            }

            PyErr_SetArgsError((PyObject *) self, "setDefaultAssertionStatus", arg);
            return NULL;
        }

        static PyObject *t_ClassLoader_setPackageAssertionStatus(t_ClassLoader *self, PyObject *args)
        {
            ::java::lang::String a0((jobject) NULL);
            jboolean a1;

            if (!parseArgs(args, "sZ", &a0, &a1))
            {
                OBJ_CALL(self->object.setPackageAssertionStatus(a0, a1));
                Py_RETURN_NONE;
            }

            PyErr_SetArgsError((PyObject *) self, "setPackageAssertionStatus", args);
            return NULL;
        }

        static int t_ClassLoader_set__defaultAssertionStatus(t_ClassLoader *self, PyObject *arg, void *data)
        {
            {
                jboolean value;
                if (!parseArg(arg, "Z", &value))
                {
                    INT_CALL(self->object.setDefaultAssertionStatus(value));
                    return 0;
                }
            }
            PyErr_SetArgsError((PyObject *) self, "defaultAssertionStatus", arg);
            return -1;
        }

        static PyObject *t_ClassLoader_get__parent(t_ClassLoader *self, void *data)
        {
            ClassLoader value((jobject) NULL);
            OBJ_CALL(value = self->object.getParent());
            return t_ClassLoader::wrap_Object(value);
        }

        static PyObject *t_ClassLoader_get__systemClassLoader(t_ClassLoader *self, void *data)
        {
            ClassLoader value((jobject) NULL);
            OBJ_CALL(value = self->object.getSystemClassLoader());
            return t_ClassLoader::wrap_Object(value);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/InstantiationException.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *InstantiationException::class$ = NULL;
        jmethodID *InstantiationException::mids$ = NULL;

        jclass InstantiationException::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/InstantiationException");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        InstantiationException::InstantiationException() : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        InstantiationException::InstantiationException(const ::java::lang::String & a0) : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_InstantiationException_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_InstantiationException_instance_(PyTypeObject *type, PyObject *arg);
        static int t_InstantiationException_init_(t_InstantiationException *self, PyObject *args, PyObject *kwds);

        static PyMethodDef t_InstantiationException__methods_[] = {
            DECLARE_METHOD(t_InstantiationException, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_InstantiationException, instance_, METH_O | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(InstantiationException, t_InstantiationException, ::java::lang::Exception, InstantiationException, t_InstantiationException_init_, 0, 0, 0, 0, 0);

        void t_InstantiationException::install(PyObject *module)
        {
            installType(&PY_TYPE(InstantiationException), module, "InstantiationException", 0);
        }

        void t_InstantiationException::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(InstantiationException).tp_dict, "class_", make_descriptor(InstantiationException::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(InstantiationException).tp_dict, "wrapfn_", make_descriptor(t_InstantiationException::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(InstantiationException).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_InstantiationException_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, InstantiationException::initializeClass, 1)))
                return NULL;
            return t_InstantiationException::wrap_Object(InstantiationException(((t_InstantiationException *) arg)->object.this$));
        }
        static PyObject *t_InstantiationException_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, InstantiationException::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_InstantiationException_init_(t_InstantiationException *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    InstantiationException object((jobject) NULL);

                    INT_CALL(object = InstantiationException());
                    self->object = object;
                    break;
                }
                goto err;
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    InstantiationException object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = InstantiationException(a0));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "scala/Serializable.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace scala {

    ::java::lang::Class *Serializable::class$ = NULL;
    jmethodID *Serializable::mids$ = NULL;

    jclass Serializable::initializeClass()
    {
        if (!class$)
        {

            jclass cls = (jclass) env->findClass("scala/Serializable");

            class$ = (::java::lang::Class *) new JObject(cls);
        }
        return (jclass) class$->this$;
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace scala {
    static PyObject *t_Serializable_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Serializable_instance_(PyTypeObject *type, PyObject *arg);

    static PyMethodDef t_Serializable__methods_[] = {
        DECLARE_METHOD(t_Serializable, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_Serializable, instance_, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Serializable, t_Serializable, ::java::lang::Object, Serializable, abstract_init, 0, 0, 0, 0, 0);

    void t_Serializable::install(PyObject *module)
    {
        installType(&PY_TYPE(Serializable), module, "Serializable", 0);
    }

    void t_Serializable::initialize(PyObject *module)
    {
        PyDict_SetItemString(PY_TYPE(Serializable).tp_dict, "class_", make_descriptor(Serializable::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(Serializable).tp_dict, "wrapfn_", make_descriptor(t_Serializable::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(Serializable).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_Serializable_cast_(PyTypeObject *type, PyObject *arg)
    {
        if (!(arg = castCheck(arg, Serializable::initializeClass, 1)))
            return NULL;
        return t_Serializable::wrap_Object(Serializable(((t_Serializable *) arg)->object.this$));
    }
    static PyObject *t_Serializable_instance_(PyTypeObject *type, PyObject *arg)
    {
        if (!castCheck(arg, Serializable::initializeClass, 0))
            Py_RETURN_FALSE;
        Py_RETURN_TRUE;
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Package.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Package::class$ = NULL;
        jmethodID *Package::mids$ = NULL;

        jclass Package::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Package");

                mids$ = new jmethodID[max_mid];
                mids$[mid_getImplementationTitle_14c7b5c5] = env->getMethodID(cls, "getImplementationTitle", "()Ljava/lang/String;");
                mids$[mid_getImplementationVendor_14c7b5c5] = env->getMethodID(cls, "getImplementationVendor", "()Ljava/lang/String;");
                mids$[mid_getImplementationVersion_14c7b5c5] = env->getMethodID(cls, "getImplementationVersion", "()Ljava/lang/String;");
                mids$[mid_getName_14c7b5c5] = env->getMethodID(cls, "getName", "()Ljava/lang/String;");
                mids$[mid_getPackage_d9fbaba1] = env->getStaticMethodID(cls, "getPackage", "(Ljava/lang/String;)Ljava/lang/Package;");
                mids$[mid_getPackages_c03e7c17] = env->getStaticMethodID(cls, "getPackages", "()[Ljava/lang/Package;");
                mids$[mid_getSpecificationTitle_14c7b5c5] = env->getMethodID(cls, "getSpecificationTitle", "()Ljava/lang/String;");
                mids$[mid_getSpecificationVendor_14c7b5c5] = env->getMethodID(cls, "getSpecificationVendor", "()Ljava/lang/String;");
                mids$[mid_getSpecificationVersion_14c7b5c5] = env->getMethodID(cls, "getSpecificationVersion", "()Ljava/lang/String;");
                mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
                mids$[mid_isCompatibleWith_5fdc3f44] = env->getMethodID(cls, "isCompatibleWith", "(Ljava/lang/String;)Z");
                mids$[mid_isSealed_54c6a16a] = env->getMethodID(cls, "isSealed", "()Z");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        ::java::lang::String Package::getImplementationTitle() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getImplementationTitle_14c7b5c5]));
        }

        ::java::lang::String Package::getImplementationVendor() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getImplementationVendor_14c7b5c5]));
        }

        ::java::lang::String Package::getImplementationVersion() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getImplementationVersion_14c7b5c5]));
        }

        ::java::lang::String Package::getName() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getName_14c7b5c5]));
        }

        Package Package::getPackage(const ::java::lang::String & a0)
        {
            jclass cls = initializeClass();
            return Package(env->callStaticObjectMethod(cls, mids$[mid_getPackage_d9fbaba1], a0.this$));
        }

        JArray< Package > Package::getPackages()
        {
            jclass cls = initializeClass();
            return JArray< Package >(env->callStaticObjectMethod(cls, mids$[mid_getPackages_c03e7c17]));
        }

        ::java::lang::String Package::getSpecificationTitle() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getSpecificationTitle_14c7b5c5]));
        }

        ::java::lang::String Package::getSpecificationVendor() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getSpecificationVendor_14c7b5c5]));
        }

        ::java::lang::String Package::getSpecificationVersion() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getSpecificationVersion_14c7b5c5]));
        }

        jint Package::hashCode() const
        {
            return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
        }

        jboolean Package::isCompatibleWith(const ::java::lang::String & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_isCompatibleWith_5fdc3f44], a0.this$);
        }

        jboolean Package::isSealed() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isSealed_54c6a16a]);
        }

        ::java::lang::String Package::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Package_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Package_instance_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Package_getImplementationTitle(t_Package *self);
        static PyObject *t_Package_getImplementationVendor(t_Package *self);
        static PyObject *t_Package_getImplementationVersion(t_Package *self);
        static PyObject *t_Package_getName(t_Package *self);
        static PyObject *t_Package_getPackage(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Package_getPackages(PyTypeObject *type);
        static PyObject *t_Package_getSpecificationTitle(t_Package *self);
        static PyObject *t_Package_getSpecificationVendor(t_Package *self);
        static PyObject *t_Package_getSpecificationVersion(t_Package *self);
        static PyObject *t_Package_hashCode(t_Package *self, PyObject *args);
        static PyObject *t_Package_isCompatibleWith(t_Package *self, PyObject *arg);
        static PyObject *t_Package_isSealed(t_Package *self);
        static PyObject *t_Package_toString(t_Package *self, PyObject *args);
        static PyObject *t_Package_get__implementationTitle(t_Package *self, void *data);
        static PyObject *t_Package_get__implementationVendor(t_Package *self, void *data);
        static PyObject *t_Package_get__implementationVersion(t_Package *self, void *data);
        static PyObject *t_Package_get__name(t_Package *self, void *data);
        static PyObject *t_Package_get__packages(t_Package *self, void *data);
        static PyObject *t_Package_get__sealed(t_Package *self, void *data);
        static PyObject *t_Package_get__specificationTitle(t_Package *self, void *data);
        static PyObject *t_Package_get__specificationVendor(t_Package *self, void *data);
        static PyObject *t_Package_get__specificationVersion(t_Package *self, void *data);
        static PyGetSetDef t_Package__fields_[] = {
            DECLARE_GET_FIELD(t_Package, implementationTitle),
            DECLARE_GET_FIELD(t_Package, implementationVendor),
            DECLARE_GET_FIELD(t_Package, implementationVersion),
            DECLARE_GET_FIELD(t_Package, name),
            DECLARE_GET_FIELD(t_Package, packages),
            DECLARE_GET_FIELD(t_Package, sealed),
            DECLARE_GET_FIELD(t_Package, specificationTitle),
            DECLARE_GET_FIELD(t_Package, specificationVendor),
            DECLARE_GET_FIELD(t_Package, specificationVersion),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_Package__methods_[] = {
            DECLARE_METHOD(t_Package, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Package, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Package, getImplementationTitle, METH_NOARGS),
            DECLARE_METHOD(t_Package, getImplementationVendor, METH_NOARGS),
            DECLARE_METHOD(t_Package, getImplementationVersion, METH_NOARGS),
            DECLARE_METHOD(t_Package, getName, METH_NOARGS),
            DECLARE_METHOD(t_Package, getPackage, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Package, getPackages, METH_NOARGS | METH_CLASS),
            DECLARE_METHOD(t_Package, getSpecificationTitle, METH_NOARGS),
            DECLARE_METHOD(t_Package, getSpecificationVendor, METH_NOARGS),
            DECLARE_METHOD(t_Package, getSpecificationVersion, METH_NOARGS),
            DECLARE_METHOD(t_Package, hashCode, METH_VARARGS),
            DECLARE_METHOD(t_Package, isCompatibleWith, METH_O),
            DECLARE_METHOD(t_Package, isSealed, METH_NOARGS),
            DECLARE_METHOD(t_Package, toString, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Package, t_Package, ::java::lang::Object, Package, abstract_init, 0, 0, t_Package__fields_, 0, 0);

        void t_Package::install(PyObject *module)
        {
            installType(&PY_TYPE(Package), module, "Package", 0);
        }

        void t_Package::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Package).tp_dict, "class_", make_descriptor(Package::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Package).tp_dict, "wrapfn_", make_descriptor(t_Package::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(Package).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_Package_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Package::initializeClass, 1)))
                return NULL;
            return t_Package::wrap_Object(Package(((t_Package *) arg)->object.this$));
        }
        static PyObject *t_Package_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Package::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static PyObject *t_Package_getImplementationTitle(t_Package *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getImplementationTitle());
            return j2p(result);
        }

        static PyObject *t_Package_getImplementationVendor(t_Package *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getImplementationVendor());
            return j2p(result);
        }

        static PyObject *t_Package_getImplementationVersion(t_Package *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getImplementationVersion());
            return j2p(result);
        }

        static PyObject *t_Package_getName(t_Package *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getName());
            return j2p(result);
        }

        static PyObject *t_Package_getPackage(PyTypeObject *type, PyObject *arg)
        {
            ::java::lang::String a0((jobject) NULL);
            Package result((jobject) NULL);

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = ::java::lang::Package::getPackage(a0));
                return t_Package::wrap_Object(result);
            }

            PyErr_SetArgsError(type, "getPackage", arg);
            return NULL;
        }

        static PyObject *t_Package_getPackages(PyTypeObject *type)
        {
            JArray< Package > result((jobject) NULL);
            OBJ_CALL(result = ::java::lang::Package::getPackages());
            return JArray<jobject>(result.this$).wrap(t_Package::wrap_jobject);
        }

        static PyObject *t_Package_getSpecificationTitle(t_Package *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getSpecificationTitle());
            return j2p(result);
        }

        static PyObject *t_Package_getSpecificationVendor(t_Package *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getSpecificationVendor());
            return j2p(result);
        }

        static PyObject *t_Package_getSpecificationVersion(t_Package *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getSpecificationVersion());
            return j2p(result);
        }

        static PyObject *t_Package_hashCode(t_Package *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.hashCode());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(Package), (PyObject *) self, "hashCode", args, 2);
        }

        static PyObject *t_Package_isCompatibleWith(t_Package *self, PyObject *arg)
        {
            ::java::lang::String a0((jobject) NULL);
            jboolean result;

            if (!parseArg(arg, "s", &a0))
            {
                OBJ_CALL(result = self->object.isCompatibleWith(a0));
                Py_RETURN_BOOL(result);
            }

            PyErr_SetArgsError((PyObject *) self, "isCompatibleWith", arg);
            return NULL;
        }

        static PyObject *t_Package_isSealed(t_Package *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isSealed());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_Package_toString(t_Package *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(Package), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_Package_get__implementationTitle(t_Package *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getImplementationTitle());
            return j2p(value);
        }

        static PyObject *t_Package_get__implementationVendor(t_Package *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getImplementationVendor());
            return j2p(value);
        }

        static PyObject *t_Package_get__implementationVersion(t_Package *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getImplementationVersion());
            return j2p(value);
        }

        static PyObject *t_Package_get__name(t_Package *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getName());
            return j2p(value);
        }

        static PyObject *t_Package_get__packages(t_Package *self, void *data)
        {
            JArray< Package > value((jobject) NULL);
            OBJ_CALL(value = self->object.getPackages());
            return JArray<jobject>(value.this$).wrap(t_Package::wrap_jobject);
        }

        static PyObject *t_Package_get__sealed(t_Package *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isSealed());
            Py_RETURN_BOOL(value);
        }

        static PyObject *t_Package_get__specificationTitle(t_Package *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getSpecificationTitle());
            return j2p(value);
        }

        static PyObject *t_Package_get__specificationVendor(t_Package *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getSpecificationVendor());
            return j2p(value);
        }

        static PyObject *t_Package_get__specificationVersion(t_Package *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getSpecificationVersion());
            return j2p(value);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "scala/ScalaObject.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace scala {

    ::java::lang::Class *ScalaObject::class$ = NULL;
    jmethodID *ScalaObject::mids$ = NULL;

    jclass ScalaObject::initializeClass()
    {
        if (!class$)
        {

            jclass cls = (jclass) env->findClass("scala/ScalaObject");

            class$ = (::java::lang::Class *) new JObject(cls);
        }
        return (jclass) class$->this$;
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace scala {
    static PyObject *t_ScalaObject_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_ScalaObject_instance_(PyTypeObject *type, PyObject *arg);

    static PyMethodDef t_ScalaObject__methods_[] = {
        DECLARE_METHOD(t_ScalaObject, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_ScalaObject, instance_, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(ScalaObject, t_ScalaObject, ::java::lang::Object, ScalaObject, abstract_init, 0, 0, 0, 0, 0);

    void t_ScalaObject::install(PyObject *module)
    {
        installType(&PY_TYPE(ScalaObject), module, "ScalaObject", 0);
    }

    void t_ScalaObject::initialize(PyObject *module)
    {
        PyDict_SetItemString(PY_TYPE(ScalaObject).tp_dict, "class_", make_descriptor(ScalaObject::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(ScalaObject).tp_dict, "wrapfn_", make_descriptor(t_ScalaObject::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(ScalaObject).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_ScalaObject_cast_(PyTypeObject *type, PyObject *arg)
    {
        if (!(arg = castCheck(arg, ScalaObject::initializeClass, 1)))
            return NULL;
        return t_ScalaObject::wrap_Object(ScalaObject(((t_ScalaObject *) arg)->object.this$));
    }
    static PyObject *t_ScalaObject_instance_(PyTypeObject *type, PyObject *arg)
    {
        if (!castCheck(arg, ScalaObject::initializeClass, 0))
            Py_RETURN_FALSE;
        Py_RETURN_TRUE;
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/CharSequence.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *CharSequence::class$ = NULL;
        jmethodID *CharSequence::mids$ = NULL;

        jclass CharSequence::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/CharSequence");

                mids$ = new jmethodID[max_mid];
                mids$[mid_charAt_39c7bd29] = env->getMethodID(cls, "charAt", "(I)C");
                mids$[mid_length_54c6a179] = env->getMethodID(cls, "length", "()I");
                mids$[mid_subSequence_f88dfd57] = env->getMethodID(cls, "subSequence", "(II)Ljava/lang/CharSequence;");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        jchar CharSequence::charAt(jint a0) const
        {
            return env->callCharMethod(this$, mids$[mid_charAt_39c7bd29], a0);
        }

        jint CharSequence::length() const
        {
            return env->callIntMethod(this$, mids$[mid_length_54c6a179]);
        }

        CharSequence CharSequence::subSequence(jint a0, jint a1) const
        {
            return CharSequence(env->callObjectMethod(this$, mids$[mid_subSequence_f88dfd57], a0, a1));
        }

        ::java::lang::String CharSequence::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_CharSequence_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_CharSequence_instance_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_CharSequence_charAt(t_CharSequence *self, PyObject *arg);
        static PyObject *t_CharSequence_length(t_CharSequence *self);
        static PyObject *t_CharSequence_subSequence(t_CharSequence *self, PyObject *args);
        static PyObject *t_CharSequence_toString(t_CharSequence *self, PyObject *args);

        static PyMethodDef t_CharSequence__methods_[] = {
            DECLARE_METHOD(t_CharSequence, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_CharSequence, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_CharSequence, charAt, METH_O),
            DECLARE_METHOD(t_CharSequence, length, METH_NOARGS),
            DECLARE_METHOD(t_CharSequence, subSequence, METH_VARARGS),
            DECLARE_METHOD(t_CharSequence, toString, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(CharSequence, t_CharSequence, ::java::lang::Object, CharSequence, abstract_init, 0, 0, 0, 0, 0);

        void t_CharSequence::install(PyObject *module)
        {
            installType(&PY_TYPE(CharSequence), module, "CharSequence", 0);
        }

        void t_CharSequence::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(CharSequence).tp_dict, "class_", make_descriptor(CharSequence::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(CharSequence).tp_dict, "wrapfn_", make_descriptor(t_CharSequence::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(CharSequence).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_CharSequence_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, CharSequence::initializeClass, 1)))
                return NULL;
            return t_CharSequence::wrap_Object(CharSequence(((t_CharSequence *) arg)->object.this$));
        }
        static PyObject *t_CharSequence_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, CharSequence::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static PyObject *t_CharSequence_charAt(t_CharSequence *self, PyObject *arg)
        {
            jint a0;
            jchar result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = self->object.charAt(a0));
                return PyUnicode_FromUnicode((Py_UNICODE *) &result, 1);
            }

            PyErr_SetArgsError((PyObject *) self, "charAt", arg);
            return NULL;
        }

        static PyObject *t_CharSequence_length(t_CharSequence *self)
        {
            jint result;
            OBJ_CALL(result = self->object.length());
            return PyInt_FromLong((long) result);
        }

        static PyObject *t_CharSequence_subSequence(t_CharSequence *self, PyObject *args)
        {
            jint a0;
            jint a1;
            CharSequence result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.subSequence(a0, a1));
                return t_CharSequence::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "subSequence", args);
            return NULL;
        }

        static PyObject *t_CharSequence_toString(t_CharSequence *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(CharSequence), (PyObject *) self, "toString", args, 2);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Appendable.h"
#include "java/lang/CharSequence.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Appendable::class$ = NULL;
        jmethodID *Appendable::mids$ = NULL;

        jclass Appendable::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Appendable");

                mids$ = new jmethodID[max_mid];
                mids$[mid_append_fac808c8] = env->getMethodID(cls, "append", "(C)Ljava/lang/Appendable;");
                mids$[mid_append_ca3c2aa4] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;)Ljava/lang/Appendable;");
                mids$[mid_append_7f83fd04] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;II)Ljava/lang/Appendable;");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        Appendable Appendable::append(jchar a0) const
        {
            return Appendable(env->callObjectMethod(this$, mids$[mid_append_fac808c8], a0));
        }

        Appendable Appendable::append(const ::java::lang::CharSequence & a0) const
        {
            return Appendable(env->callObjectMethod(this$, mids$[mid_append_ca3c2aa4], a0.this$));
        }

        Appendable Appendable::append(const ::java::lang::CharSequence & a0, jint a1, jint a2) const
        {
            return Appendable(env->callObjectMethod(this$, mids$[mid_append_7f83fd04], a0.this$, a1, a2));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Appendable_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Appendable_instance_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Appendable_append(t_Appendable *self, PyObject *args);

        static PyMethodDef t_Appendable__methods_[] = {
            DECLARE_METHOD(t_Appendable, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Appendable, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Appendable, append, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Appendable, t_Appendable, ::java::lang::Object, Appendable, abstract_init, 0, 0, 0, 0, 0);

        void t_Appendable::install(PyObject *module)
        {
            installType(&PY_TYPE(Appendable), module, "Appendable", 0);
        }

        void t_Appendable::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Appendable).tp_dict, "class_", make_descriptor(Appendable::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Appendable).tp_dict, "wrapfn_", make_descriptor(t_Appendable::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(Appendable).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_Appendable_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Appendable::initializeClass, 1)))
                return NULL;
            return t_Appendable::wrap_Object(Appendable(((t_Appendable *) arg)->object.this$));
        }
        static PyObject *t_Appendable_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Appendable::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static PyObject *t_Appendable_append(t_Appendable *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jchar a0;
                    Appendable result((jobject) NULL);

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_Appendable::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    Appendable result((jobject) NULL);

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_Appendable::wrap_Object(result);
                    }
                }
                break;
              case 3:
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    Appendable result((jobject) NULL);

                    if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = self->object.append(a0, a1, a2));
                        return t_Appendable::wrap_Object(result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "append", args);
            return NULL;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "scala/Function1$mcID$sp.h"
#include "java/lang/Object.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace scala {

    ::java::lang::Class *Function1$mcID$sp::class$ = NULL;
    jmethodID *Function1$mcID$sp::mids$ = NULL;

    jclass Function1$mcID$sp::initializeClass()
    {
        if (!class$)
        {

            jclass cls = (jclass) env->findClass("scala/Function1$mcID$sp");

            mids$ = new jmethodID[max_mid];
            mids$[mid_andThen_279d294f] = env->getMethodID(cls, "andThen", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcID$sp_279d294f] = env->getMethodID(cls, "andThen$mcID$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_apply_5d1c765a] = env->getMethodID(cls, "apply", "(D)I");
            mids$[mid_compose_279d294f] = env->getMethodID(cls, "compose", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcID$sp_279d294f] = env->getMethodID(cls, "compose$mcID$sp", "(Lscala/Function1;)Lscala/Function1;");

            class$ = (::java::lang::Class *) new JObject(cls);
        }
        return (jclass) class$->this$;
    }

    ::scala::Function1 Function1$mcID$sp::andThen(const ::scala::Function1 & a0) const
    {
        return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen_279d294f], a0.this$));
    }

    ::scala::Function1 Function1$mcID$sp::andThen$mcID$sp(const ::scala::Function1 & a0) const
    {
        return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcID$sp_279d294f], a0.this$));
    }

    jint Function1$mcID$sp::apply(jdouble a0) const
    {
        return env->callIntMethod(this$, mids$[mid_apply_5d1c765a], a0);
    }

    ::scala::Function1 Function1$mcID$sp::compose(const ::scala::Function1 & a0) const
    {
        return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose_279d294f], a0.this$));
    }

    ::scala::Function1 Function1$mcID$sp::compose$mcID$sp(const ::scala::Function1 & a0) const
    {
        return ::scala::Function1(env->callObjectMethod(this$, mids$[mid_compose$mcID$sp_279d294f], a0.this$));
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace scala {
    static PyObject *t_Function1$mcID$sp_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Function1$mcID$sp_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Function1$mcID$sp_andThen(t_Function1$mcID$sp *self, PyObject *args);
    static PyObject *t_Function1$mcID$sp_andThen$mcID$sp(t_Function1$mcID$sp *self, PyObject *args);
    static PyObject *t_Function1$mcID$sp_apply(t_Function1$mcID$sp *self, PyObject *args);
    static PyObject *t_Function1$mcID$sp_compose(t_Function1$mcID$sp *self, PyObject *args);
    static PyObject *t_Function1$mcID$sp_compose$mcID$sp(t_Function1$mcID$sp *self, PyObject *args);

    static PyMethodDef t_Function1$mcID$sp__methods_[] = {
        DECLARE_METHOD(t_Function1$mcID$sp, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_Function1$mcID$sp, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_Function1$mcID$sp, andThen, METH_VARARGS),
        DECLARE_METHOD(t_Function1$mcID$sp, andThen$mcID$sp, METH_VARARGS),
        DECLARE_METHOD(t_Function1$mcID$sp, apply, METH_VARARGS),
        DECLARE_METHOD(t_Function1$mcID$sp, compose, METH_VARARGS),
        DECLARE_METHOD(t_Function1$mcID$sp, compose$mcID$sp, METH_VARARGS),
        { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Function1$mcID$sp, t_Function1$mcID$sp, ::scala::Function1, Function1$mcID$sp, abstract_init, 0, 0, 0, 0, 0);

    void t_Function1$mcID$sp::install(PyObject *module)
    {
        installType(&PY_TYPE(Function1$mcID$sp), module, "Function1$mcID$sp", 0);
    }

    void t_Function1$mcID$sp::initialize(PyObject *module)
    {
        PyDict_SetItemString(PY_TYPE(Function1$mcID$sp).tp_dict, "class_", make_descriptor(Function1$mcID$sp::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(Function1$mcID$sp).tp_dict, "wrapfn_", make_descriptor(t_Function1$mcID$sp::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(Function1$mcID$sp).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_Function1$mcID$sp_cast_(PyTypeObject *type, PyObject *arg)
    {
        if (!(arg = castCheck(arg, Function1$mcID$sp::initializeClass, 1)))
            return NULL;
        return t_Function1$mcID$sp::wrap_Object(Function1$mcID$sp(((t_Function1$mcID$sp *) arg)->object.this$));
    }
    static PyObject *t_Function1$mcID$sp_instance_(PyTypeObject *type, PyObject *arg)
    {
        if (!castCheck(arg, Function1$mcID$sp::initializeClass, 0))
            Py_RETURN_FALSE;
        Py_RETURN_TRUE;
    }

    static PyObject *t_Function1$mcID$sp_andThen(t_Function1$mcID$sp *self, PyObject *args)
    {
        ::scala::Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        ::scala::Function1 result((jobject) NULL);

        if (!parseArgs(args, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen(a0));
            return ::scala::t_Function1::wrap_Object(result);
        }

        return callSuper(&PY_TYPE(Function1$mcID$sp), (PyObject *) self, "andThen", args, 2);
    }

    static PyObject *t_Function1$mcID$sp_andThen$mcID$sp(t_Function1$mcID$sp *self, PyObject *args)
    {
        ::scala::Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        ::scala::Function1 result((jobject) NULL);

        if (!parseArgs(args, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcID$sp(a0));
            return ::scala::t_Function1::wrap_Object(result);
        }

        return callSuper(&PY_TYPE(Function1$mcID$sp), (PyObject *) self, "andThen$mcID$sp", args, 2);
    }

    static PyObject *t_Function1$mcID$sp_apply(t_Function1$mcID$sp *self, PyObject *args)
    {
        jdouble a0;
        jint result;

        if (!parseArgs(args, "D", &a0))
        {
            OBJ_CALL(result = self->object.apply(a0));
            return PyInt_FromLong((long) result);
        }

        return callSuper(&PY_TYPE(Function1$mcID$sp), (PyObject *) self, "apply", args, 2);
    }

    static PyObject *t_Function1$mcID$sp_compose(t_Function1$mcID$sp *self, PyObject *args)
    {
        ::scala::Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        ::scala::Function1 result((jobject) NULL);

        if (!parseArgs(args, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose(a0));
            return ::scala::t_Function1::wrap_Object(result);
        }

        return callSuper(&PY_TYPE(Function1$mcID$sp), (PyObject *) self, "compose", args, 2);
    }

    static PyObject *t_Function1$mcID$sp_compose$mcID$sp(t_Function1$mcID$sp *self, PyObject *args)
    {
        ::scala::Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        ::scala::Function1 result((jobject) NULL);

        if (!parseArgs(args, "K", ::scala::Function1::initializeClass, &a0, &p0, ::scala::t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcID$sp(a0));
            return ::scala::t_Function1::wrap_Object(result);
        }

        return callSuper(&PY_TYPE(Function1$mcID$sp), (PyObject *) self, "compose$mcID$sp", args, 2);
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "scala/Function1.h"
#include "java/lang/String.h"
#include "java/lang/Object.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace scala {

    ::java::lang::Class *Function1::class$ = NULL;
    jmethodID *Function1::mids$ = NULL;

    jclass Function1::initializeClass()
    {
        if (!class$)
        {

            jclass cls = (jclass) env->findClass("scala/Function1");

            mids$ = new jmethodID[max_mid];
            mids$[mid_andThen_279d294f] = env->getMethodID(cls, "andThen", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcDD$sp_279d294f] = env->getMethodID(cls, "andThen$mcDD$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcDF$sp_279d294f] = env->getMethodID(cls, "andThen$mcDF$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcDI$sp_279d294f] = env->getMethodID(cls, "andThen$mcDI$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcDJ$sp_279d294f] = env->getMethodID(cls, "andThen$mcDJ$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcFD$sp_279d294f] = env->getMethodID(cls, "andThen$mcFD$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcFF$sp_279d294f] = env->getMethodID(cls, "andThen$mcFF$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcFI$sp_279d294f] = env->getMethodID(cls, "andThen$mcFI$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcFJ$sp_279d294f] = env->getMethodID(cls, "andThen$mcFJ$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcID$sp_279d294f] = env->getMethodID(cls, "andThen$mcID$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcIF$sp_279d294f] = env->getMethodID(cls, "andThen$mcIF$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcII$sp_279d294f] = env->getMethodID(cls, "andThen$mcII$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcIJ$sp_279d294f] = env->getMethodID(cls, "andThen$mcIJ$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcJD$sp_279d294f] = env->getMethodID(cls, "andThen$mcJD$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcJF$sp_279d294f] = env->getMethodID(cls, "andThen$mcJF$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcJI$sp_279d294f] = env->getMethodID(cls, "andThen$mcJI$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcJJ$sp_279d294f] = env->getMethodID(cls, "andThen$mcJJ$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcZD$sp_279d294f] = env->getMethodID(cls, "andThen$mcZD$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcZF$sp_279d294f] = env->getMethodID(cls, "andThen$mcZF$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcZI$sp_279d294f] = env->getMethodID(cls, "andThen$mcZI$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_andThen$mcZJ$sp_279d294f] = env->getMethodID(cls, "andThen$mcZJ$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_apply_a932a95f] = env->getMethodID(cls, "apply", "(Ljava/lang/Object;)Ljava/lang/Object;");
            mids$[mid_apply$mcDD$sp_5d1c7657] = env->getMethodID(cls, "apply$mcDD$sp", "(D)D");
            mids$[mid_apply$mcDF$sp_06298cb9] = env->getMethodID(cls, "apply$mcDF$sp", "(F)D");
            mids$[mid_apply$mcDI$sp_39c7bd2e] = env->getMethodID(cls, "apply$mcDI$sp", "(I)D");
            mids$[mid_apply$mcDJ$sp_0ee6df3d] = env->getMethodID(cls, "apply$mcDJ$sp", "(J)D");
            mids$[mid_apply$mcFD$sp_5d1c7655] = env->getMethodID(cls, "apply$mcFD$sp", "(D)F");
            mids$[mid_apply$mcFF$sp_06298cbb] = env->getMethodID(cls, "apply$mcFF$sp", "(F)F");
            mids$[mid_apply$mcFI$sp_39c7bd2c] = env->getMethodID(cls, "apply$mcFI$sp", "(I)F");
            mids$[mid_apply$mcFJ$sp_0ee6df3f] = env->getMethodID(cls, "apply$mcFJ$sp", "(J)F");
            mids$[mid_apply$mcID$sp_5d1c765a] = env->getMethodID(cls, "apply$mcID$sp", "(D)I");
            mids$[mid_apply$mcIF$sp_06298cb4] = env->getMethodID(cls, "apply$mcIF$sp", "(F)I");
            mids$[mid_apply$mcII$sp_39c7bd23] = env->getMethodID(cls, "apply$mcII$sp", "(I)I");
            mids$[mid_apply$mcIJ$sp_0ee6df30] = env->getMethodID(cls, "apply$mcIJ$sp", "(J)I");
            mids$[mid_apply$mcJD$sp_5d1c7659] = env->getMethodID(cls, "apply$mcJD$sp", "(D)J");
            mids$[mid_apply$mcJF$sp_06298cb7] = env->getMethodID(cls, "apply$mcJF$sp", "(F)J");
            mids$[mid_apply$mcJI$sp_39c7bd20] = env->getMethodID(cls, "apply$mcJI$sp", "(I)J");
            mids$[mid_apply$mcJJ$sp_0ee6df33] = env->getMethodID(cls, "apply$mcJJ$sp", "(J)J");
            mids$[mid_apply$mcVD$sp_5d1c7645] = env->getMethodID(cls, "apply$mcVD$sp", "(D)V");
            mids$[mid_apply$mcVF$sp_06298cab] = env->getMethodID(cls, "apply$mcVF$sp", "(F)V");
            mids$[mid_apply$mcVI$sp_39c7bd3c] = env->getMethodID(cls, "apply$mcVI$sp", "(I)V");
            mids$[mid_apply$mcVJ$sp_0ee6df2f] = env->getMethodID(cls, "apply$mcVJ$sp", "(J)V");
            mids$[mid_apply$mcZD$sp_5d1c7649] = env->getMethodID(cls, "apply$mcZD$sp", "(D)Z");
            mids$[mid_apply$mcZF$sp_06298ca7] = env->getMethodID(cls, "apply$mcZF$sp", "(F)Z");
            mids$[mid_apply$mcZI$sp_39c7bd30] = env->getMethodID(cls, "apply$mcZI$sp", "(I)Z");
            mids$[mid_apply$mcZJ$sp_0ee6df23] = env->getMethodID(cls, "apply$mcZJ$sp", "(J)Z");
            mids$[mid_compose_279d294f] = env->getMethodID(cls, "compose", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcDD$sp_279d294f] = env->getMethodID(cls, "compose$mcDD$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcDF$sp_279d294f] = env->getMethodID(cls, "compose$mcDF$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcDI$sp_279d294f] = env->getMethodID(cls, "compose$mcDI$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcDJ$sp_279d294f] = env->getMethodID(cls, "compose$mcDJ$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcFD$sp_279d294f] = env->getMethodID(cls, "compose$mcFD$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcFF$sp_279d294f] = env->getMethodID(cls, "compose$mcFF$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcFI$sp_279d294f] = env->getMethodID(cls, "compose$mcFI$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcFJ$sp_279d294f] = env->getMethodID(cls, "compose$mcFJ$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcID$sp_279d294f] = env->getMethodID(cls, "compose$mcID$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcIF$sp_279d294f] = env->getMethodID(cls, "compose$mcIF$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcII$sp_279d294f] = env->getMethodID(cls, "compose$mcII$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcIJ$sp_279d294f] = env->getMethodID(cls, "compose$mcIJ$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcJD$sp_279d294f] = env->getMethodID(cls, "compose$mcJD$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcJF$sp_279d294f] = env->getMethodID(cls, "compose$mcJF$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcJI$sp_279d294f] = env->getMethodID(cls, "compose$mcJI$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcJJ$sp_279d294f] = env->getMethodID(cls, "compose$mcJJ$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcZD$sp_279d294f] = env->getMethodID(cls, "compose$mcZD$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcZF$sp_279d294f] = env->getMethodID(cls, "compose$mcZF$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcZI$sp_279d294f] = env->getMethodID(cls, "compose$mcZI$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_compose$mcZJ$sp_279d294f] = env->getMethodID(cls, "compose$mcZJ$sp", "(Lscala/Function1;)Lscala/Function1;");
            mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");

            class$ = (::java::lang::Class *) new JObject(cls);
        }
        return (jclass) class$->this$;
    }

    Function1 Function1::andThen(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcDD$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcDD$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcDF$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcDF$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcDI$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcDI$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcDJ$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcDJ$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcFD$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcFD$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcFF$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcFF$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcFI$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcFI$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcFJ$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcFJ$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcID$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcID$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcIF$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcIF$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcII$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcII$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcIJ$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcIJ$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcJD$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcJD$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcJF$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcJF$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcJI$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcJI$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcJJ$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcJJ$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcZD$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcZD$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcZF$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcZF$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcZI$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcZI$sp_279d294f], a0.this$));
    }

    Function1 Function1::andThen$mcZJ$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_andThen$mcZJ$sp_279d294f], a0.this$));
    }

    ::java::lang::Object Function1::apply(const ::java::lang::Object & a0) const
    {
        return ::java::lang::Object(env->callObjectMethod(this$, mids$[mid_apply_a932a95f], a0.this$));
    }

    jdouble Function1::apply$mcDD$sp(jdouble a0) const
    {
        return env->callDoubleMethod(this$, mids$[mid_apply$mcDD$sp_5d1c7657], a0);
    }

    jdouble Function1::apply$mcDF$sp(jfloat a0) const
    {
        return env->callDoubleMethod(this$, mids$[mid_apply$mcDF$sp_06298cb9], a0);
    }

    jdouble Function1::apply$mcDI$sp(jint a0) const
    {
        return env->callDoubleMethod(this$, mids$[mid_apply$mcDI$sp_39c7bd2e], a0);
    }

    jdouble Function1::apply$mcDJ$sp(jlong a0) const
    {
        return env->callDoubleMethod(this$, mids$[mid_apply$mcDJ$sp_0ee6df3d], a0);
    }

    jfloat Function1::apply$mcFD$sp(jdouble a0) const
    {
        return env->callFloatMethod(this$, mids$[mid_apply$mcFD$sp_5d1c7655], a0);
    }

    jfloat Function1::apply$mcFF$sp(jfloat a0) const
    {
        return env->callFloatMethod(this$, mids$[mid_apply$mcFF$sp_06298cbb], a0);
    }

    jfloat Function1::apply$mcFI$sp(jint a0) const
    {
        return env->callFloatMethod(this$, mids$[mid_apply$mcFI$sp_39c7bd2c], a0);
    }

    jfloat Function1::apply$mcFJ$sp(jlong a0) const
    {
        return env->callFloatMethod(this$, mids$[mid_apply$mcFJ$sp_0ee6df3f], a0);
    }

    jint Function1::apply$mcID$sp(jdouble a0) const
    {
        return env->callIntMethod(this$, mids$[mid_apply$mcID$sp_5d1c765a], a0);
    }

    jint Function1::apply$mcIF$sp(jfloat a0) const
    {
        return env->callIntMethod(this$, mids$[mid_apply$mcIF$sp_06298cb4], a0);
    }

    jint Function1::apply$mcII$sp(jint a0) const
    {
        return env->callIntMethod(this$, mids$[mid_apply$mcII$sp_39c7bd23], a0);
    }

    jint Function1::apply$mcIJ$sp(jlong a0) const
    {
        return env->callIntMethod(this$, mids$[mid_apply$mcIJ$sp_0ee6df30], a0);
    }

    jlong Function1::apply$mcJD$sp(jdouble a0) const
    {
        return env->callLongMethod(this$, mids$[mid_apply$mcJD$sp_5d1c7659], a0);
    }

    jlong Function1::apply$mcJF$sp(jfloat a0) const
    {
        return env->callLongMethod(this$, mids$[mid_apply$mcJF$sp_06298cb7], a0);
    }

    jlong Function1::apply$mcJI$sp(jint a0) const
    {
        return env->callLongMethod(this$, mids$[mid_apply$mcJI$sp_39c7bd20], a0);
    }

    jlong Function1::apply$mcJJ$sp(jlong a0) const
    {
        return env->callLongMethod(this$, mids$[mid_apply$mcJJ$sp_0ee6df33], a0);
    }

    void Function1::apply$mcVD$sp(jdouble a0) const
    {
        env->callVoidMethod(this$, mids$[mid_apply$mcVD$sp_5d1c7645], a0);
    }

    void Function1::apply$mcVF$sp(jfloat a0) const
    {
        env->callVoidMethod(this$, mids$[mid_apply$mcVF$sp_06298cab], a0);
    }

    void Function1::apply$mcVI$sp(jint a0) const
    {
        env->callVoidMethod(this$, mids$[mid_apply$mcVI$sp_39c7bd3c], a0);
    }

    void Function1::apply$mcVJ$sp(jlong a0) const
    {
        env->callVoidMethod(this$, mids$[mid_apply$mcVJ$sp_0ee6df2f], a0);
    }

    jboolean Function1::apply$mcZD$sp(jdouble a0) const
    {
        return env->callBooleanMethod(this$, mids$[mid_apply$mcZD$sp_5d1c7649], a0);
    }

    jboolean Function1::apply$mcZF$sp(jfloat a0) const
    {
        return env->callBooleanMethod(this$, mids$[mid_apply$mcZF$sp_06298ca7], a0);
    }

    jboolean Function1::apply$mcZI$sp(jint a0) const
    {
        return env->callBooleanMethod(this$, mids$[mid_apply$mcZI$sp_39c7bd30], a0);
    }

    jboolean Function1::apply$mcZJ$sp(jlong a0) const
    {
        return env->callBooleanMethod(this$, mids$[mid_apply$mcZJ$sp_0ee6df23], a0);
    }

    Function1 Function1::compose(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcDD$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcDD$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcDF$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcDF$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcDI$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcDI$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcDJ$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcDJ$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcFD$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcFD$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcFF$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcFF$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcFI$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcFI$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcFJ$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcFJ$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcID$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcID$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcIF$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcIF$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcII$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcII$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcIJ$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcIJ$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcJD$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcJD$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcJF$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcJF$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcJI$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcJI$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcJJ$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcJJ$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcZD$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcZD$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcZF$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcZF$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcZI$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcZI$sp_279d294f], a0.this$));
    }

    Function1 Function1::compose$mcZJ$sp(const Function1 & a0) const
    {
        return Function1(env->callObjectMethod(this$, mids$[mid_compose$mcZJ$sp_279d294f], a0.this$));
    }

    ::java::lang::String Function1::toString() const
    {
        return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace scala {
    static PyObject *t_Function1_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Function1_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Function1_of_(t_Function1 *self, PyObject *args);
    static PyObject *t_Function1_andThen(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcDD$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcDF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcDI$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcDJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcFD$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcFF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcFI$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcFJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcID$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcIF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcII$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcIJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcJD$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcJF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcJI$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcJJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcZD$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcZF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcZI$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_andThen$mcZJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcDD$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcDF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcDI$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcDJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcFD$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcFF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcFI$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcFJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcID$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcIF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcII$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcIJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcJD$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcJF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcJI$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcJJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcVD$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcVF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcVI$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcVJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcZD$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcZF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcZI$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_apply$mcZJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcDD$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcDF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcDI$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcDJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcFD$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcFF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcFI$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcFJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcID$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcIF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcII$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcIJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcJD$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcJF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcJI$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcJJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcZD$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcZF$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcZI$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_compose$mcZJ$sp(t_Function1 *self, PyObject *arg);
    static PyObject *t_Function1_toString(t_Function1 *self);
    static PyObject *t_Function1_get__parameters_(t_Function1 *self, void *data);
    static PyGetSetDef t_Function1__fields_[] = {
        DECLARE_GET_FIELD(t_Function1, parameters_),
        { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_Function1__methods_[] = {
        DECLARE_METHOD(t_Function1, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_Function1, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_Function1, of_, METH_VARARGS),
        DECLARE_METHOD(t_Function1, andThen, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcDD$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcDF$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcDI$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcDJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcFD$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcFF$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcFI$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcFJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcID$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcIF$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcII$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcIJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcJD$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcJF$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcJI$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcJJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcZD$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcZF$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcZI$sp, METH_O),
        DECLARE_METHOD(t_Function1, andThen$mcZJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcDD$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcDF$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcDI$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcDJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcFD$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcFF$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcFI$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcFJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcID$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcIF$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcII$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcIJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcJD$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcJF$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcJI$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcJJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcVD$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcVF$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcVI$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcVJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcZD$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcZF$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcZI$sp, METH_O),
        DECLARE_METHOD(t_Function1, apply$mcZJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcDD$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcDF$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcDI$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcDJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcFD$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcFF$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcFI$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcFJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcID$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcIF$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcII$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcIJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcJD$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcJF$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcJI$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcJJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcZD$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcZF$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcZI$sp, METH_O),
        DECLARE_METHOD(t_Function1, compose$mcZJ$sp, METH_O),
        DECLARE_METHOD(t_Function1, toString, METH_NOARGS),
        { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Function1, t_Function1, ::scala::ScalaObject, Function1, abstract_init, 0, 0, t_Function1__fields_, 0, 0);
    PyObject *t_Function1::wrap_Object(const Function1& object, PyTypeObject *T1, PyTypeObject *R)
    {
        PyObject *obj = t_Function1::wrap_Object(object);
        if (obj != NULL && obj != Py_None)
        {
            t_Function1 *self = (t_Function1 *) obj;
            self->parameters[0] = T1;
            self->parameters[1] = R;
        }
        return obj;
    }

    PyObject *t_Function1::wrap_jobject(const jobject& object, PyTypeObject *T1, PyTypeObject *R)
    {
        PyObject *obj = t_Function1::wrap_jobject(object);
        if (obj != NULL && obj != Py_None)
        {
            t_Function1 *self = (t_Function1 *) obj;
            self->parameters[0] = T1;
            self->parameters[1] = R;
        }
        return obj;
    }

    void t_Function1::install(PyObject *module)
    {
        installType(&PY_TYPE(Function1), module, "Function1", 0);
    }

    void t_Function1::initialize(PyObject *module)
    {
        PyDict_SetItemString(PY_TYPE(Function1).tp_dict, "class_", make_descriptor(Function1::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(Function1).tp_dict, "wrapfn_", make_descriptor(t_Function1::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(Function1).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_Function1_cast_(PyTypeObject *type, PyObject *arg)
    {
        if (!(arg = castCheck(arg, Function1::initializeClass, 1)))
            return NULL;
        return t_Function1::wrap_Object(Function1(((t_Function1 *) arg)->object.this$));
    }
    static PyObject *t_Function1_instance_(PyTypeObject *type, PyObject *arg)
    {
        if (!castCheck(arg, Function1::initializeClass, 0))
            Py_RETURN_FALSE;
        Py_RETURN_TRUE;
    }

    static PyObject *t_Function1_of_(t_Function1 *self, PyObject *args)
    {
        if (!parseArg(args, "T", 2, &(self->parameters)))
            Py_RETURN_SELF;
        return PyErr_SetArgsError((PyObject *) self, "of_", args);
    }

    static PyObject *t_Function1_andThen(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcDD$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcDD$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcDD$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcDF$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcDF$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcDF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcDI$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcDI$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcDI$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcDJ$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcDJ$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcDJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcFD$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcFD$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcFD$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcFF$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcFF$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcFF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcFI$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcFI$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcFI$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcFJ$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcFJ$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcFJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcID$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcID$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcID$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcIF$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcIF$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcIF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcII$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcII$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcII$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcIJ$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcIJ$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcIJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcJD$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcJD$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcJD$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcJF$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcJF$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcJF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcJI$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcJI$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcJI$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcJJ$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcJJ$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcJJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcZD$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcZD$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcZD$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcZF$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcZF$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcZF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcZI$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcZI$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcZI$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_andThen$mcZJ$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.andThen$mcZJ$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "andThen$mcZJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply(t_Function1 *self, PyObject *arg)
    {
        ::java::lang::Object a0((jobject) NULL);
        ::java::lang::Object result((jobject) NULL);

        if (!parseArg(arg, "O", self->parameters[0], &a0))
        {
            OBJ_CALL(result = self->object.apply(a0));
            return self->parameters[1] != NULL ? wrapType(self->parameters[1], result.this$) : ::java::lang::t_Object::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcDD$sp(t_Function1 *self, PyObject *arg)
    {
        jdouble a0;
        jdouble result;

        if (!parseArg(arg, "D", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcDD$sp(a0));
            return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcDD$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcDF$sp(t_Function1 *self, PyObject *arg)
    {
        jfloat a0;
        jdouble result;

        if (!parseArg(arg, "F", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcDF$sp(a0));
            return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcDF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcDI$sp(t_Function1 *self, PyObject *arg)
    {
        jint a0;
        jdouble result;

        if (!parseArg(arg, "I", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcDI$sp(a0));
            return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcDI$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcDJ$sp(t_Function1 *self, PyObject *arg)
    {
        jlong a0;
        jdouble result;

        if (!parseArg(arg, "J", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcDJ$sp(a0));
            return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcDJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcFD$sp(t_Function1 *self, PyObject *arg)
    {
        jdouble a0;
        jfloat result;

        if (!parseArg(arg, "D", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcFD$sp(a0));
            return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcFD$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcFF$sp(t_Function1 *self, PyObject *arg)
    {
        jfloat a0;
        jfloat result;

        if (!parseArg(arg, "F", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcFF$sp(a0));
            return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcFF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcFI$sp(t_Function1 *self, PyObject *arg)
    {
        jint a0;
        jfloat result;

        if (!parseArg(arg, "I", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcFI$sp(a0));
            return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcFI$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcFJ$sp(t_Function1 *self, PyObject *arg)
    {
        jlong a0;
        jfloat result;

        if (!parseArg(arg, "J", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcFJ$sp(a0));
            return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcFJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcID$sp(t_Function1 *self, PyObject *arg)
    {
        jdouble a0;
        jint result;

        if (!parseArg(arg, "D", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcID$sp(a0));
            return PyInt_FromLong((long) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcID$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcIF$sp(t_Function1 *self, PyObject *arg)
    {
        jfloat a0;
        jint result;

        if (!parseArg(arg, "F", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcIF$sp(a0));
            return PyInt_FromLong((long) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcIF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcII$sp(t_Function1 *self, PyObject *arg)
    {
        jint a0;
        jint result;

        if (!parseArg(arg, "I", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcII$sp(a0));
            return PyInt_FromLong((long) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcII$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcIJ$sp(t_Function1 *self, PyObject *arg)
    {
        jlong a0;
        jint result;

        if (!parseArg(arg, "J", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcIJ$sp(a0));
            return PyInt_FromLong((long) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcIJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcJD$sp(t_Function1 *self, PyObject *arg)
    {
        jdouble a0;
        jlong result;

        if (!parseArg(arg, "D", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcJD$sp(a0));
            return PyLong_FromLongLong((PY_LONG_LONG) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcJD$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcJF$sp(t_Function1 *self, PyObject *arg)
    {
        jfloat a0;
        jlong result;

        if (!parseArg(arg, "F", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcJF$sp(a0));
            return PyLong_FromLongLong((PY_LONG_LONG) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcJF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcJI$sp(t_Function1 *self, PyObject *arg)
    {
        jint a0;
        jlong result;

        if (!parseArg(arg, "I", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcJI$sp(a0));
            return PyLong_FromLongLong((PY_LONG_LONG) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcJI$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcJJ$sp(t_Function1 *self, PyObject *arg)
    {
        jlong a0;
        jlong result;

        if (!parseArg(arg, "J", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcJJ$sp(a0));
            return PyLong_FromLongLong((PY_LONG_LONG) result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcJJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcVD$sp(t_Function1 *self, PyObject *arg)
    {
        jdouble a0;

        if (!parseArg(arg, "D", &a0))
        {
            OBJ_CALL(self->object.apply$mcVD$sp(a0));
            Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcVD$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcVF$sp(t_Function1 *self, PyObject *arg)
    {
        jfloat a0;

        if (!parseArg(arg, "F", &a0))
        {
            OBJ_CALL(self->object.apply$mcVF$sp(a0));
            Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcVF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcVI$sp(t_Function1 *self, PyObject *arg)
    {
        jint a0;

        if (!parseArg(arg, "I", &a0))
        {
            OBJ_CALL(self->object.apply$mcVI$sp(a0));
            Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcVI$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcVJ$sp(t_Function1 *self, PyObject *arg)
    {
        jlong a0;

        if (!parseArg(arg, "J", &a0))
        {
            OBJ_CALL(self->object.apply$mcVJ$sp(a0));
            Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcVJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcZD$sp(t_Function1 *self, PyObject *arg)
    {
        jdouble a0;
        jboolean result;

        if (!parseArg(arg, "D", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcZD$sp(a0));
            Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcZD$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcZF$sp(t_Function1 *self, PyObject *arg)
    {
        jfloat a0;
        jboolean result;

        if (!parseArg(arg, "F", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcZF$sp(a0));
            Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcZF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcZI$sp(t_Function1 *self, PyObject *arg)
    {
        jint a0;
        jboolean result;

        if (!parseArg(arg, "I", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcZI$sp(a0));
            Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcZI$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_apply$mcZJ$sp(t_Function1 *self, PyObject *arg)
    {
        jlong a0;
        jboolean result;

        if (!parseArg(arg, "J", &a0))
        {
            OBJ_CALL(result = self->object.apply$mcZJ$sp(a0));
            Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "apply$mcZJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcDD$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcDD$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcDD$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcDF$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcDF$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcDF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcDI$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcDI$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcDI$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcDJ$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcDJ$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcDJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcFD$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcFD$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcFD$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcFF$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcFF$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcFF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcFI$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcFI$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcFI$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcFJ$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcFJ$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcFJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcID$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcID$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcID$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcIF$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcIF$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcIF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcII$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcII$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcII$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcIJ$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcIJ$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcIJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcJD$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcJD$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcJD$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcJF$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcJF$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcJF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcJI$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcJI$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcJI$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcJJ$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcJJ$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcJJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcZD$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcZD$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcZD$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcZF$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcZF$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcZF$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcZI$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcZI$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcZI$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_compose$mcZJ$sp(t_Function1 *self, PyObject *arg)
    {
        Function1 a0((jobject) NULL);
        PyTypeObject **p0;
        Function1 result((jobject) NULL);

        if (!parseArg(arg, "K", Function1::initializeClass, &a0, &p0, t_Function1::parameters_))
        {
            OBJ_CALL(result = self->object.compose$mcZJ$sp(a0));
            return t_Function1::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "compose$mcZJ$sp", arg);
        return NULL;
    }

    static PyObject *t_Function1_toString(t_Function1 *self)
    {
        ::java::lang::String result((jobject) NULL);
        OBJ_CALL(result = self->object.toString());
        return j2p(result);
    }
    static PyObject *t_Function1_get__parameters_(t_Function1 *self, void *data)
    {
        return typeParameters(self->parameters, sizeof(self->parameters));
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *NumberFormatException::class$ = NULL;
        jmethodID *NumberFormatException::mids$ = NULL;

        jclass NumberFormatException::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/NumberFormatException");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        NumberFormatException::NumberFormatException() : ::java::lang::IllegalArgumentException(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        NumberFormatException::NumberFormatException(const ::java::lang::String & a0) : ::java::lang::IllegalArgumentException(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_NumberFormatException_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_NumberFormatException_instance_(PyTypeObject *type, PyObject *arg);
        static int t_NumberFormatException_init_(t_NumberFormatException *self, PyObject *args, PyObject *kwds);

        static PyMethodDef t_NumberFormatException__methods_[] = {
            DECLARE_METHOD(t_NumberFormatException, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_NumberFormatException, instance_, METH_O | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(NumberFormatException, t_NumberFormatException, ::java::lang::IllegalArgumentException, NumberFormatException, t_NumberFormatException_init_, 0, 0, 0, 0, 0);

        void t_NumberFormatException::install(PyObject *module)
        {
            installType(&PY_TYPE(NumberFormatException), module, "NumberFormatException", 0);
        }

        void t_NumberFormatException::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(NumberFormatException).tp_dict, "class_", make_descriptor(NumberFormatException::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(NumberFormatException).tp_dict, "wrapfn_", make_descriptor(t_NumberFormatException::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(NumberFormatException).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_NumberFormatException_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, NumberFormatException::initializeClass, 1)))
                return NULL;
            return t_NumberFormatException::wrap_Object(NumberFormatException(((t_NumberFormatException *) arg)->object.this$));
        }
        static PyObject *t_NumberFormatException_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, NumberFormatException::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_NumberFormatException_init_(t_NumberFormatException *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    NumberFormatException object((jobject) NULL);

                    INT_CALL(object = NumberFormatException());
                    self->object = object;
                    break;
                }
                goto err;
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    NumberFormatException object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = NumberFormatException(a0));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/StringBuilder.h"
#include "java/lang/String.h"
#include "java/lang/Object.h"
#include "java/lang/CharSequence.h"
#include "java/lang/Appendable.h"
#include "java/lang/Class.h"
#include "java/lang/StringBuffer.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *StringBuilder::class$ = NULL;
        jmethodID *StringBuilder::mids$ = NULL;

        jclass StringBuilder::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/StringBuilder");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_init$_39c7bd3c] = env->getMethodID(cls, "<init>", "(I)V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_init$_a8afc64a] = env->getMethodID(cls, "<init>", "(Ljava/lang/CharSequence;)V");
                mids$[mid_append_3c8cf749] = env->getMethodID(cls, "append", "([C)Ljava/lang/StringBuilder;");
                mids$[mid_append_75fd4e14] = env->getMethodID(cls, "append", "(F)Ljava/lang/StringBuilder;");
                mids$[mid_append_1c7ab4ee] = env->getMethodID(cls, "append", "(D)Ljava/lang/StringBuilder;");
                mids$[mid_append_b60c3de1] = env->getMethodID(cls, "append", "(Ljava/lang/Object;)Ljava/lang/StringBuilder;");
                mids$[mid_append_d9a60f20] = env->getMethodID(cls, "append", "(J)Ljava/lang/StringBuilder;");
                mids$[mid_append_0f09fb50] = env->getMethodID(cls, "append", "(Z)Ljava/lang/StringBuilder;");
                mids$[mid_append_e82ae26d] = env->getMethodID(cls, "append", "(C)Ljava/lang/StringBuilder;");
                mids$[mid_append_50083a71] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;)Ljava/lang/StringBuilder;");
                mids$[mid_append_2dfc73db] = env->getMethodID(cls, "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;");
                mids$[mid_append_83777cef] = env->getMethodID(cls, "append", "(I)Ljava/lang/StringBuilder;");
                mids$[mid_append_8358d2a7] = env->getMethodID(cls, "append", "(Ljava/lang/StringBuffer;)Ljava/lang/StringBuilder;");
                mids$[mid_append_24d5875d] = env->getMethodID(cls, "append", "([CII)Ljava/lang/StringBuilder;");
                mids$[mid_append_2bd4722d] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;II)Ljava/lang/StringBuilder;");
                mids$[mid_appendCodePoint_83777cef] = env->getMethodID(cls, "appendCodePoint", "(I)Ljava/lang/StringBuilder;");
                mids$[mid_capacity_54c6a179] = env->getMethodID(cls, "capacity", "()I");
                mids$[mid_charAt_39c7bd29] = env->getMethodID(cls, "charAt", "(I)C");
                mids$[mid_codePointAt_39c7bd23] = env->getMethodID(cls, "codePointAt", "(I)I");
                mids$[mid_codePointBefore_39c7bd23] = env->getMethodID(cls, "codePointBefore", "(I)I");
                mids$[mid_codePointCount_d8d154b9] = env->getMethodID(cls, "codePointCount", "(II)I");
                mids$[mid_delete_719db8f9] = env->getMethodID(cls, "delete", "(II)Ljava/lang/StringBuilder;");
                mids$[mid_deleteCharAt_83777cef] = env->getMethodID(cls, "deleteCharAt", "(I)Ljava/lang/StringBuilder;");
                mids$[mid_ensureCapacity_39c7bd3c] = env->getMethodID(cls, "ensureCapacity", "(I)V");
                mids$[mid_getChars_06518f84] = env->getMethodID(cls, "getChars", "(II[CI)V");
                mids$[mid_indexOf_5fdc3f57] = env->getMethodID(cls, "indexOf", "(Ljava/lang/String;)I");
                mids$[mid_indexOf_6e53ccd9] = env->getMethodID(cls, "indexOf", "(Ljava/lang/String;I)I");
                mids$[mid_insert_a08f263a] = env->getMethodID(cls, "insert", "(IF)Ljava/lang/StringBuilder;");
                mids$[mid_insert_223b06cf] = env->getMethodID(cls, "insert", "(I[C)Ljava/lang/StringBuilder;");
                mids$[mid_insert_012dcedd] = env->getMethodID(cls, "insert", "(ILjava/lang/String;)Ljava/lang/StringBuilder;");
                mids$[mid_insert_719db8f9] = env->getMethodID(cls, "insert", "(II)Ljava/lang/StringBuilder;");
                mids$[mid_insert_16519a10] = env->getMethodID(cls, "insert", "(ID)Ljava/lang/StringBuilder;");
                mids$[mid_insert_de03d343] = env->getMethodID(cls, "insert", "(ILjava/lang/Object;)Ljava/lang/StringBuilder;");
                mids$[mid_insert_f2b36ed3] = env->getMethodID(cls, "insert", "(ILjava/lang/CharSequence;)Ljava/lang/StringBuilder;");
                mids$[mid_insert_094df9d6] = env->getMethodID(cls, "insert", "(IZ)Ljava/lang/StringBuilder;");
                mids$[mid_insert_4ed4b5eb] = env->getMethodID(cls, "insert", "(IC)Ljava/lang/StringBuilder;");
                mids$[mid_insert_af7946e6] = env->getMethodID(cls, "insert", "(IJ)Ljava/lang/StringBuilder;");
                mids$[mid_insert_2824e937] = env->getMethodID(cls, "insert", "(ILjava/lang/CharSequence;II)Ljava/lang/StringBuilder;");
                mids$[mid_insert_d3b5ed83] = env->getMethodID(cls, "insert", "(I[CII)Ljava/lang/StringBuilder;");
                mids$[mid_lastIndexOf_5fdc3f57] = env->getMethodID(cls, "lastIndexOf", "(Ljava/lang/String;)I");
                mids$[mid_lastIndexOf_6e53ccd9] = env->getMethodID(cls, "lastIndexOf", "(Ljava/lang/String;I)I");
                mids$[mid_length_54c6a179] = env->getMethodID(cls, "length", "()I");
                mids$[mid_offsetByCodePoints_d8d154b9] = env->getMethodID(cls, "offsetByCodePoints", "(II)I");
                mids$[mid_replace_3740c5ff] = env->getMethodID(cls, "replace", "(IILjava/lang/String;)Ljava/lang/StringBuilder;");
                mids$[mid_reverse_a1025355] = env->getMethodID(cls, "reverse", "()Ljava/lang/StringBuilder;");
                mids$[mid_setCharAt_83eec158] = env->getMethodID(cls, "setCharAt", "(IC)V");
                mids$[mid_setLength_39c7bd3c] = env->getMethodID(cls, "setLength", "(I)V");
                mids$[mid_subSequence_f88dfd57] = env->getMethodID(cls, "subSequence", "(II)Ljava/lang/CharSequence;");
                mids$[mid_substring_141401b3] = env->getMethodID(cls, "substring", "(I)Ljava/lang/String;");
                mids$[mid_substring_f9118fe5] = env->getMethodID(cls, "substring", "(II)Ljava/lang/String;");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
                mids$[mid_trimToSize_54c6a166] = env->getMethodID(cls, "trimToSize", "()V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        StringBuilder::StringBuilder() : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        StringBuilder::StringBuilder(jint a0) : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_39c7bd3c, a0)) {}

        StringBuilder::StringBuilder(const ::java::lang::String & a0) : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        StringBuilder::StringBuilder(const ::java::lang::CharSequence & a0) : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_a8afc64a, a0.this$)) {}

        StringBuilder StringBuilder::append(const JArray< jchar > & a0) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_3c8cf749], a0.this$));
        }

        StringBuilder StringBuilder::append(jfloat a0) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_75fd4e14], a0));
        }

        StringBuilder StringBuilder::append(jdouble a0) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_1c7ab4ee], a0));
        }

        StringBuilder StringBuilder::append(const ::java::lang::Object & a0) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_b60c3de1], a0.this$));
        }

        StringBuilder StringBuilder::append(jlong a0) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_d9a60f20], a0));
        }

        StringBuilder StringBuilder::append(jboolean a0) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_0f09fb50], a0));
        }

        StringBuilder StringBuilder::append(jchar a0) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_e82ae26d], a0));
        }

        StringBuilder StringBuilder::append(const ::java::lang::CharSequence & a0) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_50083a71], a0.this$));
        }

        StringBuilder StringBuilder::append(const ::java::lang::String & a0) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_2dfc73db], a0.this$));
        }

        StringBuilder StringBuilder::append(jint a0) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_83777cef], a0));
        }

        StringBuilder StringBuilder::append(const ::java::lang::StringBuffer & a0) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_8358d2a7], a0.this$));
        }

        StringBuilder StringBuilder::append(const JArray< jchar > & a0, jint a1, jint a2) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_24d5875d], a0.this$, a1, a2));
        }

        StringBuilder StringBuilder::append(const ::java::lang::CharSequence & a0, jint a1, jint a2) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_2bd4722d], a0.this$, a1, a2));
        }

        StringBuilder StringBuilder::appendCodePoint(jint a0) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_appendCodePoint_83777cef], a0));
        }

        jint StringBuilder::capacity() const
        {
            return env->callIntMethod(this$, mids$[mid_capacity_54c6a179]);
        }

        jchar StringBuilder::charAt(jint a0) const
        {
            return env->callCharMethod(this$, mids$[mid_charAt_39c7bd29], a0);
        }

        jint StringBuilder::codePointAt(jint a0) const
        {
            return env->callIntMethod(this$, mids$[mid_codePointAt_39c7bd23], a0);
        }

        jint StringBuilder::codePointBefore(jint a0) const
        {
            return env->callIntMethod(this$, mids$[mid_codePointBefore_39c7bd23], a0);
        }

        jint StringBuilder::codePointCount(jint a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_codePointCount_d8d154b9], a0, a1);
        }

        StringBuilder StringBuilder::delete$(jint a0, jint a1) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_delete_719db8f9], a0, a1));
        }

        StringBuilder StringBuilder::deleteCharAt(jint a0) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_deleteCharAt_83777cef], a0));
        }

        void StringBuilder::ensureCapacity(jint a0) const
        {
            env->callVoidMethod(this$, mids$[mid_ensureCapacity_39c7bd3c], a0);
        }

        void StringBuilder::getChars(jint a0, jint a1, const JArray< jchar > & a2, jint a3) const
        {
            env->callVoidMethod(this$, mids$[mid_getChars_06518f84], a0, a1, a2.this$, a3);
        }

        jint StringBuilder::indexOf(const ::java::lang::String & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_indexOf_5fdc3f57], a0.this$);
        }

        jint StringBuilder::indexOf(const ::java::lang::String & a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_indexOf_6e53ccd9], a0.this$, a1);
        }

        StringBuilder StringBuilder::insert(jint a0, jfloat a1) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_a08f263a], a0, a1));
        }

        StringBuilder StringBuilder::insert(jint a0, const JArray< jchar > & a1) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_223b06cf], a0, a1.this$));
        }

        StringBuilder StringBuilder::insert(jint a0, const ::java::lang::String & a1) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_012dcedd], a0, a1.this$));
        }

        StringBuilder StringBuilder::insert(jint a0, jint a1) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_719db8f9], a0, a1));
        }

        StringBuilder StringBuilder::insert(jint a0, jdouble a1) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_16519a10], a0, a1));
        }

        StringBuilder StringBuilder::insert(jint a0, const ::java::lang::Object & a1) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_de03d343], a0, a1.this$));
        }

        StringBuilder StringBuilder::insert(jint a0, const ::java::lang::CharSequence & a1) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_f2b36ed3], a0, a1.this$));
        }

        StringBuilder StringBuilder::insert(jint a0, jboolean a1) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_094df9d6], a0, a1));
        }

        StringBuilder StringBuilder::insert(jint a0, jchar a1) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_4ed4b5eb], a0, a1));
        }

        StringBuilder StringBuilder::insert(jint a0, jlong a1) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_af7946e6], a0, a1));
        }

        StringBuilder StringBuilder::insert(jint a0, const ::java::lang::CharSequence & a1, jint a2, jint a3) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_2824e937], a0, a1.this$, a2, a3));
        }

        StringBuilder StringBuilder::insert(jint a0, const JArray< jchar > & a1, jint a2, jint a3) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_d3b5ed83], a0, a1.this$, a2, a3));
        }

        jint StringBuilder::lastIndexOf(const ::java::lang::String & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_lastIndexOf_5fdc3f57], a0.this$);
        }

        jint StringBuilder::lastIndexOf(const ::java::lang::String & a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_lastIndexOf_6e53ccd9], a0.this$, a1);
        }

        jint StringBuilder::length() const
        {
            return env->callIntMethod(this$, mids$[mid_length_54c6a179]);
        }

        jint StringBuilder::offsetByCodePoints(jint a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_offsetByCodePoints_d8d154b9], a0, a1);
        }

        StringBuilder StringBuilder::replace(jint a0, jint a1, const ::java::lang::String & a2) const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_replace_3740c5ff], a0, a1, a2.this$));
        }

        StringBuilder StringBuilder::reverse() const
        {
            return StringBuilder(env->callObjectMethod(this$, mids$[mid_reverse_a1025355]));
        }

        void StringBuilder::setCharAt(jint a0, jchar a1) const
        {
            env->callVoidMethod(this$, mids$[mid_setCharAt_83eec158], a0, a1);
        }

        void StringBuilder::setLength(jint a0) const
        {
            env->callVoidMethod(this$, mids$[mid_setLength_39c7bd3c], a0);
        }

        ::java::lang::CharSequence StringBuilder::subSequence(jint a0, jint a1) const
        {
            return ::java::lang::CharSequence(env->callObjectMethod(this$, mids$[mid_subSequence_f88dfd57], a0, a1));
        }

        ::java::lang::String StringBuilder::substring(jint a0) const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_substring_141401b3], a0));
        }

        ::java::lang::String StringBuilder::substring(jint a0, jint a1) const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_substring_f9118fe5], a0, a1));
        }

        ::java::lang::String StringBuilder::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }

        void StringBuilder::trimToSize() const
        {
            env->callVoidMethod(this$, mids$[mid_trimToSize_54c6a166]);
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_StringBuilder_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_StringBuilder_instance_(PyTypeObject *type, PyObject *arg);
        static int t_StringBuilder_init_(t_StringBuilder *self, PyObject *args, PyObject *kwds);
        static PyObject *t_StringBuilder_append(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_appendCodePoint(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_capacity(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_charAt(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_codePointAt(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_codePointBefore(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_codePointCount(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_delete(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_deleteCharAt(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_ensureCapacity(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_getChars(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_indexOf(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_insert(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_lastIndexOf(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_length(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_offsetByCodePoints(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_replace(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_reverse(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_setCharAt(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_setLength(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_subSequence(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_substring(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_toString(t_StringBuilder *self, PyObject *args);
        static PyObject *t_StringBuilder_trimToSize(t_StringBuilder *self, PyObject *args);

        static PyMethodDef t_StringBuilder__methods_[] = {
            DECLARE_METHOD(t_StringBuilder, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_StringBuilder, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_StringBuilder, append, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, appendCodePoint, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, capacity, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, charAt, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, codePointAt, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, codePointBefore, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, codePointCount, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, delete, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, deleteCharAt, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, ensureCapacity, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, getChars, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, indexOf, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, insert, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, lastIndexOf, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, length, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, offsetByCodePoints, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, replace, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, reverse, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, setCharAt, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, setLength, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, subSequence, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, substring, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, toString, METH_VARARGS),
            DECLARE_METHOD(t_StringBuilder, trimToSize, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(StringBuilder, t_StringBuilder, ::java::lang::AbstractStringBuilder, StringBuilder, t_StringBuilder_init_, 0, 0, 0, 0, 0);

        void t_StringBuilder::install(PyObject *module)
        {
            installType(&PY_TYPE(StringBuilder), module, "StringBuilder", 0);
        }

        void t_StringBuilder::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(StringBuilder).tp_dict, "class_", make_descriptor(StringBuilder::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(StringBuilder).tp_dict, "wrapfn_", make_descriptor(t_StringBuilder::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(StringBuilder).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_StringBuilder_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, StringBuilder::initializeClass, 1)))
                return NULL;
            return t_StringBuilder::wrap_Object(StringBuilder(((t_StringBuilder *) arg)->object.this$));
        }
        static PyObject *t_StringBuilder_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, StringBuilder::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_StringBuilder_init_(t_StringBuilder *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    StringBuilder object((jobject) NULL);

                    INT_CALL(object = StringBuilder());
                    self->object = object;
                    break;
                }
                goto err;
              case 1:
                {
                    jint a0;
                    StringBuilder object((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        INT_CALL(object = StringBuilder(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    StringBuilder object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = StringBuilder(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    StringBuilder object((jobject) NULL);

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
                    {
                        INT_CALL(object = StringBuilder(a0));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_StringBuilder_append(t_StringBuilder *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    JArray< jchar > a0((jobject) NULL);
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "[C", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jfloat a0;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "F", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jdouble a0;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "D", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::Object a0((jobject) NULL);
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jlong a0;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "J", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jboolean a0;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "Z", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jchar a0;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::StringBuffer a0((jobject) NULL);
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "k", ::java::lang::StringBuffer::initializeClass, &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                break;
              case 3:
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "[CII", &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = self->object.append(a0, a1, a2));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = self->object.append(a0, a1, a2));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "append", args, 2);
        }

        static PyObject *t_StringBuilder_appendCodePoint(t_StringBuilder *self, PyObject *args)
        {
            jint a0;
            StringBuilder result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
                OBJ_CALL(result = self->object.appendCodePoint(a0));
                return t_StringBuilder::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "appendCodePoint", args, 2);
        }

        static PyObject *t_StringBuilder_capacity(t_StringBuilder *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.capacity());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "capacity", args, 2);
        }

        static PyObject *t_StringBuilder_charAt(t_StringBuilder *self, PyObject *args)
        {
            jint a0;
            jchar result;

            if (!parseArgs(args, "I", &a0))
            {
                OBJ_CALL(result = self->object.charAt(a0));
                return PyUnicode_FromUnicode((Py_UNICODE *) &result, 1);
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "charAt", args, 2);
        }

        static PyObject *t_StringBuilder_codePointAt(t_StringBuilder *self, PyObject *args)
        {
            jint a0;
            jint result;

            if (!parseArgs(args, "I", &a0))
            {
                OBJ_CALL(result = self->object.codePointAt(a0));
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "codePointAt", args, 2);
        }

        static PyObject *t_StringBuilder_codePointBefore(t_StringBuilder *self, PyObject *args)
        {
            jint a0;
            jint result;

            if (!parseArgs(args, "I", &a0))
            {
                OBJ_CALL(result = self->object.codePointBefore(a0));
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "codePointBefore", args, 2);
        }

        static PyObject *t_StringBuilder_codePointCount(t_StringBuilder *self, PyObject *args)
        {
            jint a0;
            jint a1;
            jint result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.codePointCount(a0, a1));
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "codePointCount", args, 2);
        }

        static PyObject *t_StringBuilder_delete(t_StringBuilder *self, PyObject *args)
        {
            jint a0;
            jint a1;
            StringBuilder result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.delete$(a0, a1));
                return t_StringBuilder::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "delete", args, 2);
        }

        static PyObject *t_StringBuilder_deleteCharAt(t_StringBuilder *self, PyObject *args)
        {
            jint a0;
            StringBuilder result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
                OBJ_CALL(result = self->object.deleteCharAt(a0));
                return t_StringBuilder::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "deleteCharAt", args, 2);
        }

        static PyObject *t_StringBuilder_ensureCapacity(t_StringBuilder *self, PyObject *args)
        {
            jint a0;

            if (!parseArgs(args, "I", &a0))
            {
                OBJ_CALL(self->object.ensureCapacity(a0));
                Py_RETURN_NONE;
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "ensureCapacity", args, 2);
        }

        static PyObject *t_StringBuilder_getChars(t_StringBuilder *self, PyObject *args)
        {
            jint a0;
            jint a1;
            JArray< jchar > a2((jobject) NULL);
            jint a3;

            if (!parseArgs(args, "II[CI", &a0, &a1, &a2, &a3))
            {
                OBJ_CALL(self->object.getChars(a0, a1, a2, a3));
                Py_RETURN_NONE;
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "getChars", args, 2);
        }

        static PyObject *t_StringBuilder_indexOf(t_StringBuilder *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.indexOf(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.indexOf(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "indexOf", args, 2);
        }

        static PyObject *t_StringBuilder_insert(t_StringBuilder *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 2:
                {
                    jint a0;
                    jfloat a1;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "IF", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    JArray< jchar > a1((jobject) NULL);
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "I[C", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    ::java::lang::String a1((jobject) NULL);
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "Is", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jint a1;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "II", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jdouble a1;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "ID", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    ::java::lang::Object a1((jobject) NULL);
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "Io", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    ::java::lang::CharSequence a1((jobject) NULL);
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "IO", &::java::lang::PY_TYPE(CharSequence), &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jboolean a1;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "IZ", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jchar a1;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "IC", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jlong a1;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "IJ", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                break;
              case 4:
                {
                    jint a0;
                    ::java::lang::CharSequence a1((jobject) NULL);
                    jint a2;
                    jint a3;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "IOII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2, &a3))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1, a2, a3));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    JArray< jchar > a1((jobject) NULL);
                    jint a2;
                    jint a3;
                    StringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "I[CII", &a0, &a1, &a2, &a3))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1, a2, a3));
                        return t_StringBuilder::wrap_Object(result);
                    }
                }
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "insert", args, 2);
        }

        static PyObject *t_StringBuilder_lastIndexOf(t_StringBuilder *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.lastIndexOf(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.lastIndexOf(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "lastIndexOf", args, 2);
        }

        static PyObject *t_StringBuilder_length(t_StringBuilder *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.length());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "length", args, 2);
        }

        static PyObject *t_StringBuilder_offsetByCodePoints(t_StringBuilder *self, PyObject *args)
        {
            jint a0;
            jint a1;
            jint result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.offsetByCodePoints(a0, a1));
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "offsetByCodePoints", args, 2);
        }

        static PyObject *t_StringBuilder_replace(t_StringBuilder *self, PyObject *args)
        {
            jint a0;
            jint a1;
            ::java::lang::String a2((jobject) NULL);
            StringBuilder result((jobject) NULL);

            if (!parseArgs(args, "IIs", &a0, &a1, &a2))
            {
                OBJ_CALL(result = self->object.replace(a0, a1, a2));
                return t_StringBuilder::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "replace", args, 2);
        }

        static PyObject *t_StringBuilder_reverse(t_StringBuilder *self, PyObject *args)
        {
            StringBuilder result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.reverse());
                return t_StringBuilder::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "reverse", args, 2);
        }

        static PyObject *t_StringBuilder_setCharAt(t_StringBuilder *self, PyObject *args)
        {
            jint a0;
            jchar a1;

            if (!parseArgs(args, "IC", &a0, &a1))
            {
                OBJ_CALL(self->object.setCharAt(a0, a1));
                Py_RETURN_NONE;
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "setCharAt", args, 2);
        }

        static PyObject *t_StringBuilder_setLength(t_StringBuilder *self, PyObject *args)
        {
            jint a0;

            if (!parseArgs(args, "I", &a0))
            {
                OBJ_CALL(self->object.setLength(a0));
                Py_RETURN_NONE;
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "setLength", args, 2);
        }

        static PyObject *t_StringBuilder_subSequence(t_StringBuilder *self, PyObject *args)
        {
            jint a0;
            jint a1;
            ::java::lang::CharSequence result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.subSequence(a0, a1));
                return ::java::lang::t_CharSequence::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "subSequence", args, 2);
        }

        static PyObject *t_StringBuilder_substring(t_StringBuilder *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    ::java::lang::String result((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = self->object.substring(a0));
                        return j2p(result);
                    }
                }
                break;
              case 2:
                {
                    jint a0;
                    jint a1;
                    ::java::lang::String result((jobject) NULL);

                    if (!parseArgs(args, "II", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.substring(a0, a1));
                        return j2p(result);
                    }
                }
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "substring", args, 2);
        }

        static PyObject *t_StringBuilder_toString(t_StringBuilder *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_StringBuilder_trimToSize(t_StringBuilder *self, PyObject *args)
        {

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(self->object.trimToSize());
                Py_RETURN_NONE;
            }

            return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "trimToSize", args, 2);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Comparable.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *Comparable::class$ = NULL;
        jmethodID *Comparable::mids$ = NULL;

        jclass Comparable::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/Comparable");

                mids$ = new jmethodID[max_mid];
                mids$[mid_compareTo_290588f1] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Object;)I");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        jint Comparable::compareTo(const ::java::lang::Object & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_compareTo_290588f1], a0.this$);
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_Comparable_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Comparable_instance_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_Comparable_of_(t_Comparable *self, PyObject *args);
        static PyObject *t_Comparable_compareTo(t_Comparable *self, PyObject *arg);
        static PyObject *t_Comparable_get__parameters_(t_Comparable *self, void *data);
        static PyGetSetDef t_Comparable__fields_[] = {
            DECLARE_GET_FIELD(t_Comparable, parameters_),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_Comparable__methods_[] = {
            DECLARE_METHOD(t_Comparable, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Comparable, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_Comparable, of_, METH_VARARGS),
            DECLARE_METHOD(t_Comparable, compareTo, METH_O),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Comparable, t_Comparable, ::java::lang::Object, Comparable, abstract_init, 0, 0, t_Comparable__fields_, 0, 0);
        PyObject *t_Comparable::wrap_Object(const Comparable& object, PyTypeObject *T)
        {
            PyObject *obj = t_Comparable::wrap_Object(object);
            if (obj != NULL && obj != Py_None)
            {
                t_Comparable *self = (t_Comparable *) obj;
                self->parameters[0] = T;
            }
            return obj;
        }

        PyObject *t_Comparable::wrap_jobject(const jobject& object, PyTypeObject *T)
        {
            PyObject *obj = t_Comparable::wrap_jobject(object);
            if (obj != NULL && obj != Py_None)
            {
                t_Comparable *self = (t_Comparable *) obj;
                self->parameters[0] = T;
            }
            return obj;
        }

        void t_Comparable::install(PyObject *module)
        {
            installType(&PY_TYPE(Comparable), module, "Comparable", 0);
        }

        void t_Comparable::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(Comparable).tp_dict, "class_", make_descriptor(Comparable::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(Comparable).tp_dict, "wrapfn_", make_descriptor(t_Comparable::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(Comparable).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_Comparable_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, Comparable::initializeClass, 1)))
                return NULL;
            return t_Comparable::wrap_Object(Comparable(((t_Comparable *) arg)->object.this$));
        }
        static PyObject *t_Comparable_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, Comparable::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static PyObject *t_Comparable_of_(t_Comparable *self, PyObject *args)
        {
            if (!parseArg(args, "T", 1, &(self->parameters)))
                Py_RETURN_SELF;
            return PyErr_SetArgsError((PyObject *) self, "of_", args);
        }

        static PyObject *t_Comparable_compareTo(t_Comparable *self, PyObject *arg)
        {
            ::java::lang::Object a0((jobject) NULL);
            jint result;

            if (!parseArg(arg, "O", self->parameters[0], &a0))
            {
                OBJ_CALL(result = self->object.compareTo(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError((PyObject *) self, "compareTo", arg);
            return NULL;
        }
        static PyObject *t_Comparable_get__parameters_(t_Comparable *self, void *data)
        {
            return typeParameters(self->parameters, sizeof(self->parameters));
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/InterruptedException.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *InterruptedException::class$ = NULL;
        jmethodID *InterruptedException::mids$ = NULL;

        jclass InterruptedException::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/InterruptedException");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        InterruptedException::InterruptedException() : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        InterruptedException::InterruptedException(const ::java::lang::String & a0) : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_InterruptedException_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_InterruptedException_instance_(PyTypeObject *type, PyObject *arg);
        static int t_InterruptedException_init_(t_InterruptedException *self, PyObject *args, PyObject *kwds);

        static PyMethodDef t_InterruptedException__methods_[] = {
            DECLARE_METHOD(t_InterruptedException, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_InterruptedException, instance_, METH_O | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(InterruptedException, t_InterruptedException, ::java::lang::Exception, InterruptedException, t_InterruptedException_init_, 0, 0, 0, 0, 0);

        void t_InterruptedException::install(PyObject *module)
        {
            installType(&PY_TYPE(InterruptedException), module, "InterruptedException", 0);
        }

        void t_InterruptedException::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(InterruptedException).tp_dict, "class_", make_descriptor(InterruptedException::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(InterruptedException).tp_dict, "wrapfn_", make_descriptor(t_InterruptedException::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(InterruptedException).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_InterruptedException_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, InterruptedException::initializeClass, 1)))
                return NULL;
            return t_InterruptedException::wrap_Object(InterruptedException(((t_InterruptedException *) arg)->object.this$));
        }
        static PyObject *t_InterruptedException_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, InterruptedException::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_InterruptedException_init_(t_InterruptedException *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    InterruptedException object((jobject) NULL);

                    INT_CALL(object = InterruptedException());
                    self->object = object;
                    break;
                }
                goto err;
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    InterruptedException object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = InterruptedException(a0));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/StringBuffer.h"
#include "java/lang/String.h"
#include "java/lang/Object.h"
#include "java/lang/CharSequence.h"
#include "java/lang/Appendable.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *StringBuffer::class$ = NULL;
        jmethodID *StringBuffer::mids$ = NULL;

        jclass StringBuffer::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/StringBuffer");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_init$_39c7bd3c] = env->getMethodID(cls, "<init>", "(I)V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_init$_a8afc64a] = env->getMethodID(cls, "<init>", "(Ljava/lang/CharSequence;)V");
                mids$[mid_append_35d2e845] = env->getMethodID(cls, "append", "([C)Ljava/lang/StringBuffer;");
                mids$[mid_append_251e110e] = env->getMethodID(cls, "append", "(F)Ljava/lang/StringBuffer;");
                mids$[mid_append_24b69bf0] = env->getMethodID(cls, "append", "(D)Ljava/lang/StringBuffer;");
                mids$[mid_append_67ad01ed] = env->getMethodID(cls, "append", "(Ljava/lang/Object;)Ljava/lang/StringBuffer;");
                mids$[mid_append_662d52ca] = env->getMethodID(cls, "append", "(J)Ljava/lang/StringBuffer;");
                mids$[mid_append_bb3a365a] = env->getMethodID(cls, "append", "(Z)Ljava/lang/StringBuffer;");
                mids$[mid_append_4ca72be1] = env->getMethodID(cls, "append", "(C)Ljava/lang/StringBuffer;");
                mids$[mid_append_6b1920e9] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;)Ljava/lang/StringBuffer;");
                mids$[mid_append_2979b2bb] = env->getMethodID(cls, "append", "(Ljava/lang/String;)Ljava/lang/StringBuffer;");
                mids$[mid_append_fdff3523] = env->getMethodID(cls, "append", "(I)Ljava/lang/StringBuffer;");
                mids$[mid_append_a876a4ab] = env->getMethodID(cls, "append", "(Ljava/lang/StringBuffer;)Ljava/lang/StringBuffer;");
                mids$[mid_append_aa3a4fc5] = env->getMethodID(cls, "append", "([CII)Ljava/lang/StringBuffer;");
                mids$[mid_append_f3c776b1] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;II)Ljava/lang/StringBuffer;");
                mids$[mid_appendCodePoint_fdff3523] = env->getMethodID(cls, "appendCodePoint", "(I)Ljava/lang/StringBuffer;");
                mids$[mid_capacity_54c6a179] = env->getMethodID(cls, "capacity", "()I");
                mids$[mid_charAt_39c7bd29] = env->getMethodID(cls, "charAt", "(I)C");
                mids$[mid_codePointAt_39c7bd23] = env->getMethodID(cls, "codePointAt", "(I)I");
                mids$[mid_codePointBefore_39c7bd23] = env->getMethodID(cls, "codePointBefore", "(I)I");
                mids$[mid_codePointCount_d8d154b9] = env->getMethodID(cls, "codePointCount", "(II)I");
                mids$[mid_delete_644727d5] = env->getMethodID(cls, "delete", "(II)Ljava/lang/StringBuffer;");
                mids$[mid_deleteCharAt_fdff3523] = env->getMethodID(cls, "deleteCharAt", "(I)Ljava/lang/StringBuffer;");
                mids$[mid_ensureCapacity_39c7bd3c] = env->getMethodID(cls, "ensureCapacity", "(I)V");
                mids$[mid_getChars_06518f84] = env->getMethodID(cls, "getChars", "(II[CI)V");
                mids$[mid_indexOf_5fdc3f57] = env->getMethodID(cls, "indexOf", "(Ljava/lang/String;)I");
                mids$[mid_indexOf_6e53ccd9] = env->getMethodID(cls, "indexOf", "(Ljava/lang/String;I)I");
                mids$[mid_insert_d95ec358] = env->getMethodID(cls, "insert", "(IF)Ljava/lang/StringBuffer;");
                mids$[mid_insert_bc0ebac7] = env->getMethodID(cls, "insert", "(I[C)Ljava/lang/StringBuffer;");
                mids$[mid_insert_88877b15] = env->getMethodID(cls, "insert", "(ILjava/lang/String;)Ljava/lang/StringBuffer;");
                mids$[mid_insert_644727d5] = env->getMethodID(cls, "insert", "(II)Ljava/lang/StringBuffer;");
                mids$[mid_insert_b71b2a52] = env->getMethodID(cls, "insert", "(ID)Ljava/lang/StringBuffer;");
                mids$[mid_insert_2e164a03] = env->getMethodID(cls, "insert", "(ILjava/lang/Object;)Ljava/lang/StringBuffer;");
                mids$[mid_insert_ed5f9c37] = env->getMethodID(cls, "insert", "(ILjava/lang/CharSequence;)Ljava/lang/StringBuffer;");
                mids$[mid_insert_3c3656bc] = env->getMethodID(cls, "insert", "(IZ)Ljava/lang/StringBuffer;");
                mids$[mid_insert_3d91488b] = env->getMethodID(cls, "insert", "(IC)Ljava/lang/StringBuffer;");
                mids$[mid_insert_5e363fec] = env->getMethodID(cls, "insert", "(IJ)Ljava/lang/StringBuffer;");
                mids$[mid_insert_732cbadf] = env->getMethodID(cls, "insert", "(ILjava/lang/CharSequence;II)Ljava/lang/StringBuffer;");
                mids$[mid_insert_6edd3397] = env->getMethodID(cls, "insert", "(I[CII)Ljava/lang/StringBuffer;");
                mids$[mid_lastIndexOf_5fdc3f57] = env->getMethodID(cls, "lastIndexOf", "(Ljava/lang/String;)I");
                mids$[mid_lastIndexOf_6e53ccd9] = env->getMethodID(cls, "lastIndexOf", "(Ljava/lang/String;I)I");
                mids$[mid_length_54c6a179] = env->getMethodID(cls, "length", "()I");
                mids$[mid_offsetByCodePoints_d8d154b9] = env->getMethodID(cls, "offsetByCodePoints", "(II)I");
                mids$[mid_replace_95b69603] = env->getMethodID(cls, "replace", "(IILjava/lang/String;)Ljava/lang/StringBuffer;");
                mids$[mid_reverse_d54172a5] = env->getMethodID(cls, "reverse", "()Ljava/lang/StringBuffer;");
                mids$[mid_setCharAt_83eec158] = env->getMethodID(cls, "setCharAt", "(IC)V");
                mids$[mid_setLength_39c7bd3c] = env->getMethodID(cls, "setLength", "(I)V");
                mids$[mid_subSequence_f88dfd57] = env->getMethodID(cls, "subSequence", "(II)Ljava/lang/CharSequence;");
                mids$[mid_substring_141401b3] = env->getMethodID(cls, "substring", "(I)Ljava/lang/String;");
                mids$[mid_substring_f9118fe5] = env->getMethodID(cls, "substring", "(II)Ljava/lang/String;");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
                mids$[mid_trimToSize_54c6a166] = env->getMethodID(cls, "trimToSize", "()V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        StringBuffer::StringBuffer() : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        StringBuffer::StringBuffer(jint a0) : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_39c7bd3c, a0)) {}

        StringBuffer::StringBuffer(const ::java::lang::String & a0) : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        StringBuffer::StringBuffer(const ::java::lang::CharSequence & a0) : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_a8afc64a, a0.this$)) {}

        StringBuffer StringBuffer::append(const JArray< jchar > & a0) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_35d2e845], a0.this$));
        }

        StringBuffer StringBuffer::append(jfloat a0) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_251e110e], a0));
        }

        StringBuffer StringBuffer::append(jdouble a0) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_24b69bf0], a0));
        }

        StringBuffer StringBuffer::append(const ::java::lang::Object & a0) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_67ad01ed], a0.this$));
        }

        StringBuffer StringBuffer::append(jlong a0) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_662d52ca], a0));
        }

        StringBuffer StringBuffer::append(jboolean a0) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_bb3a365a], a0));
        }

        StringBuffer StringBuffer::append(jchar a0) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_4ca72be1], a0));
        }

        StringBuffer StringBuffer::append(const ::java::lang::CharSequence & a0) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_6b1920e9], a0.this$));
        }

        StringBuffer StringBuffer::append(const ::java::lang::String & a0) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_2979b2bb], a0.this$));
        }

        StringBuffer StringBuffer::append(jint a0) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_fdff3523], a0));
        }

        StringBuffer StringBuffer::append(const StringBuffer & a0) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_a876a4ab], a0.this$));
        }

        StringBuffer StringBuffer::append(const JArray< jchar > & a0, jint a1, jint a2) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_aa3a4fc5], a0.this$, a1, a2));
        }

        StringBuffer StringBuffer::append(const ::java::lang::CharSequence & a0, jint a1, jint a2) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_f3c776b1], a0.this$, a1, a2));
        }

        StringBuffer StringBuffer::appendCodePoint(jint a0) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_appendCodePoint_fdff3523], a0));
        }

        jint StringBuffer::capacity() const
        {
            return env->callIntMethod(this$, mids$[mid_capacity_54c6a179]);
        }

        jchar StringBuffer::charAt(jint a0) const
        {
            return env->callCharMethod(this$, mids$[mid_charAt_39c7bd29], a0);
        }

        jint StringBuffer::codePointAt(jint a0) const
        {
            return env->callIntMethod(this$, mids$[mid_codePointAt_39c7bd23], a0);
        }

        jint StringBuffer::codePointBefore(jint a0) const
        {
            return env->callIntMethod(this$, mids$[mid_codePointBefore_39c7bd23], a0);
        }

        jint StringBuffer::codePointCount(jint a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_codePointCount_d8d154b9], a0, a1);
        }

        StringBuffer StringBuffer::delete$(jint a0, jint a1) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_delete_644727d5], a0, a1));
        }

        StringBuffer StringBuffer::deleteCharAt(jint a0) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_deleteCharAt_fdff3523], a0));
        }

        void StringBuffer::ensureCapacity(jint a0) const
        {
            env->callVoidMethod(this$, mids$[mid_ensureCapacity_39c7bd3c], a0);
        }

        void StringBuffer::getChars(jint a0, jint a1, const JArray< jchar > & a2, jint a3) const
        {
            env->callVoidMethod(this$, mids$[mid_getChars_06518f84], a0, a1, a2.this$, a3);
        }

        jint StringBuffer::indexOf(const ::java::lang::String & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_indexOf_5fdc3f57], a0.this$);
        }

        jint StringBuffer::indexOf(const ::java::lang::String & a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_indexOf_6e53ccd9], a0.this$, a1);
        }

        StringBuffer StringBuffer::insert(jint a0, jfloat a1) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_d95ec358], a0, a1));
        }

        StringBuffer StringBuffer::insert(jint a0, const JArray< jchar > & a1) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_bc0ebac7], a0, a1.this$));
        }

        StringBuffer StringBuffer::insert(jint a0, const ::java::lang::String & a1) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_88877b15], a0, a1.this$));
        }

        StringBuffer StringBuffer::insert(jint a0, jint a1) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_644727d5], a0, a1));
        }

        StringBuffer StringBuffer::insert(jint a0, jdouble a1) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_b71b2a52], a0, a1));
        }

        StringBuffer StringBuffer::insert(jint a0, const ::java::lang::Object & a1) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_2e164a03], a0, a1.this$));
        }

        StringBuffer StringBuffer::insert(jint a0, const ::java::lang::CharSequence & a1) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_ed5f9c37], a0, a1.this$));
        }

        StringBuffer StringBuffer::insert(jint a0, jboolean a1) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_3c3656bc], a0, a1));
        }

        StringBuffer StringBuffer::insert(jint a0, jchar a1) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_3d91488b], a0, a1));
        }

        StringBuffer StringBuffer::insert(jint a0, jlong a1) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_5e363fec], a0, a1));
        }

        StringBuffer StringBuffer::insert(jint a0, const ::java::lang::CharSequence & a1, jint a2, jint a3) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_732cbadf], a0, a1.this$, a2, a3));
        }

        StringBuffer StringBuffer::insert(jint a0, const JArray< jchar > & a1, jint a2, jint a3) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_6edd3397], a0, a1.this$, a2, a3));
        }

        jint StringBuffer::lastIndexOf(const ::java::lang::String & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_lastIndexOf_5fdc3f57], a0.this$);
        }

        jint StringBuffer::lastIndexOf(const ::java::lang::String & a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_lastIndexOf_6e53ccd9], a0.this$, a1);
        }

        jint StringBuffer::length() const
        {
            return env->callIntMethod(this$, mids$[mid_length_54c6a179]);
        }

        jint StringBuffer::offsetByCodePoints(jint a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_offsetByCodePoints_d8d154b9], a0, a1);
        }

        StringBuffer StringBuffer::replace(jint a0, jint a1, const ::java::lang::String & a2) const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_replace_95b69603], a0, a1, a2.this$));
        }

        StringBuffer StringBuffer::reverse() const
        {
            return StringBuffer(env->callObjectMethod(this$, mids$[mid_reverse_d54172a5]));
        }

        void StringBuffer::setCharAt(jint a0, jchar a1) const
        {
            env->callVoidMethod(this$, mids$[mid_setCharAt_83eec158], a0, a1);
        }

        void StringBuffer::setLength(jint a0) const
        {
            env->callVoidMethod(this$, mids$[mid_setLength_39c7bd3c], a0);
        }

        ::java::lang::CharSequence StringBuffer::subSequence(jint a0, jint a1) const
        {
            return ::java::lang::CharSequence(env->callObjectMethod(this$, mids$[mid_subSequence_f88dfd57], a0, a1));
        }

        ::java::lang::String StringBuffer::substring(jint a0) const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_substring_141401b3], a0));
        }

        ::java::lang::String StringBuffer::substring(jint a0, jint a1) const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_substring_f9118fe5], a0, a1));
        }

        ::java::lang::String StringBuffer::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }

        void StringBuffer::trimToSize() const
        {
            env->callVoidMethod(this$, mids$[mid_trimToSize_54c6a166]);
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_StringBuffer_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_StringBuffer_instance_(PyTypeObject *type, PyObject *arg);
        static int t_StringBuffer_init_(t_StringBuffer *self, PyObject *args, PyObject *kwds);
        static PyObject *t_StringBuffer_append(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_appendCodePoint(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_capacity(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_charAt(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_codePointAt(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_codePointBefore(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_codePointCount(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_delete(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_deleteCharAt(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_ensureCapacity(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_getChars(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_indexOf(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_insert(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_lastIndexOf(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_length(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_offsetByCodePoints(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_replace(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_reverse(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_setCharAt(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_setLength(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_subSequence(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_substring(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_toString(t_StringBuffer *self, PyObject *args);
        static PyObject *t_StringBuffer_trimToSize(t_StringBuffer *self, PyObject *args);

        static PyMethodDef t_StringBuffer__methods_[] = {
            DECLARE_METHOD(t_StringBuffer, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_StringBuffer, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_StringBuffer, append, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, appendCodePoint, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, capacity, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, charAt, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, codePointAt, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, codePointBefore, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, codePointCount, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, delete, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, deleteCharAt, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, ensureCapacity, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, getChars, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, indexOf, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, insert, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, lastIndexOf, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, length, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, offsetByCodePoints, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, replace, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, reverse, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, setCharAt, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, setLength, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, subSequence, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, substring, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, toString, METH_VARARGS),
            DECLARE_METHOD(t_StringBuffer, trimToSize, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(StringBuffer, t_StringBuffer, ::java::lang::AbstractStringBuilder, StringBuffer, t_StringBuffer_init_, 0, 0, 0, 0, 0);

        void t_StringBuffer::install(PyObject *module)
        {
            installType(&PY_TYPE(StringBuffer), module, "StringBuffer", 0);
        }

        void t_StringBuffer::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(StringBuffer).tp_dict, "class_", make_descriptor(StringBuffer::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(StringBuffer).tp_dict, "wrapfn_", make_descriptor(t_StringBuffer::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(StringBuffer).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_StringBuffer_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, StringBuffer::initializeClass, 1)))
                return NULL;
            return t_StringBuffer::wrap_Object(StringBuffer(((t_StringBuffer *) arg)->object.this$));
        }
        static PyObject *t_StringBuffer_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, StringBuffer::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_StringBuffer_init_(t_StringBuffer *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    StringBuffer object((jobject) NULL);

                    INT_CALL(object = StringBuffer());
                    self->object = object;
                    break;
                }
                goto err;
              case 1:
                {
                    jint a0;
                    StringBuffer object((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        INT_CALL(object = StringBuffer(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    StringBuffer object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = StringBuffer(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    StringBuffer object((jobject) NULL);

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
                    {
                        INT_CALL(object = StringBuffer(a0));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_StringBuffer_append(t_StringBuffer *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    JArray< jchar > a0((jobject) NULL);
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "[C", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jfloat a0;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "F", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jdouble a0;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "D", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::Object a0((jobject) NULL);
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jlong a0;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "J", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jboolean a0;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "Z", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jchar a0;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    StringBuffer a0((jobject) NULL);
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "k", StringBuffer::initializeClass, &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                break;
              case 3:
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "[CII", &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = self->object.append(a0, a1, a2));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = self->object.append(a0, a1, a2));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "append", args, 2);
        }

        static PyObject *t_StringBuffer_appendCodePoint(t_StringBuffer *self, PyObject *args)
        {
            jint a0;
            StringBuffer result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
                OBJ_CALL(result = self->object.appendCodePoint(a0));
                return t_StringBuffer::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "appendCodePoint", args, 2);
        }

        static PyObject *t_StringBuffer_capacity(t_StringBuffer *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.capacity());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "capacity", args, 2);
        }

        static PyObject *t_StringBuffer_charAt(t_StringBuffer *self, PyObject *args)
        {
            jint a0;
            jchar result;

            if (!parseArgs(args, "I", &a0))
            {
                OBJ_CALL(result = self->object.charAt(a0));
                return PyUnicode_FromUnicode((Py_UNICODE *) &result, 1);
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "charAt", args, 2);
        }

        static PyObject *t_StringBuffer_codePointAt(t_StringBuffer *self, PyObject *args)
        {
            jint a0;
            jint result;

            if (!parseArgs(args, "I", &a0))
            {
                OBJ_CALL(result = self->object.codePointAt(a0));
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "codePointAt", args, 2);
        }

        static PyObject *t_StringBuffer_codePointBefore(t_StringBuffer *self, PyObject *args)
        {
            jint a0;
            jint result;

            if (!parseArgs(args, "I", &a0))
            {
                OBJ_CALL(result = self->object.codePointBefore(a0));
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "codePointBefore", args, 2);
        }

        static PyObject *t_StringBuffer_codePointCount(t_StringBuffer *self, PyObject *args)
        {
            jint a0;
            jint a1;
            jint result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.codePointCount(a0, a1));
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "codePointCount", args, 2);
        }

        static PyObject *t_StringBuffer_delete(t_StringBuffer *self, PyObject *args)
        {
            jint a0;
            jint a1;
            StringBuffer result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.delete$(a0, a1));
                return t_StringBuffer::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "delete", args, 2);
        }

        static PyObject *t_StringBuffer_deleteCharAt(t_StringBuffer *self, PyObject *args)
        {
            jint a0;
            StringBuffer result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
                OBJ_CALL(result = self->object.deleteCharAt(a0));
                return t_StringBuffer::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "deleteCharAt", args, 2);
        }

        static PyObject *t_StringBuffer_ensureCapacity(t_StringBuffer *self, PyObject *args)
        {
            jint a0;

            if (!parseArgs(args, "I", &a0))
            {
                OBJ_CALL(self->object.ensureCapacity(a0));
                Py_RETURN_NONE;
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "ensureCapacity", args, 2);
        }

        static PyObject *t_StringBuffer_getChars(t_StringBuffer *self, PyObject *args)
        {
            jint a0;
            jint a1;
            JArray< jchar > a2((jobject) NULL);
            jint a3;

            if (!parseArgs(args, "II[CI", &a0, &a1, &a2, &a3))
            {
                OBJ_CALL(self->object.getChars(a0, a1, a2, a3));
                Py_RETURN_NONE;
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "getChars", args, 2);
        }

        static PyObject *t_StringBuffer_indexOf(t_StringBuffer *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.indexOf(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.indexOf(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "indexOf", args, 2);
        }

        static PyObject *t_StringBuffer_insert(t_StringBuffer *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 2:
                {
                    jint a0;
                    jfloat a1;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "IF", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    JArray< jchar > a1((jobject) NULL);
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "I[C", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    ::java::lang::String a1((jobject) NULL);
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "Is", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jint a1;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "II", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jdouble a1;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "ID", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    ::java::lang::Object a1((jobject) NULL);
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "Io", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    ::java::lang::CharSequence a1((jobject) NULL);
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "IO", &::java::lang::PY_TYPE(CharSequence), &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jboolean a1;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "IZ", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jchar a1;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "IC", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jlong a1;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "IJ", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                break;
              case 4:
                {
                    jint a0;
                    ::java::lang::CharSequence a1((jobject) NULL);
                    jint a2;
                    jint a3;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "IOII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2, &a3))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1, a2, a3));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    JArray< jchar > a1((jobject) NULL);
                    jint a2;
                    jint a3;
                    StringBuffer result((jobject) NULL);

                    if (!parseArgs(args, "I[CII", &a0, &a1, &a2, &a3))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1, a2, a3));
                        return t_StringBuffer::wrap_Object(result);
                    }
                }
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "insert", args, 2);
        }

        static PyObject *t_StringBuffer_lastIndexOf(t_StringBuffer *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.lastIndexOf(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.lastIndexOf(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "lastIndexOf", args, 2);
        }

        static PyObject *t_StringBuffer_length(t_StringBuffer *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.length());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "length", args, 2);
        }

        static PyObject *t_StringBuffer_offsetByCodePoints(t_StringBuffer *self, PyObject *args)
        {
            jint a0;
            jint a1;
            jint result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.offsetByCodePoints(a0, a1));
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "offsetByCodePoints", args, 2);
        }

        static PyObject *t_StringBuffer_replace(t_StringBuffer *self, PyObject *args)
        {
            jint a0;
            jint a1;
            ::java::lang::String a2((jobject) NULL);
            StringBuffer result((jobject) NULL);

            if (!parseArgs(args, "IIs", &a0, &a1, &a2))
            {
                OBJ_CALL(result = self->object.replace(a0, a1, a2));
                return t_StringBuffer::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "replace", args, 2);
        }

        static PyObject *t_StringBuffer_reverse(t_StringBuffer *self, PyObject *args)
        {
            StringBuffer result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.reverse());
                return t_StringBuffer::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "reverse", args, 2);
        }

        static PyObject *t_StringBuffer_setCharAt(t_StringBuffer *self, PyObject *args)
        {
            jint a0;
            jchar a1;

            if (!parseArgs(args, "IC", &a0, &a1))
            {
                OBJ_CALL(self->object.setCharAt(a0, a1));
                Py_RETURN_NONE;
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "setCharAt", args, 2);
        }

        static PyObject *t_StringBuffer_setLength(t_StringBuffer *self, PyObject *args)
        {
            jint a0;

            if (!parseArgs(args, "I", &a0))
            {
                OBJ_CALL(self->object.setLength(a0));
                Py_RETURN_NONE;
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "setLength", args, 2);
        }

        static PyObject *t_StringBuffer_subSequence(t_StringBuffer *self, PyObject *args)
        {
            jint a0;
            jint a1;
            ::java::lang::CharSequence result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.subSequence(a0, a1));
                return ::java::lang::t_CharSequence::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "subSequence", args, 2);
        }

        static PyObject *t_StringBuffer_substring(t_StringBuffer *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    ::java::lang::String result((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = self->object.substring(a0));
                        return j2p(result);
                    }
                }
                break;
              case 2:
                {
                    jint a0;
                    jint a1;
                    ::java::lang::String result((jobject) NULL);

                    if (!parseArgs(args, "II", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.substring(a0, a1));
                        return j2p(result);
                    }
                }
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "substring", args, 2);
        }

        static PyObject *t_StringBuffer_toString(t_StringBuffer *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_StringBuffer_trimToSize(t_StringBuffer *self, PyObject *args)
        {

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(self->object.trimToSize());
                Py_RETURN_NONE;
            }

            return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "trimToSize", args, 2);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/IllegalArgumentException.h"
#include "java/lang/Throwable.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *IllegalArgumentException::class$ = NULL;
        jmethodID *IllegalArgumentException::mids$ = NULL;

        jclass IllegalArgumentException::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/IllegalArgumentException");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_init$_c5ec8ca4] = env->getMethodID(cls, "<init>", "(Ljava/lang/Throwable;)V");
                mids$[mid_init$_01646a2e] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        IllegalArgumentException::IllegalArgumentException() : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        IllegalArgumentException::IllegalArgumentException(const ::java::lang::String & a0) : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        IllegalArgumentException::IllegalArgumentException(const ::java::lang::Throwable & a0) : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_c5ec8ca4, a0.this$)) {}

        IllegalArgumentException::IllegalArgumentException(const ::java::lang::String & a0, const ::java::lang::Throwable & a1) : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_01646a2e, a0.this$, a1.this$)) {}
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_IllegalArgumentException_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_IllegalArgumentException_instance_(PyTypeObject *type, PyObject *arg);
        static int t_IllegalArgumentException_init_(t_IllegalArgumentException *self, PyObject *args, PyObject *kwds);

        static PyMethodDef t_IllegalArgumentException__methods_[] = {
            DECLARE_METHOD(t_IllegalArgumentException, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_IllegalArgumentException, instance_, METH_O | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(IllegalArgumentException, t_IllegalArgumentException, ::java::lang::RuntimeException, IllegalArgumentException, t_IllegalArgumentException_init_, 0, 0, 0, 0, 0);

        void t_IllegalArgumentException::install(PyObject *module)
        {
            installType(&PY_TYPE(IllegalArgumentException), module, "IllegalArgumentException", 0);
        }

        void t_IllegalArgumentException::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(IllegalArgumentException).tp_dict, "class_", make_descriptor(IllegalArgumentException::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(IllegalArgumentException).tp_dict, "wrapfn_", make_descriptor(t_IllegalArgumentException::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(IllegalArgumentException).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_IllegalArgumentException_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, IllegalArgumentException::initializeClass, 1)))
                return NULL;
            return t_IllegalArgumentException::wrap_Object(IllegalArgumentException(((t_IllegalArgumentException *) arg)->object.this$));
        }
        static PyObject *t_IllegalArgumentException_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, IllegalArgumentException::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_IllegalArgumentException_init_(t_IllegalArgumentException *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    IllegalArgumentException object((jobject) NULL);

                    INT_CALL(object = IllegalArgumentException());
                    self->object = object;
                    break;
                }
                goto err;
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    IllegalArgumentException object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = IllegalArgumentException(a0));
                        self->object = object;
                        break;
                    }
                }
                {
                    ::java::lang::Throwable a0((jobject) NULL);
                    IllegalArgumentException object((jobject) NULL);

                    if (!parseArgs(args, "k", ::java::lang::Throwable::initializeClass, &a0))
                    {
                        INT_CALL(object = IllegalArgumentException(a0));
                        self->object = object;
                        break;
                    }
                }
                goto err;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    ::java::lang::Throwable a1((jobject) NULL);
                    IllegalArgumentException object((jobject) NULL);

                    if (!parseArgs(args, "sk", ::java::lang::Throwable::initializeClass, &a0, &a1))
                    {
                        INT_CALL(object = IllegalArgumentException(a0, a1));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/AbstractStringBuilder.h"
#include "java/lang/String.h"
#include "java/lang/CharSequence.h"
#include "java/lang/Appendable.h"
#include "java/lang/Class.h"
#include "java/lang/StringBuffer.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *AbstractStringBuilder::class$ = NULL;
        jmethodID *AbstractStringBuilder::mids$ = NULL;

        jclass AbstractStringBuilder::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/AbstractStringBuilder");

                mids$ = new jmethodID[max_mid];
                mids$[mid_append_7c173d47] = env->getMethodID(cls, "append", "([C)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_append_a2ed0092] = env->getMethodID(cls, "append", "(F)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_append_5e58b04c] = env->getMethodID(cls, "append", "(D)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_append_db02ec8f] = env->getMethodID(cls, "append", "(Ljava/lang/Object;)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_append_4d0b6cce] = env->getMethodID(cls, "append", "(J)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_append_9dc99a1e] = env->getMethodID(cls, "append", "(Z)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_append_a6b3f18b] = env->getMethodID(cls, "append", "(C)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_append_97dd5503] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_append_0f3b1ca9] = env->getMethodID(cls, "append", "(Ljava/lang/String;)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_append_2814c015] = env->getMethodID(cls, "append", "(I)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_append_5337ed99] = env->getMethodID(cls, "append", "(Ljava/lang/StringBuffer;)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_append_c2cdc21f] = env->getMethodID(cls, "append", "([CII)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_append_7e485efb] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;II)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_appendCodePoint_2814c015] = env->getMethodID(cls, "appendCodePoint", "(I)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_capacity_54c6a179] = env->getMethodID(cls, "capacity", "()I");
                mids$[mid_charAt_39c7bd29] = env->getMethodID(cls, "charAt", "(I)C");
                mids$[mid_codePointAt_39c7bd23] = env->getMethodID(cls, "codePointAt", "(I)I");
                mids$[mid_codePointBefore_39c7bd23] = env->getMethodID(cls, "codePointBefore", "(I)I");
                mids$[mid_codePointCount_d8d154b9] = env->getMethodID(cls, "codePointCount", "(II)I");
                mids$[mid_delete_2b8ead17] = env->getMethodID(cls, "delete", "(II)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_deleteCharAt_2814c015] = env->getMethodID(cls, "deleteCharAt", "(I)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_ensureCapacity_39c7bd3c] = env->getMethodID(cls, "ensureCapacity", "(I)V");
                mids$[mid_getChars_06518f84] = env->getMethodID(cls, "getChars", "(II[CI)V");
                mids$[mid_indexOf_5fdc3f57] = env->getMethodID(cls, "indexOf", "(Ljava/lang/String;)I");
                mids$[mid_indexOf_6e53ccd9] = env->getMethodID(cls, "indexOf", "(Ljava/lang/String;I)I");
                mids$[mid_insert_6089bc60] = env->getMethodID(cls, "insert", "(IF)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_insert_af3c3de9] = env->getMethodID(cls, "insert", "(I[C)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_insert_62ac5207] = env->getMethodID(cls, "insert", "(ILjava/lang/String;)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_insert_2b8ead17] = env->getMethodID(cls, "insert", "(II)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_insert_d1cc213e] = env->getMethodID(cls, "insert", "(ID)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_insert_5236bc0d] = env->getMethodID(cls, "insert", "(ILjava/lang/Object;)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_insert_8567b539] = env->getMethodID(cls, "insert", "(ILjava/lang/CharSequence;)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_insert_06d282ac] = env->getMethodID(cls, "insert", "(IZ)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_insert_063a9eb9] = env->getMethodID(cls, "insert", "(IC)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_insert_9beca11c] = env->getMethodID(cls, "insert", "(IJ)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_insert_78ebdb01] = env->getMethodID(cls, "insert", "(ILjava/lang/CharSequence;II)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_insert_24aafa89] = env->getMethodID(cls, "insert", "(I[CII)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_lastIndexOf_5fdc3f57] = env->getMethodID(cls, "lastIndexOf", "(Ljava/lang/String;)I");
                mids$[mid_lastIndexOf_6e53ccd9] = env->getMethodID(cls, "lastIndexOf", "(Ljava/lang/String;I)I");
                mids$[mid_length_54c6a179] = env->getMethodID(cls, "length", "()I");
                mids$[mid_offsetByCodePoints_d8d154b9] = env->getMethodID(cls, "offsetByCodePoints", "(II)I");
                mids$[mid_replace_349953a9] = env->getMethodID(cls, "replace", "(IILjava/lang/String;)Ljava/lang/AbstractStringBuilder;");
                mids$[mid_reverse_570c12f7] = env->getMethodID(cls, "reverse", "()Ljava/lang/AbstractStringBuilder;");
                mids$[mid_setCharAt_83eec158] = env->getMethodID(cls, "setCharAt", "(IC)V");
                mids$[mid_setLength_39c7bd3c] = env->getMethodID(cls, "setLength", "(I)V");
                mids$[mid_subSequence_f88dfd57] = env->getMethodID(cls, "subSequence", "(II)Ljava/lang/CharSequence;");
                mids$[mid_substring_141401b3] = env->getMethodID(cls, "substring", "(I)Ljava/lang/String;");
                mids$[mid_substring_f9118fe5] = env->getMethodID(cls, "substring", "(II)Ljava/lang/String;");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
                mids$[mid_trimToSize_54c6a166] = env->getMethodID(cls, "trimToSize", "()V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        AbstractStringBuilder AbstractStringBuilder::append(const JArray< jchar > & a0) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_7c173d47], a0.this$));
        }

        AbstractStringBuilder AbstractStringBuilder::append(jfloat a0) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_a2ed0092], a0));
        }

        AbstractStringBuilder AbstractStringBuilder::append(jdouble a0) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_5e58b04c], a0));
        }

        AbstractStringBuilder AbstractStringBuilder::append(const ::java::lang::Object & a0) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_db02ec8f], a0.this$));
        }

        AbstractStringBuilder AbstractStringBuilder::append(jlong a0) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_4d0b6cce], a0));
        }

        AbstractStringBuilder AbstractStringBuilder::append(jboolean a0) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_9dc99a1e], a0));
        }

        AbstractStringBuilder AbstractStringBuilder::append(jchar a0) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_a6b3f18b], a0));
        }

        AbstractStringBuilder AbstractStringBuilder::append(const ::java::lang::CharSequence & a0) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_97dd5503], a0.this$));
        }

        AbstractStringBuilder AbstractStringBuilder::append(const ::java::lang::String & a0) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_0f3b1ca9], a0.this$));
        }

        AbstractStringBuilder AbstractStringBuilder::append(jint a0) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_2814c015], a0));
        }

        AbstractStringBuilder AbstractStringBuilder::append(const ::java::lang::StringBuffer & a0) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_5337ed99], a0.this$));
        }

        AbstractStringBuilder AbstractStringBuilder::append(const JArray< jchar > & a0, jint a1, jint a2) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_c2cdc21f], a0.this$, a1, a2));
        }

        AbstractStringBuilder AbstractStringBuilder::append(const ::java::lang::CharSequence & a0, jint a1, jint a2) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_7e485efb], a0.this$, a1, a2));
        }

        AbstractStringBuilder AbstractStringBuilder::appendCodePoint(jint a0) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_appendCodePoint_2814c015], a0));
        }

        jint AbstractStringBuilder::capacity() const
        {
            return env->callIntMethod(this$, mids$[mid_capacity_54c6a179]);
        }

        jchar AbstractStringBuilder::charAt(jint a0) const
        {
            return env->callCharMethod(this$, mids$[mid_charAt_39c7bd29], a0);
        }

        jint AbstractStringBuilder::codePointAt(jint a0) const
        {
            return env->callIntMethod(this$, mids$[mid_codePointAt_39c7bd23], a0);
        }

        jint AbstractStringBuilder::codePointBefore(jint a0) const
        {
            return env->callIntMethod(this$, mids$[mid_codePointBefore_39c7bd23], a0);
        }

        jint AbstractStringBuilder::codePointCount(jint a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_codePointCount_d8d154b9], a0, a1);
        }

        AbstractStringBuilder AbstractStringBuilder::delete$(jint a0, jint a1) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_delete_2b8ead17], a0, a1));
        }

        AbstractStringBuilder AbstractStringBuilder::deleteCharAt(jint a0) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_deleteCharAt_2814c015], a0));
        }

        void AbstractStringBuilder::ensureCapacity(jint a0) const
        {
            env->callVoidMethod(this$, mids$[mid_ensureCapacity_39c7bd3c], a0);
        }

        void AbstractStringBuilder::getChars(jint a0, jint a1, const JArray< jchar > & a2, jint a3) const
        {
            env->callVoidMethod(this$, mids$[mid_getChars_06518f84], a0, a1, a2.this$, a3);
        }

        jint AbstractStringBuilder::indexOf(const ::java::lang::String & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_indexOf_5fdc3f57], a0.this$);
        }

        jint AbstractStringBuilder::indexOf(const ::java::lang::String & a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_indexOf_6e53ccd9], a0.this$, a1);
        }

        AbstractStringBuilder AbstractStringBuilder::insert(jint a0, jfloat a1) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_6089bc60], a0, a1));
        }

        AbstractStringBuilder AbstractStringBuilder::insert(jint a0, const JArray< jchar > & a1) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_af3c3de9], a0, a1.this$));
        }

        AbstractStringBuilder AbstractStringBuilder::insert(jint a0, const ::java::lang::String & a1) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_62ac5207], a0, a1.this$));
        }

        AbstractStringBuilder AbstractStringBuilder::insert(jint a0, jint a1) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_2b8ead17], a0, a1));
        }

        AbstractStringBuilder AbstractStringBuilder::insert(jint a0, jdouble a1) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_d1cc213e], a0, a1));
        }

        AbstractStringBuilder AbstractStringBuilder::insert(jint a0, const ::java::lang::Object & a1) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_5236bc0d], a0, a1.this$));
        }

        AbstractStringBuilder AbstractStringBuilder::insert(jint a0, const ::java::lang::CharSequence & a1) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_8567b539], a0, a1.this$));
        }

        AbstractStringBuilder AbstractStringBuilder::insert(jint a0, jboolean a1) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_06d282ac], a0, a1));
        }

        AbstractStringBuilder AbstractStringBuilder::insert(jint a0, jchar a1) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_063a9eb9], a0, a1));
        }

        AbstractStringBuilder AbstractStringBuilder::insert(jint a0, jlong a1) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_9beca11c], a0, a1));
        }

        AbstractStringBuilder AbstractStringBuilder::insert(jint a0, const ::java::lang::CharSequence & a1, jint a2, jint a3) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_78ebdb01], a0, a1.this$, a2, a3));
        }

        AbstractStringBuilder AbstractStringBuilder::insert(jint a0, const JArray< jchar > & a1, jint a2, jint a3) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_24aafa89], a0, a1.this$, a2, a3));
        }

        jint AbstractStringBuilder::lastIndexOf(const ::java::lang::String & a0) const
        {
            return env->callIntMethod(this$, mids$[mid_lastIndexOf_5fdc3f57], a0.this$);
        }

        jint AbstractStringBuilder::lastIndexOf(const ::java::lang::String & a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_lastIndexOf_6e53ccd9], a0.this$, a1);
        }

        jint AbstractStringBuilder::length() const
        {
            return env->callIntMethod(this$, mids$[mid_length_54c6a179]);
        }

        jint AbstractStringBuilder::offsetByCodePoints(jint a0, jint a1) const
        {
            return env->callIntMethod(this$, mids$[mid_offsetByCodePoints_d8d154b9], a0, a1);
        }

        AbstractStringBuilder AbstractStringBuilder::replace(jint a0, jint a1, const ::java::lang::String & a2) const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_replace_349953a9], a0, a1, a2.this$));
        }

        AbstractStringBuilder AbstractStringBuilder::reverse() const
        {
            return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_reverse_570c12f7]));
        }

        void AbstractStringBuilder::setCharAt(jint a0, jchar a1) const
        {
            env->callVoidMethod(this$, mids$[mid_setCharAt_83eec158], a0, a1);
        }

        void AbstractStringBuilder::setLength(jint a0) const
        {
            env->callVoidMethod(this$, mids$[mid_setLength_39c7bd3c], a0);
        }

        ::java::lang::CharSequence AbstractStringBuilder::subSequence(jint a0, jint a1) const
        {
            return ::java::lang::CharSequence(env->callObjectMethod(this$, mids$[mid_subSequence_f88dfd57], a0, a1));
        }

        ::java::lang::String AbstractStringBuilder::substring(jint a0) const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_substring_141401b3], a0));
        }

        ::java::lang::String AbstractStringBuilder::substring(jint a0, jint a1) const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_substring_f9118fe5], a0, a1));
        }

        ::java::lang::String AbstractStringBuilder::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }

        void AbstractStringBuilder::trimToSize() const
        {
            env->callVoidMethod(this$, mids$[mid_trimToSize_54c6a166]);
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_AbstractStringBuilder_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_AbstractStringBuilder_instance_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_AbstractStringBuilder_append(t_AbstractStringBuilder *self, PyObject *args);
        static PyObject *t_AbstractStringBuilder_appendCodePoint(t_AbstractStringBuilder *self, PyObject *arg);
        static PyObject *t_AbstractStringBuilder_capacity(t_AbstractStringBuilder *self);
        static PyObject *t_AbstractStringBuilder_charAt(t_AbstractStringBuilder *self, PyObject *arg);
        static PyObject *t_AbstractStringBuilder_codePointAt(t_AbstractStringBuilder *self, PyObject *arg);
        static PyObject *t_AbstractStringBuilder_codePointBefore(t_AbstractStringBuilder *self, PyObject *arg);
        static PyObject *t_AbstractStringBuilder_codePointCount(t_AbstractStringBuilder *self, PyObject *args);
        static PyObject *t_AbstractStringBuilder_delete(t_AbstractStringBuilder *self, PyObject *args);
        static PyObject *t_AbstractStringBuilder_deleteCharAt(t_AbstractStringBuilder *self, PyObject *arg);
        static PyObject *t_AbstractStringBuilder_ensureCapacity(t_AbstractStringBuilder *self, PyObject *arg);
        static PyObject *t_AbstractStringBuilder_getChars(t_AbstractStringBuilder *self, PyObject *args);
        static PyObject *t_AbstractStringBuilder_indexOf(t_AbstractStringBuilder *self, PyObject *args);
        static PyObject *t_AbstractStringBuilder_insert(t_AbstractStringBuilder *self, PyObject *args);
        static PyObject *t_AbstractStringBuilder_lastIndexOf(t_AbstractStringBuilder *self, PyObject *args);
        static PyObject *t_AbstractStringBuilder_length(t_AbstractStringBuilder *self);
        static PyObject *t_AbstractStringBuilder_offsetByCodePoints(t_AbstractStringBuilder *self, PyObject *args);
        static PyObject *t_AbstractStringBuilder_replace(t_AbstractStringBuilder *self, PyObject *args);
        static PyObject *t_AbstractStringBuilder_reverse(t_AbstractStringBuilder *self);
        static PyObject *t_AbstractStringBuilder_setCharAt(t_AbstractStringBuilder *self, PyObject *args);
        static PyObject *t_AbstractStringBuilder_setLength(t_AbstractStringBuilder *self, PyObject *arg);
        static PyObject *t_AbstractStringBuilder_subSequence(t_AbstractStringBuilder *self, PyObject *args);
        static PyObject *t_AbstractStringBuilder_substring(t_AbstractStringBuilder *self, PyObject *args);
        static PyObject *t_AbstractStringBuilder_toString(t_AbstractStringBuilder *self, PyObject *args);
        static PyObject *t_AbstractStringBuilder_trimToSize(t_AbstractStringBuilder *self);

        static PyMethodDef t_AbstractStringBuilder__methods_[] = {
            DECLARE_METHOD(t_AbstractStringBuilder, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_AbstractStringBuilder, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_AbstractStringBuilder, append, METH_VARARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, appendCodePoint, METH_O),
            DECLARE_METHOD(t_AbstractStringBuilder, capacity, METH_NOARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, charAt, METH_O),
            DECLARE_METHOD(t_AbstractStringBuilder, codePointAt, METH_O),
            DECLARE_METHOD(t_AbstractStringBuilder, codePointBefore, METH_O),
            DECLARE_METHOD(t_AbstractStringBuilder, codePointCount, METH_VARARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, delete, METH_VARARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, deleteCharAt, METH_O),
            DECLARE_METHOD(t_AbstractStringBuilder, ensureCapacity, METH_O),
            DECLARE_METHOD(t_AbstractStringBuilder, getChars, METH_VARARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, indexOf, METH_VARARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, insert, METH_VARARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, lastIndexOf, METH_VARARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, length, METH_NOARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, offsetByCodePoints, METH_VARARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, replace, METH_VARARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, reverse, METH_NOARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, setCharAt, METH_VARARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, setLength, METH_O),
            DECLARE_METHOD(t_AbstractStringBuilder, subSequence, METH_VARARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, substring, METH_VARARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, toString, METH_VARARGS),
            DECLARE_METHOD(t_AbstractStringBuilder, trimToSize, METH_NOARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(AbstractStringBuilder, t_AbstractStringBuilder, ::java::lang::Object, AbstractStringBuilder, abstract_init, 0, 0, 0, 0, 0);

        void t_AbstractStringBuilder::install(PyObject *module)
        {
            installType(&PY_TYPE(AbstractStringBuilder), module, "AbstractStringBuilder", 0);
        }

        void t_AbstractStringBuilder::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(AbstractStringBuilder).tp_dict, "class_", make_descriptor(AbstractStringBuilder::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(AbstractStringBuilder).tp_dict, "wrapfn_", make_descriptor(t_AbstractStringBuilder::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(AbstractStringBuilder).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_AbstractStringBuilder_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, AbstractStringBuilder::initializeClass, 1)))
                return NULL;
            return t_AbstractStringBuilder::wrap_Object(AbstractStringBuilder(((t_AbstractStringBuilder *) arg)->object.this$));
        }
        static PyObject *t_AbstractStringBuilder_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, AbstractStringBuilder::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static PyObject *t_AbstractStringBuilder_append(t_AbstractStringBuilder *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    JArray< jchar > a0((jobject) NULL);
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "[C", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jfloat a0;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "F", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jdouble a0;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "D", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::Object a0((jobject) NULL);
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "o", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jlong a0;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "J", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jboolean a0;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "Z", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jchar a0;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "C", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::String a0((jobject) NULL);
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::StringBuffer a0((jobject) NULL);
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "k", ::java::lang::StringBuffer::initializeClass, &a0))
                    {
                        OBJ_CALL(result = self->object.append(a0));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                break;
              case 3:
                {
                    JArray< jchar > a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "[CII", &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = self->object.append(a0, a1, a2));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    ::java::lang::CharSequence a0((jobject) NULL);
                    jint a1;
                    jint a2;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
                    {
                        OBJ_CALL(result = self->object.append(a0, a1, a2));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "append", args);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_appendCodePoint(t_AbstractStringBuilder *self, PyObject *arg)
        {
            jint a0;
            AbstractStringBuilder result((jobject) NULL);

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = self->object.appendCodePoint(a0));
                return t_AbstractStringBuilder::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "appendCodePoint", arg);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_capacity(t_AbstractStringBuilder *self)
        {
            jint result;
            OBJ_CALL(result = self->object.capacity());
            return PyInt_FromLong((long) result);
        }

        static PyObject *t_AbstractStringBuilder_charAt(t_AbstractStringBuilder *self, PyObject *arg)
        {
            jint a0;
            jchar result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = self->object.charAt(a0));
                return PyUnicode_FromUnicode((Py_UNICODE *) &result, 1);
            }

            PyErr_SetArgsError((PyObject *) self, "charAt", arg);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_codePointAt(t_AbstractStringBuilder *self, PyObject *arg)
        {
            jint a0;
            jint result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = self->object.codePointAt(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError((PyObject *) self, "codePointAt", arg);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_codePointBefore(t_AbstractStringBuilder *self, PyObject *arg)
        {
            jint a0;
            jint result;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = self->object.codePointBefore(a0));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError((PyObject *) self, "codePointBefore", arg);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_codePointCount(t_AbstractStringBuilder *self, PyObject *args)
        {
            jint a0;
            jint a1;
            jint result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.codePointCount(a0, a1));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError((PyObject *) self, "codePointCount", args);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_delete(t_AbstractStringBuilder *self, PyObject *args)
        {
            jint a0;
            jint a1;
            AbstractStringBuilder result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.delete$(a0, a1));
                return t_AbstractStringBuilder::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "delete", args);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_deleteCharAt(t_AbstractStringBuilder *self, PyObject *arg)
        {
            jint a0;
            AbstractStringBuilder result((jobject) NULL);

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(result = self->object.deleteCharAt(a0));
                return t_AbstractStringBuilder::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "deleteCharAt", arg);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_ensureCapacity(t_AbstractStringBuilder *self, PyObject *arg)
        {
            jint a0;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(self->object.ensureCapacity(a0));
                Py_RETURN_NONE;
            }

            PyErr_SetArgsError((PyObject *) self, "ensureCapacity", arg);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_getChars(t_AbstractStringBuilder *self, PyObject *args)
        {
            jint a0;
            jint a1;
            JArray< jchar > a2((jobject) NULL);
            jint a3;

            if (!parseArgs(args, "II[CI", &a0, &a1, &a2, &a3))
            {
                OBJ_CALL(self->object.getChars(a0, a1, a2, a3));
                Py_RETURN_NONE;
            }

            PyErr_SetArgsError((PyObject *) self, "getChars", args);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_indexOf(t_AbstractStringBuilder *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.indexOf(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.indexOf(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "indexOf", args);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_insert(t_AbstractStringBuilder *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 2:
                {
                    jint a0;
                    jfloat a1;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "IF", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    JArray< jchar > a1((jobject) NULL);
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "I[C", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    ::java::lang::String a1((jobject) NULL);
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "Is", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jint a1;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "II", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jdouble a1;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "ID", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    ::java::lang::Object a1((jobject) NULL);
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "Io", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    ::java::lang::CharSequence a1((jobject) NULL);
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "IO", &::java::lang::PY_TYPE(CharSequence), &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jboolean a1;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "IZ", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jchar a1;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "IC", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    jlong a1;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "IJ", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                break;
              case 4:
                {
                    jint a0;
                    ::java::lang::CharSequence a1((jobject) NULL);
                    jint a2;
                    jint a3;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "IOII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2, &a3))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1, a2, a3));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
                {
                    jint a0;
                    JArray< jchar > a1((jobject) NULL);
                    jint a2;
                    jint a3;
                    AbstractStringBuilder result((jobject) NULL);

                    if (!parseArgs(args, "I[CII", &a0, &a1, &a2, &a3))
                    {
                        OBJ_CALL(result = self->object.insert(a0, a1, a2, a3));
                        return t_AbstractStringBuilder::wrap_Object(result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "insert", args);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_lastIndexOf(t_AbstractStringBuilder *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint result;

                    if (!parseArgs(args, "s", &a0))
                    {
                        OBJ_CALL(result = self->object.lastIndexOf(a0));
                        return PyInt_FromLong((long) result);
                    }
                }
                break;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    jint a1;
                    jint result;

                    if (!parseArgs(args, "sI", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.lastIndexOf(a0, a1));
                        return PyInt_FromLong((long) result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "lastIndexOf", args);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_length(t_AbstractStringBuilder *self)
        {
            jint result;
            OBJ_CALL(result = self->object.length());
            return PyInt_FromLong((long) result);
        }

        static PyObject *t_AbstractStringBuilder_offsetByCodePoints(t_AbstractStringBuilder *self, PyObject *args)
        {
            jint a0;
            jint a1;
            jint result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.offsetByCodePoints(a0, a1));
                return PyInt_FromLong((long) result);
            }

            PyErr_SetArgsError((PyObject *) self, "offsetByCodePoints", args);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_replace(t_AbstractStringBuilder *self, PyObject *args)
        {
            jint a0;
            jint a1;
            ::java::lang::String a2((jobject) NULL);
            AbstractStringBuilder result((jobject) NULL);

            if (!parseArgs(args, "IIs", &a0, &a1, &a2))
            {
                OBJ_CALL(result = self->object.replace(a0, a1, a2));
                return t_AbstractStringBuilder::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "replace", args);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_reverse(t_AbstractStringBuilder *self)
        {
            AbstractStringBuilder result((jobject) NULL);
            OBJ_CALL(result = self->object.reverse());
            return t_AbstractStringBuilder::wrap_Object(result);
        }

        static PyObject *t_AbstractStringBuilder_setCharAt(t_AbstractStringBuilder *self, PyObject *args)
        {
            jint a0;
            jchar a1;

            if (!parseArgs(args, "IC", &a0, &a1))
            {
                OBJ_CALL(self->object.setCharAt(a0, a1));
                Py_RETURN_NONE;
            }

            PyErr_SetArgsError((PyObject *) self, "setCharAt", args);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_setLength(t_AbstractStringBuilder *self, PyObject *arg)
        {
            jint a0;

            if (!parseArg(arg, "I", &a0))
            {
                OBJ_CALL(self->object.setLength(a0));
                Py_RETURN_NONE;
            }

            PyErr_SetArgsError((PyObject *) self, "setLength", arg);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_subSequence(t_AbstractStringBuilder *self, PyObject *args)
        {
            jint a0;
            jint a1;
            ::java::lang::CharSequence result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
                OBJ_CALL(result = self->object.subSequence(a0, a1));
                return ::java::lang::t_CharSequence::wrap_Object(result);
            }

            PyErr_SetArgsError((PyObject *) self, "subSequence", args);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_substring(t_AbstractStringBuilder *self, PyObject *args)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 1:
                {
                    jint a0;
                    ::java::lang::String result((jobject) NULL);

                    if (!parseArgs(args, "I", &a0))
                    {
                        OBJ_CALL(result = self->object.substring(a0));
                        return j2p(result);
                    }
                }
                break;
              case 2:
                {
                    jint a0;
                    jint a1;
                    ::java::lang::String result((jobject) NULL);

                    if (!parseArgs(args, "II", &a0, &a1))
                    {
                        OBJ_CALL(result = self->object.substring(a0, a1));
                        return j2p(result);
                    }
                }
            }

            PyErr_SetArgsError((PyObject *) self, "substring", args);
            return NULL;
        }

        static PyObject *t_AbstractStringBuilder_toString(t_AbstractStringBuilder *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(AbstractStringBuilder), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_AbstractStringBuilder_trimToSize(t_AbstractStringBuilder *self)
        {
            OBJ_CALL(self->object.trimToSize());
            Py_RETURN_NONE;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/IllegalAccessException.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *IllegalAccessException::class$ = NULL;
        jmethodID *IllegalAccessException::mids$ = NULL;

        jclass IllegalAccessException::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/IllegalAccessException");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        IllegalAccessException::IllegalAccessException() : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        IllegalAccessException::IllegalAccessException(const ::java::lang::String & a0) : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_IllegalAccessException_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_IllegalAccessException_instance_(PyTypeObject *type, PyObject *arg);
        static int t_IllegalAccessException_init_(t_IllegalAccessException *self, PyObject *args, PyObject *kwds);

        static PyMethodDef t_IllegalAccessException__methods_[] = {
            DECLARE_METHOD(t_IllegalAccessException, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_IllegalAccessException, instance_, METH_O | METH_CLASS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(IllegalAccessException, t_IllegalAccessException, ::java::lang::Exception, IllegalAccessException, t_IllegalAccessException_init_, 0, 0, 0, 0, 0);

        void t_IllegalAccessException::install(PyObject *module)
        {
            installType(&PY_TYPE(IllegalAccessException), module, "IllegalAccessException", 0);
        }

        void t_IllegalAccessException::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(IllegalAccessException).tp_dict, "class_", make_descriptor(IllegalAccessException::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(IllegalAccessException).tp_dict, "wrapfn_", make_descriptor(t_IllegalAccessException::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(IllegalAccessException).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_IllegalAccessException_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, IllegalAccessException::initializeClass, 1)))
                return NULL;
            return t_IllegalAccessException::wrap_Object(IllegalAccessException(((t_IllegalAccessException *) arg)->object.this$));
        }
        static PyObject *t_IllegalAccessException_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, IllegalAccessException::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_IllegalAccessException_init_(t_IllegalAccessException *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    IllegalAccessException object((jobject) NULL);

                    INT_CALL(object = IllegalAccessException());
                    self->object = object;
                    break;
                }
                goto err;
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    IllegalAccessException object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = IllegalAccessException(a0));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/StackTraceElement.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *StackTraceElement::class$ = NULL;
        jmethodID *StackTraceElement::mids$ = NULL;

        jclass StackTraceElement::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/StackTraceElement");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_fa754eea] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V");
                mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
                mids$[mid_getClassName_14c7b5c5] = env->getMethodID(cls, "getClassName", "()Ljava/lang/String;");
                mids$[mid_getFileName_14c7b5c5] = env->getMethodID(cls, "getFileName", "()Ljava/lang/String;");
                mids$[mid_getLineNumber_54c6a179] = env->getMethodID(cls, "getLineNumber", "()I");
                mids$[mid_getMethodName_14c7b5c5] = env->getMethodID(cls, "getMethodName", "()Ljava/lang/String;");
                mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
                mids$[mid_isNativeMethod_54c6a16a] = env->getMethodID(cls, "isNativeMethod", "()Z");
                mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        StackTraceElement::StackTraceElement(const ::java::lang::String & a0, const ::java::lang::String & a1, const ::java::lang::String & a2, jint a3) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_fa754eea, a0.this$, a1.this$, a2.this$, a3)) {}

        jboolean StackTraceElement::equals(const ::java::lang::Object & a0) const
        {
            return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
        }

        ::java::lang::String StackTraceElement::getClassName() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getClassName_14c7b5c5]));
        }

        ::java::lang::String StackTraceElement::getFileName() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getFileName_14c7b5c5]));
        }

        jint StackTraceElement::getLineNumber() const
        {
            return env->callIntMethod(this$, mids$[mid_getLineNumber_54c6a179]);
        }

        ::java::lang::String StackTraceElement::getMethodName() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getMethodName_14c7b5c5]));
        }

        jint StackTraceElement::hashCode() const
        {
            return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
        }

        jboolean StackTraceElement::isNativeMethod() const
        {
            return env->callBooleanMethod(this$, mids$[mid_isNativeMethod_54c6a16a]);
        }

        ::java::lang::String StackTraceElement::toString() const
        {
            return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_StackTraceElement_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_StackTraceElement_instance_(PyTypeObject *type, PyObject *arg);
        static int t_StackTraceElement_init_(t_StackTraceElement *self, PyObject *args, PyObject *kwds);
        static PyObject *t_StackTraceElement_equals(t_StackTraceElement *self, PyObject *args);
        static PyObject *t_StackTraceElement_getClassName(t_StackTraceElement *self);
        static PyObject *t_StackTraceElement_getFileName(t_StackTraceElement *self);
        static PyObject *t_StackTraceElement_getLineNumber(t_StackTraceElement *self);
        static PyObject *t_StackTraceElement_getMethodName(t_StackTraceElement *self);
        static PyObject *t_StackTraceElement_hashCode(t_StackTraceElement *self, PyObject *args);
        static PyObject *t_StackTraceElement_isNativeMethod(t_StackTraceElement *self);
        static PyObject *t_StackTraceElement_toString(t_StackTraceElement *self, PyObject *args);
        static PyObject *t_StackTraceElement_get__className(t_StackTraceElement *self, void *data);
        static PyObject *t_StackTraceElement_get__fileName(t_StackTraceElement *self, void *data);
        static PyObject *t_StackTraceElement_get__lineNumber(t_StackTraceElement *self, void *data);
        static PyObject *t_StackTraceElement_get__methodName(t_StackTraceElement *self, void *data);
        static PyObject *t_StackTraceElement_get__nativeMethod(t_StackTraceElement *self, void *data);
        static PyGetSetDef t_StackTraceElement__fields_[] = {
            DECLARE_GET_FIELD(t_StackTraceElement, className),
            DECLARE_GET_FIELD(t_StackTraceElement, fileName),
            DECLARE_GET_FIELD(t_StackTraceElement, lineNumber),
            DECLARE_GET_FIELD(t_StackTraceElement, methodName),
            DECLARE_GET_FIELD(t_StackTraceElement, nativeMethod),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_StackTraceElement__methods_[] = {
            DECLARE_METHOD(t_StackTraceElement, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_StackTraceElement, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_StackTraceElement, equals, METH_VARARGS),
            DECLARE_METHOD(t_StackTraceElement, getClassName, METH_NOARGS),
            DECLARE_METHOD(t_StackTraceElement, getFileName, METH_NOARGS),
            DECLARE_METHOD(t_StackTraceElement, getLineNumber, METH_NOARGS),
            DECLARE_METHOD(t_StackTraceElement, getMethodName, METH_NOARGS),
            DECLARE_METHOD(t_StackTraceElement, hashCode, METH_VARARGS),
            DECLARE_METHOD(t_StackTraceElement, isNativeMethod, METH_NOARGS),
            DECLARE_METHOD(t_StackTraceElement, toString, METH_VARARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(StackTraceElement, t_StackTraceElement, ::java::lang::Object, StackTraceElement, t_StackTraceElement_init_, 0, 0, t_StackTraceElement__fields_, 0, 0);

        void t_StackTraceElement::install(PyObject *module)
        {
            installType(&PY_TYPE(StackTraceElement), module, "StackTraceElement", 0);
        }

        void t_StackTraceElement::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(StackTraceElement).tp_dict, "class_", make_descriptor(StackTraceElement::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(StackTraceElement).tp_dict, "wrapfn_", make_descriptor(t_StackTraceElement::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(StackTraceElement).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_StackTraceElement_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, StackTraceElement::initializeClass, 1)))
                return NULL;
            return t_StackTraceElement::wrap_Object(StackTraceElement(((t_StackTraceElement *) arg)->object.this$));
        }
        static PyObject *t_StackTraceElement_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, StackTraceElement::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_StackTraceElement_init_(t_StackTraceElement *self, PyObject *args, PyObject *kwds)
        {
            ::java::lang::String a0((jobject) NULL);
            ::java::lang::String a1((jobject) NULL);
            ::java::lang::String a2((jobject) NULL);
            jint a3;
            StackTraceElement object((jobject) NULL);

            if (!parseArgs(args, "sssI", &a0, &a1, &a2, &a3))
            {
                INT_CALL(object = StackTraceElement(a0, a1, a2, a3));
                self->object = object;
            }
            else
            {
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_StackTraceElement_equals(t_StackTraceElement *self, PyObject *args)
        {
            ::java::lang::Object a0((jobject) NULL);
            jboolean result;

            if (!parseArgs(args, "o", &a0))
            {
                OBJ_CALL(result = self->object.equals(a0));
                Py_RETURN_BOOL(result);
            }

            return callSuper(&PY_TYPE(StackTraceElement), (PyObject *) self, "equals", args, 2);
        }

        static PyObject *t_StackTraceElement_getClassName(t_StackTraceElement *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getClassName());
            return j2p(result);
        }

        static PyObject *t_StackTraceElement_getFileName(t_StackTraceElement *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getFileName());
            return j2p(result);
        }

        static PyObject *t_StackTraceElement_getLineNumber(t_StackTraceElement *self)
        {
            jint result;
            OBJ_CALL(result = self->object.getLineNumber());
            return PyInt_FromLong((long) result);
        }

        static PyObject *t_StackTraceElement_getMethodName(t_StackTraceElement *self)
        {
            ::java::lang::String result((jobject) NULL);
            OBJ_CALL(result = self->object.getMethodName());
            return j2p(result);
        }

        static PyObject *t_StackTraceElement_hashCode(t_StackTraceElement *self, PyObject *args)
        {
            jint result;

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.hashCode());
                return PyInt_FromLong((long) result);
            }

            return callSuper(&PY_TYPE(StackTraceElement), (PyObject *) self, "hashCode", args, 2);
        }

        static PyObject *t_StackTraceElement_isNativeMethod(t_StackTraceElement *self)
        {
            jboolean result;
            OBJ_CALL(result = self->object.isNativeMethod());
            Py_RETURN_BOOL(result);
        }

        static PyObject *t_StackTraceElement_toString(t_StackTraceElement *self, PyObject *args)
        {
            ::java::lang::String result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.toString());
                return j2p(result);
            }

            return callSuper(&PY_TYPE(StackTraceElement), (PyObject *) self, "toString", args, 2);
        }

        static PyObject *t_StackTraceElement_get__className(t_StackTraceElement *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getClassName());
            return j2p(value);
        }

        static PyObject *t_StackTraceElement_get__fileName(t_StackTraceElement *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getFileName());
            return j2p(value);
        }

        static PyObject *t_StackTraceElement_get__lineNumber(t_StackTraceElement *self, void *data)
        {
            jint value;
            OBJ_CALL(value = self->object.getLineNumber());
            return PyInt_FromLong((long) value);
        }

        static PyObject *t_StackTraceElement_get__methodName(t_StackTraceElement *self, void *data)
        {
            ::java::lang::String value((jobject) NULL);
            OBJ_CALL(value = self->object.getMethodName());
            return j2p(value);
        }

        static PyObject *t_StackTraceElement_get__nativeMethod(t_StackTraceElement *self, void *data)
        {
            jboolean value;
            OBJ_CALL(value = self->object.isNativeMethod());
            Py_RETURN_BOOL(value);
        }
    }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/ClassNotFoundException.h"
#include "java/lang/Throwable.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
    namespace lang {

        ::java::lang::Class *ClassNotFoundException::class$ = NULL;
        jmethodID *ClassNotFoundException::mids$ = NULL;

        jclass ClassNotFoundException::initializeClass()
        {
            if (!class$)
            {

                jclass cls = (jclass) env->findClass("java/lang/ClassNotFoundException");

                mids$ = new jmethodID[max_mid];
                mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
                mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
                mids$[mid_init$_01646a2e] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");
                mids$[mid_getCause_9a29189d] = env->getMethodID(cls, "getCause", "()Ljava/lang/Throwable;");
                mids$[mid_getException_9a29189d] = env->getMethodID(cls, "getException", "()Ljava/lang/Throwable;");

                class$ = (::java::lang::Class *) new JObject(cls);
            }
            return (jclass) class$->this$;
        }

        ClassNotFoundException::ClassNotFoundException() : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

        ClassNotFoundException::ClassNotFoundException(const ::java::lang::String & a0) : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

        ClassNotFoundException::ClassNotFoundException(const ::java::lang::String & a0, const ::java::lang::Throwable & a1) : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_01646a2e, a0.this$, a1.this$)) {}

        ::java::lang::Throwable ClassNotFoundException::getCause() const
        {
            return ::java::lang::Throwable(env->callObjectMethod(this$, mids$[mid_getCause_9a29189d]));
        }

        ::java::lang::Throwable ClassNotFoundException::getException() const
        {
            return ::java::lang::Throwable(env->callObjectMethod(this$, mids$[mid_getException_9a29189d]));
        }
    }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        static PyObject *t_ClassNotFoundException_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_ClassNotFoundException_instance_(PyTypeObject *type, PyObject *arg);
        static int t_ClassNotFoundException_init_(t_ClassNotFoundException *self, PyObject *args, PyObject *kwds);
        static PyObject *t_ClassNotFoundException_getCause(t_ClassNotFoundException *self, PyObject *args);
        static PyObject *t_ClassNotFoundException_getException(t_ClassNotFoundException *self);
        static PyObject *t_ClassNotFoundException_get__cause(t_ClassNotFoundException *self, void *data);
        static PyObject *t_ClassNotFoundException_get__exception(t_ClassNotFoundException *self, void *data);
        static PyGetSetDef t_ClassNotFoundException__fields_[] = {
            DECLARE_GET_FIELD(t_ClassNotFoundException, cause),
            DECLARE_GET_FIELD(t_ClassNotFoundException, exception),
            { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_ClassNotFoundException__methods_[] = {
            DECLARE_METHOD(t_ClassNotFoundException, cast_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_ClassNotFoundException, instance_, METH_O | METH_CLASS),
            DECLARE_METHOD(t_ClassNotFoundException, getCause, METH_VARARGS),
            DECLARE_METHOD(t_ClassNotFoundException, getException, METH_NOARGS),
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(ClassNotFoundException, t_ClassNotFoundException, ::java::lang::Exception, ClassNotFoundException, t_ClassNotFoundException_init_, 0, 0, t_ClassNotFoundException__fields_, 0, 0);

        void t_ClassNotFoundException::install(PyObject *module)
        {
            installType(&PY_TYPE(ClassNotFoundException), module, "ClassNotFoundException", 0);
        }

        void t_ClassNotFoundException::initialize(PyObject *module)
        {
            PyDict_SetItemString(PY_TYPE(ClassNotFoundException).tp_dict, "class_", make_descriptor(ClassNotFoundException::initializeClass, 1));
            PyDict_SetItemString(PY_TYPE(ClassNotFoundException).tp_dict, "wrapfn_", make_descriptor(t_ClassNotFoundException::wrap_jobject));
            PyDict_SetItemString(PY_TYPE(ClassNotFoundException).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_ClassNotFoundException_cast_(PyTypeObject *type, PyObject *arg)
        {
            if (!(arg = castCheck(arg, ClassNotFoundException::initializeClass, 1)))
                return NULL;
            return t_ClassNotFoundException::wrap_Object(ClassNotFoundException(((t_ClassNotFoundException *) arg)->object.this$));
        }
        static PyObject *t_ClassNotFoundException_instance_(PyTypeObject *type, PyObject *arg)
        {
            if (!castCheck(arg, ClassNotFoundException::initializeClass, 0))
                Py_RETURN_FALSE;
            Py_RETURN_TRUE;
        }

        static int t_ClassNotFoundException_init_(t_ClassNotFoundException *self, PyObject *args, PyObject *kwds)
        {
            switch (PyTuple_GET_SIZE(args)) {
              case 0:
                {
                    ClassNotFoundException object((jobject) NULL);

                    INT_CALL(object = ClassNotFoundException());
                    self->object = object;
                    break;
                }
                goto err;
              case 1:
                {
                    ::java::lang::String a0((jobject) NULL);
                    ClassNotFoundException object((jobject) NULL);

                    if (!parseArgs(args, "s", &a0))
                    {
                        INT_CALL(object = ClassNotFoundException(a0));
                        self->object = object;
                        break;
                    }
                }
                goto err;
              case 2:
                {
                    ::java::lang::String a0((jobject) NULL);
                    ::java::lang::Throwable a1((jobject) NULL);
                    ClassNotFoundException object((jobject) NULL);

                    if (!parseArgs(args, "sk", ::java::lang::Throwable::initializeClass, &a0, &a1))
                    {
                        INT_CALL(object = ClassNotFoundException(a0, a1));
                        self->object = object;
                        break;
                    }
                }
              default:
              err:
                PyErr_SetArgsError((PyObject *) self, "__init__", args);
                return -1;
            }

            return 0;
        }

        static PyObject *t_ClassNotFoundException_getCause(t_ClassNotFoundException *self, PyObject *args)
        {
            ::java::lang::Throwable result((jobject) NULL);

            if (!parseArgs(args, ""))
            {
                OBJ_CALL(result = self->object.getCause());
                return ::java::lang::t_Throwable::wrap_Object(result);
            }

            return callSuper(&PY_TYPE(ClassNotFoundException), (PyObject *) self, "getCause", args, 2);
        }

        static PyObject *t_ClassNotFoundException_getException(t_ClassNotFoundException *self)
        {
            ::java::lang::Throwable result((jobject) NULL);
            OBJ_CALL(result = self->object.getException());
            return ::java::lang::t_Throwable::wrap_Object(result);
        }

        static PyObject *t_ClassNotFoundException_get__cause(t_ClassNotFoundException *self, void *data)
        {
            ::java::lang::Throwable value((jobject) NULL);
            OBJ_CALL(value = self->object.getCause());
            return ::java::lang::t_Throwable::wrap_Object(value);
        }

        static PyObject *t_ClassNotFoundException_get__exception(t_ClassNotFoundException *self, void *data)
        {
            ::java::lang::Throwable value((jobject) NULL);
            OBJ_CALL(value = self->object.getException());
            return ::java::lang::t_Throwable::wrap_Object(value);
        }
    }
}
