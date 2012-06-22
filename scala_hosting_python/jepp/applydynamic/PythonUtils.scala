package jepp_applydynamic
import java.io._
import jep.Jep
import jep.JepException



class PythonUtils() extends scala.Dynamic {
  val jep = new Jep()
  try {
      jep.runScript("python_utils.py")
    } catch {
      case e: JepException => println(e.getMessage())
    }

	def applyDynamic[R](name: String)(args: Any*) = {
	  val plist = new Array[String](args.length)
	    for (i <- 0 until args.length) {
	      plist(i) =
	        args(i) match{
	          case s:String => "'" + s + "'"
	          case _ => args(i).toString()
	        }
	     }  
	     
	   val str = "python_utils." + name  + "(" + plist.reduceLeft[String](_ + ", " + _) + ")"
	   jep.getValue(str).asInstanceOf[R]
	}
}
