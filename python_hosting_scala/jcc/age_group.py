import staircase

staircase.initVM(staircase.CLASSPATH)
from staircase import ScalaUtils
print(ScalaUtils.ageGroupMethod(21.0) + 1) 
