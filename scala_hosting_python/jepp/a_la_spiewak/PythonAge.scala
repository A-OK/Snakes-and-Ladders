package jepp_a_la_spiewak

object PythonAge extends App with Scalathon {
  pythonImport("python_utils")
  val pythonAge:Float  = 'py_python_age(9.0)
  println(pythonAge.round)
}
