
import os, _scala4py

__dir__ = os.path.abspath(os.path.dirname(__file__))

class JavaError(Exception):
    def getJavaException(self):
        return self.args[0]
    def __str__(self):
        writer = StringWriter()
        self.getJavaException().printStackTrace(PrintWriter(writer))
        return "\n".join((super(JavaError, self).__str__(), "    Java stacktrace:", str(writer)))

class InvalidArgsError(Exception):
    pass

_scala4py._set_exception_types(JavaError, InvalidArgsError)

VERSION = "1.0"
CLASSPATH = [os.path.join(__dir__, "su.jar")]
CLASSPATH = os.pathsep.join(CLASSPATH)
_scala4py.CLASSPATH = CLASSPATH
_scala4py._set_function_self(_scala4py.initVM, _scala4py)

from _scala4py import *
