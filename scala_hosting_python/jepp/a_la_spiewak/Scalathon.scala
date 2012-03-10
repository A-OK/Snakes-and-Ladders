package jepp_a_la_spiewak

import jep.Jep
import jep.JepException
import java.io._

trait Scalathon {

  val jep = new Jep()
 
  def pythonImport(scriptName:String) = {
    try {
	  jep.runScript(scriptName + ".py")
	 } catch {
	   case e: JepException => println(e.getMessage())
	 }
  }

  implicit def sym2Method[R](sym:Symbol): (Any*)=>R =
    new PyFunction[R](sym)

  class PyFunction[R](method:Symbol) extends ((Any*)=>R) {

    override def apply(params:Any*)={
      val paramObjects = params.map(_.asInstanceOf[AnyRef])     
      val result = jep.invoke(sym2string(method), paramObjects : _*)
      result.asInstanceOf[R]
    }  
  
    def sym2string(sym:Symbol) = {
     val back = sym.toString()
     back.substring(1, back.length())
    }
  }
}