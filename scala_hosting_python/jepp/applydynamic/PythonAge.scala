package jepp_applydynamic

object PythonAge extends App {
  val pythonUtils = new PythonUtils
  val age = 9.0.asInstanceOf[AnyRef]
  val pythonAge = pythonUtils.py_python_age(age)
  println(pythonAge.asInstanceOf[Float].round)
  
}
