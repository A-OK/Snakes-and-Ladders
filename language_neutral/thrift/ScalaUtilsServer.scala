import org.apache.thrift._
import org.apache.thrift.protocol._
import org.apache.thrift.transport._
import org.apache.thrift.server._
import org.apache.thrift.server.TServer.Args
import scala_utils_plumbing._

class ScalaUtilsLogic extends ScalaUtilsService.Iface {

 override def ageGroupMethod(age: Double): Int = {

   val ageGroupFunction = (age:Double) => {
     if (age <= 19)
       1
     else if (age <= 55)
       2
     else 
       3
   }
   ageGroupFunction(age) 
 }
}

 object ScalaUtilsServer extends App {
   val serverTransport = new TServerSocket(1234)
   val logic = new ScalaUtilsLogic()
   val processor = new ScalaUtilsService.Processor(logic)
   val plumbing=new Args(serverTransport).processor(processor)
   val server = new TSimpleServer(plumbing)
   println("starting server")
   server.serve();  
 }
