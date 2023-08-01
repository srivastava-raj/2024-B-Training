package Implementation.Stack;
import java.util.*;

class Stack{
	static int[] arr = new int[100];
	static int top= -1;
	
	void push(int val)
	{
		if(top == 100-1)
			System.out.println("Overflow");
		else
		{
			arr[++top] = val;
		}
	}
	int pop()
	{
		if(top==-1)
		{
			System.out.println("Underflow");
			return -1;
		}
		else
			return arr[top--];
	}
	void traverse() {
		for(int i=0;i<=top;i++)
			System.out.print(arr[i]+ " ");
	}
}

public class StackUsingArray {

	public static void main(String[] args) {
		
		
		Scanner sc = new Scanner(System.in);
        Stack s = new Stack();
        
        s.push(1);
        s.push(2);
        s.pop();
        s.push(3);

        s.traverse();
	}
	
	

}


