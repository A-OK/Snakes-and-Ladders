package jepp_out_of_the_box

import java.io._
import jep.Jep
import jep.JepException

object PythonAge extends App {

  
  val jep = new Jep()


  jep.runScript("python_utils.py")


  val age = (9.0).asInstanceOf[AnyRef]


  val pythonAge = jep.invoke("py_python_age", age)


  println(pythonAge.asInstanceOf[Float].round)
  

}
