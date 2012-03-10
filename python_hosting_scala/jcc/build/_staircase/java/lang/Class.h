#ifndef java_lang_Class_H
#define java_lang_Class_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class ClassNotFoundException;
        class String;
        class Package;
        class IllegalAccessException;
        class ClassLoader;
        class InstantiationException;
        class SecurityException;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class Class : public ::java::lang::Object {
        public:
            enum {
                mid_asSubclass_ecb22eb3,
                mid_cast_a932a95f,
                mid_desiredAssertionStatus_54c6a16a,
                mid_forName_7d663d97,
                mid_forName_4c5c10fb,
                mid_getCanonicalName_14c7b5c5,
                mid_getClassLoader_8d2f11fc,
                mid_getClasses_ffb25e7d,
                mid_getComponentType_44a5f2c9,
                mid_getDeclaredClasses_ffb25e7d,
                mid_getDeclaringClass_44a5f2c9,
                mid_getEnclosingClass_44a5f2c9,
                mid_getEnumConstants_94e49c77,
                mid_getInterfaces_ffb25e7d,
                mid_getModifiers_54c6a179,
                mid_getName_14c7b5c5,
                mid_getPackage_b0f2f7bb,
                mid_getSigners_94e49c77,
                mid_getSimpleName_14c7b5c5,
                mid_getSuperclass_44a5f2c9,
                mid_isAnnotation_54c6a16a,
                mid_isAnonymousClass_54c6a16a,
                mid_isArray_54c6a16a,
                mid_isAssignableFrom_a5deaff8,
                mid_isEnum_54c6a16a,
                mid_isInstance_290588e2,
                mid_isInterface_54c6a16a,
                mid_isLocalClass_54c6a16a,
                mid_isMemberClass_54c6a16a,
                mid_isPrimitive_54c6a16a,
                mid_isSynthetic_54c6a16a,
                mid_newInstance_846352c3,
                mid_toString_14c7b5c5,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Class(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Class(const Class& obj) : ::java::lang::Object(obj) {}

            Class asSubclass(const Class &) const;
            ::java::lang::Object cast(const ::java::lang::Object &) const;
            jboolean desiredAssertionStatus() const;
            static Class forName(const ::java::lang::String &);
            static Class forName(const ::java::lang::String &, jboolean, const ::java::lang::ClassLoader &);
            ::java::lang::String getCanonicalName() const;
            ::java::lang::ClassLoader getClassLoader() const;
            JArray< Class > getClasses() const;
            Class getComponentType() const;
            JArray< Class > getDeclaredClasses() const;
            Class getDeclaringClass() const;
            Class getEnclosingClass() const;
            JArray< ::java::lang::Object > getEnumConstants() const;
            JArray< Class > getInterfaces() const;
            jint getModifiers() const;
            ::java::lang::String getName() const;
            ::java::lang::Package getPackage() const;
            JArray< ::java::lang::Object > getSigners() const;
            ::java::lang::String getSimpleName() const;
            Class getSuperclass() const;
            jboolean isAnnotation() const;
            jboolean isAnonymousClass() const;
            jboolean isArray() const;
            jboolean isAssignableFrom(const Class &) const;
            jboolean isEnum() const;
            jboolean isInstance(const ::java::lang::Object &) const;
            jboolean isInterface() const;
            jboolean isLocalClass() const;
            jboolean isMemberClass() const;
            jboolean isPrimitive() const;
            jboolean isSynthetic() const;
            ::java::lang::Object newInstance() const;
            ::java::lang::String toString() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Class);

        class t_Class {
        public:
            PyObject_HEAD
            Class object;
            PyTypeObject *parameters[1];
            static PyTypeObject **parameters_(t_Class *self)
            {
                return (PyTypeObject **) &(self->parameters);
            }
            static PyObject *wrap_Object(const Class&);
            static PyObject *wrap_jobject(const jobject&);
            static PyObject *wrap_Object(const Class&, PyTypeObject *);
            static PyObject *wrap_jobject(const jobject&, PyTypeObject *);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
