public class Main{
    public static void main(String[] args){
    Scanner scn=new Scanner(System.in);
        int n=scn.nextInt(); 
//       input for n=5
     System.out.println(generate(n));
//       output   ->    [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
    }
    public static List<List<Integer>> generate(int n) {
    List<List<Integer>> ans = new ArrayList<>();
        int[][] arr=new int[n][n];
        for(int i=0;i<n;i++){
            List<Integer> list=new ArrayList<>();
            for(int j=0;j<=i;j++){
                if(i-j==0 || i-j==i){
                    arr[i][j]=1;
                 
                }else{
                    arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
                }
                   list.add(arr[i][j]);
            }
            ans.add(list);
        }
        return ans;
    }
}
