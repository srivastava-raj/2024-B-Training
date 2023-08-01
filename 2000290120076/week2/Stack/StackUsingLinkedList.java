package Implementation.Stack;


class Stack_LL{
	class Node{
		int data;
		Node next;
		
		public Node(int data)
		{
			this.data = data;
			this.next = null;
		}
		
		public Node(int data, Node next)
		{
			this.data = data;
			this.next = next;
		}
	}
	
	Node head = null;
	Node temp = head;
	
	void push(int data)
	{
		Node n = new Node(data);
		n.next = head;
		head = n;
	}
	
	int pop()
	{
		if(head==null)
		{
			System.out.println("Empty Stack");
			return -1;
		}
		Node temp = head;
		head = head.next;
		temp.next = null;
		return temp.data;
	}
	
	void traverse()
	{
		Node temp = head;
		while(temp!=null)
		{
			System.out.print(temp.data + "->");
			temp = temp.next;
		}
	}
	
	
}

public class StackUsingLinkedList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Stack_LL st = new Stack_LL();
		st.push(0);
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		
		st.pop();st.pop();st.pop();st.pop();st.pop();st.pop();
		st.traverse();
		

	}

}
