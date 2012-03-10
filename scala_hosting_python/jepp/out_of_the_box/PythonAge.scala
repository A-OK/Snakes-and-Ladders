package jepp_out_of_the_box

import java.io._
import jep.Jep
import jep.JepException

object PythonAge extends App {
  try {
    val jep = new Jep()
    jep.runScript("python_utils.py")
    val arg = 9.0.asInstanceOf[AnyRef]
    val pythonAge  = jep.invoke("py_python_age", arg)
    println(pythonAge.asInstanceOf[Float].round)
  } catch {
    case e: JepException => println(e.getMessage())
  } 
}
