#ifndef java_lang_Package_H
#define java_lang_Package_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class NumberFormatException;
        class String;
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class Package : public ::java::lang::Object {
        public:
            enum {
                mid_getImplementationTitle_14c7b5c5,
                mid_getImplementationVendor_14c7b5c5,
                mid_getImplementationVersion_14c7b5c5,
                mid_getName_14c7b5c5,
                mid_getPackage_d9fbaba1,
                mid_getPackages_c03e7c17,
                mid_getSpecificationTitle_14c7b5c5,
                mid_getSpecificationVendor_14c7b5c5,
                mid_getSpecificationVersion_14c7b5c5,
                mid_hashCode_54c6a179,
                mid_isCompatibleWith_5fdc3f44,
                mid_isSealed_54c6a16a,
                mid_toString_14c7b5c5,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Package(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Package(const Package& obj) : ::java::lang::Object(obj) {}

            ::java::lang::String getImplementationTitle() const;
            ::java::lang::String getImplementationVendor() const;
            ::java::lang::String getImplementationVersion() const;
            ::java::lang::String getName() const;
            static Package getPackage(const ::java::lang::String &);
            static JArray< Package > getPackages();
            ::java::lang::String getSpecificationTitle() const;
            ::java::lang::String getSpecificationVendor() const;
            ::java::lang::String getSpecificationVersion() const;
            jint hashCode() const;
            jboolean isCompatibleWith(const ::java::lang::String &) const;
            jboolean isSealed() const;
            ::java::lang::String toString() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Package);

        class t_Package {
        public:
            PyObject_HEAD
            Package object;
            static PyObject *wrap_Object(const Package&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
