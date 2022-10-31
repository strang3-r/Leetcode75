import java.lang.*;   
public class MergeArrayExample2  
{   
public static void main(String[] args)   
{   
int firstArray[] = { 11,22,33,44,55,98,76,54,60};   
int secondArray[] = {66,77,88,99,22,67,21,90,80,70};   
int source_arr[], sourcePos, dest_arr[], destPos, len;   
source_arr = firstArray;   
dest_arr = secondArray;   
sourcePos = 2;   
destPos = 4;   
len = 3;   
// Print elements of source   
System.out.print("source_array : ");   
for (int i = 0; i < firstArray.length; i++)   
System.out.print(firstArray[i] + " ");   
System.out.println("");   
System.out.println("sourcePos : " + sourcePos);   
// Print elements of destination  
System.out.print("dest_array : ");   
for (int i = 0; i < secondArray.length; i++)   
System.out.print(secondArray[i] + " ");   
System.out.println("");   
System.out.println("destPos : " + destPos);   
System.out.println("len : " + len);   
//invoking arraycopy() method   
System.arraycopy(source_arr, sourcePos, dest_arr,destPos, len);   
// Print elements of destination after   
System.out.print("Resultant array : ");   
for (int i = 0; i < secondArray.length; i++)   
System.out.print(secondArray[i] + " ");   
}   
}    
