package Implementation.Queue;

class Queue_LL{
	class Node{
		int data;
		Node next;
		
		public Node(int data)
		{
			this.data = data;
			this.next = null;
		}
	}
	
	Node front = null;
	Node rear = null;
	
	public void enqueue(int data)
	{
		Node n = new Node(data);
		
		if(front ==null)
		{
			front = n;
			rear = n;
		}
		else
		{
			rear.next = n;
			rear = rear.next;
		}
	}
	
	public int dequeue()
	{
		if(front == null)
		{
			System.out.println("Queue is Empty");
			return -1;
		}
		else
		{
			Node temp = front;
			front = front.next;
			temp.next = null;
			return temp.data;
		}
	}
	
	public void traverse()
	{
		Node temp = front;
		while(temp!=null)
		{
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
	}
}

public class QueueUsingLinkedList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Queue_LL que = new Queue_LL();
		
		que.enqueue(0);
		que.enqueue(1);
		que.enqueue(2);
		que.enqueue(3);
		
		que.dequeue();que.dequeue();que.dequeue();
		
		que.traverse();
		
		

	}

}
