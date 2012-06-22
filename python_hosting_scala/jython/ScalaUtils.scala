import java.lang.{Double => JDouble}

object ScalaUtils {


 def reptileAgeGroupFunctionFactory (reptileAgeFunction: (JDouble) => JDouble):java.lang.Double => Int =
   reptileAgeFunction.andThen(ageGroupFunction)
 
 val ageGroupFunction = (age:JDouble) => {
   if (age <= 19)
     1
   else if (age <= 55)
     2
   else 
     3
 }

 def ageGroupMethod(age:JDouble):Int = ageGroupFunction(age)      

 val ages = collection.immutable.ListMap("Python" -> 21.0,
 	                                     "Scala" -> 9.0)

}

