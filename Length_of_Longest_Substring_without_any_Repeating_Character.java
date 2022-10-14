import java.util.*;
public class Main {
    static int solve(String str) {

        if(str.length()==0)
             return 0;
        int maxans = Integer.MIN_VALUE;
        for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
        {
            Set < Character > se = new HashSet < > ();
            for (int j = i; j < str.length(); j++) // nested loop for getting different 
            string starting with str[i]
            {
                if (se.contains(str.charAt(j))) // if element if found so mark it as ans 
                and break from the loop
                {
                    maxans = Math.max(maxans, j - i);
                    break;
                }
                se.add(str.charAt(j));
            }
        }
        return maxans;
    }

    public static void main(String args[]) {
        String str = "takeUforward";
        System.out.println("The length of the longest substring without repeating 
        characters is " + solve(str));

    }
}
