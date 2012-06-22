# This code is covered on pages 60 through 121 in the annotated slide deck  

from scalathon import scalafy
from ScalaUtils import *

# works right out the box!
print ageGroupMethod(21.0)

# account for Scala/Jython differences in determining what constitutes an instance
ageGroupFunction = ageGroupFunction()
ages = ages()

print ages

print ageGroupFunction.apply(21.0)

def python_age(age):
	return age / 2.8

# 'scalafy' python_age so it can be passed to a Scala functions that takes a Scala function argument
scalafied_python_age=scalafy(python_age)

python_ages = ages.mapValues(scalafied_python_age)
print python_ages

python_age_group_function = reptileAgeGroupFunctionFactory(scalafied_python_age)
python_age_group = python_age_group_function.apply(21.0)
print python_age_group

