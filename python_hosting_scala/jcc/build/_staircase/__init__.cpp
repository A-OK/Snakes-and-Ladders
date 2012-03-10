#include <jni.h>
#include <Python.h>
#include "JCCEnv.h"
#include "functions.h"

PyObject *initVM(PyObject *module, PyObject *args, PyObject *kwds);
#include "ScalaUtils.h"
#include "ScalaUtils$.h"
#include "ScalaUtils$$anonfun$1.h"

namespace java {
    void __install__(PyObject *module);
    void __initialize__(PyObject *module);
}
namespace scala {
    void __install__(PyObject *module);
    void __initialize__(PyObject *module);
}

void __install__(PyObject *module)
{
    t_ScalaUtils::install(module);
    t_ScalaUtils$::install(module);
    t_ScalaUtils$$anonfun$1::install(module);
    java::__install__(module);
    scala::__install__(module);
}

PyObject *__initialize__(PyObject *module, PyObject *args, PyObject *kwds)
{
    PyObject *env = initVM(module, args, kwds);

    if (env == NULL)
        return NULL;

    try {
        t_ScalaUtils::initialize(module);
        t_ScalaUtils$::initialize(module);
        t_ScalaUtils$$anonfun$1::initialize(module);
        java::__initialize__(module);
        scala::__initialize__(module);
        return env;
    } catch (int e) {
        switch(e) {
          case _EXC_JAVA:
            return PyErr_SetJavaError();
          default:
            throw;
        }
    }
}


namespace java {

    namespace io {
        void __install__(PyObject *module);
        void __initialize__(PyObject *module);
    }
    namespace lang {
        void __install__(PyObject *module);
        void __initialize__(PyObject *module);
    }
    namespace util {
        void __install__(PyObject *module);
        void __initialize__(PyObject *module);
    }

    void __install__(PyObject *module)
    {
        io::__install__(module);
        lang::__install__(module);
        util::__install__(module);
    }

    void __initialize__(PyObject *module)
    {
        io::__initialize__(module);
        lang::__initialize__(module);
        util::__initialize__(module);
    }
}

#include "java/io/PrintWriter.h"
#include "java/io/StringWriter.h"
#include "java/io/Writer.h"

namespace java {
    namespace io {


        void __install__(PyObject *module)
        {
            t_PrintWriter::install(module);
            t_StringWriter::install(module);
            t_Writer::install(module);
        }

        void __initialize__(PyObject *module)
        {
            t_PrintWriter::initialize(module);
            t_StringWriter::initialize(module);
            t_Writer::initialize(module);
        }
    }
}

#include "java/lang/AbstractStringBuilder.h"
#include "java/lang/Appendable.h"
#include "java/lang/Boolean.h"
#include "java/lang/Byte.h"
#include "java/lang/CharSequence.h"
#include "java/lang/Character.h"
#include "java/lang/Class.h"
#include "java/lang/ClassLoader.h"
#include "java/lang/ClassNotFoundException.h"
#include "java/lang/Comparable.h"
#include "java/lang/Double.h"
#include "java/lang/Exception.h"
#include "java/lang/Float.h"
#include "java/lang/IllegalAccessException.h"
#include "java/lang/IllegalArgumentException.h"
#include "java/lang/InstantiationException.h"
#include "java/lang/Integer.h"
#include "java/lang/InterruptedException.h"
#include "java/lang/Long.h"
#include "java/lang/Number.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/Object.h"
#include "java/lang/Package.h"
#include "java/lang/RuntimeException.h"
#include "java/lang/SecurityException.h"
#include "java/lang/Short.h"
#include "java/lang/StackTraceElement.h"
#include "java/lang/String.h"
#include "java/lang/StringBuffer.h"
#include "java/lang/StringBuilder.h"
#include "java/lang/Throwable.h"

namespace java {
    namespace lang {


        void __install__(PyObject *module)
        {
            t_AbstractStringBuilder::install(module);
            t_Appendable::install(module);
            t_Boolean::install(module);
            t_Byte::install(module);
            t_CharSequence::install(module);
            t_Character::install(module);
            t_Class::install(module);
            t_ClassLoader::install(module);
            t_ClassNotFoundException::install(module);
            t_Comparable::install(module);
            t_Double::install(module);
            t_Exception::install(module);
            t_Float::install(module);
            t_IllegalAccessException::install(module);
            t_IllegalArgumentException::install(module);
            t_InstantiationException::install(module);
            t_Integer::install(module);
            t_InterruptedException::install(module);
            t_Long::install(module);
            t_Number::install(module);
            t_NumberFormatException::install(module);
            t_Object::install(module);
            t_Package::install(module);
            t_RuntimeException::install(module);
            t_SecurityException::install(module);
            t_Short::install(module);
            t_StackTraceElement::install(module);
            t_String::install(module);
            t_StringBuffer::install(module);
            t_StringBuilder::install(module);
            t_Throwable::install(module);
        }

        void __initialize__(PyObject *module)
        {
            t_AbstractStringBuilder::initialize(module);
            t_Appendable::initialize(module);
            t_Boolean::initialize(module);
            t_Byte::initialize(module);
            t_CharSequence::initialize(module);
            t_Character::initialize(module);
            t_Class::initialize(module);
            t_ClassLoader::initialize(module);
            t_ClassNotFoundException::initialize(module);
            t_Comparable::initialize(module);
            t_Double::initialize(module);
            t_Exception::initialize(module);
            t_Float::initialize(module);
            t_IllegalAccessException::initialize(module);
            t_IllegalArgumentException::initialize(module);
            t_InstantiationException::initialize(module);
            t_Integer::initialize(module);
            t_InterruptedException::initialize(module);
            t_Long::initialize(module);
            t_Number::initialize(module);
            t_NumberFormatException::initialize(module);
            t_Object::initialize(module);
            t_Package::initialize(module);
            t_RuntimeException::initialize(module);
            t_SecurityException::initialize(module);
            t_Short::initialize(module);
            t_StackTraceElement::initialize(module);
            t_String::initialize(module);
            t_StringBuffer::initialize(module);
            t_StringBuilder::initialize(module);
            t_Throwable::initialize(module);
        }
    }
}

#include "java/util/Enumeration.h"
#include "java/util/Iterator.h"

namespace java {
    namespace util {


        void __install__(PyObject *module)
        {
            t_Enumeration::install(module);
            t_Iterator::install(module);
        }

        void __initialize__(PyObject *module)
        {
            t_Enumeration::initialize(module);
            t_Iterator::initialize(module);
        }
    }
}


namespace scala {

    namespace runtime {
        void __install__(PyObject *module);
        void __initialize__(PyObject *module);
    }

    void __install__(PyObject *module)
    {
        runtime::__install__(module);
    }

    void __initialize__(PyObject *module)
    {
        runtime::__initialize__(module);
    }
}

#include "scala/runtime/AbstractFunction1.h"
#include "scala/runtime/AbstractFunction1$mcID$sp.h"

namespace scala {
    namespace runtime {


        void __install__(PyObject *module)
        {
            t_AbstractFunction1::install(module);
            t_AbstractFunction1$mcID$sp::install(module);
        }

        void __initialize__(PyObject *module)
        {
            t_AbstractFunction1::initialize(module);
            t_AbstractFunction1$mcID$sp::initialize(module);
        }
    }
}

