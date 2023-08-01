package Implementation.Queue;

class QueueCircular
{
	int[] arr = new int[10];
	int front = -1;
	int rear = -1;
	
	void enqueue(int data)
	{
		if(front == -1 && rear == -1)
		{
			arr[++rear] = data;
			front = 0;
			return;
		}
		if(rear==front-1 || (front==0 && rear == arr.length-1))
		{
			System.out.println("Queue is full");
			return ;
		}
		rear = (rear+1)%arr.length;
		arr[rear] = data;
	}
	
	int dequeue()
	{
		if(front == -1 && rear ==-1)
		{
			System.out.println("Queue is Empty");
			return -1;
		}
		int val = arr[front];
		if(front==rear)
		{
			front = -1;
			rear = -1;
		}
		else
			front++;
		return val;
	}
	
	void traverse()
	{
		if(front<=rear)
		{
			for(int i=front;i<=rear;i++)
				System.out.print(arr[i] + " ");
		}
		else
		{
			for(int i=front;i<arr.length;i++)
				System.out.print(arr[i] + " ");
			for(int i=0;i<=rear;i++)
				System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
}

public class CircularQueueArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		QueueCircular que = new QueueCircular();
		
		que.enqueue(0);
		que.enqueue(1);
		que.enqueue(2);
		que.enqueue(3);
		que.enqueue(4);
		que.enqueue(0);
		que.enqueue(1);
		que.enqueue(2);
		que.enqueue(3);
		que.enqueue(4);
		
		que.dequeue();
		que.dequeue();
		que.dequeue();
		que.dequeue();
		que.dequeue();
		
		que.enqueue(0);
		que.enqueue(1);
		que.enqueue(2);
		que.enqueue(3);
		que.enqueue(4);
		
		que.dequeue();
		
		que.traverse();

	}

}
