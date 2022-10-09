// important import statements  

import java.util.HashMap;  

import java.util.ArrayList;  

import java.util.Collections;

import java.util.Map;  

import java.util.Comparator;  

class Comparison implements Comparator<ArrayList<Integer>>  

{  

    public int compare(ArrayList<Integer> al1 , ArrayList<Integer> al2)  

    {     

        // frequency of element present in the list al1  

        int x1 = al1.get(0);          

        // frequency of element present in the list al2  

        int x2 = al2.get(0);  

        // index of the first occurrence of the element present in the list al1  

        int y1 = al1.get(1);  

        // index of the first occurrence of the element present in the list al2  

        int y2 = al2.get(1);          

        // if the frequency of occurrence of the elements do not   

        // match return the difference of x2 and x1  

        if(x1 != x2)  

        {  

           return x2 - x1;  

        }  

        // if the frequency of occurrence of the elements match   

        // return the difference of the indices of their first occurrence   

        else  

        {  

           return y1 - y2;  

        }  

    }  

}  

public class SortEleByFreq   

{  

    public int[] sortByFreq(int inputArr[])   

    {  

        HashMap<Integer, Integer> hm = new HashMap<>();  

        HashMap<Integer, Integer> idx = new HashMap<>();  

        // For each element of the array, put it in the dictionary and its index and frequency of the   

        // first occurrence in the array  

        for (int i = 0; i < inputArr.length; i++)   

        {  

            if(hm.containsKey(inputArr[i]))  

            {     

                // reaching here means, the element inputArr[i]  

                // has already been found. Therefore, all we have to   

                // do is to increase its frequency  

                hm.put(inputArr[i], hm.get(inputArr[i]) + 1);  

            }  

            else  

            {  

                // if the inputArr[i], is found only once  

                // put it in the hash map with the frequency of occurrence as 1  

                hm.put(inputArr[i] , 1);  

            }  

            if (idx.containsKey(inputArr[i]) == false)   

            {  

                // keeping track of the first occurrence   

                // of the element present in the input array  

                idx.put(inputArr[i], i);  

            }  

        }  

        ArrayList<ArrayList<Integer>> list = new ArrayList<>();  

        for (Map.Entry<Integer , Integer> itr : hm.entrySet())   

        {  

            // the list contains three elements   

            // the first one contains the frequency of the occurrence  

            // the second one contains the index of the first occurrence of the element in the input array  

            // the third element contains the element whose frequency has been stored as the first element   

            // in the tmp list  

            ArrayList<Integer> tmp = new ArrayList<>();  

            tmp.add(itr.getValue());  

            tmp.add(idx.get(itr.getKey()));  

            tmp.add(itr.getKey());  

            list.add(tmp);  

        }  

  

        // Sorting the values using the custom comparator.  

        // instantiating the Comparison class  

        Collections.sort(list, new Comparison());  

  

        // Eventually returning the sorted list having the arranged elements.  

        ArrayList<Integer> ansList = new ArrayList<>();  

        for (int j = 0; j < list.size(); j++)   

        {  

            for (int i = 1; i <= list.get(j).get(0); i++)   

            {  

                ansList.add(list.get(j).get(2));  

            }  

        }  

          

        int resultArr[] = new int[ansList.size()];  

          

        // copying the results in the resultArr  

        for(int j = 0 ; j < ansList.size() ; j++)  

        {  

            resultArr[j] = ansList.get(j);  

        }  

        return resultArr;  

    }  

    // main method  

    public static void main(String argvs[])  

    {  

        // input 1  

        int inputArr[] = {12, 16, 15, 12, 12, 18, 15, 18, 16, 18, 18};          

        // creating an object of the class SortEleByFreq  

        SortEleByFreq obj = new SortEleByFreq();  

        int resultArr[] = obj.sortByFreq(inputArr);  

        int size = resultArr.length;  

        System.out.println("The input array is: ");  

        for(int i = 0; i < size; i++)  

        {  

            System.out.print(inputArr[i] + " ");  

        }  

        System.out.println("\n ");  

        System.out.println("After sorting by frequency of occurrences, the array becomes: ");  

        for(int i = 0; i < size; i++)  

        {  

            System.out.print(resultArr[i] + " ");  

        }  

        System.out.println("\n ");  

        // input 2  

        int inputArr1[] = {19, 20, 17, 45, 34, 3, 2, 1, 89, 56, 80, 85, 90};  

        int resultArr1[] = obj.sortByFreq(inputArr1);  

        size = resultArr1.length;  

        System.out.println("The input array is: ");  

        for(int i = 0; i < size; i++)  

        {  

            System.out.print(inputArr1[i] + " ");  

        }  

        System.out.println("\n ");  

        System.out.println("After sorting by frequency of occurrences, the array becomes: ");  

        for(int i = 0; i < size; i++)  

        {  

            System.out.print(inputArr1[i] + " ");  

        }  

          

        System.out.println("\n ");  

    }  

} 
