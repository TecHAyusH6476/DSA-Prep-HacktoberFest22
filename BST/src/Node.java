
public class Node<T> {
	T data;
	Node<T> left;
	Node<T> right;
	
	Node(){
		
	}
	
	Node(T data){
		this.data = data;
	}
	Node(T data, Node<T> left, Node<T> right){
		this.data = data;
		this.left = left;
		this.right = right;
	}
	
}
