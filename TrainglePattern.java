/* 
        *
      *   *
    *       *
  *           *
*               *
*/
public class TrianglePattern {
  public static void main(String[] args) {
    // Write code here
    int rows = 5;
    for (int i = 1; i <= rows; i++) {
      for (int j = rows; j > i; j--) {
        System.out.print(" ");
      }
      System.out.print("*");
      for (int j = 1; j < (i - 1) * 2; j++) {
        System.out.print(" ");
      }
      if (i == 1) {
        System.out.print("\n");
      } else {
        System.out.print("*" + "\n");
      }
    }
  }
}
