package Implementation.Queue;

class Queue{
	
	int[] arr = new int[100];
	int front = -1;
	int rear = -1;
	
	void enqueue(int data)
	{
		if(rear == arr.length-1)
		{
			System.out.println("Eueue is full");
			return;
		}
		if(rear == -1)
			front = 0;
		arr[++rear] = data;
		
	}
	
	int dequeue()
	{
		if(front == -1)
		{
			System.out.println("Queue is Empty");
			return -1;
		}
		int val = arr[front++];
		if(front>rear)
		{
			front = -1;
			rear = -1;
		}
		return val;
	}
	
	void traverse()
	{
		if(rear>=0)
		{
			for(int i=front;i<=rear;i++)
				System.out.print(arr[i] + " ");
			System.out.println();
		}
	}
	
}

public class QueueUsingArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Queue que = new Queue();
		que.enqueue(0);
		que.enqueue(1);
		que.enqueue(2);
		que.enqueue(3);
		que.enqueue(4);
		
		que.traverse();
		
		que.dequeue();que.dequeue();que.dequeue();que.dequeue();que.dequeue();
		
		que.traverse();

	}

}
