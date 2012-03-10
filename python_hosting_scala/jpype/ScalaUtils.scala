import java.lang.{Double => JDouble}

object ScalaUtils {
 
 val ageGroupFunction = (age:Double) => {
   if (age <= 19)
     1
   else if (age <= 30)
     2
   else if (age <= 45)
     3
   else if (age <= 60)
     4
   else if (age <= 75)
     5
   else
     6
 }

 def ageGroupMethod(age:Double):Int = ageGroupFunction(age)      

 val ages = collection.immutable.ListMap("Python" -> 21.0,
 	                                     "Scala" -> 9.0)

}

