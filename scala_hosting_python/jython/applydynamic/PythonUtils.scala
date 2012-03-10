package jython_applydynamic

import javax.script._
import java.io._

class PythonUtils() extends scala.Dynamic {
  val scriptEngineManager = new ScriptEngineManager()
  val pyEngine = scriptEngineManager.getEngineByName("python")
  val engine = pyEngine.asInstanceOf[ScriptEngine with Invocable]
  engine.eval(new FileReader("python_utils.py"))
  
  val python_utils = engine.get("python_utils")

  def applyDynamic(name: String)(args: Any*) = {
       val argObjects = args.map(_.asInstanceOf[AnyRef])
       engine.invokeMethod(python_utils, name, argObjects : _*)
  }
}

