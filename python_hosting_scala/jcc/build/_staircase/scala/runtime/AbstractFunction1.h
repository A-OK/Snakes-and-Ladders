#ifndef scala_runtime_AbstractFunction1_H
#define scala_runtime_AbstractFunction1_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class String;
        class Class;
    }
}
template<class T> class JArray;

namespace scala {
    namespace runtime {

        class AbstractFunction1 : public ::java::lang::Object {
        public:
            enum {
                mid_init$_54c6a166,
                mid_apply$mcDD$sp_5d1c7657,
                mid_apply$mcDF$sp_06298cb9,
                mid_apply$mcDI$sp_39c7bd2e,
                mid_apply$mcDJ$sp_0ee6df3d,
                mid_apply$mcFD$sp_5d1c7655,
                mid_apply$mcFF$sp_06298cbb,
                mid_apply$mcFI$sp_39c7bd2c,
                mid_apply$mcFJ$sp_0ee6df3f,
                mid_apply$mcID$sp_5d1c765a,
                mid_apply$mcIF$sp_06298cb4,
                mid_apply$mcII$sp_39c7bd23,
                mid_apply$mcIJ$sp_0ee6df30,
                mid_apply$mcJD$sp_5d1c7659,
                mid_apply$mcJF$sp_06298cb7,
                mid_apply$mcJI$sp_39c7bd20,
                mid_apply$mcJJ$sp_0ee6df33,
                mid_apply$mcVD$sp_5d1c7645,
                mid_apply$mcVF$sp_06298cab,
                mid_apply$mcVI$sp_39c7bd3c,
                mid_apply$mcVJ$sp_0ee6df2f,
                mid_apply$mcZD$sp_5d1c7649,
                mid_apply$mcZF$sp_06298ca7,
                mid_apply$mcZI$sp_39c7bd30,
                mid_apply$mcZJ$sp_0ee6df23,
                mid_toString_14c7b5c5,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit AbstractFunction1(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            AbstractFunction1(const AbstractFunction1& obj) : ::java::lang::Object(obj) {}

            AbstractFunction1();

            jdouble apply$mcDD$sp(jdouble) const;
            jdouble apply$mcDF$sp(jfloat) const;
            jdouble apply$mcDI$sp(jint) const;
            jdouble apply$mcDJ$sp(jlong) const;
            jfloat apply$mcFD$sp(jdouble) const;
            jfloat apply$mcFF$sp(jfloat) const;
            jfloat apply$mcFI$sp(jint) const;
            jfloat apply$mcFJ$sp(jlong) const;
            jint apply$mcID$sp(jdouble) const;
            jint apply$mcIF$sp(jfloat) const;
            jint apply$mcII$sp(jint) const;
            jint apply$mcIJ$sp(jlong) const;
            jlong apply$mcJD$sp(jdouble) const;
            jlong apply$mcJF$sp(jfloat) const;
            jlong apply$mcJI$sp(jint) const;
            jlong apply$mcJJ$sp(jlong) const;
            void apply$mcVD$sp(jdouble) const;
            void apply$mcVF$sp(jfloat) const;
            void apply$mcVI$sp(jint) const;
            void apply$mcVJ$sp(jlong) const;
            jboolean apply$mcZD$sp(jdouble) const;
            jboolean apply$mcZF$sp(jfloat) const;
            jboolean apply$mcZI$sp(jint) const;
            jboolean apply$mcZJ$sp(jlong) const;
            ::java::lang::String toString() const;
        };
    }
}

#include <Python.h>

namespace scala {
    namespace runtime {
        extern PyTypeObject PY_TYPE(AbstractFunction1);

        class t_AbstractFunction1 {
        public:
            PyObject_HEAD
            AbstractFunction1 object;
            PyTypeObject *parameters[2];
            static PyTypeObject **parameters_(t_AbstractFunction1 *self)
            {
                return (PyTypeObject **) &(self->parameters);
            }
            static PyObject *wrap_Object(const AbstractFunction1&);
            static PyObject *wrap_jobject(const jobject&);
            static PyObject *wrap_Object(const AbstractFunction1&, PyTypeObject *, PyTypeObject *);
            static PyObject *wrap_jobject(const jobject&, PyTypeObject *, PyTypeObject *);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
