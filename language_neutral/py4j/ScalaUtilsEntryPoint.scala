import py4j.GatewayServer 


object ScalaUtilsEntryPoint extends App{
    def getScalaUtils() = ScalaUtils

    def bla() = 50
	    
    var gatewayServer = new GatewayServer(ScalaUtilsEntryPoint)

    gatewayServer.start()
    println("Started....")  

}


