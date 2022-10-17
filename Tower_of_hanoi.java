import java.util.*;

public class Main
{
  public static void towerofhanoi(int n, int t1, int t2, int t3)
  {
    if (n == 0)
      return;
    towerofhanoi(n - 1, t1, t3, t2);
    System.out.println(n + "[" + t1 + " -> " + t2 + "]");
    towerofhanoi(n - 1, t3, t2, t1);
  }
  public static void main(String[] args) throws Exception
  {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int t1 = scn.nextInt();
    int t2 = scn.nextInt();
    int t3 = scn.nextInt();
    towerofhanoi(n, t1, t2, t3);
  }
}