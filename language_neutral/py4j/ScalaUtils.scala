object ScalaUtils {

 def reptileAgeGroupFunctionMaker3 (reptileAgeFunction: (Double) => Double) =
   reptileAgeFunction.andThen(ageGroupFunction)
 
 def ageGroupMethod(age:Double):Int = ageGroupFunction(age) 

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
    
 val ages = collection.immutable.ListMap("Python" -> 21.0,
 	                                     "Scala" -> 9.0)

}
