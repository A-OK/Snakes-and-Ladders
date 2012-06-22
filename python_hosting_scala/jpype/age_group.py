
from jpype import *


startJVM(getDefaultJVMPath(), "-Djava.class.path=/Users/AOK/scala-library.jar:/Users/AOK/Snakes-and-Ladders/python_hosting_scala/jpype/scala-utils.jar")
scala =JPackage('scala')
scala_utils = JClass("ScalaUtils")
group=scala_utils.ageGroupMethod(21.0)
print(group + 1)
shutdownJVM()

