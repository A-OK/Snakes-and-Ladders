import inspect
import java
import scala

def scalafy(func):
	
	num_args = len(inspect.getargspec(func)[0])
	java_interface_name = "Function%d" % num_args
	java_interface = getattr(scala, java_interface_name)
	
	class ScalafiedFunction(java_interface):
		def apply(self,*args):
			return func.__call__(*args)
			
		def __call__(self, *args, **kwargs):
			return func.__call__(*args)
			
	scalafied_function = ScalafiedFunction()
	
	java_abstract_cl_name = "%s$class" % java_interface_name    
	java_abstract_cl = getattr(scala, java_abstract_cl_name)
	
	concrete_member_names=concrete_members(java_abstract_cl)
	
	for concrete_member_name in concrete_member_names:
		member = getattr(java_abstract_cl, concrete_member_name)
		impl = lambda *args: member.__call__(scalafied_function,
                                             *args)
		setattr(scalafied_function, concrete_member_name, impl) 
		
	return scalafied_function
	
def concrete_members(cl):
	return [method for method in dir(cl) if method.find("$") == -1 and method not in dir(java.lang.Object)]
