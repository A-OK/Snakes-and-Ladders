
import os, _staircase

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

_staircase._set_exception_types(JavaError, InvalidArgsError)

VERSION = "0.5"
CLASSPATH = [os.path.join(__dir__, "scala-library.jar"), os.path.join(__dir__, "su.jar")]
CLASSPATH = os.pathsep.join(CLASSPATH)
_staircase.CLASSPATH = CLASSPATH
_staircase._set_function_self(_staircase.initVM, _staircase)

from _staircase import *
