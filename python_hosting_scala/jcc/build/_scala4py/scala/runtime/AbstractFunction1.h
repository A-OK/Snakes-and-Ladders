#ifndef scala_runtime_AbstractFunction1_H
#define scala_runtime_AbstractFunction1_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class String;
        class Class;
    }
}
namespace scala {
    class Function1;
    class ScalaObject;
}
template<class T> class JArray;

namespace scala {
    namespace runtime {

        class AbstractFunction1 : public ::java::lang::Object {
        public:
            enum {
                mid_init$_54c6a166,
                mid_andThen_279d294f,
                mid_andThen$mcDD$sp_279d294f,
                mid_andThen$mcDF$sp_279d294f,
                mid_andThen$mcDI$sp_279d294f,
                mid_andThen$mcDJ$sp_279d294f,
                mid_andThen$mcFD$sp_279d294f,
                mid_andThen$mcFF$sp_279d294f,
                mid_andThen$mcFI$sp_279d294f,
                mid_andThen$mcFJ$sp_279d294f,
                mid_andThen$mcID$sp_279d294f,
                mid_andThen$mcIF$sp_279d294f,
                mid_andThen$mcII$sp_279d294f,
                mid_andThen$mcIJ$sp_279d294f,
                mid_andThen$mcJD$sp_279d294f,
                mid_andThen$mcJF$sp_279d294f,
                mid_andThen$mcJI$sp_279d294f,
                mid_andThen$mcJJ$sp_279d294f,
                mid_andThen$mcZD$sp_279d294f,
                mid_andThen$mcZF$sp_279d294f,
                mid_andThen$mcZI$sp_279d294f,
                mid_andThen$mcZJ$sp_279d294f,
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
                mid_compose_279d294f,
                mid_compose$mcDD$sp_279d294f,
                mid_compose$mcDF$sp_279d294f,
                mid_compose$mcDI$sp_279d294f,
                mid_compose$mcDJ$sp_279d294f,
                mid_compose$mcFD$sp_279d294f,
                mid_compose$mcFF$sp_279d294f,
                mid_compose$mcFI$sp_279d294f,
                mid_compose$mcFJ$sp_279d294f,
                mid_compose$mcID$sp_279d294f,
                mid_compose$mcIF$sp_279d294f,
                mid_compose$mcII$sp_279d294f,
                mid_compose$mcIJ$sp_279d294f,
                mid_compose$mcJD$sp_279d294f,
                mid_compose$mcJF$sp_279d294f,
                mid_compose$mcJI$sp_279d294f,
                mid_compose$mcJJ$sp_279d294f,
                mid_compose$mcZD$sp_279d294f,
                mid_compose$mcZF$sp_279d294f,
                mid_compose$mcZI$sp_279d294f,
                mid_compose$mcZJ$sp_279d294f,
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

            ::scala::Function1 andThen(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcDD$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcDF$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcDI$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcDJ$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcFD$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcFF$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcFI$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcFJ$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcID$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcIF$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcII$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcIJ$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcJD$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcJF$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcJI$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcJJ$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcZD$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcZF$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcZI$sp(const ::scala::Function1 &) const;
            ::scala::Function1 andThen$mcZJ$sp(const ::scala::Function1 &) const;
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
            ::scala::Function1 compose(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcDD$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcDF$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcDI$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcDJ$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcFD$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcFF$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcFI$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcFJ$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcID$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcIF$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcII$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcIJ$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcJD$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcJF$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcJI$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcJJ$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcZD$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcZF$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcZI$sp(const ::scala::Function1 &) const;
            ::scala::Function1 compose$mcZJ$sp(const ::scala::Function1 &) const;
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
