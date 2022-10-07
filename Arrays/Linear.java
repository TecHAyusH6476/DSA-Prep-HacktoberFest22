package Arrays;

public class Linear {
    public static void main(String[]args) {
        int[] nums = {34, 56, 23, 78, -31, 90, 56, 54, 87 };
        int target = 78;
        int ans = linearSearch(nums, target);
        System.out.println(ans);

    }
    // search in the array:return the index if item found
    // if not found return -1
    static int linearSearch(int[] arr,int target ){
        if (arr.length == 0) {
            return -1;
        }
        // run a for loop
        for(int i =0; i<arr.length; i++ ){
            // check for element at every index if it is = target
            int element = arr[i];

            if (element == target) {
                return target;
                
            }
        }
        return -1;
    }
}