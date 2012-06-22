import inspect
import java
import scala

def scalafy(func):
	
	num_args = len(inspect.getargspec(func)[0])
	superclass_trait_name = "Function%d" % num_args
	superclass_trait = getattr(scala, superclass_trait_name)
	
	class ScalafiedFunction(superclass_trait):
		
		def apply(self,*args):
			return func.__call__(*args)
			
		def __call__(self, *args, **kwargs):
			return func.__call__(*args)
   
	scalafied_function = ScalafiedFunction()

	java_abstract_cl_name = "%s$class" % superclass_trait_name 
	java_abstract_cl = getattr(scala, java_abstract_cl_name)

	method = getattr(java_abstract_cl, "andThen")
	
	logic = lambda *args: method.__call__(scalafied_function,
                                         *args)
	
	setattr(scalafied_function, "andThen", logic)     
   
	return scalafied_function
	
	

	
	

