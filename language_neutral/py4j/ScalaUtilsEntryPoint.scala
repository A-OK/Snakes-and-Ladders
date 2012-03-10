import py4j.GatewayServer 
 

object ScalaUtilsEntryPoint extends App{
 

def getScalaUtils() = ScalaUtils

    var gatewayServer = new GatewayServer(ScalaUtilsEntryPoint)
    gatewayServer.start()
    System.out.println("YAY")

   


}


