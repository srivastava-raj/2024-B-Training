package Implementation.LinkedList;


public class ReverseRecursively {
	class Node{
		int data;
		Node next;
		Node(int data){
			this.data = data;
			this.next = null;
		}
	}

	static Node reverse(Node node)
	{
		if(node==null)
			return node;
		if(node.next==null)
			return node;
		Node newNode = reverse(node.next);
		node.next.next = node;
		node.next = null;
		return newNode;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
