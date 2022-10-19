// java program to check implement cycle sort
import java.util.*;
public class Main{
	public static void main(String[] args)
	{
		int[] a = { 3,2,4,5,1};
		int n = a.length;
		System.out.println("Before sort :");
		System.out.println(Arrays.toString(a));
		CycleSort(a, n);
		
	}

	static void CycleSort(int[] a, int n)
	{
		int j = 0;
		while (j < n) {
		
			int correctpos = a[j] - 1;
			if (a[j] < n && a[j] != a[correctpos]) {
		
				swap(a, j, correctpos);
			}
			else {
				j++;
			}
		}
			System.out.println("After sort : ");
			System.out.print(Arrays.toString(a));
		
		
	}

	static void swap(int[] a, int i, int correctpos)
	{
	// swap elements with their correct indexes
		int temp = a[i];
		a[i] = a[correctpos];
		a[correctpos] = temp;
	}
}
