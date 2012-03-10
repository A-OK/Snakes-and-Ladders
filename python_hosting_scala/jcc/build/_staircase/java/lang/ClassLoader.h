#ifndef java_lang_ClassLoader_H
#define java_lang_ClassLoader_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class ClassNotFoundException;
        class String;
        class Class;
    }
    namespace util {
        class Enumeration;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class ClassLoader : public ::java::lang::Object {
        public:
            enum {
                mid_clearAssertionStatus_54c6a166,
                mid_getParent_8d2f11fc,
                mid_getSystemClassLoader_8d2f11fc,
                mid_loadClass_7d663d97,
                mid_setClassAssertionStatus_f3691645,
                mid_setDefaultAssertionStatus_bb0c767f,
                mid_setPackageAssertionStatus_f3691645,
                mid_loadClass_dfdc0682,
                mid_getPackage_d9fbaba1,
                mid_setSigners_34aa77b4,
                mid_findClass_7d663d97,
                mid_defineClass_43666462,
                mid_defineClass_deb30b89,
                mid_defineClass_fd7e66de,
                mid_defineClass_2476a918,
                mid_resolveClass_a5deaff4,
                mid_findSystemClass_7d663d97,
                mid_findLoadedClass_7d663d97,
                mid_findResource_77de5daa,
                mid_findResources_1aac6a8a,
                mid_definePackage_ebf4cbfe,
                mid_getPackages_c03e7c17,
                mid_findLibrary_97a5258f,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit ClassLoader(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            ClassLoader(const ClassLoader& obj) : ::java::lang::Object(obj) {}

            void clearAssertionStatus() const;
            ClassLoader getParent() const;
            static ClassLoader getSystemClassLoader();
            ::java::lang::Class loadClass(const ::java::lang::String &) const;
            void setClassAssertionStatus(const ::java::lang::String &, jboolean) const;
            void setDefaultAssertionStatus(jboolean) const;
            void setPackageAssertionStatus(const ::java::lang::String &, jboolean) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(ClassLoader);

        class t_ClassLoader {
        public:
            PyObject_HEAD
            ClassLoader object;
            static PyObject *wrap_Object(const ClassLoader&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
