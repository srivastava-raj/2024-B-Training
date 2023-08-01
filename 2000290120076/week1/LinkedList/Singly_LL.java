package Implementation.LinkedList;
import java.util.*;

import Implementation.LinkedList.ReverseRecursively.Node;

class LinkedList{
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
	
	public void insert_beginning(int data)
	{
		Node n = new Node(data);
		
		if(head == null)
			head = n;
		else
		{
			n.next = head;
			head = n;
		}
	}
	
	public void insert_end(int data)
	{
		Node n = new Node(data);
		if(head == null)
			head = n;
		else
		{
			Node temp = head;
			while(temp.next!=null)
				temp = temp.next;
			temp.next = n;
		}
	}
	
	public void insert_index(int data, int index)
	{
		Node n = new Node(data);
		if(index<0)
			System.out.println("enter index >= 0");
		
		if(index==0)
			insert_beginning(data);
		else
		{
			Node temp = head;
			while(index>1 && temp.next!=null) {
				index--;
				temp = temp.next;
			}
			if(index>1)
			{
				System.out.println("Enter index <= size");
				return;
			}
			
			n.next = temp.next;
			temp.next = n;
		}
	}
	
	public int delete_beginning()
	{
		if(head == null)
		{
			System.out.println("Empty LL");
			return -1;
		}
		else
		{
			Node temp = head;
			head = head.next;
			temp.next = null;
			return temp.data;
		}
	}
	
	public int delete_end()
	{
		if(head == null)
		{
			System.out.println("Empty LL");
			return -1;
		}
		else
		{
			Node temp = head;
			Node prev = null;
			
			if(head.next==null)
			{
				head = null;
				return temp.data;
			}
			while(temp.next!=null)
			{
				prev = temp;
				temp = temp.next;
			}
			prev.next = null;
			return temp.data;
		}
	}
	
	public int delete_index(int index)
	{
		if(index<0)
			System.out.println("enter index >= 0");
		
		if(index==0)
			return delete_beginning();
		int i=0;
		Node temp = head;
		Node prev=null;
		while(i!=index && temp.next!=null)
		{
			i++;
			prev = temp;
			temp = temp.next;
		}
		if(i!=index)
		{
			System.out.println("enter index <= LL size");
			return -1;
		}
		prev.next = temp.next;
		return temp.data;
		
	}
	static Node reverseUtil(Node node)
	{
		if(node==null)
			return node;
		if(node.next==null)
			return node;
		Node newNode = reverseUtil(node.next);
		node.next.next = node;
		node.next = null;
		return newNode;
	}
	void reverse()
	{
		Node temp = head;
		head = reverseUtil(temp);
	}
	
	public void traverse()
	{
		Node temp = head;
		while(temp!=null)
		{
			System.out.print(temp.data + "->");
			temp = temp.next;
		}
		System.out.println();
	}
}
public class Singly_LL {

	public static void main(String[] args) {
		LinkedList ll= new LinkedList();
		ll.insert_beginning(1);
		ll.insert_beginning(2);
		ll.insert_beginning(3);
		ll.insert_beginning(4);
		ll.insert_beginning(5);
		
		ll.traverse();
		
		ll.insert_end(10);
		ll.insert_end(11);
		ll.insert_end(12);
		ll.insert_end(13);
		ll.insert_end(14);
		
		ll.traverse();
		
		ll.reverse();
		
		ll.traverse();
		
		ll.delete_beginning();
		ll.delete_end();
		ll.delete_end();ll.delete_end();ll.delete_end();ll.delete_end();ll.delete_end();ll.delete_end();ll.delete_end();
		ll.delete_beginning();
		
		ll.traverse();
		
		ll.insert_index(0, 0);ll.insert_index(1, 1);ll.insert_index(0, 1);ll.insert_index(0, 4);ll.insert_index(0, -5);
		
		ll.delete_index(0);ll.delete_index(0);
		ll.traverse();
		
		

	}

}
