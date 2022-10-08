import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BinaryTree {

	public static void main(String [] args) {
		Node<Integer> root= null;
		root = new Node<Integer>( 10);
		root.left=new Node<Integer>( 5);
		root.right=new Node<Integer>( 15);
		root.left.left = new Node<Integer>( 3);
		root.left.right = new Node<Integer>( 4);
		root.right.left = new Node<Integer>( 12);
		
		ArrayList<ArrayList<Integer>> result = BFS(root);
		for(ArrayList<Integer> sublist: result) {
			System.out.println(sublist);
		}
		
		preorder(root);
	}
	
	public static <T> ArrayList<ArrayList<T>> BFS(Node root){
		ArrayList<ArrayList<T>> list = new ArrayList<>();
		Queue<Node<T>> q = new LinkedList<>();
		if(root == null) return list;
		
		q.add(root);
		while(!q.isEmpty()) {
			int levelNum = q.size();
			ArrayList<T> sublist = new ArrayList<T>();
			for(int i =0; i<levelNum; i++) {
				if(q.peek().left!=null) q.add(q.peek().left);
				if(q.peek().right!=null) q.add(q.peek().right);
				sublist.add(q.poll().data);
				
			}
			list.add(sublist);
			
		}
		return list ;
	}
	
	public static void preorder(Node root) {
		if(root == null) return;
		System.out.print(root.data + " ");
		preorder(root.left);
		preorder(root.right);
		
	}
}
