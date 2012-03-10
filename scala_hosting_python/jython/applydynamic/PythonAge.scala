package jython_applydynamic

object PythonAge extends App {
  val python_utils = new PythonUtils  
  val pythonAge = python_utils.py_python_age(9.0)
  println(pythonAge.asInstanceOf[Double].round)
  
}
