package jepp_applydynamic

object PythonAge extends App {
  val pythonUtils = new PythonUtils
  val pythonAge: Float = pythonUtils.py_python_age(100.0)
  println(pythonAge.round)
  
}
