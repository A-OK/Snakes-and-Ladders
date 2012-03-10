import sys
sys.path.append('gen-py/scala_utils_plumbing')
import ScalaUtilsService

from thrift import Thrift

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

try:
	
  transport = TSocket.TSocket('localhost', 1234)
  transport = TTransport.TBufferedTransport(transport)
  protocol = TBinaryProtocol.TBinaryProtocol(transport)
  client = ScalaUtilsService.Client(protocol)
  print client.ageGroupMethod(21) 
  transport.close()

except Thrift.TException, tx:
  print '%s' % (tx.message)