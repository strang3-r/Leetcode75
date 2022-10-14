// Java recursive program to solve tower of hanoi puzzle

class Codespeedy
{ 
   
  static void result(long n, char source, char destination, char auxiliary) 
  { 
    if (n == 1) 
    { 
      System.out.println("Move disk 1 from " + source + " to " + destination); // print the task
      return; 
    } 
    
       result(n-1, source, auxiliary, destination); 
    
    System.out.println("Move disk " + n + " from " + source + " to " + destination); // print the task
    
         result(n-1, auxiliary, destination, source); 
  } 
  
  
  public static void main(String args[]) 
  { 
      long n = 3; // Number of disks 
       result(n,'A','C','B'); // A, B and C are names of rods 
  } }